struct D2GameStrc;
struct D2UnitStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xBA8];
    int nHighestClassSkillCount;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnGlobal_007310CC;                                                                               // 0x007310CC
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile);                   // 0x005AE1F0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __stdcall sub_0062E880(D2UnitStrc* pItem);                                                              // 0x0062E880

// 0x005B0BC0
int __fastcall MISSMODE_SrvDo01_BasicMissile(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x00530F30
void __fastcall sub_00530F30_SetGlobal(int nValue)
{
    gnGlobal_007310CC = nValue;
}

// 0x00568D70
int __cdecl sub_00568D70_GetHighestClassSkillCount()
{
    return sgptDataTables->nHighestClassSkillCount;
}

// 0x005DE320
void __fastcall sub_005DE320_AttachSoundNoOrigin(D2UnitStrc* pUnit, int nUpdateType)
{
    SUNIT_AttachSound(pUnit, nUpdateType, 0);
}

// 0x00576320
static __forceinline int sub_00576320_CheckItem(D2UnitStrc* pItem)
{
    return sub_0062E880(pItem);
}

int __stdcall sub_M114_Emit_00576320(D2UnitStrc* pItem)
{
    return sub_00576320_CheckItem(pItem) + 1;
}

// 0x005875D0
void __fastcall sub_005875D0_SetQuestStateIfIntroDone(D2QuestDataStrc* pQuest)
{
    if (!pQuest->fState && pQuest->bNotIntro)
    {
        pQuest->fState = 1;
    }
}

#include "gen/data/Source/D2Game/005B0BC0_MISSMODE_SrvDo01_BasicMissile.inc"
