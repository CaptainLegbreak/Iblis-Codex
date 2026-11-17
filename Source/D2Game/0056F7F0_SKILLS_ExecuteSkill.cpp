struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        struct D2StaticPathStrc* pStaticPath;
        struct D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x08];
    unsigned int dwSeqFrame;
    char unk0x3C[0x88];
    unsigned int dwFlags;
};

struct D2SkillStrc;
struct D2ActiveRoomStrc;
struct D2StatListStrc;
struct D2MissilesTxt;

struct D2SkillsTxt
{
    short nSkillId;
    unsigned short unk0x02;
    unsigned int dwFlags[2];
    char nCharClass;
    unsigned char unk0x0D[3];
    unsigned char nAnim;
    char unk0x11[0x1B];
    short wSrvStartFunc;
    short wSrvDoFunc;
    char unk0x30[0x16];
    short wSrvMissile;
    char unk0x48[0x122];
    short wItemEffect;
    char unk0x16C[0x24];
    unsigned int dwDelay;
    char unk0x194[0x23C - 0x194];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

typedef int (__fastcall* SKILLDOFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);
typedef int (__fastcall* SKILLSTARTFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern "C" const unsigned int gdwBitMasks[];                                                                // 0x006CE268
extern D2DataTablesStrc* sgptDataTable;                                                                     // 0x00744304
extern SKILLSTARTFUNC gpSkillSrvStartFnTable_00732140[];                                                    // 0x00732140
extern SKILLDOFUNC gpSkillSrvDoFnTable_007322B0[];                                                          // 0x007322B0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                          // 0x0046ACE0
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nFrame, int a5, int a6); // 0x005417D0
void __fastcall sub_0056BFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056BFE0
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit);                                      // 0x0056C160
int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                          // 0x0056C3F0
struct D2CoordStrc { int nX; int nY; };
struct D2StaticPathStrc { char unk0x00[0x0C]; D2CoordStrc tGameCoords; };
enum D2C_UnitTypes { UNIT_OBJECT = 2, UNIT_ITEM = 4, UNIT_TILE = 5 };
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                   // 0x0056E900
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056EE90
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nMode, int nX, int nY, int a7); // 0x005809D0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                  // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall sub_006252D0(D2StatListStrc* pStatList, int nState);                                      // 0x006252D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
void __stdcall sub_00625CE0(D2StatListStrc* pStatList, void (__fastcall* pfRemove)(D2UnitStrc*, int, D2StatListStrc*)); // 0x00625CE0
void __stdcall sub_006260B0(D2StatListStrc* pStatList, int nExpireFrame);                                // 0x006260B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                // 0x00639DB0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
unsigned int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                // 0x006446A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define PLRMODE_TOWNNEUTRAL 5
#define PLRMODE_SEQUENCE 18
#define STATE_SKILLDELAY 121
#define EVENTTYPE_REMOVESTATE 12
#define UNITFLAG_SKSRVDOFUNC 0x00000040

#define SKILLSFLAGINDEX_DECQUANT 0
#define SKILLSFLAGINDEX_LOB 1
#define SKILLSFLAGINDEX_INTOWN 8
#define SKILLSFLAGINDEX2_USEMANAONDO (32 + 5)

#define SKILLS_CHECK_FLAG(pRecord, nIndex) (((const unsigned char*)(pRecord)->dwFlags)[(nIndex) >> 3] & gdwBitMasks[(nIndex) & 7])

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTable->nSkillsTxtRecordCount)
    {
        return &sgptDataTable->pSkillsTxt[nSkillId];
    }
    return 0;
}

static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay); // 0x0056EF90

