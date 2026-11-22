#include "D2Client.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2GameTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientNotifyStrc;

struct D2ClientCharRecordStrc;

struct D2RangeStrc;

#pragma pack(push, 1)

struct D2ClientCharRecordStrc
{
    char unk0x00[0x19];
    char aState[4];
    char unk0x1D[2];
    union
    {
        char szName[0x1D0];
        struct
        {
            char szText0x1F[0x18];
            char szText0x37[0x1B8];
        };
    };
    union
    {
        unsigned char aFlags[2];
        unsigned short wValue;
    };
    char unk0x1F1[0x1F];
    unsigned char nKind;
    char unk0x211[0x14];
    D2ClientNotifyStrc* pNotify;
    char unk0x229[0x1C];
    char szText245[0x18];
    char szText25D[0x10];
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* pString);

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall sub_0045AEA0_SetPanelSlide(int nMode); // 0x0045AEA0

void __fastcall sub_00457640(int nValue); // 0x00457640

void __fastcall sub_00457440_Nop(int nResolution); // 0x00457440

void __fastcall sub_004549B0(int nResolution); // 0x004549B0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __cdecl sub_00466FF0(); // 0x00466FF0

void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom); // 0x0046C460

void __fastcall sub_00466820_SpawnRoomPresets(D2ActiveRoomStrc* pRoom); // 0x00466820

void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom); // 0x0046BE60

extern D2McpPacketHandler gpfnMcpHandlers_0070ED00[]; // 0x0070ED00

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern int gnGlobal_00711474; // 0x00711474

extern void (__fastcall* gpfnCallback_00799308)(void* pArg); // 0x00799308

int gaValues_007A0424[1]; // 0x007A0424

int gnValueCount_007A044C; // 0x007A044C

extern int gdwGlobal_007A061C; // 0x007A061C

extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634

extern int gdwGlobal_007A0650; // 0x007A0650

extern int gdwGlobal_007A0654; // 0x007A0654

extern int gdwGlobal_007A0658; // 0x007A0658

int gdwGlobal_007A0670;                                                                                     // 0x007A0670

extern int gdwGlobal_007A0674; // 0x007A0674

extern int gnUiRecordRow_007A5218; // 0x007A5218

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth_007A5220; // 0x007A5220

struct D2RangeStrc
{
    int nStart;
    int nLength;
};

int __cdecl sub_004F59A0(); // 0x004F59A0

void __stdcall WINDOW_ShowAll(); // 0x004F5F60

void __stdcall CLIENT_Initialize(int nArg, const char* szAddress); // 0x0052A750

int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int)); // 0x00451BB0

int __stdcall sub_0044BBB0_WaitConnect(int nUnused); // 0x0044BBB0

extern D2McpCallbackFn gpfnMcpCallback_007992F8; // 0x007992F8

extern D2McpCallbackFn gpfnMcpCallback_007992FC; // 0x007992FC

D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438

int gdwGlobal_007A065C; // 0x007A065C

int gdwGlobal_007A0660; // 0x007A0660

int gdwGlobal_007A0664; // 0x007A0664

int gdwGlobal_007A066C; // 0x007A066C

struct D2AutomapRecordStrc;

struct D2PoolSystemStrc;

#pragma pack(push, 1)

struct D2ClientInfoStrc
{
    char unk0x00[0x1EF];
    union
    {
        unsigned short wFlags;
        struct
        {
            unsigned char lowFlags;
            unsigned char progress;
        };
    };
    char unk0x1F1[0x33];
    unsigned char nSoundArg;
};

#pragma pack(pop)

struct D2LoadingTimerStrc
{
    unsigned long dwStart;
    unsigned long dwLength;
    D2LoadingTimerStrc() : dwStart(0), dwLength(0)
    {
    }
};

struct D2WinMsgStrc
{
    unsigned int dwTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2MsgRecordChunkStrc
{
    D2WinMsgStrc tRecords[500];
    int nCount;
    int nUnk0x1F44;
    D2MsgRecordChunkStrc* pNext;
};

typedef void (__fastcall* D2InitHandlerFn)(void* pArg);

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

typedef int (__stdcall* D2LoadStringFn)(int nId, char* szBuffer, unsigned int nSize);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryExA(const char* szFileName, void* hFile, unsigned long dwFlags); // 0x006CC348

extern "C" __declspec(dllimport) void* __stdcall LoadAcceleratorsA(void* hInstance, const char* szTableName); // 0x006CC4A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80

int __cdecl sub_00409DD0_InitPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused); // 0x00409DD0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0);                        // 0x0040B3C0

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

int __stdcall SErrRegisterMessageSource(unsigned short wFacility, void* hModule, void* pReserved);     // 0x0041C2F0

int __cdecl sub_0044BBA0();                                                                                 // 0x0044BBA0

void __stdcall sub_0044C850(int nArg1, int nArg2, int nArg3);                                               // 0x0044C850

void __fastcall sub_0044C990(void* pArg);                                                                   // 0x0044C990

void __cdecl sub_0044DBE0_ReadColorFlag();                                                                  // 0x0044DBE0

int __stdcall sub_004512C0_LoadString(int nId, char* szBuffer, unsigned int nSize);                         // 0x004512C0

