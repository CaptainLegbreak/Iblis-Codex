#include "D2Unicode.h"
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0

static int __fastcall GetCenteredXInline(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    nWidth /= 2;
    return nX - nWidth;
}

// 0x00495DC0
void __cdecl sub_00495DC0_DrawHelpText()
{
    unsigned short wszLine1Buf[100];
    Unicode* wszLine1 = (Unicode*)wszLine1Buf;
    unsigned short wszLine2Buf[100];
    Unicode* wszLine2 = (Unicode*)wszLine2Buf;
    unsigned short wszLine3Buf[100];
    Unicode* wszLine3 = (Unicode*)wszLine3Buf;
    unsigned short wszLine4Buf[100];
    Unicode* wszLine4 = (Unicode*)wszLine4Buf;
    unsigned short wszLine5Buf[100];
    Unicode* wszLine5 = (Unicode*)wszLine5Buf;

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1066), GetCenteredXInline(0x1066, 0x131), 0x11, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1030), GetCenteredXInline(0x1030, 0x21D), 0x49, 0, 0);

    const int nOldFont = sub_00502EF0(5);

    for (int i = 0; i < 100; ++i)
    {
        wszLine1[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine1Buf) / sizeof(wszLine1[0]), wszLine1, D2LANG_GetStringFromTblIndex(0x1067), CMDTBL_GetKeyText(0x22, 1));
    D2Win_10117_DrawText(wszLine1, 0x75, 0x4E, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine2[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine2Buf) / sizeof(wszLine2[0]), wszLine2, D2LANG_GetStringFromTblIndex(0x1068), CMDTBL_GetKeyText(0x25, 1));
    D2Win_10117_DrawText(wszLine2, 0x75, 0x62, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine3[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine3Buf) / sizeof(wszLine3[0]), wszLine3, D2LANG_GetStringFromTblIndex(0x1069), CMDTBL_GetKeyText(0x24, 1));
    D2Win_10117_DrawText(wszLine3, 0x75, 0x76, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine4[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine4Buf) / sizeof(wszLine4[0]), wszLine4, D2LANG_GetStringFromTblIndex(0x106A), CMDTBL_GetKeyText(0x7, 1));
    D2Win_10117_DrawText(wszLine4, 0x75, 0x8A, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106B), 0x75, 0x9E, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106C), 0x75, 0xB2, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106D), 0x75, 0xC6, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine5[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine5Buf) / sizeof(wszLine5[0]), wszLine5, D2LANG_GetStringFromTblIndex(0x106E), CMDTBL_GetKeyText(0x6, 1));
    D2Win_10117_DrawText(wszLine5, 0x75, 0xDA, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106F), GetCenteredXInline(0x106F, 0x37), 0x168, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1070), GetCenteredXInline(0x1070, 0x83), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredXInline(0x1071, 0x83), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredXInline(0x1072, 0x83), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1074), GetCenteredXInline(0x1074, 0xB6), 0x181, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1075), GetCenteredXInline(0x1075, 0xB6), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1076), GetCenteredXInline(0x1076, 0xE7), 0x168, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1077), GetCenteredXInline(0x1077, 0x120), 0x181, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1078), GetCenteredXInline(0x1078, 0x120), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1079), GetCenteredXInline(0x1079, 0x162), 0x113, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107A), GetCenteredXInline(0x107A, 0x162), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107B), GetCenteredXInline(0x107B, 0x162), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107C), GetCenteredXInline(0x107C, 0x162), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107D), GetCenteredXInline(0x107D, 0x1C1), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1073), GetCenteredXInline(0x1073, 0x1FB), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredXInline(0x1071, 0x1FB), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredXInline(0x1072, 0x1FB), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107E), GetCenteredXInline(0x107E, 0x24A), 0x168, 0, 0);

    sub_00502EF0(nOldFont);
}
