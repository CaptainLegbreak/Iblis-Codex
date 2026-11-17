#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0x70];
    int nGameType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2NpcHirelingStrc
{
    unsigned short wName;
    unsigned short unk0x02;
    int nHirelingId;
    int bHired;
    int bPresent;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2NpcHirelingStrc* pHirelings;
    char unk0x14[0x0D];
    unsigned char bHirelingsInit;
};

struct D2HirelingTxt
{
    char unk0x000[0x08];
    int dwClass;
    char unk0x00C[0x108];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

#pragma pack(push, 1)
struct D2GSPacketSrv4E
{
    unsigned char nHeader;
    unsigned short wName;
    int nHirelingId;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
void __fastcall sub_00576070(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00576070
D2HirelingTxt* __stdcall sub_006564D0_GetHirelingTxtRecord(int nGameType, int nId, int nDifficulty, int a4); // 0x006564D0
void __fastcall D2GAME_SendPacket0x4E_6FC3F410(D2ClientStrc* pClient, D2GSPacketSrv4E* pPacket);           // 0x0053D7B0

static __forceinline int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = sub_006564D0_GetHirelingTxtRecord(pGame->nGameType, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    D2_ASSERT((*pNameLast - *pNameFirst + 1) != -1, 96);
    return (*pNameLast - *pNameFirst + 1);
}

// 0x00576770
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo)
{
    if (!pNpc)
    {
        return;
    }

    if (pNpc->dwClassId != 150 && pNpc->dwClassId != 198 && pNpc->dwClassId != 515 && pNpc->dwClassId != 252)
    {
        return;
    }

    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0x4F);

    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(CLIENTS_GetGame(pClient), pNpc, &nIndex);
    if (!pNpcRecord)
    {
        return;
    }

    const int nNpcClassId = pNpc->dwClassId;
    if (!pNpcRecord->bHirelingsInit)
    {
        sub_00576070(CLIENTS_GetGame(pClient), nNpcClassId, pNpcRecord);
    }

    D2NpcHirelingStrc* pHirelings = pNpcRecord->pHirelings;
    int nNameFirst;
    int nNameLast;
    const int nCount = sub_00575FF0(pGame, nNpcClassId, &nNameFirst, &nNameLast, 0);
    D2_ASSERT(nCount != -1, 0x1FB);

    for (int i = 0; i < nCount; ++i)
    {
        if (pHirelings[i].bPresent && !pHirelings[i].bHired)
        {
            D2GSPacketSrv4E packet;
            packet.nHeader = 0x4E;
            packet.wName = pHirelings[i].wName;
            packet.nHirelingId = pHirelings[i].nHirelingId;
            D2GAME_SendPacket0x4E_6FC3F410(pClient, &packet);
        }
    }
}