void __stdcall sub_00451920_RecordHandler(int nArg1, int nArg2, int nArg3);                                 // 0x00451920

void __cdecl sub_00456550_LoadLoadingScreen();                                                              // 0x00456550

void __cdecl sub_00456D80_ShutdownUI();                                                                                // 0x00456D80

void __fastcall sub_00457300_InitGfxCaches(void* pMemPool, int bCelPool);                                   // 0x00457300

void __fastcall sub_00457420_FreeCaches(int nArg);                                                                     // 0x00457420

void __cdecl sub_00463C70();                                                                                // 0x00463C70

void __fastcall sub_00463D90_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90

void __cdecl sub_004659C0_FreeAllUnits();                                                                                // 0x004659C0

void __cdecl sub_00466FE0();                                                                                // 0x00466FE0

unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0

int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90

void __cdecl sub_0046BF90_ResetLevelEffects();                                                                                // 0x0046BF90

void __cdecl sub_0046D750();                                                                                // 0x0046D750

void __cdecl sub_00472320();                                                                                // 0x00472320

void __cdecl sub_004723C0();                                                                                // 0x004723C0

void __cdecl sub_00472BD0();                                                                                // 0x00472BD0

void __cdecl sub_00473CE0_Nop();                                                                                // 0x00473CE0

void __cdecl sub_00473CF0_Nop();                                                                                // 0x00473CF0

void __cdecl sub_00474790_ClearLightGrid();                                                                                // 0x00474790

void __cdecl sub_004758D0_FreeAllLights();                                                                                // 0x004758D0

void __fastcall sub_00475FD0(D2ViewStrc* pView);                                                            // 0x00475FD0

void __fastcall sub_004760A0_SetViewPos(D2ViewStrc* pView, int nX, int nY);                                 // 0x004760A0

D2ViewStrc* __cdecl sub_00476B10();                                                                         // 0x00476B10

void __cdecl sub_00476EA0_LoadPalShift();                                                                   // 0x00476EA0

void __cdecl sub_00476FB0();                                                                                // 0x00476FB0

void __cdecl sub_00477DD0();                                                                                // 0x00477DD0

void __fastcall sub_004781D0(int bAnimate);                                                    // 0x004781D0

void __cdecl sub_0047BD30_ResetChatHistory();                                                                                // 0x0047BD30

void __cdecl sub_0047F1D0_LoadResolution();                                                                 // 0x0047F1D0

void __cdecl sub_00483960();                                                                                // 0x00483960

void __cdecl sub_00499E30_SetBlackColour();                                                                                // 0x00499E30

int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320

D2RecordHandlerFn __fastcall sub_005173D3_SetRecordHandler(D2RecordHandlerFn pfnHandler);                  // 0x005173D3

int __fastcall sub_0051740B_ErrorBox(const char* szText);                                                   // 0x0051740B

void __fastcall sub_005177B2_SetLoadStringFn(void* pfnLoadString); // 0x005177B2

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

void __cdecl D2CMPTileFreeAsyncLoads();                                                                                // 0x005FE070

void __cdecl D2CMPSpriteFreeAsyncLoads();                                                                                // 0x005FF3A0

void __cdecl sub_00600B80();                                                                                // 0x00600B80

extern "C" const char gszLngFileName_006D5EE0[];                                                            // 0x006D5EE0

extern int gdwGlobal_0070F414;                                                                              // 0x0070F414

extern D2InitHandlerFn gpfnInitHandlers_0070F488[52];                                                       // 0x0070F488

extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern char gaClientState_007A0480[0x80];                                                                   // 0x007A0480

extern D2ClientCallbackFn gpfnClientCallback_007A0484;                                                      // 0x007A0484

D2PoolSystemStrc* gpMemPool_007A0488;                                                                       // 0x007A0488

extern int gdwGlobal_007A048C;                                                                              // 0x007A048C

extern int gdwGlobal_007A0498;                                                                              // 0x007A0498

extern unsigned long gdwNextTick_007A049C;                                                                  // 0x007A049C

extern unsigned long gdwLastTick_007A04A0;                                                                  // 0x007A04A0

extern int gdwGlobal_007A04A8;                                                                              // 0x007A04A8

int gdwGlobal_007A04B8;                                                                                     // 0x007A04B8

extern unsigned long gdwDelayEnd_007A04BC;                                                                  // 0x007A04BC

extern int gdwGlobal_007A04C8;                                                                              // 0x007A04C8

extern int gdwGlobal_007A04F4;                                                                              // 0x007A04F4

int gdwGlobal_007A04F8;                                                                                     // 0x007A04F8

int gdwGlobal_007A04FC;                                                                                     // 0x007A04FC

extern int gdwGlobal_007A0524;                                                                              // 0x007A0524

extern int gdwGlobal_007A05F8;                                                                              // 0x007A05F8

extern int gdwGlobal_007A0608;                                                                              // 0x007A0608

unsigned char gnDifficulty_007A060C;                                                                        // 0x007A060C

extern int gdwGlobal_007A0620;                                                                              // 0x007A0620

extern int gnValue_007A0624;                                                                                // 0x007A0624

