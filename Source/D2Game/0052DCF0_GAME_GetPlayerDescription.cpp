struct Unicode
{
    unsigned short wChar;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    short nNextInClass;
    unsigned short wNameStr;
    char unk0x08[0x1A8 - 0x08];
};

struct D2ItemsTxt
{
    char unk0x00[0xF4];
    unsigned short wNameStr;
};

struct D2ObjectsTxt
{
    char szName[64];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
};

#define PCLASS_AMAZON 0
#define PCLASS_SORCERESS 1
#define PCLASS_NECROMANCER 2
#define PCLASS_PALADIN 3
#define PCLASS_BARBARIAN 4
#define PCLASS_DRUID 5
#define PCLASS_ASSASSIN 6

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

static __forceinline D2MonStatsTxt* DESC_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x0052DCF0
void __fastcall GAME_GetPlayerDescription(char* szDescription, int nClassId)
{
    switch (nClassId)
    {
    case PCLASS_AMAZON: strcpy(szDescription, "Amazon"); break;
    case PCLASS_SORCERESS: strcpy(szDescription, "Sorceress"); break;
    case PCLASS_NECROMANCER: strcpy(szDescription, "Necromancer"); break;
    case PCLASS_PALADIN: strcpy(szDescription, "Paladin"); break;
    case PCLASS_BARBARIAN: strcpy(szDescription, "Barbarian"); break;
    case PCLASS_DRUID: strcpy(szDescription, "Druid"); break;
    case PCLASS_ASSASSIN: strcpy(szDescription, "Assassin"); break;
    default: strcpy(szDescription, "Invalid Class"); break;
    }
}

// 0x0052DDF0
void __fastcall GAME_GetMonsterDescription(char* szDescription, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DESC_GetMonStatsTxtRecord(nClassId);
    if (pMonStatsTxtRecord)
    {
        const Unicode* pName = D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr);
        sub_00526F70(szDescription, pName, 64);
    }
    else
        sprintf(szDescription, "Monster %d", nClassId);
}

// 0x0052DE40
void __fastcall GAME_GetObjectDescription(char* szDescription, int nClassId)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    if (pObjectsTxtRecord)
        strcpy(szDescription, pObjectsTxtRecord->szName);
    else
        sprintf(szDescription, "Object %d", nClassId);
}

// 0x0052DE80
void __fastcall GAME_GetItemDescription(char* szDescription, int nClassId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (pItemsTxtRecord)
    {
        const Unicode* pName = D2LANG_GetStringFromTblIndex(pItemsTxtRecord->wNameStr);
        sub_00526F70(szDescription, pName, 64);
    }
    else
        sprintf(szDescription, "Item %d", nClassId);
}

// 0x0052DEC0
void __fastcall GAME_GetMissileDescription(char* szDescription, int nClassId)
{
    sprintf(szDescription, "Missile %d", nClassId);
}
