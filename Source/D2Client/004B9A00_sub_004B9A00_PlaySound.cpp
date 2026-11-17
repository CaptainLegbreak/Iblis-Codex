struct D2UnitStrc;
struct D2SoundUnitNodeStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2SoundVecStrc
{
    float fX;
    float fY;
    float fZ;
};

#pragma pack(push, 1)
struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    int f_1C;
    float fPan;
    int nArg4;
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
    unsigned int f_34;
    int nArg3;
    unsigned char nPriority;
    int bLocked;
    char unk0x41[0x18];
};

struct D2SoundsTxtStrc
{
    char unk0x00[0x3C];
    unsigned char bEnabled;
    char unk0x3D[8];
    short nTimeout;
    int nKind;
    char unk0x4B[3];
    unsigned char f_4E;
    char unk0x4F[0x11];
    int nGroup;
};
#pragma pack(pop)

struct T00481920
{
    char unk0x00[0x18];
    unsigned char bFlag;
};

struct D2SoundNodeStrc
{
    D2ClientSoundStrc* f_0;
    D2SoundNodeStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define NULL 0

extern D2SoundNodeStrc* gpSoundList_007C5458;                                                               // 0x007C5458
extern int gbSoundReady_007C545C;                                                                           // 0x007C545C
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_004817A0_GetPlayerSoundEnviron();                                                           // 0x004817A0
unsigned int __cdecl sub_00481820();                                                                        // 0x00481820
D2SoundsTxtStrc* __fastcall sub_00481860(int nId);                                                          // 0x00481860
int __fastcall sub_00481890_GetHintGroup(int nId);                                                          // 0x00481890
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId);                        // 0x00481920
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax);                             // 0x004B93A0
D2ClientSoundStrc* __cdecl sub_004B93F0_AllocHintEntry();                                                   // 0x004B93F0
void __fastcall sub_004CA8A0_AddUnitSound(D2UnitStrc* pUnit, int nHandle);                                  // 0x004CA8A0
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY);                                           // 0x004E4160
void __fastcall sub_00516950_LinkEntry(D2SoundUnitNodeStrc** ppList, D2UnitStrc* pUnit);                    // 0x00516950
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                       // 0x00620900
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0

static D2ClientSoundStrc* __stdcall sub_004B9760_FindGroupSound(D2ClientSoundStrc* pExclude, int nSoundId)
{
    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        if (sub_00481890_GetHintGroup(pSound->nSoundId) == pTxt->nGroup && pSound != pExclude && !pSound->bLocked)
        {
            if (pTxt->nTimeout < 0 || sub_00481820() - pSound->f_34 <= pTxt->nTimeout)
                return pSound;
        }
    }
    return NULL;
}

// 0x004B97D0
static void __stdcall sub_004B97D0_GetSoundOffset(D2UnitStrc* pUnit, int nSoundId, D2SoundVecStrc* pPos)
{
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    int nX;
    int nY;

    D2UnitStrc* pPlayer = sub_00463DD0();
    UNITS_GetClientCoords(pPlayer, &tPlayer);
    UNITS_GetClientCoords(pUnit, &tUnit);
    if (nSoundId == 0xA27)
    {
        const double dSlope = -2.0;
        const float fPX = (float)tPlayer.nX;
        const float fPY = (float)tPlayer.nY;
        const float fT = (dSlope * fPX + fPY - tUnit.nX * 0.5 - tUnit.nY) / -2.5;
        nX = (int)fT;
        const float fY = dSlope * fPX - dSlope * fT + fPY;
        nY = (int)fY;
    }
    else
    {
        nY = tUnit.nY;
        nX = tUnit.nX;
    }

    pPos->fX = (float)(nX - tPlayer.nX);
    pPos->fZ = 640.0f;
    pPos->fY = (float)(nY - tPlayer.nY) * 2.0f;
}

static float __stdcall sub_004B9890_GetSoundPan(D2UnitStrc* pUnit, int nSoundId)
{
    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    if (pTxt)
    {
        if (pTxt->nKind == 4)
            return 0.0f;

        if (pTxt->nGroup == 0xCA)
        {
            T00481920* pEnviron = sub_00481920_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
            if (pEnviron && pEnviron->bFlag)
                return 0.5f;

            return 0.0f;
        }
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
        return 0.5f;

    return 0.0f;
}

static void sub_004B98F0_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos)
{
    D2_ASSERT(pSound && pPos, 0x1A6);

    pSound->vPos = *pPos;
    const float fX = sub_004B93A0_ClampFloat(pPos->fX, -2000.0f, 2000.0f);
    const float fY = sub_004B93A0_ClampFloat(pPos->fY, -2000.0f, 2000.0f);
    pSound->fDistance = sub_004E4160_LengthSquared2D(fX, fY);
}

// 0x004B9A00
int __fastcall sub_004B9A00_PlaySound(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4)
{
    if (!gbSoundReady_007C545C)
        return 0;

    if (nSoundId <= 0)
        return 0;

    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    int nTick = sub_00481820();
    if (!pTxt->bEnabled)
        return 0;

    D2ClientSoundStrc* pSound = NULL;
    if (pTxt->nTimeout)
        pSound = sub_004B9760_FindGroupSound(NULL, nSoundId);

    if (!pSound)
    {
        pSound = sub_004B93F0_AllocHintEntry();
        if (!pSound)
            return 0;

        pSound->nArg3 = nArg3;
        pSound->nSoundId = nSoundId;
        pSound->f_34 = nTick + nDelay;
        pSound->nArg4 = nArg4;
        pSound->f_1C = 0xFF;
        pSound->nPriority = pTxt->f_4E;

        D2SoundVecStrc tPos;
        if (pUnit)
        {
            sub_004B97D0_GetSoundOffset(pUnit, nSoundId, &tPos);
            sub_004B98F0_SetSoundPosition(pSound, &tPos);
            pSound->fPan = sub_004B9890_GetSoundPan(pUnit, nSoundId);
        }
        else
        {
            tPos.fX = 0.0f;
            tPos.fY = 0.0f;
            tPos.fZ = 320.0f;
            sub_004B98F0_SetSoundPosition(pSound, &tPos);
        }
    }

    if (pUnit == sub_00463DD0())
        pSound->nPriority += 0x50;

    if (pUnit)
    {
        sub_00516950_LinkEntry(&pSound->pUnitList, pUnit);
        sub_004CA8A0_AddUnitSound(pUnit, pSound->f_8);
    }

    return pSound->f_8;
}
