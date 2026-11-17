struct _iobuf;
struct D2TxtLinkStrc;

struct D2StatesTxt
{
    unsigned short wState;
    char unk0x02[0xE];
    unsigned char nStateFlags[8];
    char unk0x18[0x24];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0
void* __fastcall sub_00612280_ReadExcelFile(void* hArchive, const char* szName, const char* szExtension, int* pSize, const char* szFile, int nLine); // 0x00612280

extern "C" const char gszExcelDirectory_006D8ED4[];                                                         // 0x006D8ED4
extern "C" const char gszFileModeWb_006D69E0[];                                                             // 0x006D69E0
extern "C" const char szBinExtension_006DCC68[];                                                            // 0x006DCC68

extern int gbCompileTxt;                                                                                    // 0x0096C8B4
extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2StatesTxt* gpStatesTxt;                                                                                   // 0x0096BCEC
extern D2TxtLinkStrc* gpStatesLinker_0096BCF0;                                                              // 0x0096BCF0
extern int gnStatesTxtRecordCount;                                                                          // 0x0096BCF4
unsigned int* gpStateMasks_0096BCF8;                                                                        // 0x0096BCF8
unsigned int* gfStateMasks_0096BCFC[40];                                                                    // 0x0096BCFC
short* gpProgressiveStates_0096BD9C;                                                                        // 0x0096BD9C
short* gpCurseStates_0096BDA4;                                                                              // 0x0096BDA4
short* gpTransformStates_0096BDAC;                                                                          // 0x0096BDAC
short* gpActionStates_0096BDB4;                                                                             // 0x0096BDB4

char* gpSkillsCode_0096BC70;                                                                                // 0x0096BC70
extern int gnSkillsCodeSize_0096BC74;                                                                       // 0x0096BC74
extern int gnSkillsCodeSizeEx_0096BC78;                                                                     // 0x0096BC78
char* gpSkillDescCode_0096BC7C;                                                                             // 0x0096BC7C
extern int gnSkillDescCodeSize_0096BC80;                                                                    // 0x0096BC80
extern int gnSkillDescCodeSizeEx_0096BC84;                                                                  // 0x0096BC84
extern void* gpSkillDescTxt_0096C7BC;                                                                       // 0x0096C7BC
extern D2TxtLinkStrc* gpSkillDescLinker_0096C7C0;                                                           // 0x0096C7C0
extern int gnSkillDescTxtRecordCount_0096C7C4;                                                              // 0x0096C7C4
extern void* gpSkillsTxt_0096C7C8;                                                                          // 0x0096C7C8
extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC;                                                              // 0x0096C7CC
extern int gnSkillsTxtRecordCount_0096C7D0;                                                                 // 0x0096C7D0
extern short* gpClassSkillCount_0096C7D4;                                                                   // 0x0096C7D4
extern int gnHighestClassSkillCount_0096C7D8;                                                               // 0x0096C7D8
extern short* gpClassSkillList_0096C7DC;                                                                    // 0x0096C7DC
extern int gnPassiveSkills_0096C7E0;                                                                        // 0x0096C7E0
extern short* gpPassiveSkills_0096C7E4;                                                                     // 0x0096C7E4

static void DATATBLS_UnloadBinInline(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00611D60
void __fastcall sub_00611D60_BuildStateMask(unsigned int* pMask, int nFlag)
{
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (pStatesTxt[i].nStateFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7])
            pMask[i >> 5] |= gdwBitMasks[i & 0x1F];
    }
}

// 0x00613E90
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx)
{
    int nSize;
    char szFilePath[0x104];
    if (gbCompileTxt && *ppFileHandle)
    {
        wsprintfA(szFilePath, "%s\\%s.bin", gszExcelDirectory_006D8ED4, szFile);
        _iobuf* pFile = fopen(szFilePath, gszFileModeWb_006D69E0);
        if (pFile)
        {
            fwrite(*ppFileHandle, *pSize, 1, pFile);
            fclose(pFile);
        }
        FOG_FreePool(0, *ppFileHandle, ".\\DATATBLS\\DataTbls.cpp", 0x275, 0);
    }
    *ppFileHandle = sub_00612280_ReadExcelFile(hArchive, szFile, szBinExtension_006DCC68, &nSize, ".\\DATATBLS\\DataTbls.cpp", 0x27A);
    *pSizeEx = nSize;
    *pSize = nSize;
}

