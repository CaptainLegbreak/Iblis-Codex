struct D2BitBufferStrc;

struct D2PlayerDataStrc
{
    char szName[16];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc;

#pragma pack(push, 1)
struct D2QuestSaveSectionStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short nSize;
    unsigned char pQuestRecord[3][96];
};
#pragma pack(pop)

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0

// 0x00532BE0
int __fastcall sub_00532BE0_ReadQuestData(D2UnitStrc* pPlayer, const D2QuestSaveSectionStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2QuestSaveSectionStrc tSection = *pSection;
    D2QuestSaveSectionStrc* pQuestSection = &tSection;
    if (pQuestSection->dwHeaderMagic != '!ooW')
    {
        return 2;
    }

    if (pQuestSection->dwVersion != 6)
    {
        return 2;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], pQuestSection->pQuestRecord[i], 96, 1);
    }

    *pSize = sizeof(D2QuestSaveSectionStrc);
    return 0;
}
