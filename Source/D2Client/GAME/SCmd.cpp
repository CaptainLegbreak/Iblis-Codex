#include "D2Client.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2UnitData.h"
struct D2ActiveRoomStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define SKILLSFLAGINDEX_PROGRESSIVE 2
#define STAT_HITPOINTS 6
struct D2SkillsTxt;
struct D2GameStrc;
struct D2RunesTxt;
struct D2CinematicPacketStrc;
struct D2GSPacketSrv45;
struct D2GSPacketSrv4F;
struct D2GSPacketSrv54;
struct D2GSPacketSrv5E;
struct D2GSPacketSrv66;
struct D2GSPacketSrv77;
struct D2GSPacketSrv89;
struct D2GSPacketSrv8F;
struct Unicode;
struct D2WinMsgStrc;
struct D2UnitFlagsStrc;
struct D2GSPacketSrv0C;
struct D2GSPacketSrv0E;
struct D2GSPacketSrv0F;
struct D2GSPacketSrv17;
struct D2GSPacketSrv4C;
struct D2GSPacketSrv4D;
struct D2GSPacketSrv67;
struct D2GSPacketSrv68;
struct D2GSPacketSrv69;
struct D2GSPacketSrv6A;
struct D2GSPacketSrv6B;
struct D2GSPacketSrv6C;
struct D2ClientPacket7Strc;
struct D2ClientPacket6Strc;
struct D2SaveChunkPacketStrc;
struct D2ErrorPacketStrc;
struct D2GSPacketSrv01;
struct D2GSPacketSrv03;
struct D2PlayerDataStrc;
struct D2GSPacketSrv09;
struct D2GSPacketSrv0A;
struct D2GSPacketSrv0B;
struct D2GSPacketSrv51;
struct D2ItemStatCostTxt;
struct D2GSPacketSrv0D;
struct D2ClientUnitUpdateStrc;
struct D2GSPacketSrv16;
struct D2GSPacketSrv93;
struct D2GSPacketSrv27Strc;
struct D2GSPacketSrv3E;
struct D2GSPacketSrv42Strc;
struct D2GSPacketSrv74Strc;
struct D2GSPacketSrv7DStrc;
struct D2GSPacketSrv82;
struct D2GSPacketSrvA8;
struct D2GSPacketSrvAA;
struct D2GSPacketSrv10;
struct D2UnitDropItemsPacketStrc;
struct D2GSPacketSrv11;
struct D2GSPacketSrv28;
struct D2GSPacketSrv62;
struct D2GSPacketSrvA4;
struct D2GSPacketSrv21;
struct D2SkillLevelEntryStrc;
struct D2GSPacketSrv94;
struct D2GSPacketSrv22;
struct D2GSPacketSrv23;
struct D2GSPacketSrv99;
struct D2PacketRecord11Strc;
struct D2UnitStatPacketStrc;
struct D2PlayerStatPacketStrc;
struct D2UnitStatPacket2Strc;
struct D2SkillPacketStrc;
struct D2Packet18RecordStrc;
struct D2Packet95RecordStrc;
struct D2Packet96RecordStrc;
struct D2PacketBufferStrc;
struct D2PacketTableEntryStrc;
struct D2GSPacketCoordinateStrc;
struct D2GSPacketSrv2C;
struct D2GSPacketSrv59;
struct D2GSPacketSrv5B;
struct D2GSPacketSrv5C;
struct D2GSPacketSrv92;
struct D2GSPacketSrv5F;
struct D2GSPacketSrv61;
struct D2GSPacketSrv65;
struct D2GSPacketSrv75;
struct D2GSPacketSrv79;
struct D2GSPacketSrv7A;
struct D2GSPacketSrv7B;
struct D2GSPacketSrv7E;
struct D2GSPacketSrv7F;
struct D2GSPacketSrv90;
struct D2GSPacketSrv8B;
struct D2GSPacketSrv8C;
struct D2GSPacketSrv8D;
struct D2GSPacketSrv8E;
struct D2GSPacketSrv9B;
struct D2GSPacketSrv97;
struct D2GSPacketSrvA6;
struct D2GSPacketSrvA7;
struct D2GSPacketSrvA9;
union D2SeedStrc;
struct D2GSPacketSrv73;
struct D2MissileStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwTime;
    int f_14;
    int nPointY;
};

struct D2UnitFlagsStrc
{
    char unk0x00[0xC8];
    unsigned int dwFlagEx;
};

struct D2GSPacketSrv0C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char unk0x06;
    unsigned char nHitClass;
    unsigned char nLife;
};

struct D2GSPacketSrv0E
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08[4];
};

struct D2GSPacketSrv0F
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nFlags;
    unsigned char nDestPosX[2];
    unsigned char nDestPosY[2];
    unsigned char unk0x0B;
    unsigned char nCurrentPosX[2];
    unsigned char nCurrentPosY[2];
};

struct D2GSPacketSrv17
{
    unsigned char nHeader;
    unsigned char unk0x01[5];
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08[2];
    unsigned char unk0x0A[2];
};

struct D2GSPacketSrv4C
{
    unsigned char nHeader;
    unsigned char unk0x01[5];
    unsigned char unk0x06[2];
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A[4];
};

struct D2GSPacketSrv4D
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02[4];
    unsigned char unk0x06[4];
    unsigned char unk0x0A;
    unsigned char unk0x0B[2];
    unsigned char unk0x0D[2];
};

struct D2GSPacketSrv67
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char nPathType;
    unsigned char nVelocity[2];
    unsigned char unk0x0F;
};

struct D2GSPacketSrv68
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B[4];
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char nPathType;
    unsigned char nVelocity[2];
    unsigned char unk0x14;
};

struct D2GSPacketSrv69
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06[2];
    unsigned char unk0x08[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
};

struct D2GSPacketSrv6A
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nTargetUnitType;
    unsigned char nTargetUnitGuid[4];
    unsigned char nDirection;
};

struct D2GSPacketSrv6B
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06[2];
    unsigned char unk0x08[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C[2];
    unsigned char unk0x0E[2];
};

struct D2GSPacketSrv6C
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07[4];
    unsigned char unk0x0B;
    unsigned char unk0x0C[2];
    unsigned char unk0x0E[2];
};

struct D2ClientPacket7Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
    unsigned char nValue0;
    unsigned char nValue1;
};

struct D2ClientPacket6Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
};
extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode); // 0x006CC4A4
extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC488
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
extern "C" __declspec(dllimport) int __stdcall TranslateAcceleratorA(void* hWnd, void* hAccTable, D2WinMsgStrc* pMsg); // 0x006CC4A8
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg); // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg); // 0x006CC478
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned int nMilliseconds); // 0x006CC258
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __cdecl sub_00466FE0(); // 0x00466FE0
int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0
void __cdecl sub_0044C060_Refresh(); // 0x0044C060
void __cdecl sub_00466FF0(); // 0x00466FF0
void __cdecl sub_004A01E0_ClearListFlags(); // 0x004A01E0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_004F59A0(); // 0x004F59A0
int __stdcall SMsgRegisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420BF0
int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C10
int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C30
int __stdcall SMsgRegisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C50
int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C70
int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C90
int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420CB0
int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420CD0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940
void __stdcall sub_005022F0_ShowPopUpText(const Unicode* wszText, int nX, int nY, int nArg); // 0x005022F0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall sub_004B1240_UsePacket7(D2ClientPacket7Strc* pPacket); // 0x004B1240
void __fastcall sub_0049F8C0_UsePacket6(D2ClientPacket6Strc* pPacket); // 0x0049F8C0
extern int gdwGlobal_007A0664; // 0x007A0664
extern int gdwGlobal_007A065C; // 0x007A065C
extern int gdwGlobal_007A0654; // 0x007A0654
extern int gdwGlobal_007A0670; // 0x007A0670
extern int gdwGlobal_007A0658; // 0x007A0658
extern void* gxGlobal_007A0708; // 0x007A0708
extern Unicode gxGlobal_007A2C80[80]; // 0x007A2C80

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00411020
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __cdecl sub_00477DA0(); // 0x00477DA0
void __fastcall sub_004A40D0_StorePacket52(void* pPacket); // 0x004A40D0

#pragma pack(push, 1)
struct D2SaveChunkPacketStrc
{
    unsigned char f_0;
    unsigned char nLength;
    unsigned char bFirst;
    unsigned int nTotal;
    unsigned char aData[1];
};

struct D2ErrorPacketStrc
{
    unsigned char f_0;
    int nCode;
};

#pragma pack(pop)

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __cdecl sub_0045C520_SaveCharFile(); // 0x0045C520
void __fastcall sub_0044E380_ShowLoadingMessage(int nError); // 0x0044E380
extern int gdwGlobal_007A0618; // 0x007A0618

#pragma pack(push, 1)
struct D2GSPacketSrv01
{
    unsigned char nHeader;
    unsigned char nDifficulty;
    unsigned int dwArenaFlags;
    unsigned char nExpansion;
    unsigned char nLadder;
};

struct D2GSPacketSrv03
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned int dwGameSeed;
    unsigned short nTownLevelId;
    unsigned int nObjectSeed;
};

#pragma pack(pop)

void __fastcall sub_0044DC70_SetDifficulty(unsigned char nDifficulty); // 0x0044DC70
void __fastcall sub_0044DC80(unsigned char nValue); // 0x0044DC80
void __fastcall sub_0044DC90(int nValue); // 0x0044DC90
void __fastcall sub_0047A9A0_SetClientFlags(int nFlags); // 0x0047A9A0
void __cdecl sub_00456970_InitUI(); // 0x00456970
void __fastcall sub_0044E100_LoadAct(unsigned char nAct, unsigned int dwGameSeed, unsigned int dwObjectSeed, int nTownLevelId); // 0x0044E100
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gnValue_007A0624; // 0x007A0624
void __fastcall sub_00470B10_PreloadForceAct(int nAct); // 0x00470B10

#pragma pack(push, 1)
struct D2GSPacketSrv09
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char unk0x06;
    unsigned short nPosX;
    unsigned short nPosY;
};

struct D2GSPacketSrv0A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

struct D2GSPacketSrv0B
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

struct D2GSPacketSrv51
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nObject;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char unk0x0C;
    unsigned char nInteractType;
};

#pragma pack(pop)

void __cdecl sub_0044C880(); // 0x0044C880
extern int gdwGlobal_007A0620; // 0x007A0620
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __cdecl sub_0044C870(); // 0x0044C870
D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0
void __fastcall sub_00470B70_ResetMonsterModeGfx(D2UnitStrc* pUnit); // 0x00470B70
D2UnitStrc* __fastcall sub_00466300_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType); // 0x00466300
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_00463D90(int nArg); // 0x00463D90
void __cdecl sub_0046F360_Empty(); // 0x0046F360

enum D2C_F23Constants
{
    ITEMSTATCOSTFLAGINDEX_SIGNED = 1,
    STAT_ID_END = 0x1FF,
    STATE_ID_END = 0xFF,
};

