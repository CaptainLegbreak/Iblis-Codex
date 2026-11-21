#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinControlStrc;

struct D2WinSmackStrc;

int gbSmackKeepFile_0087E968; // 0x0087E968

enum D2WinControlTypes
{
    D2WIN_SMACK = 9,
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion); // 0x00506910

void __stdcall WINDOW_PlaySmacker(void* pContext); // 0x004F5E40

extern unsigned int gdwBitMasks[]; // 0x006CE268

#pragma pack(push, 1)

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

int __fastcall SMACK_Draw(D2WinControlStrc* pControl); // 0x00506A90

int __stdcall SMACK_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00506B10

// 0x00506A80
void __stdcall D2Win_10184()
{
    gbSmackKeepFile_0087E968 = 1;
}

char gszSmackFileName_0087E860[260]; // 0x0087E860

unsigned char gnSmackVersion_0087E964; // 0x0087E964

// 0x00506A90
int __fastcall SMACK_Draw(D2WinControlStrc* pControl)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)pControl;

    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0xA4);

    if (!(pSmack->controlHeader.dwFlags & gdwBitMasks[2]) || !(pSmack->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    if (gbSmackKeepFile_0087E968)
    {
        if (gszSmackFileName_0087E860[0])
        {
            SMACK_Decode(pSmack, gszSmackFileName_0087E860, gnSmackVersion_0087E964);
        }

        gbSmackKeepFile_0087E968 = 0;
    }

    WINDOW_PlaySmacker(&pSmack->field_140);
    return 1;
}

// 0x00506B70
D2WinSmackStrc* __fastcall sub_00506B70_SmackCreate(int nX, int nY, int nWidth, int nHeight, D2WinMsgHandler pfHandler)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)FOG_Alloc(sizeof(D2WinSmackStrc), ".\\Src\\D2WinSmack.cpp", 0x23, 0);
    memset(pSmack, 0, sizeof(D2WinSmackStrc));
    pSmack->controlHeader.eType = 9;
    pSmack->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pSmack->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pSmack->controlHeader.nWidth = nWidth;
    pSmack->controlHeader.pNext = 0;
    memset(&pSmack->controlHeader.pfHandleMouseUp, 0, 3 * sizeof(D2WinMsgHandler));
    pSmack->controlHeader.nImageX = nX;
    pSmack->controlHeader.nImageY = nY;
    pSmack->controlHeader.nHeight = nHeight;
    pSmack->controlHeader.field_34 = pfHandler;
    pSmack->controlHeader.pfDraw = SMACK_Draw;
    pSmack->controlHeader.pfHandleMouseDown = SMACK_HandleMouseDown;
    pSmack->szFileName[0] = 0;
    memset(&pSmack->field_140, 0, 2 * sizeof(int));
    pSmack->nMovieX = (nWidth - 468) / 2 + nX;
    pSmack->nMovieY = (nHeight - 60) / 2 + nY;
    CONTROL_AppendToList(&pSmack->controlHeader);
    return pSmack;
}
