struct D2BitBufferInitStrc {
#ifdef MOVED_TEST
 int movedGap;
#endif
 unsigned char* pBuffer; unsigned char* pCurrent; int nBits; int nPos;
};
// 0x0060B160
static __declspec(noinline) void __stdcall sub_0060B160_Copy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {
 dst->pBuffer=src->pBuffer;
 dst->pCurrent=src->pCurrent;
 dst->nBits=src->nBits;
 dst->nPos=src->nPos;
}
void __stdcall EmitCopy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {sub_0060B160_Copy(dst,src);}
