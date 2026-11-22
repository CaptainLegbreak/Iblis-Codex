#include "Storm.h"
#include "D2GameTypes.h"
#define BASE 65521U
#define NMAX 5552
#define DO1(buf, i) { adler += (buf)[i]; sum2 += adler; }
#define DO2(buf, i) DO1(buf, i); DO1(buf, i + 1);
#define DO4(buf, i) DO2(buf, i); DO2(buf, i + 2);
#define DO8(buf, i) DO4(buf, i); DO4(buf, i + 4);
#define DO16(buf) DO8(buf, 0); DO8(buf, 8);
#define Buf_size        16
#define LITERALS        256
#define ENOUGH          1444
#define DEF_MEM_LEVEL   8
#define DEF_WBITS       MAX_WBITS
#define Z_DEFAULT_STRATEGY 0

struct SEvtBreakCmdStrc;
struct D2StormLinkStrc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct D2CriticalSectionStrc;
struct SEvtLinkStrc;
struct deflate_state;
struct inflate_state;
struct ct_data;
struct tree_desc;
struct code;
struct config;
struct gz_header;

struct D2StormLinkStrc { D2StormLinkStrc* m_prevlink;
 char* m_next; };

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];


struct SEvtLinkStrc
{
    SEvtLinkStrc* pPrevLink;
    SEvtBreakCmdStrc* pNext;

    SEvtLinkStrc() { pPrevLink = 0; pNext = 0; }
    SEvtLinkStrc* NextLink(int nLinkOffset = -1)
    {
        if ((int)pNext < 0)
            return (SEvtLinkStrc*)~(unsigned int)pNext;
        if (nLinkOffset < 0)
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        return (SEvtLinkStrc*)((int)pNext + nLinkOffset);
    }
    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink()->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct SEvtBreakCmdStrc
{
    SEvtLinkStrc f_0;
    void* pData;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
void* __stdcall SMemAlloc(unsigned int nSize, const char* szLogName, int nLogLine, unsigned int nFlags); // 0x00413020
extern "C" const char gszBREAKCMDTypeName[]; // 0x007088D8
extern SEvtLinkStrc gtSEvtBreakCmdTerminator; // 0x007088EC
extern D2CriticalSectionStrc gtSEvtLock; // 0x0077930C
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl malloc(unsigned int nSize); // 0x00683EFD

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
    int good_match;
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
    unsigned int last_lit;
    unsigned short* d_buf;
    unsigned long opt_len;
    unsigned long static_len;
    unsigned int matches;
    unsigned int insert;
    unsigned short bi_buf;
    char pad16BA[0x2];
    int bi_valid;
    char pad16C0[0x4];
};

struct inflate_state
{
    char unk0x00[0x08];
    int wrap;
    char unk0x0C[0x18];
    unsigned int wbits;
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
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

typedef unsigned short (__fastcall* compress_func)(void* s, int flush);

struct config
{
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    compress_func func;
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

extern config configuration_table[10]; // 0x006D0280
int __fastcall deflateEnd(z_stream* strm); // 0x004274A0
void __fastcall _tr_flush_bits(deflate_state* s); // 0x0042D150
unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2); // 0x0042DA50
int __fastcall deflateInit2_(z_stream* strm, int level, int method, int windowBits, int memLevel, int strategy, const char* version, int stream_size); // 0x004294C0
int __fastcall inflateResetKeep(z_stream* strm); // 0x00429810
int __fastcall inflateInit2_(z_stream* strm, int windowBits, const char* version, int stream_size); // 0x00429950
extern "C" const unsigned char _dist_code[]; // 0x006D13D8
extern "C" const unsigned char _length_code[]; // 0x006D15D8
extern "C" void __cdecl free(void* pMemory); // 0x00683FC0
extern char gaTable_0070896C[]; // 0x0070896C

inline void* __cdecl operator new(unsigned int nSize, void* pWhere);

// 0x00426900
char* __fastcall sub_00426900_Next(D2StormLinkStrc* pLink) {
 return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x004269B0
extern "C" void* __fastcall sub_004269B0(void* value) { return value; }

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return f_4;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

// 0x00426A60
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

// 0x00426AC0
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00426C60
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) { return pWhere; }

// 0x00426E80
int __stdcall SEvtBreakHandlerChain(void* pData)
{
    EnterCriticalSection(&gtSEvtLock);
    SEvtBreakCmdStrc* pCmd = new (SMemAlloc(sizeof(SEvtBreakCmdStrc), gszBREAKCMDTypeName, -2, 8)) SEvtBreakCmdStrc;
    SEvtLinkStrc* pLink = pCmd ? &pCmd->f_0 : &gtSEvtBreakCmdTerminator;
    pLink->Unlink();
    SEvtLinkStrc* pTail = gtSEvtBreakCmdTerminator.pPrevLink;
    pLink->pPrevLink = pTail;
    pLink->pNext = pTail->pNext;
    pTail->pNext = pCmd;
    gtSEvtBreakCmdTerminator.pPrevLink = pLink;
    pCmd->pData = pData;
    LeaveCriticalSection(&gtSEvtLock);
    return 1;
}

#include "gen/data/Source/Storm/Unknown_00426900.inc"

// 0x00427220
int __fastcall deflatePending(z_stream* strm, unsigned int* pending, int* bits)
{
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    if (pending != 0) *pending = ((deflate_state*)strm->state)->pending;
    if (bits != 0) *bits = ((deflate_state*)strm->state)->bi_valid;
    return Z_OK;
}

// 0x004272F0
int __fastcall deflateTune(z_stream* strm, int good_length, int max_lazy, int nice_length, int max_chain)
{
    deflate_state* s;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;
    s->good_match = good_length;
    s->max_lazy_match = max_lazy;
    s->nice_match = nice_length;
    s->max_chain_length = max_chain;
    return Z_OK;
}

// 0x0042B1B0
int __fastcall inflateGetDictionary(z_stream* strm, unsigned char* dictionary, unsigned int* dictLength)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (state->whave && dictionary != 0)
    {
        memcpy(dictionary, state->window + state->wnext, state->whave - state->wnext);
        memcpy(dictionary + state->whave - state->wnext, state->window, state->wnext);
    }
    if (dictLength != 0) *dictLength = state->whave;
    return Z_OK;
}

// 0x0042B660
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len)
{
    unsigned long sum2;
    unsigned n;

    sum2 = (adler >> 16) & 0xffff;
    adler &= 0xffff;

    if (len == 1)
    {
        adler += buf[0];
        if (adler >= BASE)
            adler -= BASE;
        sum2 += adler;
        if (sum2 >= BASE)
            sum2 -= BASE;
        return adler | (sum2 << 16);
    }

    if (buf == 0)
        return 1L;

    if (len < 16)
    {
        while (len--)
        {
            adler += *buf++;
            sum2 += adler;
        }
        if (adler >= BASE)
            adler -= BASE;
        sum2 %= BASE;
        return adler | (sum2 << 16);
    }

    while (len >= NMAX)
    {
        len -= NMAX;
        n = NMAX / 16;
        do
        {
            DO16(buf);
            buf += 16;
        } while (--n);
        adler %= BASE;
        sum2 %= BASE;
    }

    if (len)
    {
        while (len >= 16)
        {
            len -= 16;
            DO16(buf);
            buf += 16;
        }
        while (len--)
        {
            adler += *buf++;
            sum2 += adler;
        }
        adler %= BASE;
        sum2 %= BASE;
    }

    return adler | (sum2 << 16);
}

