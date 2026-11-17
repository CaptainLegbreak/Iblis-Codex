unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0

// 0x0060AE80
static __declspec(noinline) unsigned int sub_0060AE80_GetCelDataHashKey(const char* szName)
{
    unsigned int nHash = SStrHash(szName, 1, 0);
    return ((nHash ^ (nHash >> 8)) ^ ((nHash ^ (nHash >> 8)) >> 16)) & 0x1FF;
}

unsigned int __fastcall sub_M383_Emit_0060AE80(int nAdd, const char* szName)
{
    return sub_0060AE80_GetCelDataHashKey(szName) + nAdd * 3;
}
