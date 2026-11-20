#include "D2ClientGame.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2TxtItems.h"
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2StatListStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

struct D2UnitSndPlayerStrc
{
    int f_0;
    int nDeathSound;
    int unk0x08[8];
    int nFootstep;
};

struct D2UnitSndObjectStrc
{
    int nModeSound[8];
    int nSoundA;
    int nSoundAMode;
    int nSoundB;
    int nSoundBMode;
};

struct D2DirRateStrc
{
    int nValue;
    unsigned int nRate;
};

struct D2SkillStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2UnitSndPlayerStrc* gpUnitSndPlayer_0072A008[];                                                     // 0x0072A008
extern D2UnitSndObjectStrc* gpUnitSndObject_007295F8[];                                                     // 0x007295F8
extern D2UnitSndObjectStrc gUnitSndObject_00729328;                                                         // 0x00729328
extern int gnUnitSndObject3D_00728338[];                                                                    // 0x00728338
extern D2DirRateStrc gaDirRate_00727ED8[];                                                                  // 0x00727ED8
extern unsigned int gnNeutralTick_007C88B8;                                                                 // 0x007C88B8
extern unsigned int gnSfxTick_007C88BC;                                                                     // 0x007C88BC
extern unsigned int gnNeutralDelay_007C88C0;                                                                // 0x007C88C0

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId);                          // 0x00656F90
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId);                      // 0x00656FC0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit);                                          // 0x004AC7C0
int __fastcall sub_004AE360_IsUniqueMonster(D2UnitStrc* pUnit);                                              // 0x004AE360
int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380
int __fastcall sub_004AE3A0_IsSuperUniqueMonster(D2UnitStrc* pUnit);                                              // 0x004AE3A0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue);                                            // 0x004B9B50
int __fastcall sub_004B9BE0_HasActiveHint(int nKey); // 0x004B9BE0
int __fastcall sub_004B9CA0_GetHintIdByKey(int nKey); // 0x004B9CA0
int __fastcall sub_004B9E10_IsNearPlayer(D2UnitStrc* pUnit);                                                // 0x004B9E10
int __fastcall sub_004B9E90_HasUnitSound(D2UnitStrc* pUnit);                                                // 0x004B9E90
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce); // 0x004BA790
int __fastcall sub_00481890_GetCacheFirst(int nId);                                                          // 0x00481890
void __fastcall sub_004822B0_AddVariantRefs(int nIndex, int nDelta);                                        // 0x004822B0
int __cdecl sub_0044DB00(); // 0x0044DB00
int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0
extern "C" int __fastcall sub_004E4100_RandomInRange(int nMin, int nMax); // 0x004E4100
int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength);                     // 0x004E4180
int __fastcall sub_004CA810_GetModeSound(D2UnitStrc* pUnit, int nMode);                                     // 0x004CA810
int __fastcall sub_004CADB0_GetUnitFloorMaterial(D2UnitStrc* pUnit);                                        // 0x004CADB0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection);               // 0x004CA500
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __fastcall sub_004CAA10_PurgeUnitHints(D2UnitStrc* pUnit);                                             // 0x004CAA10
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit);                                                             // 0x00623C20
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
void __fastcall sub_004A0200_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId);                          // 0x004A0200
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590
void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg);                                         // 0x004DCE10

void __stdcall sub_004CB2C0_ReleaseMonsterSfx(D2UnitStrc* pUnit);
__declspec(noinline) void __fastcall sub_004CC160_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta);

#define UNIT_INVALID 6

static __declspec(noinline) int sub_004CA2C0_GetUnitSndClassId(D2UnitStrc* pUnit)
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

static __declspec(noinline) int sub_004CA320_GetUnitSndType(D2UnitStrc* pUnit)
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

static __forceinline void sub_004CA560_SetHitSound1(int nHitClass, int* pSound1)
{
    switch (nHitClass & 0xF)
    {
    case 1: *pSound1 = 0x141; break;
    case 8: case 9: *pSound1 = 0x149; break;
    case 6: case 7: *pSound1 = 0x14F; break;
    case 2: case 3: case 4: case 5: *pSound1 = 0x155; break;
    case 10: case 11: *pSound1 = 0x15B; break;
    case 12: *pSound1 = 0x145; break;
    }
}

static __forceinline void sub_004CA560_SetHitSound2(int nHitClass, int* pSound1, int* pSound2, int nType, int bParam)
{
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

// 0x004CA560
void __fastcall sub_004CA560_GetHitSounds(D2UnitStrc* pUnit, int nHitClass, int bParam, int* pSound1, int* pSound2)
{
    D2_ASSERT(pUnit, 0xB82);
    int nType = sub_004CA320_GetUnitSndType(pUnit);
    *pSound1 = 0;
    *pSound2 = 0;
    if (nType == 1)
    {
        if (sub_004638A0_CheckMonStats2Flag(sub_004CA2C0_GetUnitSndClassId(pUnit), 0xD))
            return;
    }

    const int nHitClassHigh = nHitClass & 0xF0;
    switch (nHitClass & 0xF)
    {
    case 1: *pSound1 = 0x141; break;
    case 8: case 9: *pSound1 = 0x149; break;
    case 6: case 7: *pSound1 = 0x14F; break;
    case 2: case 3: case 4: case 5: *pSound1 = 0x155; break;
    case 10: case 11: *pSound1 = 0x15B; break;
    case 12: *pSound1 = 0x145; break;
    }

    switch (nHitClassHigh)
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
