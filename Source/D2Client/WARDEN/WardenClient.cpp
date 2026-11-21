#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2ClientGame.h"
#include "D2StormTypes.h"
#include "D2Win32Types.h"
#include "D2ItemsWorld.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)

#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)

#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)

#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2RectStrc;

struct T00479230;

struct D2WaypointMenuEntryStrc;

struct D2WaypointActRangeStrc;

struct D2AreaScanFindStrc;

struct D2SetItemsTxt;

struct D2SkillsTxt;

struct D2MonStatsTxt;

struct D2RequestStrc;

struct D2RosterPetStrc;

struct D2OptionHeaderStrc;

struct D2OptionEntryStrc;

struct D2EscMenuUIStateStrc;

struct D2InvRectStrc;

class WardenModule;


struct D2ClientSlotObjStrc;


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct T00479230
{
    char unk0x00[0x16];
    char nScroll[4];
    char unk0x1A[0x12];
};

struct D2WaypointActRangeStrc
{
    char bInit;
    char nFirstLevelId[4];
    char nLastLevelId[4];
    unsigned char nMinWaypoint;
    unsigned char nMaxWaypoint;
};

struct D2AreaScanFindStrc
{
    int nFirst;
    int nBest;
    int nSecond;
    int nArgA;
    int nArgB;
    int nOut;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nArg0;
    int nArg1;
    int nArg2;
    int unk0x1C[4];
    int nArg3;
    int nArg4;
    int unk0x34[10];
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl sub_0047A560(); // 0x0047A560

int __cdecl sub_004B8A10(); // 0x004B8A10

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __cdecl sub_0044DA40(); // 0x0044DA40

int __cdecl sub_0045AE90(); // 0x0045AE90

extern "C" int __cdecl sub_0045AFC0(); // 0x0045AFC0

extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset(); // 0x0045AFD0

int __cdecl sub_0044DCC0(); // 0x0044DCC0

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode); // 0x0046E570

void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046E5A0

void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80

int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0

D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

void __fastcall sub_004CEFE0_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nArg1, int nArg2, int nArg3); // 0x004CEFE0

int __fastcall sub_004DB0D0_UpdateGfxEntry(void* pEntry, int nArg); // 0x004DB0D0

int __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pItem, int nArg1, int nArg2, int nArg3, int nProp, int nArg5, int nArg6, int nArg7); // 0x004E60A0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370

D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490

int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nState); // 0x0063A7B0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

void __cdecl sub_00466FE0(); // 0x00466FE0

void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430

T00479230* __fastcall sub_004A05E0_CreateTextBox(const Unicode* wszText, int nMode); // 0x004A05E0

void __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __fastcall sub_004C5E70_FindCallback(void* pArg, D2UnitStrc* pUnit); // 0x004C5E70

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId); // 0x004E0650

int __cdecl sub_004F59A0(); // 0x004F59A0

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0

void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg); // 0x004912A0

int __stdcall sub_004934D0_CheckBoxAction(int nArg); // 0x004934D0

int __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt); // 0x004A8C80

int __fastcall sub_004A8D30_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004A8D30

void __fastcall sub_004A9690_DrawSkillInfoBase(int nValue, D2SkillsTxt* pSkillsTxt, int nOwnerGUID, int nCharges, int nState, int nX, int nY, int nArg); // 0x004A9690

void __fastcall sub_004A8D50_UpdateButton(short* pId, int nState, int nA, int nB, int nX, int nY); // 0x004A8D50

void __fastcall sub_004AA1F0_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

int __stdcall WAYPOINTS_GetLevelIdFromWaypointNo(unsigned short wWaypointNo, int* pLevelId); // 0x00660D90

int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00

int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall sub_00463E50_GetGfxField34(D2UnitStrc* pUnit); // 0x00463E50

int __fastcall sub_00463EB0_GetGfxField38(D2UnitStrc* pUnit); // 0x00463EB0

int __fastcall sub_004791B0_IsOwnedByPlayer(D2UnitStrc* pUnit); // 0x004791B0

void __cdecl sub_0047B9C0_RecallChatLine(); // 0x0047B9C0

void __stdcall sub_0047BA80_StepChatIndex(int nDelta); // 0x0047BA80

extern const int gdwBitMasks[]; // 0x006CE268

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern int gaSetPartialCounts_006DBD90[]; // 0x006DBD90

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern D2OptionHeaderStrc gOptionHeader_00713044; // 0x00713044

extern D2EscMenuUIStateStrc gaEscMenuUIState_00713058[38]; // 0x00713058

extern D2OptionEntryStrc gaOptionEntries_00713220[]; // 0x00713220

extern D2OptionHeaderStrc gOptionHeader_00714210; // 0x00714210

extern D2OptionHeaderStrc gOptionHeader_00714224; // 0x00714224

extern D2OptionEntryStrc gaOptionEntries_00714238[]; // 0x00714238

