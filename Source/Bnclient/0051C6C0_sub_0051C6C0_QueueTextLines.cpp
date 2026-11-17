extern "C" char* __cdecl strchr(const char* s, int c);                                  // 0x00687740
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);      // 0x006829C0
int __fastcall sub_005202F0_QueueText(int nId, const char* szText);                     // 0x005202F0
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x0051C6C0
void __fastcall sub_0051C6C0_QueueTextLines(const char* szText)
{
    char szLine[288];

    const char* pEnd = strchr(szText, '\r');
    while (pEnd)
    {
        const int nLength = D2_MIN(pEnd - szText, 287);
        memcpy(szLine, szText, nLength);
        szLine[nLength] = 0;
        sub_005202F0_QueueText(1, szLine);
        szText = pEnd + 1;
        if (pEnd[1] == '\n')
            ++szText;
        pEnd = strchr(szText, '\r');
    }
}
