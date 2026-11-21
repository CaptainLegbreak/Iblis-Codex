#include "D2Launch.h"
struct D2FileTimeStrc;
struct D2FuncTable;
struct D2MenuCallbackArgStrc;
struct D2LaunchRecordStrc;

struct Unicode
{
    unsigned short wChar;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x98];
    D2FuncRecordStrc* (__cdecl* pfnGetRecord)();
};
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData); // 0x006CC1C8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
const char* __stdcall sub_005180A0_GetNthString(D2FuncRecordStrc* pRecord, int nIndex); // 0x005180A0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall sub_005009D0_SetValue(D2WinControlStrc* pControl, int nMode, Unicode* pText, int nArg); // 0x005009D0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A8B0
int __fastcall sub_004F9190(); // 0x004F9190
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath); // 0x00406A10
int __fastcall sub_00449920_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue); // 0x00449920
extern D2WinControlStrc* gpControl_007795AC; // 0x007795AC
extern int gdwGlobal_00779974; // 0x00779974

void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
extern int gbFeCharPalette_007795F0; // 0x007795F0

struct D2FuncTable { char unk00[0x50]; void (__fastcall* pfnRequest)(const char*, int); char unk54[0x14]; int (__cdecl* pfnAvailable)(); };

extern D2FuncTable* gpFuncTable; // 0x0077ABF0
extern int gnCancelled; // 0x0077932C
extern const char gszMainMenus[]; // 0x006D41C0
extern const char gszTextExt[]; // 0x006D48E0
extern const char gszTosPrefix[]; // 0x006D48E8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void*, unsigned long*); // 0x006CC2F0
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl sub_0042F800(); // 0x0042F800
void __stdcall sub_00525260(void* pOut, int nField); // 0x00525260
unsigned int __stdcall SStrPack(char*, const char*, unsigned int); // 0x00413800
void __cdecl sub_00430400_PollSlot4C(); // 0x00430400
void __stdcall sub_004FA590(D2LaunchDoneFn); // 0x004FA590
void __cdecl sub_004336C0_ShowMainMenu(); // 0x004336C0
void __fastcall sub_00433380_ShowMessage(const Unicode*, D2LaunchDoneFn, int); // 0x00433380
void __cdecl sub_00430390_CreateScreenControls(); // 0x00430390
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int); // 0x0042F430
void* __fastcall sub_00406960_CreateFile(const char*, unsigned long, unsigned long, void*, unsigned long, unsigned long, void*); // 0x00406960
int __fastcall sub_004069B0_ReadFile(void*, void*, unsigned long, unsigned long*, void*); // 0x004069B0
int __fastcall sub_004069A0_CloseFile(void*); // 0x004069A0
int __fastcall sub_00406990_DeleteFile(const char*); // 0x00406990
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_0042E5D0_SwapUnicode(Unicode*, unsigned int); // 0x0042E5D0
Unicode* __fastcall win2Unicode(Unicode*, const char*, int); // 0x00526F20
int __fastcall sub_00501820(const Unicode*); // 0x00501820
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30
void __fastcall D2Win_10053(D2WinControlStrc*, int); // 0x004FBA30

struct D2MenuCallbackArgStrc { D2WinControlStrc* pControl; unsigned int nMessage, nParam, nArg; };

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unknown00[0x85];
    unsigned char nFlag085, nFlag086, nFlag087, nFlag088, nFlag089, nFlag08A, nFlag08B;
    char unknown08C[0x1EE-0x8C]; char nMode; unsigned short nFlags;
};

#pragma pack(pop)
extern D2WinControlStrc* gpClassImages_0077956C[7]; // 0x0077956C
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4
extern D2WinControlStrc* gpControl_00779330; // 0x00779330
extern D2WinControlStrc* gpControl_0077933C; // 0x0077933C
extern D2WinControlStrc* gpControl_0077934C; // 0x0077934C
extern D2WinControlStrc* gpControl_007795B0; // 0x007795B0
extern D2WinControlStrc* gpControl_007795B8; // 0x007795B8
extern D2WinControlStrc* gpControl_007795C4; // 0x007795C4
extern D2WinControlStrc* gpControl_007795CC; // 0x007795CC
int __fastcall sub_004307A0(unsigned int, int, int, int); // 0x004307A0
int __stdcall sub_004308A0_ExpansionNotice6(D2MenuCallbackArgStrc*); // 0x004308A0
int __stdcall sub_004308E0_ExpansionNotice5(D2MenuCallbackArgStrc*); // 0x004308E0
void __stdcall sub_004F91C0(D2WinControlStrc*); // 0x004F91C0
void __fastcall sub_004F9740(D2WinControlStrc*, int); // 0x004F9740
extern "C" int __fastcall sub_00500310_GetAnimImageField50(D2WinControlStrc*); // 0x00500310
int __fastcall D2Win_10104(D2WinControlStrc*); // 0x00500340
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinControlStrc*, int); // 0x005009A0
void __fastcall D2SOUND_10039(const char*); // 0x00514EC0
void __cdecl sub_00515020_FadeOutWaves(); // 0x00515020