int gdwGlobal_007A0628;                                                                                     // 0x007A0628

int gdwGlobal_007A062C;                                                                                     // 0x007A062C

extern D2AutomapRecordStrc* gpAutomapRecord_007A0638;                                                       // 0x007A0638

extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640

int gdwGlobal_007A0684;                                                                                     // 0x007A0684

int gdwGlobal_007A0688;                                                                                     // 0x007A0688

extern void* gxGlobal_007A0708;                                                                             // 0x007A0708

void* ghLngModule_007A070C;                                                                                 // 0x007A070C

char gszLngPath_007A0710[0x104];                                                                            // 0x007A0710

extern D2RecordHandlerFn gpfnPrevHandler_007A2764;                                                          // 0x007A2764

extern int gdwGlobal_007A2780;                                                                              // 0x007A2780

extern int gdwGlobal_007A2788;                                                                              // 0x007A2788

extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0

Unicode gxGlobal_007A2C80[80];                                                                              // 0x007A2C80

extern int gdwGlobal_007A2D20;                                                                              // 0x007A2D20

extern int gdwGlobal_007A2D24;                                                                              // 0x007A2D24

extern Unicode gwszHoverLine_007A2D30[];                                                                    // 0x007A2D30

extern int gnHoverTextColor_007A2F30;                                                                       // 0x007A2F30

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl sub_0044C060_Refresh(); // 0x0044C060

int __stdcall D2GFX_Release(); // 0x004F5050

int __stdcall WINDOW_Destroy(); // 0x004F5900

#define OFFSET(T,m) ((unsigned int)&(((T*)0)->m))

struct D2DrlgStrc;

struct Context;

struct Auxiliary;

struct Allocation;

struct UnitPrefix;

void __cdecl sub_0044C750_InitRooms(); // 0x0044C750

void __cdecl sub_00465AA0_ResetUnitTables(); // 0x00465AA0

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

void __stdcall DUNGEON_AnimateTiles(D2ActiveRoomStrc* pRoom); // 0x0061AEF0

void __cdecl sub_0046BEB0_UpdateTimers(); // 0x0046BEB0

void __fastcall sub_00470350_PreloadTick(int nValue); // 0x00470350

int __stdcall ENVIRONMENT_UpdatePeriodOfDay(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061BFC0

void __cdecl sub_004646C0_UpdateObjectsForPeriod(); // 0x004646C0

D2DrlgStrc* __stdcall DUNGEON_GetDrlgFromAct(D2DrlgActStrc* pAct); // 0x0061AA90

void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg); // 0x0061B920

void __cdecl sub_00459020_UpdateAutomapReveal(); // 0x00459020

void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct); // 0x0061AA20

extern unsigned long gdwTickCount_007A048C; // 0x007A048C

extern unsigned int gnTickCounter_007A0498; // 0x007A0498

struct UnitPrefix { U32 prefix0; U32 prefix4; U32 prefix8; U32 identifier; };

typedef char check_UnitPrefix_identifier[OFFSET(UnitPrefix,identifier)==12?1:-1];

extern "C" UnitPrefix* __cdecl sub_004680A0_GetSelected();

extern "C" void __fastcall sub_004786A0_SendPacket(U8 command,U32 first,U32 second);

extern "C" Auxiliary* __cdecl sub_004646A0_GetAuxiliary();

extern "C" void __stdcall sub_0061C240_Configure(Context* context,Auxiliary* auxiliary,int mode,int angle,int flag);

extern "C" void __cdecl sub_0049F960_Cleanup();

extern "C" void __stdcall sub_006612A0_Release(Allocation* allocation);

extern "C" int __cdecl sub_0044DCC0_Mode();

extern "C" Context* gContext; // 0x007A0634

extern "C" U8 gDeferred; // 0x007A060E

extern "C" U32 gCleanupState;

extern "C" Allocation* gAllocation;

extern "C" int gCoordinateBase;

extern "C" int gCoordinateOffset;

struct D2SGameDataStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    char unk0x14[0x1DF4 - 0x14];

    D2SGameDataStrc()
    {
        unk0x04 = 0;
        unk0x08 = 0;
        unk0x0C = 0;
        unk0x10 = 0;
    }
};

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00450810_CalcChunkSize(unsigned int nCount);                                           // 0x00450810
    void sub_00450D90_ReallocData(unsigned int nAlloc);                                                     // 0x00450D90
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C ? f_C : sub_00450810_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_00450D90_ReallocData(nCount);
        }
    }
    D2SGameDataStrc* sub_00450ED0_New();
};

struct D2SGameDataStrc;

struct D2StormListAStrc;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210

struct SGAMEDATA;

struct HSGAMEDATA__;

struct HSGAMEDATALOCK__;

class HASHKEY_NONE;

class CCritSect;

template <class T, class KEY> class TSHashTable;

template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;

template <class T, class THANDLE, int CHUNKSIZE> class TSExportTableSimple;

template <class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE> class TSExportTableSync;

template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>;

typedef TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> D2StormHashTableReuseStrc;

template <> class TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0>;

typedef TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> D2StormExportTableSimpleStrc;

template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0>;

typedef TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> D2StormExportTableSyncStrc;