struct D2GSPacketSrv0D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nHitClass;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char nHitType;
    unsigned char nUnitLifePct;
};

struct D2ClientUnitUpdateStrc
{
    unsigned char nUnitType;
    unsigned char nUnitGUID[4];
    unsigned char nX[2];
    unsigned char nY[2];
};

struct D2GSPacketSrv16
{
    unsigned char nHeader;
    unsigned char nSize[2];
    unsigned char nNumUpdates;
    D2ClientUnitUpdateStrc unitUpdate[1];
};

struct D2GSPacketSrv93
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
};

struct D2GSPacketSrv27Strc
{
    int nData00;
    int nData04;
    int nData08;
    int nData0C;
    int nData10;
    int f_14;
    int nData18;
    int nData1C;
    int nData20;
    int nData24;
};

struct D2GSPacketSrv3E
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned char pBuffer[32];
};

struct D2GSPacketSrv42Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
};

struct D2GSPacketSrv74Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
};

struct D2GSPacketSrv7DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
    unsigned char unk0x0D;
    unsigned char unk0x0E;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char unk0x11;
};

struct D2GSPacketSrv82
{
    unsigned char nHeader;
    unsigned char dwOwnerGUID[4];
    char szOwnerName[16];
    unsigned char dwPortalGUID0[4];
    unsigned char dwPortalGUID1[4];
};

struct D2GSPacketSrvA8
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitId[4];
    unsigned char nSize;
    unsigned char nState;
    unsigned char pStream[1];
};

struct D2GSPacketSrvAA
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitId[4];
    unsigned char nSize;
    unsigned char pStream[1];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern void* gpGlobal_007BB384; // 0x007BB384
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __cdecl sub_0044DA30(); // 0x0044DA30
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_00462F60(D2GSPacketSrv74Strc* pPacket); // 0x00462F60
int __cdecl sub_00463DF0(); // 0x00463DF0
void __fastcall sub_0047A270_SetPortalIds(int nOwnerGUID, int nPortalGUID0, int nPortalGUID1); // 0x0047A270
void __fastcall sub_0047A690(int nUnitGUID, unsigned char nLifePct); // 0x0047A690
void __fastcall sub_004A1600(D2GSPacketSrv27Strc* pPacket); // 0x004A1600
void __fastcall sub_004BDFE0_SetObjectName(D2UnitStrc* pUnit, const char* szName); // 0x004BDFE0
void __fastcall sub_004C1F30(unsigned int nA, unsigned char nB, unsigned int nC, unsigned int nD, unsigned short nE); // 0x004C1F30
void __fastcall sub_004C2050(D2GSPacketSrv42Strc* pPacket); // 0x004C2050
void __fastcall sub_004C2270(D2GSPacketSrv7DStrc* pPacket); // 0x004C2270
void __fastcall sub_004C7990(D2UnitStrc* pUnit, int nA, int nB, unsigned char nC); // 0x004C7990
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D9B20_BeginState(D2UnitStrc* pUnit, int nState); // 0x004D9B20
int __fastcall sub_004D9D70_SetStateStat(D2UnitStrc* pUnit, int nPrev, int nState, int nStatId, int nValue, int nLayer); // 0x004D9D70
void __fastcall sub_004D9E60_StartClientState(D2UnitStrc* pUnit, int nState); // 0x004D9E60
D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620

struct D2GSPacketSrv10
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nFlags;
    unsigned char nTargetType;
    unsigned char dwTargetGUID[4];
    unsigned char nCurrentPosX[2];
    unsigned char nCurrentPosY[2];
};

struct D2UnitDropItemsPacketStrc
{
    char nHeader;
    char bActive;
    char nUnitId[4];
    char nOtherUnitId[4];
};

unsigned char __stdcall sub_00462EE0_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
unsigned char* __fastcall sub_004AC740_GetMonsterBytes(D2UnitStrc* pUnit); // 0x004AC740
void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005449E0

#pragma pack(push, 1)
struct D2GSPacketSrv11
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short wOverlay;
};

struct D2GSPacketSrv28
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nArg;
    unsigned char pBuffer[1];
};

struct D2GSPacketSrv62
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
};

struct D2GSPacketSrvA4
{
    unsigned char nHeader;
    unsigned short wMonsterId;
};

struct D2GSPacketSrv21
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char bRemove;
    int nUnitId;
    unsigned short wSkillId;
    unsigned char nSkillLevel;
};

struct D2SkillLevelEntryStrc
{
    unsigned short wSkillId;
    unsigned char nSkillLevel;
};

struct D2GSPacketSrv94
{
    unsigned char nHeader;
    unsigned char nCount;
    int nUnitId;
    D2SkillLevelEntryStrc pEntries[1];
};

struct D2GSPacketSrv22
{
    unsigned char nHeader;
    unsigned char unk0x01[2];
    int nUnitId;
    unsigned short wSkillId;
    unsigned char nQuantity;
    unsigned char unk0x0A;
    unsigned char bSkip;
};

struct D2GSPacketSrv23
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int nUnitId;
    unsigned char bLeft;
    unsigned short wSkillId;
    int nOwnerGUID;
};

struct D2GSPacketSrv99
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short f_6;
    unsigned char nArg3;
    unsigned char nTargetType;
    int f_A;
    unsigned short wArg5;
};

#pragma pack(pop)

void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg); // 0x00464E50
void __fastcall sub_004B6DD0_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg); // 0x004B6DD0
void __fastcall sub_004B5320_OnUnitRemoved(unsigned char nUnitType, int nUnitId); // 0x004B5320
void __fastcall sub_004B2620(const unsigned char* pData); // 0x004B2620
void __fastcall sub_0046F870_LoadMonsterCofs(int nMonsterId, int bLoadNow); // 0x0046F870
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
extern "C" void __cdecl sub_004AA8F0_ClearValue7C0C3C(); // 0x004AA8F0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity); // 0x00645120
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50
int __fastcall sub_004CA200_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5); // 0x004CA200
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648C30
void __fastcall sub_0044DB40(int nDelay); // 0x0044DB40
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634

#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    int nUnitId;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
};

struct D2UnitStatPacketStrc
{
    unsigned char nHeader;
    unsigned char nStat;
    int nUnitId;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
    };
};

struct D2PlayerStatPacketStrc
{
    unsigned char nHeader;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
        struct
        {
            unsigned char nStat;
            union
            {
                unsigned char nByte2;
                unsigned short nWord2;
                unsigned int nDword2;
            };
        };
    };
};

struct D2UnitStatPacket2Strc
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nStat;
    int nValue;
};

#pragma pack(pop)

void __fastcall sub_004C1BC0(D2PacketRecord11Strc* pPacket, int nArg); // 0x004C1BC0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall sub_004C1C10(D2UnitStrc* pUnit); // 0x004C1C10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

#pragma pack(push, 1)
struct D2SkillPacketStrc
{
    unsigned char nHeader;
    unsigned char nMode;
    unsigned short wSkillId;
    unsigned short f_4;
    unsigned char nUnitType;
    unsigned int dwUnitId;
    unsigned char nTargetType;
    unsigned int dwTargetId;
    int nX;
    int nY;
};

#pragma pack(pop)

void __fastcall sub_004C6930_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode); // 0x004C6930
void __fastcall sub_004C6AC0_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nMode);

#pragma pack(push, 1)
struct D2Packet18RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned char nValue07;
    unsigned char nValue08;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2Packet95RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2Packet96RecordStrc
{
    unsigned char nHeader;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

#pragma pack(pop)

typedef void (__fastcall* D2PacketHandlerFn)(unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    D2PacketHandlerFn pfnHandler;
    int nSize;
    void* f_8;
};
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(D2UnitStrc* pUnit); // 0x00464770
void __fastcall sub_004647A0_SetPacketBuffer(D2UnitStrc* pUnit, D2PacketBufferStrc* pBuffer); // 0x004647A0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern D2PacketTableEntryStrc gtPacketTable_007114D0[]; // 0x007114D0
extern int gnPacketBytes_007A6AF4; // 0x007A6AF4
extern int gnPacketBlocks_007A6AFC; // 0x007A6AFC
extern int gnLargePacketBlocks_007A6B04; // 0x007A6B04
extern unsigned char gnLastPacketId_007A5234; // 0x007A5234
extern "C" const char szSCmdCppFile_006D69E4[];
extern int gnGlobal_007A5230;

#pragma pack(push, 1)
struct D2GSPacketCoordinateStrc
{
#ifdef MOVED_TEST
    unsigned char movedPrefix[4];
#endif
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short f_6;
    unsigned char unk0x08[2];
    unsigned char nArg3;
    unsigned short wArg4;
    unsigned short wArg5;
    unsigned short wArg6;
};

#pragma pack(pop)

int __fastcall sub_004CA230_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6);
extern "C" unsigned int __cdecl strlen(const char* szString);

#pragma pack(push, 1)
struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short nSoundEvent;
};

struct D2GSPacketSrv59
{
    unsigned char nHeader;
    unsigned int dwGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nPosX;
    unsigned short nPosY;
};

struct D2GSPacketSrv5B
{
    unsigned char nHeader;
    unsigned short nPacketLen;
    int nUnitGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nLevel;
    unsigned short nPartyId;
    unsigned short unk0x1C;
    unsigned short nPartyFlags;
    unsigned short unk0x20;
    char szText[1];
};

struct D2GSPacketSrv5C
{
    unsigned char nHeader;
    int dwPlayerGUID;
};

struct D2GSPacketSrv92
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};

struct D2GSPacketSrv5F
{
    unsigned char nHeader;
    int nPortalFlags;
};

struct D2GSPacketSrv61
{
    unsigned char nHeader;
    unsigned char unk0x01;
};

struct D2GSPacketSrv65
{
    unsigned char nHeader;
    int dwUnitId;
    unsigned short unk0x05;
};

struct D2GSPacketSrv75
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned short nPartyId;
    unsigned short nLevel;
    unsigned short nFlags;
    unsigned short unk0x0B;
};

struct D2GSPacketSrv79
{
    unsigned char nHeader;
    unsigned char nOwnerGUID;
    int dwGold;
};

struct D2GSPacketSrv7A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned short unk0x03;
    int unk0x05;
    int unk0x09;
};

struct D2GSPacketSrv7B
{
    unsigned char nHeader;
    unsigned char nSlot;
    unsigned short wSkill;
    int nItemGUID;
};

struct D2GSPacketSrv7E
{
    unsigned char nHeader;
    unsigned char unk0x001[4];
};

struct D2GSPacketSrv7F
{
    unsigned char nHeader;
    unsigned char bIsPlayer;
    unsigned short nLifePercentage;
    int nUnitGUID;
    unsigned short nLevelId;
};

struct D2GSPacketSrv90
{
    unsigned char nHeader;
    int dwGUID;
    int dwPosX;
    int dwPosY;
};

struct D2GSPacketSrv8B
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char bParty;
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    int dwPlayerGUID1;
    int dwPlayerGUID2;
    unsigned short nFlags;
};

