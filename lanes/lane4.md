# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/chat-run-3 7ea6faa0 580->573 chat.cpp takes the chat command run (0x47B3B0-0x47F8B0): eight functions from WardenClient.cpp with the globals they own, and the placeholders Unknown_0047B3B0, Unknown_0047BAD0, Unknown_0047BD80, Unknown_0047BDF0, Unknown_0047CDA0, Unknown_0047CEE0 and Unknown_0047D8A0; VERIFIED bc3ba8e17363
  - Replaces `lane4/chat-run` (stacked on the old gfx-more) and `lane4/chat-run-2` (based on #292). Based on #293.
  - Evidence: assert line numbers rise from chat.cpp's own 235-669 (0x47AD60-0x47B2E0) through 1256-1611 (0x47DBB0-0x47E3D0); WardenClient.cpp's `.\WARDEN\WardenClient.cpp` numbering starts again at 163 at 0x47FA20.
  - chat.cpp gets WardenClient.cpp's flags (/GS-): several functions in the run have char buffers and no cookie, and chat.cpp's own functions build the same either way.
  - The three identical 5-byte option stubs get a name each: 0x47CDE0 is `sub_0047CDE0`, 0x47CEE0 is `sub_0047CEE0` (units.json names changed with them).
  - Nothing outside lane 4. Borrowed data on this build: 15,691 B (main #293: 15,689 B), +2 B I have not tracked down yet. Merges into #294 with a docs-only conflict.

## Questions

## Notes for other lanes

- Lane 1: by the ownership table, these lane-4 residue placeholders are yours now: Unknown_004C0440 (0x4C0550 left: a static panel mode swaps a stack slot in 0x4BFDD0), Unknown_004C7C80, Unknown_004C97C0 (register allocation in Skills.cpp).
- Lane 2: `D2ClientTypes.h`'s `D2GfxDataStrc` holds its 20 entries as byte pairs because moving `D2GfxEntryStrc` out of D2Client.h changes code in useitem.cpp and inv_0048DD90.cpp. useitem.cpp and Unknown_0047BD80 kept private cel-context copies for the same reason (Unknown_0047BD80 is now in chat.cpp on chat-run-3, using the shared one).

## Left in place (and why)

- Unknown_0047C420 (0x47C420): in chat.cpp it compiles with different registers; cause not found yet. chat.cpp keeps an unmarked copy for its caller 0x47CA70, as WardenClient.cpp did.
- WardenClient.cpp 0x47F8B0-0x47F990 and Unknown_0047F950: no assert; they sit on the chat/Warden boundary just before 0x47FA20.
- Weather block 0x472210-0x473F50 (Unknown_00472210, Unknown_004726F0, Unknown_00472890, Unknown_00473090, Unknown_004737B0): no assert path or data reference names its file yet.
- Unknown_0046C7D0: Gfx.cpp would inline its functions into 0x46CE40 and 0x46D780.
- Hireables.cpp's four placeholders (0x493A00, 0x493B50, 0x493CE0, 0x493E10): they disagree on the pet-icon helpers' argument order; aligning the calls made seven functions differ.
