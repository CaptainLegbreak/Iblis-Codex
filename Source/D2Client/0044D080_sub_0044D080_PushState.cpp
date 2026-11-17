struct D2CelFileStrc;

#pragma pack(push, 1)
struct D2ConfigStrc
{
    char unk0x000[0x19];
    int dwGameType;
    unsigned short wJoinID;
    char szGameName[0x18];
    char szServerIP[0x18];
    char szBattleNetIP[0x18];
    char szMCPIP[0x18];
    char unk0x07F[6];
    char bAmazon;
    char bPaladin;
    char bSorceress;
    char bNecromancer;
    char bBarbarian;
    char bDruid;
    char bAssassin;
    char unk0x08C[0x1FF - 0x08C];
    int dwAct;
    char unk0x203[0x219 - 0x203];
    char bFlag219;
    char unk0x21A[0x229 - 0x21A];
    int dwValue229;
};

struct D2BetaScreenStrc
{
    unsigned long dwTick;
    D2CelFileStrc* pCelFile;
    unsigned char nAct;
    const char* szName;
};
#pragma pack(pop)

struct D2GfxDataStrc
{
    int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCellFile;
    char unk0x38[0x08];
    int nDirection;
    char unk0x44[0x04];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                     // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);           // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* s1, const char* s2);
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118

extern int gnState_0070EF18;                                                                                // 0x0070EF18
extern D2BetaScreenStrc gtBetaScreens_0070F238[];                                                           // 0x0070F238
extern int gnBetaScreenCount_0070F024;                                                                      // 0x0070F024
unsigned char gnBetaScreenIndex_007A060D;                                                                   // 0x007A060D
extern char gszServerIP_0070EF20[];                                                                         // 0x0070EF20
char gszGameName_007A05DC[20];                                                                              // 0x007A05DC
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
unsigned short gwJoinID_007A0520;                                                                           // 0x007A0520
int gdwGlobal_007A05C0;                                                                                     // 0x007A05C0
extern char gszAddress_0070F028[];                                                                          // 0x0070F028
extern char gszAddress_0070F130[];                                                                          // 0x0070F130
extern unsigned char gbGlobal_007A0522;                                                                     // 0x007A0522

void __fastcall sub_0044B440_PushValue(int nValue);                                                         // 0x0044B440
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);    // 0x004F60F0
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                              // 0x004788B0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
int __fastcall D2Win_10177(unsigned char nAct);                                                             // 0x004FB480
void __cdecl sub_00475EF0_FreeLerpTables();                                                                 // 0x00475EF0
void __cdecl sub_00468170_ShutdownCursor();                                                                 // 0x00468170
void __cdecl sub_00451850();                                                                                // 0x00451850
void __cdecl sub_004794B0_FreeRosterLists();                                                                // 0x004794B0
void __cdecl sub_00478A50_FreeRosterPets();                                                                 // 0x00478A50
void __cdecl sub_00451F20_RegisterWindowHandlers();                                                         // 0x00451F20
void __fastcall sub_00530F30(int nValue);                                                                   // 0x00530F30
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void __stdcall GAME_SetGlobalAct(int nAct);                                                                 // 0x0052DFA0

// 0x0044D080
int __cdecl sub_0044D080_PushState()
{
    if (gnState_0070EF18 == 5)
        sub_0044B440_PushValue(gnState_0070EF18 - 3);
    return gnState_0070EF18;
}

