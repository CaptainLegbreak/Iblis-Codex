struct D2GameStrc;
struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2PlrIntroStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    char unk0x1C[0x44];
    D2PlrIntroStrc* pPlayerIntro[3];
};

#pragma pack(push, 2)
struct D2QuestSaveStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short wSize;
    unsigned char aQuestData[3][0x60];
};
#pragma pack(pop)

struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char unk0x04[3][8];
    unsigned char unk0x1C[3][8];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __fastcall PLRINTRO_CopyQuestIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572520
void __fastcall PLRINTRO_CopyNpcIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer);   // 0x00572530
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestFlags, unsigned char* pBuffer, int nBufferSize, int nUnused); // 0x0065C560

// 0x00569320
int __fastcall sub_00569320(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + sizeof(D2QuestSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2QuestSaveStrc tQuestSave;
    memset(&tQuestSave, 0, sizeof(tQuestSave));
    tQuestSave.dwHeaderMagic = 0x216F6F57;
    tQuestSave.dwVersion = 6;
    tQuestSave.wSize = sizeof(tQuestSave);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyRecordToBuffer(pPlayerData->pQuestData[i], tQuestSave.aQuestData[i], 0x60, 1);
    }

    memcpy(pSection, &tQuestSave, sizeof(tQuestSave));
    *ppSection = pSectionEnd;
    return 0;
}

// 0x00569490
int __fastcall PLRSAVE2_WritePlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + sizeof(D2PlrIntroSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2PlrIntroSaveStrc tPlrIntroSave;
    memset(&tPlrIntroSave, 0, sizeof(tPlrIntroSave));
    tPlrIntroSave.nHeader = 0x7701;
    tPlrIntroSave.nLength = sizeof(tPlrIntroSave);
    for (int i = 0; i < 3; ++i)
    {
        PLRINTRO_CopyQuestIntroFlagsToBuffer(pPlayerData->pPlayerIntro[i], tPlrIntroSave.unk0x04[i]);
        PLRINTRO_CopyNpcIntroFlagsToBuffer(pPlayerData->pPlayerIntro[i], tPlrIntroSave.unk0x1C[i]);
    }

    memcpy(pSection, &tPlrIntroSave, sizeof(tPlrIntroSave));
    *ppSection = pSectionEnd;
    return 0;
}