// 0x0042DC70
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size)
{
    return malloc(items * size);
}

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

// 0x004297F0
int __fastcall deflateInit_(z_stream* strm, int level, const char* version, int stream_size)
{
    return deflateInit2_(strm, level, Z_DEFLATED, MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY, version, stream_size);
}

static int __fastcall inflateReset(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    state->wsize = 0;
    state->whave = 0;
    state->wnext = 0;
    return inflateResetKeep(strm);
}

// 0x004298B0
int __fastcall inflateReset2(z_stream* strm, int windowBits)
{
    int wrap;
    inflate_state* state;

    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;

    if (windowBits < 0)
    {
        wrap = 0;
        windowBits = -windowBits;
    }
    else
    {
        wrap = (windowBits >> 4) + 1;
        if (windowBits < 48)
            windowBits &= 15;
    }

    if (windowBits && (windowBits < 8 || windowBits > 15))
        return Z_STREAM_ERROR;
    if (state->window != 0 && state->wbits != (unsigned)windowBits)
    {
        (*strm->zfree)(strm->opaque, state->window);
        state->window = 0;
    }

    state->wrap = wrap;
    state->wbits = (unsigned)windowBits;
    return inflateReset(strm);
}

// 0x00429A10
int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size)
{
    return inflateInit2_(strm, DEF_WBITS, version, stream_size);
}

// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x0042B9D0
void __cdecl sub_0042B9D0_Nop()
{
}

// 0x00650EA0
void __cdecl sub_00650EA0_Nop()
{
}

// build: symbol ?_tr_tally@@YIHPAUdeflate_state@@II@Z 0x0042C600
int __fastcall _tr_tally(deflate_state* s, unsigned int dist, unsigned int lc)
{
    s->d_buf[s->last_lit] = (unsigned short)dist;
    s->l_buf[s->last_lit++] = (unsigned char)lc;
    if (dist == 0) {
        s->dyn_ltree[lc].freq++;
    } else {
        s->matches++;
        dist--;
        s->dyn_ltree[_length_code[lc] + 256 + 1].freq++;
        unsigned int code;
        if (dist < 256)
            code = _dist_code[dist];
        else
            code = _dist_code[256 + (dist >> 7)];
        s->dyn_dtree[code].freq++;
    }
    return (s->last_lit == s->lit_bufsize - 1);
}

// 0x0042D460
static unsigned long crc32_little(unsigned long crc, const unsigned char* buf, unsigned len)
{
    register unsigned long c;
    register const unsigned long* buf4;

    c = (unsigned long)crc;
    c = ~c;
    while (len && ((int)buf & 3)) {
        c = crc_table[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
        len--;
    }

    buf4 = (const unsigned long*)(const void*)buf;
    while (len >= 32) {
        DOLIT32;
        len -= 32;
    }
    while (len >= 4) {
        DOLIT4;
        len -= 4;
    }
    buf = (const unsigned char*)buf4;

    if (len) do {
        c = crc_table[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
    } while (--len);
    c = ~c;
    return (unsigned long)c;
}

// 0x0042DC00
unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len)
{
    if (buf == 0) return 0UL;
    return crc32_little(crc, buf, len);
}

// 0x0042DC90
void __fastcall zcfree(void* opaque, void* ptr)
{
    free(ptr);
}

void* gpOwner_00779324; // 0x00779324

// 0x0042E590
void* __fastcall sub_0042E590_SetOwner(void* pOwner)
{
    gpOwner_00779324 = pOwner;
    return gaTable_0070896C;
}
