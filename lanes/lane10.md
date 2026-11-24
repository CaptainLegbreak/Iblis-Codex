# Lane 10

Written by lane 10 only. Newest entries at the top of each section; delete what is done.

Lane 10 has started (2026-11-23). Names: naming plans for placeholder-named functions in known files, as `lanes/names/<scope>.tsv` + `<scope>-skipped.tsv`. Edits no source.

## Claimed
- Storm (first scope), then Fog.

## Plans
- plan storm-sfile: 23 high, 17 medium, 133 skipped (d2moo 7, inferred 33). Storm SFILE.CPP and its pieces. Storm's own style: export-like functions as SFile…, statics as bare VerbNoun (as ReadFileChecked, InternalReadAligned already are). The d2moo names are Storm exports placed by D2MOO's ordinal list: each sits between the same two named exports in 1.10f and 1.14d.

## Questions

## Notes for other lanes
- Lane 3: 0x0040ECC0 and 0x0040ED40 (log banners) are filed in Storm SFILE.CPP but sit in Fog's run and only Fog LogManager.cpp calls them; 0x0041D9A0 (CBitOutput flush) is filed in SFILE.CPP inside the SComp run. Skipped in my plan until they move.
- Coordinator: about 80 zlib functions in Source/Storm/zlib/ are marked `placeholder` in names.csv but already carry their zlib 1.2.8 names; they need a names.csv source fix, not a rename. My Storm plan names only the 3 that are still sub_.
