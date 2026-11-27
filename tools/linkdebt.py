#!/usr/bin/env python3
"""Count the link debt of the sources: every reference the ordinary build has to bind by address.

  python tools/linkdebt.py [--out DIR] [-j N] [--no-compile] [--module M] [--max N] [--category C,...]

tools/link.py links the objects as an ordinary program, but where a file's declaration of a callee or global does
not agree with its definition (another name, another type or linkage, a copy of a function kept for a call site, a
global the code reaches past into its neighbour), it connects the reference to the definition at the address the
reference means instead of by name. This tool runs the same analysis (the compile step of tools/build.py, sharing its
object cache, then link.py's plan; nothing is linked) and sorts every such reference into one category:

  data_cluster          a global of a run of globals the code treats as one object: the run keeps its original
                        layout and is copied from your Game.exe
  unsourced_data        data no source defines yet, copied from your Game.exe
  interior              an address inside a function or global a source defines (declared as an object of its own)
  type_disagreement     the same identifier as the definition, another decorated name (type, signature, C vs C++)
  different_identifier  another identifier than the definition (a method vs a free function, an older name)
  placeholder           another identifier, and the definition's is still a placeholder (gData_<VA>, sub_<VA>_...)
  renamed_definition    the declaration agrees, but the definition is static or its name is not unique, so the
                        ordinary link renames it to <name>$<VA>
  local_copy            a call through a copy of the function this file defines for its calling convention or a
                        call site (the copy is left out of the link)
  duplicate_data        a global this file defines too: the link keeps the widest definition, from another file
  import                an import declared under another name or type than its import library's
  runtime_library       a runtime library routine declared under another name or type
  pkware                the PKWARE compression routines Storm links as a prebuilt library

It writes <out>/ordinary/LINK_DEBT.json (totals, per module, per file and every item; the data clusters with their
range, size and member globals; the generated data blocks) and LINK_DEBT.txt, the table it prints.

--module M lists the items of module M (the second component of the path under Source/) in detail. With --max N it
exits with code 1 if the module's count (of every category, or of the --category list) is above N; without --module,
--max applies to the total.
"""
import os, re, sys, json, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, settings, check_image, die
import checker
import link

CATEGORIES = ("data_cluster", "unsourced_data", "interior", "type_disagreement", "different_identifier", "placeholder",
              "renamed_definition", "local_copy", "duplicate_data", "import", "runtime_library", "pkware")
SHORT = {"data_cluster": "cluster", "unsourced_data": "unsrc", "interior": "inter", "type_disagreement": "type",
         "different_identifier": "ident", "placeholder": "plchld", "renamed_definition": "renamed", "local_copy": "copy",
         "duplicate_data": "dup", "import": "import", "runtime_library": "crt", "pkware": "pkware"}
PLACEHOLDER = re.compile(r"^(?:gData_|sub_|dword_|byte_|word_|unk_|off_|stru_)|(?:^|_)[0-9A-F]{8}(?:_|$)")


def opt(args, name, default=None):
    return args[args.index(name) + 1] if name in args else default


def ident(n):
    """The source identifier of a symbol, with its class or namespace: `D2Foo::Bar`, `gnBaz`."""
    if n.startswith("??"):
        m = re.match(r"^\?\?([01])([A-Za-z_0-9]+)@", n)
        if m:
            return "%s::%s%s" % (m.group(2), "~" if m.group(1) == "1" else "", m.group(2))
        return checker.undec(n)
    if n.startswith("?"):
        m = re.match(r"^\?([^@?]+)@((?:[^@]+@)*?)@", n)
        if m:
            scopes = [x for x in m.group(2).split("@") if x]
            return "::".join(list(reversed(scopes)) + [m.group(1)])
        return checker.undec(n)
    if n.startswith("@"):
        return n[1:].split("@")[0]
    if n.startswith("_"):
        return n[1:].split("@")[0]
    return n


def module_of(rel):
    p = rel.split("/")
    return p[1] if len(p) > 2 and p[0] == "Source" else p[0]


def definition_of(K, S):
    """(unit, symbol name) of the source definition of address S, or None."""
    h = K.home.get(S)
    if h is not None:
        return h[0], h[0].o.by_idx[h[2]]["name"]
    d = K.dhome.get(S)
    if d is not None:
        return d[0], d[0].o.by_idx[d[1]]["name"]
    d = K.cluster_home.get(S)
    if d is not None:
        return d[0], d[0].o.by_idx[d[1]]["name"]
    return None


