#include "D2MissileIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2MonModes.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Primitives.h"
#include "D2Win32Types.h"

#define UNIT_MONSTER 1

#define FIELD_OFFSET(T,F) ((unsigned long)&(((T*)0)->F))

union D2SeedStrc;

struct D2MonsterDataStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

struct D2MissilesTxt;

struct RecordView;

struct PayloadView;

struct UnitView;

struct TablesView;

void __fastcall sub_0046F170_RemoveOverlays(D2UnitStrc* pUnit); // 0x0046F170

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount); // 0x0046C320

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall sub_004E2ED0_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

extern "C" int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wMask); // 0x004AC7E0

D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

struct RecordView
{
    char opaque[0x1a8];
};

struct PayloadView
{
    RecordView* record;
    char unused4[0x24];
    unsigned short flags28;
    char unusedAfterFlags[0x12];
    int value3c;
};

struct UnitView
{
    int type;
    int classId;
    char unusedAfterClass[0x0c];
    PayloadView* payload;
};

struct TablesView
{
    char unused0[0xa78];
    RecordView* records;
    int unusedAfterRecords;
    int count;
};

extern "C" TablesView* gTables_00744304;

typedef char RecordView_size[(sizeof(RecordView)==0x1a8)?1:-1];

typedef char PayloadView_size[(sizeof(PayloadView)==0x40)?1:-1];

typedef char PayloadView_record_offset[(FIELD_OFFSET(PayloadView,record)==0)?1:-1];

typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags28)==0x28)?1:-1];

typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value3c)==0x3c)?1:-1];

typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];

typedef char UnitView_class_offset[(FIELD_OFFSET(UnitView,classId)==0x4)?1:-1];

typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];

typedef char TablesView_size[(sizeof(TablesView)==0xa84)?1:-1];

typedef char TablesView_records_offset[(FIELD_OFFSET(TablesView,records)==0xa78)?1:-1];

typedef char TablesView_count_offset[(FIELD_OFFSET(TablesView,count)==0xa80)?1:-1];

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientStringListStrc;

struct D2NpcMessageStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl sub_00466FE0(); // 0x00466FE0

void __cdecl sub_00487C20_ResetButtonsFromState5(); // 0x00487C20

void __cdecl sub_004B1E80_OpenTimedDialog36(); // 0x004B1E80

int __cdecl sub_004B5C60_Handler(); // 0x004B5C60

void __fastcall sub_004B8020(void* pRes); // 0x004B8020

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0();
    virtual unsigned int GetAt(int nIndex);
};

extern unsigned char gbFound_007C0DDA; // 0x007C0DDA

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __cdecl sub_00453AE0(); // 0x00453AE0

void __cdecl sub_00487990_ResetHover(); // 0x00487990

void __fastcall sub_004C0620_OpenPanelMode1(int nArg); // 0x004C0620

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

int __cdecl sub_0044DCC0(); // 0x0044DCC0

int __fastcall sub_00478EE0_CountPets(D2UnitStrc* pOwner, int nPetType); // 0x00478EE0

void __cdecl sub_004B3610_CloseTradeDialog(); // 0x004B3610

extern int (__cdecl* gpfnGlobal_00726CD7)(); // 0x00726CD7

extern short gwGlobal_00726CC9; // 0x00726CC9

extern int (__cdecl* gpfnGlobal_00727253)(); // 0x00727253

extern short gwGlobal_00727245; // 0x00727245

extern int (__cdecl* gpfnGlobal_007272A5)(); // 0x007272A5

extern short gwGlobal_00727295; // 0x00727295

extern unsigned char gbGlobal_007C0D89; // 0x007C0D89

void __cdecl sub_004B2940(); // 0x004B2940

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

void __fastcall sub_004B3C20(int nValue); // 0x004B3C20

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_004BA840(int nHandle); // 0x004BA840

void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall sub_004B6A30_NpcTextCallback(void* pContext, int nArg, int nValue); // 0x004B6A30

void __cdecl sub_004B4830_Rebuild(); // 0x004B4830

void __cdecl sub_00487D40_ResetButtonsFromState7(); // 0x00487D40

