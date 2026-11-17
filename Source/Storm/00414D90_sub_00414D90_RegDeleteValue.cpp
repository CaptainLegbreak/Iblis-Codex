void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
int __fastcall sub_00414990_SRegDeleteEntry(unsigned int nFlags, const char* szKeyName, const char* szValueName);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00414D90
int __stdcall sub_00414D90_RegDeleteValue(const char* szKeyName, const char* szValueName, unsigned int nFlags)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    __assume((szKeyName) != 0);
    VALIDATE(*szKeyName);
    __assume((*szKeyName) != 0);
    VALIDATE(szValueName);
    __assume((szValueName) != 0);
    VALIDATE(*szValueName);
    __assume((*szValueName) != 0);
    VALIDATEEND;
    return sub_00414990_SRegDeleteEntry(nFlags, szKeyName, szValueName);
}
