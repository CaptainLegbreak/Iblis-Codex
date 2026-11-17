struct D2ClientStrc;

#define UNIT_INVALID 6

#pragma pack(push, 1)
struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nSoundEvent;
};
#pragma pack(pop)

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0x5E];
    unsigned short nUpdateType;
    D2UnitStrc* pUpdateUnit;
};

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket);                       // 0x0053D780

static __forceinline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }

    return UNIT_INVALID;
}

// 0x00571740
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2UnitStrc* pUpdateUnit = pUnit->pUpdateUnit;
    if (!pUpdateUnit || CLIENTS_GetPlayerFromClient(pClient, 0) == pUpdateUnit)
    {
        D2GSPacketSrv2C packet2C;
        packet2C.nHeader = 0x2C;
        packet2C.dwUnitGUID = pUnit->dwUnitId;
        packet2C.nUnitType = UNITS_GetUnitTypeInline(pUnit);
        packet2C.nSoundEvent = pUnit->nUpdateType;
        SCMD_SendPacket0x2C(pClient, &packet2C);
    }
}