// 0x0044D100
int __stdcall sub_0044D100_ShowBetaScreens(int nArg)
{
    char szPath[0x104];
    D2GfxDataStrc tData;
    if (!WINDOW_GetState())
    {
        if (!D2GFX_StartDraw(1, 0, 0, 0))
            return 0;
        if (gnBetaScreenIndex_007A060D < gnBetaScreenCount_0070F024)
        {
            if (!gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].pCelFile)
            {
                wsprintfA(szPath, "%s\\ui\\betascreens\\%s", szDataGlobal_006D4118, gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].szName);
                gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].pCelFile = sub_004788B0(szPath, 0);
                gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].dwTick = GetTickCount();
                D2Win_10177(gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].nAct);
            }
            memset(&tData, 0, sizeof(tData));
            tData.pCellFile = gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].pCelFile;
            tData.nDirection = 0;
            tData.nFrame = 0;
            TEXTURE_CelDraw(&tData, 0, 0x100, -1, 5, 0);
            tData.nFrame = 1;
            TEXTURE_CelDraw(&tData, 0x100, 0x100, -1, 5, 0);
            tData.nFrame = 2;
            TEXTURE_CelDraw(&tData, 0x200, 0x100, -1, 5, 0);
            tData.nFrame = 3;
            TEXTURE_CelDraw(&tData, 0, 0x1E0, -1, 5, 0);
            tData.nFrame = 4;
            TEXTURE_CelDraw(&tData, 0x100, 0x1E0, -1, 5, 0);
            tData.nFrame = 5;
            TEXTURE_CelDraw(&tData, 0x200, 0x1E0, -1, 5, 0);
        }
        D2GFX_EndScene();
    }
    if (gnBetaScreenIndex_007A060D >= gnBetaScreenCount_0070F024 || GetTickCount() > gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].dwTick + 10000)
    {
        gnBetaScreenIndex_007A060D += 1;
        if (gnBetaScreenIndex_007A060D >= gnBetaScreenCount_0070F024)
        {
            for (int i = 0; i < gnBetaScreenCount_0070F024; i += 1)
            {
                if (gtBetaScreens_0070F238[i].pCelFile)
                {
                    sub_00478A00(gtBetaScreens_0070F238[i].pCelFile);
                    gtBetaScreens_0070F238[i].pCelFile = 0;
                    gtBetaScreens_0070F238[i].dwTick = 0;
                }
            }
            sub_0044B880_SetValue(0);
            return 1;
        }
    }
    return 0;
}

// 0x0044D550
int __cdecl sub_0044D550_Shutdown()
{
    sub_00475EF0_FreeLerpTables();
    sub_00468170_ShutdownCursor();
    sub_00451850();
    sub_004794B0_FreeRosterLists();
    sub_00478A50_FreeRosterPets();
    sub_00451F20_RegisterWindowHandlers();
    return 1;
}

// 0x0044D580
void __fastcall sub_0044D580_ApplyConfig219(D2ConfigStrc* pConfig)
{
    if (pConfig->bFlag219)
        sub_00530F30(0);
}

// 0x0044D5A0
void __fastcall sub_0044D5A0_ApplyConfigAct(D2ConfigStrc* pConfig)
{
    if (pConfig->dwAct)
    {
        D2_ASSERT(pConfig->dwAct < 6, 3366);
        D2_ASSERT(pConfig->dwAct > 0, 3367);
        GAME_SetGlobalAct(pConfig->dwAct - 1);
    }
}

// 0x0044D5F0
void __fastcall sub_0044D5F0_ApplyConfigGame(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szServerIP, "0"))
        SStrCopy(gszServerIP_0070EF20, pConfig->szServerIP, 0x7FFFFFFF);
    SStrCopy(gszGameName_007A05DC, pConfig->szGameName, 0x7FFFFFFF);
    gdwGlobal_007A0610 = pConfig->dwGameType;
    gwJoinID_007A0520 = pConfig->wJoinID;
    gdwGlobal_007A05C0 = pConfig->dwValue229;
}

// 0x0044D650
void __fastcall sub_0044D650_ApplyConfigAddr4F(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szBattleNetIP, "0"))
        SStrCopy(gszAddress_0070F028, pConfig->szServerIP, 0x7FFFFFFF);
}

// 0x0044D680
void __fastcall sub_0044D680_ApplyConfigAddr67(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szMCPIP, "0"))
        SStrCopy(gszAddress_0070F130, pConfig->szMCPIP, 0x7FFFFFFF);
}

// 0x0044D6B0
void __fastcall sub_0044D6B0_ApplyConfigClass(D2ConfigStrc* pConfig)
{
    if (pConfig->bAmazon) gbGlobal_007A0522 = 0;
    if (pConfig->bPaladin) gbGlobal_007A0522 = 3;
    if (pConfig->bSorceress) gbGlobal_007A0522 = 1;
    if (pConfig->bNecromancer) gbGlobal_007A0522 = 2;
    if (pConfig->bBarbarian) gbGlobal_007A0522 = 4;
    if (pConfig->bDruid) gbGlobal_007A0522 = 5;
    if (pConfig->bAssassin) gbGlobal_007A0522 = 6;
}

#include "gen/data/Source/D2Client/0044D080_sub_0044D080_PushState.inc"
