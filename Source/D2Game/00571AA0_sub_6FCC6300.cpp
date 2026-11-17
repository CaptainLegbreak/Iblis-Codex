struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};

struct D2UnitPacketSkillEventStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nSkillParam;
    char unk0x09;
    short nSkillId;
    short nSkillLevel;
    char unk0x0E[0x02];
    int nUnitType;
    int nUnitGUID;
    int nTargetType;
    int nTargetGUID;
    int nX;
    int nY;
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

#define UNIT_INVALID 6

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

// 0x00571AA0
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7)
{
    D2UnitPacketSkillEventStrc* pMsg = (D2UnitPacketSkillEventStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketSkillEventStrc), ".\\UNIT\\SUnitMsg.cpp", 746, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketSkillEventStrc));
    pMsg->pNext = 0;
    pMsg->nHeader = 0xA3;
    pMsg->nSkillParam = a7;
    pMsg->nSkillId = nSkillId;
    pMsg->nSkillLevel = nSkillLevel;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nX = nX;
    pMsg->nY = nY;

    if (pTargetUnit)
    {
        const int nTargetType = (pTargetUnit ? pTargetUnit->dwUnitType : 6);
        pMsg->nTargetType = nTargetType;
        const int nTargetGUID = (pTargetUnit ? pTargetUnit->dwUnitId : -1);
        pMsg->nTargetGUID = nTargetGUID;
    }
    else
    {
        pMsg->nTargetGUID = -1;
    }

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
