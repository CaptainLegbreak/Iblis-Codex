struct D2BitBufferStrc;
struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xB8 - 0x14];
    unsigned int dwDropItemCode;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

#define QUEST_A3Q2_KHALIMFLAIL 16
#define QUESTSTATEFLAG_A2COMPLETED 15
#define QUESTSTATEFLAG_A3Q2 18
#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM2 6
#define QFLAG_CUSTOM3 7

void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                // 0x00628590
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x005B81C0
static void __stdcall sub_005B81C0_SendKhalimPacket(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, unsigned char nState)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nQuestId = QUEST_A3Q2_KHALIMFLAIL;
    packet5D.nFlags = (unsigned char)pQuestData->dwFlags;
    packet5D.nState = nState;
    sub_6FC3F380(SUNIT_GetClientFromPlayer(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 568), &packet5D);
}

// 0x005B8210
void __fastcall ACT3Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2COMPLETED, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        return;
    }

    const unsigned int dwItemCode = ITEMS_GetBaseCode(pQuestArg->pTarget);

    bool bNoCustom1 = false;
    bool bNoCustom3 = false;
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_STARTED);
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_LEAVETOWN);
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_ENTERAREA);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM1))
    {
        bNoCustom1 = true;
    }
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM2);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM3))
    {
        bNoCustom3 = true;
    }

    bool bEyeAvailable = false;
    bool bHeartAvailable = false;
    bool bBrainAvailable = false;
    bool bBaseFlailAvailable = false;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 1fq'))
    {
        bBaseFlailAvailable = true;
    }

    ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2fq');

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' yeq'))
    {
        bEyeAvailable = true;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rbq'))
    {
        bBrainAvailable = true;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rhq'))
    {
        bHeartAvailable = true;
    }

    if (dwItemCode == ' 2fq')
    {
        if (pQuestData->fLastState)
        {
            pQuestData->fLastState = 7;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2COMPLETED, QFLAG_REWARDGRANTED))
        {
            return;
        }

        if (bNoCustom3)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 5);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 6);
        }
    }
    else if (dwItemCode == ' 1fq')
    {
        if (!bEyeAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else if (!bBrainAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bHeartAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else if (bNoCustom1)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 5);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' yeq')
    {
        if (!bBrainAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bBaseFlailAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bHeartAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' rhq')
    {
        if (!bBrainAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bBaseFlailAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bEyeAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' rbq')
    {
        if (!bHeartAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else if (!bBaseFlailAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bEyeAvailable)
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else
        {
            sub_005B81C0_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
}
