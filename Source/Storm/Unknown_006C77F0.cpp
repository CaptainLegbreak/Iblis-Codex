#include "Storm.h"

#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_DATA_ERROR    (-3)
#define Z_BUF_ERROR     (-5)
#define Z_FINISH        4
static __declspec(noinline) int __stdcall sub_006C77F0_ConvertFromWide(const unsigned short* source, unsigned int count, const unsigned short* volatile table, char* destination);
static __declspec(noinline) int __cdecl sub_006C78C0_Translate(const unsigned short* pTable, unsigned short* pDest, const unsigned char* pSource, int nCount);

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

// 0x006C77F0
static int __stdcall sub_006C77F0_ConvertFromWide(const unsigned short* source, unsigned int count, const unsigned short* volatile table, char* destination)
{
    if (!count)
    {
        return 0;
    }

    char* out = destination;
    unsigned short ch = *source;
    while (ch && count)
    {
        if (ch < 0x100 && ch == table[ch])
        {
            *out = (char)*source;
        }
        else
        {
            int i = 255;
            const unsigned short* p = &table[253];
            do
            {
                if (ch == p[2])
                {
                    break;
                }
                if (ch == p[1])
                {
                    i -= 1;
                    break;
                }
                if (ch == p[0])
                {
                    i -= 2;
                    break;
                }
                if (ch == p[-1])
                {
                    i -= 3;
                    break;
                }
                if (ch == p[-2])
                {
                    i -= 4;
                    break;
                }
                i -= 5;
                p -= 5;
            }
            while (i > 0);
            *out = (char)(i ? i : '?');
        }
        ch = *++source;
        ++out;
        --count;
    }

    if (count)
    {
        *out++ = 0;
    }

    return out - destination;
}

// 0x006C7920
int __stdcall sub_006C7920_FromWide(char* destination, const unsigned short* source, unsigned int count)
{
    return sub_006C77F0_ConvertFromWide(source, count, gWideTable_006FCFC0, destination);
}

// 0x006C7940
int __stdcall sub_006C7940_FromWide(char* destination, const unsigned short* source, unsigned int count)
{
    return sub_006C77F0_ConvertFromWide(source, count, gWideTable_006FD1C0, destination);
}

// 0x006C78C0
static int __cdecl sub_006C78C0_Translate(const unsigned short* pTable, unsigned short* pDest, const unsigned char* pSource, int nCount)
{
    if (!nCount)
    {
        return 0;
    }

    unsigned short* pWrite = pDest;
    while (*pSource)
    {
        if (!nCount)
        {
            return pWrite - pDest;
        }
        *pWrite = pTable[*pSource];
        ++pSource;
        ++pWrite;
        --nCount;
    }

    if (nCount)
    {
        *pWrite = 0;
        ++pWrite;
    }
    return pWrite - pDest;
}

// 0x006C7980
int __stdcall sub_006C7980_TranslateB(unsigned short* pDest, const unsigned char* pSource, int nCount)
{
    return sub_006C78C0_Translate(gawTranslateTable_006FCFC0, pDest, pSource, nCount);
}

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