int gdwGlobal_00779990; // 0x00779990

// 0x00431AF0
void __cdecl sub_00431AF0()
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    char szText[0x100];
    const int nIndex = pRecord->nIndex;
    SStrCopy(szText, sub_005180A0_GetNthString(pRecord, nIndex), 0x100);

    Unicode wszText[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, szText, 0x100);

    Unicode wszFormat[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszFormat[i].wChar = 0;
    sub_005267E0(wszFormat, D2LANG_GetStringFromTblIndex(0x2B29));

    Unicode wszOut[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszOut[i].wChar = 0;
    memset(wszOut, 0, 0x100);
    sub_005269D0(0x100, wszOut, wszFormat, wszText);

    for (int i = 0; i < sub_00526800(wszOut); ++i)
    {
        const unsigned short wChar = wszOut[i].wChar;
        wszOut[i].wChar = wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar;
    }

    sub_005009D0_SetValue(gpControl_007795AC, 10, wszOut, 0);
}

// 0x00431C90
int __stdcall sub_00431C90_PollSystemPacket(int nUnused)
{
    unsigned char pBuffer[0x200];
    if (CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer)) != -1)
    {
        switch (pBuffer[0])
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            sub_004F9190();
            return 1;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }

    if (gdwGlobal_00779990 || gdwGlobal_00779974)
        sub_004F9190();

    return 1;
}

// 0x0043C750
void __fastcall sub_0043C750(const char* szCharName, const char* szSubdirectory)
{
    char szDir[0x104];
    D2FindDataStrc tFind;
    char szTemp[0x104];
    char szPath[500];
    char szMask[500];

    D2_ASSERT(szCharName[0], 0xAF);

    sub_00407050_GetSavePath(szDir, 0x104);
    if (szSubdirectory && szSubdirectory[0])
    {
        SStrPrintf(szTemp, 0x104, "%s%s\\", szDir, szSubdirectory);
        sub_00406A10_CreateDirectoryTree(szTemp);
        SStrCopy(szDir, szTemp, 0x104);
    }

    sprintf(szMask, "%s%s.*", szDir, szCharName);
    void* hFind = FindFirstFileA(szMask, &tFind);
    while (hFind != (void*)-1)
    {
        sprintf(szPath, "%s%s", szDir, tFind.cFileName);
        if (GetFileAttributesA(szPath) & 0x10)
        {
            if (!FindNextFileA(hFind, &tFind))
                return;
        }
        else
        {
            if (!DeleteFileA(szPath))
                return;
            hFind = FindFirstFileA(szMask, &tFind);
        }
    }
}

// 0x0043E900
int __stdcall sub_0043E900_FindCdKeyInText(const char* szText)
{
    char szKey[0x400];
    int nCount = 0;
    const int nLength = SStrLen(szText);
    for (int i = 0; i < nLength; ++i)
    {
        if (nLength - i < 16 - nCount)
            return 0;

        const char c = szText[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            szKey[nCount++] = c;
        }
        else if (c != '-' && c != ' ')
        {
            nCount = 0;
            continue;
        }

        if (nCount == 16)
        {
            unsigned int nProduct;
            unsigned int nValue;
            szKey[16] = 0;
            if (sub_00449920_DecodeCdKey(szKey, &nProduct, &nValue)
                && (nProduct == 6 || nProduct == 7 || nProduct == 10 || nProduct == 12))
                return 1;
            nCount = 0;
        }
    }
    return 0;
}

D2LaunchDoneFn gpfnGatewayDone_007795BC; // 0x007795BC

