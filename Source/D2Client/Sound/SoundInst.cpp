#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"


struct D2SoundUnitNodeStrc
{
    D2UnitStrc* pUnit;
    D2SoundUnitNodeStrc* pNext;
};

#pragma pack(push, 1)
struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    int f_1C;
    float fPan;
    int nArg4;
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
    unsigned int f_34;
    int nArg3;
    unsigned char nPriority;
    int bLocked;
    int nRestart;
    int f_45;
    int nFadeFrom;
    int nFadeTo;
    unsigned int dwFadeStart;
    unsigned int dwFadeEnd;
};

struct D2SoundsTxtStrc
{
    char unk0x00[0x3E];
    unsigned char bStream;
    unsigned char nFadeIn;
    char unk0x40[1];
    unsigned char bCompound;
    unsigned char f_42;
    unsigned short nDuration;
    short nTimeout;
    int nKind;
    char unk0x4B[2];
    unsigned char bMusic;
    unsigned char f_4E;
    char unk0x4F[2];
    unsigned char bPositional;
    unsigned char bDuck;
    char unk0x53[0x0D];
    int nGroup;
    char unk0x64[0x22];
    int nMusicType;
};
#pragma pack(pop)

struct T00481920
{
    char unk0x00[0x18];
    unsigned char bFlag;
};

struct D2SoundNodeStrc
{
    D2ClientSoundStrc* f_0;
    D2SoundNodeStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl sub_0044DB30(); // 0x0044DB30
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_004817F0(); // 0x004817F0
int __cdecl sub_00481800(); // 0x00481800
unsigned int __cdecl sub_00481820(); // 0x00481820
D2SoundsTxtStrc* __fastcall sub_00481860(int nId); // 0x00481860
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
float __fastcall sub_00482610_GetCacheRange(int nSoundId); // 0x00482610
void __fastcall sub_00482860_TouchCacheEntry(int nSoundId); // 0x00482860
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax); // 0x004B93A0
D2ClientSoundStrc* __stdcall sub_004B9690_FindOldestEntry(int nGroup, D2UnitStrc* pUnit, D2ClientSoundStrc* pExclude); // 0x004B9690
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004CA8D0_NotifyUnitHint(D2UnitStrc* pUnit, int nHandle); // 0x004CA8D0
void __fastcall sub_004DFC20(void* pStream); // 0x004DFC20
void* __fastcall sub_004E01B0(D2ClientSoundStrc* pSound); // 0x004E01B0
int __fastcall sub_004E4100(int nMin, int nMax); // 0x004E4100
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY); // 0x004E4160
int __cdecl sub_00514CC0(); // 0x00514CC0
int __cdecl sub_00514CF0(); // 0x00514CF0
void __fastcall sub_00516950_LinkEntry(void* ppList, void* pData); // 0x00516950
void __fastcall sub_00516980_RemoveNode(D2SoundNodeStrc** ppList, D2ClientSoundStrc* pSound); // 0x00516980
int __fastcall sub_005169D0_ListHasKey(D2SoundUnitNodeStrc* pList, D2UnitStrc* pUnit); // 0x005169D0
void __fastcall sub_00516A10_FreeList(void* ppList); // 0x00516A10
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

extern int gnMusicVolume_00727564; // 0x00727564
extern int gnSoundVolume_00727568; // 0x00727568
extern int gbPositionalSound_007A061C; // 0x007A061C
static D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458
int gbSoundReady_007C545C;        // 0x007C545C
unsigned int gdwLastVolumeTick_007C5464;        // 0x007C5464
extern int gbAmbientSound_007C5468; // 0x007C5468

// 0x004B94E0
static void sub_004B94E0_FreeSound(D2ClientSoundStrc* pSound)
{
    if (!pSound)
        return;

    sub_00516980_RemoveNode(&gpSoundList_007C5458, pSound);
    for (D2SoundUnitNodeStrc* pNode = pSound->pUnitList; pNode; pNode = pNode->pNext)
        sub_004CA8D0_NotifyUnitHint(pNode->pUnit, pSound->f_8);

    sub_00516A10_FreeList(&pSound->pUnitList);
    if (pSound->nType == 1)
        sub_004DF7B0(pSound->pStream);

    D2_ASSERT(!pSound->pStream, 0x93);
    pSound->bActive = 0;
}

