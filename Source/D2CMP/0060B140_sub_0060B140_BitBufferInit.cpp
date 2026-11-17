struct D2BitBufferInitStrc
{
    unsigned char* pBuffer;
    unsigned char* pCurrent;
    int nBits;
    int nPos;
};

// 0x0060B140
static void __stdcall sub_0060B140_BitBufferInit(int nSize, unsigned char* pBuffer, D2BitBufferInitStrc* pBitBuf)
{
    pBitBuf->pBuffer = pBuffer;
    pBitBuf->pCurrent = pBuffer;
    pBitBuf->nBits = nSize * 8;
    pBitBuf->nPos = 0;
}

void __stdcall sub_K13_Emit_0060B140(D2BitBufferInitStrc* pBitBuf, unsigned char* pBuffer, int nSize)
{
    sub_0060B140_BitBufferInit(nSize, pBuffer, pBitBuf);
}