struct D2GSPacketSrv8D
{
    unsigned char nHeader;
    int dwPlayerGUID;
    unsigned short nPartyGUID;
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    int dwPlayerGUID;
    int dwCorpseGUID;
};

struct D2GSPacketSrv9B
{
    unsigned char nHeader;
    unsigned short unk0x01;
    unsigned short unk0x03;
};

struct D2GSPacketSrv97
{
    unsigned char nHeader;
};

struct D2GSPacketSrvA6
{
    unsigned char nHeader;
    unsigned char bSkip;
    unsigned char unk0x02[2];
    unsigned short nRecordId;
    unsigned char pRecord[1];
};

struct D2GSPacketSrvA7
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};

struct D2GSPacketSrvA9
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};

#pragma pack(pop)

void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0
D2UnitStrc* __fastcall sub_00466200_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName); // 0x00466200
void __fastcall sub_0047A6F0_AddRosterUnit(int nUnitId, int nClassId, const char* szName, unsigned short wLevel, unsigned short wPartyId, int nUnused, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildTag, const char* szGuildName); // 0x0047A6F0
void __fastcall sub_0047A8B0_RemoveRosterUnit(int nPlayerGUID); // 0x0047A8B0
void __fastcall sub_004C23E0_RemoveEquippedItems(D2UnitStrc* pUnit); // 0x004C23E0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags); // 0x006221E0
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket); // 0x004B9320
void __cdecl sub_0047F1D0_LoadResolution(); // 0x0047F1D0
void __fastcall sub_00479B10_SetKillCount(int nUnitId, unsigned short nValue); // 0x00479B10
void __fastcall sub_0047A850_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags); // 0x0047A850
void __fastcall sub_004B90D0(int nGold, unsigned char nOwner); // 0x004B90D0
void __fastcall sub_00478B10_SetRosterEntry(int nKey, int nArg, int nType, int nValue); // 0x00478B10
void __fastcall sub_00478C90_DropPetEntry(int nKey); // 0x00478C90
void __fastcall sub_004AA0C0_SetSlot(int nSlot, int nValueA, int nValueB, int nValueC); // 0x004AA0C0
void __fastcall sub_0046F310_LoadGlobalHashedFile(unsigned char nAct); // 0x0046F310
void __fastcall sub_0047A0D0_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId); // 0x0047A0D0
void __fastcall sub_00479010_UpdatePetLife(int nUnitId, int nLifePercent, unsigned short nArg); // 0x00479010
void __fastcall sub_0047A100_SetPosition(int nUnitId, int nX, int nY); // 0x0047A100
void __fastcall sub_0047A350_SetPartyFlags(int nUnitId, unsigned char nFlags); // 0x0047A350
void __fastcall sub_0047A370_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags); // 0x0047A370
void __fastcall sub_0047A330_SetPartyId(int nUnitId, unsigned short wPartyId); // 0x0047A330
void __fastcall sub_0047A3D0_AddCorpse(int nUnitId, int nCorpseId); // 0x0047A3D0
void __fastcall sub_0047A490_DropCorpseEntry(int nUnitId, int nCorpseId); // 0x0047A490
void __fastcall sub_004B6980_SetNpcMenuState(unsigned short wValue, int nValue); // 0x004B6980
extern "C" void __cdecl sub_0048A700(); // 0x0048A700
void __stdcall DATATBLS_AddOrChangeRunesTxtRecord(int nRecordId, D2RunesTxt* pRecord); // 0x00639CC0
void __fastcall sub_004D9F40_EndClientState(D2UnitStrc* pUnit, int nState); // 0x004D9F40
void __fastcall sub_004D9C30_EndState(D2UnitStrc* pUnit, int nState); // 0x004D9C30
void __cdecl sub_00473CA0_Empty(); // 0x00473CA0
void __cdecl sub_004B3290_ResetSlots(); // 0x004B3290
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket); // 0x004B92B0

struct D2GSPacketSrv73
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char nMissileId[2];
    unsigned char nX[4];
    unsigned char nY[4];
    unsigned char nFirstX[4];
    unsigned char nFirstY[4];
    unsigned char nCurrentFrame[2];
    unsigned char nUnitType;
    unsigned char nUnitGUID[4];
    unsigned char nLevel;
    unsigned char nPierce;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId); // 0x00621CC0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __fastcall sub_004B8CF0(const D2GSPacketSrv77* pPacket); // 0x004B8CF0
void __fastcall sub_004B9330_UniqueEvent(const D2GSPacketSrv89* pPacket); // 0x004B9330
void __fastcall sub_0044CDB0_StorePong(const D2GSPacketSrv8F* pPacket); // 0x0044CDB0

int gdwGlobal_007A2D20; // 0x007A2D20

int gdwGlobal_007A2D24; // 0x007A2D24

int gdwGlobal_007A2D28; // 0x007A2D28

// build: context sub_0044C5E0_ActivateMsg
void __stdcall sub_0044C5E0_ActivateMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F7E0 = pMsg->wParam;
    if (pMsg->wParam)
    {
        sub_00455F20(0xD, 1, 0);
        gdwGlobal_007A0664 = 0;
        sub_00466FE0();
        sub_004FB130_SetActiveState(0);
        pMsg->bUseResult = 0;
        return;
    }

    if (sub_00469D90(0x22, 1) && !(GetAsyncKeyState(sub_00469AA0(0x22, 1)) & 0x8000))
    {
        gdwGlobal_007A065C = 0;
    }

    if (gdwGlobal_0070F234 != 0x10)
    {
        sub_0044C060_Refresh();
    }

    if (gdwGlobal_0070F2BC != 0x10)
    {
        gdwGlobal_0070F2BC = 0x10;
        gdwGlobal_007A0654 = 0;
        gdwGlobal_007A0670 = 1;
        gdwGlobal_007A0658 = 0;
        sub_00466FF0();
    }

    pMsg->bUseResult = 0;
}

// 0x00451A90
void __stdcall sub_00451A90_QuitMsg(SMSGHANDLER_PARAMS* pMsg)
{
    PostQuitMessage(0);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
}

// 0x00451AD0
void __stdcall sub_00451AD0_DefWindowProcMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bUseResult = 1;
    pMsg->lResult = DefWindowProcA(pMsg->hWnd, pMsg->uMessage, pMsg->wParam, pMsg->lParam);
}

// 0x00451B00
void __stdcall sub_00451B00_CloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
}

// 0x00451BB0
int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int))
{
    int nCount = 0;
    int bContinue = 1;
    int nResult;
    D2WinMsgStrc msg;

    while (bContinue)
    {
        if (PeekMessageA(&msg, 0, 0, 0, 0))
        {
            bContinue = GetMessageA(&msg, 0, 0, 0);
            if (bContinue && gxGlobal_007A0708)
            {
                TranslateAcceleratorA((void*)sub_004F59A0(), gxGlobal_007A0708, &msg);
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        else
        {
            if (pfnIdle)
            {
                nResult = pfnIdle(nCount++);
                if (nResult)
                {
                    break;
                }
            }

            if (!gdwGlobal_0070F7E0 && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 8)
            {
                Sleep(10);
            }
        }
    }

    return bContinue ? nResult : 1;
}

// 0x00451C70
void __fastcall sub_00451C70_RegisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler)
{
    D2_ASSERT(hWnd, 0x110);

    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x114);
        SMsgRegisterMessage(hWnd, nId, pfnHandler);
        return;
    case 1:
        SMsgRegisterCommand(hWnd, nId, pfnHandler);
        return;
    case 2:
        SMsgRegisterKeyUp(hWnd, nId, pfnHandler);
        return;
    case 3:
        SMsgRegisterKeyDown(hWnd, nId, pfnHandler);
        return;
    }
}

// 0x00451D10
void __fastcall sub_00451D10_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler)
{
    D2_ASSERT(hWnd, 0x131);

    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x135);
        SMsgUnregisterMessage(hWnd, nId, pfnHandler);
        return;
    case 1:
        SMsgUnregisterCommand(hWnd, nId, pfnHandler);
        return;
    case 2:
        SMsgUnregisterKeyUp(hWnd, nId, pfnHandler);
        return;
    case 3:
        SMsgUnregisterKeyDown(hWnd, nId, pfnHandler);
        return;
    }
}

// 0x00452090
void __stdcall sub_00452090_ResetMsg(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004A01E0_ClearListFlags();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00452300
Unicode* __fastcall sub_00452300_StripStringAndNextChar(Unicode* pString)
{
    D2_ASSERT(sub_00526800(pString) < 500, 0x37F);

    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_FindSubstring(pString, pPattern);
    while (pFound && pFound[nLength].wChar)
    {
        memmove(pFound, &pFound[nLength + 1], sizeof(Unicode) * (sub_00526800(pFound) - nLength));
        pFound = sub_00526940_FindSubstring(pString, pPattern);
    }

    return pString;
}

// 0x004524D0
void __fastcall sub_004524D0_SetPopUpText(const Unicode* wszText, int nA, int nB, int nC)
{
    gxGlobal_007A2C80[0].wChar = 0;
    if (wszText)
    {
        sub_005267E0(gxGlobal_007A2C80, wszText);
        gdwGlobal_007A2D20 = nA;
        gdwGlobal_007A2D24 = nB;
        gdwGlobal_007A2D28 = nC;
    }
}

// 0x00452510
void __stdcall sub_00452510_ShowPopUpText(const Unicode* wszText, int nX, int nY, int nArg)
{
    sub_005022F0_ShowPopUpText(wszText, nX, nY, nArg);
}

// 0x0045C430
void __fastcall sub_0045C430_SetUnitFlagEx(D2UnitFlagsStrc* pUnit, unsigned int dwFlag, int bSet)
{
    if (pUnit)
    {
        if (bSet)
            pUnit->dwFlagEx |= dwFlag;
        else
            pUnit->dwFlagEx &= ~dwFlag;
    }
}

// 0x0045CC70
void __fastcall sub_0045CC70_UnitPacket0C(D2UnitStrc* pUnit, const D2GSPacketSrv0C* pPacket)
{
    int args[7] = {};
    args[0] = pPacket->nHitClass;
    args[1] = pPacket->nLife;
    sub_00480C10_UnitEvent(pPacket->unk0x06, pUnit, args, 1);
}

// 0x0045CD10
void __fastcall sub_0045CD10_UnitPacket0E(D2UnitStrc* pUnit, const D2GSPacketSrv0E* pPacket)
{
    int args[7];
    args[0] = pPacket->unk0x07;
    args[1] = *(const int*)pPacket->unk0x08;
    sub_00480C10_UnitEvent(pPacket->unk0x06, pUnit, args, 1);
}

// 0x0045CD40
void __fastcall sub_0045CD40(D2UnitStrc* pUnit, const D2GSPacketSrv0F* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nDestPosX;
    args[1] = *(const unsigned short*)pPacket->nDestPosY;
    args[2] = pPacket->unk0x0B;
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->nCurrentPosX, *(const unsigned short*)pPacket->nCurrentPosY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->nFlags, pUnit, args, 1);
}

