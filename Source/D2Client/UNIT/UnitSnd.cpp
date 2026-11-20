#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_INVALID 6

struct D2UnitSfxNodeStrc;
struct D2UnitStrc;
struct D2MonSoundsTxt;
struct D2UnitSndPlayerStrc;
struct D2UnitSndObjectStrc;
struct D2SuperUniquesTxt;
struct D2MonStatsTxt;
struct D2DataTablesStrc;
struct D2DirRateStrc;
struct D2SkillsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2UnitSfxNodeStrc
{
    void* f_0;
    D2UnitSfxNodeStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x3C];
    int nSeqCurrentFramePrecise;
    unsigned int dwFrameCountPrecise;
    short wAnimSpeed;
    char unk0x4E[0x22];
    unsigned char bUnitSfx;
    char unk0x71[3];
    int dwSfxMode;
    D2UnitSfxNodeStrc* pUnitSfxList;
    unsigned int dwSfxTicks;
    unsigned int dwSfxAsyncTicks;
    unsigned int dwSfxStepTicks;
    int bHasActiveSound;
    char unk0x8C[0x24];
    int dwLastHitClass;
};

struct D2MonSoundsTxt
{
    unsigned int dwId;
    unsigned int dwAttack1;
    unsigned int dwAtt1Del;
    unsigned int dwAtt1Prb;
    unsigned int dwAttack2;
    unsigned int dwAtt2Del;
    unsigned int dwAtt2Prb;
    unsigned int dwWeapon1;
    unsigned int dwWea1Del;
    unsigned int dwWea1Vol;
    unsigned int dwWeapon2;
    unsigned int dwWea2Del;
    unsigned int dwWea2Vol;
    unsigned int dwHitSound;
    unsigned int dwHitDelay;
    unsigned int dwDeathSound;
    unsigned int dwDeaDelay;
    unsigned int dwSkill[4];
    unsigned int dwFootstep;
    unsigned int dwFootstepLayer;
    unsigned int dwFsCnt;
    unsigned int dwFsOff;
    unsigned int dwFsPrb;
    unsigned int dwNeutral;
    unsigned int dwNeuTime;
    unsigned int dwInit;
    unsigned int dwTaunt;
    unsigned int dwFlee;
    unsigned char nCvtMo1;
    unsigned char nCvtTgt1;
    unsigned short pad0x7E;
    int dwCvtSk1;
    unsigned char nCvtMo2;
    unsigned char nCvtTgt2;
    unsigned short pad0x86;
    int dwCvtSk2;
    unsigned char nCvtMo3;
    unsigned char nCvtTgt3;
    unsigned short pad0x8E;
    int dwCvtSk3;
};

struct D2SuperUniquesTxt
{
    char unk0x00[0x18];
    int dwMonSound;
};




extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2UnitSndPlayerStrc* gpUnitSndPlayer_0072A008[]; // 0x0072A008
extern D2UnitSndObjectStrc* gpUnitSndObject_007295F8[]; // 0x007295F8
extern D2UnitSndObjectStrc gUnitSndObject_00729328; // 0x00729328
extern int gnUnitSndObject3D_00728338[]; // 0x00728338
extern D2DirRateStrc gaDirRate_00727ED8[]; // 0x00727ED8
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId); // 0x00656F90
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId); // 0x00656FC0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit); // 0x004AC7C0
int __fastcall sub_004AE360_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360
int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit); // 0x004AE380
int __fastcall sub_004AE3A0_IsSuperUniqueMonster(D2UnitStrc* pUnit); // 0x004AE3A0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue); // 0x004B9B50
int __fastcall sub_004B9BE0_HasActiveHint(void* pEntry); // 0x004B9BE0
int __fastcall sub_004B9CA0_GetHintIdByKey(void* pKey); // 0x004B9CA0
int __fastcall sub_004B9E10_IsNearPlayer(D2UnitStrc* pUnit); // 0x004B9E10
int __fastcall sub_004B9E90_HasUnitSound(D2UnitStrc* pUnit); // 0x004B9E90
void __fastcall sub_004B9EF0_ArmHint(void* pEntry, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790
int __fastcall sub_00481890_GetCacheFirst(int nId); // 0x00481890
void __fastcall sub_004822B0_AddVariantRefs(int nIndex, int nDelta); // 0x004822B0
unsigned int __cdecl sub_0044DB00(); // 0x0044DB00
int __fastcall sub_004E40A0(int nRange); // 0x004E40A0
int __fastcall sub_004E4100(int nMin, int nMax); // 0x004E4100
int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength); // 0x004E4180
int __fastcall sub_004CA810_GetModeSound(D2UnitStrc* pUnit, int nMode); // 0x004CA810
int __fastcall sub_004CADB0_GetUnitFloorMaterial(D2UnitStrc* pUnit); // 0x004CADB0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __fastcall sub_004CAA10_PurgeUnitHints(D2UnitStrc* pUnit); // 0x004CAA10
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall sub_004A0200_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId); // 0x004A0200
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType); // 0x004E0590
void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg); // 0x004DCE10
void __stdcall sub_004CB2C0_ReleaseMonsterSfx(D2UnitStrc* pUnit);
__declspec(noinline) void __fastcall sub_004CC160_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta);
extern unsigned int gnNeutralTick_007C88B8;
extern unsigned int gnSfxTick_007C88BC;
extern unsigned int gnNeutralDelay_007C88C0;

