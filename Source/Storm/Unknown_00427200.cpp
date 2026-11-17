#include "Storm.h"

struct gz_header;

struct deflate_state
{
    char unk0x00[0x18];
    int wrap;
    gz_header* gzhead;
};

struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    char unk0x0C[0x10];
    deflate_state* state;
    char unk0x20[0x10];
    unsigned long adler;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len);          // 0x0042B660
unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len);              // 0x0042DC00

// 0x00427200
int __fastcall deflateSetHeader(z_stream* strm, gz_header* head)
{
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    if (strm->state->wrap != 2) return Z_STREAM_ERROR;
    strm->state->gzhead = head;
    return Z_OK;
}

// 0x00427700
static unsigned read_buf(z_stream* strm, unsigned char* buf, unsigned size)
{
    unsigned len = strm->avail_in;

    if (len > size) len = size;
    if (len == 0) return 0;

    strm->avail_in -= len;

    memcpy(buf, strm->next_in, len);
    if (strm->state->wrap == 1) {
        strm->adler = adler32(strm->adler, buf, len);
    }
    else if (strm->state->wrap == 2) {
        strm->adler = crc32(strm->adler, buf, len);
    }
    strm->next_in += len;
    strm->total_in += len;

    return len;
}

unsigned __fastcall sub_M126_Emit_00427700(z_stream* strm, unsigned char* buf, unsigned size, int nUnused)
{
    return read_buf(strm, buf, size);
}

// 0x0042DC50
const char* __fastcall zError(int err)
{
    return ERR_MSG(err);
}
