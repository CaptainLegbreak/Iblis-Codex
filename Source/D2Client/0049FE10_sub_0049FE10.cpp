void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void* gpCelFile_007BF26C;                                                                                   // 0x007BF26C
void* gpCelFile_007BF270;                                                                                   // 0x007BF270
void* gpCelFile_007BF274;                                                                                   // 0x007BF274

// 0x0049FE10
void __cdecl sub_0049FE10()
{
    if (gpCelFile_007BF270)
    {
        sub_00478A00(gpCelFile_007BF270);
        gpCelFile_007BF270 = 0;
    }
    if (gpCelFile_007BF26C)
    {
        sub_00478A00(gpCelFile_007BF26C);
        gpCelFile_007BF26C = 0;
    }
    if (gpCelFile_007BF274)
    {
        sub_00478A00(gpCelFile_007BF274);
        gpCelFile_007BF274 = 0;
    }
}
