#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct _RTL_CRITICAL_SECTION;
struct D2BetaScreenStrc;
struct Unicode;
struct D2ClientConfigStrc;

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
    unsigned char unk_8C[0x31];
    char szName[0x18];
    char szRealm[0x18];
    unsigned char unk_ED[0x112];
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl strcmp(const char* s1, const char* s2);
extern int gnState_0070EF18; // 0x0070EF18
extern D2BetaScreenStrc gtBetaScreens_0070F238[]; // 0x0070F238
extern int gnBetaScreenCount_0070F024; // 0x0070F024
extern char gszServerIP_0070EF20[]; // 0x0070EF20
extern char gszAddress_0070F130[]; // 0x0070F130
extern unsigned char gbGlobal_007A0522; // 0x007A0522
void __fastcall sub_0044B440_PushValue(int nValue); // 0x0044B440
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480
void __cdecl sub_00475EF0_FreeLerpTables(); // 0x00475EF0
void __cdecl sub_00468170_ShutdownCursor(); // 0x00468170
void __cdecl sub_00451850(); // 0x00451850
void __cdecl sub_004794B0_FreeRosterLists(); // 0x004794B0
void __cdecl sub_00478A50_FreeRosterPets(); // 0x00478A50
void __cdecl sub_00451F20_RegisterWindowHandlers(); // 0x00451F20
void __fastcall sub_00530F30(int nValue); // 0x00530F30
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __stdcall GAME_SetGlobalAct(int nAct); // 0x0052DFA0

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
extern int gnGlobal_0071146C; // 0x0071146C
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

struct D2ClientConfigStrc
{
    char unk0x000[0x1EF];
    unsigned char nFlags1EF;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
void __cdecl sub_00449B70(); // 0x00449B70
void __cdecl sub_0044C000(); // 0x0044C000
void __cdecl sub_0044C2C0(); // 0x0044C2C0
void __cdecl sub_0044C6E0(); // 0x0044C6E0
void __cdecl sub_0044C790(); // 0x0044C790
__declspec(noinline) int __fastcall sub_0044CCA0(unsigned int nFrames, unsigned int nRemainder, int nRate);
void __cdecl sub_0044CCE0(); // 0x0044CCE0
void __cdecl sub_0044CE90(); // 0x0044CE90
void __cdecl sub_0044EEC0(); // 0x0044EEC0
void __cdecl sub_004519C0(); // 0x004519C0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __cdecl sub_00462920(); // 0x00462920
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __cdecl sub_00467AC0(); // 0x00467AC0
void __cdecl sub_00477DD0(); // 0x00477DD0
void __cdecl sub_0047BDF0(); // 0x0047BDF0
void __fastcall sub_00480320(int nDelta); // 0x00480320
void __fastcall sub_00481600(D2UnitStrc* pPlayer); // 0x00481600
void __cdecl sub_00482C20_Tick(); // 0x00482C20
int __cdecl sub_00514840_IsChannelStreaming(); // 0x00514840
void __cdecl sub_00514930(); // 0x00514930
void __fastcall sub_00515F50(int nArg); // 0x00515F50
int __stdcall sub_0052FC20(int nArg); // 0x0052FC20
extern unsigned int gdwFrameTime_0070EF1C; // 0x0070EF1C
extern D2ClientConfigStrc* gpConfig_007A0438; // 0x007A0438
extern _RTL_CRITICAL_SECTION gCriticalSection_007A0468; // 0x007A0468
extern unsigned int gdwLastCheck_007A04A0; // 0x007A04A0
extern unsigned int gdwGlobal_007A04B8; // 0x007A04B8
extern unsigned int gdwGlobal_007A04BC; // 0x007A04BC
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gdwGlobal_007A0620; // 0x007A0620
extern int gnGlobal_007A0648; // 0x007A0648
extern int gnGlobal_007A0650; // 0x007A0650
extern int gnGlobal_007A0654; // 0x007A0654

unsigned char gnBetaScreenIndex_007A060D; // 0x007A060D

char gszGameName_007A05DC[20]; // 0x007A05DC

unsigned short gwJoinID_007A0520; // 0x007A0520

int gdwGlobal_007A05C0; // 0x007A05C0

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

#include "gen/data/Source/D2Client/GAME/Game_0044D080.inc"

int gdwGlobal_007A04F4; // 0x007A04F4

// 0x0044D390
int __fastcall sub_0044D390_GetTextX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - sub_00501820(wszText) / 2;
}

