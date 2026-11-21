#include "D2Client.h"
#include "D2SysTypes.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
#include "D2Structs.h"

struct D2TileLibraryHeaderStrc;

struct D2CelFileStrc;

struct D2PoolSystemStrc;

struct Unicode;

struct D2QuestScreenStrc;

struct D2LoadingTimerStrc;

struct D2MsgHandlerEntryStrc;

struct D2MessageStrc;

struct D2CriticalSectionStrc;

struct D2VersionInfoStrc;

struct D2ComInterfaceStrc;

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

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall DATATBLS_CheckActInLevelTypesTxt(int nLevelType, unsigned char nAct); // 0x0061EAE0

void __stdcall DATATBLS_GetFileNameFromLevelTypeAndFileId(int nLevelType, int nFile, char* szFile); // 0x0061EB40

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry); // 0x004795A0

extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0

int __fastcall sub_00479B80_GetRecordValue(D2StoredUnitRecordStrc* pEntry); // 0x00479B80

int __cdecl sub_0047A980_IsNumberDisplayEnabled(); // 0x0047A980

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

void __cdecl sub_0044D3E0_DrawOverlayA(); // 0x0044D3E0

void __cdecl sub_0044E5A0_DrawOverlayB(); // 0x0044E5A0

int __fastcall sub_0044D390_GetTextX(unsigned short nStringIndex, int nCenterX); // 0x0044D390

void __cdecl sub_004684C0(); // 0x004684C0

void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880

void __stdcall D2CMPLoadProjectRecord(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath); // 0x00600790

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

D2CelFileStrc* __fastcall sub_004788B0_LoadCellFile(const char* szPath, int nType); // 0x004788B0

int __stdcall D2Win_10028(const char* pszPalDatFilename, const char* pszPalPL2Filename); // 0x004FB500

void __fastcall sub_004547B0(); // 0x004547B0

void __fastcall sub_00478130_SetScale(int nValue, int nDivisor); // 0x00478130

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex); // 0x004B92E0

void __fastcall sub_00478A00(void* pCel); // 0x00478A00

void __fastcall sub_00492F40_SetFade(int nMode); // 0x00492F40

int __fastcall sub_0044DFF0_TimerExpired(D2LoadingTimerStrc* pTimer); // 0x0044DFF0

void __fastcall sub_00502680_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nA, int nB, int nC); // 0x00502680

extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC

extern int gnLineHeight_007111C8; // 0x007111C8

extern int gdwGlobal_007A04F4; // 0x007A04F4

extern D2QuestScreenStrc gtQuestScreens_0070F85C[]; // 0x0070F85C

extern int gnQuestScreens_0070F92C; // 0x0070F92C

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern D2CelFileStrc* gpLoadingScreen_007A2888; // 0x007A2888

extern int gnLoadingFrame_007A2A6C; // 0x007A2A6C

extern int gdwGlobal_007A2868; // 0x007A2868

extern int gnValue_007A27B8; // 0x007A27B8

extern int gnValue_007A0624; // 0x007A0624


struct D2MessageStrc { void* hWnd; unsigned int uMessage,wParam,lParam,time; int x,y; };


struct D2VersionInfoStrc { unsigned long dwSize; char unknown04[144]; };

struct D2ComInterfaceStrc { char unknown00[0xC4]; void (__stdcall* Close)(); };

#pragma pack(push, 1)

struct D2ClientInfoStrc
{
    char unknown00[0x1EF];
    union { unsigned short wFlags; struct {unsigned char lowFlags,progress;}; };
    char unknown1F1[0x33]; unsigned char nSoundArg;
};

#pragma pack(pop)

typedef int (__stdcall* D2IdleHandler)(int);

typedef unsigned long (__stdcall* D2ThreadProc)(void*);

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2VersionInfoStrc*); // 0x006CC1F8

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc*); // 0x006CC210

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*,unsigned long,D2ThreadProc,void*,unsigned long,unsigned long*); // 0x006CC250

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2MessageStrc*,void*,unsigned int,unsigned int,unsigned int); // 0x006CC480

