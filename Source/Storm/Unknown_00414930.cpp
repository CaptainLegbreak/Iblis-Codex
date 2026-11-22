#include "SValidate.h"
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMaxLength); // 0x004135D0

// 0x00414930
int __stdcall SRegGetBaseKey(unsigned int nFlags, char* szDest, unsigned int nMaxLength)
{
    VALIDATEBEGIN;
    VALIDATE(szDest);
    VALIDATE(nMaxLength);
    VALIDATEEND;
    if (nFlags & 2)
        SStrCopy(szDest, "Software\\Battle.net\\", nMaxLength);
    else
        SStrCopy(szDest, "Software\\Blizzard Entertainment\\", nMaxLength);
    return nValid ? 1 : 0;
}
