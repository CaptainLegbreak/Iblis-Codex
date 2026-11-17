// 0x006BBF40
extern "C" __declspec(dllexport) void __stdcall sub_006BBF40(unsigned char* pBuffer, unsigned int nValue) {
    *pBuffer = (unsigned char)(nValue | 0x80);
    *(pBuffer + 1) = (unsigned char)((nValue >> 7) | 0x80);
}
