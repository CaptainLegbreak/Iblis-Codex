extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int);                                       // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);                                                     // 0x00681E09
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod);  // 0x00406940
int __stdcall sub_00416230_GetFileName(void*, char*, unsigned int);                                         // 0x00416230

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00516F14
int __fastcall sub_00516F14_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod)
{
    char name[0x104];
    D2_ASSERT(file, 0x70);
    int nResult = sub_00406940_mpqSetFilePointer(file, nOffset, pnOffsetHigh, nMethod);
    if (nResult != -1)
    {
        return nResult;
    }

    sub_00416230_GetFileName(file, name, 0x104);
    D2_ASSERT(0, 0x79);
}
