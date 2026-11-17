struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
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

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
void __fastcall sub_004DC190_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5);             // 0x004DC190

extern CLIENTSTATEFN gpfClientStateRemFuncs_0072A710[];                                                     // 0x0072A710
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

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

#include "gen/data/Source/D2Client/004D9F40_sub_004D9F40_EndClientState.inc"
