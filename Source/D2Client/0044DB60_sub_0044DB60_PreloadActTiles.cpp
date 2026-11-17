struct Unicode
{
    unsigned short wChar;
};

struct D2TileLibraryHeaderStrc;
struct D2StoredUnitRecordStrc;
struct D2CellFileStrc;
struct D2ActiveRoomStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2LevelsTxt
{
    char unk0x00[0x145];
    char szEntryFile[40];
};

struct D2QuestScreenStrc
{
    char nLevelId[4];
    char nQuest[4];
    char szName[5];
};

struct D2LoadingTimerStrc
{
    unsigned long dwStart;
    unsigned long dwLength;

    D2LoadingTimerStrc() : dwStart(0), dwLength(0)
    {
    }
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh); // 0x006CC2F0
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __stdcall DATATBLS_CheckActInLevelTypesTxt(int nLevelType, unsigned char nAct);                         // 0x0061EAE0
void __stdcall DATATBLS_GetFileNameFromLevelTypeAndFileId(int nLevelType, int nFile, char* szFile);         // 0x0061EB40
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);                    // 0x004795A0
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry);                              // 0x004795C0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                          // 0x00479BC0
int __fastcall sub_00479B80_GetRecordValue(D2StoredUnitRecordStrc* pEntry);                                    // 0x00479B80
int __cdecl sub_0047A980_IsNumberDisplayEnabled();                                                          // 0x0047A980
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);    // 0x004F60F0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190
void __fastcall sub_004FB0D0();                                                                             // 0x004FB0D0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __cdecl sub_0044D3E0_DrawOverlayA();                                                                   // 0x0044D3E0
void __cdecl sub_0044E5A0_DrawOverlayB();                                                                   // 0x0044E5A0
int __fastcall sub_0044D390_GetTextX(int nStringId, int nX);                                                // 0x0044D390
void __fastcall sub_004684C0();                                                                  // 0x004684C0
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __stdcall sub_00600790_LoadTileLibrary(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath);    // 0x00600790
const char* __stdcall D2CMP_GetGfxFileExtension(int bAllowCompressed);                                      // 0x005FE1F0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
D2CellFileStrc* __fastcall sub_004788B0_LoadCellFile(const char* szPath, int nType);                        // 0x004788B0
void __stdcall sub_004FB500(const char* szPalette, const char* szPl2);                          // 0x004FB500
void __fastcall sub_004547B0();                                                                             // 0x004547B0
int __cdecl sub_00525150();                                                                         // 0x00525150
void __fastcall sub_00478130_SetScale(int nValue, int nDivisor);                                            // 0x00478130
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __fastcall sub_00492F40_SetFade(int nMode);                                                            // 0x00492F40
int __fastcall sub_0044DFF0_TimerExpired(D2LoadingTimerStrc* pTimer);                                       // 0x0044DFF0
void __fastcall sub_00502680_DrawCellFile(D2CellFileStrc* pCell, int nX, int nY, int nA, int nB, int nC);  // 0x00502680

extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern int gnLineHeight_007111C8;                                                                           // 0x007111C8
extern int gdwGlobal_007A04F4;                                                                              // 0x007A04F4
int gdwGlobal_007A0680;                                                                                     // 0x007A0680
int gdwGlobal_007A0608;                                                                                     // 0x007A0608
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gszDataLocal_006D41A8[];                                                              // 0x006D41A8
extern D2QuestScreenStrc gtQuestScreens_0070F85C[];                                                         // 0x0070F85C
extern int gnQuestScreens_0070F92C;                                                                         // 0x0070F92C
D2CellFileStrc* gpLoadingCell_007A2794;                                                                     // 0x007A2794
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
D2CellFileStrc* gpBuySellButton_007A287C;                                                                   // 0x007A287C
extern D2CellFileStrc* gpLoadingScreen_007A2888;                                                            // 0x007A2888
extern int gnLoadingFrame_007A2A6C;                                                                         // 0x007A2A6C
extern int gdwGlobal_007A2868;                                                                              // 0x007A2868
extern int gnValue_007A27B8;                                                                                // 0x007A27B8
extern int gnValue_007A0624;                                                                                // 0x007A0624

static D2CellFileStrc* s_pEndGameCell_007A0700;                                                             // 0x007A0700
static D2CellFileStrc* s_pEndGameOkCell_007A06FC;                                                           // 0x007A06FC

