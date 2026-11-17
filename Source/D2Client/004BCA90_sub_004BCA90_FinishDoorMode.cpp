struct D2GfxLightStrc;
struct D2ActiveRoomStrc;
struct D2DrlgActStrc;
struct D2ObjectsTxt;

struct D2ShrinesTxt
{
    unsigned char nCode;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char nInteractType;
    char unk0x05[0x0B];
    int bPermanent;
    int unk0x14;
    char unk0x18[0x20];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x10 - 0x08];
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x44 - 0x18];
    int nFrame;
    char unk0x48[0x4C - 0x48];
    short wAnimSpeed;
    char unk0x4E[0x64 - 0x4E];
    D2GfxLightStrc* pLight;
    char unk0x68[0xC4 - 0x68];
    unsigned int dwFlags;
};

struct D2ObjectsTxt
{
    char unk0x000[0xC4];
    unsigned char nSelectable[8];
    char unk0x0CC[0xD8 - 0xCC];
    int dwFrameCnt[8];
    char unk0x0F8[0x108 - 0xF8];
    unsigned char nCycleAnim[8];
    unsigned char nLit[8];
    unsigned char nBlocksLight[8];
    unsigned char nHasCollision[8];
    unsigned char nIsAttackable0;
    unsigned char nStart[8];
    unsigned char nOrderFlag[8];
    unsigned char nEnvEffect;
    unsigned char nIsDoor;
    char unk0x13B[0x164 - 0x13B];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    char unk0x167[0x16F - 0x167];
    unsigned char nShrineFunction;
    char unk0x170[0x194 - 0x170];
    int n194;
    char unk0x198[0x1B4 - 0x198];
    unsigned char nClientFn;
    unsigned char nOverlay;
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int unk0x08[5];
};

struct D2ShrineHandlerStrc
{
    void (__fastcall* pfnInit)(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxt);
    void (__fastcall* pfnOperate)(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ShrinesTxt* pShrinesTxt);
    char unk0x08[8];
    int nSoundId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszUnitSourceFile_006DAA8C[];
extern D2DrlgActStrc* gpAct_007A0634;
extern D2ShrineHandlerStrc gShrineHandlers_006DA8C0[];
extern int gnShrineHandlerCount_0072779C;
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);
void __fastcall sub_00457460(D2UnitStrc* pUnit, int nArg, int nValue);
void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount);
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);
unsigned char __fastcall sub_004BDEE0(D2UnitStrc* pUnit);
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8);
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6);
void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004CB460(D2UnitStrc* pUnit);
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);
int __stdcall sub_00621B00_IsShrine(D2UnitStrc* pUnit);
D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit);
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord);
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId);
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);

static void __stdcall sub_004BC580_UpdateLight(D2UnitStrc* pUnit, unsigned short nDiameter, int nRed, int nGreen, int nBlue)
{
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!nDiameter)
    {
        if (pLight)
            sub_00464930_FreeLight(pUnit);
        return;
    }

    if (!pLight)
    {
        pLight = sub_00474160_MakeLightEntry(pUnit, 2, nDiameter >> 1, 0xFF, nRed, nGreen, nBlue);
        pUnit->pLight = pLight;
        if (!pLight)
            return;
    }

    sub_00474290(pLight, nDiameter >> 1);
}

int __fastcall sub_004BC5E0_UpdateEnvObject(D2UnitStrc* pUnit, int bNoRefresh)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    if (!pTxt->nEnvEffect)
        return 0;

    switch (ENVIRONMENT_GetPeriodOfDayFromAct(gpAct_007A0634, 0))
    {
    case 0:
        if (pUnit->dwAnimMode == 2 || pUnit->dwAnimMode == 1)
        {
            pUnit->dwAnimMode = 0;
            if (!bNoRefresh)
                sub_00470610_Refresh(pUnit, 0);

            sub_00624390_AnimInit(pUnit);
            sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pUnit->dwAnimMode], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
            if (pTxt->nSelectable[pUnit->dwAnimMode])
                pUnit->dwFlags |= 2;
            else
                pUnit->dwFlags &= ~2;
            return 1;
        }
        return 0;

    case 1:
    case 2:
    case 3:
        if (pUnit->dwAnimMode == 0)
        {
            pUnit->dwAnimMode = 1;
            if (!bNoRefresh)
                sub_00470610_Refresh(pUnit, 0);

            sub_00624390_AnimInit(pUnit);
            sub_00457460(pUnit, 2, pTxt->nSelectable[pUnit->dwAnimMode]);
        }
        sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pUnit->dwAnimMode], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
        return 1;

    default:
        D2_ASSERT(0, 0x66);
    }
    return 0;
}

