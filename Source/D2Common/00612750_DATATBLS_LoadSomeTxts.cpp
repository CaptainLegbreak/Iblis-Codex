struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2DataTablesStrc
{
    void* pPlayerClassTxt;
    D2TxtLinkStrc* pPlayerClassLinker;
    void* pBodyLocsTxt;
    D2TxtLinkStrc* pBodyLocsLinker;
    void* pStorePageTxt;
    D2TxtLinkStrc* pStorePageLinker;
    void* pElemTypesTxt;
    D2TxtLinkStrc* pElemTypesLinker;
    void* pHitClassTxt;
    D2TxtLinkStrc* pHitClassLinker;
    void* pMonModeTxtStub;
    D2TxtLinkStrc* pMonModeLinker;
    void* pPlrModeTxtStub;
    D2TxtLinkStrc* pPlrModeLinker;
    void* pSkillCalcTxt;
    D2TxtLinkStrc* pSkillCalcLinker;
    char unk0x040[0x018];
    void* pMissileCalcTxt;
    D2TxtLinkStrc* pMissileCalcLinker;
    char unk0x060[0x00C];
    void* pSkillCode;
    D2TxtLinkStrc* iSkillCode;
    void* pEventsTxt;
    D2TxtLinkStrc* pEventsLinker;
    void* pCompCodeTxt;
    D2TxtLinkStrc* pCompCodeLinker;
    int nCompCodeTxtRecordCount;
    void* pMonAiTxt;
    D2TxtLinkStrc* pMonAiLinker;
    int nMonAiTxtRecordCount;
    char unk0x094[0x020];
    void* pHireDescTxt;
    D2TxtLinkStrc* pHireDescLinker;
    char unk0x0BC[0x8F4];
    void* pColorsTxt;
    D2TxtLinkStrc* pColorsLinker;
    char unk0x9B8[0x0E4];
    void* pMonPlaceTxt;
    D2TxtLinkStrc* pMonPlaceLinker;
    int nMonPlaceTxtRecordCount;
    char unk0xAA8[0x1CC];
    void* pAnimData;
    char unk0xC78[0x00C];
    int bCompileTxt;
};