extern D2ClientDialogStrc* gpDialog_007C0D63; // 0x007C0D63

extern char gbGlobal_007C0C69; // 0x007C0C69

extern int gnNpcSoundActive_007C0DB4; // 0x007C0DB4

extern int gnNpcSoundHandle_007C0DB8; // 0x007C0DB8

extern D2ClientStringListStrc gtStringList_007C0D9A; // 0x007C0D9A

#pragma pack(push, 1)

struct D2NpcMessageStrc
{
    unsigned short nMessage;
    char unk0x02[9];
    int nClass;
};

struct D2NpcEntryStrc
{
    char unk0x00[5];
    D2NpcMessageStrc* pMessages;
    int nCount;
    int nIndex;
    char bSelected;
};

#pragma pack(pop)

void __cdecl sub_004B17A0();

int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue);

extern unsigned char gbGlobal_007C0C6A; // 0x007C0C6A

int gnGlobal_007C0C60; // 0x007C0C60

int gnGlobal_007C0C64; // 0x007C0C64

int gdwGlobal_007C0DB0; // 0x007C0DB0

D2UnitStrc* gpUnit_007C0DD4; // 0x007C0DD4

unsigned short gwGlobal_007C0DD8; // 0x007C0DD8

struct D2ClientDialogStrc;

struct D2UnitStrc;

struct Unicode { unsigned short wChar; Unicode(unsigned short ch=0):wChar(ch){} };

struct UnicodeChar:Unicode
{
    UnicodeChar(); // 0x0042F530
};

typedef int (__cdecl* D2MenuHandler)();

#pragma pack(push,1)

struct D2NpcIndexStrc { int nId,nCount; unsigned short awIds[5]; D2MenuHandler apfHandlers[5]; char bEnabled; };

#pragma pack(pop)

typedef char CheckNpcIndexSize[sizeof(D2NpcIndexStrc)==39?1:-1];

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT*,int,int,int,int); // 0x006CC498

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*,const char*,...); // 0x006CC468

extern const char gszFormatD[]; // 0x006D57BC

extern D2ViewStrc* gpView_007A0640; // 0x007A0640

extern int gnGlobal_007C0D2D; // 0x007C0D2D

int gnGlobal_007C0DD0;        // 0x007C0DD0

extern unsigned int gnHirelingName_00725494; // 0x00725494

extern D2NpcIndexStrc gaNpcIndex_00726C48[]; // 0x00726C48

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0

const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc*); // 0x00464A60

void __stdcall UNITS_GetClientCoords(D2UnitStrc*,D2CoordStrc*); // 0x00620900

void __fastcall sub_00476070_GetViewRect(D2ViewStrc*,long*,long*,long*,long*); // 0x00476070

void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc*,int*,int*); // 0x004760C0

int __cdecl sub_004B45D0_NpcMenuCancel(); // 0x004B45D0

int __cdecl sub_004B4620_NpcMenuCancelB(); // 0x004B4620

D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int,int,D2MenuHandler,D2MenuHandler,int,int,int,int,int,int,int); // 0x004B7EB0

void __fastcall sub_004B8370(void*,int); // 0x004B8370

void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4, int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled); // 0x004B85F0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode*,const Unicode*); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode*,const Unicode*); // 0x00526700

int __fastcall sub_00526800(const Unicode*); // 0x00526800

void __cdecl sub_005269D0(int,Unicode*,const Unicode*,...); // 0x005269D0

void __fastcall sub_00526F20_ToUnicode(Unicode*,const char*,int); // 0x00526F20

unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit); // 0x00622DE0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10

int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc*); // 0x0062A530

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*,int,int); // 0x0065C310

static int sub_004B1C80_GetNpcDialogPos(D2CoordStrc*);

