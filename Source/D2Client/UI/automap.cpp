#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2TxtTables.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2Skills.h"

#define OFFSET(T, M) ((unsigned int)&(((T*)0)->M))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WardenIfaceStrc;
struct D2OsVersionInfoStrc;
struct D2MemoryStatusStrc;
struct T004013C0;
struct D2CriticalSectionStrc;
struct D2FogBlockStrc;
struct D2CharSaveIdStrc;
struct D2CharSaveHeaderStrc;
struct D2AutomapLayerStrc;
struct D2AutomapCellStrc;
struct D2AutomapCellBlockStrc;
struct PlayerNode;
struct PlayerListHead;
struct D2UnitTargetStrc;
struct D2SkillsTxt;
struct D2UnitOverlayStrc;
struct D2OverlayTxt;
struct D2AutomapPairStrc;
struct D2UiRectStrc;
struct D2UiRecordStrc;
struct D2ClientSlotObjStrc;
class WardenModule;
struct D2GfxLightStrc;
struct D2UnitStrc;
struct D2GfxDataStrc;
struct D2DataTablesStrc;
struct SMSGHANDLER_PARAMS;
struct Unicode;
struct D2MsgHandlerEntryStrc;
struct D2StaticPathStrc;
struct D2SkillStrc;
struct D2SkillListStrc;
struct D2ActiveRoomStrc;
struct D2DrlgCoordsStrc;
struct D2TileRectStrc;
struct D2PacketBufferStrc;
struct D2PacketTableEntryStrc;
struct D2MonStats2Txt;

typedef unsigned char BOOLEAN;

struct D2OsVersionInfoStrc
{
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

struct T004013C0
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

struct D2CharSaveIdStrc
{
    unsigned char f_0[0x10];
};

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    char unk0x0C[0x08];
    char szName[0x10];
    unsigned int dwFlags;
    unsigned char nClass;
    unsigned char nUnk0x29;
    unsigned char nUnk0x2A;
    unsigned char nUnk0x2B;
    long nCreateTime;
    long nSaveTime;
    char unk0x34[0x54];
    D2CharSaveIdStrc tId;
    int anUnk0x98[4];
    char unk0xA8[0xA7];
};

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
    D2AutomapLayerStrc* pNext;
};

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo); // 0x006CC1F8
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus); // 0x006CC1F4
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo); // 0x006CC1F0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" long __cdecl _time32(long* pTime); // 0x006850E6
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink); // 0x00411A80
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __stdcall sub_006BBF40_PutPackedWord(unsigned char* pStream, unsigned short nValue); // 0x006BBF40
extern unsigned long gdwTotalPhys_0074D898; // 0x0074D898
extern T004013C0 gtSystemInfo_0074D8A0; // 0x0074D8A0
extern _iobuf* gapLogFiles_0075E790[20]; // 0x0075E790
extern unsigned long gadwLogOpenTick_0075E7E0[20]; // 0x0075E7E0
extern unsigned long gadwLogWriteTick_0075D2F0[20]; // 0x0075D2F0
extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0
extern D2CharSaveHeaderStrc gtCharSaveHeader_0077AC10; // 0x0077AC10
extern D2CharSaveIdStrc gtCharSaveId_0070CCC8; // 0x0070CCC8
extern D2AutomapLayerStrc* gpAutomapNodes_007A5160; // 0x007A5160


struct D2AutomapCellBlockStrc
{
    D2AutomapCellStrc cells[512];
    D2AutomapCellBlockStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall sub_00457900_RotateLeftHeavy(D2AutomapCellStrc** ppRoot); // 0x00457900
void __stdcall sub_004579E0_RotateRightHeavy(D2AutomapCellStrc** ppRoot); // 0x004579E0
extern int gaAutomapCellTable_007A3150[0x800]; // 0x007A3150

typedef char NodeFlags[(OFFSET(PlayerNode, flags) == 4) ? 1 : -1];

typedef char NodeNext[(OFFSET(PlayerNode, next) == 8) ? 1 : -1];

extern const char gPlayerListFile[];
extern const char gSoundFile[];
extern void* gAuxSoundRows;
extern int gAuxSoundCount;
extern void* gCacheRows;
extern int gCacheCount;
extern int gSoundMaxId;
extern int gSoundMinId;
extern int gTextY; // 0x007A51BC
extern int gTextRight; // 0x007A5220
PlayerListHead* __fastcall sub_0047A310(int playerId);
void* __fastcall Allocate(U32 bytes, const char* file, int line, U32 flags);
int __fastcall Release(void* allocation, const char* file, int line, U32 flags);
void __fastcall sub_004823E0(int index);
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
const Unicode* __fastcall sub_00453E70_GetLevelName(int nLevelId); // 0x00453E70
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern int gdwGlobal_007A520C; // 0x007A520C
extern int gdwGlobal_007A5208; // 0x007A5208


struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    int nUnk0x08;
    int f_C;
    int unk0x10[2];
    int nFrame;
    int nFrames;
    int nOffsetX;
    int nOffsetY;
    int unk0x28[3];
    int bFront;
    int unk0x38;
    int nUnk0x3C;
    char unk0x40[0x64];
    D2UnitOverlayStrc* pNext;
};


