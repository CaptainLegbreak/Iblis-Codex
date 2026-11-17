struct D2BitBufferStrc;

unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020

// 0x0062A960
static __forceinline unsigned int sub_0062A960_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

unsigned int __fastcall sub_M111_Emit_0062A960(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_0062A960_ReadBits(pBuffer, nBits) + 1;
}
