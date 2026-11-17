// 0x006BBF20
extern "C" __declspec(dllexport) int __stdcall sub_006BBF20(const unsigned char* pBuffer) {
    return ((*(pBuffer + 1) & 0x7F) << 7) + (*pBuffer & 0x7F);
}
