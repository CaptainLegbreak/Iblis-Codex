struct D2TxtLinkStrc;
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0
extern int gbCompileTxt;                                                                                    // 0x0096C8B4
extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308
void* gpCompCodeTxt_0096BCAC;                                                                               // 0x0096BCAC
extern D2TxtLinkStrc* gpCompCodeLinker_0096BCB0;                                                            // 0x0096BCB0
void* gpPlayerClassTxt_0096BC30;                                                                            // 0x0096BC30
extern D2TxtLinkStrc* gpPlayerClassLinker_0096BC34;                                                         // 0x0096BC34
void* gpBodyLocsTxt_0096BC38;                                                                               // 0x0096BC38
D2TxtLinkStrc* gpBodyLocsLinker_0096BC3C;                                                                   // 0x0096BC3C
void* gpStorePageTxt_0096BC40;                                                                              // 0x0096BC40
D2TxtLinkStrc* gpStorePageLinker_0096BC44;                                                                  // 0x0096BC44
void* gpElemTypesTxt_0096BC48;                                                                              // 0x0096BC48
extern D2TxtLinkStrc* gpElemTypesLinker_0096BC4C;                                                           // 0x0096BC4C
void* gpHitClassTxt_0096BC50;                                                                               // 0x0096BC50
extern D2TxtLinkStrc* gpHitClassLinker_0096BC54;                                                            // 0x0096BC54
void* gpColorsTxt_0096C5E0;                                                                                 // 0x0096C5E0
D2TxtLinkStrc* gpColorsLinker_0096C5E4;                                                                     // 0x0096C5E4
void* gpHireDescTxt_0096BCE4;                                                                               // 0x0096BCE4
extern D2TxtLinkStrc* gpHireDescLinker_0096BCE8;                                                            // 0x0096BCE8
void* gpMonModeTxt_0096BC58;                                                                                // 0x0096BC58
extern D2TxtLinkStrc* gpMonModeLinker_0096BC5C;                                                             // 0x0096BC5C
void* gpPlrModeTxt_0096BC60;                                                                                // 0x0096BC60
extern D2TxtLinkStrc* gpPlrModeLinker_0096BC64;                                                             // 0x0096BC64
void* gpMonAiTxt_0096BCB8;                                                                                  // 0x0096BCB8
D2TxtLinkStrc* gpMonAiLinker_0096BCBC;                                                                      // 0x0096BCBC
void* gpMonPlaceTxt_0096C6CC;                                                                               // 0x0096C6CC
D2TxtLinkStrc* gpMonPlaceLinker_0096C6D0;                                                                   // 0x0096C6D0
void* gpSkillCalcTxt_0096BC68;                                                                              // 0x0096BC68
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C;                                                           // 0x0096BC6C
void* gpMissileCalcTxt_0096BC88;                                                                            // 0x0096BC88
extern D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C;                                                         // 0x0096BC8C
void* gpSkillCodeTxt_0096BC9C;                                                                              // 0x0096BC9C
D2TxtLinkStrc* gpSkillCodeLinker_0096BCA0;                                                                  // 0x0096BCA0
void* gpEventsTxt_0096BCA4;                                                                                 // 0x0096BCA4
extern D2TxtLinkStrc* gpEventsLinker_0096BCA8;                                                              // 0x0096BCA8

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

// 0x00612EA0
void __stdcall sub_00612EA0_UnloadCompCodeAndCompileBins()
{
    DATATBLS_UnloadBinInline(gpCompCodeTxt_0096BCAC);
    FOG_FreeLinker(gpCompCodeLinker_0096BCB0);

    if (gbCompileTxt)
    {
        DATATBLS_UnloadBinInline(gpPlayerClassTxt_0096BC30);
        FOG_FreeLinker(gpPlayerClassLinker_0096BC34);
        DATATBLS_UnloadBinInline(gpBodyLocsTxt_0096BC38);
        FOG_FreeLinker(gpBodyLocsLinker_0096BC3C);
        DATATBLS_UnloadBinInline(gpStorePageTxt_0096BC40);
        FOG_FreeLinker(gpStorePageLinker_0096BC44);
        DATATBLS_UnloadBinInline(gpElemTypesTxt_0096BC48);
        FOG_FreeLinker(gpElemTypesLinker_0096BC4C);
        DATATBLS_UnloadBinInline(gpHitClassTxt_0096BC50);
        FOG_FreeLinker(gpHitClassLinker_0096BC54);
        DATATBLS_UnloadBinInline(gpColorsTxt_0096C5E0);
        FOG_FreeLinker(gpColorsLinker_0096C5E4);
        DATATBLS_UnloadBinInline(gpHireDescTxt_0096BCE4);
        FOG_FreeLinker(gpHireDescLinker_0096BCE8);
        DATATBLS_UnloadBinInline(gpMonModeTxt_0096BC58);
        FOG_FreeLinker(gpMonModeLinker_0096BC5C);
        DATATBLS_UnloadBinInline(gpPlrModeTxt_0096BC60);
        FOG_FreeLinker(gpPlrModeLinker_0096BC64);
        DATATBLS_UnloadBinInline(gpMonAiTxt_0096BCB8);
        FOG_FreeLinker(gpMonAiLinker_0096BCBC);
        DATATBLS_UnloadBinInline(gpMonPlaceTxt_0096C6CC);
        FOG_FreeLinker(gpMonPlaceLinker_0096C6D0);
        DATATBLS_UnloadBinInline(gpSkillCalcTxt_0096BC68);
        FOG_FreeLinker(gpSkillCalcLinker_0096BC6C);
        DATATBLS_UnloadBinInline(gpMissileCalcTxt_0096BC88);
        FOG_FreeLinker(gpMissileCalcLinker_0096BC8C);
        DATATBLS_UnloadBinInline(gpSkillCodeTxt_0096BC9C);
        FOG_FreeLinker(gpSkillCodeLinker_0096BCA0);
        DATATBLS_UnloadBinInline(gpEventsTxt_0096BCA4);
        FOG_FreeLinker(gpEventsLinker_0096BCA8);
    }
}

#include "gen/data/Source/D2Common/00612EA0_sub_00612EA0_UnloadCompCodeAndCompileBins.inc"