extern D2OptionEntryStrc gaOptionEntries_00715CC8[]; // 0x00715CC8

extern D2OptionHeaderStrc gOptionHeader_00718748; // 0x00718748

extern D2OptionHeaderStrc gOptionHeader_0071875C; // 0x0071875C

extern D2OptionEntryStrc gaOptionEntries_00718770[]; // 0x00718770

extern D2OptionEntryStrc gaOptionEntries_0071ACA0[]; // 0x0071ACA0

extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[]; // 0x00722600

extern D2WaypointActRangeStrc gaWaypointActRanges_007224AC[]; // 0x007224AC

extern D2OptionHeaderStrc gOptionHeader_0071D720; // 0x0071D720

extern D2OptionHeaderStrc gOptionHeader_0071D734; // 0x0071D734

extern D2OptionEntryStrc gaOptionEntries_0071D748[]; // 0x0071D748

extern D2OptionEntryStrc gaOptionEntries_0071F728[]; // 0x0071F728

extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0

extern D2OptionHeaderStrc* gpOptionHeader_007BC93C; // 0x007BC93C

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern char gbGlobal_007BF085; // 0x007BF085

extern int gnWaypointCount_007BF08A; // 0x007BF08A

extern int gnWaypointEnabled_007BF08E; // 0x007BF08E

extern T00479230* gpTextBox_007BF0A4; // 0x007BF0A4

extern int gnGlobal_007BF1BC; // 0x007BF1BC

extern int gnGlobal_007BF1C0; // 0x007BF1C0

extern unsigned long gnGlobal_007BF22C; // 0x007BF22C

extern int gbTextSound_007BF230; // 0x007BF230

extern int gbTextSide_007BF236; // 0x007BF236

extern int gnGlobal_007BEEE8; // 0x007BEEE8

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

struct D2ClientSlotObjStrc
{
    virtual void Slot0(int* pValue, int nSize);
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
    virtual void Slot3(int nArg);
};

struct D2WardenIfaceStrc;

typedef D2ClientSlotObjStrc* (__fastcall* WARDENCREATEFN)(D2WardenIfaceStrc* pIface);

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();                                                                // 0x004E06A0
    void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x10D, 0);
    }
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }
    bool sub_004E0730_Load(void* pData, int nSize);                         // 0x004E0730
    void* sub_004E0700_GetProc(int nOrdinal);                                // 0x004E0700

    void* pImage;
    int unk0x04;
    int nImports;
    D2ClientSlotObjStrc* pObj;
    WARDENCREATEFN pfnCreate;
};

struct D2Warden47F930Strc
{
    int n00;
    int n04;
    int n08;

    D2Warden47F930Strc();
};

struct D2WardenModuleHolderAStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderAStrc();
};

struct D2WardenModuleHolderBStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderBStrc();
};

namespace NWardenClient
{
struct Library
{
    Library();
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
};
}

struct D2StormHashCtxStrc;

struct D2RC4Strc;

struct D2WardenFindArgStrc;

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

struct D2StormHashCtxStrc
{
    unsigned __int64 nBitCount;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void sub_00425D90_Init();                                               // 0x00425D90
    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen); // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                        // 0x00425F00
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize); // 0x004E09B0
    void sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

struct D2WardenFindArgStrc
{
    int unk0x00;
    int unk0x04;
};