extern D2MsgHandlerEntryStrc gtHandlers_0070F2C4[1]; // 0x0070F2C4

extern D2MsgHandlerEntryStrc gtHandlers_0070F2D0[10]; // 0x0070F2D0

extern D2MsgHandlerEntryStrc gtHandlers_0070F348[2]; // 0x0070F348

extern D2MsgHandlerEntryStrc gtHandlers_0070F360[2]; // 0x0070F360

extern D2MsgHandlerEntryStrc gtHandlers_0070F3C0[7]; // 0x0070F3C0

extern D2MsgHandlerEntryStrc gtHandlers_0070F418[9]; // 0x0070F418

extern D2CriticalSectionStrc gtCriticalSection_007A0468; // 0x007A0468

extern int gnServerToken_007A0520; // 0x007A0520

extern D2VersionInfoStrc gtVersionInfo_007A0528; // 0x007A0528

extern void* ghThread_007A05BC; // 0x007A05BC

extern int gnServerHash_007A05C0; // 0x007A05C0

extern const char gszGameName_007A05DC[]; // 0x007A05DC

extern unsigned long gnThreadId_007A05F0; // 0x007A05F0

extern D2ComInterfaceStrc* gpComInterface_007A05F4; // 0x007A05F4

extern int gnBetaScreens_007A0600; // 0x007A0600

extern int gnDifficultyDirty_007A0604; // 0x007A0604

extern unsigned char gnDifficulty_007A060C; // 0x007A060C

extern int gnMode_007A0610; // 0x007A0610

extern int gnPlayCinematic_007A0628; // 0x007A0628

extern int gnCinematicPlayed_007A062C; // 0x007A062C

extern int gnVersionValid_007A0644; // 0x007A0644

extern int gnThreadStop_007A0648; // 0x007A0648

extern int gnThreadReady_007A064C; // 0x007A064C

extern D2LoadingTimerStrc gtLoadingTimer_007A0684; // 0x007A0684

void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc*,int); // 0x00409FF0

void __fastcall sub_0044B440_PushValue(int); // 0x0044B440

void __fastcall sub_0044BA20(int); // 0x0044BA20

void __cdecl sub_0044C890_ReleaseGameState(); // 0x0044C890

unsigned long __stdcall sub_0044CF20(void*); // 0x0044CF20

int __stdcall sub_0044D100_ShowBetaScreens(int); // 0x0044D100

extern "C" void __cdecl sub_0044DCE0_MouseExtTables_451E10(); // 0x0044DCE0

int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc*); // 0x0044E040

void __cdecl sub_0044E200_InitGameState(); // 0x0044E200

int __stdcall sub_0044E400_LoadingTimerCallback(int); // 0x0044E400

int __stdcall sub_0044E770_DrawEndGameScreen(int); // 0x0044E770

int __stdcall sub_0044EFA0_GameFrame(int); // 0x0044EFA0

void __cdecl sub_00451620_WriteRecordFile(); // 0x00451620

int __cdecl sub_00451910(); // 0x00451910

void __cdecl sub_00451940_InstallRecordHandler(); // 0x00451940

void __cdecl sub_00451970(); // 0x00451970

int __cdecl sub_00451980(); // 0x00451980

int __fastcall sub_00451BB0_MessageLoop(D2IdleHandler); // 0x00451BB0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int,D2MsgHandlerEntryStrc*,unsigned int); // 0x00451DB0

void __fastcall sub_00451E10_UnregisterMsgHandlers(int,D2MsgHandlerEntryStrc*,int); // 0x00451E10

int __cdecl sub_00451F10_PushRegisterState(); // 0x00451F10

int __fastcall sub_004680B0_InitCursor(int); // 0x004680B0

void __cdecl sub_00468170_ShutdownCursor(); // 0x00468170