// build: symbol ??0?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@QAE@XZ 0x00451170
// build: symbol ??0?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@QAE@XZ 0x004511F0
// build: symbol ??0?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00451100

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
};

template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> : public TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);                                                    // 0x00450D60
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00451000
    char unk0x04[0x40];

    TSHashTableReuse();                                                                            // 0x00451100
};

template <> class TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> : public D2StormHashTableReuseStrc
{
public:
    unsigned int unk0x44;
    unsigned int m_sequence;
    void* m_wrapper;

    TSExportTableSimple();
};

template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> : public D2StormExportTableSimpleStrc
{
public:
    D2CriticalSectionStrc m_cs;

    TSExportTableSync();
};

// 0x0044B190
int __fastcall sub_0044B190_DispatchPacket(const unsigned char* pPacket, unsigned int nSize)
{
    int nResult = 0;
    if (nSize <= 0)
        return nResult;
    const unsigned char nCmd = pPacket[0];
    if (nCmd >= 0x1A)
        return 0;
    D2McpPacketHandler pfnHandler = gpfnMcpHandlers_0070ED00[nCmd];
    if (pfnHandler)
        nResult = pfnHandler(pPacket, nSize);
    return nResult;
}

// 0x0044B1F0
void __fastcall sub_0044B1F0_SetMcpCallbackA(D2McpCallbackFn pfnCallback)
{
    gpfnMcpCallback_007992F8 = pfnCallback;
}

// 0x0044B200
void __fastcall sub_0044B200_SetMcpCallbackB(D2McpCallbackFn pfnCallback)
{
    gpfnMcpCallback_007992FC = pfnCallback;
}

// 0x0044B220
void __fastcall sub_0044B220_SetCallback(void (__fastcall* pfnCallback)(void* pArg))
{
    gpfnCallback_00799308 = pfnCallback;
}

// 0x0044B440
void __fastcall sub_0044B440_PushValue(int nValue)
{
    D2_ASSERT(gnValueCount_007A044C < 5, 0xAA);
    gaValues_007A0424[gnValueCount_007A044C] = nValue;
    gnValueCount_007A044C += 1;
}

// 0x0044B480
int __cdecl sub_0044B480_PopValue()
{
    D2_ASSERT(gnValueCount_007A044C, 0xB4);
    int nValue = gaValues_007A0424[0];
    --gnValueCount_007A044C;
    for (int i = 0; i < 3; ++i)
        gaValues_007A0424[i] = gaValues_007A0424[i + 1];
    return nValue;
}

// 0x0044B780
void __cdecl sub_0044B780_RaiseGameWindow()
{
    void* hWnd = (void*)sub_004F59A0();
    if (hWnd)
        SendMessageA(hWnd, 0x1C, 0, 0);
    WINDOW_ShowAll();
}

// 0x0044B7B0
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify()
{
    return gpCharRecord_007A0438->pNotify;
}

// 0x0044B7C0
const char* __cdecl sub_0044B7C0_GetRecordText1F()
{
    if (gpCharRecord_007A0438 && strlen(gpCharRecord_007A0438->szText0x1F) >= 1)
        return gpCharRecord_007A0438->szText0x1F;
    return 0;
}

// 0x0044B7F0
const char* __cdecl sub_0044B7F0_GetRecordText245()
{
    if (gpCharRecord_007A0438 && strlen(gpCharRecord_007A0438->szText245) >= 1)
        return gpCharRecord_007A0438->szText245;
    return 0;
}

// 0x0044B820
const char* __cdecl sub_0044B820_GetRecordText37()
{
    if (gpCharRecord_007A0438 && strlen(gpCharRecord_007A0438->szText0x37) >= 1)
        return gpCharRecord_007A0438->szText0x37;
    return 0;
}

// 0x0044B850
int __cdecl sub_0044B850_IsHardcore()
{
    return gpCharRecord_007A0438->aFlags[0] & 4;
}

// 0x0044B860
void __cdecl sub_0044B860()
{
    *(unsigned short*)gpCharRecord_007A0438->aFlags |= 8;
}

// 0x0044B870
void __cdecl sub_0044B870_SetLaunchState1()
{
    gnLaunchState_0070EE4C = 1;
}

// 0x0044B880
void __fastcall sub_0044B880_SetValue(int nValue)
{
    gdwGlobal_0070EE8C = nValue;
}

// 0x0044BA20
void __fastcall sub_0044BA20(int nResolution)
{
    if (nResolution == D2GFX_GetResolutionMode())
        return;
    switch (nResolution)
    {
    case 0:
        gnGlobal_0071146C = 640;
        gnGlobal_00711470 = 480;
        gnUiRecordRow_007A5218 = 0;
        break;
    case 2:
        gnGlobal_0071146C = 800;
        gnGlobal_00711470 = 600;
        gnUiRecordRow_007A5218 = 1;
        break;
    }
    gnAutomapWidth_007A5220 = gnGlobal_0071146C;
    gnAutomapHeight_007A521C = gnGlobal_00711470 - 40;
    gnGlobal_00711474 = gnGlobal_0071146C;
    sub_004F90A0(nResolution);
    sub_0045AEA0_SetPanelSlide(sub_0045AE90());
    sub_00457640(1);
    sub_00457440_Nop(nResolution);
    sub_004549B0(nResolution);
}

