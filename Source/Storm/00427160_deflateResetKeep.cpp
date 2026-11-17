// Altered from the original zlib source.
#define Z_NULL          0
#define Z_OK            0
#define Z_STREAM_ERROR  (-2)
#define Z_DATA_ERROR    (-3)
#define Z_NO_FLUSH      0
#define Z_UNKNOWN       2
#define INIT_STATE      42
#define EXTRA_STATE     69
#define NAME_STATE      73
#define COMMENT_STATE   91
#define HCRC_STATE      103
#define BUSY_STATE      113
#define FINISH_STATE    666

typedef void* (__fastcall* alloc_func)(void* opaque, unsigned int items, unsigned int size);
typedef void (__fastcall* free_func)(void* opaque, void* address);

struct z_stream
{
    char pad00[0x8];
    unsigned long total_in;
    char pad0C[0x8];
    unsigned long total_out;
    char* msg;
    void* state;
    alloc_func zalloc;
    free_func zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

struct deflate_state
{
    z_stream* strm;
    int status;
    unsigned char* pending_buf;
    unsigned long pending_buf_size;
    unsigned char* pending_out;
    unsigned int pending;
    int wrap;
    void* gzhead;
    unsigned int gzindex;
    unsigned char method;
    char pad25[0x3];
    int last_flush;
    char pad2C[0xC];
    unsigned char* window;
    char pad3C[0x4];
    unsigned short* prev;
    unsigned short* head;
};

struct inflate_state
{
    char pad00[0x34];
    unsigned char* window;
};

unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len);              // 0x0042DC00
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len);          // 0x0042B660
void __fastcall _tr_init(deflate_state* s);                                                                 // 0x0042CCD0

#define ZFREE(strm, addr) (*((strm)->zfree))((strm)->opaque, (void*)(addr))
#define TRY_FREE(s, p) { if (p) ZFREE(s, p); }

// build: symbol ?_tr_init@@YIXPAUdeflate_state@@@Z 0x0042CCD0
// 0x00427160
int __fastcall deflateResetKeep(z_stream* strm)
{
    deflate_state* s;
    if (strm == Z_NULL || strm->state == Z_NULL || strm->zalloc == (alloc_func)0 || strm->zfree == (free_func)0)
    {
        return Z_STREAM_ERROR;
    }
    strm->total_in = strm->total_out = 0;
    strm->msg = Z_NULL;
    strm->data_type = Z_UNKNOWN;
    s = (deflate_state*)strm->state;
    s->pending = 0;
    s->pending_out = s->pending_buf;
    if (s->wrap < 0)
    {
        s->wrap = -s->wrap;
    }
    s->status = s->wrap ? INIT_STATE : BUSY_STATE;
    strm->adler = s->wrap == 2 ? crc32(0L, Z_NULL, 0) : adler32(0L, Z_NULL, 0);
    s->last_flush = Z_NO_FLUSH;
    _tr_init(s);
    return Z_OK;
}

// 0x004274A0
int __fastcall deflateEnd(z_stream* strm)
{
    int status;
    if (strm == Z_NULL || strm->state == Z_NULL)
        return Z_STREAM_ERROR;
    status = ((deflate_state*)strm->state)->status;
    if (status != INIT_STATE && status != EXTRA_STATE && status != NAME_STATE && status != COMMENT_STATE && status != HCRC_STATE && status != BUSY_STATE && status != FINISH_STATE)
    {
        return Z_STREAM_ERROR;
    }
    TRY_FREE(strm, ((deflate_state*)strm->state)->pending_buf);
    TRY_FREE(strm, ((deflate_state*)strm->state)->head);
    TRY_FREE(strm, ((deflate_state*)strm->state)->prev);
    TRY_FREE(strm, ((deflate_state*)strm->state)->window);
    ZFREE(strm, strm->state);
    strm->state = Z_NULL;
    return status == BUSY_STATE ? Z_DATA_ERROR : Z_OK;
}

// 0x0042B170
int __fastcall inflateEnd(z_stream* strm)
{
    inflate_state* state;
    if (strm == Z_NULL || strm->state == Z_NULL || strm->zfree == (free_func)0)
        return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (state->window != Z_NULL)
        ZFREE(strm, state->window);
    ZFREE(strm, strm->state);
    strm->state = Z_NULL;
    return Z_OK;
}
