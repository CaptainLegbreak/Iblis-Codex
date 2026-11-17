extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();

struct D2ClientStrc;
struct D2BitBufferStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc;
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    void* pGame;
    unsigned char nActNo;
    char unk0x09[0xE3];
    QUESTACTIVEFILTER pfActiveFilter;
    char unk0xF0[0x04];
    D2QuestDataStrc* pPrev;
};

struct T005438E0
{
    D2QuestDataStrc* pLastQuest;
    int unk0x04;
    int unk0x08;
};

struct D2GameStrc
{
    char unk0x0000[0x6D];
    unsigned char nDifficulty;
    char unk0x006E[0x1086];
    T005438E0* pQuestControl;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char dwMonStatsFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

#pragma pack(push, 1)
struct D2GSPacketSrv8A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
};
#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket);            // 0x0053DFF0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

static __forceinline int sub_00544590_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->dwMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x00544590
int __fastcall sub_00544590_QuestsActiveFilter(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC)
{
    const bool bIsPlayer = pPlayer && pPlayer->dwUnitType == 0;
    D2_ASSERT(bIsPlayer, 2028);

    const int nNPCType = pNPC ? pNPC->dwUnitType : 6;
    D2_ASSERT(nNPCType == 1, 2029);

    const int nNpcId = pNPC->dwClassId;
    if (!sub_00544590_CheckMonStatsFlag(nNpcId, 9))
    {
        return 0;
    }

    T005438E0* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(pQuestControl->unk0x08, 2036);

    const unsigned char nAct = CLIENTS_GetActNo(SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 2038));

    for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (nAct == pQuestData->nActNo)
        {
            if (pQuestData->pfActiveFilter)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfActiveFilter), 2050);
                D2_ASSERT(UNITS_GetPlayerData(pPlayer), 2051);
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
                D2_ASSERT(pQuestFlags, 2053);

                if (pQuestData->pfActiveFilter(pQuestData, nNpcId, pPlayer, pQuestFlags, pNPC))
                {
                    D2GSPacketSrv8A tPacket8A;
                    tPacket8A.nHeader = 0x8A;
                    tPacket8A.nUnitType = 1;
                    tPacket8A.dwUnitGUID = pNPC->dwUnitId;
                    D2GAME_SendPacket0x8A_6FC3FA60(SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 2061), &tPacket8A);
                    return 1;
                }
            }
            else
            {
                D2_ASSERT(false, 2067);
            }
        }
    }

    return 0;
}