// 0x004B9700
static D2ClientSoundStrc* __stdcall sub_004B9700_FindUnitSound(D2ClientSoundStrc* pExclude, D2UnitStrc* pUnit)
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        if (pSound != pExclude && pSound->nType == 1)
        {
            if (!pUnit || sub_005169D0_ListHasKey(pSound->pUnitList, pUnit))
            {
                if (pSound->nSoundId >= 0xB76 && pSound->nSoundId <= 0x1230)
                    return pSound;
            }
        }
    }
    return 0;
}

// 0x004B97D0
static void __stdcall sub_004B97D0_GetSoundOffset(D2UnitStrc* pUnit, int nSoundId, D2SoundVecStrc* pPos)
{
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    int nX;
    int nY;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    UNITS_GetClientCoords(pPlayer, &tPlayer);
    UNITS_GetClientCoords(pUnit, &tUnit);
    if (nSoundId == 0xA27)
    {
        const double dSlope = -2.0;
        const float fPX = (float)tPlayer.nX;
        const float fPY = (float)tPlayer.nY;
        const float fT = (dSlope * fPX + fPY - tUnit.nX * 0.5 - tUnit.nY) / -2.5;
        nX = (int)fT;
        const float fY = dSlope * fPX - dSlope * fT + fPY;
        nY = (int)fY;
    }
    else
    {
        nY = tUnit.nY;
        nX = tUnit.nX;
    }

    pPos->fX = (float)(nX - tPlayer.nX);
    pPos->fZ = 640.0f;
    pPos->fY = (float)(nY - tPlayer.nY) * 2.0f;
}

static float __stdcall sub_004B9890_GetSoundPan(D2UnitStrc* pUnit, int nSoundId)
{
    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    if (pTxt)
    {
        if (pTxt->nKind == 4)
            return 0.0f;

        if (pTxt->nGroup == 0xCA)
        {
            T00481920* pEnviron = sub_00481920_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
            if (pEnviron && pEnviron->bFlag)
                return 0.5f;

            return 0.0f;
        }
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
        return 0.5f;

    return 0.0f;
}

// 0x004B98F0
static void sub_004B98F0_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos)
{
    D2_ASSERT(pSound && pPos, 0x1A6);

    pSound->vPos = *pPos;
    const float fX = sub_004B93A0_ClampFloat(pPos->fX, -2000.0f, 2000.0f);
    const float fY = sub_004B93A0_ClampFloat(pPos->fY, -2000.0f, 2000.0f);
    pSound->fDistance = sub_004E4160_LengthSquared2D(fX, fY);
}

static __forceinline int sub_004B9BC0_IsOnAndNotHeld(D2ClientSoundStrc* pSound)
{
    return pSound->f_45 && !pSound->nFadeTo;
}

static void __cdecl sub_004B9EB0_PlayRandomSound()
{
    if (sub_00481820() % 3 == 0)
    {
        const int nSound = sub_004E4100(0xB76, 0x1230);
        sub_004B9A00(nSound, 0, 0, 0, 0);
    }
}

static int sub_004BA020_SortsBefore(D2ClientSoundStrc* pSound1, D2ClientSoundStrc* pSound2)
{
    if (pSound1->nPriority > pSound2->nPriority)
        return 1;
    if (pSound1->nPriority < pSound2->nPriority)
        return 0;
    if (pSound1->fDistance < pSound2->fDistance)
        return 1;
    if (pSound1->fDistance > pSound2->fDistance)
        return 0;
    if (pSound1->f_34 > pSound2->f_34)
        return 1;
    if (pSound1->f_34 < pSound2->f_34)
        return 0;
    return pSound1 > pSound2;
}

static float sub_004BA020_MinF(float a, float b)
{
    return a < b ? a : b;
}

static float sub_004BA020_MaxF(float a, float b)
{
    return a > b ? a : b;
}

