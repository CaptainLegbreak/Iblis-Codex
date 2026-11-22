#include "D2Client.h"
#include "D2Unicode.h"

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01() = 0;
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int Slot11() = 0;

    void operator delete(void* pMemory)
    {
        if (pMemory)
        {
            SMemFree(pMemory, "delete", -1, 0);
        }
    }

    int unk0x04;
};

#pragma pack(push, 2)

class EditBoxImplementation : public UIWidget
{
public:
    virtual ~EditBoxImplementation();
    virtual void Slot01();
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot11();
    virtual void sub_004BB5B0_Slot12(char* szBuffer);
    virtual void Slot13();

    int nX;
    int nY;
    int nTextX;
    int nTextY;
    int nTextWidth;
    int nHeight;
    int unk0x20;
    int unk0x24;
    Unicode* pText;
    Unicode* pTextCopy;
    int unk0x30;
    unsigned short nMaxLength;
    int unk0x36;
    int unk0x3A;
    int unk0x3E;
    int unk0x42;
    unsigned int unk0x46;
    int unk0x4A;
    int nFont;
    void* pCellFile;
    int unk0x56;
};

#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6);
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);
int __fastcall sub_00502EF0(int nFontSize);
extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0
extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800

// 0x004BB210
void EditBoxImplementation::Slot01()
{
    ++unk0x46;
    if (unk0x56)
    {
        sub_0046EFD0_DrawFramedBox(nTextX - 10, nTextY - 0x10, nTextWidth, 0x12, 0, 2);
    }
    sub_00502EF0(nFont);

    Unicode wszBuffer[200];
    Unicode wszCursor[2];
    char szCursor[2];
    szCursor[1] = 0;
    szCursor[0] = '_';
    Unicode::win2Unicode(wszCursor, szCursor, 2);

    if ((unk0x4A && unk0x46 % 20 == 0) || (!unk0x4A && unk0x46 % 10 == 0))
    {
        unk0x4A = !unk0x4A;
    }

    if (nHeight == 1)
    {
        int nStart = 0;
        if (sub_00501820(pText) > nTextWidth)
        {
            const int nLength = sub_00526800((const unsigned short*)pText);
            for (nStart = 0; nStart < nLength; ++nStart)
            {
                if (sub_00501820(&pText[nStart]) <= nTextWidth)
                {
                    break;
                }
            }
        }

        sub_00502320(&pText[nStart], nTextX, nTextY, 0, 0);
        if (unk0x36 < nMaxLength && unk0x4A && unk0x36 <= unk0x3A)
        {
            if (sub_00526800((const unsigned short*)&pText[nStart]))
            {
                sub_005267E0((unsigned short*)pTextCopy, (const unsigned short*)pText);
                pTextCopy[unk0x36] = 0;
                sub_00502320(wszCursor, sub_00501820(pTextCopy) + nTextX, nTextY, 0, 0);
            }
            else
            {
                sub_00502320(wszCursor, nTextX, nTextY, 0, 0);
            }
        }
        return;
    }

    int nLines;
    T0044CB60* pLine = sub_00502970_SplitText(pText, &nLines, nTextWidth);
    int nLine = 0;
    int nChars = 0;
    int bDone = 0;
    while (pLine)
    {
        sub_00502320(pLine->pText, nTextX, nTextY + 20 * nLine, 0, 0);
        const int nLength = sub_00526800((const unsigned short*)pLine->pText);
        T0044CB60* pNext = pLine->pNext;
        nChars += nLength;
        ++nLine;
        if (unk0x36 < nMaxLength && unk0x4A && nChars >= unk0x36 && !bDone)
        {
            bDone = 1;
            int nColumn = unk0x36 - nChars + nLength;
            if (nColumn < 0)
            {
                nColumn = 0;
            }
            if (sub_00526800((const unsigned short*)pLine->pText))
            {
                if (sub_00526800((const unsigned short*)pLine->pText) > 199)
                {
                    return;
                }
                sub_005267E0((unsigned short*)wszBuffer, (const unsigned short*)pLine->pText);
                wszBuffer[nColumn] = 0;
                sub_00502320(wszCursor, sub_00501820(wszBuffer) + nTextX, nTextY + 20 * (nLine - 1), 0, 0);
            }
            else
            {
                sub_00502320(wszCursor, nTextX, nTextY + 20 * (nLine - 1), 0, 0);
            }
        }
        FOG_Free(pLine->pText, ".\\UI\\editbox.cpp", 0x103, 0);
        FOG_Free(pLine, ".\\UI\\editbox.cpp", 0x104, 0);
        pLine = pNext;
    }
    if (!nLine && unk0x4A)
    {
        sub_00502320(wszCursor, nTextX, nTextY, 0, 0);
    }
}
