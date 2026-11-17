struct D2HoverTextStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    unsigned int dwGameFrame;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0xA0];
    D2HoverTextStrc* pHoverText;
    char unk0xA8[0x1C];
    unsigned int dwFlags;
};

#define UNITFLAG_HASTXTMSG 0x00000100

void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame);                           // 0x00627460
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg);                             // 0x006611D0
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x005406A0
void __fastcall sub_6FC7E640(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00575630

// 0x00580800
void __fastcall D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

// 0x00580B70
void __fastcall sub_6FC81B20(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    if (!pUnit)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
    {
        return;
    }

    const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
    if (nTimeout <= pGame->dwGameFrame)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_HASTXTMSG;
    }
    else
    {
        EVENT_SetEvent(pGame, pUnit, 6, nTimeout, 0, 0);
    }
}

// 0x00580BE0
void __fastcall sub_6FC81B90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    PARTY_SynchronizeWithClient(pGame, pUnit);
    sub_6FC7E640(pGame, pUnit);
    EVENT_SetEvent(pGame, pUnit, 11, pGame->dwGameFrame + 30, 0, 0);
}