// 0x0044BB70
int __stdcall sub_0044BB70_StartGame()
{
    gnSubsystemActive_007A0458 = 1;
    return GAME_Initialize();
}

// 0x0044BC10
int __fastcall sub_0044BC10_RunClient(int nArg, const char* szAddress)
{
    CLIENT_Initialize(nArg, szAddress);
    sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
    return 1;
}

// 0x0044BE10
int __fastcall sub_0044BE10_GetRangeEnd(D2RangeStrc* pRange)
{
    return pRange->nLength + pRange->nStart;
}

// 0x0044BE80
void __fastcall sub_0044BE80(int bAlwaysRun)
{
    gdwGlobal_007A0660 = bAlwaysRun;
}

// 0x0044BEA0
void __fastcall sub_0044BEA0_SetValue(int nValue)
{
    gdwGlobal_007A0664 = nValue;
}

// 0x0044BEC0
unsigned short __cdecl sub_0044BEC0_GetClickFlags()
{
    int nFlags = 0;
    if (gdwGlobal_007A065C)
        nFlags = 8;
    if (gdwGlobal_007A0660)
        nFlags |= 8;
    if (gdwGlobal_007A0664)
        nFlags |= 4;
    return nFlags;
}

// 0x0044BEF0
void __cdecl sub_0044BEF0()
{
    gdwGlobal_007A0658 = 1;
}

// 0x0044BFE0
int __cdecl sub_0044BFE0()
{
    return gdwGlobal_007A066C != 0;
}

static unsigned short __cdecl sub_0044BEC0_GetClickFlags_static()
{
    int nFlags = 0;
    if (gdwGlobal_007A065C)
        nFlags = 8;
    if (gdwGlobal_007A0660)
        nFlags |= 8;
    if (gdwGlobal_007A0664)
        nFlags |= 4;
    return nFlags;
}

// 0x0044C000
void __cdecl sub_0044C000_StartClick()
{
    gdwGlobal_0070F234 = 8;
    if (gdwGlobal_007A061C && gdwGlobal_007A0650 && !gdwGlobal_007A0658)
    {
        gdwGlobal_007A066C = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nFlags = sub_0044BEC0_GetClickFlags_static();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            sub_00462D00(1, sub_00468730(), sub_00468740(), nFlags);
        }
    }
}

static __forceinline int CLIENT_GetClickFlags_inl()
{
    int nFlags = 0;
    if (gdwGlobal_007A065C)
        nFlags = 8;
    if (gdwGlobal_007A0660)
        nFlags |= 8;
    if (gdwGlobal_007A0664)
        nFlags |= 4;
    return nFlags;
}

// 0x0044C060
void __cdecl sub_0044C060_Refresh()
{
    gdwGlobal_0070F234 = 0x10;
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (gdwGlobal_007A061C)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
            sub_00462D00(2, sub_00468730(), sub_00468740(), CLIENT_GetClickFlags_inl());
    }
}

// 0x0044C0F0
void __stdcall sub_0044C0F0_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0044C060_Refresh();
}

// 0x0044C180
void __stdcall sub_0044C180_OnClickUp(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F2BC = 4;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (!gdwGlobal_007A061C || sub_0045AE90() == 3)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    int bLeftPanel = 0;
    if (sub_0045AE90() == 2 && nX > 0 && nX < gnGlobal_0071146C / 2 && nY > 0 && nY < gnGlobal_00711470 - 0x2F)
    {
        bLeftPanel = 1;
    }
    int bRightPanel = 0;
    if (sub_0045AE90() == 1 && nX > gnGlobal_0071146C / 2 && nX < gnGlobal_0071146C && nY > 0 && nY < gnAutomapHeight_007A521C)
    {
        bRightPanel = 1;
    }
    if (bLeftPanel || bRightPanel)
    {
        pMsg->bReturn = 0;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gdwGlobal_007A0654 = 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nFlags = sub_0044BEC0_GetClickFlags_static();
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        gdwGlobal_007A0654 = sub_00462D00(3, pMsg->nXpos, pMsg->nYpos, nFlags);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044C2C0
void __cdecl sub_0044C2C0()
{
    gdwGlobal_0070F2BC = 8;
    if (gdwGlobal_007A061C && gdwGlobal_007A0654)
    {
        gdwGlobal_007A0670 = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nFlags = CLIENT_GetClickFlags_inl();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
            sub_00462D00(4, sub_00468730(), sub_00468740(), nFlags);
    }
}

// 0x0044C750
void __cdecl sub_0044C750_InitRooms()
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(gpAct_007A0634); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (!(pRoom->dwFlags & 1))
        {
            sub_0046C460_PopulateRoom(pRoom);
            sub_00466820_SpawnRoomPresets(pRoom);
            sub_0046BE60_ApplyDenOfEvilRoom(pRoom);
            pRoom->dwFlags |= 1;
        }
    }
}

