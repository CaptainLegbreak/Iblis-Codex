struct D2LaunchSlotStrc
{
    char* szName;
    void* pData;
};

struct D2MenuListStrc
{
    int unk_00;
    int nCount;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk_00[0x40];
    D2MenuListStrc* (__fastcall* pfnGetMenuList)(int nArg);
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);
extern "C" unsigned int __cdecl strlen(const char* szText);
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfnCompare)(const void*, const void*)); // 0x00685B50
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszMainMenusFile_006D41C0[]; // 0x006D41C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __cdecl sub_0042F6E0(); // 0x0042F6E0
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
int __stdcall sub_00431D10_ClearLoop(int nArg); // 0x00431D10
int __cdecl sub_00430B00_CompareNames(const void* pEntry1, const void* pEntry2); // 0x00430B00
extern D2MenuListStrc* gpMenuList_007795C0; // 0x007795C0
static D2LaunchSlotStrc** gppSlots_00779988; // 0x00779988
extern int gdwGlobal_0077998C; // 0x0077998C
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x004309C0
int __stdcall sub_004309C0_AddToSlots(void* pEntry)
{
    D2_ASSERT(gppSlots_00779988, 4383);
    for (int i = 0; i < gdwGlobal_0077998C; i++)
    {
        if (!gppSlots_00779988[i])
        {
            gppSlots_00779988[i] = (D2LaunchSlotStrc*)pEntry;
            return 1;
        }
    }
    return 0;
}

// 0x00430A20
int __cdecl sub_00430A20_FreeSlots()
{
    if (!gppSlots_00779988)
        return 1;
    for (int i = 0; i < gdwGlobal_0077998C; i++)
    {
        D2LaunchSlotStrc* pSlot = gppSlots_00779988[i];
        if (pSlot)
        {
            D2_ASSERT(pSlot->pData, 0x1139);
            sub_0040B3C0(pSlot->pData, gszMainMenusFile_006D41C0, 0x113A, 0);
            D2_ASSERT(gppSlots_00779988[i]->szName, 0x113B);
            sub_0040B3C0(gppSlots_00779988[i]->szName, gszMainMenusFile_006D41C0, 0x113C, 0);
            sub_0040B3C0(gppSlots_00779988[i], gszMainMenusFile_006D41C0, 0x113E, 0);
        }
    }
    sub_0040B3C0(gppSlots_00779988, gszMainMenusFile_006D41C0, 0x1141, 0);
    gppSlots_00779988 = 0;
    return 1;
}

// 0x00434060
void __cdecl sub_00434060_BuildMenuList()
{
    sub_0042F6E0();
    sub_004FA590_RunLoop(sub_00431D10_ClearLoop);
    if (gpFuncTable_0077ABF0)
        gpMenuList_007795C0 = gpFuncTable_0077ABF0->pfnGetMenuList(0);
    sub_0042F3F0_DestroyControls();
    D2MenuListStrc* pList = gpMenuList_007795C0;
    if (!pList)
    {
        gdwGlobal_0077998C = -1;
        return;
    }
    gdwGlobal_0077998C = pList->nCount;
    D2_ASSERT(gdwGlobal_0077998C < 512, 4481);
    char* pText = (char*)(pList + 1);
    sub_00430A20_FreeSlots();
    int nCount = gdwGlobal_0077998C;
    if (gdwGlobal_0077998C)
    {
        const unsigned int nSize = gdwGlobal_0077998C * sizeof(D2LaunchSlotStrc*);
        gppSlots_00779988 = (D2LaunchSlotStrc**)FOG_Alloc(nSize, gszMainMenusFile_006D41C0, 4492, 0);
        memset(gppSlots_00779988, 0, nSize);
        for (int i = 0; i < nCount; ++i)
        {
            D2LaunchSlotStrc* pSlot = (D2LaunchSlotStrc*)FOG_Alloc(sizeof(D2LaunchSlotStrc), gszMainMenusFile_006D41C0, 4498, 0);
            pText += sizeof(int);
            unsigned int nLength = strlen(pText) + 1;
            pSlot->szName = (char*)FOG_Alloc(nLength, gszMainMenusFile_006D41C0, 4511, 0);
            SStrCopy(pSlot->szName, pText, nLength);
            pText += nLength;
            nLength = strlen(pText) + 1;
            pSlot->pData = FOG_Alloc(nLength, gszMainMenusFile_006D41C0, 4516, 0);
            SStrCopy((char*)pSlot->pData, pText, nLength);
            pText += nLength;
            sub_004309C0_AddToSlots(pSlot);
        }
        qsort(gppSlots_00779988, gdwGlobal_0077998C, sizeof(D2LaunchSlotStrc*), sub_00430B00_CompareNames);
    }
}
