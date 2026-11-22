#include "Storm.h"

extern "C" __declspec(dllimport) int __stdcall LoadStringA(void* hInstance, unsigned int uId, char* buffer, int length); // 0x006CC46C
void* __fastcall StormGetInstance(); // 0x0041BEF0
extern const char* gpszMessageFallback_006CF2F4[]; // 0x006CF2F4
static const char* sub_0041C170_GetMessageText(int nIndex);

extern D2StormMsgSourceStrc* gpSources_007790E8; // 0x007790E8
extern int gnInitialized_007790EC; // 0x007790EC
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
void __cdecl sub_0041C140_AppendExeMsgSources(); // 0x0041C140
void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long, unsigned long, char*, unsigned long, void*);

char gszMessageBuffer_00779100[256]; // 0x00779100

// 0x0041C170
static const char* sub_0041C170_GetMessageText(int nIndex)
{
    if (LoadStringA(StormGetInstance(), nIndex + 0x5100, gszMessageBuffer_00779100, 256))
        return gszMessageBuffer_00779100;
    return gpszMessageFallback_006CF2F4[nIndex];
}

const char* __stdcall EmitMessageText(int nIndex)
{
    return sub_0041C170_GetMessageText(nIndex);
}

#include "gen/data/Source/Storm/Unknown_0041C170.inc"

// 0x0041C430
int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size)
{
    VALIDATEBEGIN;
    VALIDATE(buffer);
    VALIDATE(size);
    VALIDATEEND;
    sub_0041C1A0_LockErrorState();
    if (!gnInitialized_007790EC) { gnInitialized_007790EC = 1; sub_0041C140_AppendExeMsgSources(); }
    D2StormMsgSourceStrc* const head = gpSources_007790E8;
    unsigned int facility = (error >> 16) & 0xfff;
    void* module = 0;
    if (head) {
        D2StormMsgSourceStrc* source = head;
        do {
            if (source->wFacility == (unsigned short)facility) { module = source->hModule; break; }
            source = source->pNext;
        } while (source);
    }
    sub_0041C1E0_UnlockErrorState();
    buffer[0] = 0;
    return FormatMessageA(module ? 0x800 : 0x1000, module, error, 0x400, buffer, size, 0) != 0;
}
