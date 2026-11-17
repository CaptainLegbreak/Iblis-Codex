// Altered from the original zlib source.
typedef unsigned int size_t;

struct inflate_state
{
    int mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned int dmax;
    unsigned long check;
    unsigned long total;
    void* head;
    unsigned int wbits;
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
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
    void* (__fastcall* zalloc)(void* opaque, unsigned int items, unsigned int size);
    void (__fastcall* zfree)(void* opaque, void* address);
    void* opaque;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);                                // 0x006829C0
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len);          // 0x0042B660

// 0x00429AC0
static int __stdcall updatewindow(z_stream* strm, const unsigned char* end, unsigned copy)
{
    inflate_state* state;
    unsigned dist;

    state = strm->state;
    if (state->window == 0) {
        state->window = (unsigned char*)(*strm->zalloc)(strm->opaque, 1U << state->wbits, sizeof(unsigned char));
        if (state->window == 0) return 1;
    }
    if (state->wsize == 0) {
        state->wsize = 1U << state->wbits;
        state->wnext = 0;
        state->whave = 0;
    }
    if (copy >= state->wsize) {
        memcpy(state->window, end - state->wsize, state->wsize);
        state->wnext = 0;
        state->whave = state->wsize;
    }
    else {
        dist = state->wsize - state->wnext;
        if (dist > copy) dist = copy;
        memcpy(state->window + state->wnext, end - copy, dist);
        copy -= dist;
        if (copy) {
            memcpy(state->window, end - copy, copy);
            state->wnext = copy;
            state->whave = state->wsize;
        }
        else {
            state->wnext += dist;
            if (state->wnext == state->wsize) state->wnext = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}

// 0x0042B220
int __fastcall inflateSetDictionary(z_stream* strm, const unsigned char* dictionary, unsigned dictLength)
{
    inflate_state* state;
    unsigned long dictid;
    int ret;

    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    if (state->wrap != 0 && state->mode != 10)
        return -2;
    if (state->mode == 10) {
        dictid = adler32(0L, 0, 0);
        dictid = adler32(dictid, dictionary, dictLength);
        if (dictid != state->check)
            return -3;
    }
    ret = updatewindow(strm, dictionary + dictLength, dictLength);
    if (ret) {
        state->mode = 30;
        return -4;
    }
    state->havedict = 1;
    return 0;
}