struct D2AutomapPairStrc
{
    int nIndex;
    int nValue;
};



struct D2ClientSlotObjStrc
{
    virtual void Slot0(int* pValue, int nSize);
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

class WardenModule
{
public:
    ~WardenModule();
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }

    void* pImage;
    int unk0x04;
    int nImports;
    D2ClientSlotObjStrc* pObj;
    D2ClientSlotObjStrc* (__fastcall* pfnCreate)(D2WardenIfaceStrc* pIface);
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __cdecl sub_0045A2B0_ReloadAutomapCels(); // 0x0045A2B0
int __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00461250
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x0046E040
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60
void __fastcall sub_004BD6D0_ObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004BD6D0
void __fastcall sub_004C1B80_ItemCommand(int nCommand, D2UnitStrc* pUnit, int nParam1, int nParam2); // 0x004C1B80
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300


D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem); // 0x0062A310
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord); // 0x00660CB0
extern D2AutomapPairStrc gaAutomapPairs_00711258[49]; // 0x00711258
extern int gdwGlobal_007113E8; // 0x007113E8
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern D2WardenIfaceStrc gWardenIface_00721C98; // 0x00721C98
extern int gdwAutoMapFade_007A51A8; // 0x007A51A8
extern int gdwGlobal_007A51E0; // 0x007A51E0
extern int gdwGlobal_007A51E4; // 0x007A51E4
extern int gdwGlobal_007A51E8; // 0x007A51E8
extern int gnUiRecordRow_007A5218; // 0x007A5218
extern int gbUiRecordMode_007BEF98; // 0x007BEF98
extern int gnAutomapMode_007A5150; // 0x007A5150
extern int gnAutomapStep_00711254; // 0x00711254
void __fastcall sub_00457640(int force); // 0x00457640

enum D2C_F06UiConstants
{
    PLAYER_MODE_WALK = 2,
    PLAYER_MODE_RUN = 3,
    PLAYER_MODE_6 = 6,
    BODYLOC_RARM = 4,
    BODYLOC_LARM = 5,
};

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);



struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
};

typedef void (__fastcall* D2PacketHandlerFn)(void* pArg, unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    void* pfnHandler;
    int nSize;
    D2PacketHandlerFn f_8;
};

