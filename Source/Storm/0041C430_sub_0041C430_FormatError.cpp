struct D2MessageSourceStrc { unsigned short facility, padding; void* module; D2MessageSourceStrc* next; };
extern D2MessageSourceStrc* gpSources_007790E8; // 0x007790E8
extern int gnInitialized_007790EC; // 0x007790EC
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
void __cdecl sub_0041C140_AppendExeMsgSources(); // 0x0041C140
void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long, unsigned long, char*, unsigned long, void*);
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return nValid; }

// 0x0041C430
int __stdcall sub_0041C430_FormatError(unsigned long error, char* buffer, unsigned long size)
{
    VALIDATEBEGIN;
    VALIDATE(buffer);
    VALIDATE(size);
    VALIDATEEND;
    sub_0041C1A0_LockErrorState();
    if (!gnInitialized_007790EC) { gnInitialized_007790EC = 1; sub_0041C140_AppendExeMsgSources(); }
    D2MessageSourceStrc* const head = gpSources_007790E8;
    unsigned int facility = (error >> 16) & 0xfff;
    void* module = 0;
    if (head) {
        D2MessageSourceStrc* source = head;
        do {
            if (source->facility == (unsigned short)facility) { module = source->module; break; }
            source = source->next;
        } while (source);
    }
    sub_0041C1E0_UnlockErrorState();
    buffer[0] = 0;
    return FormatMessageA(module ? 0x800 : 0x1000, module, error, 0x400, buffer, size, 0) != 0;
}
