struct D2DynamicPathStrc;
struct Obj00648AD0;
struct D2CoordStrc { int nX; int nY; };
struct D2StaticPathStrc { char unk0x00[0x0C]; int nX; int nY; };
struct D2UnitStrc { int dwUnitType; char unk0x04[0x28]; union { D2StaticPathStrc* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };
struct D2GameStrc { char unk0x00[0x6D]; unsigned char nDifficulty; char unk0x6E[0x3A]; int dwGameFrame; };
struct D2AiControlStrc { int nAiSpecialState; char unk0x04[0x10]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk0x00[0x56]; short wAiParam[8][3]; char unk0x86[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl; unsigned int unk0x04; D2UnitStrc* pTarget; unsigned int unk0x0C[2]; int nTargetDistance;
    int bCombat; D2MonStatsTxt* pMonstatsTxt;
};

extern "C" const int gnDesertTurretIndices_006E33E0[64];                  // 0x006E33E0
extern "C" const D2CoordStrc gDesertTurretOffsets_006E33A0[8];            // 0x006E33A0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern "C" void __stdcall sub_00648AD0(Obj00648AD0* pObj, unsigned short wA, unsigned short wB); // 0x00648AD0
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY);

static short AITHINK_GetParam_Desert(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

static __forceinline int GetXInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5:
        return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetYInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5:
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E0980
void __fastcall AITHINK_Fn094_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
        pAiControl->dwAiParam[2] = 0;
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (nTargetDistance > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 3))
    {
        if (pAiControl->dwAiParam[1] > 0)
        {
            --pAiControl->dwAiParam[1];
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    const int nTargetX = GetXInl_Desert(pTarget);
    const int nTargetY = GetYInl_Desert(pTarget);
    const int nUnitX = GetXInl_Desert(pUnit);
    const int nUnitY = GetYInl_Desert(pUnit);
    const int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY);
    const int nIndex1 = pAiControl->dwAiParam[2] % 8;
    const int nIndex2 = sub_0063E7A0_GetByteTableEntry(nDirection) % 8;
    pAiControl->dwAiParam[2] = gnDesertTurretIndices_006E33E0[nIndex1 + 8 * nIndex2];

    const int nSpread = AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 4);
    const int nX = nUnitX + nSpread * gDesertTurretOffsets_006E33A0[pAiControl->dwAiParam[2]].nX;
    const int nY = nUnitY + nSpread * gDesertTurretOffsets_006E33A0[pAiControl->dwAiParam[2]].nY;

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);

    if (pMonStatsTxt->nSkill[0] >= 0 && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, nX, nY)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        sub_00648AD0((Obj00648AD0*)pUnit->pDynamicPath, nX, nY);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 1))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 0);
        }
        return;
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        --pAiControl->dwAiParam[1];
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

#include "gen/data/Source/D2Game/005E0980_AITHINK_Fn094_DesertTurret.inc"