struct D2ClientServiceStrc
{
    char unk0x00[0xC8];
    void (__fastcall* pfnFree)(void* pData, int nSize);
    int (__fastcall* pfnFind)(char* szName, int* pArg, void** ppData, int* pSize);
    void (__fastcall* pfnCall)(const char* szName, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

extern WardenModule* gpPendingWarden_007BC994; // 0x007BC994

extern D2ClientServiceStrc* gpService_007BC998; // 0x007BC998

static void __stdcall sub_0047F990_HashModule(const char* szName, unsigned char* pDigest, const unsigned char* pData, unsigned int nSkip, unsigned int nSize);

static int __stdcall sub_0047FEE0_LoadModuleByKey(const unsigned char* pRc4Key, const unsigned char* pModuleKey);

static void __stdcall sub_0047F990_HashModule(const char* szName, unsigned char* pDigest, unsigned int nSkip, const unsigned char* pData, unsigned int nSize);

static int __stdcall sub_0047FA20_VerifyModuleSignature(const char* szName, unsigned char* pData, const unsigned char* pModulus, const unsigned char* pExponent, unsigned int nExponentSize, unsigned int nSkip, unsigned int nSize, unsigned int nSignatureSize);

void __cdecl sub_00480230(); // 0x00480230

extern WardenModule* gpSlotHolder_007BC990; // 0x007BC990

int gnOptionSelected_007BC938; // 0x007BC938

D2OptionEntryStrc* gpOptionEntries_007BC940; // 0x007BC940

static int gnGlobal_007BCA4C; // 0x007BCA4C

static int gnGlobal_007BCBD8; // 0x007BCBD8

static int gnGlobal_007BEECC; // 0x007BEECC

D2WaypointMenuEntryStrc gaWaypointEntries_007BF03C[9]; // 0x007BF03C

unsigned short gwTextStringId_007BF212; // 0x007BF212

int gnHintId_007BF260; // 0x007BF260

int gnGlobal_007BF278; // 0x007BF278

static int gbStarted_007BF27C; // 0x007BF27C

int gnGlobal_007BEED4; // 0x007BEED4

void* gpWardenBuffer_007BC988; // 0x007BC988

unsigned int gnWardenBufferSize_007BC98C; // 0x007BC98C

static int __stdcall sub_0047FC70_LoadModule(const unsigned char* pData, const unsigned char* pKey, unsigned int nSize);

int __fastcall sub_004803C0_InitWarden(int nValue);

bool __stdcall sub_00480020_LoadModuleByKey(const unsigned char* pModuleKey, const unsigned char* pRc4Key);



extern D2WardenIfaceStrc gWardenIface_00721C98; // 0x00721C98


// 0x00479230
void __fastcall sub_00479230_UpdateOwnerPetFlags(int nOwnerId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwOwnerId == nOwnerId)
        {
            switch (pPet->nClassId)
            {
            case 0x16B:
            case 0x16C:
            {
                D2UnitStrc* pUnit = sub_00463990(pPet->dwUnitId, UNIT_MONSTER);
                if (pUnit)
                {
                    int nFlagB = sub_00463EB0_GetGfxField38(pUnit);
                    int bSet = !sub_004791B0_IsOwnedByPlayer(pUnit);
                    if (nFlagB == sub_00463E50_GetGfxField34(pUnit))
                    {
                        sub_00463E80_SetUnitFlagB(pUnit, bSet);
                    }
                    sub_00463E20_SetUnitFlagA(pUnit, bSet);
                }
                break;
            }
            }
        }
    }
}

// 0x0047BCA0
void __stdcall sub_0047BCA0_ChatKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (pMsg->lParam & 0x40000000)
    {
        return;
    }
    int nKey = pMsg->wParam;
    switch (nKey)
    {
    case 0x26:
        sub_0047B9C0_RecallChatLine();
        sub_0047BA80_StepChatIndex(1);
        break;
    case 0x28:
        sub_0047BA80_StepChatIndex(-1);
        sub_0047B9C0_RecallChatLine();
        break;
    }
}

// 0x0047E090
void __fastcall sub_0047E090(int bSaveState, int nMenu)
{
    if (bSaveState)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            gaEscMenuUIState_00713058[i].nSaved = 0;
            if (gaEscMenuUIState_00713058[i].bCheck)
            {
                if (gaEscMenuUIState_00713058[i].bSave)
                {
                    gaEscMenuUIState_00713058[i].nSaved = sub_004538D0(i);
                }
                if (sub_004538D0(i))
                {
                    sub_00455F20(i, 1, 0);
                }
            }
        }
    }
    sub_00455F20(9, 0, 0);
    switch (nMenu)
    {
    case 0:
        gpOptionHeader_007BC93C = &gOptionHeader_00713044;
        gpOptionEntries_007BC940 = gaOptionEntries_00713220;
        break;
    case 1:
        gpOptionHeader_007BC93C = &gOptionHeader_00714210;
        gpOptionEntries_007BC940 = gaOptionEntries_00714238;
        break;
    case 2:
        gpOptionHeader_007BC93C = &gOptionHeader_00714224;
        gpOptionEntries_007BC940 = gaOptionEntries_00715CC8;
        break;
    case 3:
        if (sub_00408F20_HasExpansionMpq())
        {
            gpOptionHeader_007BC93C = &gOptionHeader_0071875C;
            gpOptionEntries_007BC940 = gaOptionEntries_0071ACA0;
        }
        else
        {
            gpOptionHeader_007BC93C = &gOptionHeader_00718748;
            gpOptionEntries_007BC940 = gaOptionEntries_00718770;
        }
        break;
    case 4:
        if (sub_00408F20_HasExpansionMpq())
        {
            gpOptionHeader_007BC93C = &gOptionHeader_0071D734;
            gpOptionEntries_007BC940 = gaOptionEntries_0071F728;
        }
        else
        {
            gpOptionHeader_007BC93C = &gOptionHeader_0071D720;
            gpOptionEntries_007BC940 = gaOptionEntries_0071D748;
        }
        break;
    }
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
    if (nMenu == 5)
    {
        gnOptionSelected_007BC938 = 1;
    }
}

// build: symbol ??_7Library@NWardenClient@@6B@ 0x006D8E38
// 0x0047F8B0
void __fastcall sub_0047F8B0_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x0047F930
D2Warden47F930Strc::D2Warden47F930Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

// 0x0047F940
D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

