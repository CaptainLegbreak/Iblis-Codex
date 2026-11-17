// Altered from the original zlib source.
#define Z_OK            0
#define Z_STREAM_ERROR  (-2)
#define Z_DATA_ERROR    (-3)

typedef enum
{
    HEAD = 0,
    STORED = 13,
    COPY = 15,
    MATCH = 24
} inflate_mode;

struct code
{
    unsigned char op;
    unsigned char bits;
    unsigned short val;
};

struct gz_header
{
    char unk0x00[0x30];
    int done;
};

struct z_stream
{
    char unk0x00[0x1C];
    void* state;
};

struct inflate_state
{
    inflate_mode mode;
    char unk0x04[0x04];
    int wrap;
    char unk0x0C[0x14];
    gz_header* head;
    unsigned int wbits;
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
    unsigned long hold;
    unsigned int bits;
    unsigned int length;
    unsigned int offset;
    unsigned int extra;
    const code* lencode;
    const code* distcode;
    unsigned int lenbits;
    unsigned int distbits;
    char unk0x5C[0x1BC0 - 0x5C];
    int sane;
    int back;
    unsigned int was;
};

int __fastcall inflateResetKeep(z_stream* strm);                                                            // 0x00429810
extern const code lenfix_006D0300[512];                                                                     // 0x006D0300
extern const code distfix_006D0B00[32];                                                                     // 0x006D0B00

// 0x00429880
int __fastcall inflateReset(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    state->wsize = 0;
    state->whave = 0;
    state->wnext = 0;
    return inflateResetKeep(strm);
}

// 0x00429AA0
static __forceinline void fixedtables(inflate_state* state)
{
    state->lencode = lenfix_006D0300;
    state->lenbits = 9;
    state->distcode = distfix_006D0B00;
    state->distbits = 5;
}

void __fastcall sub_M120_Emit_00429AA0(inflate_state* state, int nUse)
{
    if (nUse)
        fixedtables(state);
}

// 0x0042B2D0
int __fastcall inflateGetHeader(z_stream* strm, gz_header* head)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if ((state->wrap & 2) == 0) return Z_STREAM_ERROR;
    state->head = head;
    head->done = 0;
    return Z_OK;
}

// 0x0042B460
int __fastcall inflateSyncPoint(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    return state->mode == STORED && state->bits == 0;
}

// 0x0042B5E0
int __fastcall inflateUndermine(z_stream* strm, int subvert)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    state->sane = 1;
    return Z_DATA_ERROR;
}

// 0x0042B610
long __fastcall inflateMark(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return -1L << 16;
    state = (inflate_state*)strm->state;
    return ((long)(state->back) << 16) +
        (state->mode == COPY ? state->length :
            (state->mode == MATCH ? state->was - state->length : 0));
}

#include "gen/data/Source/Storm/00429880_inflateReset.inc"
