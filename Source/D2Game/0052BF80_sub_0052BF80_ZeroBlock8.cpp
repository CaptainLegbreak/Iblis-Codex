void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

// 0x0052BF80
void __fastcall sub_0052BF80_ZeroBlock8(void* pData)
{
    SMemZero(pData, 8);
}