// 0x0045CDE0
void __fastcall sub_0045CDE0_UnitPacket67(D2UnitStrc* pUnit, const D2GSPacketSrv67* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nX;
    args[1] = *(const unsigned short*)pPacket->nY;
    args[2] = pPacket->unk0x0A;
    args[3] = pPacket->nPathType;
    args[4] = *(const short*)pPacket->nVelocity;
    args[5] = pPacket->unk0x0F;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CE30
void __fastcall sub_0045CE30_UnitPacket68(D2UnitStrc* pUnit, const D2GSPacketSrv68* pPacket)
{
    int args[7];
    args[0] = pPacket->unk0x0A;
    args[1] = *(const int*)pPacket->unk0x0B;
    args[2] = pPacket->unk0x0F;
    args[3] = pPacket->nPathType;
    args[4] = *(const short*)pPacket->nVelocity;
    args[5] = pPacket->unk0x14;
    args[6] = pPacket->unk0x10;
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->nX, *(const unsigned short*)pPacket->nY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CEA0
void __fastcall sub_0045CEA0_UnitPacket69(D2UnitStrc* pUnit, const D2GSPacketSrv69* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->unk0x06;
    args[1] = *(const unsigned short*)pPacket->unk0x08;
    args[2] = pPacket->unk0x0A;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CEF0
void __fastcall sub_0045CEF0_UnitPacket6A(D2UnitStrc* pUnit, const D2GSPacketSrv6A* pPacket)
{
    int args[7];
    args[0] = pPacket->nTargetUnitType;
    args[1] = *(const int*)pPacket->nTargetUnitGuid;
    args[2] = pPacket->nDirection;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CF40
void __fastcall sub_0045CF40_UnitPacket6B(D2UnitStrc* pUnit, const D2GSPacketSrv6B* pPacket)
{
    int args[7];
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->unk0x0C, *(const unsigned short*)pPacket->unk0x0E, 0, 0, 0);
    args[0] = *(const unsigned short*)pPacket->unk0x06;
    args[1] = *(const unsigned short*)pPacket->unk0x08;
    args[2] = pPacket->unk0x0A;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CFB0
void __fastcall sub_0045CFB0_UnitPacket6C(D2UnitStrc* pUnit, const D2GSPacketSrv6C* pPacket)
{
    int args[7];
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->unk0x0C, *(const unsigned short*)pPacket->unk0x0E, 0, 0, 0);
    args[0] = pPacket->unk0x06;
    args[1] = *(const int*)pPacket->unk0x07;
    args[2] = pPacket->unk0x0B;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045D260
void __fastcall sub_0045D260_UnitPacket17(D2UnitStrc* pUnit, const D2GSPacketSrv17* pPacket)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
    {
        D2_ASSERT(pUnit, 0x841);

        int args[7];
        unsigned short pos[2];
        pos[0] = *(const unsigned short*)*(const unsigned short*)pPacket->unk0x08;
        pos[1] = *(const unsigned short*)*(const unsigned short*)pPacket->unk0x0A;
        args[0] = pPacket->unk0x06 >> 1;
        args[1] = (int)pos;
        sub_00480C10_UnitEvent(pPacket->unk0x07, pUnit, args, 1);
    }
}

// 0x0045DE50
void __fastcall sub_0045DE50_CopyPacket7(const D2ClientPacket7Strc* pPacket)
{
    D2ClientPacket7Strc tPacket = *pPacket;
    sub_004B1240_UsePacket7(&tPacket);
}

// 0x0045DF00
void __fastcall sub_0045DF00_UnitPacket4C(D2UnitStrc* pUnit, const D2GSPacketSrv4C* pPacket)
{
    if (pUnit)
    {
        int args[7] = {};
        args[0] = *(const unsigned short*)pPacket->unk0x06;
        args[2] = pPacket->unk0x09;
        args[3] = *(const int*)pPacket->unk0x0A;
        args[4] = pPacket->unk0x08;
        args[1] = -1;
        sub_00480C10_UnitEvent(0x16, pUnit, args, 1);
    }
}

// 0x0045DF60
void __fastcall sub_0045DF60_UnitPacket4D(D2UnitStrc* pUnit, const D2GSPacketSrv4D* pPacket)
{
    if (pUnit)
    {
        int args[7] = {};
        args[0] = *(const int*)pPacket->unk0x06;
        args[2] = *(const unsigned short*)pPacket->unk0x0B;
        args[3] = *(const unsigned short*)pPacket->unk0x0D;
        args[4] = pPacket->unk0x0A;
        args[1] = -1;
        sub_00480C10_UnitEvent(0x15, pUnit, args, 1);
    }
}

// 0x0045E050
void __fastcall sub_0045E050_CopyPacket6(const D2ClientPacket6Strc* pPacket)
{
    D2ClientPacket6Strc tPacket = *pPacket;
    sub_0049F8C0_UsePacket6(&tPacket);
}

// 0x0045C300
unsigned int __fastcall sub_0045C300_ReadVarUnsigned(D2BitBufferStrc* pBuffer)
{
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 8);
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 0x10);
    return sub_00411020_ReadBits(pBuffer, 0x20);
}

// 0x0045C340
unsigned int __fastcall sub_0045C340_ReadVarUnsigned16(D2BitBufferStrc* pBuffer)
{
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 8);
    return sub_00411020_ReadBits(pBuffer, 0x10);
}

// 0x0045C4E0
int __cdecl sub_0045C4E0_GetSkillsTxtRecordCount()
{
    return sgptDataTables->nSkillsTxtRecordCount;
}

// 0x0045C900
void __fastcall sub_0045C900_GamePacketIgnored(void* pPacket)
{
}

// 0x0045C910
void __fastcall sub_0045C910_GamePacket02(void* pPacket)
{
    sub_00477DA0();
}

// 0x0045C920
int __cdecl sub_0045C920_GetPlayerActNo()
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
        return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x527);
    exit(-1);
}

// 0x0045C960
int __fastcall sub_0045C960_GetUnitActNo(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
        return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x538);
    exit(-1);
}

// 0x0045CC00
void __fastcall sub_0045CC00_GamePacket52(void* pPacket)
{
    sub_004A40D0_StorePacket52(pPacket);
}

static unsigned char* gpSaveBuffer_007A5224; // 0x007A5224

static unsigned int gnSaveBufferSize_007A5228; // 0x007A5228

// 0x0045C620
static void sub_0045C620_ReceiveSaveChunk(D2SaveChunkPacketStrc* pPacket)
{
    if (gpSaveBuffer_007A5224 && pPacket->bFirst)
    {
        FOG_Free(gpSaveBuffer_007A5224, ".\\GAME\\SCmd.cpp", 0x5B, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }

    if (!gpSaveBuffer_007A5224)
        gpSaveBuffer_007A5224 = (unsigned char*)FOG_Alloc(pPacket->nTotal, ".\\GAME\\SCmd.cpp", 0x62, 0);

    unsigned int nSize = gnSaveBufferSize_007A5228;
    unsigned char* pDest = gpSaveBuffer_007A5224 + nSize;
    const unsigned char* pSource = pPacket->aData;
    for (int i = 0; i < pPacket->nLength; i++)
        pDest[i] = pSource[i];

    gnSaveBufferSize_007A5228 += pPacket->nLength;
    if (pPacket->nTotal == gnSaveBufferSize_007A5228)
    {
        sub_0045C520_SaveCharFile();
        FOG_Free(gpSaveBuffer_007A5224, ".\\GAME\\SCmd.cpp", 0x71, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }
}

static void sub_0045C6D0_HandleErrorPacket(D2ErrorPacketStrc* pPacket)
{
    switch (pPacket->nCode)
    {
    case 1: sub_0044E380_ShowLoadingMessage(0); return;
    case 2: sub_0044E380_ShowLoadingMessage(1); return;
    case 3: sub_0044E380_ShowLoadingMessage(2); return;
    case 4: sub_0044E380_ShowLoadingMessage(3); return;
    case 5: sub_0044E380_ShowLoadingMessage(4); return;
    case 6: sub_0044E380_ShowLoadingMessage(5); return;
    case 7: sub_0044E380_ShowLoadingMessage(0x0A); return;
    case 8: sub_0044E380_ShowLoadingMessage(0x0B); return;
    case 9: sub_0044E380_ShowLoadingMessage(0x0C); return;
    case 10: sub_0044E380_ShowLoadingMessage(0x0D); return;
    case 11: sub_0044E380_ShowLoadingMessage(0x0E); return;
    case 12: sub_0044E380_ShowLoadingMessage(0x0F); return;
    case 13: sub_0044E380_ShowLoadingMessage(0x10); return;
    case 14: sub_0044E380_ShowLoadingMessage(0x11); return;
    case 15: sub_0044E380_ShowLoadingMessage(0x12); return;
    case 16: sub_0044E380_ShowLoadingMessage(0x13); return;
    case 17: sub_0044E380_ShowLoadingMessage(0x14); return;
    case 18: sub_0044E380_ShowLoadingMessage(0x15); return;
    case 19: sub_0044E380_ShowLoadingMessage(0x16); return;
    case 20: sub_0044E380_ShowLoadingMessage(0x17); return;
    case 21: sub_0044E380_ShowLoadingMessage(0x18); return;
    case 24: sub_0044E380_ShowLoadingMessage(0x1A); return;
    case 23: sub_0044E380_ShowLoadingMessage(0x19); return;
    case 26: sub_0044E380_ShowLoadingMessage(0x1C); return;
    case 25: sub_0044E380_ShowLoadingMessage(0x1B); return;
    }
    sub_0044E380_ShowLoadingMessage(9);
}

void __fastcall sub_0045C850_HandleSystemPacket(unsigned char* pPacket, int nSize)
{
    if (nSize == -1)
        return;

    switch (pPacket[0])
    {
    case 0xAF:
        gdwGlobal_007A0618 = 1;
        return;
    case 0xB0:
        gdwGlobal_007A0618 = 0;
        return;
    case 0xB3:
        sub_0045C620_ReceiveSaveChunk((D2SaveChunkPacketStrc*)pPacket);
        return;
    case 0xB4:
        sub_0045C6D0_HandleErrorPacket((D2ErrorPacketStrc*)pPacket);
        return;
    }
}

// 0x0045C8B0
void __fastcall sub_0045C8B0_GamePacket01_GameFlags(D2GSPacketSrv01* pPacket)
{
    const unsigned int dwArenaFlags = pPacket->dwArenaFlags;
    sub_0044DC70_SetDifficulty(pPacket->nDifficulty);
    sub_0044DC80(pPacket->nExpansion);
    sub_0044DC90(pPacket->nLadder);
    sub_0047A9A0_SetClientFlags(dwArenaFlags);
    sub_00456970_InitUI();
}

// 0x0045C8E0
void __fastcall sub_0045C8E0_GamePacket03_LoadAct(D2GSPacketSrv03* pPacket)
{
    sub_0044E100_LoadAct(pPacket->nAct, pPacket->dwGameSeed, pPacket->nObjectSeed, pPacket->nTownLevelId);
}

// 0x0045C9A0
void __fastcall sub_0045C9A0_GamePacket04_LoadDone(void* pPacket)
{
    gdwGlobal_007A061C = 1;
    gnValue_007A0624 = 0;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        sub_00470B10_PreloadForceAct(DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)));
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x527);
        exit(-1);
    }
}

