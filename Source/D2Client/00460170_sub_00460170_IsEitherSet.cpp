struct D2UnitStrc;
struct D2LightStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x150];
    int nState;
    int nMode;
    int nArg1;
    int nArg2;
};

struct D2ClientUnitViewStrc
{
    int dwUnitType;
    int unk0x04[4];
    D2PlayerDataStrc* pPlayerData;
};

D2LightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                         // 0x00643A00
void __fastcall sub_004743D0_ReleaseOverlayResource(D2LightStrc* pLight);                                   // 0x004743D0
extern int gnGlobal_007A5258;                                                                               // 0x007A5258
extern int gnGlobal_007A525C;                                                                               // 0x007A525C

// 0x00460170
int __cdecl sub_00460170_IsEitherSet()
{
    if (gnGlobal_007A5258 || gnGlobal_007A525C)
        return 1;
    return 0;
}

// 0x00460760
void __fastcall sub_00460760_SetPlayerState(D2ClientUnitViewStrc* pUnit, int nState)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        pUnit->pPlayerData->nState = nState;
}

// 0x004607D0
int __fastcall sub_004607D0_GetPlayerMode(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

// 0x004607F0
int __fastcall sub_004607F0_GetPlayerArg1(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg1;
    return 0;
}

// 0x00460810
int __fastcall sub_00460810_GetPlayerArg2(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg2;
    return 0;
}

// 0x00460FF0
static __forceinline void sub_00460FF0_ReleaseLight(D2UnitStrc* pUnit)
{
    D2LightStrc* pLight = D2Common_10958(pUnit, 0);
    if (pLight)
        sub_004743D0_ReleaseOverlayResource(pLight);
}

void __fastcall sub_M115_Emit_00460FF0(D2UnitStrc* pUnit)
{
    sub_00460FF0_ReleaseLight(pUnit);
}