// 0x004330A0
static int __stdcall sub_004330A0_SetMultilineText(D2WinControlStrc* pControl, int nArg, const Unicode* pText, bool bWrapped)
{
    Unicode aBuffer[0x400];
    for (int i = 0; i < 0x400; ++i)
        aBuffer[i].wChar = 0;
    sub_00526790(aBuffer, pText, 0x400);
    Unicode* pChar = aBuffer;
    Unicode* pLine = pChar;
    while (pChar->wChar)
    {
        if (pChar->wChar == 0xA)
        {
            pChar->wChar = 0;
            D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
            pLine = pChar + 1;
        }
        ++pChar;
    }
    if (pLine < pChar)
        D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
    return 1;
}

// 0x00433130
void __fastcall sub_00433130_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xE7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xE8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xE9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText1, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xEA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x004331C0
void __fastcall sub_004331C0_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xEB);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xEC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xED);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText1, false);
    if (pText3 && pText3->wChar)
    {
        pControl = sub_0042F3A0_CreateFromTemplate(0xEF);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
        pControl = sub_0042F3A0_CreateFromTemplate(0xF0);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004330A0_SetMultilineText(pControl, 4, pText3, false);
        gpfnGatewayDone_007795BC = pfnDone;
        return;
    }
    pControl = sub_0042F3A0_CreateFromTemplate(0xEE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x004332B0
void __fastcall sub_004332B0_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xF1);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xF2);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText1, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF5);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText3, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF6);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 4, pText4, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00433380
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    D2WinControlStrc* pFrame;
    D2WinControlStrc* pButton;
    D2WinControlStrc* pTextBox;
    sub_0042F3F0_DestroyControls();
    if (gbFeCharPalette_007795F0)
    {
        pFrame = sub_0042F3A0_CreateFromTemplate(0xF7);
        D2Win_10033(pFrame, 1);
        pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xF8 : 0xFA);
        pTextBox = sub_0042F3A0_CreateFromTemplate(0xF9);
    }
    else
    {
        pFrame = sub_0042F3A0_CreateFromTemplate(0xDE);
        D2Win_10033(pFrame, 1);
        pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
        pTextBox = sub_0042F3A0_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    sub_004330A0_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00433460
void __fastcall sub_00433460_ShowTextBox(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xF7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xFA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00435180
void __fastcall sub_00435180_ShowMessage2(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pFrame = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pFrame, 1);
    D2WinControlStrc* pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
    D2WinControlStrc* pTextBox = sub_0042F3A0_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    sub_004330A0_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00433810
int __cdecl sub_00433810_ShowTerms()
{
    char szLanguage[128];
    Unicode wszLine[200];
    char szFileName[128];
    gnCancelled = 0;
    sub_0042F800();
    sub_00525260(szLanguage, 2);
    SStrCopy(szFileName, gszTosPrefix, 128);
    SStrPack(szFileName, szLanguage, 128);
    SStrPack(szFileName, gszTextExt, 128);
    gpFuncTable->pfnRequest(szFileName, strlen(szFileName));
    sub_004FA590(sub_00430400_PollSlot4C);
    if (gnCancelled) { sub_0042F3F0_DestroyControls(); return 0; }
    if (!gpFuncTable->pfnAvailable())
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x14E3);
        sub_00433380_ShowMessage(pMessage, sub_004336C0_ShowMainMenu, 1);
        return 0;
    }
    sub_0042F3F0_DestroyControls();
    sub_00430390_CreateScreenControls();
    sub_0042F430_CreateControl(0x4D);
    D2WinControlStrc* pText = sub_0042F430_CreateControl(0x4E);
    void* hFile = sub_00406960_CreateFile(szFileName, 0x80000000, 0, 0, 3, 0x08000000, 0);
    if (hFile == (void*)-1)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x14E3);
        sub_00433380_ShowMessage(pMessage, sub_004336C0_ShowMainMenu, 1);
        return 0;
    }
    unsigned long nSize = GetFileSize(hFile, 0);
    void* pBuffer = FOG_Alloc(nSize, gszMainMenus, 0xC4D, 0);
    unsigned long nRead;
    sub_004069B0_ReadFile(hFile, pBuffer, nSize, &nRead, 0);
    sub_004069A0_CloseFile(hFile);
    sub_00406990_DeleteFile(szFileName);
    Unicode* pChars = 0;
    int nCount;
    if (nSize == nRead && nSize > 2)
    {
        if (*(unsigned short*)pBuffer == 0xFEFF)
        {
            pChars = (Unicode*)pBuffer + 1;
            nCount = (nSize - 2) / 2;
        }
        else if (*(unsigned short*)pBuffer == 0xFFFE)
        {
            pChars = (Unicode*)pBuffer + 1;
            nCount = (nSize - 2) / 2;
            sub_0042E5D0_SwapUnicode(pChars, nCount);
        }
        else
        {
            pChars = (Unicode*)FOG_Alloc(2*nSize+1, gszMainMenus, 0xC6B, 0);
            win2Unicode(pChars, (const char*)pBuffer, nSize);
            FOG_Free(pBuffer, gszMainMenus, 0xC6D, 0);
            pBuffer = pChars;
            nCount = nSize;
        }
    }
    else nCount = 0;
    int nStart = 0;
    int i = 0;
    while (i < nCount)
    {
        memset(wszLine, 0, sizeof(wszLine));
        int nLine = 0;
        do
        {
            if (i >= nCount) break;
            const unsigned short nChar = pChars[i].wChar;
            if (nChar == '\r' || nChar == '\n') { wszLine[nLine].wChar = ' '; nLine = 200; ++i; }
            else if (nChar != '\t') { wszLine[nLine++].wChar = nChar; ++i; }
            else { ++i; wszLine[nLine++].wChar = ' '; }
            if (sub_00501820(wszLine) > 540)
            {
                int nLength = sub_00526800(wszLine);
                while (nLength > 1 && !sub_00526D30_IsLineBreak(pChars + nStart, nLength)) --nLength;
                i = nStart + nLength;
                wszLine[nLength].wChar = 0;
                if (nLength && wszLine[nLength - 1].wChar == ' ') wszLine[nLength - 1].wChar = 0;
                break;
            }
        } while (nLine < 200);
        int nLength = sub_00526800(wszLine);
        for (int j = 0; j < nLength; ++j)
        {
            if (wszLine[j].wChar != ' ')
            {
                D2Win_10051(pText, wszLine, 0, 0, 0);
                break;
            }
        }
        nStart = i;
    }
    FOG_Free(pBuffer, gszMainMenus, 0xCB4, 0);
    D2Win_10053(pText, 0);
    sub_0042F430_CreateControl(0x4F);
    sub_0042F430_CreateControl(0x50);
    pText = sub_0042F430_CreateControl(0x51);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x143C), 0, 0, 0);
    sub_0042F430_CreateControl(0x52);
    sub_0042F430_CreateControl(0x53);
    return 1;
}