static inline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004AD5F0
void __fastcall sub_004AD5F0_StateOverlayOrSpawn(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
        return;

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
        return;

    if (pUnit->dwAnimMode == MONMODE_DEATH)
    {
        int nFrame;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
        if (nFrame == 13)
        {
            sub_0046F170_RemoveOverlays(pUnit);
            sub_00470390(pUnit, 0x34, 5, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, 0x9C, 5, 0, 0, 0, 0, 0);
            pUnit->nActionFrame = 0;
        }
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD)
    {
        if ((unsigned int)SEED_RollRandomNumberForceInline(&pUnit->pSeed) % 100 == 0 && (int)pMonsterData->dwDurielFlag < 100)
        {
            CLIENTS_GetUnitX(pUnit);
            CLIENTS_GetUnitY(pUnit);
            sub_0046C320_SpawnAroundUnit(pUnit, MONSTER_MAGGOT, 4);
            pMonsterData->dwDurielFlag += 4;
        }
    }
}

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x004AD6E0
static void __stdcall sub_004AD6E0_StateMissileBurst(int nSkillLevel, D2UnitStrc* pUnit, int nMissile)
{
    if (!nSkillLevel)
        nSkillLevel = 1;
    if (nMissile == MISSILE_LIGHTUNIQUE)
    {
        if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || !(pUnit->pMonsterData->nTypeFlag & 0x100))
            return;
    }
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = GetUnitPathX(pUnit);
    tMissile.nY = GetUnitPathY(pUnit);
    tMissile.nSkill = 0;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    if (nMissile != MISSILE_QUEENPOISONCLOUD)
        tMissile.pInitFunc = sub_004E2ED0_InitCappedChargedPath;
    int anDX[4] = { 0, 1, 0, -1 };
    int anDY[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = GetUnitPathX(pUnit);
        const int nUnitY = GetUnitPathY(pUnit);
        const int nX = anDX[i] + nUnitX;
        const int nY = anDY[i] + nUnitY;
        for (int j = 0; j < 2; ++j)
        {
            tMissile.nInitArg = j;
            tMissile.nTargetX = nX;
            tMissile.nTargetY = nY;
            sub_004CD540_CreateMissile(&tMissile);
        }
    }
}

// 0x004AD890
void __fastcall sub_004AD890_StateBurstOnFrame(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bSet, &nFrameCount);
    if (!pUnit || pUnit->dwAnimMode != 3 || bSet != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, MISSILE_LIGHTUNIQUE);
}

// 0x004AD8E0
void __fastcall sub_004AD8E0_StateBurst(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    if (pUnit && pUnit->dwAnimMode == 3)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, MISSILE_LIGHTUNIQUE);
}

// 0x004AD920
void __fastcall sub_004AD920_StateBurstNeutral(D2UnitStrc* pUnit, int nState, int bSet)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode != 3 && pUnit->dwAnimMode)
        return;
    if (nFrameNo != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, MISSILE_BUGLIGHTNING);
}

__forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004AD970
void __fastcall sub_004AD970_StateMissileSplit(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag || !pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    const int nMissileId = pUnit->dwClassId;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_004AC7E0(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pOwner);
    int nX;

    if (!pTarget)
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pPath);
        bFlag = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nX = CLIENTS_GetUnitX(pTarget);
        bFlag = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 'SEIS');
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDX = CLIENTS_GetUnitX(pOwner) - nX;
    int nDY = CLIENTS_GetUnitY(pOwner) - bFlag;

    if (nDX < 0)
    {
        nDX = -1;
    }
    else if (nDX > 0)
    {
        nDX = 1;
    }

    if (nDY < 0)
    {
        nDY = -1;
    }
    else if (nDY > 0)
    {
        nDY = 1;
    }

    switch (nMissileId)
    {
    case MISSILE_MUMMY1:
    case 63 + 1:
    case 63 + 2:
    case MISSILE_MUMMY4:
        nDY = 0;
        nDX = 0;
        break;
    }

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 0x80;
        }
    }

    sub_004CDBA0_SubmitOwnerRequest(pOwner, nMissileId, nX - nDY, bFlag + nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));
    sub_004CDBA0_SubmitOwnerRequest(pOwner, nMissileId, nX + nDY, bFlag - nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~0x80;
        }
    }
}

