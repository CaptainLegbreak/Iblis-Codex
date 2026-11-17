#include "D2Game.h"

struct D2FileTimeStrc;
struct D2ServerCallbackFunctions;
struct D2StormSlotLink00530600Strc;
struct D2StormSlotList00530600Strc;
struct D2StormSlotArray00530600Strc;
struct D2StormHashTable00530600Strc;

struct D2UnitStrc { int dwUnitType; int dwClassId; };

struct D2FileTimeStrc { unsigned int dwLowDateTime; unsigned int dwHighDateTime; };

struct D2ClientStrc { char unk00[0x190]; D2FileTimeStrc nSaveCreationTimestamp; char unk198[0x310]; D2ClientStrc* pNext; };

struct D2GameStrc { char unk00[0x74]; int dwGameType; char unk78[0x10]; D2ClientStrc* pClientList; };

typedef void (__fastcall* FnUpdateCharacterLadder)(const char*, int, int, unsigned __int64, unsigned int, D2FileTimeStrc*);

struct D2ServerCallbackFunctions { void* pfCallbacks[10]; FnUpdateCharacterLadder pfUpdateCharacterLadder; };

extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc*, D2UnitStrc*, const char*, unsigned long); // 0x00532400
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
int __fastcall CLIENTS_GetFlags(D2ClientStrc*); // 0x00538640
char* __fastcall CLIENTS_GetName(D2ClientStrc*); // 0x00538830
void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc*, unsigned char*, unsigned char*, unsigned char*); // 0x00539190
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0

struct D2StormSlotLink00530600Strc
{
    D2StormSlotLink00530600Strc* m_prevlink;
    char* m_next;

    __forceinline char* Next()
    {
        char* const pNext = (int)m_next <= 0 ? 0 : m_next;
        return pNext;
    }
};

struct D2StormSlotList00530600Strc
{
    int m_linkoffset;
    D2StormSlotLink00530600Strc m_terminator;

};

struct D2StormSlotArray00530600Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormSlotList00530600Strc* m_data;
    unsigned int m_chunk;

};

struct D2StormHashTable00530600Strc
{
    void* m_vtable;
    D2StormSlotList00530600Strc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArray00530600Strc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0052FF20_GrowListArray();  // 0x0052FF20
    int sub_00530600(unsigned int nSlot);
};

// 0x0052C900
void __fastcall sub_0052C900_SaveClientAndGamePlayers(D2ClientStrc* pClient, D2GameStrc* pGame)
{
    if (!pClient)
        return;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer || !D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(pClient), 1))
        return;
    D2ClientStrc* volatile pNext;
    D2ClientStrc* i = pGame->pClientList;
    for (; i; i = pNext)
    {
        pNext = i->pNext;
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (pPlayer)
        {
            if (i != pClient)
                D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(i), 0);
            if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder && pGame->dwGameType)
            {
                unsigned char nBackgroundColor, nForegroundColor, nEmblemType;
                CLIENTS_GetGuildEmblem(i, &nBackgroundColor, &nForegroundColor, &nEmblemType);
                const int nClassId = pPlayer->dwClassId;
                gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, 12, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, 13, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
    }
}

// 0x00530600
int D2StormHashTable00530600Strc::sub_00530600(unsigned int nSlot)
{
    D2StormSlotList00530600Strc* const& pSlotLists = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
    {
        return 0;
    }

    if (m_fullnessIndicator > 3)
    {
        m_fullnessIndicator -= 3;
    }
    else
    {
        m_fullnessIndicator = 0;
    }

    for (char* pNode = pSlotLists[nSlot].m_terminator.Next(); (int)pNode > 0; )
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            sub_0052FF20_GrowListArray();
            return 1;
        }

        D2StormSlotList00530600Strc* pList = &pSlotLists[nSlot];
        D2StormSlotLink00530600Strc* pLink = pNode ? (D2StormSlotLink00530600Strc*)(pNode + pList->m_linkoffset) : &pList->m_terminator;
        pNode = pLink->m_next;
    }

    return 0;
}