unsigned int gnNeutralTick_007C88B8; // 0x007C88B8

unsigned int gnSfxTick_007C88BC; // 0x007C88BC

unsigned int gnNeutralDelay_007C88C0; // 0x007C88C0

// 0x004CA2C0
static int sub_004CA2C0_GetUnitSndClassId(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB01);
    return nClass;
}

// 0x004CA320
static int sub_004CA320_GetUnitSndType(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB0D);
    return nType;
}

// 0x004CA380
static int sub_004CA380_GetUnitSndMode(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB19);
    return nMode;
}

// 0x004CA3E0
static D2UnitSndPlayerStrc* sub_004CA3E0_GetPlayerSoundRecord(unsigned int nClass)
{
    D2_ASSERT(nClass < 7, 0xB22);
    return gpUnitSndPlayer_0072A008[nClass];
}

// build: context sub_004CA410_GetMonSoundsRecord
static D2MonSoundsTxt* sub_004CA410_GetMonSoundsRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);

    const int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount)
        return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);

    if (pUnit->dwUnitType != 1)
        return DATATBLS_GetMonSoundsTxtRecordFromMonsterId(nClass);

    if (sub_004AE3A0_IsSuperUniqueMonster(pUnit))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(sub_004AC7C0_GetSuperUniqueId(pUnit));
        if (pSuperUniquesTxtRecord && pSuperUniquesTxtRecord->dwMonSound > 0)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(pSuperUniquesTxtRecord->dwMonSound);
    }

    if (sub_004AE360_IsUniqueMonster(pUnit) || sub_004AE380_IsMinionMonster(pUnit))
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClass);
        if (!pMonStatsTxtRecord)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);
        if (pMonStatsTxtRecord->wUMonSound > 0)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(pMonStatsTxtRecord->wUMonSound);
    }

    return DATATBLS_GetMonSoundsTxtRecordFromMonsterId(nClass);
}

int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, unsigned int nDirection)
{
    D2_ASSERT(pUnit, 0xB5C);
    nDirection &= 0xF;
    if (nDirection <= 0xD)
        return gaDirRate_00727ED8[nDirection].nValue;
    D2_ASSERT(0, 0xB60);
}

void __fastcall sub_004CA560_GetHitSounds(D2UnitStrc* pUnit, int nHitClass, int bParam, int* pSound1, int* pSound2)
{
    D2_ASSERT(pUnit, 0xB82);
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    *pSound1 = 0;
    *pSound2 = 0;
    if (nType == 1 && sub_004638A0_CheckMonStats2Flag(sub_004CA2C0_GetUnitSndClassId(pUnit), 0xD))
        return;

    switch (nHitClass & 0xF)
    {
    case 1:
        *pSound1 = 0x141;
        break;
    case 8:
    case 9:
        *pSound1 = 0x149;
        break;
    case 6:
    case 7:
        *pSound1 = 0x14F;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        *pSound1 = 0x155;
        break;
    case 10:
    case 11:
        *pSound1 = 0x15B;
        break;
    case 12:
        *pSound1 = 0x145;
        break;
    }

    switch (nHitClass & 0xF0)
    {
    case 0x20:
        *pSound2 = *pSound1 ? 0x164 : 0x161;
        break;
    case 0x30:
        if (!*pSound1)
        {
            *pSound2 = 0x167;
            break;
        }
        if ((nType == 0 || nType == 1) && !bParam)
            break;
        *pSound2 = 0x16A;
        break;
    case 0x40:
        *pSound2 = *pSound1 ? 0x174 : 0x170;
        break;
    case 0x50:
        if (*pSound1 && (nType == 0 || nType == 1) && !bParam)
            break;
        *pSound2 = 0x178;
        break;
    case 0x10:
        if (*pSound1)
            *pSound2 = 0x17B;
        break;
    case 0x60:
        *pSound2 = 0x17E;
        break;
    case 0x70:
        *pSound2 = 0x18B;
        break;
    case 0x80:
        *pSound2 = 0x956;
        break;
    case 0xB0:
        *pSound2 = 0x187;
        break;
    }
}

// 0x004CAB30
static __declspec(noinline) unsigned int sub_004CAB30_ReadSoundTick(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCBB);
    return pUnit->dwSfxTicks;
}

