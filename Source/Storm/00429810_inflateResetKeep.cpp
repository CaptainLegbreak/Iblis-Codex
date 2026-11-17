// Altered from the original zlib source.
struct inflate_state_00429810
{
    int mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned dmax;
    unsigned long check;
    unsigned long total;
    void* head;
    unsigned wbits;
    unsigned wsize;
    unsigned whave;
    unsigned wnext;
    unsigned char* window;
    unsigned long hold;
    unsigned bits;
    unsigned length;
    unsigned offset;
    unsigned extra;
    const void* lencode;
    const void* distcode;
    unsigned lenbits;
    unsigned distbits;
    unsigned ncode;
    unsigned nlen;
    unsigned ndist;
    unsigned have;
    void* next;
    unsigned short lens[320];
    unsigned short work[288];
    unsigned int codes[1444];
    int sane;
    int back;
    unsigned was;
};
struct z_stream_00429810
{
    unsigned char* next_in;
    unsigned avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned avail_out;
    unsigned long total_out;
    char* msg;
    inflate_state_00429810* state;
    void* zalloc;
    void* zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

// 0x00429810
int __fastcall inflateResetKeep(z_stream_00429810* strm)
{
    inflate_state_00429810* state;

    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    strm->total_in = strm->total_out = state->total = 0;
    strm->msg = 0;
    if (state->wrap)
        strm->adler = state->wrap & 1;
    state->mode = 0;
    state->last = 0;
    state->havedict = 0;
    state->dmax = 32768U;
    state->head = 0;
    state->hold = 0;
    state->bits = 0;
    state->lencode = state->distcode = state->next = state->codes;
    state->sane = 1;
    state->back = -1;
    return 0;
}
