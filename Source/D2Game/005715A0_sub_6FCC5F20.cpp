struct D2ClientStrc;
struct D2StatListStrc;

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};

struct D2UnitPacketLifeStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nUnitType;
    char unk0x09[0x03];
    int nUnitGUID;
    unsigned char nLife;
    char unk0x11[0x03];
};

struct D2UnitPacketSkillStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nUnitType;
    char unk0x09[0x03];
    int nUnitGUID;
    short nSkillId;
    char unk0x12[0x02];
};

struct D2UnitPacketPrecacheStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    short nMonsterClassId;
    char unk0x0A[0x02];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xDC];
    D2UnitPacketListStrc* pMsgFirst;
    D2UnitPacketListStrc* pMsgLast;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC0];
    int nOverlayTxtRecordCount;
};

#define UNIT_INVALID 6
#define STATE_SKILL_MOVE 18
#define STAT_UNIT_DOOVERLAY 178

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit);                                        // 0x004DC0B0
void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0
void __fastcall D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay); // 0x0053D850
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);               // 0x00625760
int __stdcall STATLIST_GetTotalStatValue_Layer0(D2StatListStrc* pStatListEx, int nStatId);                 // 0x00625A50
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

// 0x005715A0
void __fastcall sub_6FCC5F20(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x80);
    if (pStatList)
    {
        const int nOverlay = STATLIST_GetTotalStatValue_Layer0(pStatList, STAT_UNIT_DOOVERLAY);
        if (nOverlay >= 0 && nOverlay <= sgptDataTables->nOverlayTxtRecordCount)
        {
            D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(pClient, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId, nOverlay);
        }
    }
}

// 0x00571600
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    sub_0053BDA0_SendUnitRemoval(pClient, 0x0A, pUnit->dwUnitType, pUnit->dwUnitId);
}

// 0x00571A10
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent)
{
    D2UnitPacketLifeStrc* pMsg = (D2UnitPacketLifeStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketLifeStrc), ".\\UNIT\\SUnitMsg.cpp", 729, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketLifeStrc));
    pMsg->nHeader = 0xAB;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nLife = nLifePercent;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571B70
void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId)
{
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 0);

    D2UnitPacketSkillStrc* pMsg = (D2UnitPacketSkillStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketSkillStrc), ".\\UNIT\\SUnitMsg.cpp", 783, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketSkillStrc));
    pMsg->pNext = 0;
    pMsg->nHeader = 0xA5;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nSkillId = nSkillId;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571C00
void __fastcall SUNITMSG_QueueMonsterPrecache(D2UnitStrc* pUnit, int nMonsterClassId)
{
    D2UnitPacketPrecacheStrc* pMsg = (D2UnitPacketPrecacheStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketPrecacheStrc), ".\\UNIT\\SUnitMsg.cpp", 802, 0);
    pMsg->nHeader = 0xA4;
    pMsg->pNext = 0;
    pMsg->nMonsterClassId = nMonsterClassId;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571F40
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit)
{
    D2UnitPacketListStrc* pMsg = pUnit->pMsgFirst;
    if (pMsg)
    {
        do
        {
            D2UnitPacketListStrc* pFree = pMsg;
            pMsg = pMsg->pNext;
            FOG_FreeServerMemory(sub_004DC0B0_GetUnitMemoryPool(pUnit), pFree, ".\\UNIT\\SUnitMsg.cpp", 974, 0);
        }
        while (pMsg);

        pUnit->pMsgLast = 0;
        pUnit->pMsgFirst = 0;
    }
}
