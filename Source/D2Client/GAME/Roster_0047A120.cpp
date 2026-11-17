#include "D2Client.h"

struct D2RosterInfoStrc;

struct D2RosterCorpseStrc
{
    int dwCorpseId;
    D2RosterCorpseStrc* pNext;
};

struct D2StoredUnitRecordStrc
{
    char szName[16];
    int dwUnitId;
    int dwPartyLife;
    int dwKillCount;
    int dwClassId;
    unsigned short wLevel;
    unsigned short wPartyId;
    int dwLevelId;
    int dwPosX;
    int dwPosY;
    int dwPartyFlags;
    D2RosterInfoStrc** pRosterInfo;
    D2RosterCorpseStrc* pCorpse;
    int dwPortalA;
    int dwPortalB;
    unsigned short wGuildFlags;
    char szGuildTag[4];
    char szGuildName[28];
    char szNameEx[26];
    D2StoredUnitRecordStrc* pNext;
};

struct Unicode
{
    unsigned short wChar;

    int isWhitespace() const;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __cdecl sub_00479AB0();                                                                                // 0x00479AB0
void __cdecl sub_0049A640();                                                                                // 0x0049A640
void __fastcall sub_004DC2B0_FreeRosterInfoList(D2RosterInfoStrc** pList);                                  // 0x004DC2B0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
unsigned short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit);                           // 0x00465400

extern D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0;                                                      // 0x007BB5C0

// 0x0047A120
int __fastcall sub_0047A120_IsInPlayerParty(D2StoredUnitRecordStrc* pRecord)
{
    if (pRecord && pRecord->wPartyId != 0xFFFF && sub_00465400_GetPlayerRosterField22(sub_00463DD0()) == pRecord->wPartyId)
    {
        return 1;
    }
    return 0;
}

// 0x0047A8B0
void __fastcall sub_0047A8B0_RemoveRosterUnit(int nUnitId)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0;
    D2_ASSERT(nUnitId != -1, 0x121);
    for (; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
        {
            if (pPrev)
            {
                pPrev->pNext = pRec->pNext;
            }
            else
            {
                gpStoredUnits_007BB5C0 = pRec->pNext;
            }
            sub_004DC2B0_FreeRosterInfoList(pRec->pRosterInfo);
            pRec->pRosterInfo = 0;
            D2RosterCorpseStrc* pCorpse = pRec->pCorpse;
            while (pCorpse)
            {
                D2RosterCorpseStrc* pNext = pCorpse->pNext;
                FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x110, 0);
                pCorpse = pNext;
            }
            pRec->pCorpse = 0;
            FOG_Free(pRec, ".\\GAME\\Roster.cpp", 0x131, 0);
            break;
        }
        pPrev = pRec;
    }
    sub_00479AB0();
    sub_0049A640();
}

// 0x0047A9B0
void __fastcall sub_0047A9B0_SetClientFlag1(int bClear)
{
    if (bClear)
    {
        gdwGlobal_00712EFC &= ~1;
    }
    else
    {
        gdwGlobal_00712EFC |= 1;
    }
}

// 0x0047A9E0
int __cdecl sub_0047A9E0_GetClientFlag40()
{
    return gdwGlobal_00712EFC & 0x40;
}

// 0x0047A9F0
int __cdecl sub_0047A9F0_GetClientFlag80()
{
    return gdwGlobal_00712EFC & 0x80;
}

// 0x0047AA00
int __cdecl sub_0047AA00_GetClientFlag200()
{
    return gdwGlobal_00712EFC & 0x200;
}

// 0x0047AA10
void __fastcall sub_0047AA10_SetGlobal(int nValue)
{
    gdwGlobal_00712F00 = nValue;
}

// 0x0047AA40
int Unicode::isWhitespace() const
{
    if (this->wChar < 0x100)
    {
        return ::isspace(this->wChar);
    }
    return 0;
}

#include "gen/data/Source/D2Client/GAME/Roster_0047A120.inc"
