struct D2TokRecord { char unk[0x34]; };
struct D2PlrModeDataTbl { unsigned int nPlrModeTypeTxtRecordCount; void* pPlrModeTypeTxt; D2TokRecord* pPlayerType; D2TokRecord* pPlayerMode; };
struct D2MonModeDataTbl { unsigned int nMonModeTxtRecordCount; void* pMonModeTxt; D2TokRecord* pMonMode[2]; };
struct D2ObjModeDataTbl { unsigned int nObjModeTypeTxtRecordCount; void* pObjModeTypeTxt; D2TokRecord* pObjType; D2TokRecord* pObjMode; };

extern D2MonModeDataTbl gMonModeDataTables;                                                                 // 0x0096D4B8
extern D2ObjModeDataTbl gObjModeDataTables;                                                                 // 0x0096D4C8
D2PlrModeDataTbl gPlrModeDataTables;                                                                        // 0x0096D4D8
D2TokRecord* gpArmTypeTxt;                                                                                  // 0x0096D4E8
D2TokRecord* gpCompositTxt;                                                                                 // 0x0096D4EC
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TOK_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0065B3C0
void __fastcall DATATBLS_UnloadPlrMode_Type_MonMode_ObjMode_Type_Composit_ArmtypeTxt()
{
    if (gPlrModeDataTables.pPlrModeTypeTxt)
    {
        sub_0040B480(0, gPlrModeDataTables.pPlrModeTypeTxt, ".\\DATATBLS\\TokTbls.cpp", 214, 0);
    }
    gPlrModeDataTables.pPlrModeTypeTxt = 0;

    if (gMonModeDataTables.pMonModeTxt)
    {
        DATATBLS_UnloadBin(gMonModeDataTables.pMonModeTxt);
    }
    gMonModeDataTables.pMonModeTxt = 0;

    if (gObjModeDataTables.pObjModeTypeTxt)
    {
        sub_0040B480(0, gObjModeDataTables.pObjModeTypeTxt, ".\\DATATBLS\\TokTbls.cpp", 226, 0);
    }
    gObjModeDataTables.pObjModeTypeTxt = 0;

    if (gpCompositTxt)
    {
        DATATBLS_UnloadBin(gpCompositTxt);
    }
    gpCompositTxt = 0;

    if (gpArmTypeTxt)
    {
        DATATBLS_UnloadBin(gpArmTypeTxt);
    }
    gpArmTypeTxt = 0;
}

// 0x0065B450
D2PlrModeDataTbl* __fastcall DATATBLS_GetPlrMode_TypeDataTables()
{
    return &gPlrModeDataTables;
}

// 0x0065B460
D2MonModeDataTbl* __fastcall DATATBLS_GetMonModeDataTables()
{
    return &gMonModeDataTables;
}

// 0x0065B470
D2ObjModeDataTbl* __fastcall DATATBLS_GetObjMode_TypeDataTables()
{
    return &gObjModeDataTables;
}

// 0x0065B480
D2TokRecord* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(unsigned int nIndex, int bGetMode)
{
    if (nIndex >= gPlrModeDataTables.nPlrModeTypeTxtRecordCount)
    {
        return 0;
    }

    TOK_ASSERT(gPlrModeDataTables.pPlrModeTypeTxt, 272);

    switch (bGetMode)
    {
    case 0:
        TOK_ASSERT(&gPlrModeDataTables.pPlayerType[nIndex], 275);
        return &gPlrModeDataTables.pPlayerType[nIndex];

    case 1:
        TOK_ASSERT(&gPlrModeDataTables.pPlayerMode[nIndex], 278);
        return &gPlrModeDataTables.pPlayerMode[nIndex];

    default:
        return 0;
    }
}

// 0x0065B500
D2TokRecord* __stdcall DATATBLS_GetMonModeTxtRecord(unsigned int nIndex, int bGetMode)
{
    if (nIndex >= gMonModeDataTables.nMonModeTxtRecordCount)
    {
        return 0;
    }

    switch (bGetMode)
    {
    case 0:
        TOK_ASSERT(&gMonModeDataTables.pMonMode[0][nIndex], 294);
        return &gMonModeDataTables.pMonMode[0][nIndex];

    case 1:
        TOK_ASSERT(&gMonModeDataTables.pMonMode[1][nIndex], 297);
        return &gMonModeDataTables.pMonMode[1][nIndex];

    default:
        return 0;
    }
}

// 0x0065B570
D2TokRecord* __stdcall DATATBLS_GetObjModeTypeTxtRecord(unsigned int nIndex, int bGetMode)
{
    if (nIndex >= gObjModeDataTables.nObjModeTypeTxtRecordCount)
    {
        return 0;
    }

    switch (bGetMode)
    {
    case 0:
        TOK_ASSERT(&gObjModeDataTables.pObjType[nIndex], 313);
        return &gObjModeDataTables.pObjType[nIndex];

    case 1:
        TOK_ASSERT(&gObjModeDataTables.pObjMode[nIndex], 316);
        return &gObjModeDataTables.pObjMode[nIndex];

    default:
        return 0;
    }
}

// 0x0065B5E0
D2TokRecord* __stdcall DATATBLS_GetCompositTxtRecord(int nComposit)
{
    TOK_ASSERT(&gpCompositTxt[nComposit], 327);

    return &gpCompositTxt[nComposit];
}

// 0x0065B620
D2TokRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(int nId)
{
    TOK_ASSERT(&gpArmTypeTxt[nId], 336);
    return &gpArmTypeTxt[nId];
}
