#include "D2Client.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"

struct D2ChatTextStrc;
struct D2ClientNotifyStrc;
struct Unicode;

struct D2ChatMessageStrc
{
    unsigned char unk0x00;
    unsigned char nType;
    unsigned char unk0x02[6];
    unsigned char nColor;
    unsigned char unk0x09[0x11];
    D2ChatTextStrc tText;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" size_t __cdecl strlen(const char* sz);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
D2ClientNotifyStrc* __cdecl GAME_GetClientNotify(); // 0x0044B7B0
void __stdcall sub_Z12_EmitUse(int nValue);

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0
const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __stdcall sub_0047E9A0_DrawSlots(int bDraw); // 0x0047E9A0
int __cdecl sub_0047EA60_IsAnyPanelOpen(); // 0x0047EA60
int __cdecl sub_0047EB50_IsAnyLeftPanelOpen(); // 0x0047EB50
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern void* gpMiniPanelCel; // 0x007BC960
extern int gbSlotBarBlocked; // 0x007BC970
extern int gaSlotX[]; // 0x007BC898
extern int gaSlotY[]; // 0x007BC8B8
extern int gaSlotKind[]; // 0x007BC8D8
extern int gaSlotFrame[]; // 0x007BC918

int __stdcall sub_0047B3B0_CompareCommand(const char* szCommand, const char* szInput); // 0x0047B3B0

static int sub_0047C100(char* szInput, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0047B3B0_CompareCommand(szCommand, szInput))
    {
        const char c = szInput[nLength];
        if (c == ' ' || !c)
        {
            char szDelim[] = " ";
            int nTokens = 0;
            if (strtok(szInput, szDelim))
            {
                while (nTokens < 2)
                {
                    ++nTokens;
                    if (!strtok(0, szDelim))
                        break;
                }
                if (nTokens == 1)
                {
                    D2ClientNotifyStrc* pNotify = GAME_GetClientNotify();
                    if (pNotify)
                        pNotify->pfnResign(szInput);
                    return 1;
                }
            }
            D2ChatTextStrc tBuffer;
            sprintf(tBuffer.sz, "<BattleNet>: Correct usage is: %s", szCommand);
            D2ChatMessageStrc tMessage;
            tMessage.nType = 4;
            tMessage.nColor = 3;
            tMessage.tText = tBuffer;
            sub_0049F490_PrintChatMessage(&tMessage);
            return 1;
        }
    }
    return 0;
}

// 0x0047C3F0
static void __stdcall sub_0047C3F0_CopyCommandArgs(char* szDest, const char* szSource, unsigned int nSize)
{
    const char* pArgs = SStrChr(szSource, ' ');
    if (pArgs)
        SStrCopy(szDest, pArgs + 1, nSize);
    else
        *szDest = 0;
}

void __fastcall sub_Z12_EmitChatCommands(char* szInput, char* szOut)
{
    if (sub_0047C100(szInput, "/help"))
        return;
    if (sub_0047C100(szInput, "/?"))
        return;
    sub_0047C3F0_CopyCommandArgs(szOut, szInput, 0x31);
    sub_Z12_EmitUse(szOut[0]);
}

int gaSlotX[8]; // 0x007BC898

int gaSlotY[8]; // 0x007BC8B8

int gaSlotKind[8]; // 0x007BC8D8

int gaSlotFrame[8]; // 0x007BC918

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0047E8B0
static void sub_0047E8B0_LayoutSlots(int nMode)
{
    int nSlots = 8;
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    int nFrameAdd = 0;
    int nKindAdd = 0;
    if (!nMode)
    {
        return;
    }
    int nX = gnScreenWidth / 2 - 0x54;
    if (gbSmallPanel_007BC978)
    {
        nX = gnScreenWidth / 2 - 0x4A;
    }
    const int nY = gnScreenHeight - 0x32;
    if (nMode == 1)
    {
        nX = gnScreenWidth / 2 - 0xCA;
    }
    else if (nMode == 3)
    {
        nX = gnScreenWidth / 2 + 0x39;
        if (!gbSmallPanel_007BC978)
        {
            nX = gnScreenWidth / 2 + 0x23;
        }
    }
    gaSlotKind[0] = 0;
    gaSlotFrame[0] = 0;
    gaSlotX[0] = nX;
    gaSlotY[0] = nY;
    nX += 0x15;
    for (int i = 1; i < nSlots; ++i)
    {
        gaSlotX[i] = nX;
        gaSlotY[i] = nY;
        if (gbSmallPanel_007BC978)
        {
            if (i == 3)
            {
                nFrameAdd += 2;
                nKindAdd += 1;
            }
            gaSlotKind[i] = nKindAdd + i;
            gaSlotFrame[i] = nFrameAdd + i * 2;
        }
        else
        {
            gaSlotKind[i] = i;
            gaSlotFrame[i] = i * 2;
        }
        nX += 0x15;
    }
}