void __fastcall sub_00451D10_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451D10
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl sub_0044DA70(); // 0x0044DA70
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_004B3230_GetTickPair(int* pLow); // 0x004B3230
int __fastcall sub_004AE360_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360
int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit); // 0x004AE380
void __fastcall sub_004ADEA0_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId); // 0x004ADEA0
D2AutomapCellStrc* __cdecl sub_00457C30(); // 0x00457C30
int __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot); // 0x00457B00
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __fastcall sub_00476AC0_GetViewShift(int* pX, int* pY); // 0x00476AC0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(void* pArg); // 0x00464770
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
void __fastcall sub_004742D0(D2GfxLightStrc* pLight, int nRadius); // 0x004742D0
void __fastcall sub_00474390_SetRecordBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem); // 0x00628660
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __stdcall sub_00650C60_UpdatePath(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00650C60
extern Unicode gwszHoverName_007A2F38[]; // 0x007A2F38
extern int gdwGlobal_007A5210; // 0x007A5210
extern int gnGlobal_007A5214; // 0x007A5214
extern int gnGlobal_007A5230; // 0x007A5230
extern D2PacketTableEntryStrc gtPacketTable_007114D0[]; // 0x007114D0
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern int gnGlobal_007A5258; // 0x007A5258
extern int gnGlobal_007A525C; // 0x007A525C

int gnOsKind_0074D890; // 0x0074D890

float gfOsVersion_0074D894; // 0x0074D894

int gbSystemInfoDone_0074D88C; // 0x0074D88C

int gabFreeBlockDirty_007784C8[0x100]; // 0x007784C8

int gnFreeBlockSweep_007788C8; // 0x007788C8

// 0x00404850
BOOLEAN __stdcall sub_00404850_IsAtLeast1C(unsigned int nValue)
{
    return nValue >= 0x1C;
}

// 0x00407DE0
void __cdecl sub_00407DE0_CaptureSystemInfo()
{
    D2OsVersionInfoStrc tVersion;
    D2MemoryStatusStrc tMemory;
    tVersion.dwOSVersionInfoSize = sizeof(tVersion);
    if (GetVersionExA(&tVersion))
    {
        float fMinor = (float)tVersion.dwMinorVersion;
        while (fMinor > 1.0)
        {
            fMinor = fMinor / 10.0;
        }
        gfOsVersion_0074D894 = (float)((float)tVersion.dwMajorVersion + fMinor / 100.0);
        switch (tVersion.dwPlatformId)
        {
        case 2:
            gnOsKind_0074D890 = 1;
            if (tVersion.dwMajorVersion >= 5)
            {
                if (tVersion.dwMinorVersion >= 2)
                {
                    gnOsKind_0074D890 = 4;
                }
                else
                {
                    gnOsKind_0074D890 = tVersion.dwMinorVersion < 1 ? 2 : 3;
                }
            }
            break;
        case 3:
            gnOsKind_0074D890 = 0;
            break;
        default:
            gnOsKind_0074D890 = 0;
            break;
        }
    }
    GlobalMemoryStatus(&tMemory);
    gdwTotalPhys_0074D898 = tMemory.dwTotalPhys;
    GetSystemInfo(&gtSystemInfo_0074D8A0);
    gbSystemInfoDone_0074D88C = 1;
}

// 0x0040E850
unsigned __int64 __cdecl sub_0040E850_ReadTimeStampCounter()
{
    unsigned __int64 nTicks;
    __asm
    {
        rdtsc
        mov dword ptr nTicks[0], eax
        mov dword ptr nTicks[4], edx
    }
    return nTicks;
}

// 0x0040F350
void __cdecl sub_0040F350_CloseStaleLogs()
{
    char szPath[0x104];
    int bLog = 0;
    szPath[0] = 0;
    unsigned long nNow = GetTickCount();
    for (int i = 0; i < 20; ++i)
    {
        if (gapLogFiles_0075E790[i])
        {
            if (nNow - gadwLogOpenTick_0075E7E0[i] > 15000 || nNow - gadwLogWriteTick_0075D2F0[i] > 5000)
            {
                if (bLog)
                {
                    OutputDebugStringA(szPath);
                }
                fclose(gapLogFiles_0075E790[i]);
                gapLogFiles_0075E790[i] = 0;
            }
        }
    }
}

// 0x00412000
void __cdecl sub_00412000_ReleaseFreeBlocks()
{
    int i = 0;
    gnFreeBlockSweep_007788C8 = 0;
    D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
    int n = 0x100;
    do
    {
        if (gabFreeBlockDirty_007784C8[i])
        {
            EnterCriticalSection(pLock);
            gabFreeBlockDirty_007784C8[i] = 0;
            D2FogBlockStrc** ppLink = &gapFreeBlocks_007768B8[i];
            while (*ppLink)
            {
                D2FogBlockStrc* pBlock = *ppLink;
                if (!pBlock->bInUse && pBlock->dwSize < 0x80000000)
                    sub_00411A80_ReleaseBlock(ppLink);
                else
                    ppLink = &pBlock->pNext;
            }
            LeaveCriticalSection(pLock);
        }
        ++i;
        ++pLock;
    } while (--n);
}

// 0x00414220
double __fastcall sub_00414220_PowInt(double x, int nExp)
{
    const double one = 1.0;
    unsigned int nBits = nExp >= 0 ? (unsigned int)nExp : (unsigned int)-nExp;
    double z = one;
    for (;;)
    {
        if (nBits & 1)
            z *= x;
        nBits >>= 1;
        if (nBits == 0)
            break;
        x *= x;
    }
    return nExp < 0 ? one / z : z;
}

// 0x0043C540
void __fastcall sub_0043C540(const char* szName, unsigned char nClass, unsigned char* pStream, unsigned short wFlags)
{
    memset(&gtCharSaveHeader_0077AC10, 0, 0x14F);
    gtCharSaveHeader_0077AC10.dwMagic = 0xAA55AA55;
    gtCharSaveHeader_0077AC10.dwVersion = 0x60;
    SStrCopy(gtCharSaveHeader_0077AC10.szName, szName, 0x7FFFFFFF);
    gtCharSaveHeader_0077AC10.nClass = nClass;
    gtCharSaveHeader_0077AC10.nUnk0x2B = 1;
    gtCharSaveHeader_0077AC10.dwFlags = wFlags | 1;
    gtCharSaveHeader_0077AC10.nCreateTime = _time32(0);
    gtCharSaveHeader_0077AC10.nSaveTime = gtCharSaveHeader_0077AC10.nCreateTime;
    gtCharSaveHeader_0077AC10.dwSize = 0x14F;
    gtCharSaveHeader_0077AC10.nUnk0x29 = 0x10;
    gtCharSaveHeader_0077AC10.nUnk0x2A = 0x1E;
    if (nClass == 6 || nClass == 5)
        gtCharSaveHeader_0077AC10.dwFlags |= 0x20;
    sub_006BBF40_PutPackedWord(pStream, 0xE);
    pStream += 2;
    gtCharSaveHeader_0077AC10.tId = gtCharSaveId_0070CCC8;
    for (int i = 0; i < 11; ++i)
        *pStream++ = gtCharSaveId_0070CCC8.f_0[i];
    *pStream++ = nClass + 1;
    memset(gtCharSaveHeader_0077AC10.anUnk0x98, 0xFF, sizeof(gtCharSaveHeader_0077AC10.anUnk0x98));
    memset(pStream, -1, 11);
    pStream += 11;
    const unsigned short wSavedFlags = (unsigned short)gtCharSaveHeader_0077AC10.dwFlags;
    *pStream++ = 1;
    sub_006BBF40_PutPackedWord(pStream, wSavedFlags);
    pStream += 2;
    sub_006BBF40_PutPackedWord(pStream, 0);
    pStream += 2;
    *pStream++ = 0xFF;
    *pStream++ = 0xFF;
    *pStream++ = 0xFF;
    *pStream = 0;
}

int gnGlobal_007A5204; // 0x007A5204

int gdwGlobal_007A5208; // 0x007A5208

int gdwGlobal_007A520C; // 0x007A520C

int gnGlobal_007A5248; // 0x007A5248

int gnGlobal_007A524C; // 0x007A524C

int gnGlobal_007A5250; // 0x007A5250

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00451E10
void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < nCount; ++i)
    {
        sub_00451D10_UnregisterMsgHandler(hWnd, pTable[i].nType, pTable[i].nId, (SMSGHANDLER)pTable[i].pfnHandler);
    }
}