// 0x0044C790
void __cdecl sub_0044C790_Update()
{
    gdwTickCount_007A048C = GetTickCount();
    sub_0044C750_InitRooms();
    sub_00465AA0_ResetUnitTables();
    DUNGEON_AnimateTiles(sub_004646A0_GetPlayerRoom());
    sub_0046BEB0_UpdateTimers();
    sub_00470350_PreloadTick(1);
    if (ENVIRONMENT_UpdatePeriodOfDay(gpAct_007A0634, sub_004646A0_GetPlayerRoom()))
        sub_004646C0_UpdateObjectsForPeriod();
    DRLGACTIVATE_Update(DUNGEON_GetDrlgFromAct(gpAct_007A0634));
    sub_00459020_UpdateAutomapReveal();
    if (++gnTickCounter_007A0498 % 13 == 0)
        DUNGEON_UpdateAndFreeInactiveRooms(gpAct_007A0634);
}

// 0x0044C820
extern "C" void __cdecl sub_0044C820_ConfigureOrDefer()
{
    if(gContext != (Context*)0)
        sub_0061C240_Configure(gContext,sub_004646A0_GetAuxiliary(),5,0,1);
    else
        gDeferred=1;
}

// 0x0044C850
void __stdcall sub_0044C850(int nArg1, int nArg2, int nArg3)
{
    WINDOW_Destroy();
    D2GFX_Release();
}

// 0x0044C860
void __fastcall sub_0044C860_SetValue(int nValue)
{
    gdwGlobal_007A0674 = nValue;
}

// 0x0044C880
void __cdecl sub_0044C880()
{
    sub_00472BD0();
}

// 0x0044C890
void __cdecl sub_0044C890_ReleaseGameState()
{
    sub_00472BD0();
    sub_00476FB0();
    sub_004659C0_FreeAllUnits();
    if (gpAct_007A0634)
        DUNGEON_FreeAct(gpAct_007A0634);
    gpAct_007A0634 = 0;
    D2CMPSpriteFreeAsyncLoads();
    D2CMPTileFreeAsyncLoads();
    sub_00457420_FreeCaches(0);
    sub_00475FD0(gpView_007A0640);
    gpView_007A0640 = 0;
    sub_00456D80_ShutdownUI();
    sub_00473CF0_Nop();
    sub_004758D0_FreeAllLights();
    sub_004723C0();
    FOG_DestroyMemoryPoolSystem(gpMemPool_007A0488);
    memset(gaClientState_007A0480, 0, sizeof(gaClientState_007A0480));
    FOG_Free(gpAutomapRecord_007A0638, ".\\GAME\\Game.cpp", 0x599, 0);
}

// 0x0044CCE0
void __cdecl sub_0044CCE0_AverageCounters()
{
    const int nNow = gdwGlobal_007A048C;
    if ((unsigned int)(nNow - gdwGlobal_007A04B8) > 3000)
    {
        gdwGlobal_007A04A8 = gdwGlobal_007A04AC / 3;
        gdwGlobal_007A04B0 = gdwGlobal_007A04B4 / 3;
        gdwGlobal_007A04B8 = nNow;
        gdwGlobal_007A04AC = 0;
        gdwGlobal_007A04B4 = 0;
    }
}

// 0x0044CD70
void __cdecl sub_0044CD70_TickTimer()
{
    const unsigned long dwNow = GetTickCount();
    if (gdwNextTick_007A049C < dwNow)
    {
        sub_00477DD0();
        gdwLastTick_007A04A0 = dwNow;
        if (gpClientInfo_007A0438->wFlags & 4)
            gdwNextTick_007A049C = dwNow + 5000;
        else
            gdwNextTick_007A049C = dwNow + 5000;
    }
}

// 0x0044CE40
void __fastcall sub_0044CE40(int nValue)
{
    gdwGlobal_007A04FC = nValue;
}

// 0x0044CE90
void __cdecl sub_0044CE90_UpdateKeyState()
{
    if (sub_00469D90(0x24, 1))
    {
        const unsigned short wKey = sub_00469AA0(0x24, 1);
        if (wKey != 0xFFFF && (GetAsyncKeyState(wKey) & 0x8000))
        {
            gdwGlobal_007A0664 = 1;
            return;
        }
    }
    if (sub_00469D90(0x24, 0))
    {
        const unsigned short wKey = sub_00469AA0(0x24, 0);
        if (wKey != 0xFFFF && (GetAsyncKeyState(wKey) & 0x8000))
        {
            gdwGlobal_007A0664 = 1;
            return;
        }
    }
    gdwGlobal_007A0664 = 0;
}

// 0x0044D510
void __cdecl sub_0044D510()
{
    gdwGlobal_007A062C = 1;
}

// 0x0044D520
void __cdecl sub_0044D520()
{
    gdwGlobal_007A0620 = 1;
}

// 0x0044D530
void __fastcall sub_0044D530(int nValue)
{
    gdwGlobal_007A0628 = nValue;
}

// 0x0044D9F0
int __fastcall sub_0044D9F0_RunInitHandlers(void* pArg)
{
    gdwGlobal_0070F414 = 1;
    for (unsigned int i = 0; i < 52; i++)
    {
        if (gpfnInitHandlers_0070F488[i])
            gpfnInitHandlers_0070F488[i](pArg);
    }
    return gdwGlobal_0070F414;
}