// build: symbol ?$S1@?7??sub_00455510_DrawLevelLoadingScreen@@YAXXZ@4IA 0x007A314C
// 0x0044DB60
void __stdcall sub_0044DB60_PreloadActTiles(unsigned char nAct)
{
    char szFile[60];
    ++nAct;
    for (int nLevelType = 0; nLevelType < 36; ++nLevelType)
    {
        if (DATATBLS_CheckActInLevelTypesTxt(nLevelType, nAct))
        {
            for (int nFile = 0; nFile < 32; ++nFile)
            {
                DATATBLS_GetFileNameFromLevelTypeAndFileId(nLevelType, nFile, szFile);
                if (szFile[0] != '0' && szFile[0])
                {
                    D2TileLibraryHeaderStrc* pLibrary;
                    sub_00600790_LoadTileLibrary(&pLibrary, szFile);
                }
            }
        }
    }

    {
        D2TileLibraryHeaderStrc* pLibrary;
        sub_00600790_LoadTileLibrary(&pLibrary, "data\\global\\tiles\\act1\\barracks\\warp.dt1");
        sub_00600790_LoadTileLibrary(&pLibrary, "data\\global\\tiles\\act1\\outdoors\\blank.dt1");
    }
}

// 0x0044E770
int __stdcall sub_0044E770_DrawEndGameScreen(int nUnused)
{
    D2CelContextStrc tContext;
    char szName[0x104];
    char szPalette[0x104];
    char szPath[0x104];
    char szPl2[0x104];
    if (!WINDOW_GetState())
    {
        if (D2GFX_StartDraw(1, 0, 0, 0))
        {
            if (!s_pEndGameCell_007A0700)
            {
                if (!gdwGlobal_007A04F4)
                {
                    strcpy(szName, "endgame");
                }
                else
                {
                    strcpy(szName, "endgame2");
                }
                sprintf(szPath, "%s\\ui\\menu\\%s", szDataGlobal_006D4118, szName);
                s_pEndGameCell_007A0700 = sub_004788B0_LoadCellFile(szPath, 0);
                sprintf(szPalette, "%s\\Palette\\%s\\pal.dat", szDataGlobal_006D4118, szName);
                sprintf(szPl2, "%s\\Palette\\%s\\pal.pl2", szDataGlobal_006D4118, szName);
                sub_004FB500(szPalette, szPl2);
            }

            if (!s_pEndGameOkCell_007A06FC)
            {
                sprintf(szPalette, "%s\\ui\\menu\\endgameok", szDataGlobal_006D4118);
                s_pEndGameOkCell_007A06FC = sub_004788B0_LoadCellFile(szPalette, 0);
            }

            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = s_pEndGameCell_007A0700;
            tContext.unk0x40 = 0;
            sub_004FB0D0();
            if (!gdwGlobal_007A04F4)
            {
                tContext.nFrame = 0;
                sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
                tContext.nFrame = 1;
                sub_004F6480(&tContext, 0x100, 0x100, -1, 5, 0);
                tContext.nFrame = 2;
                sub_004F6480(&tContext, 0, gnGlobal_00711470 - 1, -1, 5, 0);
                tContext.nFrame = 3;
                sub_004F6480(&tContext, 0x100, gnGlobal_00711470 - 1, -1, 5, 0);
                tContext.nFrame = 4;
                sub_004F6480(&tContext, gnGlobal_0071146C / 2, 0x100, -1, 5, 0);
                tContext.nFrame = 5;
                sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x100, 0x100, -1, 5, 0);
                tContext.nFrame = 6;
                sub_004F6480(&tContext, gnGlobal_0071146C / 2, gnGlobal_00711470, -1, 5, 0);
                tContext.nFrame = 7;
                sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x100, gnGlobal_00711470, -1, 5, 0);
            }
            else
            {
                tContext.nFrame = 0;
                sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
                tContext.nFrame = 1;
                sub_004F6480(&tContext, 0x100, 0x100, -1, 5, 0);
                tContext.nFrame = 2;
                sub_004F6480(&tContext, 0x200, 0x100, -1, 5, 0);
                tContext.nFrame = 3;
                sub_004F6480(&tContext, 0x300, 0x100, -1, 5, 0);
                tContext.nFrame = 4;
                sub_004F6480(&tContext, 0, 0x200, -1, 5, 0);
                tContext.nFrame = 5;
                sub_004F6480(&tContext, 0x100, 0x200, -1, 5, 0);
                tContext.nFrame = 6;
                sub_004F6480(&tContext, 0x200, 0x200, -1, 5, 0);
                tContext.nFrame = 7;
                sub_004F6480(&tContext, 0x300, 0x200, -1, 5, 0);
                tContext.nFrame = 8;
                sub_004F6480(&tContext, 0, 0x258, -1, 5, 0);
                tContext.nFrame = 9;
                sub_004F6480(&tContext, 0x100, 0x258, -1, 5, 0);
                tContext.nFrame = 10;
                sub_004F6480(&tContext, 0x200, 0x258, -1, 5, 0);
                tContext.nFrame = 11;
                sub_004F6480(&tContext, 0x300, 0x258, -1, 5, 0);
            }

            sub_00502EF0(3);
            sub_0044D3E0_DrawOverlayA();
            sub_0044E5A0_DrawOverlayB();
            sub_00502EF0(1);
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = s_pEndGameOkCell_007A06FC;
            tContext.unk0x40 = 0;
            tContext.nFrame = gdwGlobal_007A0680 != 0;
            sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x30, gnGlobal_00711470 - 0x50, -1, 5, 0);
            const int nX = sub_0044D390_GetTextX(0x13EE, gnGlobal_0071146C / 2);
            int nOffset = 0;
            if (gdwGlobal_007A0680)
            {
                nOffset = 2;
            }
            sub_00502320(D2LANG_GetStringFromTblIndex(0x13EE), nX - nOffset, gnGlobal_00711470 + nOffset - 0x58, 0, 0);
            sub_004684C0();
            D2GFX_EndScene();
        }
        else
        {
            return 0;
        }
    }

    if (!gdwGlobal_007A0608)
    {
        return 0;
    }

    if (s_pEndGameCell_007A0700)
    {
        sub_00478A00(s_pEndGameCell_007A0700);
        s_pEndGameCell_007A0700 = 0;
    }
    if (s_pEndGameOkCell_007A06FC)
    {
        sub_00478A00(s_pEndGameOkCell_007A06FC);
        s_pEndGameOkCell_007A06FC = 0;
    }
    sub_0044B880_SetValue(0);
    return 1;
}