// 0x004ADCE0
void __fastcall sub_004ADCE0_StateRequests(D2UnitStrc* pUnit)
{
    int nX = GetUnitPathX(pUnit);
    int nY = GetUnitPathY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x221, nX, nY, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004ADD80
void __fastcall sub_004ADD80_StateRequestsCallback(D2UnitStrc* pUnit, int nState, int bFlag)
{
    sub_004ADCE0_StateRequests(pUnit);
}

// 0x004AE080
extern "C" int __fastcall sub_004AE080_MaskedPayloadWord(UnitView* unit, unsigned short mask)
{
    if (unit && unit->type == 1)
    {
        PayloadView* data = unit->payload;
        if (data)
            return data->flags28 & mask;
    }
    return 0;
}

extern "C" int __fastcall sub_004AE130_GetPayloadValue(UnitView* unit)
{
    PayloadView* data = (unit && unit->type == 1) ? unit->payload : 0;
    if (!data)
        return -1;
    return data->value3c;
}

// 0x004B2E70
int __cdecl sub_004B2E70_MenuBack()
{
    if (gnGlobal_007C0D31 == 5)
    {
        if (gpRes_007C0D5F)
        {
            sub_004B8020(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B1E80_OpenTimedDialog36();
        return 1;
    }
    if (gnGlobal_007C0C6B == 4)
    {
        if (gpRes_007C0D5F)
        {
            sub_004B8020(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B2650(0, 0);
        return 1;
    }
    sub_00466FE0();
    D2_ASSERT(gnGlobal_007C0C6B != 4, 0x14F9);
    return 1;
}

// 0x004B2F00
int __cdecl sub_004B2F00_MenuClose()
{
    sub_004B8020(gpRes_007C0D5F);
    gpRes_007C0D5F = 0;
    if (gnGlobal_007C0D31 == 5)
    {
        sub_004B5C60_Handler();
        return 1;
    }
    sub_00487C20_ResetButtonsFromState5();
    gnGlobal_007C0C6B = 3;
    sub_00466FE0();
    return 1;
}

// 0x004B3360
void __fastcall sub_004B3360(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x13E && pUnit->dwAnimMode == 2)
        gbFound_007C0DDA = 1;
}

// 0x004B35B0
int __cdecl sub_004B35B0_NpcMenuHandler()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    sub_00455F20(8, 1, 0);
    sub_00453AE0();
    sub_00487990_ResetHover();
    gnGlobal_007C0C6B = 7;
    gnGlobal_007C0D31 = 0;
    sub_004C0620_OpenPanelMode1(gnGlobal_007C0D25);
    return 1;
}

// 0x004B3660
int __cdecl sub_004B3660_TradeMenuHandler()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    const int nCount = gpTradeObj_007C0D83->GetCount();
    gnGlobal_007C0C60 = nCount;
    gnGlobal_007C0C64 = gnGlobal_007C0D25;
    if (nCount < 10 && gpTradeObj_007C0D83->GetAt(nCount) < 10)
    {
        if (sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) == -1
            && (!sub_0044DCC0() || (!sub_00478EE0_CountPets(sub_00463DD0_GetPlayerUnit(), 7) && gwGlobal_00725494 == 0xFFFF)))
        {
            sub_004B1E80_OpenTimedDialog36();
            return 0;
        }
        sub_004B3610_CloseTradeDialog();
    }
    return 0;
}

// 0x004B3700
int __cdecl sub_004B3700_InitHandler()
{
    gnGlobal_00726CC1 = 4;
    gpfnGlobal_00726CD7 = sub_004B35B0_NpcMenuHandler;
    gwGlobal_00726CC9 = 0xFB1;
    return 1;
}

// 0x004B3730
int __cdecl sub_004B3730_InitHandler()
{
    gnGlobal_0072723D = 4;
    gpfnGlobal_00727253 = sub_004B35B0_NpcMenuHandler;
    gwGlobal_00727245 = 0x58DC;
    return 1;
}

// 0x004B3760
int __cdecl sub_004B3760_InitHandler()
{
    gnGlobal_0072728B = 5;
    gpfnGlobal_007272A5 = sub_004B35B0_NpcMenuHandler;
    gwGlobal_00727295 = 0x58DD;
    return 1;
}

// 0x004B3C00
void __fastcall sub_004B3C00(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 0 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

void __fastcall sub_004B1980_AddUsedString(unsigned short wStringId)
{
    if (gtStringList_007C0D9A.wCount < 9)
    {
        gtStringList_007C0D9A.awStrings[gtStringList_007C0D9A.wCount] = wStringId;
        gtStringList_007C0D9A.wCount++;
    }
}

// 0x004B4010
int __cdecl sub_004B4010_NpcMenuCloseDialog6F()
{
    if (gbGlobal_007C0C69)
        return 0;

    if (gpDialog_007C0D6F)
    {
        sub_004B8020(gpDialog_007C0D6F);
        gpDialog_007C0D6F = 0;
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }
    return 1;
}

// 0x004B40D0
static void __stdcall sub_004B40D0_ShowNpcMessage(char bFlag, int nIndex)
{
    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    if (!pNpc)
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gbGlobal_007C0C69 = 1;
    sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
    sub_004B8020(gpRes_007C0D6F);
    gpRes_007C0D6F = 0;
    gpNpcEntry_007C0C7D->bSelected = 1;
    if (!gbGlobal_007C0C6A)
    {
        sub_004B17A0();
        if (bFlag)
            nIndex = gpNpcEntry_007C0C7D->nIndex;
    }
    D2UnitStrc* pUnit = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    sub_004A10E0(pUnit, gpNpcEntry_007C0C7D->pMessages[nIndex % gpNpcEntry_007C0C7D->nCount].nMessage, 0);
}

// 0x004B41C0
int __cdecl sub_004B41C0_NextNpcMessage()
{
    sub_004B40D0_ShowNpcMessage(1, gpNpcEntry_007C0C7D->nIndex);
    return 1;
}

// 0x004B41E0
int __cdecl sub_004B41E0_GreetNpcMessage()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    if (gnGlobal_007C0D29)
    {
        D2UnitStrc* pNpc = sub_00463990(gnGlobal_007C0D25, 1);
        if (pNpc)
        {
            switch (pNpc->dwClassId)
            {
            case MONSTER_MALAH:
                if (nClass == 4)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xF);
                    return 1;
                }
                break;
            case MONSTER_NIHLATHAK:
                if (nClass == 2)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xB);
                    return 1;
                }
                break;
            case MONSTER_QUAL_KEHK:
                if (nClass == 3)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xA);
                    return 1;
                }
                break;
            }
        }
    }
    if (nClass == gpNpcEntry_007C0C7D->pMessages[1].nClass)
        sub_004B40D0_ShowNpcMessage(0, 1);
    else
        sub_004B40D0_ShowNpcMessage(0, 0);
    return 1;
}