// 0x00452580
int __fastcall sub_00452580_GetHoverMonsterName(D2UnitStrc* pUnit, int nArg)
{
    int nTick;
    if (sub_0045AE90() == 3)
    {
        return 0;
    }
    if (sub_004B3230_GetTickPair(&nTick))
    {
        return 0;
    }
    gwszHoverName_007A2F38[0].wChar = 0;
    if (!sub_004AE360_IsUniqueMonster(pUnit) && !sub_004AE380_IsMinionMonster(pUnit))
    {
        return 0;
    }
    sub_004ADEA0_GetMonsterName(pUnit, gwszHoverName_007A2F38, 0x100, nArg);
    return 1;
}

static D2AutomapCellBlockStrc* gpAutomapCellBlocks_007A5158; // 0x007A5158

static int gnAutomapCellCount_007A515C; // 0x007A515C

static D2AutomapLayerStrc* gpAutomapContext_007A5164; // 0x007A5164

// 0x00457B00
int __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pRoot = *ppRoot;
    D2AutomapCellStrc* pRotate = pRoot;
    int nResult;
    if (pRoot)
    {
        int nDiff = pCell->yPixel - pRoot->yPixel;
        if (!nDiff)
        {
            nDiff = pCell->xPixel - pRoot->xPixel;
            if (!nDiff)
            {
                const int nValue = gaAutomapCellTable_007A3150[pCell->nCellNo];
                if (nValue != -1 && nValue != gaAutomapCellTable_007A3150[pRoot->nCellNo])
                    nDiff = pCell->nCellNo - pRoot->nCellNo;
            }
        }
        if (nDiff < 0)
        {
            nResult = sub_00457B00(pCell, &pRoot->pPrev);
            if (nResult)
            {
                switch (pRoot->wWeight)
                {
                case -1:
                    sub_00457900_RotateLeftHeavy(&pRotate);
                    pRoot = pRotate;
                    nResult = 0;
                    break;
                case 0:
                    pRoot->wWeight = -1;
                    break;
                case 1:
                    pRoot->wWeight = 0;
                    nResult = 0;
                    break;
                }
            }
        }
        else if (nDiff > 0)
        {
            nResult = sub_00457B00(pCell, &pRoot->pNext);
            if (nResult)
            {
                switch (pRoot->wWeight)
                {
                case -1:
                    pRoot->wWeight = 0;
                    nResult = 0;
                    break;
                case 0:
                    pRoot->wWeight = 1;
                    break;
                case 1:
                    sub_004579E0_RotateRightHeavy(&pRotate);
                    pRoot = pRotate;
                    nResult = 0;
                    break;
                }
            }
        }
        else
        {
            nResult = 0;
        }
    }
    else
    {
        pCell->pPrev = 0;
        pCell->pNext = 0;
        pRoot = pCell;
        pCell->wWeight = 0;
        nResult = 1;
    }
    *ppRoot = pRoot;
    return nResult;
}

void __fastcall sub_J02_EmitSetAutomapContext(D2AutomapLayerStrc* pContext, D2AutomapCellBlockStrc* pBlock)
{
    gpAutomapContext_007A5164 = pContext;
    gpAutomapCellBlocks_007A5158 = pBlock;
    gnAutomapCellCount_007A515C = 7;
}

D2AutomapCellBlockStrc* gpCellBlocks_007A5158; // 0x007A5158

int gnCellCount_007A515C; // 0x007A515C

// 0x00457C30
D2AutomapCellStrc* __cdecl sub_00457C30()
{
    D2AutomapCellBlockStrc* current = gpCellBlocks_007A5158;
    D2AutomapCellBlockStrc* previous = 0;
    int blockIndex = gnCellCount_007A515C / 512;
    int cellIndex = gnCellCount_007A515C % 512;
    int i = 0;
    ++gnCellCount_007A515C;
    if (gpCellBlocks_007A5158)
    {
        for (; current && i < blockIndex; ++i)
        {
            previous = current;
            current = current->pNext;
        }
    }
    else
    {
        current = 0;
    }
    if (!current)
    {
        current = (D2AutomapCellBlockStrc*)FOG_Alloc(sizeof(D2AutomapCellBlockStrc), ".\\UI\\automap.cpp", 0x35D, 0);
        memset(current, 0, sizeof(D2AutomapCellBlockStrc));
        if (previous)
            previous->pNext = current;
        else
            gpCellBlocks_007A5158 = current;
    }
    D2AutomapCellStrc* cell = &current->cells[cellIndex];
    memset(cell, 0, sizeof(D2AutomapCellStrc));
    return cell;
}

