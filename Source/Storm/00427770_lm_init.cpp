// Altered from the original zlib source.
typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDest, int nValue, size_t nSize);                                     // 0x00681EF0

typedef int (*compress_func)(void* s, int flush);

struct config
{
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    compress_func func;
};

struct deflate_state
{
    char pad00[0x2C];
    unsigned int w_size;
    char pad30[0xC];
    unsigned long window_size;
    char pad40[0x4];
    unsigned short* head;
    unsigned int ins_h;
    unsigned int hash_size;
    char pad50[0xC];
    long block_start;
    unsigned int match_length;
    char pad64[0x4];
    int match_available;
    unsigned int strstart;
    char pad70[0x4];
    unsigned int lookahead;
    unsigned int prev_length;
    unsigned int max_chain_length;
    unsigned int max_lazy_match;
    int level;
    char pad88[0x4];
    unsigned int good_match;
    int nice_match;
    char pad94[0x1620];
    unsigned long insert;
};

struct z_stream
{
    char pad00[0x1C];
    deflate_state* state;
};

extern config configuration_table[10];                                                                      // 0x006D0280
int __fastcall deflateResetKeep(z_stream* strm);                                                            // 0x00427160

// 0x00427770
static void lm_init(deflate_state* s)
{
    s->window_size = (unsigned long)2L * s->w_size;
    s->head[s->hash_size - 1] = 0;
    memset((unsigned char*)s->head, 0, (unsigned)(s->hash_size - 1) * sizeof(*s->head));
    s->max_lazy_match = configuration_table[s->level].max_lazy;
    s->good_match = configuration_table[s->level].good_length;
    s->nice_match = configuration_table[s->level].nice_length;
    s->max_chain_length = configuration_table[s->level].max_chain;
    s->strstart = 0;
    s->block_start = 0L;
    s->lookahead = 0;
    s->insert = 0;
    s->match_length = s->prev_length = 3 - 1;
    s->match_available = 0;
    s->ins_h = 0;
}

// 0x00428C40
int __fastcall deflateReset(z_stream* strm)
{
    int ret;
    ret = deflateResetKeep(strm);
    if (ret == 0)
        lm_init(strm->state);
    return ret;
}