int gdwGlobal_007A0524; // 0x007A0524

// 0x0045CA30
void __fastcall sub_0045CA30_GamePacket05_UnloadDone(void* pPacket)
{
    sub_0044C880();
    sub_00409B80(0);
    gdwGlobal_007A061C = 0;
    gnValue_007A0624 = 1;
    gdwGlobal_007A0524 = GetTickCount();
}

// 0x0045CA60
void __fastcall sub_0045CA60_GamePacket06_LogoutDone(void* pPacket)
{
    if (gdwGlobal_007A0610 == 7 || gdwGlobal_007A0610 == 9)
    {
        if (!sub_0044C870())
            sub_0044E380_ShowLoadingMessage(8);
    }
    if ((gdwGlobal_007A0610 == 2 || gdwGlobal_007A0610 == 3) && gdwGlobal_007A061C)
        sub_0044E380_ShowLoadingMessage(7);
    gdwGlobal_007A0620 = 1;
}

// 0x0045CB90
void __fastcall sub_0045CB90_GamePacket09_AssignWarp(D2GSPacketSrv09* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    const unsigned short nX = pPacket->nPosX;
    const unsigned short nY = pPacket->nPosY;
    D2UnitStrc* pUnit = sub_004661C0_AllocClientUnit(nUnitGUID, pPacket->unk0x06, nX, nY, pPacket->nUnitType, 0);
    if (pUnit && pUnit->dwUnitType == 1)
        sub_00470B70_ResetMonsterModeGfx(pUnit);
}

// 0x0045CBD0
void __fastcall sub_0045CBD0_GamePacket51_AssignObject(D2GSPacketSrv51* pPacket)
{
    sub_00466300_CreateObjectUnit(pPacket->dwUnitGUID, pPacket->nObject, pPacket->nPosX, pPacket->nPosY, pPacket->nUnitType, 0, pPacket->unk0x0C, pPacket->nInteractType);
}

// 0x0045CC10
void __fastcall sub_0045CC10_GamePacket0A_RemoveObject(D2GSPacketSrv0A* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    if (pPacket->nUnitType == 1 && nUnitGUID == sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 1))
        return;
    sub_00465EE0_RemoveClientSideUnit(nUnitGUID, pPacket->nUnitType);
}

// 0x0045CC50
void __fastcall sub_0045CC50_GamePacket0B_Handshake(D2GSPacketSrv0B* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    D2UnitStrc* pUnit = sub_00463990(nUnitGUID, pPacket->nUnitType);
    if (pUnit)
        sub_00463D90((int)pUnit);
    sub_0046F360_Empty();
}

// 0x0045CCC0
void __fastcall sub_0045CCC0(D2UnitStrc* pUnit, const D2GSPacketSrv0D* pPacket)
{
    const int nUnitGUID = *(const int*)pPacket->dwUnitGUID;
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nX;
    args[1] = *(const unsigned short*)pPacket->nY;
    args[2] = pPacket->nHitType;
    sub_00480C10_UnitEvent(pPacket->nHitClass, pUnit, args, 1);
    if (pPacket->nUnitType == UNIT_PLAYER)
    {
        sub_0047A690(nUnitGUID, pPacket->nUnitLifePct);
    }
}

// 0x0045D2E0
void __fastcall sub_0045D2E0_Packet16(const D2GSPacketSrv16* pPacket)
{
    D2_ASSERT(pPacket->nNumUpdates, 2133);

    const D2ClientUnitUpdateStrc* pUpdate = pPacket->unitUpdate;
    for (int i = 0; i < pPacket->nNumUpdates; ++i)
    {
        unsigned short nX = *(const unsigned short*)pUpdate->nX;
        unsigned short nY = *(const unsigned short*)pUpdate->nY;
        D2UnitStrc* pUnit = sub_00463990(*(const int*)pUpdate->nUnitGUID, pUpdate->nUnitType);
        if (pUnit)
        {
            sub_004804E0_SetPosition(pUnit, nX, nY, 0, 0, 0);
        }
        ++pUpdate;
    }
}

// 0x0045DD10
void __fastcall sub_0045DD10_Packet93(const D2GSPacketSrv93* pPacket)
{
    const int nUnitGUID = *(const int*)pPacket->nUnitGUID;
    int nValue = pPacket->unk0x05;
    if (nValue > 0x80)
        nValue -= 0x100;
    const int nB = pPacket->unk0x06;
    const char nC = pPacket->unk0x07;

    D2UnitStrc* pUnit = sub_00463990(nUnitGUID, UNIT_PLAYER);
    if (pUnit)
    {
        sub_004C7990(pUnit, nValue, nB, nC);
    }
}

// 0x0045E0A0
void __fastcall sub_0045E0A0_Packet27(const D2GSPacketSrv27Strc* pPacket)
{
    D2GSPacketSrv27Strc tPacket = *pPacket;
    sub_004A1600(&tPacket);
}

// 0x0045E130
void __fastcall sub_0045E130_Packet3E(D2GSPacketSrv3E* pPacket)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pBuffer, pPacket->nSize - 2);

    unsigned int nA;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nA = sub_00411020_ReadBits(&tBuffer, 8);
    else if (!sub_00411020_ReadBits(&tBuffer, 1))
        nA = sub_00411020_ReadBits(&tBuffer, 16);
    else
        nA = sub_00411020_ReadBits(&tBuffer, 32);

    const unsigned char nB = sub_00411020_ReadBits(&tBuffer, 1);
    const unsigned int nC = sub_00411020_ReadBits(&tBuffer, 9);

    unsigned int nD;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nD = sub_00411020_ReadBits(&tBuffer, 8);
    else if (!sub_00411020_ReadBits(&tBuffer, 1))
        nD = sub_00411020_ReadBits(&tBuffer, 16);
    else
        nD = sub_00411020_ReadBits(&tBuffer, 32);

    unsigned short nE;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nE = sub_00411020_ReadBits(&tBuffer, 8);
    else
        nE = sub_00411020_ReadBits(&tBuffer, 16);

    sub_004C1F30(nA, nB, nC, nD, nE);
}

// 0x0045E270
void __fastcall sub_0045E270_Packet42(const D2GSPacketSrv42Strc* pPacket)
{
    D2GSPacketSrv42Strc tPacket = *pPacket;
    sub_004C2050(&tPacket);
}

// 0x0045E7B0
void __fastcall sub_0045E7B0_Packet74(const D2GSPacketSrv74Strc* pPacket)
{
    D2GSPacketSrv74Strc tPacket = *pPacket;
    sub_00462F60(&tPacket);
}

// 0x0045E930
void __fastcall sub_0045E930_Packet7D(const D2GSPacketSrv7DStrc* pPacket)
{
    D2GSPacketSrv7DStrc tPacket = *pPacket;
    sub_004C2270(&tPacket);
}

// 0x0045E9D0
void __fastcall sub_0045E9D0_Packet82(const D2GSPacketSrv82* pPacket)
{
    const int nOwnerGUID = *(const int*)pPacket->dwOwnerGUID;
    const int nPortalGUID0 = *(const int*)pPacket->dwPortalGUID0;
    const int nPortalGUID1 = *(const int*)pPacket->dwPortalGUID1;

    D2UnitStrc* pPortal = sub_00463990(nPortalGUID0, UNIT_OBJECT);
    if (pPortal)
    {
        sub_004BDFE0_SetObjectName(pPortal, pPacket->szOwnerName);
    }

    if (nPortalGUID1 != -1)
    {
        pPortal = sub_00463990(nPortalGUID1, UNIT_OBJECT);
        if (pPortal)
        {
            sub_004BDFE0_SetObjectName(pPortal, pPacket->szOwnerName);
        }
        sub_0047A270_SetPortalIds(nOwnerGUID, nPortalGUID0, nPortalGUID1);
    }
}

// 0x0045EE20
void __fastcall sub_0045EE20_PacketA8(D2GSPacketSrvA8* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(*(const int*)pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    const int nState = pPacket->nState;
    sub_004D9B20_BeginState(pUnit, nState);

    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pStream, pPacket->nSize - 8);
    int nPrev = 0;
    int nStatId = sub_00411020_ReadBits(&tBuffer, 9);
    while (nStatId < STAT_ID_END)
    {
        if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            return;
        D2ItemStatCostTxt* pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        if (!pItemStatCostTxtRecord)
            return;
        if (pItemStatCostTxtRecord->nSendBits <= 0)
            return;

        int nLayer = 0;
        if (pItemStatCostTxtRecord->nSendParamBits > 0)
            nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendParamBits);

        int nValue;
        if (pItemStatCostTxtRecord->nSendBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SIGNED & 7])
            nValue = BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendBits);
        else
            nValue = sub_00411020_ReadBits(&tBuffer, pItemStatCostTxtRecord->nSendBits);

        nPrev = sub_004D9D70_SetStateStat(pUnit, nPrev, nState, nStatId, nValue, nLayer);
        nStatId = sub_00411020_ReadBits(&tBuffer, 9);
    }

    sub_004D9E60_StartClientState(pUnit, nState);
}

// 0x0045EFA0
void __fastcall sub_0045EFA0_PacketAA(D2GSPacketSrvAA* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(*(const int*)pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pStream, pPacket->nSize - 7);
    int nState = sub_00411020_ReadBits(&tBuffer, 8);
    while (nState < STATE_ID_END)
    {
        sub_004D9B20_BeginState(pUnit, nState);
        if (sub_00411020_ReadBits(&tBuffer, 1))
        {
            int nPrev = 0;
            int nStatId = sub_00411020_ReadBits(&tBuffer, 9);
            while (nStatId < STAT_ID_END)
            {
                if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
                    return;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
                if (!pItemStatCostTxtRecord)
                    return;
                if (pItemStatCostTxtRecord->nSendBits <= 0)
                    return;

                int nLayer = 0;
                if (pItemStatCostTxtRecord->nSendParamBits > 0)
                    nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendParamBits);

                int nValue;
                if (pItemStatCostTxtRecord->nSendBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SIGNED & 7])
                    nValue = BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendBits);
                else
                    nValue = sub_00411020_ReadBits(&tBuffer, pItemStatCostTxtRecord->nSendBits);

                nPrev = sub_004D9D70_SetStateStat(pUnit, nPrev, nState, nStatId, nValue, nLayer);
                nStatId = sub_00411020_ReadBits(&tBuffer, 9);
            }
        }
        sub_004D9E60_StartClientState(pUnit, nState);
        nState = sub_00411020_ReadBits(&tBuffer, 8);
    }
}

