#include "Storm.h"

#define ZLIB_VERSION    "1.2.8"
#define Z_VERSION_ERROR (-6)
#define MAX_MEM_LEVEL   9
#define MIN_MATCH       3
#define FINISH_STATE    666

struct D2StormLinkStrc;
struct D2StormBreakCmdListStrc;
struct D2StormListAStrc;
struct D2StormListFixedArrayStrc;
struct D2SGameDataStrc;
struct D2StormGameDataArrayStrc;
struct deflate_state;
struct inflate_state;
struct code;
struct gz_header;

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x004133D0
extern const char gszTypeSGameData_0070F56C[]; // 0x0070F56C
extern const char gszTypeExplicitList_0070F584[]; // 0x0070F584

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormBreakCmdListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* sub_00426F20_DeleteNode(char* pNode);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;

    ~D2StormListFixedArrayStrc();
};

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    D2SGameDataStrc(const D2SGameDataStrc& tSource);                                                        // 0x00450950
    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;

    void sub_00450D90_ReallocData(unsigned int nAlloc);
};

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

typedef enum
{
    HEAD = 0,
    STORED = 13,
    COPY = 15,
    MATCH = 24
} inflate_mode;

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
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size); // 0x0042DC70
void __fastcall zcfree(void* opaque, void* ptr); // 0x0042DC90
int __fastcall deflateEnd(z_stream* strm); // 0x004274A0
int __fastcall deflateReset(z_stream* strm); // 0x00428C40
int __fastcall inflateReset2(z_stream* strm, int windowBits); // 0x004298B0

struct gz_header
{
    char unk0x00[0x30];
    int done;
};

int __fastcall inflateResetKeep(z_stream* strm); // 0x00429810
extern const code lenfix_006D0300[512]; // 0x006D0300
extern const code distfix_006D0B00[32]; // 0x006D0B00

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00426F20
char* D2StormBreakCmdListStrc::sub_00426F20_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormLinkStrc*)pNode)->Unlink();
    SMemFree(pNode, gszTypeBreakCmd_007088D8, -2, 0);
    return pNext;
}

// 0x0044FF60
D2StormListFixedArrayStrc::~D2StormListFixedArrayStrc()
{
    for (unsigned int i = 0; i < f_4; i++)
        f_8[i].~D2StormListAStrc();
    if (f_8)
        SMemFree(f_8, gszTypeExplicitList_0070F584, -2, 0);
}

// 0x00450D90
void D2StormGameDataArrayStrc::sub_00450D90_ReallocData(unsigned int nAlloc)
{
    D2SGameDataStrc* pOld = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOld[i].~D2SGameDataStrc();
    f_0 = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2SGameDataStrc), gszTypeSGameData_0070F56C, -2, 0x10);
    f_8 = (D2SGameDataStrc*)pNew;
    if (!pNew)
    {
        f_8 = (D2SGameDataStrc*)SMemAlloc(nAlloc * sizeof(D2SGameDataStrc), gszTypeSGameData_0070F56C, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= f_4 ? f_4 : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&f_8[i]) D2SGameDataStrc(pOld[i]);
                pOld[i].~D2SGameDataStrc();
            }
            SMemFree(pOld, gszTypeSGameData_0070F56C, -2, 0);
        }
    }
}

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

#include "gen/data/Source/Storm/Unknown_00426F20.inc"