// 0x004CAB60
static void __stdcall sub_004CAB60_WriteSoundTick(D2UnitStrc* pUnit, unsigned int nTicks)
{
    D2_ASSERT(pUnit, 0xCC6);
    pUnit->dwSfxTicks = nTicks;
}

// 0x004CAB90
static unsigned int sub_004CAB90_ReadAsyncSoundTick(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCD1);
    return pUnit->dwSfxAsyncTicks;
}

// 0x004CABC0
static void __stdcall sub_004CABC0_WriteAsyncSoundTick(D2UnitStrc* pUnit, unsigned int nTicks)
{
    D2_ASSERT(pUnit, 0xCDC);
    pUnit->dwSfxAsyncTicks = nTicks;
}

// 0x004CAC30
static void __stdcall sub_004CAC30_WriteStepSoundTick(D2UnitStrc* pUnit, unsigned int nTicks)
{
    D2_ASSERT(pUnit, 0xCF2);
    pUnit->dwSfxStepTicks = nTicks;
}

// build: context sub_004CAEB0_GetFootstepSound
int __fastcall sub_004CAEB0_GetFootstepSound(D2UnitStrc* pUnit, int bLayer)
{
    int nSound = 0;
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    if (nType == 0)
    {
        nSound = sub_004CA3E0_GetPlayerSoundRecord(sub_004CA2C0_GetUnitSndClassId(pUnit))->nFootstep;
    }
    else if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
        nSound = !pMonSoundsTxtRecord ? 0 : pMonSoundsTxtRecord->dwFootstep;
    }

    if (!nSound)
        return 0;

    switch (sub_004CADB0_GetUnitFloorMaterial(pUnit))
    {
    case 2:
        nSound += 4;
        break;
    case 3:
        nSound += 8;
        break;
    case 4:
        nSound += 0xC;
        break;
    case 6:
        nSound += 0x14;
        break;
    case 5:
        nSound += 0x10;
        break;
    }

    if (bLayer)
        nSound += 0x18;
    return nSound;
}

// build: context sub_004CAF60_UpdateFootsteps
void __fastcall sub_004CAF60_UpdateFootsteps(D2UnitStrc* pUnit)
{
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    const int nMode = sub_004CA380_GetUnitSndMode(pUnit);
    if (nType == 1)
    {
        int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
        if (nClass < 0 || nClass >= sgptDataTables->nMonStatsTxtRecordCount)
            nClass = -1;

        int bWalk = 0;
        if (nMode == 2 || nMode == 0xF)
            bWalk = 1;

        if (nClass == 0xF && nMode == 1)
            bWalk = 1;
        else if (nClass == 0x6E)
            bWalk = nMode == 8;

        if (!bWalk)
            return;
    }

    unsigned int nFrameCount = pUnit->dwFrameCountPrecise;
    const int nFrame = pUnit->nSeqCurrentFramePrecise;
    const int nSpeed = pUnit->wAnimSpeed;
    if (!nSpeed)
        return;

    unsigned int nOffset = 0;
    unsigned int nSteps = 2;
    unsigned int nLayerSound = 0;
    unsigned int nChance = 100;
    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
        if (pMonSoundsTxtRecord)
        {
            nOffset = pMonSoundsTxtRecord->dwFsOff << 8;
            nSteps = pMonSoundsTxtRecord->dwFsCnt;
            nLayerSound = pMonSoundsTxtRecord->dwFootstepLayer;
            nChance = pMonSoundsTxtRecord->dwFsPrb;
            if (!nSteps)
                return;
        }
    }

    const unsigned int nTick = sub_0044DB00();
    const unsigned int nPeriod = nFrameCount / (nSteps * nSpeed);
    const unsigned int nElapsed = nTick - pUnit->dwSfxStepTicks;
    if (nSteps > 1 && nElapsed < nPeriod * 2 / 3)
        return;

    const unsigned int nStepLength = nFrameCount / nSteps;
    const int nDist = sub_004E4180(nFrame, nOffset, nStepLength);
    const int nDistNext = sub_004E4180(nFrame + nSpeed, nOffset, nStepLength);
    const int nDistPrev = sub_004E4180(nFrame - nSpeed, nOffset, nStepLength);
    if (nDist >= nDistNext || nDist >= nDistPrev)
        return;

    int bRun = 0;
    if (nType == 0)
    {
        if (nMode == 3)
            bRun = 1;
    }
    else if (nType == 1)
    {
        if (nMode == 0xF)
            bRun = 1;
    }

    const int hSound = sub_004B9A00(sub_004CAEB0_GetFootstepSound(pUnit, bRun), pUnit, 0, 0, 0);
    if (hSound)
    {
        int nVolume = 0xFF;
        if (pUnit != sub_00463DD0_GetPlayerUnit())
            nVolume = 0xC8;
        if (nElapsed > nPeriod * 3 / 2)
            nVolume = nVolume * 160 / 255;
        sub_004B9B50_SetValue(hSound, nVolume);
    }

    if (nLayerSound && (unsigned int)sub_004E40A0(100) < nChance)
        sub_004B9A00(nLayerSound, pUnit, 0, 0, 0);

    sub_004CAC30_WriteStepSoundTick(pUnit, nTick);
}