extern "C" const char gszTxtField_code[];                                                                   // 0x006DCCE0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern "C" const char gszHitclassTxtName[];                                                                 // 0x006DCF50
extern D2DataTablesStrc gD2DataTables;                                                                      // 0x0096BC30
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void __fastcall DATATBLS_LoadItemTypesTxt(void* hArchive);                                                  // 0x00638D80
void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive);                                                    // 0x00658520
void __fastcall DATATBLS_LoadSoundsTxt(void* hArchive);                                                     // 0x00659BB0
void __fastcall DATATBLS_LoadPetTypeTxt(void* hArchive);                                                    // 0x00618D90
void __fastcall DATATBLS_LoadOverlayTxt(void* hArchive);                                                    // 0x00664150
void __fastcall DATATBLS_LoadItemStatCostTxt(void* hArchive);                                               // 0x00637A00
void __fastcall DATATBLS_LoadPropertiesTxt(void* hArchive);                                                 // 0x00638630
void __fastcall DATATBLS_LoadMissilesTxt(void* hArchive);                                                   // 0x00661B20
void __fastcall DATATBLS_LoadStatesTxt(void* hArchive);                                                     // 0x00618100
void __stdcall DATATBLS_LoadSkills_SkillDescTxt(void* hArchive);                                            // 0x00613F80
void __stdcall DATATBLS_LoadCharStatsTxt(void* hArchive);                                                   // 0x00613260
void __fastcall DATATBLS_LoadArenaTxt(void* hArchive);                                                      // 0x006649B0
void __fastcall DATATBLS_LoadCharTemplateTxt(void* hArchive);                                               // 0x00664B80
void __fastcall DATATBLS_LoadItemsTxt(void* hArchive);                                                      // 0x006315D0
void __fastcall DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(void* hArchive);                               // 0x00633730
void __fastcall DATATBLS_LoadRareSuffix_PrefixTxt(void* hArchive);                                          // 0x00633F40
void __fastcall DATATBLS_LoadUniqueItemsTxt(void* hArchive);                                                // 0x006342B0
void __fastcall DATATBLS_LoadSets_SetItemsTxt(void* hArchive);                                              // 0x00634DC0
void __fastcall DATATBLS_LoadGemsTxt(void* hArchive);                                                       // 0x00636B70
void __fastcall DATATBLS_LoadBooksTxt(void* hArchive);                                                      // 0x00637320
void __fastcall DATATBLS_LoadQualityItemsTxt(void* hArchive);                                               // 0x00636770
void __fastcall DATATBLS_LoadLowQualityItemsTxt(void* hArchive);                                            // 0x00637500
void __fastcall DATATBLS_LoadRunesTxt(void* hArchive);                                                      // 0x006394A0
void __fastcall DATATBLS_LoadItemRatioTxt(void* hArchive);                                                  // 0x00637620
void __fastcall DATATBLS_LoadGambleTxt(void* hArchive);                                                     // 0x00638AE0
void __fastcall DATATBLS_LoadPlrType_ModeTxt(void* hArchive);                                               // 0x0065ADC0
void __fastcall DATATBLS_LoadMonModeTxt(void* hArchive);                                                    // 0x0065AEF0
void __fastcall DATATBLS_LoadObjType_ModeTxt(void* hArchive);                                               // 0x0065B1B0
void __fastcall DATATBLS_LoadCompositTxt(void* hArchive);                                                   // 0x0065B2E0
void __fastcall DATATBLS_LoadArmTypeTxt(void* hArchive);                                                    // 0x0065B350
void __stdcall sub_00613D30(void* hArchive);                                                  // 0x00613D30
void* __fastcall DATATBLS_LoadAnimDataD2(void* hArchive);                                                   // 0x0066A770
void __fastcall DATATBLS_LoadSomeMonsterTxts(void* hArchive);                                               // 0x0065A400
void __fastcall DATATBLS_LoadLevelsTxt(void* hArchive);                                                     // 0x0061C540
void __fastcall DATATBLS_LoadLevelDefsBin(void* hArchive);                                                  // 0x0061DE00
void __fastcall sub_0061E520(void* hArchive);                                                   // 0x0061E520
void __fastcall DATATBLS_AllocGlobalTileLibraryHash(void* hArchive);                                        // 0x0061FAE0
void __fastcall DATATBLS_LoadLvlWarpTxt(void* hArchive);                                                    // 0x0061F130
void __fastcall DATATBLS_LoadLvlMazeTxt(void* hArchive);                                                    // 0x0061F380
void __fastcall DATATBLS_LoadAutomapTxt(void* hArchive);                                                    // 0x0061FCF0
void __fastcall DATATBLS_LoadObjectsTxt(void* hArchive);                                                    // 0x0063F690
void __fastcall DATATBLS_LoadObjGroupTxt(void* hArchive);                                                   // 0x00640F20
void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive);                                                    // 0x00641320
void __fastcall DATATBLS_LoadInventoryTxt(void* hArchive);                                                  // 0x0065B660
int __fastcall DATATBLS_LoadExpFieldD2(void* hArchive);                                                     // 0x0066A700
void __fastcall DATATBLS_LoadBeltsTxt(void* hArchive);                                                      // 0x00660290
void __fastcall DATATBLS_LoadMonItemPercentTxt(void* hArchive);                                             // 0x00654F20
void __fastcall sub_0066A270(void* hArchive);                                                // 0x0066A270
void __fastcall DATATBLS_LoadCubeMainTxt(void* hArchive);                                                   // 0x00669130
void __stdcall DATATBLS_LoadDifficultyLevelsTxt(void* hArchive);                                            // 0x00617D90
void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles);                                   // 0x0061EBB0
void __fastcall DATATBLS_LoadLvlSubTxt(void* hArchive, int a2, int a3);                                     // 0x0061F500
void __fastcall sub_00659C30();                                                           // 0x00659C30

