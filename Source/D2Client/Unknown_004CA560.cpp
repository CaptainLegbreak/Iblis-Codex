extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2StatListStrc;

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
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

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

struct D2UnitSndPlayerStrc
{
    int f_0;
    int nDeathSound;
    int anEventSounds[8];
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

struct D2SuperUniquesTxt
{
    char unk0x00[0x18];
    int dwMonSound;
};

struct D2MonStatsTxt
{
    char unk0x00[0x16];
    short wUMonSound;
};

struct D2DataTablesStrc
{
    char unk0x00[0xA80];
    int nMonStatsTxtRecordCount;
};

struct D2DirRateStrc
{
    int nValue;
    unsigned int nRate;
};

struct D2SkillsTxt
{
    char unk0x00[0xFC];
    short wStSound;
};

struct D2SkillStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2UnitSndPlayerStrc* gapUnitSndPlayers[];                                                     // 0x0072A008
extern D2UnitSndObjectStrc* gapUnitSndObjects[];                                                     // 0x007295F8
extern D2UnitSndObjectStrc gtUnitSndObject;                                                         // 0x00729328
extern int gaUnitSndObject3D[];                                                                    // 0x00728338
extern D2DirRateStrc gaDirRate[];                                                                  // 0x00727ED8
extern unsigned int gnNeutralTick;                                                                 // 0x007C88B8
extern unsigned int gnSfxTick;                                                                     // 0x007C88BC
extern unsigned int gnNeutralDelay;                                                                // 0x007C88C0

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId);                          // 0x00656F90
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId);                      // 0x00656FC0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit);                                          // 0x004AC7C0
int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit);                                              // 0x004AE360
int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380
int __fastcall MONSTER_IsSuperUniqueMonster(D2UnitStrc* pUnit);                                              // 0x004AE3A0
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit);                                                             // 0x00463860
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue);                                            // 0x004B9B50
int __fastcall SOUNDINST_HasActiveHint(int nKey); // 0x004B9BE0
int __fastcall SOUNDINST_GetSoundIdByHandle(int nKey); // 0x004B9CA0
int __fastcall SOUNDINST_IsNearPlayer(D2UnitStrc* pUnit);                                                // 0x004B9E10
int __fastcall SOUNDINST_HasUnitSound(D2UnitStrc* pUnit);                                                // 0x004B9E90
void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce); // 0x004BA790
int __fastcall SOUNDHDR_GetGroupStart(int nId);                                                          // 0x00481890
void __fastcall SOUNDHDR_AddVariantRefs(int nIndex, int nDelta);                                        // 0x004822B0
int __cdecl sub_0044DB00(); // 0x0044DB00
int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0
extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100
int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength);                     // 0x004E4180
int __fastcall UNITSND_GetModeSound(D2UnitStrc* pUnit, int nMode);                                     // 0x004CA810
int __fastcall UNITSND_GetUnitFloorMaterial(D2UnitStrc* pUnit);                                        // 0x004CADB0
unsigned int __fastcall UNITSND_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection);               // 0x004CA500
void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __fastcall UNITSND_PurgeUnitHints(D2UnitStrc* pUnit);                                             // 0x004CAA10
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit);                                                             // 0x00623C20
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
void __fastcall TEXT_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId);                          // 0x004A0200
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590
void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg);                                         // 0x004DCE10

void __stdcall UNITSND_ReleaseMonsterSfx(D2UnitStrc* pUnit); // 0x004CB2C0
void __fastcall UNITSND_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta); // 0x004CC160

#define UNIT_INVALID 6

// build: symbol ?UNITSND_GetUnitSndClassId@* 0x004CA2C0
static int UNITSND_GetUnitSndClassId(D2UnitStrc* pUnit)
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

// build: symbol ?UNITSND_GetUnitSndType@* 0x004CA320
static int UNITSND_GetUnitSndType(D2UnitStrc* pUnit)
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

static inline void sub_004CA560_SetHitSound1(int nHitClass, int* pSound1)
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

static inline void sub_004CA560_SetHitSound2(int nHitClass, int* pSound1, int* pSound2, int nType, int bParam)
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
    int nType = UNITSND_GetUnitSndType(pUnit);
    *pSound1 = 0;
    *pSound2 = 0;
    if (nType == 1)
    {
        if (MONSTERREGION_CheckMonStats2Flag(UNITSND_GetUnitSndClassId(pUnit), 0xD))
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
