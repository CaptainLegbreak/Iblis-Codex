extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_LOWORD(l) ((unsigned short)((unsigned int)(l) & 0xFFFF))
#define D2_HIWORD(l) ((unsigned short)(((unsigned int)(l) >> 16) & 0xFFFF))

struct SMSGHANDLER_PARAMS
{
    void* hWindow;
    unsigned int nMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int unk0x10;
    unsigned int unk0x14;
    int bUseResult;
    int lResult;
};

#pragma pack(push, 1)
struct D2QuestPanelEntryStrc
{
    int nQuestId;
    char unk0x004[0x25E - 0x004];
    unsigned short wTextId;
    unsigned char nSlot;
    char unk0x261[0x263 - 0x261];
    unsigned char bEnabled;
    char unk0x264[0x265 - 0x264];
    int bDone;
    char unk0x269[0x26A - 0x269];
};
#pragma pack(pop)

struct D2QuestSlotRectStrc
{
    int nX;
    int nY;
    int unk0x08;
    int unk0x0C;
};

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __stdcall D2GFX_GetResolutionMode();                                                                    // 0x004F5160
void __fastcall sub_004A3FE0(int nMode);
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound);               // 0x004A1320
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0
int __fastcall sub_004A27B0_CloseQuestText(void* pContext, int nArg, int nValue);                           // 0x004A27B0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2QuestSlotRectStrc gaQuestSlots_00723EB0[];                                                         // 0x00723EB0
extern int gnQuestCount_007BF2A0;                                                                           // 0x007BF2A0
extern char gbGlobal_007BF2B0;                                                                              // 0x007BF2B0
extern char gbGlobal_007BF2B1;                                                                              // 0x007BF2B1
char gbGlobal_007BF2B2;                                                                                     // 0x007BF2B2
extern char gbGlobal_007BF2B3;                                                                              // 0x007BF2B3
char gbGlobal_007BF2B4;                                                                                     // 0x007BF2B4
extern int gnIndex_007BF2B5;                                                                                // 0x007BF2B5
extern int gnIndex_007BF2B9;                                                                                // 0x007BF2B9
extern int ganPageSelection_007BF2BD[];                                                                     // 0x007BF2BD
extern D2QuestPanelEntryStrc gaQuestEntries_007BF3AA[];                                                     // 0x007BF3AA
extern int gnGlobal_007C0255;                                                                               // 0x007C0255
extern char gbGlobal_007C025D;                                                                              // 0x007C025D
extern char gbGlobal_007C025E;                                                                              // 0x007C025E
extern char gbGlobal_007C025F;                                                                              // 0x007C025F
extern char gbGlobal_007C0260;                                                                              // 0x007C0260

#define D2_RESET_QUEST_SELECTION() \
    gbGlobal_007BF2B1 = 0; \
    gbGlobal_007BF2B2 = 0; \
    gbGlobal_007BF2B0 = 0; \
    gnIndex_007BF2B5 = -1; \
    gbGlobal_007BF2B4 = 0; \
    gbGlobal_007C025D = 0; \
    gbGlobal_007C025E = 0; \
    gbGlobal_007C025F = 0; \
    gbGlobal_007C0260 = 0

static unsigned char sub_004A2610_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}

static int sub_004A2630_GetSlotAtPoint(int nX, int nY)
{
    int nCount = gnQuestCount_007BF2A0;
    D2_ASSERT((unsigned int)nCount <= 6, 0x738);
    for (int i = 0; i < nCount; ++i)
    {
        if (nX >= gaQuestSlots_00723EB0[i].nX && nX < gaQuestSlots_00723EB0[i].nX + 0x38 && nY >= gaQuestSlots_00723EB0[i].nY && nY < gaQuestSlots_00723EB0[i].nY + 0x34)
        {
            return i;
        }
    }
    return -1;
}

static unsigned char sub_004A2690_HitTestButtonB(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}

static void sub_004A27D0_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (gaQuestEntries_007BF3AA[i].nSlot == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gaQuestEntries_007BF3AA[nIndex].wTextId;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    sub_004A1320_OpenTextPanel(wTextId, 1, 0);
    sub_0049E7E0_SetTextCallback(sub_004A27B0_CloseQuestText, 0);
    gbGlobal_007BF2B3 = 1;
}

// 0x004A42A0
void __stdcall sub_004A42A0_OnLeftButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnGlobal_007A2858;
    int nY = D2_HIWORD(pMsg->lParam) + gnGlobal_007A285C;
    if (gbGlobal_007BF2B2)
    {
        if (sub_004A2690_HitTestButtonB(nX, nY)) sub_004A3FE0(0);
    }
    else if (!gbGlobal_007BF2B3)
    {
        if (gnIndex_007BF2B5 != -1)
        {
            int nSlot = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nSlot == gnIndex_007BF2B5)
            {
                ganPageSelection_007BF2BD[gnGlobal_007C0255] = nSlot;
                gnIndex_007BF2B9 = nSlot;
            }
        }
        else if (gbGlobal_007BF2B4 == 1)
        {
            if (sub_004A2610_HitTestButtonA(nX, nY) && gnIndex_007BF2B9 != -1)
            {
                sub_004A27D0_OpenQuestDescription(gnIndex_007BF2B9);
            }
        }
    }
    D2_RESET_QUEST_SELECTION();
    if (D2_LOWORD(pMsg->lParam) > gnGlobal_0071146C / 2) return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x2F) return;
    }
    else
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x31) return;
    }
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}