// 0x00612750
static void DATATBLS_LoadSomeTxts(void* hArchive)
{
    int nRecordCount;

    D2BinFieldStrc pCompCodeTbl[] =
    {
        { gszTxtField_code, 10, 0, 0, &gD2DataTables.pCompCodeLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    gD2DataTables.pCompCodeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 115);
    gD2DataTables.pCompCodeTxt = DATATBLS_CompileTxt(hArchive, "compcode", pCompCodeTbl, &gD2DataTables.nCompCodeTxtRecordCount, 4);

    if (gD2DataTables.bCompileTxt)
    {
        D2BinFieldStrc pPlayerClassTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pPlayerClassLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pPlayerClassLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 132);
        gD2DataTables.pPlayerClassTxt = DATATBLS_CompileTxt(hArchive, "playerclass", pPlayerClassTbl, &nRecordCount, 4);

        D2BinFieldStrc pBodyLocsTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pBodyLocsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pBodyLocsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 144);
        gD2DataTables.pBodyLocsTxt = DATATBLS_CompileTxt(hArchive, "bodylocs", pBodyLocsTbl, &nRecordCount, 4);

        D2BinFieldStrc pStorePageTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pStorePageLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pStorePageLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 156);
        gD2DataTables.pStorePageTxt = DATATBLS_CompileTxt(hArchive, "storepage", pStorePageTbl, &nRecordCount, 4);

        D2BinFieldStrc pElemTypesTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pElemTypesLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pElemTypesLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 168);
        gD2DataTables.pElemTypesTxt = DATATBLS_CompileTxt(hArchive, "elemtypes", pElemTypesTbl, &nRecordCount, 4);

        D2BinFieldStrc pHitClassTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pHitClassLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pHitClassLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 184);
        gD2DataTables.pHitClassTxt = DATATBLS_CompileTxt(hArchive, gszHitclassTxtName, pHitClassTbl, &nRecordCount, 4);

        D2BinFieldStrc pColorsTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pColorsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pColorsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 196);
        gD2DataTables.pColorsTxt = DATATBLS_CompileTxt(hArchive, "colors", pColorsTbl, &nRecordCount, 4);

        D2BinFieldStrc pHireDescTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pHireDescLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pHireDescLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 208);
        gD2DataTables.pHireDescTxt = DATATBLS_CompileTxt(hArchive, "hiredesc", pHireDescTbl, &nRecordCount, 4);

        D2BinFieldStrc pMonModeTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pMonModeLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonModeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 220);
        gD2DataTables.pMonModeTxtStub = DATATBLS_CompileTxt(hArchive, "monmode", pMonModeTbl, &nRecordCount, 4);

        D2BinFieldStrc pPlrModeTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pPlrModeLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pPlrModeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 232);
        gD2DataTables.pPlrModeTxtStub = DATATBLS_CompileTxt(hArchive, "plrmode", pPlrModeTbl, &nRecordCount, 4);

        D2BinFieldStrc pMonAiTbl[] =
        {
            { "AI", 17, 0, 0, &gD2DataTables.pMonAiLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonAiLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 244);
        gD2DataTables.pMonAiTxt = DATATBLS_CompileTxt(hArchive, "monai", pMonAiTbl, &gD2DataTables.nMonAiTxtRecordCount, 2);

        D2BinFieldStrc pMonPlaceTbl[] =
        {
            { gszTxtField_code, 17, 0, 0, &gD2DataTables.pMonPlaceLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonPlaceLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 256);
        gD2DataTables.pMonPlaceTxt = DATATBLS_CompileTxt(hArchive, "monplace", pMonPlaceTbl, &gD2DataTables.nMonPlaceTxtRecordCount, 2);

        D2BinFieldStrc pSkillCalcTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pSkillCalcLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pSkillCalcLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 268);
        gD2DataTables.pSkillCalcTxt = DATATBLS_CompileTxt(hArchive, "skillcalc", pSkillCalcTbl, &nRecordCount, 4);

        D2BinFieldStrc pMissileCalcTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pMissileCalcLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMissileCalcLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 280);
        gD2DataTables.pMissileCalcTxt = DATATBLS_CompileTxt(hArchive, "misscalc", pMissileCalcTbl, &nRecordCount, 4);

        D2BinFieldStrc pSkillCodeTbl[] =
        {
            { "skill", 17, 0, 0, &gD2DataTables.iSkillCode },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.iSkillCode = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 291);
        gD2DataTables.pSkillCode = DATATBLS_CompileTxt(hArchive, "skills", pSkillCodeTbl, &nRecordCount, 2);

        D2BinFieldStrc pEventsTbl[] =
        {
            { "event", 17, 0, 0, &gD2DataTables.pEventsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pEventsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 303);
        gD2DataTables.pEventsTxt = DATATBLS_CompileTxt(hArchive, "events", pEventsTbl, &nRecordCount, 2);
    }
}

