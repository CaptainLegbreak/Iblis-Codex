struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2ClientServiceStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x80];
    unsigned int dwOverlayFlags;
    char unk0xB4[0x10];
    unsigned int dwFlags;
};

struct D2LevelsTxt
{
    char unk0x000[0x21C];
    unsigned char nSoundEnv;
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0(int* pValue, int nSize);
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650

class WardenModule
{
public:
    ~WardenModule();
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }

    void* pImage;
    int unk0x04;
    int nImports;
    D2ClientSlotObjStrc* pObj;
};

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath);                                   // 0x00650590
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_004E4020(D2UnitStrc* pUnit);                                                            // 0x004E4020
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall sub_004CC5B0_RequestMode(D2UnitStrc* pUnit, int nMode, int nArg);                          // 0x004CC5B0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
void __cdecl sub_004DF800();                                                                                // 0x004DF800
void __cdecl sub_004BAAB0();                                                                                // 0x004BAAB0

extern WardenModule* gpSlotHolder_007BC990;                                                                 // 0x007BC990
extern WardenModule* gpPendingWarden_007BC994;                                                              // 0x007BC994
extern int gnWardenIfaceValue_00721C94;                                                                     // 0x00721C94
extern D2ClientServiceStrc* gpService_007BC998;                                                             // 0x007BC998
extern void* gpWardenBuffer_007BC988;                                                                       // 0x007BC988
extern unsigned int gnWardenBufferSize_007BC98C;                                                            // 0x007BC98C

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// 0x004801D0
void __cdecl sub_004801D0_UnloadWarden()
{
    if (gpSlotHolder_007BC990)
    {
        gpSlotHolder_007BC990->pObj->Slot1();
        gpSlotHolder_007BC990->~WardenModule();
        delete gpSlotHolder_007BC990;
    }
    gpSlotHolder_007BC990 = 0;
}

// 0x00480340
void __cdecl sub_00480340_ResetWarden()
{
    if (gpPendingWarden_007BC994)
    {
        gpPendingWarden_007BC994->~WardenModule();
        delete gpPendingWarden_007BC994;
        gpPendingWarden_007BC994 = 0;
    }
    sub_004801D0_UnloadWarden();
    gnWardenIfaceValue_00721C94 = -1;
    gpService_007BC998 = 0;
    if (gpWardenBuffer_007BC988)
        SMemFree(gpWardenBuffer_007BC988, ".\\WARDEN\\WardenClient.cpp", 0x24F, 0);
    gpWardenBuffer_007BC988 = 0;
    gnWardenBufferSize_007BC98C = 0;
}

// 0x00480490
void __fastcall sub_00480490_RecacheUnitPath(D2UnitStrc* pUnit)
{
    PATH_RecacheRoomIfNeeded(pUnit->pDynamicPath);
}

// 0x00480D20
void __fastcall sub_00480D20_SetModeOverlay(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit)
        return;

    if (pUnit->dwUnitType == 0)
    {
        if (nMode != 0 && nMode != 4 && nMode != 0x13)
            return;
    }
    else if (pUnit->dwUnitType == 1)
    {
        if (nMode != 0 && nMode != 3 && nMode != 0xD)
            return;
    }
    else
    {
        return;
    }

    const unsigned int dwFlags = pUnit->dwOverlayFlags;
    const unsigned int dwKind = dwFlags & 0xF0;
    if (!dwKind || !(dwFlags & 0xF))
        return;

    if (dwKind == 0x20)
        sub_00470390(pUnit, 0x51, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x30)
        sub_00470390(pUnit, 0x24, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x40)
        sub_00470390(pUnit, 1, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x10)
        sub_00470390(pUnit, 0x36, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x70)
        sub_00470390(pUnit, 0x93, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x80)
        sub_00470390(pUnit, 0x15, 2, 0, 0, 0, 0, 0);
    else if (dwKind == 0x90)
        sub_00470390(pUnit, 0x71, 2, 0, 0, 0, 0, 0);
}

// 0x00480E70
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
    {
        sub_00470610_Refresh(pUnit, 0);
        sub_00480D20_SetModeOverlay(pUnit, nMode);
        sub_004CC5B0_RequestMode(pUnit, nMode, 0);
    }
}

// 0x00480EC0
void __fastcall sub_00480EC0_SetUnitModeNoOverlay(D2UnitStrc* pUnit, int nMode)
{
    sub_004E4020(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~0x40;
    if (UNITS_ChangeAnimMode(pUnit, nMode))
        sub_00470610_Refresh(pUnit, 0);
}

// 0x00481780
int __cdecl sub_00481780_GetPlayerLevelId()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return 0;
    return DUNGEON_GetLevelIdFromRoom(pRoom);
}

// 0x004817A0
int __cdecl sub_004817A0_GetPlayerSoundEnv()
{
    int nLevelId = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
            nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }
    if (!nLevelId)
        return 0;
    return DATATBLS_GetLevelsTxtRecord(nLevelId)->nSoundEnv;
}

// 0x00481830
void __cdecl sub_00481830()
{
    sub_004DF800();
    sub_004BAAB0();
}