// 0x0047F990
static void __stdcall sub_0047F990_HashModule(const char* szName, unsigned char* pDigest, const unsigned char* pData, unsigned int nSkip, unsigned int nSize)
{
    D2StormHashCtxStrc tCtx;
    char szBuffer[0x400];
    tCtx.sub_00425D90_Init();
    if (nSkip)
    {
        tCtx.sub_00425DD0_Update(pData + nSkip, nSize - nSkip);
        tCtx.sub_00425DD0_Update(pData, nSkip);
    }
    else
    {
        tCtx.sub_00425DD0_Update(pData, nSize);
    }
    SStrCopy(szBuffer, szName, 0x400);
    sub_004141E0_StrUpper(szBuffer);
    tCtx.sub_00425DD0_Update((const unsigned char*)szBuffer, SStrLen(szBuffer));
    tCtx.sub_00425F00_Final(pDigest);
}

static inline int WardenReadTag(const unsigned char* pSource)
{
    int nTag;
    SMemCopy(&nTag, pSource, 4);
    return nTag;
}

// 0x0047FA20
static int __stdcall sub_0047FA20_VerifyModuleSignature(const char* szName, unsigned char* pData, const unsigned char* pModulus, const unsigned char* pExponent, unsigned int nExponentSize, unsigned int nSkip, unsigned int nSize, unsigned int nSignatureSize)
{
    D2_ASSERT(nSkip <= nSize, 0xA3);
    unsigned int nDataSize = nSize - nSignatureSize - 4;
    unsigned char* pSignature;
    if (nSize < nSignatureSize + 4)
    {
        goto fail;
    }
    pSignature = pData + nDataSize;
    if (WardenReadTag(pSignature) != 0x5349474E)
    {
fail:
        return 0;
    }
    unsigned char* pExpected = (unsigned char*)SMemAlloc(nSignatureSize, ".\\WARDEN\\WardenClient.cpp", 0xAB, 0);
    SMemFill(pExpected, nSignatureSize, 0xBB);
    pExpected[nSignatureSize - 1] = 0x0B;
    sub_0047F990_HashModule(szName, pExpected, pData, nSkip, nDataSize);
    unsigned char* pDecrypted = (unsigned char*)SMemAlloc(nSignatureSize, ".\\WARDEN\\WardenClient.cpp", 0xB5, 0);
    SMemCopy(pDecrypted, pSignature + 4, nSignatureSize);
    void* hResult;
    void* hSignature;
    void* hExponent;
    void* hModulus;
    SBigNew(&hResult);
    SBigNew(&hSignature);
    SBigNew(&hExponent);
    SBigNew(&hModulus);
    SBigFromBinary(hSignature, pDecrypted, nSignatureSize);
    SBigFromBinary(hExponent, pExponent, nExponentSize);
    SBigFromBinary(hModulus, pModulus, nSignatureSize);
    SBigPowMod(hResult, hSignature, hExponent, hModulus);
    SBigToBinaryBuffer(hResult, pDecrypted, nSignatureSize, 0);
    int bValid = !SMemCmp(pDecrypted, pExpected, nSignatureSize);
    SMemFree(pExpected, ".\\WARDEN\\WardenClient.cpp", 0xCC, 0);
    SMemFree(pDecrypted, ".\\WARDEN\\WardenClient.cpp", 0xCD, 0);
    SBigDel(hResult);
    SBigDel(hSignature);
    SBigDel(hExponent);
    SBigDel(hModulus);
    return bValid;
}

// 0x0047FBC0
WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    pObj = 0;
    pfnCreate = 0;
}

// 0x0047FBE0
D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

// 0x0047FBF0
void* __fastcall sub_0047FBF0_WardenAlloc(unsigned int nSize)
{
    return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x10D, 0);
}

// 0x0047FC10
void __fastcall sub_0047FC10_WardenFree(void* pMemory)
{
    SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
}

// 0x0047FC30
NWardenClient::Library::Library()
{
}

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// build: symbol ??_GWardenModule@@QAEPAXI@Z 0x0047FC40
// 0x0047FC40

