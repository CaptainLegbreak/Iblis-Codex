struct Unicode
{
    unsigned short wChar;
};

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};
#pragma pack(pop)

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall D2Win_10123(const Unicode* wszText, int nLength);                                            // 0x00501730
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2TextListStrc gtTextList_007BF1EA;                                                                  // 0x007BF1EA

// 0x0049DEE0
void __cdecl sub_0049DEE0_DrawOverheadTextList()
{
    if (!gtTextList_007BF1EA.nCount)
    {
        return;
    }

    int nOldFont = sub_00502EF0(13);
    D2TextNodeStrc* pNode = gtTextList_007BF1EA.pFirst;
    int nX = 15;
    if (sub_004538D0(6) || sub_004538D0(0x11))
    {
        nX = 100;
    }

    if (pNode)
    {
        int nBoxRow = 0;
        int nTextRow = 0;
        do
        {
            for (int i = 0; i < 6; ++i)
            {
                if (pNode->pLines[i])
                {
                    sub_0046EFD0_DrawFramedBox(nX - 5, gnGlobal_00711470 - 25 * nBoxRow - i * 25 / 2 - 0x81,
                                               D2Win_10123(pNode->pLines[i], sub_00526800(pNode->pLines[i])) + 10, 0x10, 0, 1);
                    sub_00502320(pNode->pLines[i], nX, gnGlobal_00711470 + 25 * nTextRow - i * 25 / 2 - 0x73, pNode->nColor, 0);
                }
            }
            pNode = pNode->pNext;
            ++nBoxRow;
            --nTextRow;
        }
        while (pNode);
    }

    pNode = gtTextList_007BF1EA.pFirst;
    D2TextNodeStrc* pPrev = 0;
    unsigned int dwNow = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwNow)
        {
            --gtTextList_007BF1EA.nCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtTextList_007BF1EA.pFirst == pNode)
            {
                gtTextList_007BF1EA.pFirst = pNext;
            }

            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);

            if (pPrev)
            {
                pPrev->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->pNext;
        }
    }

    sub_00502EF0(nOldFont);
}
