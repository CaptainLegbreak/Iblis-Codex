struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

// 0x005717C0
void __fastcall sub_6FCC60D0(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, unsigned char nUnitType, int nUnitGUID, unsigned char a6)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 644, 0);
    *((unsigned char*)pMsg + 10) = nSkillLevel;
    *((unsigned char*)pMsg + 11) = nUnitType;
    pMsg->nHeader = 0x99;
    pMsg->pNext = 0;
    *((short*)pMsg + 4) = nSkillId;
    *((int*)pMsg + 3) = nUnitGUID;
    *((unsigned char*)pMsg + 16) = a6;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571840
void __fastcall sub_6FCC6150(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, short nX, short nY, unsigned char a6)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 667, 0);
    *((unsigned char*)pMsg + 10) = nSkillLevel;
    *((short*)pMsg + 6) = nX;
    pMsg->nHeader = 0x9A;
    pMsg->pNext = 0;
    *((short*)pMsg + 4) = nSkillId;
    *((short*)pMsg + 7) = nY;
    *((unsigned char*)pMsg + 16) = a6;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571C60
void __fastcall sub_6FCC64D0(D2UnitStrc* pUnit, int bLeftSkill, short nSkillId, int nOwnerGUID)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, 16, ".\\UNIT\\SUnitMsg.cpp", 818, 0);
    pMsg->nHeader = 0x23;
    pMsg->pNext = 0;
    *((unsigned char*)pMsg + 14) = bLeftSkill;
    *((short*)pMsg + 6) = nSkillId;
    *((int*)pMsg + 2) = nOwnerGUID;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}
