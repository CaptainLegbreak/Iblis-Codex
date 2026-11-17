struct D2ActiveRoomStrc;
struct D2DrlgActStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2KeyConfigFileStrc
{
    unsigned short wTag;
    unsigned short wVersion;
    unsigned short wSize;
    unsigned char aBody[0x474];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef unsigned int size_t;
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int a2, int a3);                    // 0x00619DA0
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
void __fastcall FOG_GetInstallPath(char* szPath, int nBufferSize);                                          // 0x00406BA0
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
void __fastcall sub_004069A0_CloseFile(void* hFile);                                                        // 0x004069A0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __stdcall sub_004FAC80();                                                                             // 0x004FAC80
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
int __cdecl sub_00410A80_GetTime();                                                                         // 0x00410A80
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70
extern D2DrlgActStrc* gpGlobal_007A0634;                                                                    // 0x007A0634
extern "C" const char szDataLocal_006D41A8[];                                                               // 0x006D41A8
extern unsigned char gaKeyTable_00712220[0x474];                                                            // 0x00712220
extern int gnTimerEnd_007A7464;                                                                             // 0x007A7464
extern int gnTimerUnitId_007129D4;                                                                          // 0x007129D4
extern int gnGlobal_0071146C;                                                                               // 0x0071146C

// 0x00465420
D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomBySubtile(int nX, int nY)
{
    char szMessage[0x200];
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    D2ActiveRoomStrc* pRoom = 0;
    if (!nX && !nY)
        return 0;
    if (pPlayer)
    {
        pRoom = UNITS_GetRoom(pPlayer);
        D2ActiveRoomStrc* pFound = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
        if (pFound)
            return pFound;
    }
    D2ActiveRoomStrc* pFound = sub_00619DA0_ActLookup(gpGlobal_007A0634, nX, nY);
    if (pFound)
        return pFound;
    SStrPrintf(szMessage, sizeof(szMessage), "Unable to find room for unit...  hControlUnit:%8x  hUnitRoom:%8x  ghAct:%8x  nX:%d  nY:%d", pPlayer, pRoom, gpGlobal_007A0634, nX, nY);
    D2_ASSERT(0, 0x13C);
}

// 0x004698D0
void __stdcall sub_004698D0_LoadKeyConfig(int bInstallDir)
{
    char szLang[4];
    char szPath[0x104];
    D2KeyConfigFileStrc tFile;
    sub_00525260(szLang, 0);
    void* pData;
    int bLoaded = 0;
    if (bInstallDir)
    {
        FOG_GetInstallPath(szPath, 0xDC);
        strcat(szPath, "default.key");
        void* hFile = sub_00406960_CreateFile(szPath, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile != (void*)-1)
        {
            unsigned long nRead;
            sub_004069B0_ReadFile(hFile, &tFile, sizeof(tFile), &nRead, 0);
            sub_004069A0_CloseFile(hFile);
            if (nRead == sizeof(tFile))
            {
                pData = FOG_AllocPool(0, sizeof(tFile), ".\\UI\\CmdTbl.cpp", 0x50F, 0);
                memcpy(pData, &tFile, sizeof(tFile));
                bLoaded = 1;
            }
        }
    }
    if (!bLoaded)
    {
        sprintf(szPath, "%s\\CMD\\%s\\default.key", szDataLocal_006D41A8, szLang);
        pData = sub_00517079_LoadFile(sub_004FAC80(), szPath, 0, ".\\UI\\CmdTbl.cpp", 0x51E);
    }
    if (!pData)
        return;
    D2KeyConfigFileStrc* pFile = (D2KeyConfigFileStrc*)pData;
    if (pFile->wTag == 0x5357 && pFile->wVersion == 0x25 && pFile->wSize == sizeof(D2KeyConfigFileStrc))
    {
        memcpy(gaKeyTable_00712220, pFile->aBody, sizeof(gaKeyTable_00712220));
        FOG_Free(pData, ".\\UI\\CmdTbl.cpp", 0x52C, 0);
        return;
    }
    FOG_Free(pData, ".\\UI\\CmdTbl.cpp", 0x531, 0);
}

// 0x0046C060
void __cdecl sub_0046C060_DrawCountdown()
{
    Unicode wszText[256];
    const int nNow = sub_00410A80_GetTime();
    if (!gnTimerEnd_007A7464 || gnTimerEnd_007A7464 <= nNow)
        return;
    D2UnitStrc* pUnit = sub_00463990(gnTimerUnitId_007129D4, 1);
    if (pUnit && pUnit->dwAnimMode != 12 && gnTimerEnd_007A7464 - 0x46 > nNow)
        return;
    for (int i = 0; i < 256; ++i)
        wszText[i].wChar = 0;
    sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x13E9), gnTimerEnd_007A7464 - nNow);
    const int nOldFont = sub_00502EF0(13);
    const int nWidth = sub_00501820(wszText);
    sub_00502320(wszText, gnGlobal_0071146C / 2 - nWidth / 2, 0x177, 9, 1);
    sub_00502EF0(nOldFont);
}

#include "gen/data/Source/D2Client/00465420_sub_00465420_FindRoomBySubtile.inc"