// 0x0044D3E0
void __cdecl sub_0044D3E0_DrawOverlayA()
{
    int nX = sub_0044D390_GetTextX(0x13EA, gnGlobal_0071146C / 2);
    int nY = 0x3E;
    if (gdwGlobal_007A04F4)
        nY = 0x64;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x13EA), nX, nY, 4, 0);
    if (!gdwGlobal_007A04F4)
    {
        nX = sub_0044D390_GetTextX(0x13EB, gnGlobal_0071146C / 2);
        sub_00502320(D2LANG_GetStringFromTblIndex(0x13EB), nX, 0x6B, 4, 0);
    }
    nY = 0xE8;
    if (gdwGlobal_007A04F4)
        nY = 0x110;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x13EC), sub_0044D390_GetTextX(0x13EC, gnGlobal_0071146C / 2), nY, 4, 0);
}

char gszCharName_007A05C4[4]; // 0x007A05C4

// 0x0044D890
void __fastcall sub_0044D890_ApplyConfigName(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szName, "0"))
    {
        int nLength = strlen(pConfig->szName);
        memset(gszCharName_007A05C4, 0, 0x10);
        ++nLength;
        if (nLength > 0x10)
        {
            nLength = 0x10;
        }
        strncpy(gszCharName_007A05C4, pConfig->szName, nLength);
    }
}

// 0x0044CCA0
int __fastcall sub_0044CCA0(unsigned int nValue, unsigned int nUnused, int nLimit)
{
    int nCount = 0;
    if (nLimit < 7)
        nCount = 1;
    if ((int)nValue > 1)
        nCount++;
    if ((int)nValue > 9)
        nCount++;
    if ((int)nValue > 0x13)
        nCount++;
    if ((int)nValue > 0x1D)
        nCount++;
    return nCount;
}

D2ClientCallbackFn gpfnClientCallback_007A0484; // 0x007A0484

unsigned int gdwGlobal_007A048C; // 0x007A048C

unsigned int gdwLastFrame_007A0490; // 0x007A0490

int gnGlobal_007A0494; // 0x007A0494

unsigned int gdwNextCheck_007A049C; // 0x007A049C

int gdwGlobal_007A04A8; // 0x007A04A8

int gnGlobal_007A04AC; // 0x007A04AC

int gnGlobal_007A04B0; // 0x007A04B0

int gnGlobal_007A04B4; // 0x007A04B4

void* ghEvent_007A05BC; // 0x007A05BC

int gnGameType_007A0610; // 0x007A0610

int gnSkipped_007A0704; // 0x007A0704

