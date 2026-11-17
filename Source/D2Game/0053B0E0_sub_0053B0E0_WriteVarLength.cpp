struct D2BitBufferStrc;

void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0

// 0x0053B0E0
void __fastcall sub_0053B0E0_WriteVarLength(D2BitBufferStrc* pBuffer, unsigned int nValue)
{
    if (nValue < 0x100)
    {
        BITMANIP_Write(pBuffer, 0, 1);
        BITMANIP_Write(pBuffer, nValue, 8);
    }
    else
    {
        BITMANIP_Write(pBuffer, 1, 1);
        if (nValue < 0x10000)
        {
            BITMANIP_Write(pBuffer, 0, 1);
            BITMANIP_Write(pBuffer, nValue, 16);
        }
        else
        {
            BITMANIP_Write(pBuffer, 1, 1);
            BITMANIP_Write(pBuffer, nValue, 32);
        }
    }
}