void __fastcall sub_004BC720_InitObject(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nObjectId, unsigned char nMode)
{
    pUnit->pLight = 0;
    pUnit->dwAnimMode = nMode;
    pUnit->pObjectData = (D2ObjectDataStrc*)FOG_Alloc(sizeof(D2ObjectDataStrc), gszUnitSourceFile_006DAA8C, 0x76, 0);
    memset(pUnit->pObjectData, 0, sizeof(D2ObjectDataStrc));
    pUnit->pObjectData->bPermanent = 0;
    pUnit->pObjectData->unk0x14 = 0;

    D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
    if (pTxt->nSelectable[pUnit->dwAnimMode])
        pUnit->dwFlags |= 2;
    else
        pUnit->dwFlags &= ~2;

    pUnit->pObjectData->pObjectTxt = pTxt;
    UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
    if (pTxt->nHasCollision[pUnit->dwAnimMode])
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);

    if (pTxt->nIsAttackable0)
        pUnit->dwFlags |= 4;
    else
        pUnit->dwFlags &= ~4;

    UNITROOM_AddUnitToRoom(pUnit, pRoom);
    pUnit->dwFlags &= ~8;
    sub_00624390_AnimInit(pUnit);

    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;

    if (pTxt->nOrderFlag[pUnit->dwAnimMode] == 1)
        pUnit->dwFlags |= 0x100000;

    switch (pUnit->dwClassId)
    {
    case 0x3B:
    {
        nMode = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nMode);
        D2_ASSERT(nTownLevelId <= 0xFF, 0x95);
        pUnit->pObjectData->nInteractType = nTownLevelId;
        break;
    }
    case 0x3C:
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nLevelId == 0x26)
            pUnit->pObjectData->nInteractType = 4;
        else if (nLevelId == 4)
            pUnit->pObjectData->nInteractType = 0x26;
        break;
    }
    }

    if (!sub_004BC5E0_UpdateEnvObject(pUnit, 1))
        sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pUnit->dwAnimMode], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
}

// 0x004BCA90
static void sub_004BCA90_FinishDoorMode(D2UnitStrc* pUnit)
{
    const int nMode = pUnit->dwAnimMode;
    if (nMode == 3)
    {
        pUnit->dwAnimMode = 0;
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[0];
    }
    else if (nMode == 1)
    {
        UNITS_FreeCollisionPath(pUnit);
        pUnit->dwAnimMode = 2;
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[2];
    }
    else
    {
        D2_ASSERT(0, 0x11F);
    }

    sub_00470610_Refresh(pUnit, 0);
    sub_00624390_AnimInit(pUnit);
    if (pUnit->pObjectData->pObjectTxt->nSelectable[pUnit->dwAnimMode])
        pUnit->dwFlags |= 2;
    else
        pUnit->dwFlags &= ~2;
}

static void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit)
{
    const int nMode = pUnit->dwAnimMode;
    const int nFrameCnt = pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode];
    if (nMode == 1)
    {
        const int nLastFrame = nFrameCnt - 0x100;
        int nFrame = pUnit->nFrame;
        if (nFrame == nLastFrame)
        {
            sub_004BCA90_FinishDoorMode(pUnit);
            return;
        }
        nFrame += pUnit->wAnimSpeed;
        pUnit->nFrame = nFrame;
        if (nFrame > nLastFrame)
            pUnit->nFrame = nLastFrame;
        return;
    }

    if (nMode == 3)
    {
        const int nFrame = pUnit->nFrame;
        if (nFrame <= 0)
        {
            sub_004BCA90_FinishDoorMode(pUnit);
            return;
        }
        if (pUnit->wAnimSpeed > nFrame)
            pUnit->nFrame = 0;
        else
            pUnit->nFrame = nFrame - pUnit->wAnimSpeed;
        return;
    }

    D2_ASSERT(0, 0x155);
}