// 0x0047FC70
static int __stdcall sub_0047FC70_LoadModule(const unsigned char* pData, const unsigned char* pKey, unsigned int nSize)
{
    char szName[10];
    szName[0] = (char)0x5F;
    szName[1] = (char)0x7B;
    szName[2] = (char)0x53;
    szName[3] = (char)0xE7;
    szName[4] = (char)0xF2;
    szName[5] = (char)0x5A;
    szName[6] = (char)0xBF;
    szName[7] = (char)0x75;
    szName[8] = (char)0x8C;
    szName[9] = 0;
    for (unsigned int i = 0; i < 10; ++i)
    {
        szName[i] *= 0xD3;
    }
    if (gpPendingWarden_007BC994)
    {
        gpPendingWarden_007BC994->~WardenModule();
        delete gpPendingWarden_007BC994;
        gpPendingWarden_007BC994 = 0;
    }
    unsigned char* pBuffer = (unsigned char*)SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x16E, 0);
    SMemCopy(pBuffer, pData, nSize);
    if (!pBuffer)
    {
        return 0;
    }
    D2RC4Strc tRc4;
    tRc4.sub_004E09B0_Init(pKey, 0x10);
    tRc4.sub_0047F8C0_Crypt(pBuffer, nSize);
    if (!sub_0047FA20_VerifyModuleSignature(szName, pBuffer, gabModulus_006D8D18, gabExponent_006D8D14, 4, 0, nSize, 0x100))
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x17C, 0);
        return 0;
    }
    unsigned int nModuleSize = *(unsigned int*)pBuffer;
    unsigned char* pModule = (unsigned char*)SMemAlloc(nModuleSize, ".\\WARDEN\\WardenClient.cpp", 0x182, 0);
    if (!pModule)
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x185, 0);
        return 0;
    }
    if (sub_006C79C0_Decompress(pModule, &nModuleSize, pBuffer + 4, nSize - 4))
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x18D, 0);
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x18E, 0);
        return 0;
    }
    SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x193, 0);
    WardenModule* pWarden = new WardenModule;
    if (!pWarden)
    {
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x199, 0);
        return 0;
    }
    if (!pWarden->sub_004E0730_Load(pModule, nModuleSize))
    {
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1A0, 0);
        delete pWarden;
        return 0;
    }
    pWarden->pfnCreate = (WARDENCREATEFN)pWarden->sub_004E0700_GetProc(1);
    if (!pWarden->pfnCreate)
    {
        pWarden->~WardenModule();
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1AA, 0);
        delete pWarden;
        return 0;
    }
    SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1B0, 0);
    gpPendingWarden_007BC994 = pWarden;
    return 1;
}

// 0x0047FEE0
static int __stdcall sub_0047FEE0_LoadModuleByKey(const unsigned char* pRc4Key, const unsigned char* pModuleKey)
{
    if (!SMemCmp(pModuleKey, gabBuiltinModuleKey_006D8768, 0x10))
    {
        return sub_0047FC70_LoadModule(gabBuiltinModule_006D74B0, gabBuiltinModuleRc4Key_006D8778, 0x12B2);
    }
    char szName[0x28];
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        sprintf(&szName[i * 2], "%02x", pModuleKey[i]);
    }
    SStrCopy(&szName[0x20], ".mod", 5);
    if (!gpService_007BC998)
    {
        return 0;
    }
    D2WardenFindArgStrc tFindArg;
    void* pModule;
    int nModuleSize;
    if (!gpService_007BC998->pfnFind(szName, &tFindArg.unk0x00, &pModule, &nModuleSize))
    {
        return 0;
    }
    int nResult = sub_0047FC70_LoadModule((const unsigned char*)pModule, pRc4Key, nModuleSize);
    gpService_007BC998->pfnFree(pModule, nModuleSize);
    return nResult;
}

// 0x00480020
bool __stdcall sub_00480020_LoadModuleByKey(const unsigned char* pModuleKey, const unsigned char* pRc4Key)
{
    return sub_0047FEE0_LoadModuleByKey(pRc4Key, pModuleKey);
}

// 0x00480040
void __stdcall sub_00480040_CallServiceWithHashName(const unsigned char* pHash, int nArg2, int nArg3)
{
    char szName[40];
    for (unsigned int i = 0; i < 16; ++i)
        sprintf(&szName[i * 2], "%02x", pHash[i]);
    SStrCopy(&szName[32], ".mod", 5);
    if (!gpService_007BC998)
        return;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    gpService_007BC998->pfnCall(szName, nArg2, nArg3, &tTime, -1, -1);
}


// 0x004800C0
void* __stdcall sub_004800C0_WardenAlloc(int nSize)
{
    return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x274, 0);
}


// 0x004800E0
void __stdcall sub_004800E0_WardenFree(void* pMemory)
{
    SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x27B, 0);
}


// 0x00480100
void __stdcall sub_00480100_SetWardenBuffer(const void* pData, unsigned int nSize)
{
    if (gpWardenBuffer_007BC988)
    {
        SMemFree(gpWardenBuffer_007BC988, ".\\WARDEN\\WardenClient.cpp", 0x283, 0);
    }
    gpWardenBuffer_007BC988 = SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x284, 0);
    gnWardenBufferSize_007BC98C = nSize;
    sub_0041D2A0_MemCopy(gpWardenBuffer_007BC988, pData, nSize);
}