// 0x004689D0
void __cdecl sub_004689D0_ShowHelpOnce()
{
    if (sub_0044DA30())
        return;
    if (sub_00463DF0())
        return;

    sub_00455F20(0x21, 2, 0);
    unsigned long dwValue;
    if (!SRegLoadValue("Diablo II", "Help Menu", 1, &dwValue) || !dwValue)
    {
        dwValue = 1;
        SRegSaveValue("Diablo II", "Help Menu", 1, dwValue);
    }
}

// 0x0046B4A0
void __cdecl sub_0046B4A0_RequestNearMonster()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    D2UnitStrc* pMonster = sub_0065A620_FindUnitInAdjacentRooms(pRoom, UNIT_MONSTER, 0x20E);
    if (!pMonster)
        return;

    const int nX = CLIENTS_GetUnitX(pMonster);
    const int nY = CLIENTS_GetUnitY(pMonster);
    sub_004CDB40_SubmitRequest(pPlayer, 0x25E, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pPlayer, 0x25B, nX, nY, 0, 1);
    pMonster->dwFlagEx |= 0x40000;
}

// 0x00476E30
void __cdecl sub_00476E30_LoadGreenBlood()
{
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpGlobal_007BB384 = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile);
    }
}

// 0x0045CD90
void __fastcall sub_0045CD90_UnitPacket10(D2UnitStrc* pUnit, const D2GSPacketSrv10* pPacket)
{
    int args[7];
    args[0] = pPacket->nTargetType;
    args[1] = *(const int*)pPacket->dwTargetGUID;
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->nCurrentPosX, *(const unsigned short*)pPacket->nCurrentPosY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->nFlags, pUnit, args, 1);
}

// 0x0045D010
void __fastcall sub_0045D010_UnitPacket6D(D2UnitStrc* pUnit, const unsigned char* p)
{
    if (!pUnit)
        return;
    if (!p)
        return;

    const unsigned short nX = *(const unsigned short*)(p + 5);
    const unsigned short nY = *(const unsigned short*)(p + 7);
    int args[7] = { nX, nY, p[9], 2, 0, 4, 0 };
    sub_004804E0_SetPosition(pUnit, nX, nY, 0, 0, 0);
    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    sub_00480C10_UnitEvent(7, pUnit, args, 1);
}

// 0x0045E400
void __fastcall sub_0045E400_Packet57(const unsigned char* p)
{
    const int nId = *(const int*)(p + 1);
    const unsigned short n6 = *(const unsigned short*)(p + 6);
    const unsigned short n8 = *(const unsigned short*)(p + 8);
    const unsigned short nA = *(const unsigned short*)(p + 0xA);
    const unsigned short nC = *(const unsigned short*)(p + 0xC);
    if (p[5] == 1)
    {
        D2UnitStrc* pUnit = sub_00463990(nId, 1);
        if (pUnit)
        {
            sub_004AC780_SetMonsterWord(pUnit, n6);
            unsigned char* pBytes = sub_004AC740_GetMonsterBytes(pUnit);
            pBytes[0] = (unsigned char)n8;
            pBytes[1] = (unsigned char)(n8 >> 8);
            pBytes[2] = (unsigned char)nA;
            if (nC)
            {
                sub_004AC810_ToggleMonsterFlag(pUnit, 4, 1);
            }
            sub_004AC810_ToggleMonsterFlag(pUnit, 8, 1);
            sub_004AD020_RefreshMonster(pUnit);
        }
    }
}

// 0x00462F60
void __fastcall sub_00462F60_UnitDropItems(D2UnitDropItemsPacketStrc* pPacket)
{
    if (!pPacket->bActive)
        return;
    D2UnitStrc* pUnit = sub_00463990(*(int*)pPacket->nUnitId, 0);
    if (!pUnit)
        return;
    if (!sub_00464820_IsDeadOrDying(pUnit))
        sub_00480E70_SetUnitMode(pUnit, 0);
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        D2UnitStrc* pOther = sub_00463990(*(int*)pPacket->nOtherUnitId, 0);
        if (!pOther)
            return;
        D2DynamicPathStrc* pPath = pOther->pDynamicPath;
        PATH_SetMoveTestCollisionMask(pPath, 0);
        sub_00649190_SetPathMode(pOther, 5);
        D2_ASSERT(sub_00650BE0_PlaceUnit(pPath, pOther, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)), 0xABA);
        PATH_SetDirection(pOther->pDynamicPath, PATH_GetDirection(pUnit->pDynamicPath));
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            pItem = INVENTORY_UnitIsItem(pItem);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            sub_0046F280_ClearGfxBytes(pUnit, sub_00462EE0_GetItemComponent(pUnit, pItem));
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xAC8);
            D2_ASSERT(pRemoved == pItem, 0xAC9);
            sub_004C0EC0_UpdateItemLink(pItem, pUnit, 0, 0);
            sub_0063BE30(pInventory, ITEMS_GetBodyLocation(pItem));
            sub_00470610_Refresh(pUnit, 0);
            const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
            const int nUnitId = !pItem ? -1 : pItem->dwUnitId;
            sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
        }
        pItem = pNext;
    }
}

// 0x0045D0A0
void __fastcall sub_0045D0A0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0B0
void __fastcall sub_0045D0B0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0C0
void __fastcall sub_0045D0C0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0D0
void __fastcall sub_0045D0D0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0E0
void __fastcall sub_0045D0E0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D130
void __fastcall sub_0045D130_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D140
void __fastcall sub_0045D140_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D150
void __fastcall sub_0045D150_PacketNop(const unsigned char* pPacket)
{
}

// 0x00581A10
void __fastcall sub_00581A10_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    QUESTS_ObjectEvents(pGame, pObject);
}

// 0x0045D0F0
void __fastcall sub_0045D0F0_Packet11(const D2GSPacketSrv11* pPacket)
{
    const int nUnitType = pPacket->nUnitType;
    const int nUnitId = pPacket->nUnitId;
    const unsigned short wOverlay = pPacket->wOverlay;
    D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
    if (pUnit && wOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        sub_00464E50_SetOverlayWithSound(pUnit, wOverlay, 0);
    }
}

// 0x0045D370
void __fastcall sub_0045D370_Packet28(const D2GSPacketSrv28* pPacket)
{
    sub_004B6DD0_NpcInteractPacket(pPacket->nUnitType, pPacket->nUnitId, (unsigned char*)pPacket->pBuffer, pPacket->nArg);
}

// 0x0045D390
void __fastcall sub_0045D390_Packet62(const D2GSPacketSrv62* pPacket)
{
    sub_004B5320_OnUnitRemoved(pPacket->nUnitType, pPacket->nUnitId);
}

// 0x0045D3A0
void __fastcall sub_0045D3A0_Packet29(const unsigned char* pPacket)
{
    sub_004B2620(pPacket + 1);
}

// 0x0045D760
void __fastcall sub_0045D760_PacketA4(const D2GSPacketSrvA4* pPacket)
{
    const unsigned short wMonsterId = pPacket->wMonsterId;
    if (wMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        sub_0046F870_LoadMonsterCofs(wMonsterId, 0);
    }
}

// 0x0045DCD0
void __fastcall sub_0045DCD0_Packet21_AssignSkill(const D2GSPacketSrv21* pPacket)
{
    const unsigned short wSkillId = pPacket->wSkillId;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        SKILLS_AssignSkill(pUnit, wSkillId, pPacket->nSkillLevel, pPacket->bRemove, ".\\GAME\\SCmd.cpp", 2700);
        sub_004AA8F0_ClearValue7C0C3C();
    }
}

// 0x0045DD60
void __fastcall sub_0045DD60_Packet94_AssignSkills(const D2GSPacketSrv94* pPacket)
{
    const int nUnitId = pPacket->nUnitId;
    const unsigned char nCount = pPacket->nCount;
    const D2SkillLevelEntryStrc* pEntry = pPacket->pEntries;
    D2UnitStrc* pUnit = sub_00463990(nUnitId, 0);
    if (pUnit)
    {
        for (int i = 0; i < nCount; ++i)
        {
            SKILLS_AssignSkill(pUnit, pEntry->wSkillId, pEntry->nSkillLevel, 0, ".\\GAME\\SCmd.cpp", 2743);
            ++pEntry;
        }
    }
}

// 0x0045DDB0
void __fastcall sub_0045DDB0_Packet22_SetSkillQuantity(const D2GSPacketSrv22* pPacket)
{
    if (pPacket->bSkip)
    {
        return;
    }
    const unsigned short wSkillId = pPacket->wSkillId;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, wSkillId, -1);
        D2_ASSERT(pSkill, 2774);
        SKILLS_SetQuantity(pSkill, pPacket->nQuantity);
    }
}

// 0x0045DE10
void __fastcall sub_0045DE10_Packet23_SetActiveSkill(const D2GSPacketSrv23* pPacket)
{
    const unsigned short wSkillId = pPacket->wSkillId;
    const int nOwnerGUID = pPacket->nOwnerGUID;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        if (pPacket->bLeft)
        {
            SKILLS_SetLeftActiveSkill(pUnit, wSkillId, nOwnerGUID);
        }
        else
        {
            SKILLS_SetRightActiveSkill(pUnit, wSkillId, nOwnerGUID);
        }
    }
}

// 0x0045DE80
void __fastcall sub_0045DE80_Packet99(const D2GSPacketSrv99* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        D2UnitStrc* pTarget = sub_00463990(pPacket->f_A, pPacket->nTargetType);
        if (pTarget)
        {
            sub_004CA200_Forward(pUnit, pPacket->f_6, pPacket->nArg3, (int)pTarget, pPacket->wArg5);
        }
    }
}

// 0x0045D160
void __fastcall sub_0045D160(const unsigned char* pPacket)
{
    const unsigned short nX = *(const unsigned short*)(pPacket + 6);
    const unsigned short nY = *(const unsigned short*)(pPacket + 8);
    D2UnitStrc* pUnit = sub_00463990(*(const int*)(pPacket + 2), pPacket[1]);
    if (!pUnit)
        return;
    sub_004654C0_SetUnitPosition(pUnit, nX, nY, pPacket[0xA]);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpGlobal_007A0634;
        if (pUnit->pDynamicPath)
        {
            if (pUnit->dwUnitType == 0)
            {
                D2Common_10214(pUnit);
                PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x1C09);
            }
            else if (pUnit->dwUnitType == 1 && !MONSTERS_IsDead(pUnit))
            {
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x100);
            }
        }
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            D2_ASSERT(!sub_0061AB30(UNITS_GetRoom(pUnit)), 0x81E);
            sub_0044DB40(3000);
        }
    }
    else
    {
        D2_ASSERT(pRoom, 0x538);
    }
}

static void sub_0045D3B0_SendUnitStatus(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2PacketRecord11Strc tPacket;
        tPacket.nHeader = 0x47;
        tPacket.nUnitType = (unsigned char)pUnit->dwUnitType;
        tPacket.nUnitId = pUnit->dwUnitId;
        sub_004C1BC0(&tPacket, 0);
    }
}

