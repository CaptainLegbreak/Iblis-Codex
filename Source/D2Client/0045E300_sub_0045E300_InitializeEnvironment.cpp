struct D2DrlgActStrc;
struct D2ActiveRoomStrc;

#pragma pack(push, 1)
struct D2EnvironmentPacketStrc
{
    unsigned char nHeader;
    int nIndex;
    int nTicks;
    unsigned char bEclipse;
};

struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned long dwUnitId;
    unsigned long dwUnused07;
};
#pragma pack(pop)

struct D2UnitStrc
{
    unsigned long dwUnitType;
    unsigned long dwClassId;
    void* pMemoryPool;
    unsigned long dwUnitId;
    char unk0x10[0x0C];
    D2DrlgActStrc* pDrlgAct;
};

extern D2DrlgActStrc* gpDrlgAct_007A0634;                                                                   // 0x007A0634

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __cdecl sub_004646C0_UpdateObjectsForPeriod();                                                         // 0x004646C0
void __fastcall sub_004C1BC0_RefreshUnitItems(D2PacketRecord11Strc* pPacket, int nArg);                     // 0x004C1BC0
void __stdcall ENVIRONMENT_InitializeEnvironment(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom, int nIndex, int nTicks, int bEclipse); // 0x0061C240

// 0x0045E300
void __fastcall sub_0045E300_InitializeEnvironment(D2EnvironmentPacketStrc* pPacket)
{
    const int nIndex = pPacket->nIndex;
    const int nTicks = pPacket->nTicks;
    if (gpDrlgAct_007A0634 == sub_00463DD0()->pDrlgAct)
    {
        ENVIRONMENT_InitializeEnvironment(gpDrlgAct_007A0634, sub_004646A0_GetPlayerRoom(), nIndex, nTicks, pPacket->bEclipse);
        sub_004646C0_UpdateObjectsForPeriod();

        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer)
        {
            D2PacketRecord11Strc tPacket;
            const int nUnitType = !pPlayer ? 6 : pPlayer->dwUnitType;
            tPacket.nUnitType = (unsigned char)nUnitType;
            tPacket.dwUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
            tPacket.nHeader = 0x47;
            sub_004C1BC0_RefreshUnitItems(&tPacket, 0);
        }
    }
}
