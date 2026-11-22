#include "Storm.h"
#include "D2StormAutoLink.h"

#define BASE 65521
#define GF2_DIM 32

struct D2GameStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2StormTSListStrc;
struct BREAKCMD;
struct D2GameLinkStrc;
struct D2StormGameArrayStrc;
struct D2StormHashObjectChunkStrc;
struct D2StormBreakCmdListStrc;
struct D2GameListStrc;
struct D2StormChunkListStrc;
struct config;
struct deflate_state;
struct inflate_state_00429810;
struct z_stream_00429810;

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2StormTSListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }

    void sub_00426CF0_UnlinkAll();
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
extern char gszTypeNameBreakCmd_007088D8[]; // 0x007088D8
extern "C" const char gszSGameDataTypeName[]; // 0x0070F56C
extern char gszTypeNameHashObjectChunk_0070F5F4[]; // 0x0070F5F4

struct BREAKCMD
{
    D2StormLinkStrc f_0;
    int nData;
};

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;

    D2GameLinkStrc()
    {
        pPrevLink = 0;
        pNext = 0;
    }
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;
    char unk0x14[0x1DE0];
};

struct D2StormGameArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2GameStrc* f_8;
    unsigned int f_C;

    D2StormGameArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameArrayStrc m_array;
    D2StormLinkStrc f_10;
};

struct D2StormBreakCmdListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00426B00_LinkNode(BREAKCMD* pNode, unsigned int nLinkType, BREAKCMD* pExisting); // 0x00426B00
    BREAKCMD* sub_00426DC0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2GameListStrc
{
    int m_linkoffset;
    D2GameLinkStrc m_terminator;

    void sub_004502A0_LinkNode(D2GameStrc* pNode, unsigned int nLinkType, D2GameStrc* pExisting);          // 0x004502A0
    D2GameStrc* sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_004508A0_LinkNode(D2StormHashObjectChunkStrc* pNode, unsigned int nLinkType, D2StormHashObjectChunkStrc* pExisting); // 0x004508A0
    D2StormHashObjectChunkStrc* sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

extern "C" void* __cdecl memset(void* pDest, int nValue, size_t nSize); // 0x00681EF0

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

extern config configuration_table[10]; // 0x006D0280
int __fastcall deflateResetKeep(z_stream* strm); // 0x00427160

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

typedef long z_off_t;

typedef long long z_off64_t;

inline void* operator new(unsigned int nSize, void* pWhere) throw();
static unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2);

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00426910
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

void __cdecl sub_00601B50_Empty()
{
}

char* __fastcall sub_00601B60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00601C60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00601CE0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x004269A0
void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00601E10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00426BD0
void D2StormLinkStrc::sub_00426BD0()
{
    Unlink();
}

// 0x00426CF0
void D2StormTSListStrc::sub_00426CF0_UnlinkAll()
{
    while (char* pNode = Head())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00426DC0
BREAKCMD* D2StormBreakCmdListStrc::sub_00426DC0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(BREAKCMD) + nExtraBytes, gszTypeNameBreakCmd_007088D8, -2, nFlags | 8);
    BREAKCMD* pNode = pMemory ? new (pMemory) BREAKCMD : 0;
    if (nLocation)
        sub_00426B00_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// 0x00450390
D2GameStrc* D2GameListStrc::sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2GameStrc) + nExtraBytes, gszSGameDataTypeName, -2, nFlags | 8);
    D2GameStrc* pNode = pMemory ? new (pMemory) D2GameStrc : 0;
    if (nLocation)
        sub_004502A0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// 0x00450FA0
D2StormHashObjectChunkStrc* D2StormChunkListStrc::sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHashObjectChunkStrc) + nExtraBytes, gszTypeNameHashObjectChunk_0070F5F4, -2, nFlags | 8);
    D2StormHashObjectChunkStrc* pNode = pMemory ? new (pMemory) D2StormHashObjectChunkStrc : 0;
    if (nLocation)
        sub_004508A0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

#include "gen/data/Source/Storm/Unknown_00426910.inc"

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

// 0x0042B8E0
static unsigned long __stdcall adler32_combine_(unsigned long adler1, unsigned long adler2, z_off64_t len2)
{
    unsigned long sum1;
    unsigned long sum2;
    unsigned rem;

    if (len2 < 0)
        return 0xffffffffUL;
    len2 %= BASE;
    rem = (unsigned)len2;
    sum1 = adler1 & 0xffff;
    sum2 = rem * sum1;
    sum2 %= BASE;
    sum1 += (adler2 & 0xffff) + BASE - 1;
    sum2 += ((adler1 >> 16) & 0xffff) + ((adler2 >> 16) & 0xffff) + BASE - rem;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum2 >= (BASE << 1)) sum2 -= (BASE << 1);
    if (sum2 >= BASE) sum2 -= BASE;
    return sum1 | (sum2 << 16);
}

// 0x0042B990
unsigned long __fastcall adler32_combine(unsigned long adler1, unsigned long adler2, z_off_t len2)
{
    return adler32_combine_(adler1, adler2, len2);
}

// 0x0042B9B0
unsigned long __fastcall adler32_combine64(unsigned long adler1, unsigned long adler2, z_off64_t len2)
{
    return adler32_combine_(adler1, adler2, len2);
}

// 0x0042D9F0
static unsigned long gf2_matrix_times(unsigned long* mat, unsigned long vec)
{
    unsigned long sum;

    sum = 0;
    while (vec) {
        if (vec & 1)
            sum ^= *mat;
        vec >>= 1;
        mat++;
    }
    return sum;
}

unsigned long __fastcall crc32_combine(unsigned long crc1, unsigned long crc2, long len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

unsigned long __fastcall crc32_combine64(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

// 0x0042DA10
static void gf2_matrix_square(unsigned long* square, unsigned long* mat)
{
    int n;

    for (n = 0; n < GF2_DIM; n++)
        square[n] = gf2_matrix_times(mat, mat[n]);
}

// 0x0042DA50
static unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    int n;
    unsigned long row;
    unsigned long even[GF2_DIM];
    unsigned long odd[GF2_DIM];

    if (len2 <= 0)
        return crc1;

    odd[0] = 0xedb88320UL;
    row = 1;
    for (n = 1; n < GF2_DIM; n++) {
        odd[n] = row;
        row <<= 1;
    }

    gf2_matrix_square(even, odd);

    gf2_matrix_square(odd, even);

    do {
        gf2_matrix_square(even, odd);
        if (len2 & 1)
            crc1 = gf2_matrix_times(even, crc1);
        len2 >>= 1;

        if (len2 == 0)
            break;

        gf2_matrix_square(odd, even);
        if (len2 & 1)
            crc1 = gf2_matrix_times(odd, crc1);
        len2 >>= 1;

    } while (len2 != 0);

    crc1 ^= crc2;
    return crc1;
}