// 0x004BA020
void __fastcall sub_004BA020(unsigned int nTick)
{
    if (!gbSoundReady_007C545C)
        return;

    D2SoundNodeStrc* pFreeList = NULL;
    if (gbAmbientSound_007C5468)
        sub_004B9EB0_PlayRandomSound();

    D2SoundNodeStrc* pNode;
    int bSorted;
    do
    {
        bSorted = 1;
        for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            if (pNode->pNext)
            {
                if (sub_004BA020_SortsBefore(pNode->pNext->f_0, pNode->f_0))
                {
                    D2ClientSoundStrc* pTmp = pNode->f_0;
                    pNode->f_0 = pNode->pNext->f_0;
                    pNode->pNext->f_0 = pTmp;
                    bSorted = 0;
                }
            }
        }
    }
    while (!bSorted);

    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        if (pSound->bLocked && !sub_004B9BC0_IsOnAndNotHeld(pSound))
        {
            if (pSound->nType == 0)
                pSound->nType = 2;

            if (pSound->nType == 1)
            {
                sub_004DF7B0(pSound->pStream);
                D2_ASSERT(!pSound->pStream, 0x93);
            }
        }
    }

    const int bEnabled = sub_00514CC0() > 0;
    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        D2SoundsTxtStrc* pTxt = sub_00481860(pSound->nSoundId);
        int bAudible = bEnabled;
        if (pSound->nSoundId >= sub_004817F0() && pSound->nSoundId <= sub_00481800() && !sub_00514CF0())
            bAudible = 0;

        if (pSound->nType == 2)
        {
            D2_ASSERT(!pSound->pStream, 0x349);
            if (pTxt->bStream && !pTxt->nDuration && !pSound->bLocked)
            {
                if (pSound->f_45)
                {
                    pSound->f_1C = pSound->nFadeTo;
                    pSound->f_45 = 0;
                }
                pSound->nType = 0;
            }
            else
            {
                sub_00516950_LinkEntry(&pFreeList, pSound);
            }
            continue;
        }

        if (gbPositionalSound_007A061C && pTxt->bPositional && pSound->pUnitList)
        {
            D2SoundVecStrc tPos;
            D2SoundVecStrc tBest;
            tPos.fX = 0.0f;
            tPos.fY = 0.0f;
            tPos.fZ = 0.0f;
            D2UnitStrc* pBest = NULL;
            int nCount = 0;
            tBest.fX = 0.0f;
            tBest.fY = 0.0f;
            tBest.fZ = 0.0f;
            float fBestDist = -1.0f;
            float fPanSum = 0.0f;
            for (D2SoundUnitNodeStrc* pUnitNode = pSound->pUnitList; pUnitNode; pUnitNode = pUnitNode->pNext)
            {
                D2UnitStrc* pUnit = pUnitNode->pUnit;
                D2_ASSERT(pUnit, 0x36C);
                sub_004B97D0_GetSoundOffset(pUnit, pSound->nSoundId, &tPos);
                const float fDist = sub_004E4160_LengthSquared2D(tPos.fX, tPos.fY);
                if (!pBest || fDist < fBestDist)
                {
                    tBest = tPos;
                    pBest = pUnit;
                    fBestDist = fDist;
                }

                fPanSum += sub_004B9890_GetSoundPan(pUnit, pSound->nSoundId);
                ++nCount;
            }

            sub_004B98F0_SetSoundPosition(pSound, &tBest);
            const float fTarget = fPanSum / nCount;
            if (fTarget > pSound->fPan)
                pSound->fPan = sub_004BA020_MinF(pSound->fPan + 0.05000000074505806, fTarget);
            else
                pSound->fPan = sub_004BA020_MaxF(pSound->fPan - 0.05000000074505806, fTarget);
        }

        if (pSound->f_45)
        {
            if (nTick > pSound->dwFadeEnd)
            {
                pSound->f_45 = 0;
                pSound->f_1C = pSound->nFadeTo;
            }
            else if (nTick < pSound->dwFadeStart)
            {
                pSound->f_1C = pSound->nFadeFrom;
            }
            else
            {
                pSound->f_1C = pSound->nFadeFrom + (pSound->nFadeTo - pSound->nFadeFrom) * (int)(nTick - pSound->dwFadeStart) / (int)(pSound->dwFadeEnd - pSound->dwFadeStart);
            }
        }

        const float fRange = sub_00482610_GetCacheRange(pSound->nSoundId);
        const float fRangeSq = fRange * fRange;
        if (pSound->nType == 0 && nTick >= pSound->f_34 && pSound->f_1C)
        {
            if (bAudible && pSound->fDistance <= fRangeSq)
            {
                D2_ASSERT(!pSound->pStream, 0x3A1);
                D2UnitStrc* pUnit = NULL;
                D2ClientSoundStrc* pOther = NULL;
                if (pSound->pUnitList && !pSound->pUnitList->pNext)
                    pUnit = pSound->pUnitList->pUnit;

                const int bHasPos = pSound->vPos.fX != 0.0f || pSound->vPos.fY != 0.0f || pSound->vPos.fZ != 0.0f;

                if (pTxt->bCompound || pTxt->f_42)
                    pOther = sub_004B9690_FindOldestEntry(pTxt->nGroup, pUnit, pSound);

                if (pUnit && pSound->nSoundId >= 0xB76 && pSound->nSoundId <= 0x1230)
                    pOther = sub_004B9700_FindUnitSound(pSound, pUnit);

                if (!(pTxt->bCompound && !pSound->pUnitList && bHasPos) && pOther)
                {
                    if (pTxt->f_42)
                    {
                        pOther->bLocked = 1;
                        sub_00516950_LinkEntry(&pFreeList, pOther);
                    }
                    else
                    {
                        pSound->bLocked = 1;
                        sub_00516950_LinkEntry(&pFreeList, pSound);
                        continue;
                    }
                }

                int bRestart = 0;
                if (pSound->nRestart)
                {
                    pSound->nArg4 = pSound->nRestart;
                    pSound->nRestart = 0;
                    bRestart = 1;
                }

                int nVolume = 0;
                int nFade = 0;
                if (bRestart)
                {
                    nFade = 3;
                    nVolume = pSound->f_1C;
                    pSound->f_1C = 0;
                }
                else if (pTxt->nFadeIn && !pSound->f_45 && !(pSound->nArg3 & 2))
                {
                    nFade = pTxt->nFadeIn;
                    nVolume = pSound->f_1C;
                    pSound->f_1C = 0;
                }

                pSound->pStream = sub_004E01B0(pSound);
                if (pSound->pStream)
                {
                    pSound->nType = 1;
                    if (nFade)
                    {
                        pSound->nFadeFrom = pSound->f_1C;
                        pSound->nFadeTo = nVolume;
                        pSound->dwFadeStart = nTick;
                        pSound->dwFadeEnd = nTick + nFade;
                        pSound->f_45 = 1;
                    }
                }

                pTxt = sub_00481860(pSound->nSoundId);
            }

            if (!pSound->pStream && !pTxt->bStream && (!pTxt->bMusic || pTxt->nMusicType != 1))
                sub_00516950_LinkEntry(&pFreeList, pSound);
        }

        if (pSound->nType == 1)
        {
            D2_ASSERT(pSound->pStream, 0x3F3);
            if ((!pTxt->nDuration || nTick - pSound->f_34 <= pTxt->nDuration) && bAudible && !(pSound->fDistance > fRangeSq))
            {
                sub_004DFC20(pSound->pStream);
                if (pTxt->nMusicType == 2)
                    sub_00482860_TouchCacheEntry(pSound->nSoundId);
            }
            else
            {
                sub_004DF7B0(pSound->pStream);
                D2_ASSERT(!pSound->pStream, 0x93);
            }
        }
    }

    for (D2SoundNodeStrc* pFree = pFreeList; pFree; pFree = pFree->pNext)
        sub_004B94E0_FreeSound(pFree->f_0);

    sub_00516A10_FreeList(&pFreeList);

    int bPanel;
    if ((!sub_0044DB30() || sub_0044DB30() == 1) && (sub_00453A90_GetUIVarUnchecked(9) || sub_00453A90_GetUIVarUnchecked(11)))
        bPanel = 1;
    else
        bPanel = 0;

    int bDuck = 0;
    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        if (sub_00481860(pSound->nSoundId)->bDuck && !sub_004B9BC0_IsOnAndNotHeld(pSound))
        {
            bDuck = 1;
            break;
        }
    }

    if (nTick > gdwLastVolumeTick_007C5464)
    {
        if (bPanel)
        {
            const int n = gnMusicVolume_00727564 - 5;
            gnMusicVolume_00727564 = n < 0 ? 0 : n;
        }
        else
        {
            const int n = gnMusicVolume_00727564 + 5;
            gnMusicVolume_00727564 = n > 100 ? 100 : n;
        }

        if (bDuck)
        {
            const int n = gnSoundVolume_00727568 - 2;
            gnSoundVolume_00727568 = n < 70 ? 70 : n;
        }
        else
        {
            const int n = gnSoundVolume_00727568 + 2;
            gnSoundVolume_00727568 = n > 100 ? 100 : n;
        }
    }

    gdwLastVolumeTick_007C5464 = nTick;
}

#include "gen/data/Source/D2Client/Sound/SoundInst.inc"
