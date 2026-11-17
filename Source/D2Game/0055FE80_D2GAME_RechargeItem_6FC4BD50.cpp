struct D2ClientStrc;
struct D2GameStrc;
struct D2SkillsTxt;

struct D2UnitStrc
{
    int dwUnitType;
};
struct D2StatStrc
{
    union
    {
        struct
        {
            unsigned short nLayer;
            unsigned short nStat;
        };
        int nPackedValue;
    };
    int nValue;
};
struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xC8];
    int nStuff;
    int nShiftedStuff;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);      // 0x006261D0
int __stdcall ITEMMODS_UpdateItemWithSkillCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges); // 0x0065C940

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define STAT_ITEM_CHARGED_SKILL 204

// 0x0055FE80
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pGame || !pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ClientStrc* pClient = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 6809);
    }

    D2StatStrc stats[64];
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, stats, 64);
    int bRecharged = 0;
    for (int i = 0; i < nStats; ++i)
    {
        const int nLayer = stats[i].nLayer;
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
        const int nValue = stats[i].nValue >> 8;
        if ((stats[i].nValue & 0xFF) < nValue)
        {
            ITEMMODS_UpdateItemWithSkillCharges(pItem, nSkillId, nSkillLevel, nValue);

            bRecharged = 1;
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, STAT_ITEM_CHARGED_SKILL,
                    (nValue & 0xFF) + (nValue << 8),
                    (nSkillLevel & (unsigned short)sgptDataTables->nShiftedStuff) + (nSkillId << sgptDataTables->nStuff));
            }
        }
    }

    return bRecharged;
}
