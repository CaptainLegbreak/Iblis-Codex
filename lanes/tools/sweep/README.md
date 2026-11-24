# Context-copy sweep

`sweep.py OUT.json [UNIT_REL ...]` tests every `// build: context NAME` line in the given units (all non-LTCG units
by default) on the current checkout, from temporary copies (it edits nothing):

- **directive_removable**: the unit still checks equal without the `// build: context` line.
- **copy**: what happens with the copy itself taken out. A file-local (`static`/`inline`) copy is deleted; an
  external one becomes its prototype, so calls go to the real definition.
  - `removable`: the unit still checks equal;
  - `needed by ...`: those functions stop matching;
  - `does not compile without it`: the unit uses it and nothing else defines it there;
  - `definition not found in file`: the directive names a symbol without a definition in this file.

Equality is `tools/build.py`'s rule per function. A full verify still decides; the sweep only finds candidates.
`results-340.json` is the run on main #340 (393 directives in 160 units, about 17 minutes on two workers).
