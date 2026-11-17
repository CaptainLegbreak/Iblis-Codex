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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);

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

// 0x004BCB20
static __declspec(noinline) void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit)
{
    const int nMode = pUnit->dwAnimMode;
    const int nFrameCnt = pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode];
    if (nMode == 1)
    {
        if (pUnit->nFrame == nFrameCnt - 0x100)
        {
            sub_004BCA90_FinishDoorMode(pUnit);
            return;
        }
        pUnit->nFrame += pUnit->wAnimSpeed;
        if (pUnit->nFrame > nFrameCnt - 0x100)
            pUnit->nFrame = nFrameCnt - 0x100;
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

void __fastcall sub_M256_Emit_004BCB20(D2UnitStrc* pUnit)
{
    sub_004BCB20_StepDoorFrame(pUnit);
}