// 0x00457E40
void __stdcall sub_00457E40_AddAutomapCell(unsigned short nCellNo, unsigned short xPixel, unsigned short yPixel, D2AutomapCellStrc** ppRoot, unsigned int fSaved)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    pCell->fSaved = fSaved;
    pCell->nCellNo = nCellNo;
    pCell->xPixel = xPixel;
    pCell->yPixel = yPixel;
    sub_00457B00(pCell, ppRoot);
}

// 0x00458680
void __cdecl sub_00458680_ResetAutomapCells()
{
    if (gpAutomapContext_007A5164)
    {
        D2AutomapCellBlockStrc* pBlock = gpAutomapCellBlocks_007A5158;
        while (pBlock)
        {
            D2AutomapCellBlockStrc* pFree = pBlock;
            pBlock = pBlock->pNext;
            FOG_Free(pFree, ".\\UI\\automap.cpp", 0x51E, 0);
        }
        gpAutomapCellBlocks_007A5158 = 0;
        gnAutomapCellCount_007A515C = 0;
        gpAutomapContext_007A5164->pFloors = 0;
        gpAutomapContext_007A5164->pWalls = 0;
        gpAutomapContext_007A5164->pObjects = 0;
        gpAutomapContext_007A5164->pExtras = 0;
    }
}

// 0x00458CF0
void __stdcall sub_00458CF0_PushNode(int nValue)
{
    D2AutomapLayerStrc* pNode = (D2AutomapLayerStrc*)FOG_Alloc(sizeof(D2AutomapLayerStrc), ".\\UI\\automap.cpp", 0x5ED, 0);
    D2AutomapLayerStrc* pHead = gpAutomapNodes_007A5160;
    memset(&pNode->fSaved, 0, sizeof(pNode->fSaved) + 4 * sizeof(D2AutomapCellStrc*));
    pNode->nLayerNo = nValue;
    pNode->pNext = pHead;
    gpAutomapNodes_007A5160 = pNode;
}

// 0x0045A050
void __cdecl sub_0045A050_DrawLevelName()
{
    D2ActiveRoomStrc* room = sub_004646A0_GetPlayerRoom();
    if (room)
    {
        const Unicode* text = sub_00453E70_GetLevelName(DUNGEON_GetLevelIdFromRoom(room));
        sub_00502320(text, gTextRight - sub_00501820(text) - 16, gTextY, 4, 0);
        gTextY += 16;
    }
}

// 0x0045A280
void __cdecl sub_0045A280_FreeAutomapCels()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gpAutomapCels_007A5168[i])
        {
            sub_00478A00(gpAutomapCels_007A5168[i]);
        }
        gpAutomapCels_007A5168[i] = 0;
    }
}

WardenModule* gpSlotHolder_007BC990; // 0x007BC990

WardenModule* gpPendingWarden_007BC994; // 0x007BC994

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// 0x0045A4C0
void __cdecl sub_0045A4C0_InitAutomap()
{
    unsigned long dwValue = 0;
    sub_0045A2B0_ReloadAutomapCels();
    for (int i = 0; i < 0x800; i++)
    {
        gaAutomapCellTable_007A3150[i] = -1;
    }
    for (int i = 0; i < 49; i++)
    {
        gaAutomapCellTable_007A3150[gaAutomapPairs_00711258[i].nIndex] = gaAutomapPairs_00711258[i].nValue;
    }
    dwValue = 0;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    gdwAutoMapFade_007A51A8 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Centers", 0, &dwValue);
    gdwGlobal_007113E0 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Party", 0, &dwValue);
    gdwGlobal_007113E4 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Party Names", 0, &dwValue);
    gdwGlobal_007113E8 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Left", 0, &dwValue);
    gdwGlobal_007A51E0 = dwValue;
    gdwGlobal_007A51E4 = dwValue;
    gdwGlobal_007A51E8 = dwValue;
}

// 0x0045A720
void __fastcall sub_0045A720_SetAutomapMode(int mode)
{
    if (mode != gnAutomapMode_007A5150)
    {
        gnAutomapMode_007A5150 = mode;
        gnAutomapStep_00711254 = 10;
        switch (mode)
        {
        case 1:
            gnAutomapStep_00711254 = 20;
            break;
        }
        sub_0045A2B0_ReloadAutomapCels();
        sub_00457640(1);
    }
}

// 0x0045AE50
void __fastcall sub_0045AE50_SetGlobal00711428(int nValue)
{
    gdwGlobal_00711428 = nValue;
}

