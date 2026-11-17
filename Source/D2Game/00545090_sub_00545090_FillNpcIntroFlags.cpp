struct D2UnitStrc;
struct D2ClientStrc;
struct D2PlrIntroStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2GSPacketSrv91
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned short pNPCFlags[12];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId);                          // 0x00572470
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_0053E060_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket);               // 0x0053E060
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern int gpAct1_NPCIds_007318B0[6];                                                                       // 0x007318B0
extern int gpAct2_NPCIds_007318C8[11];                                                                      // 0x007318C8
extern int gpAct3_NPCIds_007318F4[7];                                                                       // 0x007318F4
extern int gpAct5_NPCIds_00731910[7];                                                                       // 0x00731910

// 0x00545090
static int __stdcall sub_00545090_FillNpcIntroFlags(D2PlrIntroStrc* pIntroFlags, const int* pNpcIds, int nCount, D2GSPacketSrv91* pPacket)
{
    int bUpdate = 0;
    memset(pPacket->pNPCFlags, -1, sizeof(pPacket->pNPCFlags));
    int nFound = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (PLRINTRO_GetNpcIntroFlag(pIntroFlags, pNpcIds[i]))
        {
            pPacket->pNPCFlags[nFound] = (unsigned short)pNpcIds[i];
            ++nFound;
            bUpdate = 1;
        }
    }
    return bUpdate;
}

// 0x00545100
void __fastcall QUESTS_UpdateNPCIntros(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    D2GSPacketSrv91 packet91;
    D2PlrIntroStrc* pIntroFlags = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    int bUpdate;
    switch (nAct)
    {
    case 0:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct1_NPCIds_007318B0, 6, &packet91);
        break;
    case 1:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct2_NPCIds_007318C8, 11, &packet91);
        break;
    case 2:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct3_NPCIds_007318F4, 7, &packet91);
        break;
    case 4:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct5_NPCIds_00731910, 7, &packet91);
        break;
    default:
        return;
    }
    if (bUpdate)
    {
        packet91.nHeader = 0x91;
        packet91.nAct = nAct;
        sub_0053E060_SendPacket0x91(SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xAB7), &packet91);
    }
}