// 0x0045D4B0
static void __stdcall sub_0045D4B0_OnStatChanged(int nValue, int nStat, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    switch (nStat)
    {
    case 6:
        if (nValue && pUnit->dwAnimMode == 0x11)
        {
            sub_00480E70_SetUnitMode(pUnit, 5);
            sub_004647D0(pUnit);
        }
        break;

    case 0xC:
        sub_0045D3B0_SendUnitStatus(sub_00463DD0_GetPlayerUnit());
        if (pUnit != sub_00463DD0_GetPlayerUnit())
            break;
        sub_0045D3E0(pUnit);

    case 0:
    case 2:
        sub_004C1C10(pUnit);
        break;
    }
}

void __fastcall sub_0045D540_HandleUnitStatPacket(D2UnitStatPacketStrc* pPacket)
{
    int bAdd = 0;
    int nValue;
    switch (pPacket->nHeader)
    {
    case 0x9E:
        nValue = pPacket->nByte;
        break;
    case 0xA0:
        nValue = pPacket->nDword;
        break;
    case 0xA1:
        nValue = pPacket->nByte;
        bAdd = 1;
        break;
    case 0xA2:
        bAdd = 1;

    case 0x9F:
        nValue = pPacket->nWord;
        break;
    default:
        return;
    }

    const int nStat = pPacket->nStat;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 1);
    if (!pUnit)
        return;

    if (nStat == 0xC)
        sub_0045D3B0_SendUnitStatus(pUnit);

    if (bAdd)
        STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
    else
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x0045D780
void __fastcall sub_0045D780_HandlePlayerStatPacket(D2PlayerStatPacketStrc* pPacket)
{
    const unsigned char nHeader = pPacket->nHeader;
    int nValue = 0;
    int nStat = -1;
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x9AA);

    switch (nHeader)
    {
    case 0x19:
        nStat = 0xE;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1A:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1B:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nWord;
        break;
    case 0x1C:
        nValue = pPacket->nDword;
        nStat = 0xD;
        break;
    case 0x1D:
        nValue = pPacket->nByte2;
        nStat = pPacket->nStat;
        break;
    case 0x1E:
        nValue = pPacket->nWord2;
        nStat = pPacket->nStat;
        break;
    case 0x1F:
        nValue = pPacket->nDword2;
        nStat = pPacket->nStat;
        break;
    }

    STATLIST_SetUnitStat(pPlayer, nStat, nValue, 0);
    sub_0045D4B0_OnStatChanged(nValue, nStat, pPlayer);
}

// 0x0045D880
void __fastcall sub_0045D880_HandleUnitStatPacket2(D2UnitStatPacket2Strc* pPacket)
{
    const int nValue = pPacket->nValue;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        const int nStat = pPacket->nStat;
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
        sub_0045D4B0_OnStatChanged(nValue, nStat, pUnit);
    }
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0045D5E0
void __fastcall sub_0045D5E0_SkillPacket(D2SkillPacketStrc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pTarget = sub_00463990(pPacket->dwTargetId, pPacket->nTargetType);
    const int nX = pPacket->nX;
    const int nY = pPacket->nY;
    const short nSkillId = pPacket->wSkillId;
    const short nSkillLevel = pPacket->f_4;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PROGRESSIVE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE & 7])
    {
        sub_004C6AC0_DoSkill(pUnit, pTarget, nSkillId, nSkillLevel, nX, nY, pPacket->nMode);
    }
    else
    {
        sub_004C6930_DoSkillPrgFunc(pUnit, pTarget, nSkillId, nSkillLevel, nX, nY, pPacket->nMode);
    }
}

// 0x0045D8C0
static __declspec(noinline) void __stdcall sub_0045D8C0_AddSignedByteOffsets(short nBaseY, short* pX, short* pY, short nBaseX, unsigned char nDY, unsigned char nDX)
{
    int nOffsetX = nDX;
    int nOffsetY = nDY;
    if (nOffsetX > 0x80)
        nOffsetX -= 0x100;

    if (nOffsetY > 0x80)
        nOffsetY -= 0x100;

    *pX = nBaseX + nOffsetX;
    *pY = nBaseY + nOffsetY;
}

void __fastcall sub_U05_Emit_0045D8C0(unsigned char* pBytes, short* pBase, short* pOut)
{
    sub_0045D8C0_AddSignedByteOffsets(pBase[1], &pOut[0], &pOut[1], pBase[0], pBytes[1], pBytes[0]);
    sub_0045D8C0_AddSignedByteOffsets(pBase[3], &pOut[2], &pOut[3], pBase[2], pBytes[3], pBytes[2]);
}

int gnGlobal_007A5230; // 0x007A5230

// 0x0045D900
static void sub_0045D900_ReadPacket18(unsigned char* pData, D2Packet18RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xF);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nValue07 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nValue08 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045DA90
static void sub_0045DA90_ReadPacket95(unsigned char* pData, D2Packet95RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xD);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045DBE0
static void sub_0045DBE0_ReadPacket96(unsigned char* pData, D2Packet96RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 9);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045DC50
void __fastcall sub_0045DC50_HandlePacket96(unsigned char* pPacket)
{
    D2Packet96RecordStrc tRecord;
    sub_0045DBE0_ReadPacket96(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
}

// 0x0045F610
static D2PacketBufferStrc* sub_0045F610_GrowPacketBuffer(D2UnitStrc* pUnit)
{
    if (!gnGlobal_007A5230)
    {
        for (int i = 0; i < 0xAF; ++i)
        {
            if (gtPacketTable_007114D0[i].f_8 && gtPacketTable_007114D0[i].nSize > gnGlobal_007A5230)
            {
                gnGlobal_007A5230 = gtPacketTable_007114D0[i].nSize;
            }
        }
        gnGlobal_007A5230 += 5;
    }
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer)
    {
        pBuffer = (D2PacketBufferStrc*)FOG_Alloc(0x10, ".\\GAME\\SCmd.cpp", 0x1266, 0);
        memset(pBuffer, 0, 0x10);
        sub_004647A0_SetPacketBuffer(pUnit, pBuffer);
    }
    int nNewMax = pBuffer->nMax + 5;
    unsigned char* pData = (unsigned char*)FOG_Alloc(gnGlobal_007A5230 * nNewMax, ".\\GAME\\SCmd.cpp", 0x126B, 0);
    memset(pData, 0, gnGlobal_007A5230 * nNewMax);
    if (pBuffer->pData)
    {
        memcpy(pData, pBuffer->pData, pBuffer->nMax * gnGlobal_007A5230);
        FOG_Free(pBuffer->pData, ".\\GAME\\SCmd.cpp", 0x126F, 0);
    }
    pBuffer->nMax = nNewMax;
    pBuffer->pData = pData;
    return pBuffer;
}

// 0x0045F730
static void __stdcall sub_0045F730_QueuePacket(unsigned char* pPacket, int nLength, D2UnitStrc* pUnit)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer || pBuffer->nCount + 1 == pBuffer->nMax)
    {
        pBuffer = sub_0045F610_GrowPacketBuffer(pUnit);
    }
    D2_ASSERT(nLength <= gnGlobal_007A5230, 0x127F);
    memcpy(pBuffer->pData + pBuffer->nCount * gnGlobal_007A5230, pPacket, nLength);
    ++pBuffer->nCount;
}

void __fastcall sub_0045F7B0_ProcessPackets(unsigned char* pData, int nSize)
{
    if (nSize == -1)
    {
        return;
    }
    int nRemaining = nSize;
    unsigned char* pPacket = pData;
    GetTickCount();
    if (nSize > 500)
    {
        ++gnLargePacketBlocks_007A6B04;
    }
    while (nRemaining > 0)
    {
        unsigned char nId = *pPacket;
        int nPacketSize;
        if (!sub_0052B920(pPacket, nSize, &nPacketSize))
        {
            return;
        }
        unsigned short nLength = (unsigned short)nPacketSize;
        D2_ASSERT(nId < 0xAF, 0x1449);
        D2PacketTableEntryStrc* pEntry = &gtPacketTable_007114D0[nId];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT(nLength == pEntry->nSize, 0x1450);
        }
        if (pEntry->nSize == -1 || nLength == pEntry->nSize)
        {
            if (pEntry->f_8)
            {
                int nUnitId;
                int nUnitType;
                switch (nId)
                {
                case 0x67: case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D:
                    nUnitId = *(int*)(pPacket + 1);
                    nUnitType = 1;
                    break;
                default:
                    nUnitId = *(int*)(pPacket + 2);
                    nUnitType = pPacket[1];
                    break;
                }
                D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
                if (pUnit)
                {
                    sub_0045F730_QueuePacket(pPacket, nLength, pUnit);
                }
            }
            switch (nId)
            {
            case 0x0D:
                if (pPacket[1] == 1)
                {
                    sub_00463990(*(int*)(pPacket + 2), 1);
                }
                break;
            case 0x18:
            {
                D2Packet18RecordStrc tRecord;
                sub_0045D900_ReadPacket18(pPacket, &tRecord);
                break;
            }
            case 0x95:
            {
                D2Packet95RecordStrc tRecord;
                sub_0045DA90_ReadPacket95(pPacket, &tRecord);
                break;
            }
            case 0x96:
            {
                D2Packet96RecordStrc tRecord;
                sub_0045DBE0_ReadPacket96(pPacket, &tRecord);
                break;
            }
            }
            if (pEntry->pfnHandler)
            {
                pEntry->pfnHandler(pPacket);
            }
        }
        gnPacketBytes_007A6AF4 += nLength;
        nRemaining -= nLength;
        pPacket += nLength;
        gnLastPacketId_007A5234 = nId;
    }
    ++gnPacketBlocks_007A6AFC;
}

// 0x0045D9B0
void __fastcall sub_0045D9B0_HandlePacket18(unsigned char* pPacket)
{
    D2Packet18RecordStrc tRecord;
    sub_0045D900_ReadPacket18(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, 6, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, 8, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 0x4A, tRecord.nValue07, 0);
    STATLIST_SetUnitStat(pPlayer, 0x1A, tRecord.nValue08, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        sub_00480E70_SetUnitMode(pPlayer, 5);
        sub_004647D0_UpdateAttackableFlag(pPlayer);
    }
}

// 0x0045DB20
void __fastcall sub_0045DB20_HandlePacket95(unsigned char* pPacket)
{
    D2Packet95RecordStrc tRecord;
    sub_0045DA90_ReadPacket95(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, 6, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, 8, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        sub_00480E70_SetUnitMode(pPlayer, 5);
        sub_004647D0_UpdateAttackableFlag(pPlayer);
    }
}

// 0x0045DEC0
void __fastcall sub_0045DEC0(const D2GSPacketCoordinateStrc* pPacket)
{
    D2UnitStrc* pUnit=sub_00463990(pPacket->nUnitId,pPacket->nUnitType);
    if(pUnit)
        sub_004CA230_Forward(pUnit,pPacket->f_6,pPacket->nArg3,pPacket->wArg4,pPacket->wArg5,pPacket->wArg6);
}

// 0x0045E110
void __fastcall sub_0045E110_Packet2C(const D2GSPacketSrv2C* pPacket)
{
    sub_004CBDE0_PlayEventSound(pPacket->dwUnitGUID, pPacket->nUnitType, pPacket->nSoundEvent);
}

