// 0x005183C0
extern "C" __declspec(dllexport) const char* __stdcall sub_005183C0(const char* pText, const char* pEnd) {
    while (pText < pEnd && *pText && (*pText == '\r' || *pText == '\n')) {
        pText++;
    }
    return pText;
}
