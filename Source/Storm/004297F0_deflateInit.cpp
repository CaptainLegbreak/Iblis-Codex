// Altered from the original zlib source.
#define Z_STREAM_ERROR  (-2)
#define Z_DEFLATED      8
#define MAX_WBITS       15
#define DEF_MEM_LEVEL   8
#define DEF_WBITS       MAX_WBITS
#define Z_DEFAULT_STRATEGY 0

typedef void (__fastcall* free_func)(void* opaque, void* address);

struct z_stream
{
    char unk0x00[0x1C];
    void* state;
    void* zalloc;
    free_func zfree;
    void* opaque;
    char unk0x2C[0x0C];
};

struct inflate_state
{
    char unk0x00[0x08];
    int wrap;
    char unk0x0C[0x18];
    unsigned int wbits;
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
};

int __fastcall deflateInit2_(z_stream* strm, int level, int method, int windowBits, int memLevel, int strategy, const char* version, int stream_size); // 0x004294C0
int __fastcall inflateResetKeep(z_stream* strm);                                                            // 0x00429810
int __fastcall inflateInit2_(z_stream* strm, int windowBits, const char* version, int stream_size);        // 0x00429950

// 0x004297F0
int __fastcall deflateInit_(z_stream* strm, int level, const char* version, int stream_size)
{
    return deflateInit2_(strm, level, Z_DEFLATED, MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY, version, stream_size);
}

static int __fastcall inflateReset(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    state->wsize = 0;
    state->whave = 0;
    state->wnext = 0;
    return inflateResetKeep(strm);
}

// 0x004298B0
int __fastcall inflateReset2(z_stream* strm, int windowBits)
{
    int wrap;
    inflate_state* state;

    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;

    if (windowBits < 0)
    {
        wrap = 0;
        windowBits = -windowBits;
    }
    else
    {
        wrap = (windowBits >> 4) + 1;
        if (windowBits < 48)
            windowBits &= 15;
    }

    if (windowBits && (windowBits < 8 || windowBits > 15))
        return Z_STREAM_ERROR;
    if (state->window != 0 && state->wbits != (unsigned)windowBits)
    {
        (*strm->zfree)(strm->opaque, state->window);
        state->window = 0;
    }

    state->wrap = wrap;
    state->wbits = (unsigned)windowBits;
    return inflateReset(strm);
}

// 0x00429A10
int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size)
{
    return inflateInit2_(strm, DEF_WBITS, version, stream_size);
}
