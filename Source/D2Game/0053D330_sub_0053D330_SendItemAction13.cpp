struct D2ClientStrc;
struct D2UnitStrc;

void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053CEF0

// 0x0053D330
void __fastcall sub_0053D330_SendItemAction13(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, 0x13, dwFlag, 0);
}
