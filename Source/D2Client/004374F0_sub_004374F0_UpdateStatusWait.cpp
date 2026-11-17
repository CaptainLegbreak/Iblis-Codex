struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x04];
    void* (__fastcall* pfnSlot04)();
    char unk0x08[0x08];
    void (__fastcall* pfnSlot10)();
};

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
int gnStatusDots_007799B4;        // 0x007799B4
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __fastcall sub_004F9190(); // 0x004F9190
void __cdecl sub_00436AD0_UpdateStatus(); // 0x00436AD0
void __cdecl sub_0043B820_Clear(); // 0x0043B820
int __cdecl sub_0043B830(); // 0x0043B830

// 0x004374F0
int __stdcall sub_004374F0_UpdateStatusWait(int nArg)
{
    sub_00436AD0_UpdateStatus();
    if (!gnStatusDots_007799B4)
    {
        sub_0043B820_Clear();
        gnStatusDots_007799B4 = (int)gpFuncTable_0077ABF0->pfnSlot04();
        if (!gnStatusDots_007799B4)
        {
            sub_004F9190();
            return 1;
        }
    }

    if (WaitForSingleObject((void*)gnStatusDots_007799B4, 0) == 0)
    {
        sub_004F9190();
    }

    if (sub_0043B830())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }

    return 1;
}
