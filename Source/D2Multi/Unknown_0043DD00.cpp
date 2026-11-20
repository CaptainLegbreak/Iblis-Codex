#include "D2MultiTypes.h"
struct D2WinControlStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short w = 0) : wChar(w) {}
};

#pragma pack(push, 1)
#pragma pack(pop)

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
#pragma intrinsic(strcat)
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall D2Win_10046(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0

extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern D2WinControlStrc* gpChatControl_0077B058[17];                                                        // 0x0077B058
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern D2WinControlStrc* gpControl_0077B080;                                                                // 0x0077B080
D2WinControlStrc* gpControl_0077B094;                                                                       // 0x0077B094
extern D2WinControlStrc* gpControl_0077B098;                                                                // 0x0077B098
extern D2WinControlStrc* gapControls_0077B050[2];                                                           // 0x0077B050
extern D2WinControlStrc* gpControl_0077BC40;                                                                // 0x0077BC40
extern D2WinControlStrc* gpControl_0077BD98;                                                                // 0x0077BD98
extern D2WinControlInitStrc gtControlInit_0070CF70;                                                         // 0x0070CF70
extern D2WinControlInitStrc gtControlInit_0070CFA0;                                                         // 0x0070CFA0
extern D2WinControlInitStrc gtControlInit_0070CFD0;                                                         // 0x0070CFD0
extern D2WinControlInitStrc gtControlInit_0070D000;                                                         // 0x0070D000
extern D2WinControlInitStrc gtControlInit_0070D030;                                                         // 0x0070D030
extern D2WinControlInitStrc gtControlInit_0070D120;                                                         // 0x0070D120
extern D2WinControlInitStrc gtControlInit_0070D150;                                                         // 0x0070D150
extern D2WinControlInitStrc gatControlInits_0070D180[2];                                                    // 0x0070D180
extern D2WinControlInitStrc gtControlInit_0070D1E0;                                                         // 0x0070D1E0
extern D2WinControlInitStrc gtControlInit_0070D2A0;                                                         // 0x0070D2A0
extern "C" const char gszLevelFormat_006D4E24[];                                                            // 0x006D4E24

// 0x0043DD00
static void __cdecl sub_0043DD00_GetClassName(int nClass, Unicode* pDest)
{
    switch (nClass)
    {
    case 0:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFAB));
        break;
    case 1:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFAA));
        break;
    case 2:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFA9));
        break;
    case 3:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFA8));
        break;
    case 4:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFA7));
        break;
    case 5:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0x2771));
        break;
    case 6:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0x2772));
        break;
    default:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0x1507));
        break;
    }
}
#define GET_CLASS_NAME sub_0043DD00_GetClassName

void __cdecl sub_0043DDD0_CreateCharControls()
{
    for (int i = 0; i < 17; i++)
        gpChatControl_0077B058[i] = 0;
    gpControlA_0077B070 = CONTROL_Create(&gtControlInit_0070CF70);
    gpChatControl_0077B074 = CONTROL_Create(&gtControlInit_0070CFA0);
    gpControlB_0077B078 = CONTROL_Create(&gtControlInit_0070CFD0);
    gpControlC_0077B07C = CONTROL_Create(&gtControlInit_0070D000);
    gpControl_0077B080 = CONTROL_Create(&gtControlInit_0070D030);
    gpControl_0077B094 = CONTROL_Create(&gtControlInit_0070D120);
    gpControl_0077B098 = CONTROL_Create(&gtControlInit_0070D150);
    sub_004F96F0_ControlClearState(gpChatControl_0077B074, 0);
    for (int j = 0; j <= 1; j++)
        gapControls_0077B050[j] = CONTROL_Create(&gatControlInits_0070D180[j]);
    gpControl_0077BC40 = CONTROL_Create(&gtControlInit_0070D1E0);

    Unicode wszClass[100];
    char szText[100];
    szText[0] = 0;
    const char* szRealm = D2Win_10161(gpCharInfo_0077BBD8->nValue0x1EE, (*(unsigned short*)gpCharInfo_0077BBD8->wFlags >> 8) & 0x1F,
        *(unsigned short*)gpCharInfo_0077BBD8->wFlags & 4, *(unsigned short*)gpCharInfo_0077BBD8->wFlags & 0x20);
    if (szRealm)
        strcat(szText, szRealm);
    strcat(szText, gpCharInfo_0077BBD8->szName0xBD);
    D2Win_10046(gpControl_0077BC40, szText, (gpCharInfo_0077BBD8->wFlags0x3CB[0] >> 2) & 1);
    GET_CLASS_NAME(gpCharInfo_0077BBD8->nValue0x1EE, wszClass);

    Unicode wszLine[100];
    Unicode wszLevel[10];
    sprintf(szText, gszLevelFormat_006D4E24, gpCharInfo_0077BBD8->nValue0x3C1 ? gpCharInfo_0077BBD8->nValue0x3C1 : 1);
    sub_00526F20_ToUnicode(wszLevel, szText, 9);
    sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xFD9));
    sub_00526700(wszLine, wszLevel);
    sub_00526700(wszLine, wszClass);
    sub_004FC9B0_SetText(gpControl_0077BC40, wszLine, 0, 0, 0);
    sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x2B74), 0, 0, 0);

    switch (((*(unsigned short*)gpCharInfo_0077BBD8->wFlags >> 8) & 0x1F) / ((*(unsigned short*)gpCharInfo_0077BBD8->wFlags & 0x20) ? 5 : 4))
    {
    case 0:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x2B75), 0, 0, 0);
        break;
    case 1:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x1424), 0, 0, 0);
        break;
    case 2:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x1423), 0, 0, 0);
        break;
    default:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x1422), 0, 0, 0);
        break;
    }

    gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    if (gpControl_0077BD98)
        sub_004FC9B0_SetText(gpControl_0077BD98, D2LANG_GetStringFromTblIndex(0x2B73), 3, 0, 0);
}

#include "gen/data/Source/D2Multi/Unknown_0043DD00.inc"
