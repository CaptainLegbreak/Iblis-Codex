struct D2TxtLinkStrc;
struct D2AnimDataTableStrc;

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0

void __fastcall sub_00612EA0_UnloadCompileTxtBins();                                                        // 0x00612EA0
void __fastcall DATATBLS_UnloadMissilesTxt();                                                               // 0x00663210
void __fastcall DATATBLS_UnloadOverlayTxt();                                                                // 0x00664530
void __fastcall DATATBLS_UnloadSkills_SkillDescTxt();                                                       // 0x00617C30
void __fastcall DATATBLS_UnloadItemStatCostTxt();                                                           // 0x006385D0
void __fastcall DATATBLS_UnloadStatesTxt();                                                                 // 0x00618C90
void __fastcall DATATBLS_UnloadItemsTxt();                                                                  // 0x00633540
void __fastcall DATATBLS_UnloadPropertiesTxt();                                                             // 0x00638AA0
void __fastcall DATATBLS_UnloadMagicSuffix_Prefix_AutomagicTxt();                                           // 0x00633EA0
void __fastcall DATATBLS_UnloadRareSuffix_PrefixTxt();                                                      // 0x00634220
void __fastcall DATATBLS_UnloadUniqueItemsTxt();                                                            // 0x00634D90
void __fastcall DATATBLS_UnloadSets_SetItemsTxt();                                                          // 0x00636730
void __fastcall DATATBLS_UnloadQualityItemsTxt();                                                           // 0x00636B00
void __fastcall DATATBLS_UnloadLowQualityItemsTxt();                                                        // 0x006375A0
void __fastcall DATATBLS_UnloadGemsTxt();                                                                   // 0x006372A0
void __fastcall DATATBLS_UnloadBooksTxt();                                                                  // 0x00637490
void __fastcall DATATBLS_UnloadItemRatioTxt();                                                              // 0x006378F0
void __fastcall DATATBLS_UnloadGambleTxt();                                                                 // 0x00638C80
void __fastcall DATATBLS_UnloadItemTypesTxt();                                                              // 0x006393E0
void __fastcall sub_006586D0();                                                           // 0x006586D0
void __fastcall DATATBLS_UnloadPlrMode_Type_MonMode_ObjMode_Type_Composit_ArmtypeTxt();                     // 0x0065B3C0
void __fastcall DATATBLS_UnloadAnimDataD2(D2AnimDataTableStrc* pAnimData);                                  // 0x0066A830
void __fastcall DATATBLS_UnloadSomeMonsterTxts();                                                           // 0x0065A190
void __fastcall DATATBLS_UnloadLevelsTxt();                                                                 // 0x0061DC60
void __fastcall DATATBLS_UnloadLevelDefsBin();                                                              // 0x0061E440
void __fastcall DATATBLS_UnloadLevelTypesTxt();                                                             // 0x0061EA90
void __fastcall DATATBLS_UnloadLvlPrestTxt();                                                               // 0x0061F030
void __fastcall DATATBLS_UnloadLvlWarpTxt();                                                                // 0x0061F300
void __fastcall DATATBLS_UnloadLvlMazeTxt();                                                                // 0x0061F480
void __fastcall DATATBLS_FreeGlobalTileLibraryHash();                                                       // 0x0061FBF0
void __fastcall DATATBLS_UnloadLvlSubTxt();                                                                 // 0x0061F9C0
void __fastcall DATATBLS_FreeAutomap();                                                                     // 0x006200D0
void __fastcall DATATBLS_UnloadObjectsTxt();                                                                // 0x00640EE0
void __fastcall DATATBLS_UnloadObjGroupTxt();                                                               // 0x00640F00
void __fastcall DATATBLS_UnloadShrinesTxt();                                                                // 0x00641510
void __fastcall sub_0065C130();                                                               // 0x0065C130
void __fastcall DATATBLS_UnloadRunesTxt();                                                                  // 0x00639C90
int __stdcall DATATBLS_FreeCollisionFieldTable();                                                           // 0x0066A420
void __fastcall DATATBLS_UnloadBeltsTxt();                                                                  // 0x00660C60
void __fastcall DATATBLS_UnloadMonItemPercentTxt();                                                         // 0x00654FC0
void __fastcall DATATBLS_UnloadArenaTxt();                                                                  // 0x00664AF0
void __fastcall DATATBLS_UnloadCubeMainTxt();                                                               // 0x0066A1A0
void __fastcall DATATBLS_UnloadCharTemplateTxt();                                                           // 0x00665740
void __fastcall D2COMMON_10916_Return();                                                                    // 0x0066A280

extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308
extern void* gpCharstatsTxt;                                                                                // 0x0096C7F4
extern void* gpPettypeTxt;                                                                                  // 0x0096C818
extern D2TxtLinkStrc* gpPettypeLinker;                                                                      // 0x0096C81C
extern D2AnimDataTableStrc* gpAnimData_0096C8A4;                                                            // 0x0096C8A4
extern void* gpExperienceTxt;                                                                               // 0x0096C8A8
extern void* gpDifficultylevelsTxt;                                                                         // 0x0096C8AC

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

// 0x00619140
void __stdcall DATATBLS_UnloadAllBins()
{
    sub_00612EA0_UnloadCompileTxtBins();
    DATATBLS_UnloadBinInline(gpCharstatsTxt);
    DATATBLS_UnloadMissilesTxt();
    DATATBLS_UnloadOverlayTxt();
    DATATBLS_UnloadSkills_SkillDescTxt();
    DATATBLS_UnloadItemStatCostTxt();
    DATATBLS_UnloadStatesTxt();
    DATATBLS_UnloadBinInline(gpPettypeTxt);
    FOG_FreeLinker(gpPettypeLinker);
    DATATBLS_UnloadItemsTxt();
    DATATBLS_UnloadPropertiesTxt();
    DATATBLS_UnloadMagicSuffix_Prefix_AutomagicTxt();
    DATATBLS_UnloadRareSuffix_PrefixTxt();
    DATATBLS_UnloadUniqueItemsTxt();
    DATATBLS_UnloadSets_SetItemsTxt();
    DATATBLS_UnloadQualityItemsTxt();
    DATATBLS_UnloadLowQualityItemsTxt();
    DATATBLS_UnloadGemsTxt();
    DATATBLS_UnloadBooksTxt();
    DATATBLS_UnloadItemRatioTxt();
    DATATBLS_UnloadGambleTxt();
    DATATBLS_UnloadItemTypesTxt();
    sub_006586D0();
    DATATBLS_UnloadPlrMode_Type_MonMode_ObjMode_Type_Composit_ArmtypeTxt();
    DATATBLS_UnloadBinInline(gpExperienceTxt);
    DATATBLS_UnloadAnimDataD2(gpAnimData_0096C8A4);
    DATATBLS_UnloadSomeMonsterTxts();
    DATATBLS_UnloadLevelsTxt();
    DATATBLS_UnloadLevelDefsBin();
    DATATBLS_UnloadLevelTypesTxt();
    DATATBLS_UnloadLvlPrestTxt();
    DATATBLS_UnloadLvlWarpTxt();
    DATATBLS_UnloadLvlMazeTxt();
    DATATBLS_FreeGlobalTileLibraryHash();
    DATATBLS_UnloadLvlSubTxt();
    DATATBLS_FreeAutomap();
    DATATBLS_UnloadObjectsTxt();
    DATATBLS_UnloadObjGroupTxt();
    DATATBLS_UnloadShrinesTxt();
    sub_0065C130();
    DATATBLS_UnloadRunesTxt();
    DATATBLS_FreeCollisionFieldTable();
    DATATBLS_UnloadBeltsTxt();
    DATATBLS_UnloadMonItemPercentTxt();
    DATATBLS_UnloadArenaTxt();
    DATATBLS_UnloadCubeMainTxt();
    DATATBLS_UnloadCharTemplateTxt();
    D2COMMON_10916_Return();
    DATATBLS_UnloadBinInline(gpDifficultylevelsTxt);
}
