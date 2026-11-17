// 0x00518390
extern "C" __declspec(dllexport) const char* __stdcall sub_00518390(const char* pText, const char* pEnd) {
    while (pText < pEnd && *pText && *pText != '\r' && *pText != '\n') {
        pText++;
    }
    return pText;
}
