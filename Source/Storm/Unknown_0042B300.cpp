// Altered from the original zlib source.
struct inflate_state
{
    int mode;
    char pad04[0x24];
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
    unsigned long hold;
    unsigned int bits;
    char pad40[0x28];
    unsigned int have;
};

struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char* msg;
    inflate_state* state;
};

int __fastcall inflateResetKeep(z_stream* strm);                                                            // 0x00429810

static __forceinline int inflateReset_Inl(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    state->wsize = 0;
    state->whave = 0;
    state->wnext = 0;
    return inflateResetKeep(strm);
}

// 0x0042B300
static unsigned __stdcall syncsearch(unsigned* have, const unsigned char* buf, unsigned len)
{
    unsigned got;
    unsigned next;

    got = *have;
    next = 0;
    while (next < len && got < 4) {
        if ((int)(buf[next]) == (got < 2 ? 0 : 0xff))
            got++;
        else if (buf[next])
            got = 0;
        else
            got = 4 - got;
        next++;
    }
    *have = got;
    return next;
}

// 0x0042B360
int __fastcall inflateSync(z_stream* strm)
{
    unsigned len;
    unsigned long in, out;
    unsigned char buf[4];
    inflate_state* state;

    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    if (strm->avail_in == 0 && state->bits < 8) return -5;

    if (state->mode != 31) {
        state->mode = 31;
        state->hold <<= state->bits & 7;
        state->bits -= state->bits & 7;
        len = 0;
        while (state->bits >= 8) {
            buf[len++] = (unsigned char)(state->hold);
            state->hold >>= 8;
            state->bits -= 8;
        }
        state->have = 0;
        syncsearch(&(state->have), buf, len);
    }

    len = syncsearch(&(state->have), strm->next_in, strm->avail_in);
    strm->avail_in -= len;
    strm->next_in += len;
    strm->total_in += len;

    if (state->have != 4) return -3;
    in = strm->total_in;  out = strm->total_out;
    inflateReset_Inl(strm);
    strm->total_in = in;  strm->total_out = out;
    state->mode = 11;
    return 0;
}
