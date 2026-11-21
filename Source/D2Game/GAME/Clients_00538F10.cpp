#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameRecords.h"
#include "D2GameClient.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define CLIENTFLAGEX_SAVE_LOADED 0x10
#define WARP_ATTEMPT_EXPIRATION_FRAMES 0x8CA
#define NUM_WARP_ATTEMPT_SLOTS 5


int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);           // 0x0040B480
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0

static int CLIENTS_IsPlayerUnit_Inlined(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// 0x00538F10
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 0xB7D);

    if (ptClient->pSaveHeader)
    {
        FOG_FreePool(ptClient->pGame->pMemoryPool, ptClient->pSaveHeader, ".\\GAME\\Clients.cpp", 0xB80, 0);
        ptClient->pSaveHeader = 0;
    }

    ptClient->nSaveHeaderSize = 0;
    ptClient->nSaveHeaderDataSentBytes = 0;
    ptClient->nSaveHeaderSendDelay = 0;
    ptClient->dwFlags &= ~CLIENTFLAGEX_SAVE_LOADED;
}

// 0x00539030
unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 0xBBA);

    return ptClient->bGameOwner;
}

// 0x005392A0
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = pClient->pPacketDataHead;

    if (pClient->pPacketDataTail == pPacketData)
    {
        pClient->pPacketDataTail = 0;
        pClient->pPacketDataHead = 0;
    }

    if (pPacketData)
    {
        pClient->pPacketDataHead = pPacketData->pNext;
    }

    return pPacketData;
}

// 0x00539360
void __fastcall CLIENTS_NotifyWarpAttempt(D2GameStrc* pGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(CLIENTS_IsPlayerUnit_Inlined(hUnit), 0xD1B);

    D2ClientStrc* ptClient = UnitGetClient(hUnit, ".\\GAME\\Clients.cpp", 0xD1D);
    D2_ASSERT(ptClient, 0xD1E);

    for (int i = 0; i < NUM_WARP_ATTEMPT_SLOTS; ++i)
    {
        const int nLastWarpFrame = ptClient->unk0x3C0[i];
        if (!nLastWarpFrame || (unsigned int)pGame->dwGameFrame - nLastWarpFrame > WARP_ATTEMPT_EXPIRATION_FRAMES)
        {
            ptClient->unk0x3C0[i] = pGame->dwGameFrame;
            return;
        }
    }
}

// 0x005393F0
int __fastcall CLIENTS_ShouldDelayWarpAttempt(D2GameStrc* pGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(CLIENTS_IsPlayerUnit_Inlined(hUnit), 0xD2D);

    D2ClientStrc* pClient = UnitGetClient(hUnit, ".\\GAME\\Clients.cpp", 0xD2F);
    D2_ASSERT(pClient, 0xD30);

    for (int i = 0; i < NUM_WARP_ATTEMPT_SLOTS; ++i)
    {
        const int nLastWarpFrame = pClient->unk0x3C0[i];
        if (!nLastWarpFrame || (unsigned int)pGame->dwGameFrame - nLastWarpFrame > WARP_ATTEMPT_EXPIRATION_FRAMES)
        {
            return 0;
        }
    }

    return 1;
}
