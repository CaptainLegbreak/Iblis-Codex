// 0x005179B3
void __fastcall sub_005179B3_CopyRect(unsigned char* pDest, const unsigned char* pSource, int nDestPitch, int nSourcePitch, int nRows, int nWidth)
{
    int nSourceSkip = nSourcePitch - nWidth;
    int nDestSkip = nDestPitch - nWidth;
    __asm
    {
        mov edi, pDest
        mov esi, pSource
        mov ebx, nRows
    nextrow:
        mov edx, nWidth
        mov ecx, edx
        and edx, 3
        je dwords
        cmp edx, 1
        je one
        cmp edx, 2
        je two
        mov al, [esi]
        mov [edi], al
        mov al, [esi + 1]
        mov [edi + 1], al
        mov al, [esi + 2]
        mov [edi + 2], al
        add edi, 3
        add esi, 3
        jmp dwords
    two:
        mov al, [esi]
        mov [edi], al
        mov al, [esi + 1]
        mov [edi + 1], al
        add edi, 2
        add esi, 2
        jmp dwords
    one:
        mov al, [esi]
        mov [edi], al
        inc edi
        inc esi
    dwords:
        shr ecx, 2
        rep movsd
        add esi, nSourceSkip
        add edi, nDestSkip
        dec ebx
        jne nextrow
    }
}

// 0x00517A36
int __fastcall sub_00517A36_CompareMemory(const void* pFirst, const void* pSecond, unsigned int nSize)
{
    __asm
    {
        mov edi, pFirst
        mov esi, pSecond
        mov edx, nSize
        mov ecx, edx
        and edx, 3
        je dwords
        cmp edx, 1
        je one
        cmp edx, 2
        je two
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        mov al, [esi + 1]
        mov bl, [edi + 1]
        cmp al, bl
        jne different
        mov al, [esi + 2]
        mov bl, [edi + 2]
        cmp al, bl
        jne different
        add edi, 3
        add esi, 3
        jmp dwords
    two:
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        mov al, [esi + 1]
        mov bl, [edi + 1]
        cmp al, bl
        jne different
        add edi, 2
        add esi, 2
        jmp dwords
    one:
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        inc edi
        inc esi
    dwords:
        shr ecx, 2
        repe cmpsd
        jne different
    }
    return 1;
different:
    return 0;
}
