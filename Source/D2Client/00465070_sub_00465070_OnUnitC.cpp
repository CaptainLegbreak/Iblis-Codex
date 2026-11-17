struct D2ActiveRoomStrc;
struct D2SkillStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    union
    {
        int dwPrecisionX;
        struct
        {
            unsigned short wOffsetX;
            unsigned short wPosX;
        };
    };
    union
    {
        int dwPrecisionY;
        struct
        {
            unsigned short wOffsetY;
            unsigned short wPosY;
        };
    };
    int dwTargetX;
    int dwTargetY;
    D2PathPointStrc tSP1;
    D2PathPointStrc tSP2;
    D2PathPointStrc tSP3;
    D2ActiveRoomStrc* pRoom;
    D2ActiveRoomStrc* pRoomNext;
    int unk0x24;
    int dwPathPoints;
    int unk0x2C;
    void* pUnit;
    int dwFlags;
    int unk0x38;
    int dwPathType;
    int dwPrevPathType;
    int dwUnitSize;
    char unk0x48[0x14];
    int dwTargetType;
    int dwTargetId;
    unsigned char unk0x64[3];
    unsigned char nDist;
    unsigned char nDistMax;
    unsigned char unk0x69;
    D2PathPointStrc tPrevPoint;
    D2PathPointStrc tNextPoint;
    char unk0x72[0x0A];
    int dwVelocity;
    int unk0x80;
    int dwVelocity2;
    int unk0x88;
    int unk0x8C;
    unsigned char unk0x90;
    unsigned char nStepNum;
    unsigned char nSteps;
    unsigned char unk0x93;
    unsigned char unk0x94;
    char unk0x95[3];
    int unk0x98;
    D2PathPointStrc PathPoints[78];
    int nSavedSteps;
    D2PathPointStrc SavedSteps[7];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gdwGlobal_007A0610;                                                                              // 0x007A0610

D2UnitStrc* __stdcall sub_00534650_GetServerUnitFromFirstGame(int nUnitType, int nUnitId);                  // 0x00534650
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20
int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pPath);                                // 0x00648770
void __stdcall sub_00648750(D2DynamicPathStrc* pPath, int nArg);                                            // 0x00648750
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __stdcall D2COMMON_10212_PATH_SetMoveFlags(D2UnitStrc* pUnit, int bSet);                               // 0x006491B0

