// Altered from the original zlib source.
#define Z_OK            0
#define Z_STREAM_ERROR  (-2)
#define Z_MEM_ERROR     (-4)
#define Z_BUF_ERROR     (-5)
#define Z_BLOCK         5
#define Z_FIXED         4
#define Z_DEFAULT_COMPRESSION (-1)
#define Buf_size        16
#define LITERALS        256
#define ENOUGH          1444
#define Z_NULL          0

typedef void* (__fastcall* alloc_func)(void* opaque, unsigned int items, unsigned int size);
typedef void (__fastcall* free_func)(void* opaque, void* address);
typedef unsigned short (__fastcall* compress_func)(void* s, int flush);

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize);                      // 0x006829C0

struct ct_data
{
    unsigned short freq;
    unsigned short dad;
};

struct tree_desc
{
    ct_data* dyn_tree;
    int max_code;
    void* stat_desc;
};

struct code
{
    unsigned char op;
    unsigned char bits;
    unsigned short val;
};

struct config
{
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    compress_func func;
};

struct z_stream
{
    char pad00[0x8];
    unsigned long total_in;
    char pad0C[0x10];
    void* state;
    alloc_func zalloc;
    free_func zfree;
    void* opaque;
    char pad2C[0xC];
};

struct gz_header
{
    char pad00[0x10];
    unsigned char* extra;
    unsigned int extra_len;
    char pad18[0x4];
    unsigned char* name;
    char pad20[0x4];
    unsigned char* comment;
    char pad28[0x4];
    int hcrc;
    char pad30[0x4];
};

struct deflate_state
{
    z_stream* strm;
    char pad04[0x4];
    unsigned char* pending_buf;
    unsigned long pending_buf_size;
    unsigned char* pending_out;
    unsigned int pending;
    int wrap;
    gz_header* gzhead;
    char pad20[0xC];
    unsigned int w_size;
    unsigned int w_bits;
    char pad34[0x4];
    unsigned char* window;
    char pad3C[0x4];
    unsigned short* prev;
    unsigned short* head;
    char pad48[0x4];
    unsigned int hash_size;
    unsigned int hash_bits;
    char pad54[0x18];
    unsigned int strstart;
    char pad70[0xC];
    unsigned int max_chain_length;
    unsigned int max_lazy_match;
    int level;
    int strategy;
    unsigned int good_match;
    int nice_match;
    ct_data dyn_ltree[573];
    ct_data dyn_dtree[61];
    ct_data bl_tree[39];
    tree_desc l_desc;
    tree_desc d_desc;
    tree_desc bl_desc;
    char padB3C[0xB5C];
    unsigned char* l_buf;
    unsigned int lit_bufsize;
    char pad16A0[0x4];
    unsigned short* d_buf;
    char pad16A8[0x10];
    unsigned short bi_buf;
    char pad16BA[0x2];
    int bi_valid;
    char pad16C0[0x4];
};

struct inflate_state
{
    char pad00[0x24];
    unsigned int wbits;
    char pad28[0xC];
    unsigned char* window;
    unsigned long hold;
    unsigned int bits;
    char pad40[0xC];
    code* lencode;
    code* distcode;
    char pad54[0x18];
    code* next;
    char pad70[0x4C0];
    code codes[1444];
    char pad1BC0[0xC];
};

extern config configuration_table[10];                                                                      // 0x006D0280
int __fastcall deflateEnd(z_stream* strm);                                                                  // 0x004274A0
int __fastcall deflate(z_stream* strm, int flush);                                                          // 0x00428C60
void __fastcall _tr_flush_bits(deflate_state* s);                                                           // 0x0042D150
unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2);              // 0x0042DA50

// build: symbol ?_tr_flush_bits@@YIXPAUdeflate_state@@@Z 0x0042D150
// 0x00427260
int __fastcall deflatePrime(z_stream* strm, int bits, int value)
{
    deflate_state* s;
    int put;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;
    if ((unsigned char*)(s->d_buf) < s->pending_out + ((Buf_size + 7) >> 3))
        return Z_BUF_ERROR;
    do {
        put = Buf_size - s->bi_valid;
        if (put > bits)
            put = bits;
        s->bi_buf |= (unsigned short)((value & ((1 << put) - 1)) << s->bi_valid);
        s->bi_valid += put;
        _tr_flush_bits(s);
        value >>= put;
        bits -= put;
    } while (bits);
    return Z_OK;
}

// 0x00427330
unsigned long __fastcall deflateBound(z_stream* strm, unsigned long sourceLen)
{
    deflate_state* s;
    unsigned long complen, wraplen;
    unsigned char* str;

    complen = sourceLen + ((sourceLen + 7) >> 3) + ((sourceLen + 63) >> 6) + 5;

    if (strm == Z_NULL || strm->state == Z_NULL)
        return complen + 6;

    s = (deflate_state*)strm->state;
    switch (s->wrap) {
    case 0:
        wraplen = 0;
        break;
    case 1:
        wraplen = 6 + (s->strstart ? 4 : 0);
        break;
    case 2:
        wraplen = 18;
        if (s->gzhead != Z_NULL) {
            if (s->gzhead->extra != Z_NULL)
                wraplen += 2 + s->gzhead->extra_len;
            str = s->gzhead->name;
            if (str != Z_NULL)
                do {
                    wraplen++;
                } while (*str++);
            str = s->gzhead->comment;
            if (str != Z_NULL)
                do {
                    wraplen++;
                } while (*str++);
            if (s->gzhead->hcrc)
                wraplen += 2;
        }
        break;
    default:
        wraplen = 6;
    }

    if (s->w_bits != 15 || s->hash_bits != 8 + 7)
        return complen + wraplen;

    return sourceLen + (sourceLen >> 12) + (sourceLen >> 14) + (sourceLen >> 25) + 13 - 6 + wraplen;
}

