struct D2SkillStrc;

struct D2UnitStrc
{
    char unk0x00[0x44];
    int nSeqCurrentFramePrecise;
};

extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
void __fastcall sub_00471EC0(D2UnitStrc* pUnit, int nArg, int nX, int nY, int bPlayer, int nFlags); // 0x00471EC0
int __stdcall D2GFX_CheckPerspective();                                                                     // 0x004F51D0
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder); // 0x004F67C0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
void __stdcall PATH_GetClientCoordsVelocity(D2UnitStrc* pUnit, int* pX, int* pY);                           // 0x00648300

// 0x004C9990
void __fastcall sub_004C9990_DrawMotionTrail(D2UnitStrc* pUnit, int nArg, int bReverse)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return;
    }

    const int nClientX = UNITS_GetClientCoordX(pUnit);
    const int nClientY = UNITS_GetClientCoordY(pUnit);
    int nVelocityX = 0;
    int nVelocityY = 0;
    PATH_GetClientCoordsVelocity(pUnit, &nVelocityX, &nVelocityY);

    if (bReverse)
    {
        if (nVelocityY < 0)
        {
            return;
        }
    }
    else if (nVelocityY >= 0)
    {
        return;
    }

    const int nAbsX = nVelocityX < 0 ? -nVelocityX : nVelocityX;
    const int nAbsY = nVelocityY < 0 ? -nVelocityY : nVelocityY;
    int nLength;
    if (nAbsX > nAbsY)
    {
        nLength = (nAbsY + 2 * nAbsX) / 2;
    }
    else
    {
        nLength = (nAbsX + 2 * nAbsY) / 2;
    }
    if (!nLength)
    {
        nLength = 1;
    }

    const int nStepX = 15 * nVelocityX / nLength;
    const int nStepY = 15 * nVelocityY / nLength;
    const int bPerspective = D2GFX_CheckPerspective();
    const int nStartFrame = pUnit->nSeqCurrentFramePrecise >> 8;
    int nFrame = nStartFrame;
    const int nCount = SKILLS_GetParam3(pSkill);
    for (int i = 0; i < nCount; ++i)
    {
        int nX = 0;
        int nY = 0;
        --nFrame;
        if (nFrame < 0)
        {
            nFrame += 8;
        }
        pUnit->nSeqCurrentFramePrecise = nFrame << 8;

        if (bPerspective)
        {
            SCALE_ScalePerspectivePosition(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0x60, &nX, &nY, 0);
            nX += sub_0045AFC0();
            nY += sub_0045AFD0_GetMouseYOffset();
        }
        else
        {
            nX = nClientX;
            nY = nClientY;
        }

        if (bReverse)
        {
            nX -= (nCount - i) * nStepX;
            nY -= (nCount - i) * nStepY;
        }
        else
        {
            nX -= (i + 1) * nStepX;
            nY -= (i + 1) * nStepY;
        }

        sub_00471EC0(pUnit, nArg, nX, nY, 1, 0);
    }

    pUnit->nSeqCurrentFramePrecise = nStartFrame << 8;
}
