// 0x006C9A46
int __fastcall sub_006C9A46_StringEquals(const char* szA, const char* szB)
{
    while (*szA)
    {
        if (!*szB || *szA != *szB)
        {
            break;
        }
        ++szA;
        ++szB;
    }
    return *szA == *szB;
}