void __cdecl sub_00475DF0_BuildLerpTables(); // 0x00475DF0

void __cdecl sub_00475EF0_FreeLerpTables(); // 0x00475EF0

void __fastcall sub_00477CA0_SendPacket67(const char*,int); // 0x00477CA0

void __fastcall sub_00477F70_SendGameLogon(int,int); // 0x00477F70

int __cdecl sub_0047A990(); // 0x0047A990

int __fastcall sub_004803C0_InitWarden(int); // 0x004803C0

void __cdecl sub_00481830(); // 0x00481830

void __fastcall sub_00482260_UpdateSoundSystem(int); // 0x00482260

void __cdecl sub_00482940_UpdateSound(); // 0x00482940

void __fastcall sub_00482EF0_PlayCinematic(int); // 0x00482EF0

void __cdecl sub_00483310_ResetCinematicFlags(); // 0x00483310

int __cdecl sub_004F59A0(); // 0x004F59A0

void __stdcall D2Win_10006_ClearDrawCaches(); // 0x004F9130

void __fastcall sub_00515F50_FadeOutMaster(int); // 0x00515F50

int gdwGlobal_007A0680; // 0x007A0680

int gdwGlobal_007A0608; // 0x007A0608

D2CelFileStrc* gpLoadingCell_007A2794; // 0x007A2794

D2CelFileStrc* gpBuySellButton_007A287C; // 0x007A287C

static D2CelFileStrc* s_pEndGameCell_007A0700; // 0x007A0700

static D2CelFileStrc* s_pEndGameOkCell_007A06FC; // 0x007A06FC

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

union D2SeedStrc;

struct D2SaveHeaderStrc;

struct D2ClientCharRecordStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449

int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050

struct D2SaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
};

#pragma pack(push, 1)

struct D2ClientCharRecordStrc
{
    char unk0x000[0x1EF];
    unsigned short wValue;
};

#pragma pack(pop)

extern char gszCharName_007A05C4[]; // 0x007A05C4

extern D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438

unsigned char* gpSaveBuffer_007A5224; // 0x007A5224

unsigned int gnSaveBufferSize_007A5228; // 0x007A5228

// build: symbol ?$S4@?7??sub_00455510_DrawLevelLoadingScreen@@YAXXZ@4IA 0x007A314C
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
                    D2CMPLoadProjectRecord(&pLibrary, szFile);
                }
            }
        }
    }

    {
        D2TileLibraryHeaderStrc* pLibrary;
        D2CMPLoadProjectRecord(&pLibrary, "data\\global\\tiles\\act1\\barracks\\warp.dt1");
        D2CMPLoadProjectRecord(&pLibrary, "data\\global\\tiles\\act1\\outdoors\\blank.dt1");
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
                D2Win_10028(szPalette, szPl2);
            }

            if (!s_pEndGameOkCell_007A06FC)
            {
                sprintf(szPalette, "%s\\ui\\menu\\endgameok", szDataGlobal_006D4118);
                s_pEndGameOkCell_007A06FC = sub_004788B0_LoadCellFile(szPalette, 0);
            }

            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = s_pEndGameCell_007A0700;
            tContext.nDirection = 0;
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
            tContext.nDirection = 0;
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

struct D2ActiveRoomStrc;

struct D2StoredUnitRecordStrc;

static inline int TimerExpired(D2LoadingTimerStrc* pTimer)
{
    if(pTimer->dwLength)
    {
        unsigned long dwNow=GetTickCount();
        unsigned long dwLeft;
        if(dwNow>=pTimer->dwStart+pTimer->dwLength)
        {
            pTimer->dwStart=0;
            pTimer->dwLength=0;
            dwLeft=0;
        }
        else dwLeft=pTimer->dwLength-(dwNow-pTimer->dwStart);
        return dwLeft==0;
    }
    return 1;
}

