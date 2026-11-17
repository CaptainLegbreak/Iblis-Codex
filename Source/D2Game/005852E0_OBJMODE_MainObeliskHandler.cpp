extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int(__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C

struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x9E];
    unsigned char nSubType;
};

struct D2ObjectsTxt
{
    char unk0x00[0xDC];
    unsigned int dwFrameCnt1;
};

#pragma pack(push, 1)
struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nAction;
    unsigned char nResult;
};
#pragma pack(pop)

typedef int(__fastcall* ObeliskPowerUpFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue);

struct D2ObeliskPowerUpStrc
{
    ObeliskPowerUpFunction pPowerUpCallback;
    unsigned int nChance;
    int nValue;
};

extern D2ObeliskPowerUpStrc gaObeliskPowerUps_00732EB0[21];                                                 // 0x00732EB0
extern int gnObeliskPowerUps_00732FAC;                                                                      // 0x00732FAC
extern "C" const char gszObjModeSourceFile[];                                                               // 0x006E1970

void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket);               // 0x0053D8D0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __fastcall ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pObject); // 0x0059DD80
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
static int __stdcall sub_00585240_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer); // 0x00585240

// 0x00585240
static __declspec(noinline) int __stdcall sub_00585240_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer)
{
    if (nSubType < gnObeliskPowerUps_00732FAC)
    {
        const unsigned __int64 lSeed = pPlayer->pSeed.nHighSeed + 0x6AC690C5i64 * pPlayer->pSeed.nLowSeed;
        pPlayer->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pPlayer->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((unsigned int)lSeed % 100 < gaObeliskPowerUps_00732EB0[nSubType].nChance)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback), 4341);
            return gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback(pGame, pPlayer, gaObeliskPowerUps_00732EB0[nSubType].nValue);
        }
    }

    return 0;
}

// 0x005852E0
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, unsigned short nState)
{
    D2GSPacketSrv58 packet58;
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, nPlayerGUID);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (pPlayer)
    {
        if (!pObject)
        {
            return 1;
        }

        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszObjModeSourceFile, 0x1135);
        packet58.nHeader = 0x58;
        packet58.nUnitId = nObjectGUID;
        const int nAnimMode = pObject->dwAnimMode;
        switch (nState)
        {
        case 2:

            if (nAnimMode == 3)
            {
                packet58.nAction = 1;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                UNITS_ChangeAnimMode(pObject, 0);
                SUNIT_ResetInteractInfo(pPlayer);
            }
            else
            {
                packet58.nAction = 1;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                UNITS_ChangeAnimMode(pObject, 0);
                SUNIT_ResetInteractInfo(pPlayer);
            }
            break;

        case 3:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            if ((!pObject ? -1 : pObject->dwClassId) == 0x98)
            {
                if (pItemsTxtRecord->dwCode != 0x20747368)
                {
                    packet58.nAction = 4;
                    sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                    return 1;
                }
            }
            else if (!D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem))
            {
                packet58.nAction = 4;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                return 1;
            }

            packet58.nAction = 5;
            SUNIT_ResetInteractInfo(pPlayer);
            if (pObject->dwClassId == 0x98)
            {
                packet58.nResult = 1;
            }
            else
            {
                packet58.nResult = sub_00585240_ApplyObeliskPowerUp(pGame, pItemsTxtRecord->nSubType, pPlayer);
            }

            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            if (packet58.nResult == 1)
            {
                UNITS_ChangeAnimMode(pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
                if (pObject->dwClassId == 0x98)
                {
                    UNITS_ChangeAnimMode(pObject, 2);
                    ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(pGame, pPlayer, pObject);
                    break;
                }

                EVENT_SetEvent(pGame, pObject, 1, pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt1 >> 8) + 1, 0, 0);
                break;
            }

            UNITS_ChangeAnimMode(pObject, 0);
            break;
        }
        }

        return 1;
    }

    D2_ASSERT(pObject, 0x1109);
    return 1;
}
