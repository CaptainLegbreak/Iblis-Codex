#include "Storm.h"

#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_STREAM_ERROR  (-2)
#define Z_DATA_ERROR    (-3)
#define Z_MEM_ERROR     (-4)
#define Z_BUF_ERROR     (-5)
#define Z_FINISH        4
#define Z_BLOCK         5
#define Z_TREES         6
#define Z_DEFLATED      8
#define UPDATEWINDOW updatewindow
#define UPDATE(check, buf, len) \
    (state->flags ? crc32(check, buf, len) : adler32(check, buf, len))
#define CRC2(check, word) \
    do { \
        hbuf[0] = (unsigned char)(word); \
        hbuf[1] = (unsigned char)((word) >> 8); \
        check = crc32(check, hbuf, 2); \
    } while (0)
#define CRC4(check, word) \
    do { \
        hbuf[0] = (unsigned char)(word); \
        hbuf[1] = (unsigned char)((word) >> 8); \
        hbuf[2] = (unsigned char)((word) >> 16); \
        hbuf[3] = (unsigned char)((word) >> 24); \
        check = crc32(check, hbuf, 4); \
    } while (0)
#define LOAD() \
    do { \
        put = strm->next_out; \
        left = strm->avail_out; \
        next = strm->next_in; \
        have = strm->avail_in; \
        hold = state->hold; \
        bits = state->bits; \
    } while (0)
#define RESTORE() \
    do { \
        strm->next_out = put; \
        strm->avail_out = left; \
        strm->next_in = next; \
        strm->avail_in = have; \
        state->hold = hold; \
        state->bits = bits; \
    } while (0)
#define INITBITS() \
    do { \
        hold = 0; \
        bits = 0; \
    } while (0)
#define PULLBYTE() \
    do { \
        if (have == 0) goto inf_leave; \
        have--; \
        hold += (unsigned long)(*next++) << bits; \
        bits += 8; \
    } while (0)
#define NEEDBITS(n) \
    do { \
        while (bits < (unsigned)(n)) \
            PULLBYTE(); \
    } while (0)
#define BITS(n) \
    ((unsigned)hold & ((1U << (n)) - 1))
#define DROPBITS(n) \
    do { \
        hold >>= (n); \
        bits -= (unsigned)(n); \
    } while (0)
#define BYTEBITS() \
    do { \
        hold >>= bits & 7; \
        bits -= bits & 7; \
    } while (0)
#define ZSWAP32(q) ((((q) >> 24) & 0xff) + (((q) >> 8) & 0xff00) + \
                    (((q) & 0xff00) << 8) + (((q) & 0xff) << 24))

struct inflate_state;
struct code;
struct gz_header;

typedef unsigned int size_t;

struct code
{
    unsigned char op;
    unsigned char bits;
    unsigned short val;
};

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
    unsigned int ncode;
    unsigned int nlen;
    unsigned int ndist;
    unsigned int have;
    code* next;
    unsigned short lens[320];
    unsigned short work[288];
    code codes[1444];
    int sane;
    int back;
    unsigned int was;
};

struct z_stream
{
    const unsigned char* next_in;
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
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len); // 0x0042B660

typedef enum {
    HEAD,
    FLAGS,
    TIME,
    OS,
    EXLEN,
    EXTRA,
    NAME,
    COMMENT,
    HCRC,
    DICTID,
    DICT,
    TYPE,
    TYPEDO,
    STORED,
    COPY_,
    COPY,
    TABLE,
    LENLENS,
    CODELENS,
    LEN_,
    LEN,
    LENEXT,
    DIST,
    DISTEXT,
    MATCH,
    LIT,
    CHECK,
    LENGTH,
    DONE,
    BAD,
    MEM,
    SYNC
} inflate_mode;

typedef enum {
    CODES,
    LENS = 1,
    DISTS = 2
} codetype;

struct gz_header
{
    int text;
    unsigned long time;
    int xflags;
    int os;
    unsigned char* extra;
    unsigned int extra_len;
    unsigned int extra_max;
    unsigned char* name;
    unsigned int name_max;
    unsigned char* comment;
    unsigned int comm_max;
    int hcrc;
    int done;
};

unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len); // 0x0042DC00
void __fastcall inflate_fast(z_stream* strm, unsigned start); // 0x0042DCA0
int __fastcall inflate_table(codetype type, unsigned short* lens, unsigned codes, code** table, unsigned* bits, unsigned short* work); // 0x0042E120
extern const code lenfix_006D0300[512]; // 0x006D0300
extern const code distfix_006D0B00[32]; // 0x006D0B00
extern const unsigned short order_006D0B80[19]; // 0x006D0B80

static int __stdcall updatewindow(z_stream* strm, const unsigned char* end, unsigned copy);

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

static void fixedtables(inflate_state* state)
{
    state->lencode = lenfix_006D0300;
    state->lenbits = 9;
    state->distcode = distfix_006D0B00;
    state->distbits = 5;
}

// 0x00429BB0
int __fastcall inflate(z_stream* strm, int flush)
{
    inflate_state* state;
    const unsigned char* next;
    unsigned char* put;
    unsigned have, left;
    unsigned long hold;
    unsigned bits;
    unsigned in, out;
    unsigned copy;
    unsigned char* from;
    code here;
    code last;
    unsigned len;
    int ret;
    unsigned char hbuf[4];

    if (strm == 0 || strm->state == 0 || strm->next_out == 0 ||
        (strm->next_in == 0 && strm->avail_in != 0))
        return Z_STREAM_ERROR;

    state = strm->state;
    if (state->mode == TYPE) state->mode = TYPEDO;
    LOAD();
    in = have;
    out = left;
    ret = Z_OK;
    for (;;)
        switch (state->mode) {
        case HEAD:
            if (state->wrap == 0) {
                state->mode = TYPEDO;
                break;
            }
            NEEDBITS(16);
            if ((state->wrap & 2) && hold == 0x8b1f) {
                state->check = crc32(0L, 0, 0);
                CRC2(state->check, hold);
                INITBITS();
                state->mode = FLAGS;
                break;
            }
            state->flags = 0;
            if (state->head != 0)
                state->head->done = -1;
            if (!(state->wrap & 1) ||
                ((BITS(8) << 8) + (hold >> 8)) % 31) {
                strm->msg = "incorrect header check";
                state->mode = BAD;
                break;
            }
            if (BITS(4) != Z_DEFLATED) {
                strm->msg = "unknown compression method";
                state->mode = BAD;
                break;
            }
            DROPBITS(4);
            len = BITS(4) + 8;
            if (state->wbits == 0)
                state->wbits = len;
            else if (len > state->wbits) {
                strm->msg = "invalid window size";
                state->mode = BAD;
                break;
            }
            state->dmax = 1U << len;
            strm->adler = state->check = adler32(0L, 0, 0);
            state->mode = hold & 0x200 ? DICTID : TYPE;
            INITBITS();
            break;
        case FLAGS:
            NEEDBITS(16);
            state->flags = (int)(hold);
            if ((state->flags & 0xff) != Z_DEFLATED) {
                strm->msg = "unknown compression method";
                state->mode = BAD;
                break;
            }
            if (state->flags & 0xe000) {
                strm->msg = "unknown header flags set";
                state->mode = BAD;
                break;
            }
            if (state->head != 0)
                state->head->text = (int)((hold >> 8) & 1);
            if (state->flags & 0x0200) CRC2(state->check, hold);
            INITBITS();
            state->mode = TIME;
        case TIME:
            NEEDBITS(32);
            if (state->head != 0)
                state->head->time = hold;
            if (state->flags & 0x0200) CRC4(state->check, hold);
            INITBITS();
            state->mode = OS;
        case OS:
            NEEDBITS(16);
            if (state->head != 0) {
                state->head->xflags = (int)(hold & 0xff);
                state->head->os = (int)(hold >> 8);
            }
            if (state->flags & 0x0200) CRC2(state->check, hold);
            INITBITS();
            state->mode = EXLEN;
        case EXLEN:
            if (state->flags & 0x0400) {
                NEEDBITS(16);
                state->length = (unsigned)(hold);
                if (state->head != 0)
                    state->head->extra_len = (unsigned)hold;
                if (state->flags & 0x0200) CRC2(state->check, hold);
                INITBITS();
            }
            else if (state->head != 0)
                state->head->extra = 0;
            state->mode = EXTRA;
        case EXTRA:
            if (state->flags & 0x0400) {
                copy = state->length;
                if (copy > have) copy = have;
                if (copy) {
                    if (state->head != 0 &&
                        state->head->extra != 0) {
                        len = state->head->extra_len - state->length;
                        memcpy(state->head->extra + len, next,
                                len + copy > state->head->extra_max ?
                                state->head->extra_max - len : copy);
                    }
                    if (state->flags & 0x0200)
                        state->check = crc32(state->check, next, copy);
                    have -= copy;
                    next += copy;
                    state->length -= copy;
                }
                if (state->length) goto inf_leave;
            }
            state->length = 0;
            state->mode = NAME;
        case NAME:
            if (state->flags & 0x0800) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                    if (state->head != 0 &&
                            state->head->name != 0 &&
                            state->length < state->head->name_max)
                        state->head->name[state->length++] = (unsigned char)len;
                } while (len && copy < have);
                if (state->flags & 0x0200)
                    state->check = crc32(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            }
            else if (state->head != 0)
                state->head->name = 0;
            state->length = 0;
            state->mode = COMMENT;
        case COMMENT:
            if (state->flags & 0x1000) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                    if (state->head != 0 &&
                            state->head->comment != 0 &&
                            state->length < state->head->comm_max)
                        state->head->comment[state->length++] = (unsigned char)len;
                } while (len && copy < have);
                if (state->flags & 0x0200)
                    state->check = crc32(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            }
            else if (state->head != 0)
                state->head->comment = 0;
            state->mode = HCRC;
        case HCRC:
            if (state->flags & 0x0200) {
                NEEDBITS(16);
                if (hold != (state->check & 0xffff)) {
                    strm->msg = "header crc mismatch";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            if (state->head != 0) {
                state->head->hcrc = (int)((state->flags >> 9) & 1);
                state->head->done = 1;
            }
            strm->adler = state->check = crc32(0L, 0, 0);
            state->mode = TYPE;
            break;
        case DICTID:
            NEEDBITS(32);
            strm->adler = state->check = ZSWAP32(hold);
            INITBITS();
            state->mode = DICT;
        case DICT:
            if (state->havedict == 0) {
                RESTORE();
                return Z_NEED_DICT;
            }
            strm->adler = state->check = adler32(0L, 0, 0);
            state->mode = TYPE;
        case TYPE:
            if (flush == Z_BLOCK || flush == Z_TREES) goto inf_leave;
        case TYPEDO:
            if (state->last) {
                BYTEBITS();
                state->mode = CHECK;
                break;
            }
            NEEDBITS(3);
            state->last = BITS(1);
            DROPBITS(1);
            switch (BITS(2)) {
            case 0:
                state->mode = STORED;
                break;
            case 1:
                fixedtables(state);
                state->mode = LEN_;
                if (flush == Z_TREES) {
                    DROPBITS(2);
                    goto inf_leave;
                }
                break;
            case 2:
                state->mode = TABLE;
                break;
            case 3:
                strm->msg = "invalid block type";
                state->mode = BAD;
            }
            DROPBITS(2);
            break;
        case STORED:
            BYTEBITS();
            NEEDBITS(32);
            if ((hold & 0xffff) != ((hold >> 16) ^ 0xffff)) {
                strm->msg = "invalid stored block lengths";
                state->mode = BAD;
                break;
            }
            state->length = (unsigned)hold & 0xffff;
            INITBITS();
            state->mode = COPY_;
            if (flush == Z_TREES) goto inf_leave;
        case COPY_:
            state->mode = COPY;
        case COPY:
            copy = state->length;
            if (copy) {
                if (copy > have) copy = have;
                if (copy > left) copy = left;
                if (copy == 0) goto inf_leave;
                memcpy(put, next, copy);
                have -= copy;
                next += copy;
                left -= copy;
                put += copy;
                state->length -= copy;
                break;
            }
            state->mode = TYPE;
            break;
        case TABLE:
            NEEDBITS(14);
            state->nlen = BITS(5) + 257;
            DROPBITS(5);
            state->ndist = BITS(5) + 1;
            DROPBITS(5);
            state->ncode = BITS(4) + 4;
            DROPBITS(4);
            if (state->nlen > 286 || state->ndist > 30) {
                strm->msg = "too many length or distance symbols";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = LENLENS;
        case LENLENS:
            while (state->have < state->ncode) {
                NEEDBITS(3);
                state->lens[order_006D0B80[state->have++]] = (unsigned short)BITS(3);
                DROPBITS(3);
            }
            while (state->have < 19)
                state->lens[order_006D0B80[state->have++]] = 0;
            state->next = state->codes;
            state->lencode = (const code*)(state->next);
            state->lenbits = 7;
            ret = inflate_table(CODES, state->lens, 19, &(state->next),
                                &(state->lenbits), state->work);
            if (ret) {
                strm->msg = "invalid code lengths set";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = CODELENS;
        case CODELENS:
            while (state->have < state->nlen + state->ndist) {
                for (;;) {
                    here = state->lencode[BITS(state->lenbits)];
                    if ((unsigned)(here.bits) <= bits) break;
                    PULLBYTE();
                }
                if (here.val < 16) {
                    DROPBITS(here.bits);
                    state->lens[state->have++] = here.val;
                }
                else {
                    if (here.val == 16) {
                        NEEDBITS(here.bits + 2);
                        DROPBITS(here.bits);
                        if (state->have == 0) {
                            strm->msg = "invalid bit length repeat";
                            state->mode = BAD;
                            break;
                        }
                        len = state->lens[state->have - 1];
                        copy = 3 + BITS(2);
                        DROPBITS(2);
                    }
                    else if (here.val == 17) {
                        NEEDBITS(here.bits + 3);
                        DROPBITS(here.bits);
                        len = 0;
                        copy = 3 + BITS(3);
                        DROPBITS(3);
                    }
                    else {
                        NEEDBITS(here.bits + 7);
                        DROPBITS(here.bits);
                        len = 0;
                        copy = 11 + BITS(7);
                        DROPBITS(7);
                    }
                    if (state->have + copy > state->nlen + state->ndist) {
                        strm->msg = "invalid bit length repeat";
                        state->mode = BAD;
                        break;
                    }
                    while (copy--)
                        state->lens[state->have++] = (unsigned short)len;
                }
            }

            if (state->mode == BAD) break;

            if (state->lens[256] == 0) {
                strm->msg = "invalid code -- missing end-of-block";
                state->mode = BAD;
                break;
            }

            state->next = state->codes;
            state->lencode = (const code*)(state->next);
            state->lenbits = 9;
            ret = inflate_table(LENS, state->lens, state->nlen, &(state->next),
                                &(state->lenbits), state->work);
            if (ret) {
                strm->msg = "invalid literal/lengths set";
                state->mode = BAD;
                break;
            }
            state->distcode = (const code*)(state->next);
            state->distbits = 6;
            ret = inflate_table(DISTS, state->lens + state->nlen, state->ndist,
                            &(state->next), &(state->distbits), state->work);
            if (ret) {
                strm->msg = "invalid distances set";
                state->mode = BAD;
                break;
            }
            state->mode = LEN_;
            if (flush == Z_TREES) goto inf_leave;
        case LEN_:
            state->mode = LEN;
        case LEN:
            if (have >= 6 && left >= 258) {
                RESTORE();
                inflate_fast(strm, out);
                LOAD();
                if (state->mode == TYPE)
                    state->back = -1;
                break;
            }
            state->back = 0;
            for (;;) {
                here = state->lencode[BITS(state->lenbits)];
                if ((unsigned)(here.bits) <= bits) break;
                PULLBYTE();
            }
            if (here.op && (here.op & 0xf0) == 0) {
                last = here;
                for (;;) {
                    here = state->lencode[last.val +
                            (BITS(last.bits + last.op) >> last.bits)];
                    if ((unsigned)(last.bits + here.bits) <= bits) break;
                    PULLBYTE();
                }
                DROPBITS(last.bits);
                state->back += last.bits;
            }
            DROPBITS(here.bits);
            state->back += here.bits;
            state->length = (unsigned)here.val;
            if ((int)(here.op) == 0) {
                state->mode = LIT;
                break;
            }
            if (here.op & 32) {
                state->back = -1;
                state->mode = TYPE;
                break;
            }
            if (here.op & 64) {
                strm->msg = "invalid literal/length code";
                state->mode = BAD;
                break;
            }
            state->extra = (unsigned)(here.op) & 15;
            state->mode = LENEXT;
        case LENEXT:
            if (state->extra) {
                NEEDBITS(state->extra);
                state->length += BITS(state->extra);
                DROPBITS(state->extra);
                state->back += state->extra;
            }
            state->was = state->length;
            state->mode = DIST;
        case DIST:
            for (;;) {
                here = state->distcode[BITS(state->distbits)];
                if ((unsigned)(here.bits) <= bits) break;
                PULLBYTE();
            }
            if ((here.op & 0xf0) == 0) {
                last = here;
                for (;;) {
                    here = state->distcode[last.val +
                            (BITS(last.bits + last.op) >> last.bits)];
                    if ((unsigned)(last.bits + here.bits) <= bits) break;
                    PULLBYTE();
                }
                DROPBITS(last.bits);
                state->back += last.bits;
            }
            DROPBITS(here.bits);
            state->back += here.bits;
            if (here.op & 64) {
                strm->msg = "invalid distance code";
                state->mode = BAD;
                break;
            }
            state->offset = (unsigned)here.val;
            state->extra = (unsigned)(here.op) & 15;
            state->mode = DISTEXT;
        case DISTEXT:
            if (state->extra) {
                NEEDBITS(state->extra);
                state->offset += BITS(state->extra);
                DROPBITS(state->extra);
                state->back += state->extra;
            }
            state->mode = MATCH;
        case MATCH:
            if (left == 0) goto inf_leave;
            copy = out - left;
            if (state->offset > copy) {
                copy = state->offset - copy;
                if (copy > state->whave) {
                    if (state->sane) {
                        strm->msg = "invalid distance too far back";
                        state->mode = BAD;
                        break;
                    }
                }
                if (copy > state->wnext) {
                    copy -= state->wnext;
                    from = state->window + (state->wsize - copy);
                }
                else
                    from = state->window + (state->wnext - copy);
                if (copy > state->length) copy = state->length;
            }
            else {
                from = put - state->offset;
                copy = state->length;
            }
            if (copy > left) copy = left;
            left -= copy;
            state->length -= copy;
            do {
                *put++ = *from++;
            } while (--copy);
            if (state->length == 0) state->mode = LEN;
            break;
        case LIT:
            if (left == 0) goto inf_leave;
            *put++ = (unsigned char)(state->length);
            left--;
            state->mode = LEN;
            break;
        case CHECK:
            if (state->wrap) {
                NEEDBITS(32);
                out -= left;
                strm->total_out += out;
                state->total += out;
                if (out)
                    strm->adler = state->check =
                        UPDATE(state->check, put - out, out);
                out = left;
                if ((
                     state->flags ? hold :
                     ZSWAP32(hold)) != state->check) {
                    strm->msg = "incorrect data check";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            state->mode = LENGTH;
        case LENGTH:
            if (state->wrap && state->flags) {
                NEEDBITS(32);
                if (hold != (state->total & 0xffffffffUL)) {
                    strm->msg = "incorrect length check";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            state->mode = DONE;
        case DONE:
            ret = Z_STREAM_END;
            goto inf_leave;
        case BAD:
            ret = Z_DATA_ERROR;
            goto inf_leave;
        case MEM:
            return Z_MEM_ERROR;
        case SYNC:
        default:
            return Z_STREAM_ERROR;
        }

  inf_leave:
    RESTORE();
    if (state->wsize || (out != strm->avail_out && state->mode < BAD &&
            (state->mode < CHECK || flush != Z_FINISH)))
        if (UPDATEWINDOW(strm, strm->next_out, out - strm->avail_out)) {
            state->mode = MEM;
            return Z_MEM_ERROR;
        }
    in -= strm->avail_in;
    out -= strm->avail_out;
    strm->total_in += in;
    strm->total_out += out;
    state->total += out;
    if (state->wrap && out)
        strm->adler = state->check =
            UPDATE(state->check, strm->next_out - out, out);
    strm->data_type = state->bits + (state->last ? 64 : 0) +
                      (state->mode == TYPE ? 128 : 0) +
                      (state->mode == LEN_ || state->mode == COPY_ ? 256 : 0);
    if (((in == 0 && out == 0) || flush == Z_FINISH) && ret == Z_OK)
        ret = Z_BUF_ERROR;
    return ret;
}

#include "gen/data/Source/Storm/Unknown_00429AC0.inc"
