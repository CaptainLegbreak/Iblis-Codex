struct D2StringTableStrc;

struct D2StrCacheNodeStrc
{
    wchar_t* pText;
    char* szKey;
    D2StrCacheNodeStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2StrCacheNodeStrc* gpStringCache_008829B0;                                                                 // 0x008829B0
extern D2StringTableStrc* gpStringTable_008829B4;                                                           // 0x008829B4
extern void* gpStringIndex_008829B8;                                                                        // 0x008829B8
void* gpPatchStringIndex_008829BC;                                                                          // 0x008829BC
void* gpExpansionStringIndex_008829C0;                                                                      // 0x008829C0
void* gpStringData_008829C4;                                                                                // 0x008829C4
void* gpPatchStringData_008829C8;                                                                           // 0x008829C8
void* gpExpansionStringData_008829CC;                                                                       // 0x008829CC
D2StringTableStrc* gpPatchStringTable_008829D0;                                                             // 0x008829D0
D2StringTableStrc* gpExpansionStringTable_008829D4;                                                         // 0x008829D4
int gnStringTableRefs_008829D8;                                                                             // 0x008829D8
void __cdecl sub_00527720();                                                                                // 0x00527720

// 0x00524E40
void __cdecl sub_00524E40_UnloadStringTables()
{
    if (gpStringTable_008829B4 && --gnStringTableRefs_008829D8 == 0)
    {
        if (gpStringIndex_008829B8)
        {
            FOG_Free(gpStringData_008829C4, ".\\StrTable\\strtable.cpp", 0x329, 0);
            gpStringData_008829C4 = 0;
            FOG_Free(gpStringIndex_008829B8, ".\\StrTable\\strtable.cpp", 0x32E, 0);
            gpStringIndex_008829B8 = 0;
        }
        FOG_Free(gpStringTable_008829B4, ".\\StrTable\\strtable.cpp", 0x121, 0);
        gpStringTable_008829B4 = 0;

        if (gpPatchStringIndex_008829BC)
        {
            FOG_Free(gpPatchStringIndex_008829BC, ".\\StrTable\\strtable.cpp", 0x33C, 0);
            gpPatchStringIndex_008829BC = 0;
        }
        if (gpPatchStringData_008829C8)
        {
            FOG_Free(gpPatchStringData_008829C8, ".\\StrTable\\strtable.cpp", 0x341, 0);
            gpPatchStringData_008829C8 = 0;
        }
        FOG_Free(gpPatchStringTable_008829D0, ".\\StrTable\\strtable.cpp", 0x121, 0);
        gpPatchStringTable_008829D0 = 0;

        if (gpExpansionStringIndex_008829C0)
        {
            FOG_Free(gpExpansionStringIndex_008829C0, ".\\StrTable\\strtable.cpp", 0x34A, 0);
            gpExpansionStringIndex_008829C0 = 0;
        }
        if (gpExpansionStringData_008829CC)
        {
            FOG_Free(gpExpansionStringData_008829CC, ".\\StrTable\\strtable.cpp", 0x34F, 0);
            gpExpansionStringData_008829CC = 0;
        }
        if (gpExpansionStringTable_008829D4)
        {
            FOG_Free(gpExpansionStringTable_008829D4, ".\\StrTable\\strtable.cpp", 0x121, 0);
            gpExpansionStringTable_008829D4 = 0;
        }

        D2StrCacheNodeStrc* pNode = gpStringCache_008829B0;
        while (pNode)
        {
            D2StrCacheNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode->pText, ".\\StrTable\\strtable.cpp", 0x377, 0);
            FOG_Free(pNode->szKey, ".\\StrTable\\strtable.cpp", 0x378, 0);
            FOG_Free(pNode, ".\\StrTable\\strtable.cpp", 0x379, 0);
            pNode = pNext;
        }
        gpStringCache_008829B0 = 0;
        sub_00527720();
    }
}
