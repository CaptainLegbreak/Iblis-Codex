struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillListStrc;
struct D2InventoryStrc;
struct D2PropertyStrc;

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
};

struct D2SkillsTxt
{
    char unk0x000[0x23C];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
};

struct D2StatListStrc
{
    void* pMemPool;
    void* pUnit;
    unsigned int dwOwnerType;
    unsigned int dwOwnerId;
    unsigned int dwFlags;
    unsigned int dwStateNo;
    int dwExpireFrame;
    unsigned int dwSkillNo;
    unsigned int dwSLvl;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x1C];
    short wAnimSpeed;
    char unk0x4E[0x0E];
    D2StatListStrc* pStatListEx;
    char unk0x60[0x48];
    D2SkillListStrc* pSkills;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x58];
};

struct D2ObjectsTxt
{
    char unk0x000[0x1C0];
};

struct D2RunesTxt
{
    char unk0x000[0x120];
};

struct D2RuneDataTbl
{
    int nRunesTxtRecordCount;
    D2RunesTxt* pRunesTxt;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308
D2DifficultyLevelsTxt* gpDifficultylevelsTxt;                                                               // 0x0096C8AC
extern int gnDifficultylevelsTxtRecordCount;                                                                // 0x0096C8B0
D2RuneDataTbl gRuneDataTables;                                                                              // 0x0096CA98
extern D2ObjectsTxt* gpObjectsTxt;                                                                          // 0x0096D470
extern int gnObjectsTxtRecordCount;                                                                         // 0x0096D474

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
unsigned int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                           // 0x00621190
int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625350
int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);    // 0x00625420
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);                                                          // 0x0062A8D0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2ActiveRoomStrc* __stdcall PATH_GetRoom(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648A80
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9); // 0x0064F5B0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem);                                                // 0x0065E4D0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00611D30
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty)
{
    nDifficulty = nDifficulty > 0 ? nDifficulty : 0;
    if (nDifficulty >= gnDifficultylevelsTxtRecordCount - 1)
    {
        nDifficulty = gnDifficultylevelsTxtRecordCount - 1;
    }
    return &gpDifficultylevelsTxt[nDifficulty];
}

// 0x00620BB0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2198);

    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->pRoom;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetRoom(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00621780
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed)
{
    nSpeed = nSpeed > 0 ? nSpeed : 0;
    pUnit->wAnimSpeed = nSpeed < 0x7FFF ? nSpeed : 0x7FFF;
}

// 0x006219F0
D2SkillStrc* __stdcall UNITS_GetSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    D2_ASSERT(pSkillsTxtRecord, 3579);
    D2_ASSERT(pUnit, 1592);

    for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills); pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt == pSkillsTxtRecord)
        {
            return pSkill;
        }
    }
    return 0;
}

// 0x006254F0
int __stdcall sub_006254F0_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer);
}

// 0x00625500
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetTotalStatValue(pUnit->pStatListEx, nStatId, nLayer);
}

// 0x00625520
int __stdcall sub_00625520_GetStatBonus(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    if (!pStatList)
    {
        return 0;
    }

    return STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer) - sub_00625350(pStatList, nStatId, nLayer);
}

// 0x00625560
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit->pStatListEx)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    int nValue = STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer);
    return nValue - sub_00625350(pStatList, nStatId, nLayer);
}

// 0x00625A50
int __stdcall STATLIST_GetTotalStatValue_Layer0(D2StatListStrc* pStatListEx, int nStatId)
{
    return STATLIST_GetTotalStatValue(pStatListEx, nStatId, 0);
}

// 0x006260D0
void __stdcall STATLIST_SetSkillId(D2StatListStrc* pStatList, int nSkillId)
{
    pStatList->dwSkillNo = nSkillId;
}

// 0x006260F0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc* pStatList, int nSkillLevel)
{
    pStatList->dwSLvl = nSkillLevel;
}

// 0x00639CC0
void __stdcall DATATBLS_AddOrChangeRunesTxtRecord(int nRecordId, D2RunesTxt* pRecord)
{
    D2RunesTxt* pRunesTxt = 0;
    D2RunesTxt* pTmp = 0;
    int nSize = 0;

    if (gRuneDataTables.nRunesTxtRecordCount <= nRecordId)
    {
        pRunesTxt = gRuneDataTables.pRunesTxt;
        nSize = sizeof(D2RunesTxt) * (nRecordId + 1);

        if (DATATBLS_LoadFromBin)
        {
            pRunesTxt = (D2RunesTxt*)((char*)gRuneDataTables.pRunesTxt - 4);
            nSize += 4;
        }

        pTmp = (D2RunesTxt*)FOG_ReallocPool(0, pRunesTxt, nSize, ".\\DATATBLS\\ItemTbls.cpp", 2395, 0);

        if (DATATBLS_LoadFromBin)
        {
            *(int*)pTmp = nRecordId + 1;
            pTmp = (D2RunesTxt*)((char*)pTmp + 4);
        }
        gRuneDataTables.pRunesTxt = pTmp;

        memset(&pTmp[gRuneDataTables.nRunesTxtRecordCount], 0, sizeof(D2RunesTxt) * (nRecordId - gRuneDataTables.nRunesTxtRecordCount));
        gRuneDataTables.nRunesTxtRecordCount = nRecordId + 1;
    }

    gRuneDataTables.pRunesTxt[nRecordId] = *pRecord;
}

// 0x00640E90
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId)
{
    D2_ASSERT(nObjectId < gnObjectsTxtRecordCount, 221);
    D2_ASSERT(nObjectId >= 0, 222);
    return &gpObjectsTxt[nObjectId];
}

// 0x0064FA00
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* pUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int a5, D2InventoryStrc* pInventory, int nAnimMode)
{
    int nClass;
    int nType;
    int nMode;

    D2_ASSERT(pUnit, 262);

    nType = pUnit->dwUnitType;
    nClass = pUnit->dwClassId;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);

    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\COMPOSIT\\Composit.cpp", 268);

    if (nAnimMode == -1)
    {
        nAnimMode = nMode;
    }

    D2Common_10884_COMPOSIT_unk(pUnit, nClass, nAnimMode, nType, pInventory, szPath, pWeaponClassCode, bAddPathPrefix, a5);
}

// 0x0065FD20
int __fastcall ITEMMODS_PropertyFunc23(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (pProperty && pItem && pItem->dwUnitType == 4 && !ITEMS_IsEthereal(pItem) && ITEMS_HasDurability(pItem))
    {
        ITEMMODS_ApplyEthereality(pItem);
        return 1;
    }

    return 0;
}
