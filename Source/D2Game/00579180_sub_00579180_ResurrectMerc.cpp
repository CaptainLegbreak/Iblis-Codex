struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short unk0x02;
    int dwSeed;
    int bHired;
    int bDead;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2MercDataStrc* pMercData;
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
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nType;
    unsigned short nMercName;
    unsigned char unk0x05[0x0B];
};
#pragma pack(pop)

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
void __fastcall sub_00577010_VendorRefresh(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord);  // 0x00577010
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x006564D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket);            // 0x0053D7E0
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nId, D2MercDataStrc* pMercData, int bDead); // 0x00573270

// 0x00579180
void __fastcall sub_00579180_ResurrectMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nVendorId)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, nVendorId, &nIndex);
    if (!pNpcRecord)
    {
        return;
    }

    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    if (!pMercData)
    {
        return;
    }

    if (pGame->bExpansion)
    {
        if (sub_6FC7E8B0(pGame, pPlayer, 7, 1))
        {
            sub_00577010_VendorRefresh(pGame, nVendorId, pNpcRecord);
            return;
        }
    }

    if (!pGame->bExpansion)
    {
        if (sub_6FC7E8B0(pGame, pPlayer, 7, 0))
        {
            return;
        }
    }

    D2HirelingTxt* pHirelingTxt = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->bExpansion, nVendorId, pGame->nDifficulty, 0);
    if (!pHirelingTxt)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFA2);
        exit(-1);
    }

    const int nNameLast = pHirelingTxt->wNameLast;
    const int nNameFirst = pHirelingTxt->wNameFirst;
    const int nClass = pHirelingTxt->dwClass;
    const int nCount = nNameLast - nNameFirst + 1;
    int nName = nNameFirst;
    while (nName <= nNameLast)
    {
        const int nIdx = nName - nNameFirst;
        if (nIdx >= nCount)
        {
            break;
        }

        if (pMercData[nIdx].bHired == 1)
        {
            ++nName;
            continue;
        }

        if (pMercData[nIdx].bDead == 1)
        {
            D2GSPacketSrv50 packet50;
            packet50.nHeader = 0x50;
            packet50.nType = 2;
            packet50.nMercName = pMercData[nIdx].nMercName;
            pMercData[nIdx].bHired = 1;
            D2GAME_SendPacket0x50_6FC3F440(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0xFC7), &packet50);

            D2UnitStrc* pUnit = sub_6FC68D70(pGame, pPlayer, nClass, 1, 4, 0);
            if (!pUnit)
            {
                pUnit = sub_6FC68D70(pGame, pPlayer, nClass, 1, 6, 0);
                if (!pUnit)
                {
                    pUnit = sub_6FC68D70(pGame, pPlayer, nClass, 1, 0x0C, 0);
                    if (!pUnit)
                    {
                        return;
                    }
                }
            }

            MONSTERAI_AssignHireling(pGame, pPlayer, pUnit, -1, &pMercData[nIdx], 0);
            break;
        }

        ++nName;
    }

    sub_00577010_VendorRefresh(pGame, nVendorId, pNpcRecord);
}