static void sub_004BCBB0_UpdateObjectFrame(D2UnitStrc* pUnit)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    int nMode = pUnit->dwAnimMode;
    const int nFrameCnt = pTxt->dwFrameCnt[nMode];
    if (nFrameCnt == 0x100)
        return;

    const int nCycle = pUnit->pObjectData->pObjectTxt->nCycleAnim[nMode];
    if (!nCycle)
    {
        if (pTxt->nIsDoor)
        {
            sub_004BCB20_StepDoorFrame(pUnit);
            return;
        }

        if (pUnit->nFrame >= nFrameCnt - 0x100)
        {
            if (pUnit->dwClassId == 0xBD && (nMode == 2 || nMode == 3))
            {
                ++nMode;
                pUnit->dwAnimMode = nMode;
                pUnit->nFrame = pTxt->nStart[nMode] << 8;
                sub_00470610_Refresh(pUnit, 0);
                sub_00624390_AnimInit(pUnit);
                return;
            }

            if (nMode != 1)
                return;

            pUnit->dwAnimMode = 2;
            if (pTxt->nOrderFlag[2] == 1)
                pUnit->dwFlags |= 0x100000;

            if (pTxt->n194)
            {
                if (pTxt->n194 == 0xFF)
                    sub_0046C320_SpawnAroundUnit(pUnit, 0x153, 4);
                else
                    sub_0046C320_SpawnAroundUnit(pUnit, 0x97, 4);
            }

            pUnit->nFrame = pTxt->nStart[2] << 8;
            sub_00470610_Refresh(pUnit, 0);
            sub_00624390_AnimInit(pUnit);
            if (pTxt->nOverlay)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x162 || nClassId == 0x163 || nClassId == 0x18D || nClassId == 0x195
                    || nClassId == 0x197 || nClassId == 0x196 || nClassId == 0x164)
                    sub_0046F0C0(pUnit, 0, 0x47);
            }

            sub_00457460(pUnit, 2, pTxt->nSelectable[pUnit->dwAnimMode]);
            sub_004BC580_UpdateLight(pUnit, pTxt->nLit[2], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
            if (!pTxt->nHasCollision[pUnit->dwAnimMode] && pTxt->nHasCollision[1])
                UNITS_FreeCollisionPath(pUnit);
            return;
        }
    }

    if (pUnit->dwClassId == 0x0C)
    {
        pUnit->nFrame -= pUnit->wAnimSpeed;
        if (pUnit->nFrame < 0)
            pUnit->nFrame += nFrameCnt;
        return;
    }

    if (pUnit->dwClassId == 0xBD && nMode == 3)
    {
        pUnit->nFrame -= pUnit->wAnimSpeed;
        if (pUnit->nFrame >= 0)
            return;

        pUnit->dwAnimMode = 4;
        pUnit->nFrame = pTxt->nStart[4] << 8;
        sub_00470610_Refresh(pUnit, 0);
        sub_00624390_AnimInit(pUnit);
        return;
    }

    pUnit->nFrame += pUnit->wAnimSpeed;
    const int nFrame = pUnit->nFrame;
    if (nFrame >= nFrameCnt)
    {
        if (!nCycle)
            pUnit->nFrame = nFrameCnt - 0x100;
        else
            pUnit->nFrame = (pTxt->nStart[nMode] << 8) - nFrameCnt + nFrame;
    }
}

static void __stdcall sub_004BCDE0_SetDoorMode(int bSelectable, D2UnitStrc* pUnit, int nMode)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    D2_ASSERT(nMode < 8, 0x210);

    const unsigned int nOpenFrames = pTxt->dwFrameCnt[1];
    if (nMode == 0 && pUnit->dwAnimMode == 2 && pTxt->dwFrameCnt[3] != 0x100)
    {
        pUnit->nFrame = pTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 3);
        sub_00470610_Refresh(pUnit, 0);
        pUnit->dwFlags &= ~2;
        UNITS_BlockCollisionPath(pUnit, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
    }
    else if (nMode == 2 && pUnit->dwAnimMode == 0 && nOpenFrames != 0x100)
    {
        UNITS_ChangeAnimMode(pUnit, 1);
        sub_00470610_Refresh(pUnit, 0);
        pUnit->dwFlags &= ~2;
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[2];
    }
    else
    {
        if (bSelectable)
            pUnit->dwFlags |= 2;
        else
            pUnit->dwFlags &= ~2;

        const int nCurrentMode = pUnit->dwAnimMode;
        if (nMode != nCurrentMode)
        {
            if (nMode == 4 || nMode == 2 || nMode == 5)
            {
                if (nCurrentMode != 5 && nCurrentMode != 2 && nCurrentMode != 4)
                    UNITS_FreeCollisionPath(pUnit);
            }
            else if (nMode == 0 && nCurrentMode != 0)
            {
                UNITS_BlockCollisionPath(pUnit, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            }

            UNITS_ChangeAnimMode(pUnit, nMode);
            sub_00470610_Refresh(pUnit, 0);
        }
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[nMode];
    }

    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;
}

