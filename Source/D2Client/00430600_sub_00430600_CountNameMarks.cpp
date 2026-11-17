extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SlotEntryStrc
{
    int unk0x00;
    int nField04;
};

extern void** gppSlots_00779988;                                                                            // 0x00779988

// 0x00430600
static __forceinline int sub_00430600_CountNameMarks(const char* szText, int nLength)
{
    int nCount = 0;
    for (int i = 0; i < nLength; ++i)
    {
        if (szText[i] == '-' || szText[i] == '_')
        {
            ++nCount;
        }
    }
    return nCount;
}

int __stdcall sub_M121_Emit_00430600(const char* szText, int nLength) { return sub_00430600_CountNameMarks(szText, nLength); }

// 0x00430B80
int __fastcall sub_00430B80_GetSlotField04(int nSlot)
{
    D2SlotEntryStrc* pSlot = (D2SlotEntryStrc*)gppSlots_00779988[nSlot];
    D2_ASSERT(pSlot, 0x1162);
    return pSlot->nField04;
}
