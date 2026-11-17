struct D2AutomapRecordStrc
{
    unsigned int nUnk0x00;
    unsigned int nValue;
};

struct D2AutomapFileHeaderStrc
{
    int nVersion;
    int nNext;
    unsigned int nSeeds[4];
};

typedef char D2AutomapFileHeaderSizeCheck[sizeof(D2AutomapFileHeaderStrc) == 0x18 ? 1 : -1];

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile);
int __fastcall sub_00406990_DeleteFile(const char* szFileName);
int __fastcall sub_004069A0_CloseFile(void* hFile);
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped);
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped);
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod);
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);
char gszAccountFolder_007A0500[32];                                                                         // 0x007A0500
extern char gszCharName_007A05C4[];                                                                         // 0x007A05C4
extern D2AutomapRecordStrc* gpAutomapRecord_007A0638;                                                       // 0x007A0638

// 0x00457F40
void* __cdecl sub_00457F40_OpenAutomapFile()
{
    char szSavePath[0x104] = { 0 };
    char szFileName[0x104] = { 0 };
    char szAccountPath[0x104] = { 0 };

    sub_00407050_GetSavePath(szSavePath, sizeof(szSavePath));

    void* hFile = (void*)-1;
    if (gszAccountFolder_007A0500[0])
    {
        SStrPrintf(szAccountPath, sizeof(szAccountPath), "%s%s\\", szSavePath, gszAccountFolder_007A0500);
        sub_00406A10_CreateDirectoryTree(szAccountPath);
        SStrPrintf(szFileName, sizeof(szFileName), "%s%s.map", szAccountPath, gszCharName_007A05C4);
        hFile = sub_00406960_CreateFile(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (hFile != (void*)-1)
        {
            SStrCopy(szSavePath, szAccountPath, sizeof(szSavePath));
        }
    }

    if (hFile == (void*)-1)
    {
        sprintf(szFileName, "%s%s.map", szSavePath, gszCharName_007A05C4);
        hFile = sub_00406960_CreateFile(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (hFile == (void*)-1)
        {
            return hFile;
        }
    }

    D2AutomapFileHeaderStrc tHeader = { 0 };
    unsigned long nBytes = 0;
    sub_004069B0_ReadFile(hFile, &tHeader, sizeof(tHeader), &nBytes, 0);

    int bInvalid = 1;
    if (nBytes == sizeof(tHeader))
    {
        bInvalid = tHeader.nVersion != 12;
    }

    int nIndex;
    if (bInvalid)
    {
        tHeader.nVersion = 12;
        tHeader.nNext = 1;
        tHeader.nSeeds[0] = gpAutomapRecord_007A0638->nUnk0x00;
        for (int i = 0; i < 4; ++i)
        {
            sprintf(szFileName, "%s%s.ma%d", szSavePath, gszCharName_007A05C4, i);
            sub_00406990_DeleteFile(szFileName);
        }
        nIndex = 0;
    }
    else
    {
        for (nIndex = 0; nIndex < 4; ++nIndex)
        {
            if (tHeader.nSeeds[nIndex] == gpAutomapRecord_007A0638->nUnk0x00)
            {
                break;
            }
        }

        if (nIndex != 4)
        {
            goto reopen;
        }

        nIndex = tHeader.nNext;
        tHeader.nNext = (nIndex + 1) % 4;
        tHeader.nSeeds[nIndex] = gpAutomapRecord_007A0638->nUnk0x00;
        sprintf(szFileName, "%s%s.ma%d", szSavePath, gszCharName_007A05C4, nIndex);
        sub_00406990_DeleteFile(szFileName);
    }

    sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
    sub_004069D0_WriteFile(hFile, &tHeader, sizeof(tHeader), &nBytes, 0);

reopen:
    sub_004069A0_CloseFile(hFile);
    sprintf(szFileName, "%s%s.ma%d", szSavePath, gszCharName_007A05C4, nIndex);
    return sub_00406960_CreateFile(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
}
