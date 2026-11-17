void __fastcall sub_005179A4_VirtualFree(void* pMemory);                                                    // 0x005179A4
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void* gpCel_007B9554;                                                                                       // 0x007B9554
void* gpCel_007B9558;                                                                                       // 0x007B9558

// 0x00475C30
void __fastcall sub_00475C30_FreeIfSet(void* pMemory)
{
    if (pMemory)
    {
        sub_005179A4_VirtualFree(pMemory);
    }
}

// 0x00475D20
void __fastcall sub_00475D20_FreeIfSet(void* pMemory)
{
    if (pMemory)
    {
        sub_005179A4_VirtualFree(pMemory);
    }
}

// 0x00475DE0
void __fastcall sub_00475DE0_FreeIfSet(void* pMemory)
{
    if (pMemory)
    {
        sub_005179A4_VirtualFree(pMemory);
    }
}

// 0x00475EB0
void __cdecl sub_00475EB0_FreeCels()
{
    if (gpCel_007B9554)
    {
        sub_00478A00(gpCel_007B9554);
        gpCel_007B9554 = 0;
    }
    if (gpCel_007B9558)
    {
        sub_00478A00(gpCel_007B9558);
        gpCel_007B9558 = 0;
    }
}
