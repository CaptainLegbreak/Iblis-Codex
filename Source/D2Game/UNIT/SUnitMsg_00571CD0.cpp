#include "D2Game.h"

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    unsigned char unk0x05[3];
    union
    {
        struct
        {
            unsigned int dwParam;
            unsigned short wParam;
            unsigned char nParam;
        } p23;
        struct
        {
            unsigned short wSkill;
            unsigned char nSkillLevel;
            unsigned char nUnitType;
            unsigned int dwUnitGUID;
            unsigned char nParam;
        } p99;
        struct
        {
            unsigned short wSkill;
            unsigned char nSkillLevel;
            unsigned char unk0x0B;
            unsigned short wX;
            unsigned short wY;
            unsigned char nParam;
        } p9A;
        struct
        {
            unsigned int unk0x08;
            unsigned char nStatId;
            unsigned char unk0x0D[3];
            unsigned int dwValue;
            unsigned int dwFullValue;
        } pStat;
        struct
        {
            unsigned char a2;
            unsigned char unk0x09;
            unsigned short a3;
            unsigned short a4;
            unsigned short unk0x0E;
            unsigned int a5;
            unsigned int a6;
            unsigned int a7;
            unsigned int a8;
            unsigned int a9;
            unsigned int a10;
        } pA3;
        struct
        {
            short a2;
        } pA4;
        struct
        {
            unsigned char a2;
            unsigned char unk0x09[3];
            unsigned int a3;
            unsigned short a4;
        } pA5;
        struct
        {
            unsigned char nUnitType;
            unsigned char unk0x09[3];
            unsigned int dwUnitId;
            unsigned char nUnitLife;
        } pAB;
    };
};

struct D2UnitStrc
{
    char unk0x00[0xEC];
    D2UnitPacketListStrc* pMsgFirst;
};

#define UNITFLAG_UPGRLIFENHITCLASS 0x00008000

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                  // 0x00537860
void __fastcall D2GAME_PACKETS_SendPacket0x9E_9F_A0_6FC3D520(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nStatId, unsigned int nValue); // 0x0053BEE0
void __fastcall D2GAME_PACKETS_SendPacket0xA3_6FC3D730(D2ClientStrc* pClient, unsigned char a2, unsigned short a3, unsigned short a4, int a5, int a6, int a7, int a8, int a9, int a10); // 0x0053C0E0
void __fastcall D2GAME_PACKETS_SendPacket0xAB_6FC3D7B0(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife); // 0x0053C150
void __fastcall D2GAME_PACKETS_SendPacket0xA5_6FC3D7F0(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4); // 0x0053C190
void __fastcall D2GAME_PACKETS_SendPacket0x23_6FC3DC60(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char a4, unsigned short a5, int a6); // 0x0053C590
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall sub_0053D530(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned char nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D530
void __fastcall D2GAME_PACKETS_SendPacket0xA4_6FC3FC00(D2ClientStrc* pClient, short a2);                    // 0x0053E1A0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200

// 0x00571CD0
void __fastcall sub_6FCC6540(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    for (D2UnitPacketListStrc* pMsg = pUnit->pMsgFirst; pMsg; pMsg = pMsg->pNext)
    {
        switch (pMsg->nHeader)
        {
        case 0x99:
            sub_0053D530(pClient, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit), pMsg->p99.nUnitType, pMsg->p99.dwUnitGUID, pMsg->p99.wSkill, pMsg->p99.nParam, pMsg->p99.nSkillLevel, 1);
            break;

        case 0x9A:
            sub_6FC3F060(pClient, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit), pMsg->p9A.wX, pMsg->p9A.wY, pMsg->p9A.wSkill, pMsg->p9A.nParam, pMsg->p9A.nSkillLevel, 1);
            break;

        case 0x9E:
            D2GAME_PACKETS_SendPacket0x9E_9F_A0_6FC3D520(pClient, pUnit, pMsg->pStat.nStatId, pMsg->pStat.dwValue);
            break;

        case 0xA1:
            D2GAME_PACKETS_SendPacket0xA0_A1_A2_6FC3D610(pClient, pUnit, pMsg->pStat.nStatId, pMsg->pStat.dwValue, pMsg->pStat.dwFullValue);
            break;

        case 0xA4:
            D2GAME_PACKETS_SendPacket0xA4_6FC3FC00(pClient, pMsg->pA4.a2);
            break;

        case 0xA3:
            D2GAME_PACKETS_SendPacket0xA3_6FC3D730(pClient, pMsg->pA3.a2, pMsg->pA3.a3, pMsg->pA3.a4, pMsg->pA3.a5, pMsg->pA3.a6, pMsg->pA3.a7, pMsg->pA3.a8, pMsg->pA3.a9, pMsg->pA3.a10);
            break;

        case 0xAB:
            if (!sub_00451F30_TestUnitFlag(pUnit, UNITFLAG_UPGRLIFENHITCLASS))
            {
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer && sub_00554200(SUNIT_GetGameFromUnit(pPlayer), pPlayer, pUnit))
                {
                    D2GAME_PACKETS_SendPacket0xAB_6FC3D7B0(pClient, pMsg->pAB.nUnitType, pMsg->pAB.dwUnitId, pMsg->pAB.nUnitLife);
                }
            }
            break;

        case 0xA5:
            D2GAME_PACKETS_SendPacket0xA5_6FC3D7F0(pClient, pMsg->pA5.a2, pMsg->pA5.a3, pMsg->pA5.a4);
            break;

        case 0x23:
            D2GAME_PACKETS_SendPacket0x23_6FC3DC60(pClient, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit), pMsg->p23.nParam, pMsg->p23.wParam, pMsg->p23.dwParam);
            break;

        default:
            break;
        }
    }
}