// 0x00427560
int __fastcall deflateCopy(z_stream* dest, z_stream* source)
{
    deflate_state* ds;
    deflate_state* ss;
    unsigned short* overlay;

    if (source == Z_NULL || dest == Z_NULL || source->state == Z_NULL) {
        return Z_STREAM_ERROR;
    }
    ss = (deflate_state*)source->state;
    memcpy(dest, source, sizeof(z_stream));
    ds = (deflate_state*)dest->zalloc(dest->opaque, 1, sizeof(deflate_state));
    if (ds == Z_NULL) return Z_MEM_ERROR;
    dest->state = ds;
    memcpy(ds, ss, sizeof(deflate_state));
    ds->strm = dest;

    ds->window = (unsigned char*)dest->zalloc(dest->opaque, ds->w_size, 2 * sizeof(unsigned char));
    ds->prev = (unsigned short*)dest->zalloc(dest->opaque, ds->w_size, sizeof(unsigned short));
    ds->head = (unsigned short*)dest->zalloc(dest->opaque, ds->hash_size, sizeof(unsigned short));
    overlay = (unsigned short*)dest->zalloc(dest->opaque, ds->lit_bufsize, sizeof(unsigned short) + 2);
    ds->pending_buf = (unsigned char*)overlay;

    if (ds->window == Z_NULL || ds->prev == Z_NULL || ds->head == Z_NULL || ds->pending_buf == Z_NULL) {
        deflateEnd(dest);
        return Z_MEM_ERROR;
    }
    memcpy(ds->window, ss->window, ds->w_size * 2 * sizeof(unsigned char));
    memcpy(ds->prev, ss->prev, ds->w_size * sizeof(unsigned short));
    memcpy(ds->head, ss->head, ds->hash_size * sizeof(unsigned short));
    memcpy(ds->pending_buf, ss->pending_buf, (unsigned int)ds->pending_buf_size);

    ds->pending_out = ds->pending_buf + (ss->pending_out - ss->pending_buf);
    ds->d_buf = overlay + ds->lit_bufsize / sizeof(unsigned short);
    ds->l_buf = ds->pending_buf + (1 + sizeof(unsigned short)) * ds->lit_bufsize;

    ds->l_desc.dyn_tree = ds->dyn_ltree;
    ds->d_desc.dyn_tree = ds->dyn_dtree;
    ds->bl_desc.dyn_tree = ds->bl_tree;

    return Z_OK;
}

// 0x00429700
int __fastcall deflateParams(z_stream* strm, int level, int strategy)
{
    deflate_state* s;
    compress_func func;
    int err = Z_OK;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;

    if (level == Z_DEFAULT_COMPRESSION) level = 6;
    if (level < 0 || level > 9 || strategy < 0 || strategy > Z_FIXED) {
        return Z_STREAM_ERROR;
    }
    func = configuration_table[s->level].func;

    if ((strategy != s->strategy || func != configuration_table[level].func) && strm->total_in != 0) {
        err = deflate(strm, Z_BLOCK);
        if (err == Z_BUF_ERROR && s->pending == 0)
            err = Z_OK;
    }
    if (s->level != level) {
        s->level = level;
        s->max_lazy_match = configuration_table[level].max_lazy;
        s->good_match = configuration_table[level].good_length;
        s->nice_match = configuration_table[level].nice_length;
        s->max_chain_length = configuration_table[level].max_chain;
    }
    s->strategy = strategy;
    return err;
}

// 0x00429A30
int __fastcall inflatePrime(z_stream* strm, int bits, int value)
{
    inflate_state* state;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (bits < 0) {
        state->hold = 0;
        state->bits = 0;
        return Z_OK;
    }
    if (bits > 16 || state->bits + bits > 32) return Z_STREAM_ERROR;
    value &= (1L << bits) - 1;
    state->hold += value << state->bits;
    state->bits += bits;
    return Z_OK;
}

// 0x0042B490
int __fastcall inflateCopy(z_stream* dest, z_stream* source)
{
    inflate_state* state;
    inflate_state* copy;
    unsigned char* window;
    unsigned int wsize;

    if (dest == Z_NULL || source == Z_NULL || source->state == Z_NULL || source->zalloc == 0 || source->zfree == 0)
        return Z_STREAM_ERROR;
    state = (inflate_state*)source->state;

    copy = (inflate_state*)source->zalloc(source->opaque, 1, sizeof(inflate_state));
    if (copy == Z_NULL) return Z_MEM_ERROR;
    window = Z_NULL;
    if (state->window != Z_NULL) {
        window = (unsigned char*)source->zalloc(source->opaque, 1U << state->wbits, sizeof(unsigned char));
        if (window == Z_NULL) {
            source->zfree(source->opaque, copy);
            return Z_MEM_ERROR;
        }
    }

    memcpy(dest, source, sizeof(z_stream));
    memcpy(copy, state, sizeof(inflate_state));
    if (state->lencode >= state->codes && state->lencode <= state->codes + ENOUGH - 1) {
        copy->lencode = copy->codes + (state->lencode - state->codes);
        copy->distcode = copy->codes + (state->distcode - state->codes);
    }
    copy->next = copy->codes + (state->next - state->codes);
    if (window != Z_NULL) {
        wsize = 1U << state->wbits;
        memcpy(window, state->window, wsize);
    }
    copy->window = window;
    dest->state = copy;
    return Z_OK;
}

// 0x0042DBC0
unsigned long __fastcall crc32_combine(unsigned long crc1, unsigned long crc2, long len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

// 0x0042DBE0
unsigned long __fastcall crc32_combine64(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

#include "gen/data/Source/Storm/00427260_deflatePrime.inc"
