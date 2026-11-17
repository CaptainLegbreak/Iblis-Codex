extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
#pragma intrinsic(strcmp)

// 0x00447390
static __declspec(noinline) int sub_00447390_CompareNames(const char* szNameA, const char* szNameB)
{
    const char* szA = strchr(szNameA, '*');
    if (!szA)
        szA = szNameA;
    else
        szA += 1;
    const char* szB = strchr(szNameB, '*');
    if (!szB)
        szB = szNameB;
    else
        szB += 1;
    return strcmp(szA, szB);
}

int __cdecl sub_M133_Emit_00447390(const char* szNameA, const char* szNameB)
{
    return sub_00447390_CompareNames(szNameA, szNameB);
}