def containing(K, S, k, scn):
    """The definition a label at S (in unit k, section scn) lies inside: (unit, symbol name, its address)."""
    va = K.home_sec.get((k, scn))
    if va is not None:
        u, _, i = K.home[va]
        return u, u.o.by_idx[i]["name"], va
    a = K.data_of(S)
    if a is not None:
        u, i = K.dhome[a]
        return u, u.o.by_idx[i]["name"], a
    return K.units[k], None, None


def collect(K):
    """Every reference link.py binds by address, sorted into CATEGORIES."""
    K.cluster_home = {}
    cluster_of = {}
    for j, (lo, hi, members, homes) in enumerate(K.clusters):
        K.cluster_home.update(homes)
        for a in members:
            cluster_of[a] = j
    import_names = set(K.import_syms.values())
    crt_names = set(K.crt_at.values())
    items = collections.OrderedDict()
    for (k, scn, n), S in sorted(K.bound_at.items()):
        u = K.units[k]; y = u.o.relocs(scn)[n]["sym"]; b = K.retarget[k][(scn, n)]
        declared = y["name"]; dfile = None; dsym = None; dva = S
        if b.startswith("_d2va_") and b in K.labels:
            cat = "interior"
            du, dsym, dva = containing(K, S, *K.labels[b][:2])
            dfile = du.rel
        elif b.startswith("_d2va_"):
            kind = K.gen_wanted[b][1]
            if kind == "pkware":
                cat = "pkware"
            elif S in cluster_of:
                cat = "data_cluster"
                d = definition_of(K, S)
                if d:
                    dfile, dsym = d[0].rel, d[1]
            else:
                cat = "unsourced_data"
        elif b.startswith("__imp_") or b in import_names:
            cat = "import"; dsym = b
        elif b in crt_names and S in K.crt_at:
            cat = "runtime_library"; dsym = b; dfile = "libcmt.lib"
        else:
            d = definition_of(K, S)
            if d is None:
                cat = "different_identifier"; dsym = b
            else:
                dfile, dsym = d[0].rel, d[1]
                if y["scn"] > 0 or (y["scn"] == 0 and y["value"] > 0):
                    cat = "local_copy" if S in K.home else "duplicate_data"
                elif declared == dsym:
                    cat = "renamed_definition"
                elif ident(declared) == ident(dsym):
                    cat = "type_disagreement"
                elif PLACEHOLDER.search(ident(dsym)):
                    cat = "placeholder"
                else:
                    cat = "different_identifier"
        key = (cat, u.rel, declared, S)
        it = items.get(key)
        if it is None:
            it = items[key] = dict(category=cat, module=module_of(u.rel), unit=u.rel, declared=declared, bound=b,
                                   definition=dsym, defining_file=dfile, address="0x%08X" % S,
                                   definition_address="0x%08X" % dva if dva is not None else None, refs=0)
        it["refs"] += 1
    return list(items.values()), cluster_of


def tally(items, key):
    """{key value: {category: {refs, targets}, total: {refs, targets}}}."""
    refs = collections.defaultdict(collections.Counter); tg = collections.defaultdict(lambda: collections.defaultdict(set))
    for it in items:
        g = it[key] if key else "all"
        refs[g][it["category"]] += it["refs"]; refs[g]["total"] += it["refs"]
        tg[g][it["category"]].add(it["address"]); tg[g]["total"].add(it["address"])
    out = {}
    for g in sorted(refs, key=lambda g: (-refs[g]["total"], g)):
        out[g] = {c: dict(refs=refs[g][c], targets=len(tg[g][c])) for c in CATEGORIES + ("total",) if refs[g][c]}
    return out


