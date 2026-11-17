#pragma pack(push, 1)
struct D2ConfigStrc
{
    char unk0x000[0x0BD];
    char szName[0x18];
    char szRealm[0x18];
};
#pragma pack(pop)

extern "C" int __cdecl strcmp(const char* s1, const char* s2);
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

char gszCharName_007A05C4[4];       // 0x007A05C4

// 0x0044D890
void __fastcall sub_0044D890_ApplyConfigName(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szName, "0"))
    {
        int nLength = strlen(pConfig->szName);
        memset(gszCharName_007A05C4, 0, 0x10);
        ++nLength;
        if (nLength > 0x10)
        {
            nLength = 0x10;
        }
        strncpy(gszCharName_007A05C4, pConfig->szName, nLength);
    }
}
