struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2SkillStrc;
struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x46];
    unsigned char nActionFrame;
    char unk0x4F[0x75];
    unsigned int dwFlags;
};

struct D2MonStatsTxt
{
    char unk0x00[0x86];
    unsigned short wTreasureClass[3][4];
    unsigned char nTCQuestId;
    unsigned char nTCQuestCP;
    char unk0xA0[0x108];
};

struct D2SuperUniquesTxt
{
    char unk0x00[0x2C];
    unsigned short wTC[3];
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x10];
    int dwMonsterSkillBonus;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

struct D2ModeChangeStrc
{
    char unk0x00[0x08];
    D2UnitStrc* pTargetUnit;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);   // 0x00543520
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00553490
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);                                       // 0x00554CA0
void __fastcall sub_6FC52110(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, int nTCId, int nQuality, int nItemLevel, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems); // 0x0055AFA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2);                                     // 0x00558200
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
void __fastcall sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0056FC50
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
int __fastcall MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit);                 // 0x005A03A0
void __stdcall sub_005A6B70_MissileFollowUp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId);          // 0x005A6B70
void __fastcall sub_005A8030(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005A8030
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                    // 0x00611D30
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall sub_006217C0(D2UnitStrc* pUnit);                                                              // 0x006217C0
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit);                                                       // 0x00623E00
int __stdcall STATLIST_GetOwnerType(D2StatListStrc* pStatList);                                             // 0x00625250
int __stdcall STATLIST_GetOwnerGUID(D2StatListStrc* pStatList);                                             // 0x006252B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
int __stdcall STATES_CheckStateMaskExpOnUnit(D2UnitStrc* pUnit);                                            // 0x0063A690
int __stdcall D2Common_11050(D2UnitStrc* pUnit, int a2);                                                    // 0x0063E6B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A6600
void __stdcall sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a7, D2ModeChangeStrc* pModeChange)
{
    D2_ASSERT(pUnit, 404);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 406);

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    DRLG_GetActNoFromLevelId(nLevelId);

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    D2_ASSERT(pMonStatsTxtRecord, 410);

    const int nDifficulty = pGame->nDifficulty;
    int nTCId;
    const int nItemLevel = ITEMS_GetItemLevelForNewItem(pUnit, nLevelId);
    const int nSuperUniqueId = MONSTERUNIQUE_GetSuperUniqueBossHcIdx(pGame, pUnit);
    if (nSuperUniqueId != -1)
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(nSuperUniqueId);
        if (!pSuperUniquesTxtRecord)
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][2];
        }
        else
        {
            nTCId = pSuperUniquesTxtRecord->wTC[nDifficulty];
        }
    }
    else
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 4))
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][1];
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 8))
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][2];
        }
        else
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][0];
        }
    }

    if (pMonStatsTxtRecord->nTCQuestId > 0 && pMonStatsTxtRecord->wTreasureClass[nDifficulty][3] > 0 && pModeChange)
    {
        D2UnitStrc* pTarget = pModeChange->pTargetUnit;
        if (pTarget)
        {
            if (pTarget->dwUnitType != 0)
            {
                D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pTarget);
                if (STATES_CheckStateMaskExpOnUnit(pTarget))
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x800);
                    if (pStatList)
                    {
                        const int nOwnerType = STATLIST_GetOwnerType(pStatList);
                        const int nOwnerGUID = STATLIST_GetOwnerGUID(pStatList);
                        pOwner = SUNIT_GetServerUnit(pGame, nOwnerType, nOwnerGUID);
                    }
                }

                if (pOwner)
                {
                    pTarget = pOwner;
                }
            }

            if (pTarget && pTarget->dwUnitType == 0)
            {
                D2BitBufferStrc* pQuestFlags = sub_00543520(pGame, pTarget);
                if (pQuestFlags && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, 15) != 1
                    && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, 1) != 1
                    && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, pMonStatsTxtRecord->nTCQuestCP) != 1)
                {
                    nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][3];
                }
            }
        }
    }

    sub_6FC52110(pGame, pUnit, pModeChange->pTargetUnit, nTCId, 0, nItemLevel, a7, 0, 0, 0);
}

// 0x005A6D50
int __fastcall sub_005A6D50_CreateMonsterMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nParam)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nMissileId = D2Common_11050(pUnit, nParam);
    if (nMissileId < 0)
    {
        return 0;
    }

    int nSkillLevel = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty)->dwMonsterSkillBonus + 1;
    if (UNIT_HasFlag(pUnit, 0x200))
    {
        nSkillLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    }

    if (sub_6FD11420(pGame, nMissileId, pUnit, 0, nSkillLevel, 0, 0, 0, 0, 1))
    {
        sub_005A6B70_MissileFollowUp(pGame, pUnit, nMissileId);
    }

    return 1;
}

// 0x005A8670
int __fastcall sub_6FC64E90(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (sub_006217C0(pUnit))
    {
        sub_005A8030(pGame, pUnit);
        return 2;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    int bCheck = 1;
    if (nSkillFlags & 1)
    {
        sub_6FCBC7E0(pGame, pUnit);

        if (sub_6FCBC930(pGame, pUnit) == 2)
        {
            SKILLS_SetFlags(pSkill, nSkillFlags | 2);
            sub_6FD13410(pGame, pUnit);
            bCheck = 0;
        }
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame == 4 || bCheck && !UNIT_HasFlag(pUnit, 0x40) && (nActionFrame == 1 || nActionFrame == 2))
    {
        sub_6FD13410(pGame, pUnit);
    }

    UNITS_StopSequence(pUnit);

    return 1;
}