// 0x004B4290
int __cdecl sub_004B4290_NpcMenuSend38()
{
    sub_004B4070();
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, 0);
    return 1;
}

// 0x004B42B0
int __cdecl sub_004B42B0_NpcMenuTrade()
{
    if (gnNpcSoundActive_007C0DB4)
    {
        if (gnNpcSoundHandle_007C0DB8)
        {
            sub_004BA840(gnNpcSoundHandle_007C0DB8);
            gnNpcSoundHandle_007C0DB8 = 0;
        }
        gnNpcSoundActive_007C0DB4 = 0;
    }

    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0D25, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 1;
    }

    gnGlobal_007C0C6B = 3;
    gdwGlobal_007C0DB0 = 0;
    sub_00455F20(0xC, 0, 0);
    sub_004786D0_SendDwords3(0x38, 1, gnGlobal_007C0D25, 0);
    gpUnit_007C0DD4 = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B45D0
int __cdecl sub_004B45D0_NpcMenuCancel()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B4620
int __cdecl sub_004B4620_NpcMenuCancelB()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B4670
int __cdecl sub_004B4670_NpcMenuCancelText()
{
    if (gpDialog_007C0D7B)
    {
        sub_004B8020(gpDialog_007C0D7B);
        gpDialog_007C0D7B = 0;
        sub_004786A0_SendDwords2(0x31, gnGlobal_007C0D25, gwGlobal_007C0C77);
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B46D0
int __cdecl sub_004B46D0_NpcMenuCancelTextB()
{
    if (gpDialog_007C0D7B)
    {
        sub_004B8020(gpDialog_007C0D7B);
        gpDialog_007C0D7B = 0;
        sub_004786A0_SendDwords2(0x31, gnGlobal_007C0D25, gwGlobal_007C0C77);
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B4730
int __cdecl sub_004B4730_NpcMenuTalk()
{
    if (gpDialog_007C0D7B)
    {
        sub_004B8020(gpDialog_007C0D7B);
        gpDialog_007C0D7B = 0;
    }

    if (!(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 1;
    }

    sub_004A10E0(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0, gwGlobal_007C0C77, 0);
    sub_004B1980_AddUsedString(gwGlobal_007C0C77);
    if (gwGlobal_007C0C79 == 0xFFFF)
    {
        gnGlobal_007C0C6B = 0;
    }
    else
    {
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B6A30_NpcTextCallback, 0);
    }
    sub_004786A0_SendDwords2(0x31, gnGlobal_007C0D25, gwGlobal_007C0C77);
    return 1;
}

static inline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25,1):0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
static int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords)
{
    if(NPC_GetInteractUnit_Inline())
    {
        UNITS_GetClientCoords(NPC_GetInteractUnit_Inline(),pCoords);
        tagRECT tView;
        sub_00476070_GetViewRect(gpView_007A0640,&tView.left,&tView.top,&tView.right,&tView.bottom);
        D2CoordStrc tOffset;
        sub_004760C0_GetViewOffset(gpView_007A0640,&tOffset.nX,&tOffset.nY);
        tagRECT tRect;
        SetRect(&tRect,tOffset.nX,tOffset.nY,tOffset.nX+(tView.right-tView.left),tOffset.nY+(tView.bottom-tView.top));
        pCoords->nY += -150-tRect.top;
        pCoords->nX -= tRect.left;
        if(pCoords->nY<20)pCoords->nY=20;
        return 1;
    }
    return 0;
}

static __forceinline int NPC_FindIndex_Inline(D2UnitStrc* pNpc)
{
    if(!pNpc)return -1;
    const int nId=pNpc->dwClassId;
    for(int i=0;i<gnNpcIndexCount_00725A74;++i)
        if(gaNpcIndex_00726C48[i].nId==nId)return i;
    return 0;
}

// 0x004B4830
void __cdecl sub_004B4830_Rebuild()
{
    if(gpDialog_007C0D6B){sub_00408A60(&gszEmptyAssertText,sub_00408090(),0xC74);exit(-1);}
    if(!NPC_GetInteractUnit_Inline())
    {
        gnGlobal_007C0C6B=0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8,1,0);
        return;
    }
    if(gnGlobal_007C0D2D==252 || gnGlobal_007C0D2D==198 || gnGlobal_007C0D2D==515 || gnGlobal_007C0D2D==150)
    {
        D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
        sub_004786D0_SendDwords3(0x38,3,gnGlobal_007C0D25,!pPlayer?-1:pPlayer->dwUnitId);
    }
    D2CoordStrc tCoords;
    tCoords.nX=0;
    tCoords.nY=0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);
    gpDialog_007C0D6B=sub_004B7EB0_CreateDialog(tCoords.nX,tCoords.nY,sub_004B45D0_NpcMenuCancel,sub_004B4620_NpcMenuCancelB,0,0,1,0,0,0,1);
    sub_004B8370(gpDialog_007C0D6B,1);
    Unicode wszName[80];
    sub_005267E0(wszName,sub_00464A60_GetUnitName(NPC_GetInteractUnit_Inline()));
    sub_00526800(wszName);
    sub_004B85F0_AddTextLine(gpDialog_007C0D6B,wszName,21,0,4,1,0,0);
    int nIndex=NPC_FindIndex_Inline(NPC_GetInteractUnit_Inline());
    if(nIndex<0 || nIndex>=gnNpcIndexCount_00725A74)return;
    gnGlobal_007C0C6B=1;
    for(int i=0;i<gaNpcIndex_00726C48[nIndex].nCount-1;++i)
    {
        Unicode wszLine[512];
        unsigned short nStringId=gaNpcIndex_00726C48[nIndex].awIds[i];
        int bEnabled=1;
        if(nStringId==0x1507)
        {
            const Unicode* wszHireling=D2LANG_GetStringFromTblIndex(0x2B0D);
            if((unsigned short)gnHirelingName_00725494!=0x421)wszHireling=D2LANG_GetStringFromTblIndex((unsigned short)gnHirelingName_00725494);
            sub_005269D0(512,wszLine,D2LANG_GetStringFromTblIndex(0x58A8),wszHireling,gnGlobal_007C0DD0);
        }
        else if(nStringId==0xD09)
        {
            int nLife=STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(),STAT_HITPOINTS,0);
            if(nLife>=STATLIST_GetMaxLifeFromUnit(sub_00463DD0_GetPlayerUnit()))continue;
            int nCost=UNITS_GetHealingCost(sub_00463DD0_GetPlayerUnit());
            if(!nCost)nCost=1;
            sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(gaNpcIndex_00726C48[nIndex].awIds[i]));
            Unicode wszNumber[10] = {0,0,0,0,0,0,0,0,0,0};
            char szNumber[12];
            wsprintfA(szNumber,gszFormatD,nCost);
            sub_00526F20_ToUnicode(wszNumber,szNumber,9);
            sub_00526700(wszLine,wszNumber);
            if(!nCost)bEnabled=0;
        }
        else if(nStringId==0xFB4)
        {
            int bCharge=0;
            if(!QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,4,0) && !QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,4,1))bCharge=1;
            int nCount=ITEMS_GetNoOfUnidItems(sub_00463DD0_GetPlayerUnit());
            if(nCount)
            {
            gaNpcIndex_00726C48[nIndex].nCount=3;
            if(bCharge)
            {
                sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(0xFB5));
                UnicodeChar wszNumber[10];
                char szNumber[12];
                nCount*=100;
                wsprintfA(szNumber,gszFormatD,nCount);
                sub_00526F20_ToUnicode(wszNumber,szNumber,9);
                sub_00526700(wszLine,wszNumber);
            }
            else sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(0xFB4));
            }
            else {gaNpcIndex_00726C48[nIndex].nCount=2;continue;}
        }
        else if(nStringId==0x2BA0)
        {
            if(QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,41,0))continue;
            if(QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,41,1)!=1)
            {
                if(sub_0044DCD0_GetDifficulty()!=2 || QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43,41,1))continue;
            }
            sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(gaNpcIndex_00726C48[nIndex].awIds[i]));
        }
        else sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(nStringId));
        sub_004B85F0_AddTextLine(gpDialog_007C0D6B,wszLine,15,0,0,1,gaNpcIndex_00726C48[nIndex].apfHandlers[i],bEnabled);
    }
    sub_004B85F0_AddTextLine(gpDialog_007C0D6B,D2LANG_GetStringFromTblIndex(0x102E),15,0,0,1,sub_004B45D0_NpcMenuCancel,1);
}