// 0x0047F490
static void __stdcall sub_0047F490_ShowSlotTooltip(int nX, int nY, int nKind)
{
    int bHasKey = 0;
    int nHotKey = 0x39;
    int nString;
    switch (nKind)
    {
    case 0:
        nString = 0x1049;
        bHasKey = 1;
        nHotKey = 0;
        break;
    case 1:
        bHasKey = 1;
        nString = 0x104A;
        nHotKey = 1;
        break;
    case 2:
        bHasKey = 1;
        nString = 0x104B;
        nHotKey = 0xC;
        break;
    case 3:
        bHasKey = 1;
        nString = 0x104C;
        nHotKey = 2;
        break;
    case 4:
        bHasKey = 1;
        nString = 0x104D;
        nHotKey = 7;
        break;
    case 5:
        bHasKey = 1;
        nString = 0x104E;
        nHotKey = 3;
        break;
    case 6:
        bHasKey = 1;
        nString = 0x104F;
        nHotKey = 4;
        break;
    case 7:
        nString = 0x1050;
        break;
    default:
        return;
    }
    Unicode wszText[200];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    if (bHasKey && nHotKey != 0x39)
    {
        Unicode wszKey[30];
        if (CUNIT_GetHotkeyBinding(nHotKey, 1) != 0xFFFF)
        {
            memset(wszKey, 0, sizeof(wszKey));
            sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyText(nHotKey, 1));
            sub_00526700(wszText, wszKey);
        }
        if (CUNIT_GetHotkeyBinding(nHotKey, 0) != 0xFFFF)
        {
            memset(wszKey, 0, sizeof(wszKey));
            sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyText(nHotKey, 0));
            sub_00526700(wszText, wszKey);
        }
    }
    D2Win_10129_DrawFramedText(wszText, nX - 3, nY - 0x1A, 0, 1);
}

// 0x0047F650
static void sub_0047F650_UpdateSlotHover(int nMode)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    int nOffset = 0;
    int nSlots = 8;
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    if (!nMode)
    {
        return;
    }
    if (nMode == 1)
    {
        nOffset = -0x76;
    }
    else if (nMode == 3)
    {
        nOffset = 0x77;
    }
    const int nCenter = gnScreenWidth / 2 + nOffset;
    if (nMouseX <= nCenter - 0x54 || nMouseX >= nCenter + 0x59)
    {
        return;
    }
    if (nMouseY <= gnScreenHeight - 0x45 || nMouseY >= gnScreenHeight - 0x2F)
    {
        return;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (nMouseX > gaSlotX[i] && nMouseX < gaSlotX[i] + 0x14)
        {
            sub_0047F490_ShowSlotTooltip(gaSlotX[i], gaSlotY[i], gaSlotKind[i]);
        }
    }
}

int gbSlotBarBlocked; // 0x007BC970

// 0x0047F710
void __cdecl sub_0047F710_UpdateSlotBar()
{
    const int bAnyPanel = sub_0047EA60_IsAnyPanelOpen();
    const int bLeftPanel = sub_0047EB50_IsAnyLeftPanelOpen();
    D2CelContextStrc tContext;
    if (bAnyPanel && !bLeftPanel)
    {
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpMiniPanelCel;
        int nX = gnScreenWidth / 2;
        if (gbSmallPanel_007BC978)
        {
            nX += 0x38;
        }
        else
        {
            nX += 0x23;
        }
        sub_004F6480(&tContext, nX - 2, gnScreenHeight - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(3);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(3);
        gbSlotBarBlocked = 0;
        return;
    }

    if (!bAnyPanel && !bLeftPanel)
    {
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpMiniPanelCel;
        int nX = gnScreenWidth / 2;
        if (gbSmallPanel_007BC978)
        {
            nX -= 0x4A;
        }
        else
        {
            nX -= 0x54;
        }
        sub_004F6480(&tContext, nX - 3, gnScreenHeight - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(2);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(2);
        gbSlotBarBlocked = 0;
        return;
    }

    if (!bAnyPanel && bLeftPanel)
    {
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpMiniPanelCel;
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0xCD, gnScreenHeight - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(1);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(1);
        gbSlotBarBlocked = 0;
        return;
    }

    sub_00468730();
    sub_00468740();
    gbSlotBarBlocked = 1;
}
