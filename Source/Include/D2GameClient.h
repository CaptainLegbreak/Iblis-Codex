#pragma once
// D2Game: a connected client and the unit update slots it sends.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Primitives.h"
#include "D2HotkeySkill.h"

struct D2ActiveRoomStrc;
struct D2ClientInfoStrc;
struct D2GameStrc;
struct D2PacketDataStrc;
struct D2SaveHeaderStrc;
struct D2UnitStrc;
struct D2ClientUnitUpdateStrc;
struct D2ClientStrc;

struct D2ClientUnitUpdateStrc
{
    unsigned char nUnitType; // 0x00
    unsigned char nUnitGUID[4]; // 0x01
    unsigned char nX[2]; // 0x05
    unsigned char nY[2]; // 0x07
};

struct D2ClientStrc
{
    int dwClientId; // 0x00
    int dwClientState; // 0x04
    unsigned char nClassId; // 0x08
    char unk0x09; // 0x09
    unsigned short nSaveFlags; // 0x0A
    unsigned char nCharTemplate; // 0x0C
    char szName[16]; // 0x0D
    char szAccount[16]; // 0x1D
    char unk0x2D; // 0x2D
    char unk0x2E; // 0x2E
    char unk0x2F; // 0x2F
    int unk0x30[12]; // 0x30
    int nCharSaveTransactionToken; // 0x60
    int unk0x64; // 0x64
    D2ClientInfoStrc* pClientInfo; // 0x68
    int unk0x6C[7]; // 0x6C
    int nValue_088; // 0x88
    int nValue_08C; // 0x8C
    int unk0x90[55]; // 0x90
    int dwUnitType; // 0x16C
    int dwUnitGUID; // 0x170
    D2UnitStrc* pPlayer; // 0x174
    int bUnlockCharacter; // 0x178
    D2SaveHeaderStrc* pSaveHeader; // 0x17C
    int nSaveHeaderSize; // 0x180
    unsigned int nSaveHeaderSendDelay; // 0x184
    unsigned int nSaveHeaderDataSentBytes; // 0x188
    unsigned int nSaveChecksum; // 0x18C
    D2FileTimeStrc nSaveCreationTimestamp; // 0x190
    int nDeadTargetType; // 0x198
    int nDeadTargetGUID; // 0x19C
    int unk0x1A0[2]; // 0x1A0
    D2GameStrc* pGame; // 0x1A8
    unsigned char bAct; // 0x1AC
    unsigned char nByte1AD; // 0x1AD
    unsigned short unk0x1AE; // 0x1AE
    int nPlayerSyncCount; // 0x1B0
    D2ActiveRoomStrc* hRoom; // 0x1B4
    D2PacketDataStrc* pPacketDataHead; // 0x1B8
    D2PacketDataStrc* pPacketDataTail; // 0x1BC
    D2PacketDataStrc* pPacketDataPool; // 0x1C0
    int nSaveHeaderSendFailures; // 0x1C4
    int unk0x1C8; // 0x1C8
    D2ClientUnitUpdateStrc unitUpdate[55]; // 0x1CC
    char unk0x3BB; // 0x3BB
    unsigned int nUnitUpdateIndex; // 0x3BC
    int unk0x3C0[5]; // 0x3C0
    union
    {
        unsigned int dwFlags; // 0x3D4
        struct
        {
            unsigned char bFlagsLow : 5; // 0x3D4
            unsigned char bGameOwner : 1; // 0x3D4
        };
    };
    unsigned int dwLastPacketTick; // 0x3D8
    D2HotkeySkillStrc HotkeySkills[16]; // 0x3DC
    unsigned short unk0x45C; // 0x45C
    unsigned short nGuildFlags; // 0x45E
    unsigned int unk0x460; // 0x460
    int unk0x464[7]; // 0x464
    unsigned char nGuildBgColor; // 0x480
    unsigned char nGuildFgColor; // 0x481
    unsigned char unk0x482; // 0x482
    unsigned char unk0x483; // 0x483
    int nIronGolemItemGUID; // 0x484
    unsigned int nCreateTime; // 0x488
    char clientPlayerData[28]; // 0x48C
    D2ClientStrc* pNext; // 0x4A8
    D2ClientStrc* pServerNext; // 0x4AC
    D2ClientStrc* pServerNextByName; // 0x4B0
    int unk0x4B4[19]; // 0x4B4
    unsigned int dwPingsCount; // 0x500
    int dw504; // 0x504
    int nExpLoss; // 0x508
    unsigned int dwLocale; // 0x50C
    int unk0x510[2]; // 0x510
};

D2_CHECK_SIZE(D2ClientUnitUpdateStrc, 0x9);
D2_CHECK_SIZE(D2ClientStrc, 0x518);
