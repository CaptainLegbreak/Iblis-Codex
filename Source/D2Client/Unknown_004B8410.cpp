#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SoundUnitNodeStrc;
struct Unicode;
struct D2RectStrc;
struct D2DialogLineStrc;
struct D2SoundVecStrc;
struct D2SoundsTxtStrc;
struct T00481920;
struct D2SoundNodeStrc;

struct Unicode
{
    unsigned short ch;
};

struct D2DialogLineStrc
{
    Unicode wszText[0x78];
    int nHeight;
    int nX;
    int nWidth;
    int nArg4;
    int nFont;
    int nType;
    int (__cdecl* pfnCallback)();
    int bEnabled;
};

struct D2ClientDialogStrc
{
    char unk0x00[0x14];
    int bCountEnabled;
    char unk0x18[0xC];
    int nCenterX;
    int nCenterY;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    char unk0x3C[0x8];
    int f_44;
    char unk0x48[0x4];
    int nEnabled;
    int nLines;
    char unk0x54[0x4];
    int bAutoSize;
    int nMode;
    char unk0x60[0x8];
    D2DialogLineStrc pLines[10];
    void* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800


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

extern D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458
extern int gbSoundReady_007C545C; // 0x007C545C
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00481820(); // 0x00481820
D2SoundsTxtStrc* __fastcall sub_00481860(int nId); // 0x00481860
int __fastcall sub_00481890_GetCacheFirst(int nId); // 0x00481890
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax); // 0x004B93A0
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY); // 0x004E4160
void __fastcall sub_00516950_LinkEntry(D2SoundUnitNodeStrc** ppList, D2UnitStrc* pUnit); // 0x00516950
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

static void __stdcall sub_004B97D0_GetSoundOffset(D2UnitStrc* pUnit, int nSoundId, D2SoundVecStrc* pPos);
static void sub_004B98F0_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos);

static void sub_004B83A0_PlaceLine(D2ClientDialogStrc* pDialog, int nIndex)
{
    int nOldFont = sub_00502EF0(1);
    sub_00502EF0(pDialog->pLines[nIndex].nFont);
    int nWidth = sub_00501820(pDialog->pLines[nIndex].wszText);
    if (nWidth >= pDialog->nWidth)
    {
        pDialog->pLines[nIndex].nWidth = nWidth;
        pDialog->pLines[nIndex].nX = 0;
    }
    else
    {
        pDialog->pLines[nIndex].nWidth = nWidth;
        pDialog->pLines[nIndex].nX = (pDialog->nWidth - nWidth + 1) / 2 + 1;
    }
    sub_00502EF0(nOldFont);
}

// 0x004B8410
void __fastcall sub_004B8410_LayoutDialog(D2ClientDialogStrc* pDialog)
{
    int nMaxWidth = 0;
    int nHeight = 0;
    D2_ASSERT(pDialog->bAutoSize, 0x59F);
    int nOldFont = sub_00502EF0(1);
    int nDisabled = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        int nWidth = sub_00501820(pDialog->pLines[i].wszText);
        if (nWidth > nMaxWidth)
            nMaxWidth = nWidth;
        if (!pDialog->pLines[i].bEnabled)
            ++nDisabled;
        nHeight += pDialog->pLines[i].nHeight;
    }
    nMaxWidth += 0x14;
    nHeight += 0xF;
    sub_00502EF0(nOldFont);
    pDialog->nX = pDialog->nCenterX - nMaxWidth / 2;
    if (pDialog->bCountEnabled)
        pDialog->nY = pDialog->nCenterY - nDisabled * 0x15;
    else
        pDialog->nY = pDialog->nCenterY - nHeight / 3;
    D2_ASSERT(nMaxWidth <= gnGlobal_0071146C - 0x50, 0x5D2);
    D2_ASSERT(nHeight <= gnGlobal_00711470 - 0x62, 0x5D7);
    if (pDialog->nX + nMaxWidth > gnGlobal_0071146C - 0xA)
        pDialog->nX = gnGlobal_0071146C - nMaxWidth;
    if (pDialog->nY + nHeight > gnGlobal_00711470 - 0x3A)
        pDialog->nY = gnGlobal_00711470 - nHeight - 0x30;
    if (pDialog->nX <= 0xA)
        pDialog->nX = 0xA;
    if (pDialog->nY <= 0xA)
        pDialog->nY = 0xA;
    pDialog->nWidth = nMaxWidth;
    pDialog->nHeight = nHeight;
    for (int j = 0; j < pDialog->nLines; ++j)
        sub_004B83A0_PlaceLine(pDialog, j);
}

