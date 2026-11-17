extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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
int __fastcall sub_004AE360_IsMonsterFlag8(D2UnitStrc* pUnit);                                              // 0x004AE360
int __fastcall sub_004AE380_IsMonsterFlag10(D2UnitStrc* pUnit);                                             // 0x004AE380
int __fastcall sub_004AE3A0_IsMonsterFlag2(D2UnitStrc* pUnit);                                              // 0x004AE3A0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004B9B50_SetHintValue(int nKey, int nValue);                                            // 0x004B9B50
int __fastcall sub_004B9BE0_HasActiveHint(void* pEntry);                                                    // 0x004B9BE0
int __fastcall sub_004B9CA0_GetHintIdByKey(void* pKey);                                                     // 0x004B9CA0
int __fastcall sub_004B9E10_IsNearPlayer(D2UnitStrc* pUnit);                                                // 0x004B9E10
int __fastcall sub_004B9E90_HasUnitSound(D2UnitStrc* pUnit);                                                // 0x004B9E90
void __fastcall sub_004B9EF0_ArmHint(void* pEntry, int nGroup, int nOffset, unsigned int nCount);           // 0x004B9EF0
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce);                 // 0x004BA790
int __fastcall sub_00481890_GetHintGroup(int nId);                                                          // 0x00481890
void __fastcall sub_004822B0_AddVariantRefs(int nIndex, int nDelta);                                        // 0x004822B0
unsigned int __cdecl sub_0044DB00();                                                                        // 0x0044DB00
int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0
int __fastcall sub_004E4100(int nMin, int nMax);                                                            // 0x004E4100
int __fastcall sub_004E4180_GetStepDistance(int nFrame, int nOffset, int nStepLength);                     // 0x004E4180
int __fastcall sub_004CA810_GetModeSound(D2UnitStrc* pUnit, int nMode);                                     // 0x004CA810
int __fastcall sub_004CADB0_GetUnitFloorMaterial(D2UnitStrc* pUnit);                                        // 0x004CADB0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection);               // 0x004CA500
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __fastcall sub_004CAA10_PurgeUnitHints(D2UnitStrc* pUnit);                                             // 0x004CAA10
int __fastcall sub_00623C20(D2UnitStrc* pUnit);                                                             // 0x00623C20
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
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

static D2MonSoundsTxt* sub_004CA410_GetMonSoundsRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);

    const int nClass = sub_004CA2C0_GetUnitSndClassId(pUnit);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount)
        return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);

    if (pUnit->dwUnitType != 1)
        return DATATBLS_GetMonSoundsTxtRecordFromMonsterId(nClass);

    if (sub_004AE3A0_IsMonsterFlag2(pUnit))
    {
        const int nSuperUniqueId = sub_004AC7C0_GetSuperUniqueId(pUnit);
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(nSuperUniqueId);
        if (pSuperUniquesTxtRecord && pSuperUniquesTxtRecord->dwMonSound > 0)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(pSuperUniquesTxtRecord->dwMonSound);
    }

    if (sub_004AE360_IsMonsterFlag8(pUnit) || sub_004AE380_IsMonsterFlag10(pUnit))
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClass);
        if (!pMonStatsTxtRecord)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);
        if (pMonStatsTxtRecord->wUMonSound > 0)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(pMonStatsTxtRecord->wUMonSound);
    }

    return DATATBLS_GetMonSoundsTxtRecordFromMonsterId(nClass);
}

// 0x004CB170
static __forceinline unsigned int sub_004CB170_GetNeutralSound(D2UnitStrc* pUnit)
{
    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return 0;
    return pMonSoundsTxtRecord->dwNeutral;
}

// 0x004CB180
static __forceinline unsigned int sub_004CB180_GetTauntSound(D2UnitStrc* pUnit)
{
    D2MonSoundsTxt* pMonSoundsTxtRecord = sub_004CA410_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return 0;
    return pMonSoundsTxtRecord->dwTaunt;
}

unsigned int __fastcall sub_M110_Emit_004CB170(D2UnitStrc* pUnit, int bTaunt)
{
    if (bTaunt)
        return sub_004CB180_GetTauntSound(pUnit);
    return sub_004CB170_GetNeutralSound(pUnit) + 1;
}
