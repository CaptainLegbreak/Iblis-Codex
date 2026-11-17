struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

#define UNITFLAG_INITSEEDSET 0x00000010
#define UNITFLAG_SENDREFRESHMSG 0x00001000
#define IMODE_ONGROUND 3

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int a2);                            // 0x00537860
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4); // 0x0053EC90
void __fastcall D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4); // 0x0053ECF0

// 0x0055BED0
void __fastcall sub_6FC42050(D2UnitStrc* pItem, D2ClientStrc* pClient)
{
    if (!pItem || UNIT_HasFlag(pItem, UNITFLAG_INITSEEDSET) || pItem->dwAnimMode != IMODE_ONGROUND)
    {
        return;
    }

    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (UNIT_HasFlag(pItem, UNITFLAG_SENDREFRESHMSG))
    {
        D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(pClient, pPlayer, pItem, 0);
    }
    else
    {
        D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(pClient, pPlayer, pItem, 0);
    }
}
