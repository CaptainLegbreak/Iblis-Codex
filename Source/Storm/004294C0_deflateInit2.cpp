// Altered from the original zlib source.
#define ZLIB_VERSION    "1.2.8"
#define Z_OK            0
#define Z_NEED_DICT     2
#define Z_STREAM_ERROR  (-2)
#define Z_MEM_ERROR     (-4)
#define Z_VERSION_ERROR (-6)
#define Z_DEFLATED      8
#define Z_FIXED         4
#define Z_DEFAULT_COMPRESSION (-1)
#define MAX_MEM_LEVEL   9
#define MAX_WBITS       15
#define MIN_MATCH       3
#define FINISH_STATE    666
#define Z_NULL          0
#define ERR_MSG(err) z_errmsg[Z_NEED_DICT - (err)]

typedef void* (__fastcall* alloc_func)(void* opaque, unsigned int items, unsigned int size);
typedef void (__fastcall* free_func)(void* opaque, void* address);

struct z_stream
{
    char pad00[0x18];
    char* msg;
    void* state;
    alloc_func zalloc;
    free_func zfree;
    void* opaque;
    char pad2C[0xC];
};

struct deflate_state
{
    z_stream* strm;
    int status;
    unsigned char* pending_buf;
    unsigned long pending_buf_size;
    char pad10[0x8];
    int wrap;
    void* gzhead;
    char pad20[0x4];
    unsigned char method;
    char pad25[0x7];
    unsigned int w_size;
    unsigned int w_bits;
    unsigned int w_mask;
    unsigned char* window;
    char pad3C[0x4];
    unsigned short* prev;
    unsigned short* head;
    char pad48[0x4];
    unsigned int hash_size;
    unsigned int hash_bits;
    unsigned int hash_mask;
    unsigned int hash_shift;
    char pad5C[0x28];
    int level;
    int strategy;
    char pad8C[0x160C];
    unsigned char* l_buf;
    unsigned int lit_bufsize;
    char pad16A0[0x4];
    unsigned short* d_buf;
    char pad16A8[0x18];
    unsigned long high_water;
};

struct inflate_state
{
    char pad00[0x34];
    unsigned char* window;
    char pad38[0x1B94];
};

extern const char* const z_errmsg[10];                                                                      // 0x006D3848
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size);                             // 0x0042DC70
void __fastcall zcfree(void* opaque, void* ptr);                                                            // 0x0042DC90
int __fastcall deflateEnd(z_stream* strm);                                                                  // 0x004274A0
int __fastcall deflateReset(z_stream* strm);                                                                // 0x00428C40
int __fastcall inflateReset2(z_stream* strm, int windowBits);                                               // 0x004298B0

// 0x004294C0
int __fastcall deflateInit2_(z_stream* strm, int level, int method, int windowBits, int memLevel, int strategy, const char* version, int stream_size)
{
    deflate_state* s;
    int wrap = 1;
    unsigned short* overlay;

    if (version == Z_NULL || version[0] != ZLIB_VERSION[0] || stream_size != sizeof(z_stream))
    {
        return Z_VERSION_ERROR;
    }
    if (strm == Z_NULL) return Z_STREAM_ERROR;

    strm->msg = Z_NULL;
    if (strm->zalloc == (alloc_func)0)
    {
        strm->zalloc = zcalloc;
        strm->opaque = (void*)0;
    }
    if (strm->zfree == (free_func)0) strm->zfree = zcfree;

    if (level == Z_DEFAULT_COMPRESSION) level = 6;

    if (windowBits < 0)
    {
        wrap = 0;
        windowBits = -windowBits;
    }
    else if (windowBits > 15)
    {
        wrap = 2;
        windowBits -= 16;
    }
    if (memLevel < 1 || memLevel > MAX_MEM_LEVEL || method != Z_DEFLATED ||
        windowBits < 8 || windowBits > 15 || level < 0 || level > 9 ||
        strategy < 0 || strategy > Z_FIXED)
    {
        return Z_STREAM_ERROR;
    }
    if (windowBits == 8) windowBits = 9;
    s = (deflate_state*)(*strm->zalloc)(strm->opaque, 1, sizeof(deflate_state));
    if (s == Z_NULL) return Z_MEM_ERROR;
    strm->state = s;
    s->strm = strm;

    s->wrap = wrap;
    s->gzhead = Z_NULL;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;

    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift = ((s->hash_bits + MIN_MATCH - 1) / MIN_MATCH);

    s->window = (unsigned char*)(*strm->zalloc)(strm->opaque, s->w_size, 2 * sizeof(unsigned char));
    s->prev = (unsigned short*)(*strm->zalloc)(strm->opaque, s->w_size, sizeof(unsigned short));
    s->head = (unsigned short*)(*strm->zalloc)(strm->opaque, s->hash_size, sizeof(unsigned short));

    s->high_water = 0;

    s->lit_bufsize = 1 << (memLevel + 6);

    overlay = (unsigned short*)(*strm->zalloc)(strm->opaque, s->lit_bufsize, sizeof(unsigned short) + 2);
    s->pending_buf = (unsigned char*)overlay;
    s->pending_buf_size = (unsigned long)s->lit_bufsize * (sizeof(unsigned short) + 2L);

    if (s->window == Z_NULL || s->prev == Z_NULL || s->head == Z_NULL || s->pending_buf == Z_NULL)
    {
        s->status = FINISH_STATE;
        strm->msg = (char*)ERR_MSG(Z_MEM_ERROR);
        deflateEnd(strm);
        return Z_MEM_ERROR;
    }
    s->d_buf = overlay + s->lit_bufsize / sizeof(unsigned short);
    s->l_buf = s->pending_buf + (1 + sizeof(unsigned short)) * s->lit_bufsize;

    s->level = level;
    s->strategy = strategy;
    s->method = (unsigned char)method;

    return deflateReset(strm);
}

// 0x00429950
int __fastcall inflateInit2_(z_stream* strm, int windowBits, const char* version, int stream_size)
{
    int ret;
    inflate_state* state;

    if (version == Z_NULL || version[0] != ZLIB_VERSION[0] || stream_size != (int)(sizeof(z_stream)))
        return Z_VERSION_ERROR;
    if (strm == Z_NULL) return Z_STREAM_ERROR;
    strm->msg = Z_NULL;
    if (strm->zalloc == (alloc_func)0)
    {
        strm->zalloc = zcalloc;
        strm->opaque = (void*)0;
    }
    if (strm->zfree == (free_func)0) strm->zfree = zcfree;
    state = (inflate_state*)(*strm->zalloc)(strm->opaque, 1, sizeof(inflate_state));
    if (state == Z_NULL) return Z_MEM_ERROR;
    strm->state = state;
    state->window = Z_NULL;
    ret = inflateReset2(strm, windowBits);
    if (ret != Z_OK)
    {
        (*strm->zfree)(strm->opaque, state);
        strm->state = Z_NULL;
    }
    return ret;
}
