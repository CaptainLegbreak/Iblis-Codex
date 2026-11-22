#include "D2MonsterIds.h"
#include "D2Client.h"
#include "D2Primitives.h"

struct D2PacketRecord6Strc;
struct D2QuestTableStrc;
struct D2UiEntry10Strc;
struct D2QuestUiFlagsStrc;

typedef unsigned short Unicode;

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nId;
    unsigned char nFlags;
    unsigned char nValue;
    short nParam;
};

struct D2QuestTableStrc
{
    unsigned char bEnabled;
    unsigned char nCelId;
    unsigned char nCelId2;
    unsigned char nPage;
    void* pTexts;
    int nCondition;
    int nQuestId;
};
extern int gnGlobal_007BF2A4; // 0x007BF2A4
extern int gnGlobal_007BF2AC; // 0x007BF2AC
extern D2QuestTableStrc gaQuestTable_00723F30[]; // 0x00723F30
extern D2UiEntry10Strc gaUiEntries_00723F38[41]; // 0x00723F38

struct D2QuestUiFlagsStrc
{
    char bLocked;
    unsigned char unk0x01[0xA2];
    unsigned char abFlags[41];
};

extern D2QuestUiFlagsStrc gtQuestUiFlags_007BF2B3; // 0x007BF2B3
extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820
void __cdecl GAME_RequestExit(); // 0x0044D520
void __fastcall sub_0044D530(int nValue); // 0x0044D530
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
void __cdecl GAME_SetDifficultyFlags(); // 0x0044EC80
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990
void __fastcall sub_0046BFD0_StartTimer(int nDelay); // 0x0046BFD0
void __fastcall sub_0046F870_LoadMonsterCofs(int nMonsterId, int bLoadNow); // 0x0046F870
void __cdecl INV_StopCinematic(); // 0x00483300
void __cdecl INV_ChainCinematic(); // 0x00483340
void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0
void __fastcall TEXT_SelectQuestPage(int nCondition); // 0x004A2C30
void __fastcall TEXT_ClearCainFlag(D2UnitStrc* pUnit); // 0x004A2C70
void __fastcall TEXT_ClearNihlathakFlag(D2UnitStrc* pUnit); // 0x004A2C90
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
static int TEXT_FindQuestIndex(int nKey);
extern int ganPageSelection_007BF280[5]; // 0x007BF280

// 0x004A1910
int TEXT_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaUiEntries_00723F38[i].nKey == nKey)
            return i;
    }
    return -1;
}

// 0x004A2CB0
void __fastcall TEXT_HandleQuestEvent(int nArg, D2PacketRecord6Strc* pPacket)
{
    if (pPacket)
    {
        unsigned char nFlags = pPacket->nFlags;
        if (nFlags & 1)
        {
            switch (pPacket->nId)
            {
            case 13:
                sub_0046F870_LoadMonsterCofs(MONSTER_DURIEL, 1);
                return;
            case 23:
                GAME_RequestExit();
                return;
            case 3:
                TEXT_PrintChatLine(D2LANG_GetStringFromTblIndex(3708), 0);
                return;
            case 4:
                CUNIT_ForEachMonster(TEXT_ClearCainFlag);
                return;
            case 15:
                TEXT_PrintChatLine(D2LANG_GetStringFromTblIndex(3710), 0);
                return;
            case 10:
                GAME_ConfigureEnvironmentOrDefer();
                return;
            case 33:
                sub_004B9A00(237, 0, 0, 0, 0);
                return;
            }
            return;
        }

        if (nFlags & 2)
        {
            switch (pPacket->nId)
            {
            case 23:
                if (GAME_IsExpansion())
                {
                    INV_ChainCinematic();
                    return;
                }
                GAME_SetDifficultyFlags();
                INV_StopCinematic();
                return;
            case 4:
                sub_004B9A00(241, 0, 0, 0, 0);
                return;
            case 32:
                sub_004B9A00(217, 0, 0, 0, 0);
                return;
            case 33:
                sub_004B9A00(243, 0, 0, 0, 0);
                return;
            case 8:
            case 15:
            case 18:
            case 22:
            case 35:
                sub_004B9A00(7, 0, 0, 0, 0);
                return;
            case 36:
                sub_0044D530(1);
                return;
            }
            return;
        }

        if (nFlags == 0x10)
        {
            unsigned char nId = pPacket->nId;
            if (nId == 10)
            {
                sub_004B9A00(2456, 0, 0, 0, 0);
                sub_004B9A00(2474, 0, 0, 0, 0);
            }
            else if (nId == 33)
            {
                sub_004B9A00(pPacket->nParam, 0, 0, 0, 0);
            }
            return;
        }

        if (nFlags & 0x20)
        {
            unsigned char nId = pPacket->nId;
            if (nId == 32)
            {
                gnGlobal_007BF2AC = pPacket->nParam;
            }
            else if (nId == 33)
            {
                CUNIT_ForEachMonster(TEXT_ClearNihlathakFlag);
                return;
            }
            else
            {
                D2BitBufferStrc* pQuestFlags = MONSTER_GetQuestFlags();
                if (pQuestFlags && QUESTRECORD_GetQuestState(pQuestFlags, 1, 0))
                {
                    return;
                }

                if (QUESTRECORD_GetQuestState(pQuestFlags, 1, 1))
                {
                    return;
                }

                gnGlobal_007BF2A4 = pPacket->nParam;
                if (gnGlobal_007BF2A4 > 5 || gnGlobal_007BF2A4 < 0)
                {
                    gnGlobal_007BF2A4 = 666;
                }

                if (gnGlobal_007BF2A4 != 5)
                {
                    gtQuestUiFlags_007BF2B3.abFlags[TEXT_FindQuestIndex(1)] = pPacket->nValue;
                    return;
                }

                if (pPacket->nId == 23)
                {
                    short nDelay = pPacket->nParam;
                    sub_0046BFD0_StartTimer(nDelay < 1 ? 1 : nDelay);
                    return;
                }
            }
        }
    }

refresh:
    if (!gnState_007BF298)
    {
        if (sub_00455F20(17, 0, 0) == 1)
        {
            TEXT_SelectQuestPage(pPacket->nId);
            gnState_007BF298 = 1;
        }
        return;
    }

    if (GAME_GetUIVarState(15))
    {
        int nIndex = TEXT_FindQuestIndex(pPacket->nId);
        if (nIndex != -1)
        {
            gtQuestUiFlags_007BF2B3.abFlags[nIndex] = pPacket->nValue;
            if (!gtQuestUiFlags_007BF2B3.bLocked)
            {
                D2QuestTableStrc* pEntry = &gaQuestTable_00723F30[nIndex];
                if (pEntry->nPage == gnGlobal_007C0255)
                {
                    gnIndex_007BF2B9 = pEntry->nCelId2;
                }
            }
        }
    }
}

// build: symbol ?SCMD_HandleQuestEvent@* 0x0045E540
void __fastcall SCMD_HandleQuestEvent(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    TEXT_HandleQuestEvent(1, &tPacket);
}

// 0x004A3050
void __cdecl sub_004A3050()
{
    ganPageSelection_007BF280[0] = -1;
    ganPageSelection_007BF280[1] = -1;
    ganPageSelection_007BF280[2] = -1;
    ganPageSelection_007BF280[3] = -1;
    ganPageSelection_007BF280[4] = -1;
}