// 0x0045AE70
void __fastcall sub_0045AE70_SetGlobal0071142C(int nValue)
{
    gdwGlobal_0071142C = nValue;
}

// 0x0045AFE0
void __fastcall sub_0045AFE0_SetMouseOffsets(int nX, int nY)
{
    gdwGlobal_007A520C = nX;
    gdwGlobal_007A5208 = nY;
}

// 0x0045AFF0
void __fastcall sub_0045AFF0_ScreenToMap(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    if (sub_004F51D0_IsPerspective())
    {
        nY += nY / -40;
        int nHalfWidth = gnGlobal_0071146C / 2;
        nX += (40 - nY / 4) * (nX - nHalfWidth) / nHalfWidth;
    }
    nY += gdwGlobal_007A5208;
    nX += gdwGlobal_007A520C - gnGlobal_007A5214;
    DUNGEON_ClientToGameSubtileCoords(&nX, &nY);
    *pX = nX;
    *pY = nY;
}

// 0x0045B1E0
void __stdcall sub_0045B1E0_DrawUnitTileRect(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2TileRectStrc* pTileRect = sub_00619620(pRoom, pUnit);
    if (!pTileRect)
    {
        return;
    }
    int nX = UNITS_GetXPositionInline(pUnit);
    int nY = UNITS_GetYPositionInline(pUnit);
    sub_00643260(&nX, &nY);
    int nLeft = pTileRect->nX - gdwGlobal_007A520C + nX;
    int nTop = pTileRect->nY - gdwGlobal_007A5208 + nY;
    int nRight = pTileRect->nWidth + nLeft;
    int nBottom = pTileRect->nHeight + nTop;
    D2GFX_DrawLine(nLeft, nTop, nLeft, nBottom, 0xFF, 0xFF);
    D2GFX_DrawLine(nLeft, nTop, nRight, nTop, 0xFF, 0xFF);
    D2GFX_DrawLine(nLeft, nBottom, nRight, nBottom, 0xFF, 0xFF);
    D2GFX_DrawLine(nRight, nTop, nRight, nBottom, 0xFF, 0xFF);
    nX += 1;
    tagRECT tRect;
    tRect.left = nX - gdwGlobal_007A520C - 0x10;
    tRect.right = nX - gdwGlobal_007A520C + 0x10;
    tRect.top = nY - gdwGlobal_007A5208;
    tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
    D2GFX_UtilDiamond(&tRect, 0xFF);
    nX = UNITS_GetXPositionInline(pUnit);
    nY = UNITS_GetYPositionInline(pUnit);
    nX += pTileRect->nOffsetX;
    nY += pTileRect->nOffsetY;
    sub_00643260(&nX, &nY);
    nX += 1;
    tRect.left = nX - gdwGlobal_007A520C - 0x10;
    tRect.right = nX - gdwGlobal_007A520C + 0x10;
    tRect.top = nY - gdwGlobal_007A5208;
    tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
    D2GFX_UtilDiamond(&tRect, 0x2D);
}

// 0x0045B3E0
void __cdecl sub_0045B3E0_DrawRoomTileRects()
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
            {
                if (pUnit->dwUnitType == UNIT_TILE)
                {
                    sub_0045B1E0_DrawUnitTileRect(pUnit);
                }
            }
        }
    }
}

// 0x0045B440
void __cdecl sub_0045B440_UpdateAutomapOrigin()
{
    int nShiftX;
    int nShiftY;
    gnGlobal_007A5204 = -0xA0;
    if (gdwGlobal_007A5210 == 2)
    {
        gnGlobal_007A5204 = gnGlobal_0071146C / 2 - 0xA0;
    }
    else if (gdwGlobal_007A5210 == 3)
    {
        gnGlobal_007A5204 = 0;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nX = UNITS_GetClientCoordX(pPlayer);
    int nY = UNITS_GetClientCoordY(pPlayer);
    gdwGlobal_007A520C = nX - gnGlobal_0071146C / 2;
    gdwGlobal_007A5208 = nY - gnGlobal_00711470 / 2 + 0x10;
    if (sub_00476AC0_GetViewShift(&nShiftX, &nShiftY))
    {
        gdwGlobal_007A520C += nShiftX;
        gdwGlobal_007A5208 += nShiftY;
    }
}

// 0x0045B4F0
void __stdcall sub_0045B4F0_DrawRoomCollision(D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    for (int nY = tCoords.nSubtileY + 2; nY < tCoords.nSubtileY + tCoords.nSubtileHeight + 5; nY += 5)
    {
        for (int nX = tCoords.nSubtileX + 3; nX < tCoords.nSubtileX + tCoords.nSubtileWidth + 5; nX += 5)
        {
            int nCollision = sub_0061B130_GetCollision(pRoom, nX, nY);
            int nScreenX = nX;
            int nScreenY = nY;
            sub_00643260(&nScreenX, &nScreenY);
            tagRECT tRect;
            tRect.left = nScreenX - gdwGlobal_007A520C - 0x10;
            tRect.right = nScreenX - gdwGlobal_007A520C + 0x10;
            tRect.top = nScreenY - gdwGlobal_007A5208;
            tRect.bottom = nScreenY - gdwGlobal_007A5208 + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x46);
            nScreenX = nScreenX - 7 - gdwGlobal_007A520C;
            nScreenY = nScreenY - gdwGlobal_007A5208;
            D2GFX_OutputString(nScreenX, nScreenY, gszFormatInt_006D57BC, nCollision);
        }
    }
}