// 0x00480150
bool __stdcall sub_00480150_TakeWardenBuffer(void* pDst, unsigned int* pSize)
{
    void* pBuffer = gpWardenBuffer_007BC988;
    if (!pBuffer)
    {
        return false;
    }
    unsigned int nSize = *pSize < gnWardenBufferSize_007BC98C ? *pSize : gnWardenBufferSize_007BC98C;
    *pSize = nSize;
    sub_0041D2A0_MemCopy(pDst, pBuffer, nSize);
    SMemFree(gpWardenBuffer_007BC988, ".\\WARDEN\\WardenClient.cpp", 0x292, 0);
    gpWardenBuffer_007BC988 = 0;
    gnWardenBufferSize_007BC98C = 0;
    return true;
}

struct D2UnitStrc;

void WardenModule_EmitDelete(WardenModule* pModule)
{
    delete pModule;
}

// 0x004801D0
void __cdecl sub_004801D0_UnloadWarden()
{
    if (gpSlotHolder_007BC990)
    {
        gpSlotHolder_007BC990->pObj->Slot1();
        gpSlotHolder_007BC990->~WardenModule();
        delete gpSlotHolder_007BC990;
    }
    gpSlotHolder_007BC990 = 0;
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

// 0x00480320
void __fastcall sub_00480320_CallHolderSlot3(int nArg)
{
    if (gpSlotHolder_007BC990)
    {
        gpSlotHolder_007BC990->pObj->Slot3(nArg);
        sub_00480230();
    }
}


// 0x00480340
void __cdecl sub_00480340_ResetWarden()
{
    if (gpPendingWarden_007BC994)
    {
        gpPendingWarden_007BC994->~WardenModule();
        delete gpPendingWarden_007BC994;
        gpPendingWarden_007BC994 = 0;
    }
    sub_004801D0_UnloadWarden();
    gnWardenIfaceValue_00721C94 = -1;
    gpService_007BC998 = 0;
    if (gpWardenBuffer_007BC988)
        SMemFree(gpWardenBuffer_007BC988, ".\\WARDEN\\WardenClient.cpp", 0x24F, 0);
    gpWardenBuffer_007BC988 = 0;
    gnWardenBufferSize_007BC98C = 0;
}

// 0x004803C0
int __fastcall sub_004803C0_InitWarden(int nValue)
{
    sub_00480340();
    gnWardenIfaceValue_00721C94 = nValue;
    gpService_007BC998 = sub_00518C10();
    if (!gpService_007BC998)
    {
        return 0;
    }
    sub_0047FEE0_LoadModuleByKey(gabBuiltinModuleRc4Key_006D8778, gabBuiltinModuleKey_006D8768);
    sub_00480230();
    return 1;
}

// 0x004922A0
int __stdcall sub_004922A0_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
    {
        sub_004912A0_HandlePanelClick(pMsg);
        return 1;
    }
    return 0;
}

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

// 0x004936E0
void __stdcall sub_004936E0_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0044DCC0())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    const int bHit = gnGlobal_007BEECC != 2 && InBox(nX, nY, gnGlobal_007BEED4, gnGlobal_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gnGlobal_007BEEE8 = 0;
        return;
    }
    if (sub_004934D0_CheckBoxAction(1))
    {
        sub_004785B0_SendPacket3(0x61, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00496B10
void __cdecl sub_00496B10()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int bPanel = 0;
    int nYOffset = 0;
    if (!sub_0047A560())
    {
        return;
    }
    if (sub_004538D0(0x19) || sub_004538D0(0x0C) || sub_004538D0(0x18) || sub_004538D0(1) || sub_004538D0(4))
    {
        bPanel = 1;
    }
    if (sub_004538D0(0x17) && !sub_004B8A10())
    {
        return;
    }
    if (bPanel)
    {
        return;
    }
    tContext.pCellFile = gpCellFile_007BEF28;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    if (sub_004538D0(0x0A))
    {
        nYOffset = 0x46;
    }
    sub_004F6480(&tContext, gnGlobal_0071146C - 0x3A, nYOffset + 0x2D, -1, 1, 0);
}

// 0x00496BE0
void __fastcall sub_00496BE0_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg)
{
    if (!pUnit || !pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
    {
        return;
    }

    const int nValue = sub_004A8C80_GetSkillValue(pSkillsTxt);
    int nState = sub_004A8D30_GetSkillState(pUnit, pSkill);
    if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            nState = 1;
        }
    }

    int nOwnerGUID = -1;
    int nSkillLevel = 0;
    int nCharges = 0;
    const int bItemSkill = SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, 0, &nSkillLevel, &nCharges);
    if (!bItemSkill)
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    int nQuantity = 0;
    if (!bItemSkill)
    {
        nQuantity = SKILLS_GetQuantity(pSkill);
    }

    sub_004A9690_DrawSkillInfoBase(nValue, pSkillsTxt, nOwnerGUID, nCharges, nState, nX, nY, nArg);
    if (nQuantity)
    {
        sub_004AA1F0_DrawSkillQuantity(&pSkillsTxt->nSkillId, nState, nQuantity, nX, nY);
    }
    else
    {
        sub_004A8D50_UpdateButton(&pSkillsTxt->nSkillId, nState, nSkillLevel, nCharges, nX, nY);
    }
}

