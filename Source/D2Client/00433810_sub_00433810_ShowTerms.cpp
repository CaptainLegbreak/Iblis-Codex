struct Unicode { unsigned short wChar; };
struct D2WinControlStrc;
typedef void (__cdecl* D2LaunchDoneFn)();
struct D2FuncTable { char unk00[0x50]; void (__fastcall* pfnRequest)(const char*, int); char unk54[0x14]; int (__cdecl* pfnAvailable)(); };
extern D2FuncTable* gpFuncTable; // 0x0077ABF0
extern int gnCancelled; // 0x0077932C
extern const char gszMainMenus[]; // 0x006D41C0
extern const char gszTextExt[]; // 0x006D48E0
extern const char gszTosPrefix[]; // 0x006D48E8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void*, unsigned long*); // 0x006CC2F0
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
void __cdecl sub_0042F800(); // 0x0042F800
void __stdcall sub_00525260(char*, int); // 0x00525260
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0
unsigned int __stdcall sub_00413800(char*, const char*, unsigned int); // 0x00413800
void __cdecl sub_00430400_PollSlot4C(); // 0x00430400
void __stdcall sub_004FA590(D2LaunchDoneFn); // 0x004FA590
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30
void __cdecl sub_004336C0_ShowMainMenu(); // 0x004336C0
void __fastcall sub_00433380_ShowMessage(const Unicode*, D2LaunchDoneFn, int); // 0x00433380
void __cdecl sub_00430390_CreateScreenControls(); // 0x00430390
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int); // 0x0042F430
void* __fastcall sub_00406960_CreateFile(const char*, unsigned long, unsigned long, void*, unsigned long, unsigned long, void*); // 0x00406960
int __fastcall sub_004069B0_ReadFile(void*, void*, unsigned long, unsigned long*, void*); // 0x004069B0
int __fastcall sub_004069A0_CloseFile(void*); // 0x004069A0
int __fastcall sub_00406990_DeleteFile(const char*); // 0x00406990
void* __fastcall FOG_Alloc(unsigned int, const char*, int, int); // 0x0040B380
void __fastcall FOG_Free(void*, const char*, int, int); // 0x0040B3C0
void __fastcall sub_0042E5D0_SwapUnicode(Unicode*, unsigned int); // 0x0042E5D0
Unicode* __fastcall win2Unicode(Unicode*, const char*, int); // 0x00526F20
int __fastcall sub_00501820(const Unicode*); // 0x00501820
int __fastcall sub_00526800(const Unicode*); // 0x00526800
int __fastcall sub_00526D30_IsBreak(const Unicode*, int); // 0x00526D30
int __fastcall D2Win_10051(D2WinControlStrc*, const Unicode*, int, char, int); // 0x004FC9B0
void __fastcall D2Win_10053(D2WinControlStrc*, int); // 0x004FBA30
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
    sub_00413800(szFileName, szLanguage, 128);
    sub_00413800(szFileName, gszTextExt, 128);
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
                while (nLength > 1 && !sub_00526D30_IsBreak(pChars + nStart, nLength)) --nLength;
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

#include "gen/data/Source/D2Client/00433810_sub_00433810_ShowTerms.inc"