// build: context D2GAME_SKILLS_SetDelay_6FD11C00
static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay)
{
    const int nExpireFrame = nDelay + pGame->dwGameFrame;
    if (pUnit && !pUnit->dwUnitType && nDelay)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_SKILLDELAY);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, pUnit->dwUnitType, pUnit->dwUnitId);
            if (!pStatList)
            {
                return;
            }

            sub_006252D0(pStatList, STATE_SKILLDELAY);
            sub_00625CE0(pStatList, sub_6FD10E50);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, STATE_SKILLDELAY, 1);
        }

        sub_006260B0(pStatList, nExpireFrame);
        sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
    }
}

struct D2DynamicPathStrc;
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056F7F0
int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect)
{
    if (!pGame || !pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int bLivingUnit;
    if (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER)
    {
        bLivingUnit = 1;
        D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
        if (pUsedSkill && !(SKILLS_GetFlags(pUsedSkill) & 1) && !SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_INTOWN))
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
            {
                UNITS_SetUsedSkill(pUnit, 0);

                if (pUnit->dwUnitType == UNIT_PLAYER)
                {
                    sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                }

                return 0;
            }
        }

        if (!bSkipSkillCheck && (!pUsedSkill || SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\SKILLS\\Skills.cpp", 2887) != nSkillId || SKILLS_GetSkillLevel(pUnit, pUsedSkill, 1) <= 0))
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (!pSkill || SKILLS_GetSkillLevel(pUnit, pSkill, 1) <= 0)
            {
                return 0;
            }
        }
    }
    else
    {
        bLivingUnit = 0;
    }

    if (pSkillsTxtRecord->wSrvDoFunc < 0 || pSkillsTxtRecord->wSrvDoFunc >= 191
        || bLivingUnit && SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX2_USEMANAONDO) && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
    {
        return 0;
    }

    int nDoFunc = pSkillsTxtRecord->wSrvDoFunc;
    if (bItemEffect && bSkipSkillCheck && pSkillsTxtRecord->wItemEffect > 1)
    {
        nDoFunc = pSkillsTxtRecord->wItemEffect;
    }

    SKILLDOFUNC pDoFunc = gpSkillSrvDoFnTable_007322B0[nDoFunc];
    if (pDoFunc)
    {
        nResult = pDoFunc(pGame, pUnit, nSkillId, nSkillLevel);
    }

    if (pSkillsTxtRecord->wSrvMissile >= 0 && sub_0046ACE0(pSkillsTxtRecord->wSrvMissile))
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

        int nX = 0;
        int nY = 0;
        int nTargetX = 0;
        int nTargetY = 0;
        if (bSkipSkillCheck && bItemEffect)
        {
            D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY);
            if (nX && nY)
            {
                nTargetX = nX;
                nTargetY = nY;
                nX -= CLIENTS_GetUnitX(pUnit);
                nY -= CLIENTS_GetUnitY(pUnit);
                nTargetX += nX;
                nTargetY += nY;
            }
        }

        if (SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_LOB))
        {
            sub_6FD11710(pGame, pSkillsTxtRecord->wSrvMissile, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, 0);
        }
        else
        {
            sub_6FD11420(pGame, pSkillsTxtRecord->wSrvMissile, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, 0);
        }

        nResult = 1;
    }

    if (!nResult)
    {
        return 0;
    }

    if (bApplyCosts)
    {
        if (bLivingUnit)
        {
            if (!gpSkillSrvStartFnTable_00732140[pSkillsTxtRecord->wSrvStartFunc] || SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX2_USEMANAONDO))
            {
                sub_0056BFE0(pGame, pUnit, nSkillId, nSkillLevel);
            }

            if (SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_DECQUANT))
            {
                sub_6FD118C0(pGame, pUnit);
            }
        }

        const int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDelay, nSkillId, nSkillLevel);
        if (nDelay > 0 && pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (pSkillsTxtRecord->nAnim == PLRMODE_SEQUENCE)
            {
                if (!(pUnit->dwSeqFrame & 0xFFFFFF00))
                {
                    D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nDelay);
                }
            }
            else
            {
                D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nDelay);
            }
        }
    }

    return nResult;
}