#include "gen/data/Source/D2Launch/Src/MainMenus_00431AF0.inc"

D2WinControlStrc* gpControl_00779348; // 0x00779348

D2WinControlStrc* gpControl_00779568; // 0x00779568

D2WinControlStrc* gpControl_00779598; // 0x00779598

D2WinControlStrc* gpControl_007795B4; // 0x007795B4

D2WinControlStrc* gpControl_007795C8; // 0x007795C8

// 0x00431E70
static void sub_00431E70_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;
    if (nMode == 0) gpLaunchRecord_007795D4->nFlag085 = 1;
    else if (nMode == 4) gpLaunchRecord_007795D4->nFlag089 = 1;
    else if (nMode == 2) gpLaunchRecord_007795D4->nFlag088 = 1;
    else if (nMode == 3) gpLaunchRecord_007795D4->nFlag086 = 1;
    else if (nMode == 1) gpLaunchRecord_007795D4->nFlag087 = 1;
    else if (nMode == 5) gpLaunchRecord_007795D4->nFlag08A = 1;
    else if (nMode == 6) gpLaunchRecord_007795D4->nFlag08B = 1;
}

// 0x00433BF0
int __stdcall sub_00433BF0_SelectCharacterClass(D2MenuCallbackArgStrc* pArg)
{
    int nImageState = sub_00500310_GetAnimImageField50(pArg->pControl);
    if (sub_00408F20_HasExpansionMpq())
    {
        for (int i = 0; i < 7; ++i)
            if (!D2Win_10104(gpClassImages_0077956C[i])) return 0;
    }
    else
    {
        for (int i = 0; i < 5; ++i)
            if (!D2Win_10104(gpClassImages_0077956C[i])) return 0;
    }
    int nPreviousClass = gnTextSentinel_0070CB80;
    int nClass = -1;
    gnTextSentinel_0070CB80 = -1;
    if (nPreviousClass != -1)
    {
        sub_00515020_FadeOutWaves();
        switch (nPreviousClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon deselect.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian deselect.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin deselect.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer deselect.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress deselect.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid deselect.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin deselect.wav"); break;
        }
    }
    if (pArg->pControl == gpClassImages_0077956C[0])
    {
        nClass = 4;
        sub_004307A0(pArg->nArg, 4, 0xFA7, 0x140A);
    }
    else if (pArg->pControl == gpClassImages_0077956C[1])
    {
        nClass = 2;
        sub_004307A0(pArg->nArg, 2, 0xFA9, 0x1409);
    }
    else if (pArg->pControl == gpClassImages_0077956C[2])
    {
        nClass = 0;
        sub_004307A0(pArg->nArg, 0, 0xFAB, 0x1408);
    }
    else if (pArg->pControl == gpClassImages_0077956C[3])
    {
        nClass = 1;
        sub_004307A0(pArg->nArg, 1, 0xFAA, 0x140B);
    }
    else if (pArg->pControl == gpClassImages_0077956C[4])
    {
        nClass = 3;
        sub_004307A0(pArg->nArg, 3, 0xFA8, 0x140C);
    }
    else if (pArg->pControl == gpClassImages_0077956C[5])
    {
        nClass = 5;
        sub_004308E0_ExpansionNotice5(pArg);
    }
    else if (pArg->pControl == gpClassImages_0077956C[6])
    {
        nClass = 6;
        sub_004308A0_ExpansionNotice6(pArg);
    }
    if (nClass != nPreviousClass && nImageState == 1)
    {
        switch (nClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon select.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian select.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin select.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer select.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress select.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin select.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid select.wav"); break;
        }
        gnTextSentinel_0070CB80 = nClass;
    }
    else if (nImageState != 2 && nImageState != 3 && nImageState != 4)
        gnTextSentinel_0070CB80 = nClass;
    sub_00431E70_SetModeFlags((char)gnTextSentinel_0070CB80);
    if (gnTextSentinel_0070CB80 == -1 && nImageState != 1)
    {
        sub_004F9740(gpControl_00779598, 0);
        sub_004F9740(gpControl_007795CC, 0);
        sub_004F9740(gpControl_007795B0, 0);
        sub_004F9740(gpControl_007795C4, 0);
        sub_004F9740(gpControl_0077934C, 0);
        sub_004F9740(gpControl_00779330, 0);
        if (gnLaunchMode_007795EC == 1)
        {
            sub_004F9740(gpControl_007795B8, 0);
            sub_004F9740(gpControl_00779348, 0);
        }
        if (sub_00408F20_HasExpansionMpq())
        {
            sub_004F9740(gpControl_00779568, 0);
            sub_004F9740(gpControl_007795C8, 0);
            sub_004F9740(gpControl_007795B4, 0);
        }
        sub_004F91C0(0);
        if (gnLaunchMode_007795EC == 1) sub_004F9740(gpControl_0077933C, 1);
    }
    else
    {
        sub_004F9740(gpControl_00779598, 1);
        sub_004F9740(gpControl_007795CC, 1);
        if (gdwGlobal_00779DA4)
        {
            sub_004F9740(gpControl_007795B0, 1);
            sub_004F9740(gpControl_007795C4, 1);
        }
        if (gnLaunchMode_007795EC == 1)
        {
            sub_004F9740(gpControl_007795B8, 1);
            sub_004F9740(gpControl_00779348, 1);
        }
        sub_004F9740(gpControl_0077934C, 1);
        sub_004F91C0(gpControl_0077934C);
        sub_004F9740(gpControl_00779330, 1);
        if (gnLaunchMode_007795EC == 1) sub_004F9740(gpControl_0077933C, 0);
    }
    if (sub_00408F20_HasExpansionMpq())
    {
        if (gnTextSentinel_0070CB80 == 6 || gnTextSentinel_0070CB80 == 5)
        {
            sub_004F9740(gpControl_00779568, 1);
            sub_004F9740(gpControl_007795C8, 0);
            sub_004F9740(gpControl_007795B4, 1);
            gpLaunchRecord_007795D4->nFlags |= 0x20;
        }
        else if (gnTextSentinel_0070CB80 != -1)
        {
            sub_004F9740(gpControl_00779568, 1);
            sub_004F9740(gpControl_007795C8, 1);
            sub_004F9740(gpControl_007795B4, 0);
            BUTTON_SetIsPressed(gpControl_007795C8, 1);
            gpLaunchRecord_007795D4->nFlags |= 0x20;
        }
    }
    if (gnLaunchMode_007795EC == 1)
    {
        BUTTON_SetIsPressed(gpControl_00779348, 1);
        gpLaunchRecord_007795D4->nFlags |= 0x40;
    }
    return 1;
}