// 0x004CB190
void __fastcall sub_004CB190_ReleaseSkillSfx(D2UnitStrc* pUnit)
{
    if (sub_004CA320_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    D2_ASSERT(pUnit, 0xC2C);
    D2UnitSfxNodeStrc* pNode = pUnit->pUnitSfxList;
    while (pNode)
    {
        void* pEntry = pNode->f_0;
        D2UnitSfxNodeStrc* pNext = pNode->pNext;
        const int nGroup = sub_00481890_GetCacheFirst(sub_004B9CA0_GetHintIdByKey(pEntry));
        if (nGroup == pMonSoundsTxtRecord->dwSkill[0] || nGroup == pMonSoundsTxtRecord->dwSkill[1]
            || nGroup == pMonSoundsTxtRecord->dwSkill[2] || nGroup == pMonSoundsTxtRecord->dwSkill[3])
            sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 1);
        pNode = pNext;
    }
}

// 0x004CB220
void __stdcall sub_004CB220_ReleaseNeutralSfx(D2UnitStrc* pUnit, int bArm)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2UnitSfxNodeStrc* pNode = pUnit->pUnitSfxList;
    while (pNode)
    {
        D2UnitSfxNodeStrc* pNext = pNode->pNext;
        void* pEntry = pNode->f_0;
        D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
        const int nNeutral = !pMonSoundsTxtRecord ? 0 : pMonSoundsTxtRecord->dwNeutral;
        if (sub_00481890_GetCacheFirst(sub_004B9CA0_GetHintIdByKey(pEntry)) == nNeutral)
        {
            if (bArm && !sub_004B9BE0_HasActiveHint(pEntry))
                sub_004B9EF0_ArmHint(pEntry, 0, 0, 6);
            else
                sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 1);
        }
        pNode = pNext;
    }
}

// 0x004CB2C0
void __stdcall sub_004CB2C0_ReleaseMonsterSfx(D2UnitStrc* pUnit)
{
    if (sub_004CA320_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    D2_ASSERT(pUnit, 0xC2C);
    D2UnitSfxNodeStrc* pNode = pUnit->pUnitSfxList;
    while (pNode)
    {
        void* pEntry = pNode->f_0;
        D2UnitSfxNodeStrc* pNext = pNode->pNext;
        const int nGroup = sub_00481890_GetCacheFirst(sub_004B9CA0_GetHintIdByKey(pEntry));
        if (nGroup == pMonSoundsTxtRecord->dwAttack1 || nGroup == pMonSoundsTxtRecord->dwWeapon1
            || nGroup == pMonSoundsTxtRecord->dwHitSound || nGroup == pMonSoundsTxtRecord->dwNeutral
            || nGroup == pMonSoundsTxtRecord->dwSkill[0] || nGroup == pMonSoundsTxtRecord->dwSkill[1]
            || nGroup == pMonSoundsTxtRecord->dwSkill[2] || nGroup == pMonSoundsTxtRecord->dwSkill[3]
            || nGroup == pMonSoundsTxtRecord->dwInit || nGroup == pMonSoundsTxtRecord->dwTaunt
            || nGroup == pMonSoundsTxtRecord->dwFlee)
            sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 1);
        pNode = pNext;
    }
}

// 0x004CB380
static int __stdcall sub_004CB380_GetObjectStopSound(D2UnitStrc* pUnit, int nMode, int nOldMode)
{
    const unsigned int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
    if (nClass < 0x23D && nMode < 8)
    {
        D2UnitSndObjectStrc* pRecord = gpUnitSndObject_007295F8[nClass];
        if (!pRecord)
            return 0;
        if (pRecord == &gUnitSndObject_00729328 && nOldMode > nMode)
            return 0;
        return pRecord->nModeSound[nMode];
    }
    D2_ASSERT(0, 0xE72);
}

// 0x004CB3E0
static int sub_004CB3E0_GetObjectModeSound(D2UnitStrc* pUnit, int nMode)
{
    const unsigned int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
    if (nClass < 0x23D && nMode < 8)
    {
        D2UnitSndObjectStrc* pRecord = gpUnitSndObject_007295F8[nClass];
        if (!pRecord)
            return 0;
        if (nClass == 0x3D)
            return gnUnitSndObject3D_00728338[nMode];
        if (!pRecord->nSoundA && !pRecord->nSoundB)
            return 0;
        if (pRecord->nSoundAMode == nMode || pRecord->nSoundAMode == 8)
            return pRecord->nSoundA;
        if (pRecord->nSoundBMode == nMode || pRecord->nSoundBMode == 8)
            return pRecord->nSoundB;
        return 0;
    }
    D2_ASSERT(0, 0xE86);
}

