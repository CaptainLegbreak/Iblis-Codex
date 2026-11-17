unsigned long __stdcall SFileSetFilePointer(void* hFile, long lDistanceToMove, long* plDistanceToMoveHigh, unsigned int dwMoveMethod); // 0x004165A0

// 0x00406940
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod)
{
    return SFileSetFilePointer(hFile, nOffset, pnOffsetHigh, nMethod);
}
