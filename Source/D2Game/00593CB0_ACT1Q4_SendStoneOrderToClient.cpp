struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;
struct D2QuestDataStrc { char unk0x00[0x18]; void* pQuestDataEx; };
struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[5];
    char unk0x0A[0x40];
    unsigned char bStoneOrderInitialized;
};
#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nStoneOrder[5];
    unsigned char unk0x0D[3];
};
#pragma pack(pop)
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszAct1Q4SourceFile[]; // 0x006E1C48
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall sub_00592E90_InitializeStoneOrder(D2QuestDataStrc* pQuestData); // 0x00592E90
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0

// 0x00593CB0
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return;
    }
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bStoneOrderInitialized)
        {
            pQuestDataEx->bStoneOrderInitialized = 1;
            sub_00592E90_InitializeStoneOrder(pQuestData);
        }
        D2GSPacketSrv50 packet;
        packet.nHeader = 0x50;
        packet.nQuestId = 4;
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszAct1Q4SourceFile, 2169);
        int i = 0;
        if (i < 5)
        {
            do
            {
                packet.nStoneOrder[i] = pQuestDataEx->nStoneOrder[i] - 17;
                if (packet.nStoneOrder[i] >= 5)
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 2175);
                    exit(-1);
                }
                ++i;
            } while (i < 5);
        }
        D2GAME_SendPacket0x50_6FC3F440(pClient, &packet);
    }
}