def report(K, items, cluster_of):
    totals = tally(items, None).get("all", {})
    clusters = []
    by_cluster = collections.Counter(); tg_cluster = collections.defaultdict(set)
    for it in items:
        j = cluster_of.get(int(it["address"], 16))
        if it["category"] == "data_cluster" and j is not None:
            by_cluster[j] += it["refs"]; tg_cluster[j].add(it["address"])
    for j, (lo, hi, members, homes) in enumerate(K.clusters):
        mem = []
        for a in members:
            if a in homes:
                u, i = homes[a]
                mem.append(dict(address="0x%08X" % a, name=u.o.by_idx[i]["name"], file=u.rel))
            else:
                mem.append(dict(address="0x%08X" % a, name=None, file=None))
        clusters.append(dict(start="0x%08X" % lo, end="0x%08X" % hi, size=hi - lo, globals=len(homes), members=mem,
                             refs=by_cluster[j], targets=len(tg_cluster[j]),
                             modules=sorted({module_of(m["file"]) for m in mem if m["file"]})))
    refs_at = collections.Counter()
    for it in items:
        if it["category"] in ("data_cluster", "unsourced_data", "pkware"):
            refs_at[int(it["address"], 16)] += it["refs"]
    labels_in = collections.defaultdict(list)
    for nm, (S, kind) in K.gen_wanted.items():
        labels_in[S].append(nm)
    blocks = []
    starts = sorted(K.blocks)
    for lo in starts:
        b = K.blocks[lo]
        inside = [S for S in labels_in if lo <= S < b["hi"]]
        cl = [c for c in clusters if lo <= int(c["start"], 16) < b["hi"]]
        blocks.append(dict(start="0x%08X" % lo, size=b["hi"] - lo,
                           kind="pkware" if b["kind"] == "pkware" else "data" if b["init"] else "bss",
                           labels=len(inside), refs=sum(refs_at[S] for S in inside), clusters=len(cl),
                           cluster_bytes=sum(c["size"] for c in cl)))
    gen = collections.Counter()
    for bl in blocks:
        gen[bl["kind"] + "_bytes"] += bl["size"]; gen[bl["kind"] + "_blocks"] += 1
        gen[bl["kind"] + "_cluster_bytes"] += bl["cluster_bytes"]
    rep = collections.OrderedDict()
    rep["relocations_bound_by_address"] = K.problems["relocations_bound_by_address"]
    rep["counted"] = sum(it["refs"] for it in items)
    rep["totals"] = totals
    rep["definitions_renamed_to_address"] = K.problems["definition_renamed_to_address"]
    rep["data_clusters_summary"] = dict(clusters=len(clusters), bytes=sum(c["size"] for c in clusters),
                                        globals=sum(c["globals"] for c in clusters))
    rep["generated"] = dict(gen)
    rep["modules"] = tally(items, "module")
    rep["files"] = tally(items, "unit")
    rep["data_clusters"] = clusters
    rep["generated_blocks"] = blocks
    rep["items"] = items
    return rep


def table(rep, files=25, clusters=12):
    L = []
    t = rep["totals"]
    L.append("link debt: %d references bound by address (%d distinct targets)"
             % (t.get("total", {}).get("refs", 0), t.get("total", {}).get("targets", 0)))
    L.append("")
    L.append("%-22s %8s %8s" % ("category", "refs", "targets"))
    for c in CATEGORIES:
        if c in t:
            L.append("%-22s %8d %8d" % (c, t[c]["refs"], t[c]["targets"]))
    cs = rep["data_clusters_summary"]; g = rep["generated"]
    L.append("")
    L.append("data clusters: %d, %d bytes, %d globals kept in original layout" % (cs["clusters"], cs["bytes"], cs["globals"]))
    L.append("generated from Game.exe: %d data blocks %d B (%d B of them data clusters), %d bss blocks %d B (%d B clusters), pkware %d B"
             % (g.get("data_blocks", 0), g.get("data_bytes", 0), g.get("data_cluster_bytes", 0), g.get("bss_blocks", 0),
                g.get("bss_bytes", 0), g.get("bss_cluster_bytes", 0), g.get("pkware_bytes", 0)))
    L.append("definitions renamed to <name>$<VA> (static or not unique): %d" % rep["definitions_renamed_to_address"])
    cols = [c for c in CATEGORIES if c in t]
    head = "%-14s %7s" % ("module", "refs") + "".join(" %7s" % SHORT[c] for c in cols)
    L.append("")
    L.append("references per module (distinct targets in the total column in brackets)")
    L.append(head)
    for m, v in rep["modules"].items():
        L.append("%-14s %7d" % (m, v["total"]["refs"]) + "".join(" %7s" % (v[c]["refs"] if c in v else "") for c in cols)
                 + "  [%d]" % v["total"]["targets"])
    L.append("")
    L.append("top %d files" % files)
    for f, v in list(rep["files"].items())[:files]:
        L.append("  %6d  %s" % (v["total"]["refs"], f))
    L.append("")
    L.append("largest data clusters")
    for c in sorted(rep["data_clusters"], key=lambda c: -c["size"])[:clusters]:
        L.append("  %s-%s %7d B  %3d globals  %5d refs  %s" % (c["start"], c["end"], c["size"], c["globals"], c["refs"],
                                                           ",".join(c["modules"])))
    return "\n".join(L)