// 0x0044DA40
void __cdecl sub_0044DA40()
{
    gdwGlobal_0070F2BC = 0x10;
    gdwGlobal_0070F234 = 0x10;
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0670 = 0;
    sub_00466FE0();
}

// 0x0044DA70
void __cdecl sub_0044DA70()
{
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0670 = 0;
}

// 0x0044DAD0
void __fastcall sub_0044DAD0(int nValue)
{
    gdwGlobal_007A04C8 = nValue;
}

// 0x0044DB40
void __fastcall sub_0044DB40(int nDelay)
{
    const unsigned long dwEnd = GetTickCount() + nDelay;
    if (dwEnd > gdwDelayEnd_007A04BC)
        gdwDelayEnd_007A04BC = dwEnd;
}

// 0x0044DC70
void __fastcall sub_0044DC70_SetDifficulty(unsigned char nDifficulty)
{
    gnDifficulty_007A060C = nDifficulty;
}

// 0x0044DC80
void __fastcall sub_0044DC80(unsigned char nValue)
{
    gdwGlobal_007A04F4 = nValue;
}

// 0x0044DC90
void __fastcall sub_0044DC90(int nValue)
{
    gdwGlobal_007A04F8 = nValue;
}

// 0x0044DCA0
int __cdecl sub_0044DCA0_GetGameType()
{
    return (gdwGlobal_007A0610 >= 2 && gdwGlobal_007A0610 <= 3) ? gdwGlobal_007A04F8 : 1;
}

// 0x0044DCD0
unsigned char __cdecl sub_0044DCD0_GetDifficulty()
{
    return gnDifficulty_007A060C;
}

// 0x0044DFF0
int __fastcall sub_0044DFF0_TimerExpired(D2LoadingTimerStrc* pTimer)
{
    if (pTimer->dwLength)
    {
        unsigned long dwNow = GetTickCount();
        unsigned long dwLeft;
        if (dwNow >= pTimer->dwStart + pTimer->dwLength)
        {
            pTimer->dwStart = 0;
            pTimer->dwLength = 0;
            dwLeft = 0;
        }
        else
        {
            dwLeft = pTimer->dwLength - (dwNow - pTimer->dwStart);
        }
        return dwLeft == 0;
    }
    return 1;
}

// 0x0044E040
int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc* pTimer)
{
    return !sub_0044DFF0_TimerExpired(pTimer);
}