// 0x004CB460
void __fastcall sub_004CB460_UpdateModeSound(D2UnitStrc* pUnit)
{
    const int nMode = sub_004CA380_GetUnitSndMode(pUnit);
    if (sub_004CA320_GetUnitSndType(pUnit) == 2)
    {
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x1A && !nMode && !sub_004CAB90_ReadAsyncSoundTick(pUnit)
            && sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0_GetPlayerUnit()) < 0x14)
        {
            sub_004B9A00(0xE57, pUnit, 0, 0, 0);
            sub_004CABC0_WriteAsyncSoundTick(pUnit, sub_0044DB00());
        }

        D2_ASSERT(pUnit, 0xC8F);
        if (pUnit->bUnitSfx && nMode == pUnit->dwSfxMode)
            return;

        const int nSound = sub_004CB3E0_GetObjectModeSound(pUnit, nMode);
        if (nSound)
        {
            if (!sub_004CA900_FindUnitSfxInRange(pUnit, nSound))
                sub_004B9A00(nSound, pUnit, 0, 0, 0);
        }
        else
        {
            sub_004CAA10_PurgeUnitHints(pUnit);
        }

        int bForce = 0;
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x3B)
            bForce = 1;

        if (pUnit->bUnitSfx || bForce)
        {
            const int nStopSound = sub_004CB380_GetObjectStopSound(pUnit, nMode, pUnit->dwSfxMode);
            if (nStopSound)
                sub_004B9A00(nStopSound, pUnit, 0, 0, 0);
        }

        pUnit->dwSfxMode = nMode;
        pUnit->bUnitSfx = 1;
        return;
    }

    if (sub_004CA320_GetUnitSndType(pUnit) != 1)
        return;

    int nClass = sub_00463860(pUnit);
    if (nClass < 0 || nClass >= sgptDataTables->nMonStatsTxtRecordCount)
        nClass = -1;

    int bNeutral = 0;
    if (nMode == 1 || nMode == 2 || nMode == 0xF)
        bNeutral = 1;

    if (nClass == 0x6E && nMode == 8)
        bNeutral = 1;
    else if (nClass == 0x88 && nMode == 0xB)
        bNeutral = 1;

    if (!bNeutral)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    D2MonSoundsTxt* pNeutralRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    const int nNeutral = !pNeutralRecord ? 0 : pNeutralRecord->dwNeutral;
    const unsigned int nTick = sub_0044DB00();
    const unsigned int nNeuTime = pMonSoundsTxtRecord->dwNeuTime;
    if (!nNeutral)
        return;
    if (sub_004CA900_FindUnitSfxInRange(pUnit, nNeutral))
        return;
    if (nTick - gnNeutralTick_007C88B8 < gnNeutralDelay_007C88C0)
        return;
    if (nTick - sub_004CAB30_ReadSoundTick(pUnit) < nNeuTime)
        return;
    if (nTick - sub_004CAB90_ReadAsyncSoundTick(pUnit) < nNeuTime)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        return;
    if (!sub_004B9E10_IsNearPlayer(pUnit))
        return;
    if (sub_004E40A0(0xF))
        return;

    sub_004B9A00(nNeutral, pUnit, 0, 0, 0);
    gnNeutralTick_007C88B8 = nTick;
    sub_004CABC0_WriteAsyncSoundTick(pUnit, nTick);
    gnNeutralDelay_007C88C0 = sub_004E4100(0x1E, 0x5A);
}

