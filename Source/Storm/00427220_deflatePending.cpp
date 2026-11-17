// Altered from the original zlib source.
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" void* __cdecl malloc(unsigned int nSize);                                                        // 0x00683EFD

#define Z_OK            0
#define Z_STREAM_ERROR  (-2)
#define BASE 65521U
#define NMAX 5552
#define DO1(buf, i) { adler += (buf)[i]; sum2 += adler; }
#define DO2(buf, i) DO1(buf, i); DO1(buf, i + 1);
#define DO4(buf, i) DO2(buf, i); DO2(buf, i + 2);
#define DO8(buf, i) DO4(buf, i); DO4(buf, i + 4);
#define DO16(buf) DO8(buf, 0); DO8(buf, 8);

struct z_stream
{
    char unk0x00[0x1C];
    void* state;
};

struct deflate_state
{
    char unk0x00[0x14];
    unsigned int pending;
    char unk0x18[0x64];
    unsigned int max_chain_length;
    unsigned int max_lazy_match;
    char unk0x84[0x8];
    int good_match;
    int nice_match;
    char unk0x94[0x1628];
    int bi_valid;
};

struct inflate_state
{
    char unk0x00[0x2C];
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
};

// 0x00427220
int __fastcall deflatePending(z_stream* strm, unsigned int* pending, int* bits)
{
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    if (pending != 0) *pending = ((deflate_state*)strm->state)->pending;
    if (bits != 0) *bits = ((deflate_state*)strm->state)->bi_valid;
    return Z_OK;
}

// 0x004272F0
int __fastcall deflateTune(z_stream* strm, int good_length, int max_lazy, int nice_length, int max_chain)
{
    deflate_state* s;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;
    s->good_match = good_length;
    s->max_lazy_match = max_lazy;
    s->nice_match = nice_length;
    s->max_chain_length = max_chain;
    return Z_OK;
}

// 0x0042B1B0
int __fastcall inflateGetDictionary(z_stream* strm, unsigned char* dictionary, unsigned int* dictLength)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (state->whave && dictionary != 0)
    {
        memcpy(dictionary, state->window + state->wnext, state->whave - state->wnext);
        memcpy(dictionary + state->whave - state->wnext, state->window, state->wnext);
    }
    if (dictLength != 0) *dictLength = state->whave;
    return Z_OK;
}

// 0x0042B660
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len)
{
    unsigned long sum2;
    unsigned n;

    sum2 = (adler >> 16) & 0xffff;
    adler &= 0xffff;

    if (len == 1)
    {
        adler += buf[0];
        if (adler >= BASE)
            adler -= BASE;
        sum2 += adler;
        if (sum2 >= BASE)
            sum2 -= BASE;
        return adler | (sum2 << 16);
    }

    if (buf == 0)
        return 1L;

    if (len < 16)
    {
        while (len--)
        {
            adler += *buf++;
            sum2 += adler;
        }
        if (adler >= BASE)
            adler -= BASE;
        sum2 %= BASE;
        return adler | (sum2 << 16);
    }

    while (len >= NMAX)
    {
        len -= NMAX;
        n = NMAX / 16;
        do
        {
            DO16(buf);
            buf += 16;
        } while (--n);
        adler %= BASE;
        sum2 %= BASE;
    }

    if (len)
    {
        while (len >= 16)
        {
            len -= 16;
            DO16(buf);
            buf += 16;
        }
        while (len--)
        {
            adler += *buf++;
            sum2 += adler;
        }
        adler %= BASE;
        sum2 %= BASE;
    }

    return adler | (sum2 << 16);
}

// 0x0042DC70
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size)
{
    return malloc(items * size);
}