// 0x0044E200
void __cdecl sub_0044E200_InitGameState()
{
    gdwGlobal_007A0684 = 0;
    gdwGlobal_007A0688 = 0;
    gdwGlobal_007A062C = 0;
    gdwGlobal_007A0628 = 0;
    gdwGlobal_007A0608 = 0;
    gnValue_007A0624 = 0;
    gdwGlobal_007A0664 = 0;
    memset(gaClientState_007A0480, 0, sizeof(gaClientState_007A0480));
    sub_00409DD0_InitPoolSystem(&gpMemPool_007A0488, "Client Pool System", 0x40000, 0x1000);
    sub_00463D90_SetPlayerUnit(0);
    sub_0044DBE0_ReadColorFlag();
    if (!gpView_007A0640)
        gpView_007A0640 = sub_00476B10();
    sub_0047F1D0_LoadResolution();
    sub_00456550_LoadLoadingScreen();
    sub_004565E0_Redraw(1);
    if (gdwGlobal_007A0610 == 7 || gdwGlobal_007A0610 == 9 || gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
        sub_004781D0(1);
    sub_005173D3_SetRecordHandler(sub_0044C850);
    sub_00476EA0_LoadPalShift();
    sub_00600B80();
    sub_00457300_InitGfxCaches(gpMemPool_007A0488, 1);
    gdwGlobal_007A0620 = sub_0044BBA0() != 0;
    gdwGlobal_007A0524 = GetTickCount();
    gdwGlobal_007A05F8 = GetTickCount();
    gpfnClientCallback_007A0484 = sub_0044C990;
    gdwGlobal_007A0498 = 0;
    gdwGlobal_007A0494 = 0;
    sub_004760A0_SetViewPos(gpView_007A0640, 0, 0);
    sub_0045AEA0_SetPanelSlide(0);
    gdwGlobal_007A04FC = 0;
    sub_0046D750();
    sub_00473CE0_Nop();
    sub_0046BF90_ResetLevelEffects();
    gpAutomapRecord_007A0638 = (D2AutomapRecordStrc*)FOG_Alloc(8, ".\\GAME\\Game.cpp", 0x546, 0);
    sub_00463C70();
    sub_00474790_ClearLightGrid();
    sub_00472320();
    sub_0047BD30_ResetChatHistory();
    gdwGlobal_007A0674 = 0;
    gdwGlobal_007A061C = 0;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00450ED0
D2SGameDataStrc* D2StormGameDataArrayStrc::sub_00450ED0_New()
{
    Reserve(1, 1);
    new (&f_8[f_4]) D2SGameDataStrc;
    return &f_8[f_4++];
}

// build: symbol ??_7?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@6B@ 0x006D5E84
// build: symbol ??_7?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@6B@ 0x006D5E98
// 0x00451170
D2StormExportTableSimpleStrc::TSExportTableSimple()
{
    m_sequence = ~(unsigned int)this & 0x0FFFFFFF;
    m_wrapper = 0;
}

// 0x004511F0
D2StormExportTableSyncStrc::TSExportTableSync()
{
    InitializeCriticalSection(&m_cs);
}

void __cdecl sub_00451290(); // 0x00451290

// 0x00451330
int __cdecl sub_00451330()
{
    if (gszLngPath_007A0710[0])
    {
        ghLngModule_007A070C = LoadLibraryExA(gszLngPath_007A0710, 0, 2);
        SRegSaveString("Diablo II", "LNG File", 0, gszLngPath_007A0710);
    }
    if (!ghLngModule_007A070C)
    {
        if (SRegLoadString("Diablo II", "LNG File", 0, gszLngPath_007A0710, sizeof(gszLngPath_007A0710)))
            ghLngModule_007A070C = LoadLibraryExA(gszLngPath_007A0710, 0, 2);
        if (!ghLngModule_007A070C)
        {
            ghLngModule_007A070C = LoadLibraryExA(gszLngFileName_006D5EE0, 0, 2);
            if (!ghLngModule_007A070C)
            {
                sub_0051740B_ErrorBox("Unable to start LNG manager.");
                return 0;
            }
        }
    }
    gxGlobal_007A0708 = LoadAcceleratorsA(ghLngModule_007A070C, (const char*)0x64);
    SErrRegisterMessageSource(0xFFF, ghLngModule_007A070C, 0);
    sub_005177B2_SetLoadStringFn(sub_004512C0_LoadString);
    return 1;
}

// 0x00451940
void __cdecl sub_00451940_InstallRecordHandler()
{
    gdwGlobal_007A2780 = 1;
    gpfnPrevHandler_007A2764 = sub_005173D3_SetRecordHandler(sub_00451920_RecordHandler);
}

// 0x00451970
void __cdecl sub_00451970()
{
    gdwGlobal_007A2788 = 1;
}

// 0x00451F10
int __cdecl sub_00451F10_PushRegisterState()
{
    return SMsgPushRegisterState(sub_004F59A0());
}

// 0x00451F50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00451F60
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x00451F80
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x00452130
void __cdecl sub_00452130_InitColors()
{
    sub_00483960();
    sub_00499E10();
    sub_00499E30_SetBlackColour();
    sub_004AB2F0();
    sub_00497250();
    sub_00497270();
    sub_004972B0();
    sub_00497290();
}

// 0x00452170
Unicode* __fastcall sub_00452170(Unicode* pText)
{
    return pText;
}

// 0x00452180
void __fastcall sub_00452180_StrToUpper(Unicode* pText)
{
    if (!pText)
        return;
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength; i++)
    {
        const unsigned short wChar = pText[i].wChar;
        pText[i].wChar = wChar >= 0x100 ? wChar : gwToUpperTable_00730578[wChar];
    }
}

// 0x00452520
void __fastcall sub_00452520_SetHoverLine(const Unicode* pText, int nColor)
{
    if (!pText)
    {
        gwszHoverLine_007A2D30[0].wChar = 0;
        return;
    }
    sub_005267E0(gwszHoverLine_007A2D30, pText);
    gnHoverTextColor_007A2F30 = nColor;
}

// 0x00453060
void __cdecl sub_00453060()
{
    if (!sub_00526800(gxGlobal_007A2C80))
        return;
    const int nWidth = sub_00501820(gxGlobal_007A2C80) + 8;
    const int nHeight = D2Win_10125() + 7;
    int nX = gdwGlobal_007A2D20 - (nWidth >> 1);
    int nY = gdwGlobal_007A2D24 + 2;
    if (nX < 0)
        nX = 0;
    if (nX + nWidth > gnGlobal_0071146C)
        nX = gnGlobal_0071146C - nWidth;
    if (nY - nHeight < 0)
        nY = nHeight;
    if (nY > gnGlobal_00711470 - 0x1F)
        nY = gnGlobal_00711470 - 0x1F;
    sub_00502320(gxGlobal_007A2C80, nX, nY - 2, 0, 1);
    memset(gxGlobal_007A2C80, 0, sizeof(gxGlobal_007A2C80));
}

// 0x004538D0
int __fastcall sub_004538D0(unsigned int nUIVar)
{
    D2_ASSERT(nUIVar < 0x26, 0xC34);
    return gaUIVarStates_007A27C0[nUIVar];
}

struct D2UnitStrc;

extern "C" void __cdecl sub_004A1730_ClearAllocation()
{
    sub_0049F960_Cleanup();
    Allocation* allocation=gAllocation;
    gCleanupState=0;
    if(allocation) {
        sub_006612A0_Release(allocation);
        gAllocation=(Allocation*)0;
    }
}

extern "C" int __cdecl sub_00486B00_Coordinate()
{
    if(!sub_0044DCC0_Mode())
        return gCoordinateOffset+gCoordinateBase-65;
    return gCoordinateOffset+gCoordinateBase-64;
}

#include "gen/data/Source/D2Client/GAME/Game_0044C880.inc"
