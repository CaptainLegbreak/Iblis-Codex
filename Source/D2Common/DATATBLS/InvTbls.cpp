#include "D2Common.h"

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpInventoryTxt;                                                                                // 0x0096D4F4
extern int gnInventoryTxtRecordCount;                                                                       // 0x0096D4F0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

// 0x0065B660
void __fastcall DATATBLS_LoadInventoryTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "invLeft", 2, 0, 0, 0 },
        { "invRight", 2, 0, 4, 0 },
        { "invTop", 2, 0, 8, 0 },
        { "invBottom", 2, 0, 12, 0 },
        { "gridX", 4, 0, 16, 0 },
        { "gridY", 4, 0, 17, 0 },
        { "gridLeft", 2, 0, 20, 0 },
        { "gridRight", 2, 0, 24, 0 },
        { "gridTop", 2, 0, 28, 0 },
        { "gridBottom", 2, 0, 32, 0 },
        { "gridBoxWidth", 4, 0, 36, 0 },
        { "gridBoxHeight", 4, 0, 37, 0 },
        { "rArmLeft", 2, 0, 40, 0 },
        { "rArmRight", 2, 0, 44, 0 },
        { "rArmTop", 2, 0, 48, 0 },
        { "rArmBottom", 2, 0, 52, 0 },
        { "rArmWidth", 4, 0, 56, 0 },
        { "rArmHeight", 4, 0, 57, 0 },
        { "torsoLeft", 2, 0, 60, 0 },
        { "torsoRight", 2, 0, 64, 0 },
        { "torsoTop", 2, 0, 68, 0 },
        { "torsoBottom", 2, 0, 72, 0 },
        { "torsoWidth", 4, 0, 76, 0 },
        { "torsoHeight", 4, 0, 77, 0 },
        { "lArmLeft", 2, 0, 80, 0 },
        { "lArmRight", 2, 0, 84, 0 },
        { "lArmTop", 2, 0, 88, 0 },
        { "lArmBottom", 2, 0, 92, 0 },
        { "lArmWidth", 4, 0, 96, 0 },
        { "lArmHeight", 4, 0, 97, 0 },
        { "headLeft", 2, 0, 100, 0 },
        { "headRight", 2, 0, 104, 0 },
        { "headTop", 2, 0, 108, 0 },
        { "headBottom", 2, 0, 112, 0 },
        { "headWidth", 4, 0, 116, 0 },
        { "headHeight", 4, 0, 117, 0 },
        { "neckLeft", 2, 0, 120, 0 },
        { "neckRight", 2, 0, 124, 0 },
        { "neckTop", 2, 0, 128, 0 },
        { "neckBottom", 2, 0, 132, 0 },
        { "neckWidth", 4, 0, 136, 0 },
        { "neckHeight", 4, 0, 137, 0 },
        { "rHandLeft", 2, 0, 140, 0 },
        { "rHandRight", 2, 0, 144, 0 },
        { "rHandTop", 2, 0, 148, 0 },
        { "rHandBottom", 2, 0, 152, 0 },
        { "rHandWidth", 4, 0, 156, 0 },
        { "rHandHeight", 4, 0, 157, 0 },
        { "lHandLeft", 2, 0, 160, 0 },
        { "lHandRight", 2, 0, 164, 0 },
        { "lHandTop", 2, 0, 168, 0 },
        { "lHandBottom", 2, 0, 172, 0 },
        { "lHandWidth", 4, 0, 176, 0 },
        { "lHandHeight", 4, 0, 177, 0 },
        { "beltLeft", 2, 0, 180, 0 },
        { "beltRight", 2, 0, 184, 0 },
        { "beltTop", 2, 0, 188, 0 },
        { "beltBottom", 2, 0, 192, 0 },
        { "beltWidth", 4, 0, 196, 0 },
        { "beltHeight", 4, 0, 197, 0 },
        { "feetLeft", 2, 0, 200, 0 },
        { "feetRight", 2, 0, 204, 0 },
        { "feetTop", 2, 0, 208, 0 },
        { "feetBottom", 2, 0, 212, 0 },
        { "feetWidth", 4, 0, 216, 0 },
        { "feetHeight", 4, 0, 217, 0 },
        { "glovesLeft", 2, 0, 220, 0 },
        { "glovesRight", 2, 0, 224, 0 },
        { "glovesTop", 2, 0, 228, 0 },
        { "glovesBottom", 2, 0, 232, 0 },
        { "glovesWidth", 4, 0, 236, 0 },
        { "glovesHeight", 4, 0, 237, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpInventoryTxt = DATATBLS_CompileTxt(hArchive, "inventory", pTbl, &gnInventoryTxtRecordCount, 240);
    TBL_ASSERT(gnInventoryTxtRecordCount == 32, 112);
}
