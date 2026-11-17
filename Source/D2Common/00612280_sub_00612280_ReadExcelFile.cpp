extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszExcelDirectory_006D8ED4[];                                                         // 0x006D8ED4

void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

struct D2ItemTypesTxt
{
    char szCode[4];
    short nEquiv1;
    short nEquiv2;
    char unk0x08[0xDC];
};

D2ItemTypesTxt* gpItemTypesTxt_0096C828;                                                                    // 0x0096C828
int gnItemTypesTxtRecordCount_0096C82C;                                                                     // 0x0096C82C

// 0x00612280
void* __fastcall sub_00612280_ReadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnSize, const char* szFile, int nLine)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szExtension);
    return sub_00517079_LoadFile(hArchive, szPath, pnSize, ".\\DATATBLS\\DataTbls.cpp", 0x82F);
}

// 0x00638CD0
int __fastcall DATATBLS_CheckItemTypesEquivalenceNested(int nItemType1, int nItemType2)
{
    if (nItemType2 <= 0)
        return 1;
    if (nItemType1 <= 0 || nItemType1 >= gnItemTypesTxtRecordCount_0096C82C)
        return 0;
    int nParentItemTypes[128];
    nParentItemTypes[0] = nItemType1;
    int nIndex = 1;
    do
    {
        int nItemType = nParentItemTypes[--nIndex];
        if (nItemType2 == nItemType)
            return 1;
        if (nItemType >= gnItemTypesTxtRecordCount_0096C82C)
            return 0;
        if (nIndex > 124)
            return 0;
        D2ItemTypesTxt* pItemTypesTxtRecord = &gpItemTypesTxt_0096C828[nItemType];
        if (pItemTypesTxtRecord->nEquiv1 > 0)
        {
            nParentItemTypes[nIndex++] = pItemTypesTxtRecord->nEquiv1;
            if (pItemTypesTxtRecord->nEquiv2)
                nParentItemTypes[nIndex++] = pItemTypesTxtRecord->nEquiv2;
        }
    }
    while (nIndex);
    return 0;
}
