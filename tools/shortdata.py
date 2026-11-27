#!/usr/bin/env python3
"""Globals the sources declare smaller than the room the original gives them.

    python tools/shortdata.py [--no-compile] [-j N] [--module M] [--min BYTES]

For every global a source file defines, compares its declared size with the distance to the next thing the original
image has there (the next global the sources define, or the next block the ordinary build copies from your Game.exe).
A global with room left after it is a candidate for an array or struct declared too short: where the original's code
indexes it past the declared end, the byte-exact build reads the original's neighbour and the ordinary build reads
whatever its linker placed there. Writes out/ordinary/SHORT_DATA.json (addresses, sizes and names only) and prints the
list, largest room first. A candidate is not a bug by itself: the room may be padding or data no source declares yet.
"""
import os, sys, json, bisect, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, settings, check_image, die
import link


def opt(a, k, d=None):
    return a[a.index(k) + 1] if k in a and a.index(k) + 1 < len(a) else d


def main():
    a = sys.argv[1:]
    if "-h" in a or "--help" in a:
        print(__doc__); return 0
    s = settings(); check_image(s["image"])
    out = os.path.join(ROOT, "out"); lo = os.path.join(out, "ordinary"); os.makedirs(lo, exist_ok=True)
    if "--no-compile" not in a:
        cmd = [sys.executable, os.path.join(ROOT, "tools", "build.py"), "--compile-only", "--out", out]
        if opt(a, "-j"):
            cmd += ["-j", opt(a, "-j")]
        if subprocess.run(cmd, stdout=subprocess.DEVNULL).returncode:
            die("compiling the units failed")
    K = link.analyse(s, out, lo, link.compile_standins(s, lo), log=lambda *x: None)
    blocks = sorted(K.gen_reach.values()) if getattr(K, "gen_reach", None) else []
    starts = sorted(set(K.dhome) | {b[0] for b in blocks})
    mod = opt(a, "--module"); mn = int(opt(a, "--min", "4"))
    res = []
    for g in sorted(K.dhome):
        u, i = K.dhome[g]; y = u.o.by_idx[i]
        size = K.dext[g]
        j = bisect.bisect_right(starts, g)
        if j >= len(starts):
            continue
        room = starts[j] - (g + size)
        m = u.rel.split("/")[1] if u.rel.count("/") > 1 else ""
        if room < mn or (mod and m != mod):
            continue
        res.append({"address": "0x%08X" % g, "declared": size, "room_after": room, "next": "0x%08X" % starts[j],
                    "name": y["name"], "file": u.rel, "module": m})
    res.sort(key=lambda r: -r["room_after"])
    json.dump({"candidates": res, "count": len(res)}, open(os.path.join(lo, "SHORT_DATA.json"), "w"), indent=1)
    for r in res:
        print("%s %6d B declared, %6d B room after  %-60s %s" % (r["address"], r["declared"], r["room_after"], r["name"][:60], r["file"]))
    print("\n%d candidates; wrote %s" % (len(res), os.path.join(lo, "SHORT_DATA.json")))
    return 0


if __name__ == "__main__":
    sys.exit(main())
