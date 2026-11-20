#include "D2Win.h"
#include "D2WinTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WinControlStrc;
struct D2WinSmackStrc;

extern int gbSmackKeepFile_0087E968; // 0x0087E968

enum D2WinControlTypes
{
    D2WIN_SMACK = 9,
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinSmackStrc
{
    D2WinControlStrc controlHeader;
    char szFileName[256];
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion); // 0x00506910
void __stdcall WINDOW_PlaySmacker(void* pContext); // 0x004F5E40
extern unsigned int gdwBitMasks[]; // 0x006CE268

// 0x00506A80
void __stdcall D2Win_10184()
{
    gbSmackKeepFile_0087E968 = 1;
}

char gszSmackFileName_0087E860[260]; // 0x0087E860

unsigned char gnSmackVersion_0087E964; // 0x0087E964

int gbSmackKeepFile_0087E968; // 0x0087E968

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
