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

int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size);                         // 0x00429A10
int __fastcall inflate(z_stream* strm, int flush);                                                          // 0x00429BB0
int __fastcall inflateEnd(z_stream* strm);                                                                  // 0x0042B170
void* __fastcall sub_0041E080_ZAlloc(void* pArena, unsigned int nItems, unsigned int nSize);                // 0x0041E080
void __fastcall sub_0041E0D0_ZFree(void* pArena, void* pAddress);                                           // 0x0041E0D0

// 0x0041E250
static int __stdcall sub_0041E250_uncompress(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen)
{
    char aBuffer[0xB798];
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
    err = inflateInit_(&stream, "1.1.3", sizeof(stream));
    if (err != 0)
    {
        return err;
    }
    err = inflate(&stream, 4);
    if (err != 1)
    {
        inflateEnd(&stream);
        return err == 0 ? -5 : err;
    }
    *destLen = stream.total_out;
    err = inflateEnd(&stream);
    return err;
}

// 0x0041E340
int __fastcall sub_0041E340_SCompZlibDecompress(unsigned char* pOut, unsigned long* pOutSize, const unsigned char* pIn, unsigned long nInSize, int nUnused)
{
    return sub_0041E250_uncompress(pOut, pOutSize, pIn, nInSize);
}