// 0x0049C7F0
void __cdecl sub_0049C7F0_BuildWaypointList()
{
    gnWaypointCount_007BF08A = 0;
    gnWaypointEnabled_007BF08E = 0;
    const int nCurrentLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));

    for (int i = 0; i < 9; ++i)
    {
        *(int*)gaWaypointEntries_007BF03C[i].nLevelId = 0;
        gaWaypointEntries_007BF03C[i].bEnabled = 0;
    }

    if ((unsigned int)gnWaypointAct_007BF086 > 5)
    {
        gbGlobal_007BF085 = 0;
        return;
    }

    if (!gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].bInit)
    {
        gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].bInit = 1;
        for (int nLevelId = *(int*)gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nFirstLevelId;
            nLevelId <= *(int*)gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nLastLevelId; ++nLevelId)
        {
            unsigned short wWaypoint;
            if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &wWaypoint))
            {
                const unsigned char nIndex = (unsigned char)wWaypoint;
                if (gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMinWaypoint == 0xFF)
                {
                    gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMinWaypoint = nIndex;
                }

                gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint = nIndex > gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint ? nIndex : gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint;
            }
        }
    }

    for (int i = gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMinWaypoint; i <= gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint; ++i)
    {
        const unsigned short wWaypoint = (unsigned short)i;
        if (WAYPOINTS_IsActivated(gpWaypointData_007BF081, wWaypoint))
        {
            int nLevelId;
            if (WAYPOINTS_GetLevelIdFromWaypointNo(wWaypoint, &nLevelId))
            {
                *(int*)gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].nLevelId = nLevelId;
                if (nCurrentLevelId == nLevelId)
                {
                    gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].bEnabled = 0;
                }
                else
                {
                    ++gnWaypointEnabled_007BF08E;
                    gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].bEnabled = 1;
                }
                ++gnWaypointCount_007BF08A;
            }
        }
        else
        {
            int nLevelId;
            if (WAYPOINTS_GetLevelIdFromWaypointNo(wWaypoint, &nLevelId))
            {
                *(int*)gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].nLevelId = nLevelId;
                gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].bEnabled = 0;
                ++gnWaypointCount_007BF08A;
            }
        }
    }
}

// 0x004A1320
void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound)
{
    if (!bSide)
    {
        gbTextSide_007BF236 = 0;
        gnGlobal_007225FC = 0x0C;
        gnGlobal_007BF278 = (gnGlobal_0071146C - 0x145) / 2;
    }
    else
    {
        gbTextSide_007BF236 = 1;
        gnGlobal_007225FC = 0x105 - gnGlobal_007A285C;
        gnGlobal_007BF278 = gnGlobal_007A2858;
    }

    sub_0044DA40();

    if (gnHintId_007BF260)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId_007BF260);
        if (nHint)
        {
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        }
        gnHintId_007BF260 = 0;
    }

    gnHintSound_007BF24B = 0;
    gdwGlobal_007BF20A = 0;

    D2RectStrc tRect;
    const int nScreenBottom = gnGlobal_00711470 - 0x35;
    tRect.nTop = gnGlobal_007225FC;
    tRect.nBottom = gnGlobal_007225FC + 0xB6;
    if (tRect.nBottom >= nScreenBottom)
    {
        tRect.nBottom = nScreenBottom;
    }
    tRect.nLeft = gnGlobal_007BF278 - 10;
    tRect.nRight = gnGlobal_007BF278 + 0x14F;
    sub_00467430(&tRect);
    sub_00466FE0();

    gwTextStringId_007BF212 = nStringId;
    if (gpTextBox_007BF0A4)
    {
        return;
    }

    gnGlobal_007BF1BC = 0;
    const int nOldFont = sub_00502EF0(8);
    gpTextBox_007BF0A4 = sub_004A05E0_CreateTextBox(D2LANG_GetStringFromTblIndex(nStringId), 2);
    D2_ASSERT(gpTextBox_007BF0A4, 0x1063);
    sub_00502EF0(nOldFont);

    *(int*)gpTextBox_007BF0A4->nScroll = 0;
    gnGlobal_007BF1C0 = 1;
    gnGlobal_007BF1FA = 1;
    if (!gbStarted_007BF27C)
    {
        gbStarted_007BF27C = 1;
        gnGlobal_007BF22C = GetTickCount();
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
    }

    const int nSoundId = sub_004E0650_GetStringSound(nStringId);
    if (nSoundId)
    {
        gnHintSound_007BF24B = sub_004B9A00(nSoundId, sub_00463DD0_GetPlayerUnit(), 5, 0, 0);
        gnHintId_007BF260 = nSoundId;
    }

    if ((nStringId == 0x7F || nStringId == 0x4E22 || nStringId == 0x4EC9 || nStringId == 0x4EA3 || nStringId == 0x18C) && bSound)
    {
        gbTextSound_007BF230 = 1;
    }
}