// 0x0045E4C0
void __fastcall sub_0045E4C0_Packet59(const D2GSPacketSrv59* pPacket)
{
    sub_00466200_CreatePlayerUnit(pPacket->dwGUID, pPacket->nClass, pPacket->nPosX, pPacket->nPosY, (char*)pPacket->szName);
}

// 0x0045E4E0
void __fastcall sub_0045E4E0_Packet5B(const D2GSPacketSrv5B* pPacket)
{
    const char* szText = pPacket->szText;
    sub_0047A6F0_AddRosterUnit(pPacket->nUnitGUID, pPacket->nClass, pPacket->szName, pPacket->nLevel, pPacket->nPartyId, pPacket->unk0x1C,
                 pPacket->nPartyFlags, pPacket->unk0x20, szText, szText + strlen(szText) + 1);
}

// 0x0045E530
void __fastcall sub_0045E530_Packet5C(const D2GSPacketSrv5C* pPacket)
{
    sub_0047A8B0_RemoveRosterUnit(pPacket->dwPlayerGUID);
}

// 0x0045E5B0
void __fastcall sub_0045E5B0_Packet92(const D2GSPacketSrv92* pPacket)
{
    const int nUnitGUID = pPacket->nUnitGUID;
    D2UnitStrc* pUnit = sub_00463990(nUnitGUID, pPacket->nUnitType);
    if (pUnit)
    {
        sub_004C23E0_RemoveEquippedItems(pUnit);
    }
}

// 0x0045E5D0
void __fastcall sub_0045E5D0_Packet5F(const D2GSPacketSrv5F* pPacket)
{
    const int nPortalFlags = pPacket->nPortalFlags;
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 3349);
    UNITS_SetPlayerPortalFlags(pPlayer, nPortalFlags);
}

// 0x0045E660
void __fastcall sub_0045E660_Packet61(const D2GSPacketSrv61* pPacket)
{
    sub_004B9320_PlayCinematicFromPacket((const D2CinematicPacketStrc*)pPacket);
    sub_0047F1D0_LoadResolution();
}

// 0x0045E6B0
void __fastcall sub_0045E6B0_Packet65(const D2GSPacketSrv65* pPacket)
{
    sub_00479B10_SetKillCount(pPacket->dwUnitId, pPacket->unk0x05);
}

// 0x0045E7E0
void __fastcall sub_0045E7E0_Packet75(const D2GSPacketSrv75* pPacket)
{
    sub_0047A850_UpdateRosterUnit(pPacket->nUnitGUID, pPacket->nPartyId, pPacket->nLevel, pPacket->nFlags, pPacket->unk0x0B);
}

// 0x0045E850
void __fastcall sub_0045E850_Packet79(const D2GSPacketSrv79* pPacket)
{
    sub_004B90D0(pPacket->dwGold, pPacket->nOwnerGUID);
}

// 0x0045E860
void __fastcall sub_0045E860_Packet7A(const D2GSPacketSrv7A* pPacket)
{
    const int nKey = pPacket->unk0x09;
    if (pPacket->unk0x01)
    {
        sub_00478B10_SetRosterEntry(nKey, pPacket->unk0x05, pPacket->unk0x02, pPacket->unk0x03);
    }
    else
    {
        sub_00478C90_DropPetEntry(nKey);
    }
}

// 0x0045E8D0
void __fastcall sub_0045E8D0_Packet7B(const D2GSPacketSrv7B* pPacket)
{
    const unsigned short wSkill = pPacket->wSkill;
    const int nHand = wSkill & 0x8000;
    int nSkillId = wSkill & 0xFFF;
    if (nSkillId > sgptDataTables->nSkillsTxtRecordCount)
    {
        nSkillId = -1;
    }
    sub_004AA0C0_SetSlot(pPacket->nSlot, nSkillId, nHand != 0, pPacket->nItemGUID);
}

// 0x0045E970
void __fastcall sub_0045E970_Packet7E(const D2GSPacketSrv7E* pPacket)
{
    sub_0046F310_LoadGlobalHashedFile(DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))));
}

// 0x0045E990
void __fastcall sub_0045E990_Packet7F(const D2GSPacketSrv7F* pPacket)
{
    const int nUnitGUID = pPacket->nUnitGUID;
    const unsigned short nLife = pPacket->nLifePercentage;
    const unsigned short nLevelId = pPacket->nLevelId;
    if (pPacket->bIsPlayer)
    {
        sub_0047A0D0_SetLifeAndLevel(nUnitGUID, nLife, nLevelId);
    }
    else
    {
        sub_00479010_UpdatePetLife(nUnitGUID, nLife, nLevelId);
    }
}

// 0x0045E9C0
void __fastcall sub_0045E9C0_Packet90(const D2GSPacketSrv90* pPacket)
{
    sub_0047A100_SetPosition(pPacket->dwGUID, pPacket->dwPosX, pPacket->dwPosY);
}

// 0x0045EA60
void __fastcall sub_0045EA60_Packet8B(const D2GSPacketSrv8B* pPacket)
{
    sub_0047A350_SetPartyFlags(pPacket->nUnitGUID, pPacket->bParty);
}

// 0x0045EA70
void __fastcall sub_0045EA70_Packet8C(const D2GSPacketSrv8C* pPacket)
{
    sub_0047A370_SetPvpFlags(pPacket->dwPlayerGUID1, pPacket->dwPlayerGUID2, pPacket->nFlags);
}

// 0x0045EA90
void __fastcall sub_0045EA90_Packet8D(const D2GSPacketSrv8D* pPacket)
{
    sub_0047A330_SetPartyId(pPacket->dwPlayerGUID, pPacket->nPartyGUID);
}

// 0x0045EAA0
void __fastcall sub_0045EAA0_Packet8E(const D2GSPacketSrv8E* pPacket)
{
    const int nPlayerGUID = pPacket->dwPlayerGUID;
    const int nCorpseGUID = pPacket->dwCorpseGUID;
    if (pPacket->nType)
    {
        sub_0047A3D0_AddCorpse(nPlayerGUID, nCorpseGUID);
    }
    else
    {
        sub_0047A490_DropCorpseEntry(nPlayerGUID, nCorpseGUID);
    }
}

// 0x0045EAC0
void __fastcall sub_0045EAC0_Packet9B(const D2GSPacketSrv9B* pPacket)
{
    sub_004B6980_SetNpcMenuState(pPacket->unk0x01, pPacket->unk0x03);
}

// 0x0045EAD0
void __fastcall sub_0045EAD0_Packet97(const D2GSPacketSrv97* pPacket)
{
    D2_ASSERT(pPacket->nHeader == 0x97, 3910);
    sub_0048A700();
}

// 0x0045EDC0
void __fastcall sub_0045EDC0_PacketA6(const D2GSPacketSrvA6* pPacket)
{
    if (!pPacket->bSkip)
    {
        DATATBLS_AddOrChangeRunesTxtRecord(pPacket->nRecordId, (D2RunesTxt*)pPacket->pRecord);
    }
}

// 0x0045EDE0
void __fastcall sub_0045EDE0_PacketA7(const D2GSPacketSrvA7* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        const int nState = pPacket->nState;
        sub_004D9B20_BeginState(pUnit, nState);
        sub_004D9E60_StartClientState(pUnit, nState);
    }
}

// 0x0045EF60
void __fastcall sub_0045EF60_PacketA9(const D2GSPacketSrvA9* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        const int nState = pPacket->nState;
        sub_004D9F40_EndClientState(pUnit, nState);
        sub_004D9C30_EndState(pUnit, nState);
    }
}

// 0x0045E290
void __fastcall sub_0045E290_Packet45(const D2GSPacketSrv45* pPacket)
{
}

// 0x0045E3B0
void __fastcall sub_0045E3B0_Packet54(const D2GSPacketSrv54* pPacket)
{
    sub_00473CA0_Empty();
}

// 0x0045E3C0
void __fastcall sub_0045E3C0_Packet4F(const D2GSPacketSrv4F* pPacket)
{
    sub_004B3290_ResetSlots();
}

// 0x0045E570
void __fastcall sub_0045E570_Packet5E(const D2GSPacketSrv5E* pPacket)
{
    sub_004B92B0_StorePacketText(pPacket);
}

// 0x0045E6C0
void __fastcall sub_0045E6C0_Packet66(const D2GSPacketSrv66* pPacket)
{
}

// 0x0045E6D0
void __fastcall sub_0045E6D0_Packet73(const D2GSPacketSrv73* pPacket)
{
    const int nX = *(const int*)pPacket->nX;
    const int nY = *(const int*)pPacket->nY;
    const int nFirstX = *(const int*)pPacket->nFirstX;
    const int nFirstY = *(const int*)pPacket->nFirstY;
    const unsigned short nCurrentFrame = *(const unsigned short*)pPacket->nCurrentFrame;
    const unsigned short nMissileId = *(const unsigned short*)pPacket->nMissileId;
    const int nUnitGUID = *(const int*)pPacket->nUnitGUID;

    D2UnitStrc* pOwner = sub_00463DE0_GetPlayerUnit();
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pOwner;
    tMissileParams.dwFlags = 0x40000001;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkillLevel = pPacket->nLevel;
    tMissileParams.nMissile = nMissileId;
    if (nFirstX && nFirstY)
    {
        tMissileParams.dwFlags = 0x40000021;
        tMissileParams.nTargetX = nFirstX;
        tMissileParams.nTargetY = nFirstY;
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        UNITS_StoreOwnerTypeAndGUID(pMissile, pPacket->nUnitType, nUnitGUID);
        if (pPacket->nPierce)
            STATLIST_SetUnitStat(pMissile, 0x148, pPacket->nPierce, 0);

        MISSILE_SetCurrentFrame(pMissile, nCurrentFrame);
        pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissile->dwFrameCountPrecise >> 8) << 8;
    }
}

// 0x0045E800
void __fastcall sub_0045E800_Packet77(const D2GSPacketSrv77* pPacket)
{
    sub_004B8CF0(pPacket);
}

// 0x0045EA30
void __fastcall sub_0045EA30_Packet89(const D2GSPacketSrv89* pPacket)
{
    sub_004B9330_UniqueEvent(pPacket);
}

// 0x0045EB00
void __fastcall sub_0045EB00_Packet8F(const D2GSPacketSrv8F* pPacket)
{
    sub_0044CDB0_StorePong(pPacket);
}

// 0x0045F120
void __fastcall sub_0045F120_HandleLifePacket(unsigned char* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(*(int*)(pPacket + 2), pPacket[1]);
    if (!pUnit)
        return;
    if (pUnit == sub_00463DE0_GetPlayerUnit())
        return;
    const int bFlag = (pUnit->dwFlags >> 9) & 1;
    if (bFlag)
        return;
    if (pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pPacket[6] << 8, bFlag);
    else
        sub_0047A690(*(int*)(pPacket + 2), pPacket[6] * 100 / 128);
}