// 0x0044EFA0
int __stdcall sub_0044EFA0_GameFrame(int nUnused)
{
    int bFrame = 0;
    int bDrawn = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (gnGameType_007A0610 == 0 || gnGameType_007A0610 == 1)
    {
        if (WINDOW_GetState())
        {
            gdwLastFrame_007A0490 = GetTickCount();
            return 0;
        }

        if ((sub_00453A90_GetUIVarUnchecked(9) || sub_00453A90_GetUIVarUnchecked(11)) && pPlayer && sub_004646A0_GetPlayerRoom())
        {
            gdwLastFrame_007A0490 = GetTickCount();
            gpfnClientCallback_007A0484(0);
            sub_00482C20_Tick();
            return 0;
        }
    }

    sub_004519C0();
    if (gnGlobal_007A0650)
    {
        sub_0044C000();
    }

    if (gnGlobal_007A0654)
    {
        sub_0044C2C0();
    }

    sub_0044CE90();

    unsigned int dwNow = GetTickCount();
    if (gdwNextCheck_007A049C < dwNow)
    {
        sub_00477DD0();
        gdwLastCheck_007A04A0 = dwNow;
        if (gpConfig_007A0438->nFlags1EF & 4)
        {
            gdwNextCheck_007A049C = dwNow + 5000;
        }
        else
        {
            gdwNextCheck_007A049C = dwNow + 5000;
        }
    }

    gdwGlobal_007A048C = GetTickCount();
    if (!gdwLastFrame_007A0490)
    {
        gdwLastFrame_007A0490 = gdwGlobal_007A048C - gdwFrameTime_0070EF1C;
    }

    sub_00480320(gdwLastFrame_007A0490 - gdwGlobal_007A048C);
    sub_0044CCE0();

    unsigned int nElapsed = gdwGlobal_007A048C - gdwLastFrame_007A0490;
    if (nElapsed >= gdwFrameTime_0070EF1C)
    {
        gdwLastFrame_007A0490 = gdwGlobal_007A048C;
        bFrame = 1;
        if (gdwGlobal_007A048C < gdwGlobal_007A04BC)
        {
            nElapsed -= gdwFrameTime_0070EF1C;
            unsigned int nLate = gdwFrameTime_0070EF1C - 1;
            if (nElapsed < nLate)
            {
                nLate = nElapsed;
            }

            gdwLastFrame_007A0490 = gdwGlobal_007A048C - nLate;
            gnSkipped_007A0704 = 0;
            nElapsed = gdwFrameTime_0070EF1C;
            gdwGlobal_007A04B8 = gdwGlobal_007A048C;
            gdwGlobal_007A04A8 = 25;
            gnGlobal_007A04B0 = 0;
            gnGlobal_007A04AC = 0;
            gnGlobal_007A04B4 = 0;
        }

        if (gdwGlobal_007A061C)
        {
            sub_00481600(pPlayer);
        }
    }

    int bReady = 0;
    if (gnGameType_007A0610 == 0)
    {
        sub_0052CFE0();
        bReady = sub_0052FC20(1);
        if (bReady)
        {
            sub_0052FD90(1, 0);
        }
    }
    else if (gnGameType_007A0610 == 1)
    {
        sub_0052CFE0();
        bReady = sub_0052FC20(1);
        sub_0052FD90(0, 0);
    }

    sub_0044C6E0();
    sub_0047BDF0();
    sub_00449B70();
    sub_0044EEC0();

    if (gdwGlobal_007A061C)
    {
        if (gnGameType_007A0610 != 0 && gnGameType_007A0610 != 1)
        {
            if (bFrame)
            {
                sub_0044C790();
                gdwLastFrame_007A0490 += gdwFrameTime_0070EF1C - nElapsed;
                bDrawn = 1;
                const int nRate = gdwGlobal_007A04A8;
                const unsigned int nFrames = nElapsed / gdwFrameTime_0070EF1C;
                const unsigned int nRest = nElapsed % gdwFrameTime_0070EF1C;
                int nLimit = sub_0044CCA0(nFrames, nRest, nRate);
                if (nRate > 28)
                {
                    nLimit = 0;
                }

                if (gnSkipped_007A0704 > nLimit)
                {
                    gnSkipped_007A0704 = 0;
                }
            }
            else if (gdwGlobal_007A04A8 > 22)
            {
                gnSkipped_007A0704 = 0;
            }
        }
        else if (bReady)
        {
            sub_0044C790();
            bDrawn = 1;
            if (nElapsed <= gdwFrameTime_0070EF1C)
            {
                gnSkipped_007A0704 = 0;
            }
            else if (nElapsed < 2 * gdwFrameTime_0070EF1C)
            {
                gdwLastFrame_007A0490 += gdwFrameTime_0070EF1C - nElapsed;
                gnSkipped_007A0704 = 0;
            }
            else
            {
                gnSkipped_007A0704 = gnSkipped_007A0704 <= 1;
                gdwLastFrame_007A0490 += 1 - gdwFrameTime_0070EF1C;
            }
        }
    }

    if (gdwGlobal_007A061C)
    {
        sub_00462920();
        sub_00467AC0();
        if (sub_00514840_IsChannelStreaming())
        {
            sub_00515F50(0xB4);
            sub_00514930();
            sub_00515CE0_SetMasterVolume(0xFF);
        }

        if (!gnSkipped_007A0704)
        {
            if (sub_004646A0_GetPlayerRoom())
            {
                gpfnClientCallback_007A0484(0);
                ++gnGlobal_007A0494;
                ++gnGlobal_007A04AC;
            }
        }
        else if (bFrame)
        {
            ++gnGlobal_007A04B4;
        }

        if (bDrawn)
        {
            sub_00482C20_Tick();
        }

        ++gnSkipped_007A0704;
    }
    else
    {
        WINDOW_GetState();
    }

    if (!gdwGlobal_007A0620)
    {
        return 0;
    }

    sub_00480340();
    sub_004FB480_SetActA(0);
    sub_00456300_CloseUIVars(1, 0);
    if (gnGameType_007A0610 == 0 || gnGameType_007A0610 == 1)
    {
        sub_0052E9C0();
    }

    if (gnGameType_007A0610 == 6 || gnGameType_007A0610 == 8)
    {
        EnterCriticalSection(&gCriticalSection_007A0468);
        gnGlobal_007A0648 = 1;
        LeaveCriticalSection(&gCriticalSection_007A0468);
        WaitForSingleObject(ghEvent_007A05BC, 10000);
        ghEvent_007A05BC = 0;
    }

    return 1;
}
