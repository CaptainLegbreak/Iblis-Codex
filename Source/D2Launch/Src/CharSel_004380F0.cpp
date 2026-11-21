#include "D2Unicode.h"
struct D2WinControlStrc;
struct D2CompositeUnitStrc;

struct D2CompositeUnitStrc;
struct D2CelFileStrc;

struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
};

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
#pragma intrinsic(strcat, strlen)

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB);                                      // 0x004FB740
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall D2Win_10046(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0
void __stdcall D2Win_10152(D2CompositeUnitStrc* pCompositeUnit, int nX);                              // 0x005052B0
void __stdcall D2Win_10153(D2CompositeUnitStrc* pCompositeUnit, int nY);                              // 0x005052F0
void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags);                                // 0x00505360
const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

extern const int gnFlagSet0_006CE278;                                                                       // 0x006CE278
extern const int gnFlagSet1_006CE27C;                                                                       // 0x006CE27C
extern const int gnFlagClear0_006CE2F8;                                                                     // 0x006CE2F8
extern const int gnFlagClear1_006CE2FC;                                                                     // 0x006CE2FC
extern int gnVisibleRows_0070CC0C;                                                                          // 0x0070CC0C
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
int gnListTop_007799FC;                                                                                     // 0x007799FC
extern D2WinControlStrc* gapRowControls_00779A20[];                                                         // 0x00779A20
extern int gnState_00779DAC;                                                                                // 0x00779DAC
extern D2LaunchCharEntryStrc* gpCharList_00779DBC;                                                          // 0x00779DBC
extern int gnTopRow_00779DC8;                                                                               // 0x00779DC8
extern D2WinControlStrc* gpControl_00779DD0;                                                                // 0x00779DD0

static __declspec(noinline) Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass);
static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass);                                    // 0x00437F60

static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}

static __forceinline unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

// 0x004380F0
void __cdecl sub_004380F0_UpdateCharList()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    int nY = gnListTop_007799FC - 13;
    int nX = 0x25;
    int nIndex = 0;

    for (int i = 0; i < gnVisibleRows_0070CC0C; ++i)
    {
        sub_004FB6A0_ClearText(gapRowControls_00779A20[i]);
        switch (STRTABLE_GetLanguage())
        {
        case 7:
            sub_004FB740(gapRowControls_00779A20[i], -1, -7);
            break;
        case 6:
        case 9:
        case 10:
            sub_004FB740(gapRowControls_00779A20[i], -1, -2);
            break;
        }
    }

    if (gpControl_00779DD0)
    {
        sub_004FB6A0_ClearText(gpControl_00779DD0);
    }

    if (gnLaunchMode_007795EC == 1 && gnState_00779DAC)
    {
        return;
    }

    while (pEntry)
    {
        if (nIndex >= gnTopRow_00779DC8 && nIndex < gnTopRow_00779DC8 + gnVisibleRows_0070CC0C)
        {
            const int nRow = nIndex - gnTopRow_00779DC8;
            D2Win_10152(pEntry->pCompositeUnit, nX + 30);
            D2Win_10153(pEntry->pCompositeUnit, nY);

            const int bHardcore = pEntry->wFlags & 4;
            int nFlags = 1;
            if (pEntry->wFlags & 8)
            {
                nFlags |= gnFlagSet0_006CE278;
            }
            else
            {
                nFlags &= gnFlagClear0_006CE2F8;
            }
            if (bHardcore)
            {
                nFlags |= gnFlagSet1_006CE27C;
            }
            else
            {
                nFlags &= gnFlagClear1_006CE2FC;
            }
            D2Win_10156(pEntry->pCompositeUnit, nFlags);

            if (pEntry->nState == 2)
            {
                D2Win_10051(gapRowControls_00779A20[nRow], D2LANG_GetStringFromTblIndex(0x2B3B), 1, 0, 0);
            }
            else if (!pEntry->nState)
            {
                const int nClass = pEntry->nType;
                char szName[100];
                Unicode wszClass[100];
                szName[0] = 0;
                for (int j = 0; j < 100; ++j)
                {
                    wszClass[j].wChar = 0;
                }

                const char* szTitle = D2Win_10161(nClass, (pEntry->wFlags >> 8) & 0x1F, bHardcore, pEntry->wFlags & 0x20);
                if (szTitle)
                {
                    int nColor;
                    if (bHardcore)
                    {
                        nColor = 1;
                    }
                    else
                    {
                        nColor = 4;
                    }
                    D2Win_10046(gapRowControls_00779A20[nRow], szTitle, nColor);
                }

                strcat(szName, pEntry->szName);
                if (strlen(pEntry->szCode32A))
                {
                    sprintf(&szName[strlen(szName)], " {%s}", pEntry->szCode32A);
                }
                D2Win_10046(gapRowControls_00779A20[nRow], szName, bHardcore ? 1 : 4);

                sub_00437F60_GetClassName(wszClass, pEntry->nType);

                Unicode wszText[100];
                for (int j = 0; j < 100; ++j)
                {
                    wszText[j].wChar = 0;
                }
                Unicode wszLevel[10];
                wszLevel[0].wChar = 0;
                wszLevel[1].wChar = 0;
                wszLevel[2].wChar = 0;
                wszLevel[3].wChar = 0;
                wszLevel[4].wChar = 0;
                wszLevel[5].wChar = 0;
                wszLevel[6].wChar = 0;
                wszLevel[7].wChar = 0;
                wszLevel[8].wChar = 0;
                wszLevel[9].wChar = 0;
                sprintf(szName, " %d ", pEntry->nLevel);
                sub_00526F20_ToUnicode(wszLevel, szName, 9);
                sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xFD9));
                sub_00526700(wszText, wszLevel);
                sub_00526700(wszText, wszClass);
                D2Win_10051(gapRowControls_00779A20[nRow], wszText, 0, 0, 0);

                if (pEntry->wFlags & 0x20)
                {
                    D2Win_10051(gapRowControls_00779A20[nRow], D2LANG_GetStringFromTblIndex(0x58CB), 2, 0, 0);
                }
                if (pEntry->nByte32E)
                {
                    D2Win_10051(gapRowControls_00779A20[nRow], D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
                }

                const unsigned int nDays = sub_004380B0_GetDaysLeft(pEntry->nExpireTime);
                if (gnLaunchMode_007795EC == 1 && nDays <= 60)
                {
                    int nColor = 1;
                    unsigned short nString;
                    if (!nDays)
                    {
                        nString = 0x2B7E;
                    }
                    else if (nDays < 2)
                    {
                        nString = 0x2B7C;
                    }
                    else
                    {
                        nString = 0x2B7D;
                        if (nDays >= 15)
                        {
                            nColor = 0;
                        }
                    }
                    sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(nString), nDays);
                    D2Win_10051(gapRowControls_00779A20[nRow], wszText, nColor, 0, 0);
                }
            }

            if (nX == 0x25)
            {
                nX = 0x135;
            }
            else
            {
                nY += 0x5D;
                nX = 0x25;
            }
        }
        else
        {
            D2Win_10156(pEntry->pCompositeUnit, 0);
        }

        pEntry = pEntry->pNext;
        ++nIndex;
    }
}

#include "gen/data/Source/D2Launch/Src/CharSel_004380F0.inc"
