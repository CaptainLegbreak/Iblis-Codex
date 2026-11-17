struct D2DrlgActStrc;
struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00581250
void __fastcall sub_00581250_ObjectTimer_Light(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    if (pObject && pObject->dwClassId == 0x18F)
    {
        switch ((unsigned short)nMode)
        {
        case 0:
        case 2:
        {
            D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + (unsigned int)SEED_RollRandomNumber(&pObjectControl->pSeed) % 250 + 25, 0, 0);
            UNITS_ChangeAnimMode(pObject, 1);
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
            EVENT_SetEvent(pGame, pObject, 1, (pObjectsTxt->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            break;
        }
        }
        return;
    }

    switch (ENVIRONMENT_GetPeriodOfDayFromAct(pGame->pAct, 0))
    {
    case 0:
        if ((unsigned short)nMode == 2 || (unsigned short)nMode == 1)
        {
            UNITS_ChangeAnimMode(pObject, 0);
        }
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 1000, 0, 0);
        return;

    case 1:
    case 2:
    case 3:
        if (!(unsigned short)nMode)
        {
            UNITS_ChangeAnimMode(pObject, 1);
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
            EVENT_SetEvent(pGame, pObject, 1, (pObjectsTxt->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
        }
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 1000, 0, 0);
        return;

    default:
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 600, 0, 0);
        return;
    }
}
