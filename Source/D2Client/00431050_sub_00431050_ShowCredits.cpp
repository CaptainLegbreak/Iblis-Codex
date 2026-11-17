struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2WinControlStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2WinControlStrc* gpList_0077995C;                                                                   // 0x0077995C
extern D2WinControlStrc* gpList_00779960;                                                                   // 0x00779960
extern D2WinControlStrc* gpList_00779964;                                                                   // 0x00779964
extern "C" int __cdecl isalpha(int c);                                                                      // 0x00686DA5
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                     // 0x004FCF80
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                    // 0x004FD060
Unicode* __stdcall sub_00430CD0_LoadCreditsText(int* pnLength);                                             // 0x00430CD0
void __cdecl sub_00430C80_FillList();                                                                       // 0x00430C80
void __cdecl sub_00430EF0_SyncLists();                                                                      // 0x00430EF0

// 0x00431050
int __fastcall sub_00431050_ShowCredits(int nUnused)
{
    int nLength = 0;
    Unicode* pText = sub_00430CD0_LoadCreditsText(&nLength);
    Unicode wszLine[1024];
    D2_ASSERT(pText, 0x141B);

    for (int i = 0; i < 50; ++i)
    {
        sub_004FCF80_SetTextA(gpList_00779964, &gszEmptyAssertText);
        sub_004FCF80_SetTextA(gpList_0077995C, &gszEmptyAssertText);
        sub_004FCF80_SetTextA(gpList_00779960, &gszEmptyAssertText);
    }

    int nRemain = nLength;
    Unicode* pCursor = pText;
    while (nRemain)
    {
        if (pCursor->wChar == 0x2A)
        {
            sub_004FCF80_SetTextA(gpList_0077995C, &gszEmptyAssertText);
            sub_004FCF80_SetTextA(gpList_00779960, &gszEmptyAssertText);
            ++pCursor;
            if (sub_005267E0(wszLine, pCursor))
                sub_004FC9B0_SetText(gpList_00779964, wszLine, 1, 0, 0);
            else
                nRemain = 0;
            int nSkip = sub_00526800(wszLine) + 2;
            nRemain -= nSkip;
            pCursor += nSkip;
        }
        else
        {
            do
            {
                if (!nRemain)
                    break;
                Unicode wszLeft[256];
                Unicode wszRight[256];
                wszLeft[0].wChar = 0;
                wszRight[0].wChar = 0;
                if (pCursor->wChar < 0x80 && isalpha((char)pCursor->wChar) && sub_005267E0(wszLine, pCursor))
                {
                    sub_005267E0(wszLeft, wszLine);
                    int nSkip = sub_00526800(wszLine) + 2;
                    nRemain -= nSkip;
                    pCursor += nSkip;
                }
                else
                {
                    nRemain = 0;
                }

                if (nRemain && pCursor->wChar != 0x2A)
                {
                    if (sub_005267E0(wszLine, pCursor))
                    {
                        sub_005267E0(wszRight, wszLine);
                        int nSkip = sub_00526800(wszLine) + 2;
                        nRemain -= nSkip;
                        pCursor += nSkip;
                    }
                    else
                    {
                        nRemain = 0;
                    }
                }

                if (wszLeft[0].wChar && wszRight[0].wChar)
                {
                    sub_004FD060_SetText(gpList_0077995C, wszLeft);
                    sub_004FD060_SetText(gpList_00779960, wszRight);
                }
                else
                {
                    sub_004FD060_SetText(gpList_00779964, wszLeft);
                }
                sub_004FCF80_SetTextA(gpList_00779964, &gszEmptyAssertText);
            } while (pCursor->wChar != 0x2A);
        }
        sub_00430EF0_SyncLists();
    }

    sub_00430C80_FillList();
    FOG_Free(pText, ".\\Src\\MainMenus.cpp", 0x146F, 0);
    return 1;
}
