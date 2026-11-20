// Shared layouts of the game's core structures (names after D2MOO, MIT; see NOTICE-D2MOO).
// Offsets are 1.14d's. A field the game uses in more than one way is a union; unknown bytes are unk0xNN.
#pragma once

struct D2ActiveRoomStrc;
struct D2AnimDataRecordStrc;
struct D2AnimSeqTxt;
struct D2CltUnitEventStrc;
struct D2CombatStrc;
struct D2DrlgActStrc;
struct D2DynamicPathStrc;
struct D2EventTimerStrc;
struct D2GameStrc;
struct D2GfxDataStrc;
struct D2GfxLightStrc;
struct D2HoverTextStrc;
struct D2InventoryStrc;
struct D2ItemDataStrc;
struct D2MissileDataStrc;
struct D2MonsterDataStrc;
struct D2ObjectDataStrc;
struct D2PacketListStrc;
struct D2PlayerDataStrc;
struct D2QuestChainStrc;
struct D2SkillListStrc;
struct D2StaticPathStrc;
struct D2StatListExStrc;
struct D2UnitEventStrc;
struct D2UnitPacketListStrc;
struct D2UnitStrc;

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed; // 0x00
            unsigned int nHighSeed; // 0x04
        };
        unsigned __int64 lSeed; // 0x00
    };
};

struct D2StatStrc
{
    union
    {
        struct
        {
            unsigned short nLayer; // 0x00
            unsigned short nStat; // 0x02
        };
        int nPackedValue; // 0x00
    };
    int nValue; // 0x04
};

struct D2StatsArrayStrc
{
    D2StatStrc* pStat; // 0x00
    short nStatCount; // 0x04
    short nCapacity; // 0x06
};

struct D2ModStatsArrayStrc
{
    int* pStat; // 0x00
    short nStatCount; // 0x04
    short nCapacity; // 0x06
};

struct D2StatListStrc
{
    void* pMemPool; // 0x00
    D2UnitStrc* pUnit; // 0x04
    int dwOwnerType; // 0x08
    int dwOwnerId; // 0x0C
    unsigned int dwFlags; // 0x10
    unsigned int dwStateNo; // 0x14
    int dwExpireFrame; // 0x18
    int dwSkillNo; // 0x1C
    int dwSLvl; // 0x20
    D2StatsArrayStrc Stats; // 0x24
    D2StatListStrc* pPrevLink; // 0x2C
    D2StatListStrc* pNextLink; // 0x30
    D2StatListStrc* pParent; // 0x34
    void* fpStatRemove; // 0x38
};

struct D2StatListExStrc : public D2StatListStrc
{
    D2StatListStrc* pMyLastList; // 0x3C
    D2StatListStrc* pMyStats; // 0x40
    D2UnitStrc* pOwner; // 0x44
    D2StatsArrayStrc FullStats; // 0x48
    D2ModStatsArrayStrc ModStats; // 0x50
    unsigned int* StatFlags; // 0x58
    void* pfOnValueChanged; // 0x5C
    D2GameStrc* pGame; // 0x60
};

struct D2UnitStrc
{
    int dwUnitType; // 0x00
    int dwClassId; // 0x04
    void* pMemoryPool; // 0x08
    int dwUnitId; // 0x0C
    union // 0x10
    {
        int dwAnimMode;
        int dwItemMode;
        int dwMissileMode;
    };
    union // 0x14
    {
        D2PlayerDataStrc* pPlayerData;
        D2ItemDataStrc* pItemData;
        D2MonsterDataStrc* pMonsterData;
        D2ObjectDataStrc* pObjectData;
        D2MissileDataStrc* pMissileData;
    };
    unsigned char nAct; // 0x18
    unsigned char unk0x19[0x3];
    D2DrlgActStrc* pDrlgAct; // 0x1C
    D2SeedStrc pSeed; // 0x20
    unsigned int dwInitSeed; // 0x28
    union // 0x2C
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    D2AnimSeqTxt* pAnimSeq; // 0x30
    int dwSeqFrameCount; // 0x34
    int dwSeqFrame; // 0x38
    unsigned int dwSeqSpeed; // 0x3C
    int dwSeqMode; // 0x40
    int nSeqCurrentFramePrecise; // 0x44
    int dwFrameCountPrecise; // 0x48
    short wAnimSpeed; // 0x4C
    unsigned char nActionFrame; // 0x4E
    unsigned char unk0x4F; // 0x4F
    D2AnimDataRecordStrc* pAnimData; // 0x50
    D2GfxDataStrc* pGfxData; // 0x54
    D2GfxDataStrc* pGfxDataCopy; // 0x58
    D2StatListExStrc* pStatListEx; // 0x5C
    D2InventoryStrc* pInventory; // 0x60
    union // 0x64
    {
        struct // server unit
        {
            int dwInteractGUID; // 0x64
            int dwInteractType; // 0x68
            unsigned char nInteract; // 0x6C
            unsigned char unk0x6D; // 0x6D
            unsigned short nUpdateType; // 0x6E
            D2UnitStrc* pUpdateUnit; // 0x70
            D2QuestChainStrc* pQuestEventList; // 0x74
            int bSparkChest; // 0x78
            void* pTimerArg; // 0x7C
            D2GameStrc* pGame; // 0x80
            unsigned char unk0x84[0xC];
            D2UnitEventStrc* pSrvUnitEventsList; // 0x90
        };
        struct // client unit
        {
            D2GfxLightStrc* pLight; // 0x64
            int dwStartLight; // 0x68
            int nPaletteIndex; // 0x6C
            int bUnitSfx; // 0x70
            int dwSfxMode; // 0x74
            void* pUnitSfxData; // 0x78
            unsigned int dwSfxTicks; // 0x7C
            unsigned int dwSfxAsyncTicks; // 0x80
            unsigned int dwSfxStepTicks; // 0x84
            int bHasActiveSound; // 0x88
            unsigned short nLastClickX; // 0x8C
            unsigned short nLastClickY; // 0x8E
            D2CltUnitEventStrc* pCltTimerList; // 0x90
        };
    };
    int dwOwnerType; // 0x94
    int dwOwnerGUID; // 0x98
    int dwKillerType; // 0x9C
    int dwKillerGUID; // 0xA0
    D2HoverTextStrc* pHoverText; // 0xA4
    D2SkillListStrc* pSkills; // 0xA8
    D2CombatStrc* pCombat; // 0xAC
    int dwLastHitClass; // 0xB0
    unsigned char unk0xB4[0x4];
    unsigned int dwDropItemCode; // 0xB8
    unsigned char unk0xBC[0x8];
    unsigned int dwFlags; // 0xC4
    unsigned int dwFlagEx; // 0xC8
    void* pUnused0xCC; // 0xCC
    int dwNodeIndex; // 0xD0
    unsigned int dwTickCount; // 0xD4
    union // 0xD8
    {
        unsigned int dwSrvTickCount;
        D2PacketListStrc* pPacketList;
    };
    D2EventTimerStrc* pTimer; // 0xDC
    D2UnitStrc* pChangeNextUnit; // 0xE0
    D2UnitStrc* pListNext; // 0xE4
    D2UnitStrc* pRoomNext; // 0xE8
    D2UnitPacketListStrc* pMsgFirst; // 0xEC
    D2UnitPacketListStrc* pMsgLast; // 0xF0
};