static void sub_004BCF60_SetObjectMode(D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    if (pTxt->nIsDoor)
    {
        sub_004BCDE0_SetDoorMode(pTarget->nParam1, pUnit, pTarget->nParam2);
    }
    else
    {
        UNITS_ChangeAnimMode(pUnit, pTarget->nParam2);
        sub_00470610_Refresh(pUnit, 0);
        if (pTxt->nOverlay)
        {
            const int nClassId = pUnit->dwClassId;
            if ((nClassId == 0x162 || nClassId == 0x163 || nClassId == 0x18D || nClassId == 0x195
                || nClassId == 0x197 || nClassId == 0x196 || nClassId == 0x164) && pUnit->dwAnimMode == 0)
                sub_00470390(pUnit, 0x47, 3, 0, 0, 0, 0, 0);
        }

        if (pTxt->nSelectable[pUnit->dwAnimMode])
            pUnit->dwFlags |= 2;
        else
            pUnit->dwFlags &= ~2;

        if (!pTxt->nHasCollision[pUnit->dwAnimMode])
            UNITS_FreeCollisionPath(pUnit);

        if (pTxt->nOrderFlag[pUnit->dwAnimMode] == 1)
            pUnit->dwFlags |= 0x100000;

        sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pTarget->nParam2], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
    }

    sub_004CB460(pUnit);
    sub_00624390_AnimInit(pUnit);
    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;
}

static void __stdcall sub_004BD550_PlayShrineSound(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
    D2_ASSERT(pShrinesTxt, 0x34D);
    D2_ASSERT(pShrinesTxt->nCode < gnShrineHandlerCount_0072779C, 0x34E);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->nCode];
    if (pHandler->nSoundId)
        sub_004B9A00(pHandler->nSoundId, pPlayer, 0, 0, 0);
}

// build: context sub_004BD5C0_OperateShrine
static void __stdcall sub_004BD5C0_OperateShrine(D2UnitTargetStrc* pTarget, D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = 0;
    int nIndex;
    if (sub_00621B00_IsShrine(pUnit))
    {
        pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
        nIndex = pShrinesTxt->nCode;
    }
    else
    {
        nIndex = DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nShrineFunction;
    }

    D2UnitStrc* pPlayer = sub_00463990(pTarget->nParam1, 0);
    if (!pPlayer)
        return;

    if (nIndex > 0 && nIndex < gnShrineHandlerCount_0072779C && gShrineHandlers_006DA8C0[nIndex].pfnOperate)
        gShrineHandlers_006DA8C0[nIndex].pfnOperate(pUnit, pPlayer, pShrinesTxt);

    sub_004BD550_PlayShrineSound(pPlayer, pUnit);
}

static void sub_004BD650_InitShrine(D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
    D2_ASSERT(pShrinesTxt, 0x37A);
    D2_ASSERT(pShrinesTxt->nCode < gnShrineHandlerCount_0072779C, 0x37B);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->nCode];
    if (pHandler->pfnInit)
        pHandler->pfnInit(pUnit, pShrinesTxt);
}

void __fastcall sub_004BD6B0_SetShrine(D2UnitStrc* pUnit)
{
    UNITS_SetShrineTxtRecordInObjectData(pUnit, DATATBLS_GetShrinesTxtRecord(pUnit->pObjectData->nInteractType));
    sub_004BD650_InitShrine(pUnit);
}

void __fastcall sub_004BD6D0_ObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget)
{
    switch (nCommand)
    {
    case 3:
        sub_004BCF60_SetObjectMode(pUnit, pTarget);
        if (sub_00621B00_IsShrine(pUnit))
            sub_004BD650_InitShrine(pUnit);
        return;

    case 0x15:
        sub_004BD5C0_OperateShrine(pTarget, pUnit);
        return;

    default:
        D2_ASSERT(0, 0x39C);
    }
}

void __fastcall sub_004BDFF0_UpdateObject(D2UnitStrc* pUnit)
{
    sub_004BCBB0_UpdateObjectFrame(pUnit);
    if (pUnit->pObjectData->pObjectTxt->nClientFn <= 3 || sub_004BDEE0(pUnit))
        sub_004CB460(pUnit);
}
