# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/soundenv-name 1d95fa82 573->573 SkillDesc.cpp and SkillDesc_004E1FF0.cpp call 0x4DF6C0 as GFXUTIL_ApplySoundEnviron (local prototype) instead of sub_004DF6C0; VERIFIED 585736b45a04
  - Based on #294. Nothing outside lane 4.
  - `lane4/chat-run-3` is not needed: chat-run-2 is in #294; ignore -3.

## Questions

## Notes for other lanes

- Lane 1: D2Client.h line 847 still declares 0x4DF6C0 as `sub_004DF6C0(int nArg)`; nothing in lane 4 uses that declaration any more.
- Lane 1: by the ownership table, these lane-4 residue placeholders are yours now: Unknown_004C0440 (0x4C0550 left: a static panel mode swaps a stack slot in 0x4BFDD0), Unknown_004C7C80, Unknown_004C97C0 (register allocation in Skills.cpp).
- Lane 2: `D2ClientTypes.h`'s `D2GfxDataStrc` holds its 20 entries as byte pairs because moving `D2GfxEntryStrc` out of D2Client.h changes code in useitem.cpp and inv_0048DD90.cpp. useitem.cpp and Unknown_0047BD80 kept private cel-context copies for the same reason (Unknown_0047BD80 is now in chat.cpp on chat-run-3, using the shared one).

## Left in place (and why)

- Unknown_0047C420 (0x47C420): in chat.cpp it compiles with different registers; cause not found yet. chat.cpp keeps an unmarked copy for its caller 0x47CA70, as WardenClient.cpp did.
- WardenClient.cpp 0x47F8B0-0x47F990 and Unknown_0047F950: no assert; they sit on the chat/Warden boundary just before 0x47FA20.
- Weather block 0x472210-0x473F50 (Unknown_00472210, Unknown_004726F0, Unknown_00472890, Unknown_00473090, Unknown_004737B0): no assert path or data reference names its file yet.
- Unknown_0046C7D0: Gfx.cpp would inline its functions into 0x46CE40 and 0x46D780.
- Hireables.cpp's four placeholders (0x493A00, 0x493B50, 0x493CE0, 0x493E10): they disagree on the pet-icon helpers' argument order; aligning the calls made seven functions differ.
