struct D2CriticalSectionStrc { char data[24]; };
struct D2StormFileRecStrc { char pad[8]; char name[260]; const char* fullName; };
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0
__declspec(noinline)
// 0x00415950
static int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
 *ppRec = (D2StormFileRecStrc*)hFile;
 return 1;
}
// 0x004162A0
int __stdcall sub_004162A0_GetFileName(void* hFile, char* dest, unsigned int size)
{
 if (dest)
  *dest = 0;
 if (!dest) { sub_0041C340_SetLastError(0x57); return 0; }
 EnterCriticalSection(&gBasePathLock_00779068);
 D2StormFileRecStrc* rec;
 if (!sub_00415950_GetFileRec(hFile, &rec)) {
  LeaveCriticalSection(&gBasePathLock_00779068);
  return 0;
 }
 SStrCopy(dest, rec->fullName ? rec->fullName : rec->name, size);
 LeaveCriticalSection(&gBasePathLock_00779068);
 return 1;
}