// 0x0044F360
int __cdecl sub_0044F360_RunGameSession()
{
    if(TimerExpired(&gtLoadingTimer_007A0684))sub_0044B880_SetValue(1);
    GetTickCount();
    gtVersionInfo_007A0528.dwSize=sizeof(gtVersionInfo_007A0528);
    if(GetVersionExA(&gtVersionInfo_007A0528))gnVersionValid_007A0644=1;
    sub_00475DF0_BuildLerpTables();
    sub_00483310_ResetCinematicFlags();
    sub_00451F10_PushRegisterState();
    sub_004680B0_InitCursor(0);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2C4,1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F348,2);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F360,2);
    if(gnMode_007A0610!=3 && gnMode_007A0610!=7 && gnMode_007A0610!=9)
    {
        sub_00477CA0_SendPacket67(gszGameName_007A05DC,sub_0047A990());
        if(gnMode_007A0610==6 || gnMode_007A0610==8)
        {
            gnThreadStop_007A0648=0;
            gnThreadReady_007A064C=0;
            InitializeCriticalSection(&gtCriticalSection_007A0468);
            ghThread_007A05BC=CreateThread(0,0,sub_0044CF20,0,0,&gnThreadId_007A05F0);
        }
    }
    else
    {
        sub_00477F70_SendGameLogon(gnServerToken_007A0520,gnServerHash_007A05C0);
        if(gnMode_007A0610==2 || gnMode_007A0610==3)sub_004803C0_InitWarden(gnServerHash_007A05C0);
    }
    sub_00482260_UpdateSoundSystem(gpClientInfo_007A0438->nSoundArg);
    sub_0044E200_InitGameState();
    if(sub_00451910() || sub_00451980())
    {
        D2MessageStrc tMessage;
        while(PeekMessageA(&tMessage,0,0,0,1)){}
        if(sub_00451980())sub_00451970();
        else if(sub_00451910())sub_00451940_InstallRecordHandler();
    }
    FOG_SetMemoryPoolSystemMode(0,0);
    if(gnMode_007A0610==6 || gnMode_007A0610==8)
    {
        EnterCriticalSection(&gtCriticalSection_007A0468);
        gnThreadReady_007A064C=1;
        LeaveCriticalSection(&gtCriticalSection_007A0468);
    }
    sub_00451BB0_MessageLoop(sub_0044EFA0_GameFrame);
    GetTickCount();
    sub_00515F50_FadeOutMaster(180);
    sub_00481830();
    if(sub_0044E040_TimerRunning(&gtLoadingTimer_007A0684) && !gnDifficultyDirty_007A0604 && !gnCinematicPlayed_007A062C)sub_00451BB0_MessageLoop(sub_0044E400_LoadingTimerCallback);
    if(sub_00451910())sub_00451620_WriteRecordFile();
    if(gnBetaScreens_007A0600)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2C4,1);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F348,2);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F360,2);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F3C0,7);
        sub_00451BB0_MessageLoop(sub_0044D100_ShowBetaScreens);
    }
    else if(gnDifficultyDirty_007A0604)
    {
        sub_00482EF0_PlayCinematic(5);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
        sub_0044DCE0_MouseExtTables_451E10();
        sub_0044BA20(0);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
        sub_00451BB0_MessageLoop(sub_0044E770_DrawEndGameScreen);
    }
    else if(gnPlayCinematic_007A0628)
    {
        sub_00482EF0_PlayCinematic(7);
        gnCinematicPlayed_007A062C=1;
    }
    unsigned char bEndGame=1;
    if(gnCinematicPlayed_007A062C)
    {
        int nDifficulty=gnDifficulty_007A060C;
        int nProgress=gpClientInfo_007A0438->progress&31;
        D2ClientInfoStrc* pClientInfo=gpClientInfo_007A0438;
        switch(nDifficulty)
        {
        case 0:
            if(nProgress==8)bEndGame=0;
            else if(nProgress==12)bEndGame=0;
            break;
        case 1:
            if(nProgress==12)bEndGame=0;
            break;
        }
        pClientInfo->wFlags=((nDifficulty<<10)+0x500)|(pClientInfo->wFlags&0xE0FF);
        if(bEndGame)
        {
            sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
            sub_0044DCE0_MouseExtTables_451E10();
            sub_0044BA20(2);
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
            sub_00451BB0_MessageLoop(sub_0044E770_DrawEndGameScreen);
        }
    }
    sub_0044C890_ReleaseGameState();
    sub_00482940_UpdateSound();
    sub_00475EF0_FreeLerpTables();
    sub_00468170_ShutdownCursor();
    D2Win_10006_ClearDrawCaches();
    sub_0044B440_PushValue(4);
    if(gnBetaScreens_007A0600)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F3C0,7);
        gnBetaScreens_007A0600=0;
    }
    else if(gnDifficultyDirty_007A0604)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
        gnDifficultyDirty_007A0604=0;
    }
    else if(bEndGame && gnCinematicPlayed_007A062C)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
        gnCinematicPlayed_007A062C=0;
    }
    else
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
        sub_0044DCE0_MouseExtTables_451E10();
    }
    if(gnMode_007A0610==2 || gnMode_007A0610==6 || gnMode_007A0610==3 || gnMode_007A0610==7)
        if(gpComInterface_007A05F4)gpComInterface_007A05F4->Close();
    return 6;
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
D2CelFileStrc* __cdecl sub_00454600_GetBuySellButtonCells()
{
    if (!gpBuySellButton_007A287C)
    {
        char szPath[0x104];
        wsprintfA(szPath, "%s\\ui\\panel\\buysellbtn", szDataGlobal_006D4118);
        gpBuySellButton_007A287C = sub_004788B0_LoadCellFile(szPath, 0);
    }
    return gpBuySellButton_007A287C;
}

