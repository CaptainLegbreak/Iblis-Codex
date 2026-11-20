#include "D2Game.h"
#include "D2Structs.h"


struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2HirelingTxt
{
    char unk0x000[0x08];
    int dwClass;
    char unk0x00C[0x08];
    int dwSeller;
    char unk0x018[0xFC];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

struct D2MercDataRecordStrc
{
    int unk0x00;
    int unk0x04;
    int bHired;
    int bAvailable;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2MercDataRecordStrc* pMercData;
};

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short unk0x02;
    int dwSeed;
    int unk0x08[2];
};

extern "C" const char gszSUnitNpcFile_006E15F0[];                                                          // 0x006E15F0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nId, D2MercDataStrc* pMercData, int bDead); // 0x00573270
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x00656580
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, unsigned short nNameId);        // 0x00663750

// 0x005774F0
D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short wName, int nSeed, unsigned short wVersion, int nBaseMonster, int bDead)
{
    const int nMercAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, wName);
    int nAct = pPlayer->nAct;
    if (SUNIT_GetClientFromPlayer(pPlayer, gszSUnitNpcFile_006E15F0, 0x735))
    {
        nAct = CLIENTS_GetActNo(SUNIT_GetClientFromPlayer(pPlayer, gszSUnitNpcFile_006E15F0, 0x737));
    }

    if (!pGame->bExpansion && (nMercAct < 0 || nAct != nMercAct))
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord;
    if (wVersion != 0xFFFF)
    {
        pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, wVersion, 1);
    }
    else
    {
        pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(pGame->bExpansion, nMercAct, pGame->nDifficulty, 0);
    }

    if (!pHirelingTxtRecord)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x744);
        exit(-1);
    }

    const unsigned short wNameFirst = pHirelingTxtRecord->wNameFirst;
    const int nSeller = pHirelingTxtRecord->dwSeller;
    const int nNameFirst = wNameFirst;
    int nClassId = nBaseMonster;
    if (!nBaseMonster)
    {
        nClassId = pHirelingTxtRecord->dwClass;
    }

    if (wName < wNameFirst || wName > pHirelingTxtRecord->wNameLast)
    {
        wName = wNameFirst;
    }

    int nUnused;
    D2MercDataRecordStrc* pMercData = SUNITPROXY_GetNpcRecordFromClassId(pGame, nSeller, &nUnused)->pMercData;
    if (pMercData)
    {
        pMercData += wName - nNameFirst;
        if (!pMercData->bAvailable)
        {
            pMercData->bHired = 1;
        }
    }

    D2UnitStrc* pMerc = SUNIT_AllocUnitData(1, nClassId, 0, 0, pGame, 0, 1, bDead ? 12 : 1, 0);
    if (!pMerc)
    {
        return 0;
    }

    D2MercDataStrc mercData;
    mercData.dwSeed = nSeed;
    mercData.nMercName = wName;
    MONSTERAI_AssignHireling(pGame, pPlayer, pMerc, wVersion, &mercData, bDead);
    return pMerc;
}