// build: context sub_004CB6A0_PlayAttackSound
void __fastcall sub_004CB6A0_PlayAttackSound(D2UnitStrc* pUnit, int nMode, int bDelay)
{
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    if (nType == 0)
    {
        const int nDirection = UNITS_GetHitClass(pUnit);
        const int nSound = sub_004CA4C0(pUnit, nDirection);
        unsigned int nRate = sub_004CA500_GetAnimRate(pUnit, nDirection);
        if (!bDelay)
            nRate = 0;
        sub_004B9A00(nSound, pUnit, nRate, 0, 0);
        pUnit->dwSfxTicks = sub_0044DB00();
        return;
    }

    if (nType != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    int nDelay;
    int nSound;
    if (nMode == 4)
    {
        nSound = pMonSoundsTxtRecord->dwAttack1;
        nDelay = pMonSoundsTxtRecord->dwAtt1Del;
    }
    else
    {
        nSound = pMonSoundsTxtRecord->dwWeapon1;
        nDelay = pMonSoundsTxtRecord->dwWea1Del;
    }

    if (!bDelay)
        nDelay = 0;

    int nChance;
    if (nMode == 4)
        nChance = pMonSoundsTxtRecord->dwAtt1Prb;
    else
        nChance = pMonSoundsTxtRecord->dwWea1Vol;

    int bPlay = 1;
    if (!nSound)
        bPlay = 0;
    if ((unsigned int)nChance < 100)
    {
        if (sub_0044DB00() - gnSfxTick_007C88BC < 0xF)
            bPlay = 0;
        if (sub_004B9E90_HasUnitSound(pUnit))
            goto second;
    }

    if (bPlay && sub_004E40A0(100) < nChance)
    {
        sub_004CB220_ReleaseNeutralSfx(pUnit, 1);
        sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
        sub_004CAB60_WriteSoundTick(pUnit, sub_0044DB00());
        gnSfxTick_007C88BC = sub_0044DB00();
    }

second:
    int nSpeed = pUnit->wAnimSpeed;
    if (!nSpeed)
        nSpeed = 1;

    unsigned int nRate;
    if (nMode == 4)
    {
        nSound = pMonSoundsTxtRecord->dwAttack2;
        nRate = pMonSoundsTxtRecord->dwAtt2Del;
    }
    else
    {
        nSound = pMonSoundsTxtRecord->dwWeapon2;
        nRate = pMonSoundsTxtRecord->dwWea2Del;
    }
    nRate = ((nRate << 8) + 0x80) / nSpeed;

    int nVolume;
    if (nMode == 4)
        nVolume = pMonSoundsTxtRecord->dwAtt2Prb;
    else
        nVolume = pMonSoundsTxtRecord->dwWea2Vol;

    const int hSound = sub_004B9A00(nSound, pUnit, nRate, 0, 0);
    if (hSound)
        sub_004B9B50_SetValue(hSound, nVolume);
}

// 0x004CB860
static void sub_004CB860_PlayHitClassSound(D2UnitStrc* pUnit)
{
    const int nSound = sub_004CA810_GetModeSound(pUnit, pUnit->dwLastHitClass);
    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    pUnit->dwSfxTicks = sub_0044DB00();
    gnSfxTick_007C88BC = sub_0044DB00();
}

// 0x004CB890
static void sub_004CB890_PlaySkillSound(D2UnitStrc* pUnit, int nMode)
{
    if (sub_004CA320_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    const unsigned int nTick = sub_0044DB00();
    int nSound;
    if (nMode == 8)
        nSound = pMonSoundsTxtRecord->dwSkill[0];
    else if (nMode == 9)
        nSound = pMonSoundsTxtRecord->dwSkill[1];
    else if (nMode == 0xA)
        nSound = pMonSoundsTxtRecord->dwSkill[2];
    else if (nMode == 0xB)
        nSound = pMonSoundsTxtRecord->dwSkill[3];
    else
        return;

    if (nSound == 0xA84)
    {
        D2_ASSERT(pUnit, 0xCBB);
        if (nTick - pUnit->dwSfxTicks < 0x19)
            return;
    }
    else if (!nSound)
    {
        return;
    }

    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    const unsigned int nNow = sub_0044DB00();
    D2_ASSERT(pUnit, 0xCC6);
    pUnit->dwSfxTicks = nNow;
    gnSfxTick_007C88BC = sub_0044DB00();
}

// 0x004CB950
static void sub_004CB950_PlayFleeSound(D2UnitStrc* pUnit)
{
    if (sub_004CA320_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    if (sub_0044DB00() - gnSfxTick_007C88BC < 4)
        return;

    sub_004B9A00(pMonSoundsTxtRecord->dwFlee, pUnit, sub_004E40A0(3) + 6, 0, 0);
    sub_004CAB60_WriteSoundTick(pUnit, sub_0044DB00());
    gnSfxTick_007C88BC = sub_0044DB00();
}

void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent)
{
    D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
    if (!pUnit)
        return;

    int nSpeech;

    switch (nEvent)
    {
    case 90:
        sub_004B9A00(0x111B, pUnit, 0, 0, 0);
        return;
    case 10:
        sub_004B9B50_SetValue(sub_004B9A00(0xA71, pUnit, 0, 0, 0), 0x78);
        return;
    case 93:
        sub_004B9A00(0x9F9, pUnit, 0, 0, 0);
        return;
    case 12:
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x44);
        if (!pStatList)
            return;
        const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
        if (!SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
            return;
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord && pSkillsTxtRecord->wStSound > 0)
            sub_004B9A00(pSkillsTxtRecord->wStSound, pUnit, 0, 0, 0);
        return;
    }
    case 84:
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1207, pUnit, 0, 0, 0);
            nSpeech = 0x1207;
        }
        else
        {
            sub_004B9A00(0x1211, pUnit, 0, 0, 0);
            nSpeech = 0x1211;
        }
        break;
    case 85:
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1204, pUnit, 0, 0, 0);
            nSpeech = 0x1204;
        }
        else
        {
            sub_004B9A00(0x1208, pUnit, 0, 0, 0);
            nSpeech = 0x1208;
        }
        break;
    case 86:
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1205, pUnit, 0, 0, 0);
            nSpeech = 0x1205;
        }
        else
        {
            sub_004B9A00(0x120B, pUnit, 0, 0, 0);
            nSpeech = 0x120B;
        }
        break;
    case 87:
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1206, pUnit, 0, 0, 0);
            nSpeech = 0x1206;
        }
        else
        {
            sub_004B9A00(0x120E, pUnit, 0, 0, 0);
            nSpeech = 0x120E;
        }
        break;
    case 15:
        if (sub_004CA2C0_GetUnitSndClassId(pUnit) == 0x10F)
            sub_004B9A00(0x10C2, pUnit, 0, 0, 0);
        return;
    case 16:
        if (sub_004CA320_GetUnitSndType(pUnit) == 1)
        {
            D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
            sub_004B9A00(!pMonSoundsTxtRecord ? 0 : pMonSoundsTxtRecord->dwTaunt, pUnit, 0, 0, 0);
        }
        return;
    case 17:
        sub_004CB950_PlayFleeSound(pUnit);
        return;
    case 18:
        sub_004B9A00(sub_004E0590_PickNpcSound(pUnit, 1), sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
        return;
    case 13:
        sub_004B9A00(0xA4A, pUnit, 0, 0, 0);
        return;
    case 14:
        sub_004B9A00(0xA4B, pUnit, 0, 0, 0);
        return;
    case 92:
        sub_004DCE10_UpdateTimedHint(0x19, 1);
        return;
    case 91:
        sub_004B9A00(8, sub_00463DD0_GetPlayerUnit(), 0, 0, 0);
        return;
    default:
        return;
    }

    sub_004A0200_SetSpeechHoverText(pUnit, nSpeech);
    if (pUnit->dwUnitType == 0)
        sub_004CB9C0_Request(pUnit, nEvent);
}

