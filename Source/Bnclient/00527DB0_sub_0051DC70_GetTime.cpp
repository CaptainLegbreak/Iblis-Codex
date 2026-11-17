extern "C" long __cdecl _time32(long* pTime);
extern "C" int __cdecl tolower(int nChar);
extern const char gacCDKeyMap_006DF238[];

// 0x00527DB0
static __declspec(noinline) long sub_0051DC70_GetTime(long* pTime)
{
    return _time32(pTime);
}

static __declspec(noinline) unsigned int sub_0051DD10_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

static __declspec(noinline) int sub_0051DD20_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

static __declspec(noinline) int sub_0051DD40_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap_006DF238[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return sub_0051DC70_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return sub_0051DD10_NibbleToHex(tolower(n)) + sub_0051DD10_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return sub_0051DD20_HexToNibble((char)tolower(n)) * 16 + sub_0051DD20_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return sub_0051DD40_MapKeyChar((unsigned char)tolower(n)) * 24 + sub_0051DD40_MapKeyChar((unsigned char)tolower(n + 1));
}
