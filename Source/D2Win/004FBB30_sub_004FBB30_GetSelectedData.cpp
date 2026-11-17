extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WinListEntry004FBB30Strc
{
    void* pData;
    unsigned char f_4[0x18];
    D2WinListEntry004FBB30Strc* pNext1C;
};
struct D2WinControl004FBB30Strc
{
    int nType;
    unsigned char f_4[0x44];
    D2WinListEntry004FBB30Strc* pFirstEntry48;
    unsigned char unk_4C[0x10];
    unsigned int dwFlags5C;
    int nSelected60;
};

// 0x004FBB30
void* __fastcall sub_004FBB30_GetSelectedData(D2WinControl004FBB30Strc* pControl)
{
    D2_ASSERT(pControl, 0x2A6);
    D2_ASSERT(pControl->nType == 4, 0x2A7);
    if (pControl->nSelected60 != -1 && (pControl->dwFlags5C & 1))
    {
        D2WinListEntry004FBB30Strc* pEntry;
        int nIndex;
        for (pEntry = pControl->pFirstEntry48, nIndex = 0; pEntry; pEntry = pEntry->pNext1C, ++nIndex)
        {
            if (pControl->nSelected60 == nIndex)
            {
                return pEntry->pData;
            }
        }
    }
    return 0;
}