// 0x00617C30
void __fastcall DATATBLS_UnloadSkills_SkillDescTxt()
{
    if (gpClassSkillCount_0096C7D4)
    {
        FOG_FreePool(0, gpClassSkillCount_0096C7D4, ".\\DATATBLS\\DataTbls.cpp", 0x5B8, 0);
        gpClassSkillCount_0096C7D4 = 0;
    }
    if (gpClassSkillList_0096C7DC)
    {
        FOG_FreePool(0, gpClassSkillList_0096C7DC, ".\\DATATBLS\\DataTbls.cpp", 0x5BE, 0);
        gpClassSkillList_0096C7DC = 0;
    }
    gnHighestClassSkillCount_0096C7D8 = 0;
    if (gpPassiveSkills_0096C7E4)
    {
        FOG_FreePool(0, gpPassiveSkills_0096C7E4, ".\\DATATBLS\\DataTbls.cpp", 0x5C5, 0);
        gpPassiveSkills_0096C7E4 = 0;
    }
    gnPassiveSkills_0096C7E0 = 0;
    if (gpSkillsCode_0096BC70)
    {
        FOG_FreePool(0, gpSkillsCode_0096BC70, ".\\DATATBLS\\DataTbls.cpp", 0x5CC, 0);
        gpSkillsCode_0096BC70 = 0;
    }
    gnSkillsCodeSize_0096BC74 = 0;
    gnSkillsCodeSizeEx_0096BC78 = 0;
    if (gpSkillDescCode_0096BC7C)
    {
        FOG_FreePool(0, gpSkillDescCode_0096BC7C, ".\\DATATBLS\\DataTbls.cpp", 0x5D4, 0);
        gpSkillDescCode_0096BC7C = 0;
    }
    gnSkillDescCodeSize_0096BC80 = 0;
    gnSkillDescCodeSizeEx_0096BC84 = 0;
    DATATBLS_UnloadBinInline(gpSkillsTxt_0096C7C8);
    FOG_FreeLinker(gpSkillsLinker_0096C7CC);
    gnSkillsTxtRecordCount_0096C7D0 = 0;
    DATATBLS_UnloadBinInline(gpSkillDescTxt_0096C7BC);
    FOG_FreeLinker(gpSkillDescLinker_0096C7C0);
    gnSkillDescTxtRecordCount_0096C7C4 = 0;
}

// 0x00618C90
void __fastcall DATATBLS_UnloadStatesTxt()
{
    if (gpStateMasks_0096BCF8)
    {
        FOG_FreePool(0, gpStateMasks_0096BCF8, ".\\DATATBLS\\DataTbls.cpp", 0x6E8, 0);
        gpStateMasks_0096BCF8 = 0;
    }
    if (gpProgressiveStates_0096BD9C)
    {
        FOG_FreePool(0, gpProgressiveStates_0096BD9C, ".\\DATATBLS\\DataTbls.cpp", 0x6ED, 0);
        gpProgressiveStates_0096BD9C = 0;
    }
    if (gpCurseStates_0096BDA4)
    {
        FOG_FreePool(0, gpCurseStates_0096BDA4, ".\\DATATBLS\\DataTbls.cpp", 0x6F2, 0);
        gpCurseStates_0096BDA4 = 0;
    }
    if (gpTransformStates_0096BDAC)
    {
        FOG_FreePool(0, gpTransformStates_0096BDAC, ".\\DATATBLS\\DataTbls.cpp", 0x6F7, 0);
        gpTransformStates_0096BDAC = 0;
    }
    if (gpActionStates_0096BDB4)
    {
        FOG_FreePool(0, gpActionStates_0096BDB4, ".\\DATATBLS\\DataTbls.cpp", 0x6FC, 0);
        gpActionStates_0096BDB4 = 0;
    }
    memset(gfStateMasks_0096BCFC, 0, sizeof(gfStateMasks_0096BCFC));
    DATATBLS_UnloadBinInline(gpStatesTxt);
    FOG_FreeLinker(gpStatesLinker_0096BCF0);
}
