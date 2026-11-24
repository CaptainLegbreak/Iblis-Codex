#include "D2CMP.h"

struct D2BitBufferInitStrc;
struct D2BitBufferInitStrc {
 unsigned char* pBuffer; unsigned char* pCurrent; int nBits; int nPos;
};
// 0x0060B160
static void __stdcall sub_0060B160_Copy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {
 dst->pBuffer=src->pBuffer;
 dst->pCurrent=src->pCurrent;
 dst->nBits=src->nBits;
 dst->nPos=src->nPos;
}

void __stdcall EmitCopy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {sub_0060B160_Copy(dst,src);}