// 0x00453BB0
void __cdecl sub_00453BB0_DrawEntryList()
{
    sub_0046EFD0_DrawFramedBox(0x78, 0x1E, 0x190, 0x15E, 0, 0);
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    sub_00502320(D2LANG_GetStringFromTblIndex(0xFA4), 0x96, 0x37, 4, 0);
    int nY = 2 * gnLineHeight_007111C8 + 0x1E;
    while (pEntry)
    {
        const char* szName = sub_004795C0_GetEntryName(pEntry);
        Unicode wszName[16] = {};
        sub_00526F20_ToUnicode(wszName, szName, 16);
        const int nRowY = nY + 0x19;
        wszName[15].wChar = 0;
        sub_00502320(wszName, 0x96, nRowY, 0, 0);

        Unicode wszLine[20] = {};
        const Unicode* pText;
        if (sub_00479BC0_GetEntryIndex(pEntry) == 0xFFFF)
        {
            pText = D2LANG_GetStringFromTblIndex(0xFAF);
        }
        else
        {
            Unicode wszNumber[3];
            char szNumber[20];
            wszNumber[0].wChar = 0;
            wszNumber[1].wChar = 0;
            wszNumber[2].wChar = 0;
            wsprintfA(szNumber, gszFormatD_006D57BC, sub_00479BC0_GetEntryIndex(pEntry));
            sub_00526F20_ToUnicode(wszNumber, szNumber, 2);
            sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xFB0));
            sub_00526700(wszLine, wszNumber);
            wszLine[19].wChar = 0;
            pText = wszLine;
        }
        sub_00502320(pText, 0x140, nRowY, 0, 0);

        if (sub_0047A980_IsNumberDisplayEnabled())
        {
            Unicode wszValue[12] = {};
            char szValue[12];
            wsprintfA(szValue, gszFormatD_006D57BC, sub_00479B80_GetRecordValue(pEntry));
            sub_00526F20_ToUnicode(wszValue, szValue, 12);
            sub_00502320(wszValue, 0x82, nRowY, 4, 0);
        }

        pEntry = sub_004795A0_GetNextEntry(pEntry);
        nY += gnLineHeight_007111C8;
        if (nY > 0x145 - gnLineHeight_007111C8)
        {
            break;
        }
    }
}

// 0x00454600
D2CellFileStrc* __cdecl sub_00454600_GetBuySellButtonCells()
{
    if (!gpBuySellButton_007A287C)
    {
        char szPath[0x104];
        wsprintfA(szPath, "%s\\ui\\panel\\buysellbtn", szDataGlobal_006D4118);
        gpBuySellButton_007A287C = sub_004788B0_LoadCellFile(szPath, 0);
    }
    return gpBuySellButton_007A287C;
}

