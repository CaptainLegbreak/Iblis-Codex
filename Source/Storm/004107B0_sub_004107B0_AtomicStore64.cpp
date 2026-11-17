// 0x004107B0
void __fastcall sub_004107B0_AtomicStore64(__int64* pDest, const __int64* pSrc)
{
    __asm
    {
        mov edi, ecx
        mov ebx, [edx]
        mov ecx, [edx + 4]
        mov eax, [edi]
        mov edx, [edi + 4]
    retry:
        lock cmpxchg8b qword ptr [edi]
        jne retry
    }
}