void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4,
    int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled)
{
    int nIndex = pDialog->nLines;
    D2_ASSERT(nIndex < 10, 0x552);
    pDialog->nLines = nIndex + 1;
    pDialog->pLines[nIndex].nHeight = nHeight;
    pDialog->pLines[nIndex].nFont = nFont;
    pDialog->pLines[nIndex].nArg4 = nArg4;
    pDialog->pLines[nIndex].nX = 0;
    if (nType == 3)
    {
        D2_ASSERT(pDialog->nMode != 1, 0x55E);
    }
    pDialog->pLines[nIndex].nType = nType;
    pDialog->pLines[nIndex].pfnCallback = pfnCallback;
    pDialog->pLines[nIndex].bEnabled = bEnabled;
    int nLen = sub_00526800(wszText) + 1;
    if (nLen > 0x77)
        nLen = 0x77;
    sub_00526790(pDialog->pLines[nIndex].wszText, wszText, nLen);
    pDialog->pLines[nIndex].wszText[nLen].ch = 0;
    if (bEnabled)
        pDialog->nEnabled += 1;
    if (pDialog->bAutoSize)
        sub_004B8410_LayoutDialog(pDialog);
    else
        sub_004B83A0_PlaceLine(pDialog, nIndex);
    D2RectStrc tRect;
    tRect.nLeft = pDialog->nX;
    tRect.nTop = pDialog->nY;
    tRect.nRight = pDialog->nX + pDialog->nWidth;
    tRect.nBottom = pDialog->nY + pDialog->nHeight;
    sub_00467430(&tRect);
    if (pDialog->f_44 == -1 && bEnabled)
        sub_004B82F0_Select(pDialog, nIndex);
}

// 0x004B9760
static D2ClientSoundStrc* __stdcall sub_004B9760_FindGroupSound(D2ClientSoundStrc* pExclude, int nSoundId)
{
    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        if (sub_00481890_GetCacheFirst(pSound->nSoundId) == pTxt->nGroup && pSound != pExclude && !pSound->bLocked)
        {
            if (pTxt->nTimeout < 0 || sub_00481820() - pSound->f_34 <= pTxt->nTimeout)
                return pSound;
        }
    }
    return NULL;
}

// 0x004B9890
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

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
        return 0.5f;

    return 0.0f;
}

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4)
{
    if (!gbSoundReady_007C545C)
        return 0;

    if (nSoundId <= 0)
        return 0;

    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    const int nTick = sub_00481820();
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
        pSound->nArg4 = nArg4;
        pSound->nSoundId = nSoundId;
        pSound->f_34 = nDelay + nTick;
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

    if (pUnit == sub_00463DD0_GetPlayerUnit())
        pSound->nPriority += 0x50;

    if (pUnit)
    {
        sub_00516950_LinkEntry(&pSound->pUnitList, pUnit);
        sub_004CA8A0_AddUnitSound(pUnit, pSound->f_8);
    }

    return pSound->f_8;
}

// 0x004B97D0
static void __stdcall sub_004B97D0_GetSoundOffset(D2UnitStrc* pUnit, int nSoundId, D2SoundVecStrc* pPos)
{
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    int nX;
    int nY;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

// 0x004B98F0
static void sub_004B98F0_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos)
{
    D2_ASSERT(pSound && pPos, 0x1A6);

    pSound->vPos = *pPos;
    const float fX = sub_004B93A0_ClampFloat(pPos->fX, -2000.0f, 2000.0f);
    const float fY = sub_004B93A0_ClampFloat(pPos->fY, -2000.0f, 2000.0f);
    pSound->fDistance = sub_004E4160_LengthSquared2D(fX, fY);
}