// 0x00465070
void __fastcall sub_00465070_OnUnitC(D2UnitStrc* pUnit)
{
    D2_ASSERT(!gdwGlobal_007A0610, 0xBAA);

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    D2UnitStrc* pServerUnit = sub_00534650_GetServerUnitFromFirstGame(nUnitType, nUnitId);
    if (!pServerUnit)
        return;

    D2DynamicPathStrc* pSrc = pServerUnit->pDynamicPath;
    D2DynamicPathStrc* pDst = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    const int nX = pSrc->wPosX;
    const int nY = pSrc->wPosY;
    if (nX != pDst->wPosX || nY != pDst->wPosY)
    {
        if (!COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY))
            return;

        D2Common_10231(pDst, pUnit, pRoom, nX, nY);
    }

    pDst->dwPrecisionX = pSrc->dwPrecisionX;
    pDst->dwPrecisionY = pSrc->dwPrecisionY;
    pDst->dwTargetX = pSrc->dwTargetX;
    pDst->dwTargetY = pSrc->dwTargetY;
    pDst->unk0x24 = pSrc->unk0x24;
    pDst->dwPathPoints = pSrc->dwPathPoints;
    pDst->unk0x38 = pSrc->unk0x38;
    pDst->tSP1 = pSrc->tSP1;
    pDst->tSP2 = pSrc->tSP2;
    pDst->tSP3 = pSrc->tSP3;
    pDst->dwTargetType = pSrc->dwTargetType;
    pDst->dwTargetId = pSrc->dwTargetId;
    pDst->nDist = pSrc->nDist;
    pDst->nDistMax = pSrc->nDistMax;
    pDst->dwVelocity = pSrc->dwVelocity;
    pDst->unk0x80 = pSrc->unk0x80;
    pDst->dwVelocity2 = pSrc->dwVelocity2;
    pDst->unk0x88 = pSrc->unk0x88;
    pDst->unk0x8C = pSrc->unk0x8C;
    pDst->nStepNum = pSrc->nStepNum;
    pDst->nSteps = pSrc->nSteps;
    pDst->unk0x93 = pSrc->unk0x93;
    pDst->unk0x94 = pSrc->unk0x94;
    pDst->unk0x98 = pSrc->unk0x98;
    pDst->tPrevPoint = pSrc->tPrevPoint;
    pDst->tNextPoint = pSrc->tNextPoint;

    if (pSrc->dwPathPoints)
        memcpy(pDst->PathPoints, pSrc->PathPoints, pSrc->dwPathPoints * sizeof(D2PathPointStrc));

    if (pSrc->nSavedSteps)
        memcpy(pDst->SavedSteps, pSrc->SavedSteps, pSrc->nSavedSteps * sizeof(D2PathPointStrc));

    pDst->nSavedSteps = pSrc->nSavedSteps;

    if (pSrc->dwPathType != 8 && pSrc->dwPathType != 11)
        pDst->dwPathType = pSrc->dwPathType;

    if (pSrc->dwPrevPathType != 8 && pSrc->dwPrevPathType != 11)
        pDst->dwPrevPathType = pSrc->dwPrevPathType;

    pDst->dwPrevPathType = pSrc->dwPrevPathType;
    pDst->dwUnitSize = pSrc->dwUnitSize;
    sub_00648750(pDst, D2COMMON_10209_PathCheckPathingFlag(pSrc));

    const unsigned int nMode = pUnit->dwAnimMode;
    const unsigned int nServerMode = pServerUnit->dwAnimMode;
    if (nMode != nServerMode)
    {
        switch (pUnit->dwUnitType)
        {
        case 0:
            switch (!pServerUnit ? 0u : pServerUnit->dwAnimMode)
            {
            case 2:
            case 6:
                switch (nMode)
                {
                case 1:
                case 5:
                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                        UNITS_ChangeAnimMode(pUnit, 6);
                    else
                        UNITS_ChangeAnimMode(pUnit, 2);
                    break;
                }
                break;

            case 3:
                switch (nMode)
                {
                case 1:
                case 3:
                case 5:
                    UNITS_ChangeAnimMode(pUnit, 3);
                    break;
                }
                break;

            case 1:
            case 5:
                switch (nMode)
                {
                case 2:
                case 3:
                case 6:
                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                        UNITS_ChangeAnimMode(pUnit, 5);
                    else
                        UNITS_ChangeAnimMode(pUnit, 1);
                    break;
                }
                break;

            case 18:
                break;

            default:
                if (nMode != 19)
                {
                    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
                    D2SkillStrc* pServerSkill = UNITS_GetUsedSkill(pServerUnit);
                    if (!pSkill)
                        break;

                    if (pServerSkill && (SKILLS_GetFlags(pServerSkill) & 1) && !(SKILLS_GetFlags(pServerSkill) & 2))
                        break;

                    const int nFlags = SKILLS_GetFlags(pSkill);
                    if (!(nFlags & 1))
                        break;

                    SKILLS_SetFlags(pSkill, nFlags | 2);
                    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
                    return;
                }

                UNITS_ChangeAnimMode(pUnit, nServerMode);
                break;
            }
            break;

        case 1:
            switch (nServerMode)
            {
            case 1:
                switch (nMode)
                {
                case 2:
                case 15:
                    UNITS_ChangeAnimMode(pUnit, 1);
                    break;
                }
                break;

            case 2:
                switch (nMode)
                {
                case 1:
                    UNITS_ChangeAnimMode(pUnit, 2);
                    break;
                }
                break;

            case 15:
                switch (nMode)
                {
                case 1:
                    UNITS_ChangeAnimMode(pUnit, 15);
                    break;
                }
                break;
            }
            break;
        }
    }

    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
}