// 0x004CC160
__declspec(noinline) void __fastcall sub_004CC160_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta)
{
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    D2_ASSERT(pUnit, 0xCFD);
    if (pUnit->bHasActiveSound)
    {
        if (nDelta > 0)
            return;
    }
    else if (nDelta < 0)
    {
        return;
    }

    pUnit->bHasActiveSound = nDelta > 0;
    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
        if (!pMonSoundsTxtRecord)
            return;
        sub_004822B0_AddVariantRefs(pMonSoundsTxtRecord->dwAttack1, nDelta);
        sub_004822B0_AddVariantRefs(pMonSoundsTxtRecord->dwWeapon1, nDelta);
        sub_004822B0_AddVariantRefs(pMonSoundsTxtRecord->dwHitSound, nDelta);
        sub_004822B0_AddVariantRefs(pMonSoundsTxtRecord->dwDeathSound, nDelta);
        sub_004822B0_AddVariantRefs(pMonSoundsTxtRecord->dwFlee, nDelta);
        sub_004822B0_AddVariantRefs(pMonSoundsTxtRecord->dwFootstepLayer, nDelta);
    }
    else if (nType == 2)
    {
        const unsigned int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
        D2_ASSERT(nClass < 0x23D, 0x1213);
        D2UnitSndObjectStrc* pRecord = gpUnitSndObject_007295F8[nClass];
        if (pRecord)
        {
            for (int i = 0; i < 8; ++i)
                sub_004822B0_AddVariantRefs(pRecord->nModeSound[i], nDelta);
        }
    }
}

// 0x004CC380
void __fastcall sub_004CC380_PlayInitSound(D2UnitStrc* pUnit)
{
    if (sub_004CA320_GetUnitSndType(pUnit) != 1)
        return;

    const unsigned int nTick = sub_0044DB00();
    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    const int nInit = pMonSoundsTxtRecord->dwInit;
    if (nInit && !sub_00464820_IsDeadOrDying(pUnit) && !sub_004CAB90_ReadAsyncSoundTick(pUnit))
    {
        sub_004B9A00(nInit, pUnit, 0, 0, 0);
        gnNeutralTick_007C88B8 = nTick;
        sub_004CABC0_WriteAsyncSoundTick(pUnit, nTick);
        gnNeutralDelay_007C88C0 = sub_004E4100(0x1E, 0x5A);
        return;
    }

    const int nMode = sub_004CA380_GetUnitSndMode(pUnit);
    if (nMode == 8)
        sub_004CB890_PlaySkillSound(pUnit, nMode);
}

