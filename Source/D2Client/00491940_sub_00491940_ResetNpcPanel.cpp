struct Unicode
{
    unsigned short wChar;
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
};

struct D2ClientTabStrc
{
    unsigned char bSelected[4];
    unsigned char bEnabled[4];
    unsigned char unk0x08[0x0A];
};

struct D2TextListNodeStrc
{
    const Unicode* wszText;
    D2TextListNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextListNodeStrc* pFirst;
    unsigned int nCount;
    char unk0x08[0x08];
    unsigned short nWidth;
    unsigned short nHeight;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6);  // 0x0046EFD0
void __stdcall sub_00487A10_SelectItemPageTab(unsigned char nTab);                                          // 0x00487A10
void __cdecl sub_00487ED0();                                                                                // 0x00487ED0
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId);                                                // 0x004B3230
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2ClientTabStrc gaTabs_0072211A[];                                                                   // 0x0072211A
extern int gnGlobal_00722158;                                                                               // 0x00722158
extern int gnGlobal_007BCAF0;                                                                               // 0x007BCAF0
extern int gnGlobal_007BCBEC;                                                                               // 0x007BCBEC
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
unsigned char gnSelectedTab_007BCC04;                                                                       // 0x007BCC04
extern int gnGlobal_007BCC08;                                                                               // 0x007BCC08
extern int gnGlobal_007BCC40;                                                                               // 0x007BCC40
extern int gnGlobal_007BCE30;                                                                               // 0x007BCE30
extern int gnGlobal_007BEECC;                                                                               // 0x007BEECC
unsigned char gbGlobal_007BEEE4;                                                                            // 0x007BEEE4

// 0x00491940
void __cdecl sub_00491940_ResetNpcPanel()
{
    gnGlobal_007BCE30 = 0;
    gnGlobal_007BCC40 = -1;
    gnSelectedTab_007BCC04 = 0;
    gnGlobal_007BCAF0 = 0;
    for (int i = 0; i < gnGlobal_00722158; ++i)
    {
        *(int*)gaTabs_0072211A[i].bSelected = 0;
        *(int*)gaTabs_0072211A[i].bEnabled = 0;
    }
    gnGlobal_007BCBEC = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00487ED0();

    int nNpcId;
    if (sub_004B3230_GetSelectedUnitId(&nNpcId))
    {
        D2UnitStrc* pNpc = sub_00463990(nNpcId, 1);
        int bMatched = 0;
        if (pNpc)
        {
            switch (pNpc->dwClassId)
            {
            case 0x9A:
            case 0x1FF:
                gnSelectedTab_007BCC04 = 1;
                bMatched = 1;
                break;
            case 0x94:
            case 0xB1:
            case 0xB2:
            case 0xCA:
            case 0xFC:
            case 0xFD:
            case 0xFF:
            case 0x101:
            case 0x195:
            case 0x201:
                gnSelectedTab_007BCC04 = 3;
                bMatched = 1;
                break;
            case 0x93:
            case 0x200:
                gnSelectedTab_007BCC04 = 0;
                bMatched = 1;
                break;
            }
        }
        sub_00487A10_SelectItemPageTab(gnSelectedTab_007BCC04);
        if (bMatched)
        {
            gnGlobal_007BCC08 = GetTickCount() + 500;
        }
    }
}

// 0x004939B0
void __cdecl sub_004939B0_LoadPopupHireling()
{
    gnGlobal_007BEECC = 0;
    sub_00455F20(0x23, 0, 0);
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "PopupHireling", 0, &dwValue);
    if (!dwValue)
    {
        gbGlobal_007BEEE4 = 1;
    }
}

// 0x0049D8E0
void __fastcall sub_0049D8E0_DrawTextList(D2TextListStrc* pList, int nX, int nY)
{
    int nLines = pList->nCount > 10 ? 10 : pList->nCount;

    D2TextListNodeStrc* pNode = pList->pFirst;
    if (!nLines || !pNode || nY < 0)
    {
        return;
    }

    const int nHeight = pList->nHeight;
    if (nHeight + nY >= gnGlobal_00711470)
    {
        return;
    }

    sub_0046EFD0_DrawFramedBox(nX, nY + 4, pList->nWidth, nHeight - 5, 0, 1);
    int i = 0;
    const int nOldFont = sub_00502EF0(13);
    for (; i < nLines && pNode; ++i)
    {
        sub_00502320(pNode->wszText, nX + 10, nY + 18 + 15 * (i - nLines + pList->nCount), 0, 0);
        pNode = pNode->pNext;
    }
    sub_00502EF0(nOldFont);
}
