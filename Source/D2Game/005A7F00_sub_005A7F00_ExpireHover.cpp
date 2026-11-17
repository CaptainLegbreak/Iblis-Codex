#ifdef MOVED_TEST
#define PREFIX char movedPrefix[4];
#define HOVER_FLAG 0x200
#define HOVER_EVENT 8
#else
#define PREFIX
#define HOVER_FLAG 0x100
#define HOVER_EVENT 6
#endif
struct D2HoverTextStrc;

struct D2GameStrc
{
    PREFIX
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    unsigned int dwGameFrame;
};

struct D2UnitStrc
{
    PREFIX
    unsigned int dwUnitType;
    char unk0x04[0xA0];
    D2HoverTextStrc* pHoverText;
    char unk0xA8[0x1C];
    unsigned int dwFlags;
};

#define UNITFLAG_HASTXTMSG HOVER_FLAG

void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame);                           // 0x00627460
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg);                             // 0x006611D0
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x005406A0
void __fastcall sub_6FC7E640(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00575630

// 0x005A7F00
void __fastcall sub_005A7F00_ExpireHover(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
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
        EVENT_SetEvent(pGame, pUnit, HOVER_EVENT, nTimeout, 0, 0);
    }
}