// 0x0045D3E0
void __fastcall sub_0045D3E0_RefreshItemStats(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }
    int nLeftSkillId = pUnit->pSkills->pLeftSkill ? pUnit->pSkills->pLeftSkill->pSkillsTxt->nSkillId : 0;
    int nRightSkillId = pUnit->pSkills->pRightSkill ? pUnit->pSkills->pRightSkill->pSkillsTxt->nSkillId : 0;
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        int bStatNotDynamic = 0;
        if (pCheckedItem && pCheckedItem->dwUnitType == UNIT_ITEM && STATLIST_GetOwner(pCheckedItem, &bStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pCheckedItem);
            STATLIST_MergeStatLists(pUnit, pCheckedItem, bStatNotDynamic);
        }
    }
    SKILLS_SetLeftActiveSkill(pUnit, nLeftSkillId, -1);
    SKILLS_SetRightActiveSkill(pUnit, nRightSkillId, -1);
}

// 0x0045FA40
void __fastcall sub_0045FA40(void* pArg)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pArg);
    if (!pBuffer)
    {
        return;
    }
    D2_ASSERT(pBuffer->nCount <= pBuffer->nMax, 0x1525);
    for (int i = 0; i < pBuffer->nCount; ++i)
    {
        unsigned char* pPacket = pBuffer->pData + gnGlobal_007A5230 * i;
        int nSize;
        if (!sub_0052B920(pPacket, gnGlobal_007A5230, &nSize))
        {
            return;
        }
        D2_ASSERT(pPacket[0] < 0xAF, 0x1531);
        D2PacketTableEntryStrc* pEntry = &gtPacketTable_007114D0[pPacket[0]];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT((unsigned short)nSize == pEntry->nSize, 0x1534);
        }
        D2_ASSERT(pEntry->f_8, 0x1536);
        pEntry->f_8(pArg, pPacket);
    }
    if (pBuffer->nCount)
    {
        memset(pBuffer->pData, 0, pBuffer->nCount * gnGlobal_007A5230);
    }
    pBuffer->nCount = 0;
}

// 0x0045FE30
void __stdcall sub_0045FE30_ButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nLeft = gnGlobal_007A2858 + 0x110;
    int nBottom = 0x136 - gnGlobal_007A285C;
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gnGlobal_007A524C = 1;
        gnGlobal_007A5248 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004601F0
void __stdcall sub_004601F0_TwoButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nLeft = gnGlobal_007A2858 + 0xCE;
    int nBottom = 0x136 - gnGlobal_007A285C;
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gnGlobal_007A524C = 1;
        gnGlobal_007A5248 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    nLeft = gnGlobal_007A2858 + 0x152;
    nBottom = 0x136 - gnGlobal_007A285C;
    nX = sub_00468730();
    nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gnGlobal_007A5250 = 1;
        gnGlobal_007A5248 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004602E0
void __stdcall sub_004602E0_TwoButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A524C = 0;
    gnGlobal_007A5250 = 0;
    if (gnGlobal_007A5248)
    {
        int nLeft = gnGlobal_007A2858 + 0xCE;
        int nBottom = 0x136 - gnGlobal_007A285C;
        int nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gnGlobal_007A5258 = 1;
            gnGlobal_007A5248 = 0;
        }
        nLeft = gnGlobal_007A2858 + 0x152;
        nBottom = 0x136 - gnGlobal_007A285C;
        nX = sub_00468730();
        nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gnGlobal_007A525C = 1;
            gnGlobal_007A5248 = 0;
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00460930
void __fastcall sub_00460930_SetUnitLightRadius(D2UnitStrc* pUnit, int nDelta)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!pLight)
    {
        return;
    }
    int nRadius;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nRadius = 0xD;
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }
        nRadius = sub_0063EBD0_GetLightRadius(pUnit);
        if (nRadius < pMonStats2TxtRecord->nLightRadius)
        {
            nRadius = pMonStats2TxtRecord->nLightRadius;
        }
    }
    nRadius += nDelta;
    sub_004742D0(pLight, nRadius > 0 ? nRadius : 0);
}

// 0x004609A0
void __fastcall sub_004609A0_SetUnitLightColor(D2UnitStrc* pUnit, int nColor)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!pLight)
    {
        return;
    }
    unsigned char nRed = 0xFF;
    unsigned char nGreen = 0xFF;
    unsigned char nBlue = 0xFF;
    if (nColor)
    {
        nRed = (unsigned char)(nColor >> 16);
        nGreen = (unsigned char)(nColor >> 8);
        nBlue = (unsigned char)nColor;
    }
    sub_00474390_SetRecordBytes(pLight, nRed, nGreen, nBlue);
}

