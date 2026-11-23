#include "Storm.h"

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

int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size); // 0x00429A10
int __fastcall inflate(z_stream* strm, int flush); // 0x00429BB0
int __fastcall inflateEnd(z_stream* strm); // 0x0042B170

// 0x006C79C0
int __fastcall sub_006C79C0_Decompress(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen)
{
    z_stream stream;
    int err;

    stream.next_in = (unsigned char*)source;
    stream.avail_in = (unsigned int)sourceLen;
    if ((unsigned long)stream.avail_in != sourceLen)
        return Z_BUF_ERROR;

    stream.next_out = dest;
    stream.avail_out = (unsigned int)*destLen;
    if ((unsigned long)stream.avail_out != *destLen)
        return Z_BUF_ERROR;

    stream.zalloc = 0;
    stream.zfree = 0;

    err = inflateInit_(&stream, "1.2.8", (int)sizeof(z_stream));
    if (err != Z_OK)
        return err;

    err = inflate(&stream, Z_FINISH);
    if (err != Z_STREAM_END)
    {
        inflateEnd(&stream);
        if (err == Z_NEED_DICT || (err == Z_BUF_ERROR && stream.avail_in == 0))
            return Z_DATA_ERROR;
        return err;
    }
    *destLen = stream.total_out;

    err = inflateEnd(&stream);
    return err;
}
