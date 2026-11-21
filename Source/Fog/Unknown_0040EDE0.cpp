#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl strcmp(const char* szA, const char* szB);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
_iobuf* __fastcall sub_0040EBD0_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize); // 0x0040EBD0
void __fastcall sub_0040ECC0_LogWriteHeader(_iobuf* pFile, const D2SystemTimeStrc* pTime);                 // 0x0040ECC0
void __fastcall sub_0040ED40_LogWriteStartup(_iobuf* pFile);                                                // 0x0040ED40

char gaszLogNames_0075D148[20][0x10];                                                                       // 0x0075D148
extern int ganLogNewFile_0075D298[20];                                                                      // 0x0075D298
unsigned long gadwLogWriteTick_0075D2F0[20];                                                                // 0x0075D2F0
extern char gaszLogFilePaths_0075D340[20][0x104];                                                           // 0x0075D340
_iobuf* gapLogFiles_0075E790[20];                                                                           // 0x0075E790
unsigned long gadwLogOpenTick_0075E7E0[20];                                                                 // 0x0075E7E0

// 0x0040EDE0
_iobuf* __fastcall sub_0040EDE0_GetLogFile(const char* szName, int* pnSlot)
{
    const unsigned long dwTick = GetTickCount();
    int nEmpty = -1;
    int nFree = -1;
    int nOldest;
    int nSlot = -1;
    _iobuf* pFile;

    int i = szName[0] != 0;
    nOldest = 1;
    for (; i < 20; ++i)
    {
        if (!strcmp(gaszLogNames_0075D148[i], szName))
        {
            nSlot = i;
            pFile = gapLogFiles_0075E790[i];
            if (pFile)
            {
                goto done;
            }
            break;
        }

        if (!gaszLogNames_0075D148[i][0])
        {
            if (nEmpty < 0)
            {
                nEmpty = i;
            }
        }
        else if (!gapLogFiles_0075E790[i])
        {
            if (nFree < 0)
            {
                nFree = i;
            }
            else if (dwTick - gadwLogWriteTick_0075D2F0[i] > gadwLogWriteTick_0075D2F0[nFree])
            {
                nFree = i;
            }
        }
        else if (dwTick - gadwLogWriteTick_0075D2F0[i] > dwTick - gadwLogWriteTick_0075D2F0[nOldest])
        {
            nOldest = i;
        }
    }

    if (nSlot < 0)
    {
        if (nEmpty >= 0)
        {
            nSlot = nEmpty;
        }
        else
        {
            if (nFree >= 0)
            {
                nOldest = nFree;
            }

            if (gapLogFiles_0075E790[nOldest])
            {
                fclose(gapLogFiles_0075E790[nOldest]);
                gapLogFiles_0075E790[nOldest] = 0;
            }

            nSlot = nOldest;
        }
    }

    {
        D2_ASSERT(SStrLen(szName) < 16, 0x34C);
        strcpy(gaszLogNames_0075D148[nSlot], szName);

        D2SystemTimeStrc tTime;
        int bNew;
        _iobuf* pNewFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "a", &bNew, gaszLogFilePaths_0075D340[nSlot], 0x104);
        gapLogFiles_0075E790[nSlot] = pNewFile;
        gadwLogOpenTick_0075E7E0[nSlot] = dwTick;
        gadwLogWriteTick_0075D2F0[nSlot] = dwTick;
        if (ganLogNewFile_0075D298[nSlot] && pNewFile)
        {
            sub_0040ED40_LogWriteStartup(pNewFile);
            ganLogNewFile_0075D298[nSlot] = 0;
        }
        else if (bNew)
        {
            sub_0040ECC0_LogWriteHeader(pNewFile, &tTime);
        }
    }

    pFile = gapLogFiles_0075E790[nSlot];

done:
    if (pFile && pnSlot)
    {
        *pnSlot = nSlot;
    }

    return pFile;
}