// 0x004C5EB0
int __fastcall sub_004C5EB0_ScanFind(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, int nArg, int* pOut)
{
    D2AreaScanFindStrc tFind = { 0, -1, 0, nArg, nArg, 0 };

    if (!nFlags)
    {
        nFlags = 0x583;
    }

    sub_004C5C40_ScanArea(pUnit, nX, nY, nRange, nFlags | 0xA280, sub_004C5E70_FindCallback, &tFind, 0);

    int nResult = tFind.nFirst;
    if (!nResult)
    {
        nResult = tFind.nSecond;
    }

    if (pOut)
    {
        *pOut = tFind.nOut;
    }

    return nResult;
}

// 0x004DB670
int __fastcall sub_004DB670_UpdateUnitGfx(D2UnitStrc* pUnit, int nArg)
{
    int nX = 0;
    int nY = 0;
    if (sub_004F51D0_IsPerspective())
    {
        sub_004F6760_PrecisionToScreen(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0, &nX, &nY);
        switch (sub_0045AE90())
        {
        case 1:
            nX -= gnGlobal_0071146C / 4;
            break;

        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0();
        nY = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset();
    }

    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
    {
        return 0;
    }

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    int bShapeshifted = pUnit ? (pUnit->dwFlagEx >> 3) & 1 : 0;
    if (bShapeshifted && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    int nWeaponClassId[2];
    const int nId = COMPOSIT_GetWeaponClassId(pUnit, pInventory, nWeaponClassId, -1, 1);
    if (!sub_0046E5A0_FindGfxNode(pUnit, nId, -1) && !sub_0046FA80_LoadGfxNode(pUnit, nId, -1))
    {
        return 0;
    }

    void* pEntry = sub_0046E570_GetGfxEntry(pUnit, sub_0046DA60_GetUnitMode(pUnit));
    if (!pEntry)
    {
        return 0;
    }

    return sub_004DB0D0_UpdateGfxEntry(pEntry, nArg);
}

// 0x004E6560
void __fastcall sub_004E6560_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nArg1, int nArg2)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_SET)
    {
        return;
    }

    D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordFromItem(pItem);
    if (!pSetItemsTxt)
    {
        return;
    }

    int nMember;
    unsigned int nMask;
    switch (pSetItemsTxt->nAddFunc)
    {
    case 1:
    {
        nMask = ITEMS_GetSetItemsMask(pPlayer, pItem, 0);
        nMember = ITEMS_GetNoOfSetItemsFromItem(pItem);
        for (int i = 0; i < 6; ++i)
        {
            int nIndex = i;
            if (i == nMember)
            {
                continue;
            }

            if (i > nMember)
            {
                nIndex = i - 1;
            }

            if (nMask & (1 << i))
            {
                sub_004E60A0_AddSetPropText(pItem, nArg1, nArg2, 0, gaSetPropIds_006DBD70[nIndex], 0, 0, 1);
            }
        }
        break;
    }
    case 2:
    {
        const unsigned int nWorn = ITEMS_GetSetItemsMask(pPlayer, pItem, 1);
        const int nCount = (nWorn >= 0x40 ? 0 : gaSetPartialCounts_006DBD90[nWorn]) - 1;
        for (int i = 0; i < nCount; ++i)
        {
            sub_004E60A0_AddSetPropText(pItem, nArg1, nArg2, 0, gaSetPropIds_006DBD70[i], 0, 0, 1);
        }
        break;
    }
    }
}

static D2MonStatsTxt* MONSTATS_GetTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F3CE0
int __fastcall sub_004F3CE0_CreateSkillMissiles(D2UnitStrc* pUnit, int nSkillId, int nArg4, int nX, int nY, int nMonsterId)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!MONSTATS_GetTxtRecord(nMonsterId))
    {
        return 0;
    }

    if (!nX || !nY)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x2001;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = nX;
    tRequest.nArg2 = nY;
    tRequest.nArg3 = nSkillId;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nMissile;
    D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);

    const int nMissileC = pSkillsTxt->wCltMissileC;
    if (nMissileC > 0 && nMissileC < sgptDataTables->nMissilesTxtRecordCount)
    {
        tRequest.nArg4 = 2;
        tRequest.nArg0 = nMissileC;
        sub_004CD540_HandleRequest(&tRequest);
    }

    const int nMissileB = pSkillsTxt->wCltMissileB;
    if (pMissile)
    {
        if (nMissileB > 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
        {
            sub_004CEFE0_AddMissileEffect(pMissile, nMissileB, 0, 2, 0);
        }

        if (!sub_004648F0_GetPathTargetUnit(pUnit) && pSkillsTxt->wTgtSound > 0)
        {
            sub_004B9A00(pSkillsTxt->wTgtSound, pMissile, 0, 0, 0);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/WARDEN/WardenClient.inc"
