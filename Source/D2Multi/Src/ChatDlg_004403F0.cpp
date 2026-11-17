#include "D2Multi.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2LadderEntryStrc
{
    int nA;
    int nB;
    int dwFlags;
    char szName[1];
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
void __fastcall sub_00443F50_GetPlayerName(char* szName);                                                   // 0x00443F50
void __fastcall sub_004FB870_InsertRow(D2WinControlStrc* pControl, int nRow);                                // 0x004FB870
int __fastcall D2Win_10188(D2WinControlStrc* pTextBox, int nLineNum, int a3);                               // 0x004FBDE0
void __fastcall sub_004FCD90_SetCellW(D2WinControlStrc* pControl, const Unicode* wszText, int nRow, int nColumn); // 0x004FCD90
const char* __stdcall sub_005068A0(int nA, int nB, int nC, int nD);                                         // 0x005068A0
void __stdcall sub_005255C0_FormatDate(Unicode* wszOut, int nA, int nB, int nMaxLength);                   // 0x005255C0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20

extern "C" const char* const gaszClassNames_006D5524[];                                                     // 0x006D5524
extern unsigned char gnSelectModeA_0070CD62;                                                                // 0x0070CD62
extern int gnColor_0077AD74;                                                                                // 0x0077AD74
char gszSelectName_0077B040[16];                                                                            // 0x0077B040
extern int gnSelection_0077BBF4;                                                                            // 0x0077BBF4
D2WinControlStrc* gpList_0077BD00;                                                                          // 0x0077BD00

// 0x004403F0
void __fastcall sub_004403F0_OnListEvent(int nStart, int nCount, int nNameLength, unsigned char nMode, D2LadderEntryStrc* pEntries)
{
    if (!gpList_0077BD00)
    {
        return;
    }

    char szTitle[256];
    char szNumber[256];
    if (!nCount)
    {
        Unicode wszText[256];
        {
            Unicode wszFormat[256];
            Unicode wszName[256];
            char szName[256];
            sub_00443F50_GetPlayerName(szName);
            sub_00526F20_ToUnicode(wszFormat, "Player '%s' is not on the ladder.", 0x100);
            sub_00526F20_ToUnicode(wszName, szName, 0x100);
            sub_005269D0(0x100, wszText, wszFormat, wszName);
        }

        sub_0043FB50_ShowWait(wszText, 0);
        return;
    }

    if (nMode != gnSelectModeA_0070CD62)
    {
        return;
    }

    if (gnSelectIdA_0070CD7C == -1)
    {
        D2Win_10053(gpList_0077BD00, nStart);
        gnSelectIdB_0070CD80 = nStart;
        gnSelection_0077BBF4 = nStart;
        gnSelectIdA_0070CD7C = nStart;
    }

    int nEnd = nStart + nCount;
    if (nEnd > gnColor_0077AD74)
    {
        nEnd = gnColor_0077AD74;
    }

    D2LadderEntryStrc* pEntry = pEntries;
    for (int i = nStart; i < nEnd; ++i)
    {
        const int dwFlags = pEntry->dwFlags;
        const int nClass = dwFlags & 0xF;
        const int nLevel = (dwFlags >> 16) & 0xFF;
        const int nColor = !strcmp(pEntry->szName, gszSelectName_0077B040) ? 0 : ((dwFlags & 0x10) ? 5 : 4);

        sub_004FB870_InsertRow(gpList_0077BD00, i);
        D2Win_10188(gpList_0077BD00, i, nColor);

        _itoa(i + 1, szNumber, 10);
        sub_004FCD40_SetCell(gpList_0077BD00, szNumber, i, 0);

        szTitle[0] = '\0';
        const char* szPrefix = sub_005068A0(nClass, ((unsigned int)dwFlags >> 8) & 0x1F, dwFlags & 0x20, dwFlags & 0x40);
        if (szPrefix)
        {
            strcat(szTitle, szPrefix);
        }

        strcat(szTitle, pEntry->szName);
        sub_004FCD40_SetCell(gpList_0077BD00, szTitle, i, 1);
        sub_004FCD40_SetCell(gpList_0077BD00, gaszClassNames_006D5524[nClass], i, 2);
        _itoa(nLevel, szNumber, 10);
        sub_004FCD40_SetCell(gpList_0077BD00, szNumber, i, 3);

        Unicode wszDate[256];
        sub_005255C0_FormatDate(wszDate, pEntry->nA, pEntry->nB, 0xFF);
        sub_004FCD90_SetCellW(gpList_0077BD00, wszDate, i, 4);

        pEntry = (D2LadderEntryStrc*)((char*)pEntry + nNameLength + 0xC);
    }
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_004403F0.inc"
