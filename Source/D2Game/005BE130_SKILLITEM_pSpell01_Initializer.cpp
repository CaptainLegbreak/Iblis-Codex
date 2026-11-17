struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* pItem);                                                        // 0x0062BB20
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char a3, int a4, int a5, unsigned short a6); // 0x0053D220

// 0x005BE130
int __fastcall SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    ITEMS_SetItemFlag(pItem, 4, 1);

    const int nSpellIcon = ITEMS_GetSpellIcon(pItem);
    if (nSpellIcon >= 0)
    {
        D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillItem.cpp", 64), pItem, nSpellIcon, 0, 1, nSkillId);
    }

    return 1;
}
