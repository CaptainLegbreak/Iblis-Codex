#include "D2Game.h"

struct D2SaveHeaderStrc;
struct D2ClientInfoStrc;
struct D2ActiveRoomStrc
{
    char unk0x00[72];
    D2ClientStrc** ppClients;
    char unk0x4C[0x2C];
    unsigned int nNumClients;
};
struct D2GameStrc
{
    char unk0x00[136];
    D2ClientStrc* pClientList;
};
struct D2ClientKeySkillStrc
{
    short nSkill;
    unsigned char nHand;
    char unk0x03;
    unsigned int nItemGUID;
};
struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char nClassId;
    char unk0x09;
    unsigned short nSaveFlags;
    char unk0x0C;
    char szName[16];
    char szAccount[16];
    char unk0x2D[0x3B];
    D2ClientInfoStrc* pClientInfo;
    char unk0x6C[0x10C];
    int bUnlockCharacter;
    D2SaveHeaderStrc* pSaveHeader;
    int nSaveHeaderSize;
    unsigned int unk0x184;
    unsigned int nSaveHeaderDataSentBytes;
    unsigned int nSaveChecksum;
    char unk0x190[8];
    int unk0x198[4];
    D2GameStrc* pGame;
    unsigned char nAct;
    char f_1AD[7];
    D2ActiveRoomStrc* pRoom;
    char unk0x1B8[0x21C];
    unsigned int dwFlags;
    char unk0x3D8[4];
    D2ClientKeySkillStrc HotkeySkills[16];
    char unk0x45C[0x28];
    int nIronGolemItemGUID;
    unsigned int nCreateTime;
    char clientPlayerData[0x1C];
    D2ClientStrc* pNext;
    char unk0x4AC[0x5C];
    int nExpLoss;
    int unk0x50C;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                             // 0x004135D0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define CLIENTFLAGEX_DEAD 0x02
#define CLIENTFLAGEX_SAVE_LOADED 0x10
#define CLIENTFLAGEX_0x20 0x20
#define CLIENT_SAVE_STEP 5
#define ACCOUNT_COPY_MAX 50

// 0x005381C0
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId)
{
    for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00538230
D2ActiveRoomStrc* __fastcall sub_00538230(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 1966);

    return pClient->pRoom;
}

// 0x00538260
void __fastcall D2GAME_SetClientDead_6FC33830(D2ClientStrc* pClient, const int* pDeathInfo)
{
    D2_ASSERT(pClient, 1998);

    if (!pDeathInfo)
    {
        pClient->dwFlags &= ~CLIENTFLAGEX_DEAD;
        return;
    }

    pClient->unk0x198[0] = pDeathInfo[0];
    pClient->unk0x198[1] = pDeathInfo[3];
    pClient->dwFlags |= CLIENTFLAGEX_DEAD;
}

// 0x005382B0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2015);

    return pClient->nAct;
}

// 0x005382E0
void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct)
{
    D2_ASSERT(pClient, 2026);
    D2_ASSERT(nAct < NUM_ACTS, 2027);

    pClient->nAct = nAct;
}

// 0x00538320
void __fastcall sub_6FC33910(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2037);

    pClient->bUnlockCharacter = 1;
}

// 0x00538350
unsigned int __fastcall D2GAME_GetSaveChecksumFromClient_6FC33940(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2047);

    return pClient->nSaveChecksum;
}

// 0x00538380
void __fastcall D2GAME_SetSaveFileChecksum_6FC33970(D2ClientStrc* pClient, unsigned int nChecksum)
{
    D2_ASSERT(pClient, 2058);

    pClient->nSaveChecksum = nChecksum;
}

// 0x00538590
int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2160);

    return pClient->dwClientId;
}

// 0x005385C0
int __fastcall sub_005385C0()
{
    return -1;
}

// 0x005385D0
void __stdcall sub_005385D0(int nUnused)
{
}

// 0x005385F0
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2232);

    return pClient->nClassId;
}

// 0x00538620
void __fastcall CLIENTS_SetClassId(D2ClientStrc* pClient, int nClass)
{
    pClient->nClassId = nClass;
}

// 0x00538630
void __fastcall CLIENTS_SetFlags(D2ClientStrc* pClient, int nFlags)
{
    pClient->nSaveFlags = nFlags;
}

// 0x00538640
int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient)
{
    return pClient->nSaveFlags;
}

// 0x005386D0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState)
{
    D2_ASSERT(pClient, 2419);

    pClient->dwClientState = nClientState;
}

// 0x00538700
void __fastcall CLIENTS_SetIronGolemItemGUID(D2ClientStrc* pClient, int nIronGolemItemGUID)
{
    D2_ASSERT(pClient, 2430);

    pClient->nIronGolemItemGUID = nIronGolemItemGUID;
}

// 0x00538760
void __fastcall CLIENTS_SetCreateTime(D2ClientStrc* pClient, unsigned int nCreateTime)
{
    D2_ASSERT(pClient, 2452);

    pClient->nCreateTime = nCreateTime;
}

// 0x00538790
int __fastcall CLIENTS_GetCreateTime(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2463);

    return pClient->nCreateTime;
}

// 0x005387C0
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2474);

    return pClient->pGame;
}

// 0x005387F0
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        unsigned int nNumClients = pRoom->nNumClients;
        D2ClientStrc** ppClients = pRoom->ppClients;
        for (unsigned int i = 0; i < nNumClients; ++i)
        {
            if (ppClients[i] == pClient)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00538830
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2541);

    return pClient->szName;
}

// 0x00538E00
D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2901);

    return pClient->pSaveHeader;
}

// 0x00538E30
int __fastcall CLIENTS_GetSaveHeaderSize(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2911);

    return pClient->nSaveHeaderSize;
}

// 0x00538F80
void __fastcall D2GAME_SetSaveLoadComplete_6FC34300(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2961);

    pClient->unk0x184 = CLIENT_SAVE_STEP;
    pClient->nSaveHeaderDataSentBytes = 0;
    pClient->dwFlags |= CLIENTFLAGEX_SAVE_LOADED;
}

// 0x00538FC0
int __fastcall sub_00538FC0(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2974);

    return (pClient->dwFlags & CLIENTFLAGEX_SAVE_LOADED) && pClient->pSaveHeader;
}

// 0x00539000
void __fastcall sub_00539000(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2991);

    pClient->dwFlags |= CLIENTFLAGEX_0x20;
}

// 0x005390D0
void __fastcall sub_005390D0(D2ClientStrc* pClient, int nHotkey, int* pSkill, int* pHand, int* pItemGUID)
{
    if (pClient)
    {
        *pSkill = pClient->HotkeySkills[nHotkey].nSkill;
        *pHand = pClient->HotkeySkills[nHotkey].nHand;
        *pItemGUID = pClient->HotkeySkills[nHotkey].nItemGUID;
    }
}

// 0x005391E0
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss)
{
    D2_ASSERT(nExpLoss >= 0, 3166);

    pClient->nExpLoss = nExpLoss;
}

// 0x005392F0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szAccount)
{
    SStrCopy(szAccount, pClient->szAccount, ACCOUNT_COPY_MAX);
}

// 0x00539320
void __fastcall sub_00539320(D2ClientStrc* pClient, D2ClientInfoStrc* pClientInfo)
{
    pClient->pClientInfo = pClientInfo;
}

// 0x00539330
void* __fastcall CLIENTS_GetClientPlayerData(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 3344);

    return pClient->clientPlayerData;
}

// 0x00539470
int __fastcall sub_00539470(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 3392);

    return pClient->unk0x50C;
}
