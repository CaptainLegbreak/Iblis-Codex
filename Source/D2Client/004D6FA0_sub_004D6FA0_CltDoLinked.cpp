struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc tSeed;
    int unk0x28;
    D2DynamicPathStrc* pDynamicPath;
};

extern "C" const char gszMissileSourceFile_006DAEF4[];                                                      // 0x006DAEF4

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);                // 0x004639B0
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);                                    // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);                                               // 0x0064A780

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 0x004D6FA0
void __fastcall sub_004D6FA0_CltDoLinked(D2UnitStrc* pMissile)
{
    D2SeedStrc* pSeed = &pMissile->tSeed;
    int nPrevState = sub_0064A780_targetValue(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2UnitStrc* pLinked = sub_004639B0_FindServerSideUnit(sub_0064A730_GetMissileTargetStatus(pMissile), 3);
    if (pLinked)
    {
        int nState = sub_0064A730_GetMissileTargetStatus(pLinked);
        int nDistance = sub_006416D0_UnitEdgeDistance(pMissile, pLinked);
        int nMin = MAX((int)((unsigned int)SEED_RollRandomNumberInline(pSeed) % 5), 1);

        if (nPrevState != nState && nState > 1)
        {
            MISSILE_SetTargetY(pMissile, nState);
            switch (nState)
            {
            case 4:
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 20, 1);
                sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, 400, 0);
                sub_004DA6E0_SetMotionFlag20(pMissile, 1);
                D2Common_10142(pPath, pMissile, 0);
                sub_004D30C0_CltDoCommon(pMissile);
                return;

            case 3:
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -6, 1);
                sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, SEED_RollLimitedRandomNumber(pSeed, 40), 0);
                sub_004DA6E0_SetMotionFlag20(pMissile, 0);
                D2Common_10142(pPath, pMissile, 0);
                sub_004D30C0_CltDoCommon(pMissile);
                return;

            case 2:
                PATH_SetVelocity(pPath, 0, gszMissileSourceFile_006DAEF4, 6004);
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 6, 1);
                sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, SEED_RollLimitedRandomNumber(pSeed, 40) + 170, 0);
                sub_004DA6E0_SetMotionFlag20(pMissile, 1);
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pLinked), CLIENTS_GetUnitY(pLinked));
                PATH_SetVelocity(pPath, 0x300, gszMissileSourceFile_006DAEF4, 6012);
                D2Common_10142(pPath, pMissile, 0);
                sub_004D30C0_CltDoCommon(pMissile);
                return;
            }
        }
        else if (nDistance < nMin && !nPrevState)
        {
            MISSILE_SetTargetY(pMissile, 1);
            sub_004DA690_ReplaceMotionFlag1With8(pMissile);
            sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 1, 1);
            sub_004D30C0_CltDoCommon(pMissile);
            return;
        }
        else if (nPrevState == 1)
        {
            int nDiffX = -CLIENTS_GetUnitX(pLinked) + CLIENTS_GetUnitX(pMissile);
            int nDiffY = -CLIENTS_GetUnitY(pLinked) + CLIENTS_GetUnitY(pMissile);
            if (nDiffX || nDiffY)
            {
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pMissile) - nDiffY, CLIENTS_GetUnitY(pMissile) + nDiffX);
                PATH_SetVelocity(pPath, 0xA00, gszMissileSourceFile_006DAEF4, 6046);
                D2Common_10142(pPath, pMissile, 0);
            }
        }
        else if (nPrevState == 3)
        {
            D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pLinked), CLIENTS_GetUnitY(pLinked));
            PATH_SetVelocity(pPath, 0x200, gszMissileSourceFile_006DAEF4, 6055);
            D2Common_10142(pPath, pMissile, 0);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