// 0x00619300
void __stdcall DATATBLS_LoadAllTxts(void* hArchive, int a2, int a3)
{
    DATATBLS_LoadSomeTxts(hArchive);
    DATATBLS_LoadItemTypesTxt(hArchive);
    DATATBLS_LoadMonTypeTxt(hArchive);
    DATATBLS_LoadSoundsTxt(hArchive);
    DATATBLS_LoadPetTypeTxt(hArchive);
    DATATBLS_LoadOverlayTxt(hArchive);
    DATATBLS_LoadItemStatCostTxt(hArchive);
    DATATBLS_LoadPropertiesTxt(hArchive);
    DATATBLS_LoadMissilesTxt(hArchive);
    DATATBLS_LoadStatesTxt(hArchive);
    DATATBLS_LoadSkills_SkillDescTxt(hArchive);
    DATATBLS_LoadCharStatsTxt(hArchive);
    DATATBLS_LoadArenaTxt(hArchive);
    DATATBLS_LoadCharTemplateTxt(hArchive);
    DATATBLS_LoadItemsTxt(hArchive);
    DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(hArchive);
    DATATBLS_LoadRareSuffix_PrefixTxt(hArchive);
    DATATBLS_LoadUniqueItemsTxt(hArchive);
    DATATBLS_LoadSets_SetItemsTxt(hArchive);
    DATATBLS_LoadGemsTxt(hArchive);
    DATATBLS_LoadBooksTxt(hArchive);
    DATATBLS_LoadQualityItemsTxt(hArchive);
    DATATBLS_LoadLowQualityItemsTxt(hArchive);
    DATATBLS_LoadRunesTxt(hArchive);
    DATATBLS_LoadItemRatioTxt(hArchive);
    DATATBLS_LoadGambleTxt(hArchive);
    DATATBLS_LoadPlrType_ModeTxt(hArchive);
    DATATBLS_LoadMonModeTxt(hArchive);
    DATATBLS_LoadObjType_ModeTxt(hArchive);
    DATATBLS_LoadCompositTxt(hArchive);
    DATATBLS_LoadArmTypeTxt(hArchive);
    sub_00613D30(hArchive);
    gD2DataTables.pAnimData = DATATBLS_LoadAnimDataD2(hArchive);
    DATATBLS_LoadSomeMonsterTxts(hArchive);
    DATATBLS_LoadLevelsTxt(hArchive);
    DATATBLS_LoadLevelDefsBin(hArchive);
    sub_0061E520(hArchive);
    if (a2)
    {
        DATATBLS_AllocGlobalTileLibraryHash(hArchive);
    }
    DATATBLS_LoadLvlPrestTxt(hArchive, a2);
    DATATBLS_LoadLvlWarpTxt(hArchive);
    DATATBLS_LoadLvlMazeTxt(hArchive);
    DATATBLS_LoadLvlSubTxt(hArchive, a2, a3);
    DATATBLS_LoadAutomapTxt(hArchive);
    DATATBLS_LoadObjectsTxt(hArchive);
    DATATBLS_LoadObjGroupTxt(hArchive);
    DATATBLS_LoadShrinesTxt(hArchive);
    DATATBLS_LoadInventoryTxt(hArchive);
    DATATBLS_LoadExpFieldD2(hArchive);
    DATATBLS_LoadBeltsTxt(hArchive);
    DATATBLS_LoadMonItemPercentTxt(hArchive);
    sub_0066A270(hArchive);
    DATATBLS_LoadCubeMainTxt(hArchive);
    DATATBLS_LoadDifficultyLevelsTxt(hArchive);
    sub_00659C30();
}
