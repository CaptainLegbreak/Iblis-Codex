struct D2ClientStrc;

struct D2DrlgActStrc
{
    char unk0x00[0x5C];
    void* pMemPool;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x04];
    unsigned int nMaxClients;
    char unk0x08[0x24];
    D2DrlgActStrc* pAct;
    char unk0x30[0x18];
    D2ClientStrc** ppClients;
    char unk0x4C[0x2C];
    unsigned int nNumClients;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

static int sub_0061A550_CheckClientsOfRoom(D2ActiveRoomStrc* pRoom)
{
    for (unsigned int i = 0; i < pRoom->nNumClients; ++i)
    {
        D2_ASSERT(pRoom->ppClients[i], 0x453);
    }
    return 1;
}

// 0x0061A5A0
static void DUNGEON_UpdateClientListOfRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(sub_0061A550_CheckClientsOfRoom(pRoom), 0x45B);

    for (int nClients = pRoom->nNumClients - 1; nClients > 0; --nClients)
    {
        int bContinue = 0;
        for (int i = 0; i < nClients; ++i)
        {
            if (pRoom->ppClients[i] > pRoom->ppClients[i + 1])
            {
                D2ClientStrc* pTemp = pRoom->ppClients[i];
                pRoom->ppClients[i] = pRoom->ppClients[i + 1];
                pRoom->ppClients[i + 1] = pTemp;
                bContinue = 1;
            }
        }
        if (!bContinue)
            return;
    }

    sub_0061A550_CheckClientsOfRoom(pRoom);
}

// 0x0061A660
void __stdcall DUNGEON_AddClientToRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x473);
    D2_ASSERT(pClient, 0x474);
    D2_ASSERT(sub_0061A550_CheckClientsOfRoom(pRoom), 0x475);
    D2_ASSERT(pRoom->nNumClients <= pRoom->nMaxClients, 0x477);

    if (pRoom->nNumClients == pRoom->nMaxClients)
    {
        pRoom->nMaxClients += 4;
        pRoom->ppClients = (D2ClientStrc**)FOG_ReallocPool(pRoom->pAct->pMemPool, pRoom->ppClients, sizeof(D2ClientStrc*) * pRoom->nMaxClients, ".\\DUNGEON\\Dungeon.cpp", 0x47B, 0);
    }

    pRoom->ppClients[pRoom->nNumClients] = pClient;
    ++pRoom->nNumClients;
    DUNGEON_UpdateClientListOfRoom(pRoom);
}

// 0x0061A700
void __stdcall DUNGEON_RemoveClientFromRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x487);
    D2_ASSERT(pClient, 0x488);
    D2_ASSERT(sub_0061A550_CheckClientsOfRoom(pRoom), 0x489);

    unsigned int i = 0;
    for (i = 0; i < pRoom->nNumClients; ++i)
    {
        if (pRoom->ppClients[i] == pClient)
            break;
    }
    D2_ASSERT(i < pRoom->nNumClients, 0x490);

    pRoom->ppClients[i] = pRoom->ppClients[pRoom->nNumClients - 1];
    --pRoom->nNumClients;
    DUNGEON_UpdateClientListOfRoom(pRoom);
}
