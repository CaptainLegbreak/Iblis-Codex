struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710

// 0x005B4A30
static void sub_005B4A30_ACT4Q2_WarpPlayerAndSendQuestPacket(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    LEVEL_WarpUnit(pGame, pPlayer, 103, 0);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 440);
    D2GSPacketSrv5D packet = {};
    packet.nHeader = 0x5D;
    packet.nQuestId = 0x17;
    packet.nFlags = 1;
    sub_6FC3F380(pClient, &packet);
}

// build: context sub_K13_Emit_005B4A30
void __fastcall sub_K13_Emit_005B4A30(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    sub_005B4A30_ACT4Q2_WarpPlayerAndSendQuestPacket(pGame, pPlayer);
}