// 0x00461AC0
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || !pSkill || !pTarget)
    {
        return 0;
    }
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    *pRange = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwAuraRangeCalc, pSkillsTxtRecord->nSkillId,
        SKILLS_GetSkillLevel(pPlayer, pSkill, 1));
    *pDistance = sub_006416D0_UnitEdgeDistance(pPlayer, pTarget);
    return *pDistance <= *pRange;
}

// 0x00462EE0
unsigned char __stdcall sub_00462EE0_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == BODYLOC_LARM || nBodyLoc == BODYLOC_RARM)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem)
            && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && pItem != INVENTORY_GetLeftHandWeapon(pInventory))
        {
            return 6;
        }
    }
    return ITEMS_GetComponent(pItem);
}

// 0x00463180
void __fastcall sub_00463180_UpdatePathAndMove(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3)
{
    int nMode = pUnit->dwAnimMode;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTargetUnit = 0;
    int bMove = 0;
    int nX = 0;
    int nY = 0;
    if (nMode >= PLAYER_MODE_WALK && (nMode <= PLAYER_MODE_RUN || nMode == PLAYER_MODE_6))
    {
        bMove = 1;
        pTargetUnit = sub_004648F0_GetPathTargetUnit(pUnit);
        if (!pTargetUnit)
        {
            sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY);
        }
    }
    sub_00650C60_UpdatePath(pPath, pUnit, nArg1, nArg2, nArg3);
    if (bMove)
    {
        D2UnitTargetStrc tTarget;
        memset(&tTarget, 0, sizeof(tTarget));
        if (pTargetUnit)
        {
            tTarget.nParam1 = pTargetUnit->dwUnitType;
            tTarget.nParam2 = pTargetUnit->dwUnitId;
            sub_00461250_QueueMove(nMode == PLAYER_MODE_RUN ? 0x18 : 0, pUnit, &tTarget, 0);
        }
        else
        {
            tTarget.nParam1 = nX;
            tTarget.nParam2 = nY;
            sub_00461250_QueueMove(nMode == PLAYER_MODE_RUN ? 0x17 : 1, pUnit, &tTarget, 0);
        }
    }
}

// 0x0046EFD0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6)
{
    D2GFX_DrawBox(nX, nY, nX + nWidth, nY + nHeight, nArg5, nArg6);
}

inline D2OverlayTxt* DATATBLS_GetOverlayTxtRecordInline(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }
    return 0;
}

// 0x0046F0C0
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue)
{
    if (!pUnit)
    {
        return;
    }
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }
    D2_ASSERT(DATATBLS_GetOverlayTxtRecordInline(nValue), 0xCA9);
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2UnitOverlayStrc* pNext = pOverlay->pNext;
        if (pOverlay->nOverlay == nValue)
        {
            sub_0046E040_RemoveOverlay(pUnit, pOverlay);
            return;
        }
        const int nType = pOverlay->nType;
        if ((nType == 4 || nType == 9) && (pOverlay->nUnk0x08 == nValue || pOverlay->f_C == nValue))
        {
            sub_0046E040_RemoveOverlay(pUnit, pOverlay);
            return;
        }
        pOverlay = pNext;
    }
}

// 0x00480C10
int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return sub_00461250_QueueMove(nCommand, pUnit, pTarget, nArg);
    case UNIT_MONSTER:
        sub_004AFF60_MonsterCommand(nCommand, pUnit, pTarget);
        return 1;
    case UNIT_OBJECT:
        sub_004BD6D0_ObjectCommand(nCommand, pUnit, pTarget);
        return 1;
    case UNIT_ITEM:
        sub_004C1B80_ItemCommand(nCommand, pUnit, pTarget->nParam1, pTarget->nParam2);
        return 1;
    }
    return 1;
}

// 0x00498DC0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UiRecordStrc tRecord;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    if (gbUiRecordMode_007BEF98)
    {
        const D2UiRectStrc* pRect = &tRecord.aRects[tRecord.nBoxes - 4];
        if (nX >= pRect->nLeft && nX <= tRecord.aRects[3].nRight && nY >= pRect->nTop && nY <= tRecord.aRects[3].nBottom)
        {
            return 1;
        }
    }
    else if (nY > gnGlobal_00711470 - 0x30 && nX >= gnGlobal_0071146C / 2 + 0x17 && nX <= gnGlobal_0071146C / 2 + 0x91
        && nY >= gnGlobal_00711470 - 0x27 && nY <= gnGlobal_00711470 - 0xA)
    {
        return 1;
    }
    return 0;
}

// 0x004C5420
D2UnitStrc* __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4)
{
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY) || !nX || !nY)
    {
        return 0;
    }
    return sub_004CDBA0_SubmitOwnerRequest(pUnit, nRequest, nX, nY, nArg3, nArg4);
}

#include "gen/data/Source/D2Client/UI/automap.inc"
