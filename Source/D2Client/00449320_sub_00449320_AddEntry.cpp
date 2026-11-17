extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
extern const unsigned char gnCdKeyMap_006D59F0[256];                                                        // 0x006D59F0
void* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA);                             // 0x00449050

// 0x00449320
static __forceinline void* sub_00449320_AddEntry(const char* szText, int nLength, int nA)
{
    return sub_00449050_AddEntry(szText, nLength, nA);
}

// 0x004497C0
int __fastcall sub_004497C0_MapKeyChar(unsigned char cChar)
{
    return (char)gnCdKeyMap_006D59F0[cChar];
}

// 0x004497D0
int __fastcall sub_004497D0_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// 0x00449840
unsigned int __fastcall sub_00449840_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
}

// 0x00449860
int __fastcall sub_00449860_IsValidKeyText(const char* szKey)
{
    while (*szKey)
    {
        if (gnCdKeyMap_006D59F0[(unsigned char)*szKey++] > 0x17)
        {
            return 0;
        }
    }
    return 1;
}

void* __fastcall sub_M109_Emit_00449320(const char* szText, int nLength)
{
    return sub_00449320_AddEntry(szText, nLength, 7);
}

#include "gen/data/Source/D2Client/00449320_sub_00449320_AddEntry.inc"