def module_detail(rep, mod, cats):
    L = ["%s: %s" % (mod, ", ".join("%s %d" % (c, v["refs"]) for c, v in rep["modules"].get(mod, {}).items()) or "no link debt")]
    its = [it for it in rep["items"] if it["module"] == mod and (not cats or it["category"] in cats)]
    its.sort(key=lambda it: (CATEGORIES.index(it["category"]), it["unit"], it["declared"]))
    cur = None
    for it in its:
        if it["category"] != cur:
            cur = it["category"]; L.append(""); L.append("[%s]" % cur)
        L.append("  %s  %s x%d" % (it["unit"], it["address"], it["refs"]))
        L.append("      declared   %s" % it["declared"])
        L.append("      definition %s%s" % (it["definition"] or it["bound"], "  (%s)" % it["defining_file"] if it["defining_file"] else ""))
    return "\n".join(L)


def count(rep, mod=None, cats=None):
    v = rep["modules"].get(mod, {}) if mod else rep["totals"]
    if cats:
        return sum(v[c]["refs"] for c in cats if c in v)
    return v.get("total", {}).get("refs", 0)


def write(rep, lo):
    os.makedirs(lo, exist_ok=True)
    json.dump(rep, open(os.path.join(lo, "LINK_DEBT.json"), "w"), indent=1)
    txt = table(rep)
    open(os.path.join(lo, "LINK_DEBT.txt"), "w").write(txt + "\n")
    return txt


def strict_check(K, lo, modules=None):
    """link.py --strict: no reference of the sources (of the modules named) bound by address."""
    items, cluster_of = collect(K)
    rep = report(K, items, cluster_of); write(rep, lo)
    bad = [(m, count(rep, m)) for m in (modules or list(rep["modules"])) if count(rep, m)]
    for m, n in bad:
        K.log("strict: %s has %d references bound by address (python tools/linkdebt.py --no-compile --module %s)" % (m, n, m))
    if not bad:
        K.log("strict: no references bound by address%s" % (" in " + ",".join(modules) if modules else ""))
    return not bad


def main():
    a = sys.argv[1:]
    if "-h" in a or "--help" in a:
        print(__doc__); return 0
    s = settings()
    check_image(s["image"])
    if not s.get("crt_lib"):
        die("the link plan needs the C runtime libraries: run `python tools/setup.py --crt`")
    out = os.path.abspath(os.path.expanduser(opt(a, "--out", os.path.join(ROOT, "out"))))
    lo = os.path.join(out, "ordinary"); os.makedirs(lo, exist_ok=True)
    mod = opt(a, "--module"); mx = opt(a, "--max")
    cats = [c for c in (opt(a, "--category") or "").split(",") if c]
    for c in cats:
        if c not in CATEGORIES:
            die("unknown category %s (one of %s)" % (c, ", ".join(CATEGORIES)))
    if "--no-compile" not in a:
        cmd = [sys.executable, os.path.join(ROOT, "tools", "build.py"), "--compile-only", "--out", out]
        if opt(a, "-j"):
            cmd += ["-j", opt(a, "-j")]
        r = subprocess.run(cmd, stdout=subprocess.DEVNULL)
        if r.returncode:
            die("compiling the units failed")
    if not os.path.exists(os.path.join(out, "results.json")):
        die("no %s: run without --no-compile" % os.path.join(out, "results.json"))
    standins = link.compile_standins(s, lo)
    K = link.analyse(s, out, lo, standins, log=lambda *x: None)
    items, cluster_of = collect(K)
    rep = report(K, items, cluster_of)
    if rep["counted"] != rep["relocations_bound_by_address"]:
        die("counted %d references, link.py binds %d by address" % (rep["counted"], rep["relocations_bound_by_address"]))
    txt = write(rep, lo)
    if mod:
        if mod not in rep["modules"] and not any(module_of(u.rel) == mod for u in K.units):
            die("no module %s" % mod)
        print(module_detail(rep, mod, cats))
    else:
        print(txt)
    print("\nwrote %s" % os.path.join(lo, "LINK_DEBT.json"))
    if mx is not None:
        n = count(rep, mod, cats)
        what = "%s%s" % (mod or "all modules", " (%s)" % ",".join(cats) if cats else "")
        if n > int(mx):
            print("link debt of %s: %d references, above the limit of %s" % (what, n, mx)); return 1
        print("link debt of %s: %d references, within the limit of %s" % (what, n, mx))
    return 0


if __name__ == "__main__":
    sys.exit(main())
