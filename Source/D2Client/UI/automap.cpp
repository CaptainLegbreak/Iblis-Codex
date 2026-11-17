#include "D2Client.h"

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
struct D2AutomapNodeStrc;
struct D2AutomapCellStrc;
struct D2AutomapCellBlockStrc;
struct D2AutomapContextStrc;
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

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
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

struct D2AutomapNodeStrc
{
    int nValue;
    int nData[5];
    D2AutomapNodeStrc* pNext;
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
extern D2AutomapNodeStrc* gpAutomapNodes_007A5160; // 0x007A5160

struct D2AutomapCellStrc
{
    unsigned int fSaved;
    short nCellNo;
    short xPixel;
    short yPixel;
    short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

struct D2AutomapCellBlockStrc
{
    D2AutomapCellStrc cells[512];
    union
    {
        D2AutomapCellBlockStrc* pNext;
        D2AutomapCellBlockStrc* next;
    };
};

struct D2AutomapContextStrc
{
    int unk0x00;
    int nLayerKind;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall sub_00457900_RotateLeftHeavy(D2AutomapCellStrc** ppRoot); // 0x00457900
void __stdcall sub_004579E0_RotateRightHeavy(D2AutomapCellStrc** ppRoot); // 0x004579E0
extern int gaAutomapCellTable_007A3150[0x800]; // 0x007A3150
void* __fastcall FOG_Alloc(int size, const char* file, int line, int flags); // 0x0040B380
extern "C" void* __cdecl memset(void* memory, int value, unsigned int size); // 0x00681EF0

typedef unsigned int U32;

typedef unsigned short U16;

struct PlayerNode
{
    int playerId;
    U32 flags;
    PlayerNode* next;
};

struct PlayerListHead
{
    PlayerNode* first;
};

typedef char NodeSize[(sizeof(PlayerNode) == 12) ? 1 : -1];

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
void* __cdecl sub_004646A0();
int __stdcall DUNGEON_GetLevelIdFromRoom(void* room); // 0x0061A1B0
const U16* __fastcall sub_00453E70(int levelId); // 0x00453E70
int __fastcall sub_00501820(const U16* text); // 0x00501820
void __fastcall sub_00502320(const U16* text, int x, int y, int color, int mode); // 0x00502320
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern int gdwGlobal_007A520C; // 0x007A520C
extern int gdwGlobal_007A5208; // 0x007A5208

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int unk0x08[5];
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x62];
    int dwAuraRangeCalc;
};

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

struct D2GfxDataStrc
{
    char unk0x00[0x2C];
    D2UnitOverlayStrc* pOverlays;
};

struct D2OverlayTxt
{
    char unk0x00[0x7C];
    unsigned char nTrans;
    char unk0x7D[7];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBBC];
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};

struct D2AutomapPairStrc
{
    int nIndex;
    int nValue;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2UiRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2UiRecordStrc
{
    int unk0x00;
    unsigned char nIndex;
    unsigned char unk0x05;
    unsigned short unk0x06;
    D2UiRectStrc aRects[16];
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
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
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
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
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

// 0x00458CF0
void __stdcall sub_00458CF0_PushNode(int nValue)
{
    D2AutomapNodeStrc* pNode = (D2AutomapNodeStrc*)FOG_Alloc(sizeof(D2AutomapNodeStrc), ".\\UI\\automap.cpp", 0x5ED, 0);
    D2AutomapNodeStrc* pHead = gpAutomapNodes_007A5160;
    memset(pNode->nData, 0, sizeof(pNode->nData));
    pNode->nValue = nValue;
    pNode->pNext = pHead;
    gpAutomapNodes_007A5160 = pNode;
}

#include "gen/data/Source/D2Client/UI/automap.inc"

static D2AutomapCellBlockStrc* gpAutomapCellBlocks_007A5158; // 0x007A5158

static int gnAutomapCellCount_007A515C; // 0x007A515C

static D2AutomapContextStrc* gpAutomapContext_007A5164; // 0x007A5164

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

void __fastcall sub_J02_EmitSetAutomapContext(D2AutomapContextStrc* pContext, D2AutomapCellBlockStrc* pBlock)
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
            current = current->next;
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
            previous->next = current;
        else
            gpCellBlocks_007A5158 = current;
    }
    D2AutomapCellStrc* cell = &current->cells[cellIndex];
    memset(cell, 0, sizeof(D2AutomapCellStrc));
    return cell;
}

// 0x0045A050
void __cdecl sub_0045A050_DrawLevelName()
{
    void* room = sub_004646A0();
    if (room)
    {
        const U16* text = sub_00453E70(DUNGEON_GetLevelIdFromRoom(room));
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

// 0x00461AC0
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
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

// 0x00480230
void __cdecl sub_00480230()
{
    while (gpPendingWarden_007BC994)
    {
        if (gpSlotHolder_007BC990)
        {
            gpSlotHolder_007BC990->pObj->Slot1();
            gpSlotHolder_007BC990->~WardenModule();
            delete gpSlotHolder_007BC990;
        }
        gpSlotHolder_007BC990 = gpPendingWarden_007BC994;
        gpPendingWarden_007BC994 = 0;
        gpSlotHolder_007BC990->pObj = gpSlotHolder_007BC990->pfnCreate(&gWardenIface_00721C98);
        int nValue = gnWardenIfaceValue_00721C94;
        gpSlotHolder_007BC990->pObj->Slot0(&nValue, 4);
    }
}

// 0x00480C10
int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg)
{
    switch (pUnit->dwUnitType)
    {
    case 0:
        return sub_00461250_QueueMove(nCommand, pUnit, pTarget, nArg);
    case 1:
        sub_004AFF60_MonsterCommand(nCommand, pUnit, pTarget);
        return 1;
    case 2:
        sub_004BD6D0_ObjectCommand(nCommand, pUnit, pTarget);
        return 1;
    case 4:
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
        const D2UiRectStrc* pRect = &tRecord.aRects[tRecord.nIndex - 4];
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

// 0x004C54F0
int __fastcall sub_004C54F0_CanThrow(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    if (pUnit->dwUnitType != 0)
    {
        return 1;
    }
    D2UnitStrc* pWeapon = sub_00623990_GetWeapon(pUnit, 0);
    int bNoAmmo = 1;
    if (!pWeapon)
    {
        return 1;
    }
    if (ITEMS_GetAmmoType(pWeapon))
    {
        bNoAmmo = 0;
        if (!SKILLS_GetSkillIdFromSkill(UNITS_GetUsedSkill(pUnit), ".\\SKILLS\\Skills.cpp", 0xB6)
            && STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x9D, 0))
        {
            return 1;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem && (!bNoAmmo || pItem == pWeapon)
        && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem && (!bNoAmmo || pItem == pWeapon)
        && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pItem);
    }
    return 0;
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
