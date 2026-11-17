struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned int total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned int total_out;
    char* msg;
    void* state;
    void* (__fastcall* zalloc)(void* opaque, unsigned int nItems, unsigned int nSize);
    void (__fastcall* zfree)(void* opaque, void* pAddress);
    void* opaque;
    int data_type;
    unsigned int adler;
    unsigned int reserved;
};

struct D2StormZArenaStrc
{
    char* f_0;
    unsigned int nSize;
    char* f_8;
};

int __fastcall deflateInit_(z_stream* strm, int level, const char* version, int stream_size);              // 0x004297F0
int __fastcall deflate(z_stream* strm, int flush);                                                          // 0x00428C60
int __fastcall deflateEnd(z_stream* strm);                                                                  // 0x004274A0
void* __fastcall sub_0041E080_ZAlloc(void* pArena, unsigned int nItems, unsigned int nSize);                // 0x0041E080
void __fastcall sub_0041E0D0_ZFree(void* pArena, void* pAddress);                                           // 0x0041E0D0

// 0x0041E100
static int __stdcall sub_0041E100_compress2(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen, int level)
{
    char aBuffer[0x493E0];
    D2StormZArenaStrc tArena;
    z_stream stream;
    int err;
    stream.next_in = (unsigned char*)source;
    stream.avail_in = sourceLen;
    stream.next_out = dest;
    stream.avail_out = *destLen;
    tArena.f_0 = aBuffer;
    tArena.nSize = sizeof(aBuffer);
    tArena.f_8 = aBuffer;
    stream.zalloc = sub_0041E080_ZAlloc;
    stream.zfree = sub_0041E0D0_ZFree;
    stream.opaque = &tArena;
    err = deflateInit_(&stream, level, "1.1.3", sizeof(stream));
    if (err != 0)
    {
        return err;
    }
    err = deflate(&stream, 4);
    if (err != 1)
    {
        deflateEnd(&stream);
        return err == 0 ? -5 : err;
    }
    *destLen = stream.total_out;
    err = deflateEnd(&stream);
    return err;
}

// 0x0041E1F0
void __fastcall sub_0041E1F0_SCompZlibCompress(unsigned char* pOut, unsigned long* pOutSize, const unsigned char* pIn, unsigned long nInSize, int* pnResult, int nLevel)
{
    int nZLevel;
    switch (nLevel)
    {
    case 1:
        nZLevel = 9;
        break;
    case 2:
        nZLevel = 1;
        break;
    default:
        nZLevel = -1;
        break;
    }
    unsigned long nDestLen = *pOutSize;
    if (sub_0041E100_compress2(pOut, &nDestLen, pIn, nInSize, nZLevel) == 0)
    {
        *pOutSize = nDestLen;
    }
    *pnResult = 0;
}
