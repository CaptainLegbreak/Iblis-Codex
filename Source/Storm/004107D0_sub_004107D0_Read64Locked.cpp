// 0x004107D0
__declspec(naked) void __fastcall sub_004107D0_Read64Locked(__int64* pDest, const __int64* pSrc)
{
    __asm
    {
        push ebx
        push esi
        mov esi, edx
        mov eax, ebx
        mov edx, ecx
        lock cmpxchg8b qword ptr [esi]
        mov [ecx], eax
        mov [ecx + 4], edx
        pop esi
        pop ebx
        ret
    }
}
