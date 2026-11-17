struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc { char unk_00[0xC]; int nXPos; int nYPos; };
struct D2UnitStrc { int dwUnitType; char dwClassId[0x28]; union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; }; char unk_30[0x94]; unsigned int dwFlags; };
struct D2SkillsTxt { char unk_00[0x48]; short nSrvMissile; short nCltMissile; char unk_4C[0xEC]; int dwCalc[4]; char unk_148[0xF4]; };
struct D2DataTablesStrc { char unk_00[0xB6C]; int nMissilesTxtRecordCount; char unk_B70[0x28]; D2SkillsTxt* pSkillsTxt; int unk_B9C; int nSkillsTxtRecordCount; };
struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk_38;
    unsigned int unk_3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc*, D2UnitStrc*, int*, int*); // 0x0056D2C0
void __fastcall sub_6FD140D0(int*, int*); // 0x0056D370
void __fastcall sub_6FD14120(int*, int*); // 0x0056D3B0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
int __fastcall sub_00623C60(D2UnitStrc*); // 0x00623C60
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
// 0x005DB410
int __fastcall sub_005DB410_CreateMissileWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missile;
    if (pUnit) pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    if (!pSkillsTxtRecord) goto ReturnZero;
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        const int nTotal = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        int nUnitX;
        switch (pUnit->dwUnitType)
        {
        case 2:
        case 4:
        case 5:
            nUnitX = pUnit->pStaticPath->nXPos;
            break;
        default:
            nUnitX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
            break;
        }
        int nDx = nX - nUnitX;
        int nUnitY;
        switch (pUnit->dwUnitType)
        {
        case 2:
        case 4:
        case 5:
            nUnitY = pUnit->pStaticPath->nYPos;
            break;
        default:
            nUnitY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
            break;
        }
        int nDy = nY - nUnitY;
        sub_6FD140D0(&nDx, &nDy);
        sub_6FD14120(&nDx, &nDy);
        nX += -(nDx * nTotal / 2);
        nY += -(nDy * nTotal / 2);
        int nMissile = pSkillsTxtRecord->nSrvMissile;
        if (sub_00623C60(pUnit) != 1 && pSkillsTxtRecord->nCltMissile >= 0) nMissile = pSkillsTxtRecord->nCltMissile;
        if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount) goto ReturnZero;
        int nActive = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (!nActive) nActive = nTotal;
        memset(&missile, 0, sizeof(missile));
        missile.dwFlags = 0x820;
        missile.pOwner = pUnit;
        missile.pOrigin = pUnit;
        missile.nSkill = nSkillId;
        missile.nSkillLevel = nSkillLevel;
        missile.nMissile = nMissile;
        missile.nActivateFrame = SKILLS_EvaluateSkillFormula(missile.pOwner, pSkillsTxtRecord->dwCalc[1], missile.nSkill, missile.nSkillLevel);
        missile.dwFlags |= 0x10000;
        const int nOutside = (nTotal - nActive) / 2;
        if (nOutside > 0)
        {
            int i = nOutside;
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--i);
        }
        missile.dwFlags &= ~0x10000u;
        if (nActive > 0)
        {
            int i = nActive;
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--i);
        }
        missile.dwFlags |= 0x10000;
        int nRemaining = nTotal - nOutside - nActive;
        if (nRemaining > 0)
        {
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--nRemaining);
        }
    }
    return 1;
ReturnZero:
    return 0;
}
