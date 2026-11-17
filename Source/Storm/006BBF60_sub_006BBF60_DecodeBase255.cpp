// 0x006BBF60
int __stdcall sub_006BBF60_DecodeBase255(const unsigned char* pBytes)
{
    return (((pBytes[3] - 1) * 255 + (pBytes[2] - 1)) * 255 + (pBytes[1] - 1)) * 255 + (pBytes[0] - 1);
}
