extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
short* __fastcall sub_006BCC10_GetEntry(void* pDataArray, int nHandle); // 0x006BCC10
extern const char gszEmptyAssertText_006CC837; // 0x006CC837

// 0x006BCC90
short* __fastcall sub_006BCC90_GetEntryOrHalt(void* pDataArray, int nHandle)
{
    short* pEntry = sub_006BCC10_GetEntry(pDataArray, nHandle);
    if (!pEntry)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 253);
        exit(-1);
    }
    return pEntry;
}
