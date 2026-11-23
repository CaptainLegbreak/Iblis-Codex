#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Drlg.h"

#include "D2UnitData.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MonsterDataStrc;

void __fastcall MONSTER_RemoveAll(D2GameStrc* pGame); // 0x00573640
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame); // 0x00552A40
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame); // 0x00534A50
void __fastcall ITEMS_RemoveAll(D2GameStrc* pGame); // 0x00557F10
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame); // 0x0059F840
void __fastcall SUNIT_RemoveAllTiles(D2GameStrc* pGame); // 0x00555770
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

// 0x0053B090
int __fastcall sub_0053B090_CountActRooms(D2GameStrc* pGame, unsigned char nAct)
{
    D2_ASSERT(nAct < 5, 0x294);
    D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]);
    int nCount = 0;
    while (pRoom)
    {
        pRoom = pRoom->pRoomNext;
        ++nCount;
    }
    return nCount;
}

// 0x0053B140
void __fastcall sub_0053B140_WriteVarLength16(D2BitBufferStrc* pBuffer, unsigned short nValue)
{
    if (nValue < 0x100)
    {
        BITMANIP_Write(pBuffer, 0, 1);
        BITMANIP_Write(pBuffer, nValue, 8);
    }
    else
    {
        BITMANIP_Write(pBuffer, 1, 1);
        BITMANIP_Write(pBuffer, nValue, 16);
    }
}

// 0x0053B180
int* __fastcall sub_0053B180_GetMonsterDataField3C(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return 0;
    }
    return &pMonsterData->nOwnerGUID;
}

// 0x0053B1A0
static inline void sub_0053B1A0_SendToClient(int nClientId, void* pPacket, int nSize)
{
    sub_0052B330(0, nClientId, pPacket, nSize);
}

void __stdcall sub_M121_Emit_0053B1A0(int nClientId, void* pPacket, int nSize) { sub_0053B1A0_SendToClient(nClientId, pPacket, nSize); }

// 0x0053B0E0
void __fastcall sub_0053B0E0_WriteVarLength(D2BitBufferStrc* pBuffer, unsigned int nValue)
{
    if (nValue < 0x100)
    {
        BITMANIP_Write(pBuffer, 0, 1);
        BITMANIP_Write(pBuffer, nValue, 8);
    }
    else
    {
        BITMANIP_Write(pBuffer, 1, 1);
        if (nValue < 0x10000)
        {
            BITMANIP_Write(pBuffer, 0, 1);
            BITMANIP_Write(pBuffer, nValue, 16);
        }
        else
        {
            BITMANIP_Write(pBuffer, 1, 1);
            BITMANIP_Write(pBuffer, nValue, 32);
        }
    }
}

// 0x0053B210
int __fastcall PLRMODE_ModeCheck_Death(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

int __fastcall PLRMODE_ModeCheck_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

int __fastcall PLRMODE_ModeCheck_GetHit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}
