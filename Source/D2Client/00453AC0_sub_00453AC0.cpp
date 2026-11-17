struct Unicode;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2ClientEntryStrc
{
    char unk0x00[0x08];
    int nState;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int unk0x10[5];
    D2ClientEntryStrc tEntry;
    D2RosterPetStrc* pNext;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __cdecl sub_00454740_LoadLoadingPalette();                                                             // 0x00454740
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern int gdwGlobal_0070FA9C;                                                                              // 0x0070FA9C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnTimerUnitId_007129D4;                                                                          // 0x007129D4
extern unsigned long gdwUIVarTick_007A2790;                                                                 // 0x007A2790
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gdwGlobal_007A5238;                                                                              // 0x007A5238
extern void* gpGlobal_007A523C;                                                                             // 0x007A523C
extern void* gpGlobal_007A5240;                                                                             // 0x007A5240
extern void* gpGlobal_007A5244;                                                                             // 0x007A5244
extern int gnGlobal_007B8D20;                                                                               // 0x007B8D20
extern int gnGlobal_007B9534;                                                                               // 0x007B9534
extern int gnGlobal_007B9538;                                                                               // 0x007B9538
extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC

// 0x00453AC0
void __cdecl sub_00453AC0()
{
    gdwGlobal_0070FA9C = 0;
    gdwUIVarTick_007A2790 = 0;
}

// 0x00453AD0
void __cdecl sub_00453AD0()
{
    gdwGlobal_0070FA9C = 1;
}

// 0x0045FBC0
void __stdcall sub_0045FBC0_DrawCelPair(int bFirst)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (bFirst)
        tContext.pCellFile = gpGlobal_007A523C;
    else
        tContext.pCellFile = gpGlobal_007A5244;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0xBC, 0x148 - gnGlobal_007A285C, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x1BC, 0x148 - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0045FD80
void __cdecl sub_0045FD80_DrawCenteredString()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_007A2858 + 0x110, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x170, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    sub_00502EF0(nOldFont);
}

// 0x0045FFC0
void __cdecl sub_0045FFC0_DrawCenteredStrings()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xBE - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
    unsigned short nString = 0x1432;
    if (gdwGlobal_007A5238)
        nString = 0x5578;
    sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(nString), 0);
    sub_00502EF0(nOldFont);
}

// 0x004600F0
void __cdecl sub_004600F0_DrawCenteredStringPair()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_007A2858 + 0xCE, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x12E, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    sub_004A7080(gnGlobal_007A2858 + 0x152, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1B2, D2LANG_GetStringFromTblIndex(0x13EF), 0);
    sub_00502EF0(nOldFont);
}

// 0x00460430
void __cdecl sub_00460430_FreeCels()
{
    if (gpGlobal_007A523C)
    {
        sub_00478A00(gpGlobal_007A523C);
        gpGlobal_007A523C = 0;
    }
    if (gpGlobal_007A5244)
    {
        sub_00478A00(gpGlobal_007A5244);
        gpGlobal_007A5244 = 0;
    }
    if (gpGlobal_007A5240)
    {
        sub_00478A00(gpGlobal_007A5240);
        gpGlobal_007A5240 = 0;
    }
    sub_00454740_LoadLoadingPalette();
}

// 0x0046BC70
int __fastcall sub_0046BC70_SetTimerUnitId(D2UnitStrc* pUnit)
{
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    gnTimerUnitId_007129D4 = nUnitId;
    return nUnitId;
}

// 0x00476AF0
void __cdecl sub_00476AF0_ClearGlobals()
{
    gnGlobal_007B9534 = 0;
    gnGlobal_007B9538 = 0;
    gnGlobal_007B8D20 = 0;
}

// 0x00478A50
void __cdecl sub_00478A50_FreeRosterPets()
{
    D2RosterPetStrc* pPet = gpRosterPets_007BB5BC;
    while (pPet)
    {
        D2RosterPetStrc* pNext = pPet->pNext;
        FOG_Free(pPet, ".\\GAME\\RosterPets.cpp", 0x2F, 0);
        pPet = pNext;
    }
    gpRosterPets_007BB5BC = 0;
}

#include "gen/data/Source/D2Client/00453AC0_sub_00453AC0.inc"