// 0x00454650
void* __fastcall sub_00454650_ReadWholeFile(const char* szName, unsigned long* pSize)
{
    unsigned long nRead;
    char szPath[0x104];
    strcpy(szPath, szName);
    strcat(szPath, D2CMP_GetGfxFileExtension(0));
    void* hFile = CreateFileA(szName, 0x80000000, 0, 0, 3, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return 0;
    }

    *pSize = GetFileSize(hFile, 0);
    void* pBuffer = FOG_Alloc(*pSize, ".\\UI\\ui.cpp", 0x18AD, 0);
    memset(pBuffer, 0, *pSize);
    ReadFile(hFile, pBuffer, *pSize, &nRead, 0);
    CloseHandle(hFile);
    return pBuffer;
}

// 0x00454740
void __cdecl sub_00454740_LoadLoadingPalette()
{
    char szPl2[0x104];
    char szPalette[0x104];
    sprintf(szPalette, "%s\\Palette\\Loading\\pal.dat", szDataGlobal_006D4118);
    sprintf(szPl2, "%s\\Palette\\Loading\\pal.pl2", szDataGlobal_006D4118);
    sub_004FB500(szPalette, szPl2);
}

// 0x00455510
void __cdecl sub_00455510_DrawLevelLoadingScreen()
{
    char szLanguage[4];
    char szAct[32];
    char szPath[0x104];
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
    {
        if (gpLoadingCell_007A2794)
        {
            sub_00478A00(gpLoadingCell_007A2794);
            gpLoadingCell_007A2794 = 0;
        }
        return;
    }

    static D2LoadingTimerStrc s_tTimer; // 0x007A3144
    static int s_nLastLevelId; // 0x007A3140
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId != s_nLastLevelId)
    {
        sub_00492F40_SetFade(1);
        if (gpLoadingCell_007A2794)
        {
            sub_00478A00(gpLoadingCell_007A2794);
            gpLoadingCell_007A2794 = 0;
        }

        if (!s_nLastLevelId)
        {
            s_tTimer.dwStart = 0;
            s_tTimer.dwLength = 0;
        }
        else
        {
            s_tTimer.dwStart = GetTickCount();
            s_tTimer.dwLength = 2000;
        }
        s_nLastLevelId = nLevelId;
    }

    if (sub_0044DFF0_TimerExpired(&s_tTimer))
    {
        if (gpLoadingCell_007A2794)
        {
            sub_00478A00(gpLoadingCell_007A2794);
            gpLoadingCell_007A2794 = 0;
        }
        return;
    }

    D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (nLevelId >= 109)
    {
        strcpy(szAct, "EXPANSION");
    }
    else
    {
        sprintf(szAct, "ACT%d", DRLG_GetActNoFromLevelId(nLevelId) + 1);
    }
    sub_00525260(szLanguage, 0);
    sprintf(szPath, "%s\\UI\\%s\\%s\\%s", gszDataLocal_006D41A8, szLanguage, szAct, pLevelsTxt->szEntryFile);
    for (int i = 0; i < gnQuestScreens_0070F92C; ++i)
    {
        if (nLevelId == *(int*)gtQuestScreens_0070F85C[i].nLevelId && sub_004B92E0_GetTableByte(0, *(int*)gtQuestScreens_0070F85C[i].nQuest))
        {
            sprintf(szPath, "%s\\UI\\%s\\ACT1\\%s", gszDataLocal_006D41A8, szLanguage, gtQuestScreens_0070F85C[i].szName);
            break;
        }
    }

    if (!gpLoadingCell_007A2794)
    {
        gpLoadingCell_007A2794 = sub_004788B0_LoadCellFile(szPath, 0);
    }
    sub_00502680_DrawCellFile(gpLoadingCell_007A2794, gnGlobal_0071146C / 2, gnGlobal_00711470 / 2 - 140, 1, 5, 1);
}

// 0x00456550
void __cdecl sub_00456550_LoadLoadingScreen()
{
    char szPath[0x104];
    sub_004547B0();
    sub_00454740_LoadLoadingPalette();
    if (sub_00525150())
    {
        sprintf(szPath, "%s\\UI\\LoadingScreen", gszDataLocal_006D41A8);
    }
    else
    {
        sprintf(szPath, "%s\\UI\\Loading\\Loadingscreen", szDataGlobal_006D4118);
    }
    gpLoadingScreen_007A2888 = sub_004788B0_LoadCellFile(szPath, 0);
    gnLoadingFrame_007A2A6C = 0;
    gdwGlobal_007A2868 = 1;
    sub_00478130_SetScale(0, 0);
    gnValue_007A27B8 = gnValue_007A0624;
}

#include "gen/data/Source/D2Client/0044DB60_sub_0044DB60_PreloadActTiles.inc"
