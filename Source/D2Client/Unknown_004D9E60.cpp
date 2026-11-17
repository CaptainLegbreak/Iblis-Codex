#include "D2Client.h"

struct D2StatesTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2StatesTxt
{
    unsigned short wState;
    unsigned short wOverlay[4];
    unsigned short wCastOverlay;
    unsigned short wRemoveOverlay;
    unsigned short wPrgOverlay;
    unsigned char nStateFlags[8];
    unsigned short wStat;
    short wSetFunc;
    short wRemFunc;
    unsigned short wGroup;
    char unk0x20[0x10];
    short wCltEvent;
    short wCltEventFunc;
    char unk0x34[8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC];
    D2StatesTxt* pStatesTxt;
    void* pStatesLinker;
    int nStatesTxtRecordCount;
};

typedef void (__fastcall* CLIENTSTATEFN)(D2UnitStrc* pUnit, int nState);

int __fastcall sub_004C7C40_RegisterTableEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7); // 0x004C7C40
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern CLIENTSTATEFN gpfClientStateSetFuncs_0072A690[]; // 0x0072A690
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall sub_004DC190_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5); // 0x004DC190
extern CLIENTSTATEFN gpfClientStateRemFuncs_0072A710[]; // 0x0072A710

typedef unsigned int U32;

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_scalar_width[sizeof(U32)==4?1:-1];

extern "C" int __stdcall SKILLS_GetUseState(D2UnitStrc* unit,D2SkillStrc* skill); // 0x00647960
extern "C" D2UnitStrc* __cdecl sub_00463DE0(); // 0x00463DE0
extern "C" U32 __cdecl sub_0044DA90(); // 0x0044DA90
extern "C" U32 __cdecl sub_0044CE50(); // 0x0044CE50

// 0x004D9E60
void __fastcall sub_004D9E60_StartClientState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit || nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->nStateFlags[4] & gdwBitMasks[7])
    {
        if (pUnit->dwUnitType == 1 && pUnit->dwAnimMode == 12)
        {
            return;
        }

        if (pUnit->dwUnitType == 0 && pUnit->dwAnimMode == 17)
        {
            return;
        }
    }

    if (pStatesTxt->wSetFunc >= 0 && pStatesTxt->wSetFunc < 31 && gpfClientStateSetFuncs_0072A690[pStatesTxt->wSetFunc])
    {
        gpfClientStateSetFuncs_0072A690[pStatesTxt->wSetFunc](pUnit, nState);
    }

    if (pStatesTxt->wCltEvent < 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    const int nValue1 = STATLIST_GetStatValue(pStatList, 350, 0);
    const int nValue2 = STATLIST_GetStatValue(pStatList, 351, 0);
    sub_004C7C40_RegisterTableEvent(pUnit, pStatesTxt->wCltEvent, nValue1, nValue2, pStatesTxt->wCltEventFunc, 1, nState);
}

#include "gen/data/Source/D2Client/Unknown_004D9E60.inc"

// 0x004D9F40
void __fastcall sub_004D9F40_EndClientState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit || nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->wRemFunc >= 0 && pStatesTxt->wRemFunc < 30 && gpfClientStateRemFuncs_0072A710[pStatesTxt->wRemFunc])
    {
        gpfClientStateRemFuncs_0072A710[pStatesTxt->wRemFunc](pUnit, nState);
    }

    if (pStatesTxt->wCltEvent < 0)
    {
        return;
    }

    if (!STATLIST_GetStatListFromUnitAndState(pUnit, nState))
    {
        return;
    }

    sub_004DC190_RemoveCltUnitEvents(pUnit, 1, nState);
}

// 0x004D9FC0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill)
{
    int status = SKILLS_GetUseState(unit,skill);
    if (status)
        return status;
    if (unit == sub_00463DE0())
    {
        U32 first = sub_0044DA90();
        U32 second = sub_0044CE50();
        if (first < second)
            return 8;
    }
    return 0;
}
