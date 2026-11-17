struct D2UnitStrc;
struct D2GameStrc;

void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x005449E0

// 0x0045D0A0
void __fastcall sub_0045D0A0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0B0
void __fastcall sub_0045D0B0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0C0
void __fastcall sub_0045D0C0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0D0
void __fastcall sub_0045D0D0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0E0
void __fastcall sub_0045D0E0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D130
void __fastcall sub_0045D130_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D140
void __fastcall sub_0045D140_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D150
void __fastcall sub_0045D150_PacketNop(const unsigned char* pPacket)
{
}

// 0x00581A10
void __fastcall sub_00581A10_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    QUESTS_ObjectEvents(pGame, pObject);
}
