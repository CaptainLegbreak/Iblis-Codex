#include "D2Client.h"
#include "D2ClientGame.h"

struct D2SoundUnitNodeStrc
{
    D2UnitStrc* pUnit;
    D2SoundUnitNodeStrc* pNext;
};

struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    char unk0x1C[0x0C];
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2SoundNodeStrc* gpSoundList_007C5458;                                                               // 0x007C5458
extern int gbSoundReady_007C545C;                                                                           // 0x007C545C
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax);                             // 0x004B93A0
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY);                                           // 0x004E4160
void __fastcall sub_004CA8D0_NotifyUnitHint(D2UnitStrc* pUnit, int nHandle);                                // 0x004CA8D0
extern "C" void __cdecl sub_004E4280();                                                                     // 0x004E4280
void __fastcall D2SOUND_ListRemove(D2SoundNodeStrc** ppList, D2ClientSoundStrc* pSound);               // 0x00516980
int __fastcall sub_005169D0_ListHasKey(D2SoundUnitNodeStrc* pList, D2UnitStrc* pUnit);                      // 0x005169D0
void __fastcall D2SOUND_ListFree(D2SoundUnitNodeStrc** ppList);                                        // 0x00516A10

// 0x004B94E0
static void sub_004B94E0_FreeSound(D2ClientSoundStrc* pSound)
{
    if (!pSound)
        return;

    D2SOUND_ListRemove(&gpSoundList_007C5458, pSound);
    for (D2SoundUnitNodeStrc* pNode = pSound->pUnitList; pNode; pNode = pNode->pNext)
        sub_004CA8D0_NotifyUnitHint(pNode->pUnit, pSound->f_8);

    D2SOUND_ListFree(&pSound->pUnitList);
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
        D2ClientSoundStrc* pSound = pNode->pSound;
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

// 0x004B98F0
static void sub_004B98F0_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos)
{
    D2_ASSERT(pSound && pPos, 0x1A6);

    pSound->vPos = *pPos;
    const float fX = sub_004B93A0_ClampFloat(pPos->fX, -2000.0f, 2000.0f);
    const float fY = sub_004B93A0_ClampFloat(pPos->fY, -2000.0f, 2000.0f);
    pSound->fDistance = sub_004E4160_LengthSquared2D(fX, fY);
}

// 0x004B99A0
void __fastcall sub_004B99A0_MoveSound(int nHandle, int nX, int nY, int nZ)
{
    if (!nHandle)
        return;

    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        if (pSound->f_8 == nHandle)
        {
            D2SoundVecStrc tPos;
            tPos.fX = (float)nX;
            tPos.fY = (float)nY;
            tPos.fZ = (float)(nZ + 640.0);
            sub_004B98F0_SetSoundPosition(pSound, &tPos);
            return;
        }
    }
}

// 0x004B9D20
void __cdecl sub_004B9D20_FreeAllSounds()
{
    sub_004E4280();
    while (gpSoundList_007C5458)
        sub_004B94E0_FreeSound(gpSoundList_007C5458->pSound);

    gbSoundReady_007C545C = 1;
}

// 0x004B9E90
int __fastcall sub_004B9E90_HasUnitSound(D2UnitStrc* pUnit)
{
    return sub_004B9700_FindUnitSound(0, pUnit) != 0;
}