// 0x00454740
void __cdecl sub_00454740_LoadLoadingPalette()
{
    char szPl2[0x104];
    char szPalette[0x104];
    sprintf(szPalette, "%s\\Palette\\Loading\\pal.dat", szDataGlobal_006D4118);
    sprintf(szPl2, "%s\\Palette\\Loading\\pal.pl2", szDataGlobal_006D4118);
    D2Win_10028(szPalette, szPl2);
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
    if (STRTABLE_GetLanguage())
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

// build: context SEED_RollRandomNumberInline
static inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: context SEED_RollLimitedRandomNumberInline
static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0045C3E0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInline(pSeed, nMax);
}

// 0x0045C520
void __cdecl sub_0045C520_SaveCharFile()
{
    char szPath[500];
    char szDir[0x400];

    D2_ASSERT(gszCharName_007A05C4[0], 0x25);

    const unsigned int nSize = gnSaveBufferSize_007A5228;
    if (nSize < 8)
    {
        return;
    }

    unsigned char* pBuffer = gpSaveBuffer_007A5224;
    const D2SaveHeaderStrc tHeader = *(D2SaveHeaderStrc*)pBuffer;
    if (tHeader.dwMagic != 0xAA55AA55)
    {
        return;
    }

    if (tHeader.dwVersion <= 0x5B)
    {
        if (nSize < 0x82)
        {
            return;
        }
        gpCharRecord_007A0438->wValue = *(unsigned short*)(pBuffer + 0x18);
    }
    else
    {
        if (nSize < 0x14F)
        {
            return;
        }
        gpCharRecord_007A0438->wValue = *(unsigned short*)(pBuffer + 0x24);
    }

    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPath, "%s%s.d2s", szDir, gszCharName_007A05C4);
    _iobuf* pFile = fopen(szPath, "wb");
    if (pFile)
    {
        fwrite(gpSaveBuffer_007A5224, gnSaveBufferSize_007A5228, 1, pFile);
        fclose(pFile);
    }
}

#include "gen/data/Source/D2Client/GAME/Game_0044DB60.inc"