// 0x004B4CF0
int __cdecl sub_004B4CF0_NpcMenuReturn()
{
    sub_00466FE0();
    sub_004B9A00(1, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0D63);
    gpDialog_007C0D63 = 0;
    if (gnGlobal_007C0C6B == 0xC)
    {
        if (gnGlobal_007C0D31 == 5)
        {
            sub_004B3C20(gnGlobal_007C0D25);
            sub_00455F20(8, 1, 0);
            return 1;
        }
        sub_004B4830_Rebuild();
        return 1;
    }

    D2_ASSERT(gnGlobal_007C0D31 != 6, 0xD55);
    D2_ASSERT(gnGlobal_007C0C6B != 8, 0xD56);
    gnGlobal_007C0C6B = 3;
    sub_00487D40_ResetButtonsFromState7();
    return 1;
}

// 0x004B5140
int __cdecl sub_004B5140_NpcMenuAction28()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, 0x28);
    return 1;
}

// 0x004B51A0
int __cdecl sub_004B51A0_NpcMenuAction4B()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, 0x4B);
    return 1;
}

// 0x004B5200
int __cdecl sub_004B5200_NpcMenuAction6D()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, 0x6D);
    return 1;
}

// 0x004B5260
int __cdecl sub_004B5260_NpcMenuAction28b()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, 0x28);
    return 1;
}

// 0x004B52C0
int __cdecl sub_004B52C0_NpcMenuAction01()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, 1);
    return 1;
}