// 0x004CC410
static void __stdcall sub_004CC410_PlayHitSound(D2UnitStrc* pUnit, int nMode)
{
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    const int nHitClass = pUnit->dwLastHitClass;
    if (nType == 1 && STATES_CheckState(pUnit, 0x92))
        return;

    int nSound1;
    int nSound2;
    sub_004CA560_GetHitSounds(pUnit, nHitClass, nMode, &nSound1, &nSound2);
    const int hSound = sub_004B9A00(nSound1, pUnit, 0, 0, 0);
    sub_004B9A00(nSound2, pUnit, 0, 0, 0);
    if (hSound && pUnit == sub_00463DD0_GetPlayerUnit())
        sub_004B9B50_SetValue(hSound, 0xFF);

    if (nType == 1 && !nMode)
    {
        sub_004CB2C0_ReleaseMonsterSfx(pUnit);
        sub_004CC160_AddUnitSoundRefs(pUnit, -1);
    }

    if (STATES_CheckState(pUnit, 1))
        return;
    if ((nHitClass & 0xF0) == 0xA0)
        return;

    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
        if (pMonSoundsTxtRecord)
        {
            int nSound;
            int nDelay;
            if (nMode == 3 || nMode == 0xD)
            {
                if (sub_004B9E90_HasUnitSound(pUnit))
                    goto done;
                nSound = pMonSoundsTxtRecord->dwHitSound;
                nDelay = pMonSoundsTxtRecord->dwHitDelay;
            }
            else
            {
                nSound = pMonSoundsTxtRecord->dwDeathSound;
                nDelay = pMonSoundsTxtRecord->dwDeaDelay;
            }

            if (nSound)
                sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
            if (nSound == 0x2E9)
            {
                sub_004B9A00(nSound + 1, pUnit, 0x6A, 0, 0);
                sub_004B9A00(nSound + 2, pUnit, 0xC1, 0, 0);
            }
        }
    }
    else if (nType == 0)
    {
        D2UnitSndPlayerStrc* pRecord = sub_004CA3E0_GetPlayerSoundRecord(sub_004CA2C0_GetUnitSndClassId(pUnit));
        if (pRecord)
        {
            int nSound;
            int nArg;
            if (nMode == 4 || nMode == 0x13)
            {
                if (sub_004B9E90_HasUnitSound(pUnit))
                    goto done;
                nSound = pRecord->f_0;
                nArg = 2;
            }
            else
            {
                nSound = pRecord->nDeathSound;
                nArg = 1;
            }

            if (nSound)
                sub_004B9A00(nSound, pUnit, nArg, 0, 0);
        }
    }

done:
    pUnit->dwSfxTicks = sub_0044DB00();
    gnSfxTick_007C88BC = sub_0044DB00();
}

void __fastcall sub_004CC5B0_UpdateUnitSound(D2UnitStrc* pUnit, int nMode, int bModeGiven)
{
    const int nType = sub_004CA320_GetUnitSndType(pUnit);
    const int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
    if (!bModeGiven)
        nMode = sub_004CA380_GetUnitSndMode(pUnit);

    if (nType == 0)
    {
        switch (nMode)
        {
        case 15:
            if (nClass == 4)
                sub_004CB6A0_PlayAttackSound(pUnit, 15, 1);
            break;
        case 16:
            if (nClass == 6)
                sub_004CB6A0_PlayAttackSound(pUnit, 16, 1);
            break;
        case 9:
            sub_004CB860_PlayHitClassSound(pUnit);
            break;
        case 12:
            if (nClass == 6)
                sub_004B9A00(0xFF, pUnit, 4, 0, 0);
            else
                sub_004B9A00(0xFF, pUnit, 0, 0, 0);
            break;
        case 7:
        case 8:
            sub_004CB6A0_PlayAttackSound(pUnit, nMode, 1);
            break;
        case 0:
        case 4:
        case 19:
            sub_004CC410_PlayHitSound(pUnit, nMode);
            break;
        }
    }
    else if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
        if (!pMonSoundsTxtRecord)
            return;

        if (nMode == pMonSoundsTxtRecord->nCvtMo1 && pMonSoundsTxtRecord->dwCvtSk1 < 0)
            nMode = pMonSoundsTxtRecord->nCvtTgt1;
        if (nMode == pMonSoundsTxtRecord->nCvtMo2 && pMonSoundsTxtRecord->dwCvtSk2 < 0)
            nMode = pMonSoundsTxtRecord->nCvtTgt2;
        if (nMode == pMonSoundsTxtRecord->nCvtMo3 && pMonSoundsTxtRecord->dwCvtSk3 < 0)
            nMode = pMonSoundsTxtRecord->nCvtTgt3;

        switch (nMode)
        {
        case 4:
        case 5:
            sub_004CB6A0_PlayAttackSound(pUnit, nMode, 1);
            break;
        case 0:
        case 3:
        case 13:
            sub_004CC410_PlayHitSound(pUnit, nMode);
            break;
        case 8:
        case 9:
        case 10:
        case 11:
            sub_004CB890_PlaySkillSound(pUnit, nMode);
            break;
        case 12:
            sub_004CB2C0_ReleaseMonsterSfx(pUnit);
            break;
        }
    }
}

#include "gen/data/Source/D2Client/UNIT/UnitSnd.inc"
