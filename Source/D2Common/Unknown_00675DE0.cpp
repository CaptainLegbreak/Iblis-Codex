#ifdef MOVED_TEST
#define LARGE_SHIFT 20
#define SMALL_SHIFT 12
#else
#define LARGE_SHIFT 16
#define SMALL_SHIFT 8
#endif
struct D2DrlgCoordStrc { int nPosX,nPosY,nWidth,nHeight; };

// 0x00675DE0
static __declspec(noinline) void __fastcall sub_00675DE0_Place(D2DrlgCoordStrc* src,int mode,int side,D2DrlgCoordStrc* dst) {
 switch(side) {
 case 0:
  dst->nPosX=src->nPosX;
  dst->nPosY=src->nHeight+src->nPosY;
  if(mode==1) dst->nPosX-=LARGE_SHIFT;
  break;
 case 1:
  dst->nPosX=src->nPosX-dst->nWidth;
  dst->nPosY=src->nPosY;
  if(mode==1) dst->nPosY-=LARGE_SHIFT;
  else if(mode==2) dst->nPosY+=SMALL_SHIFT;
  break;
 case 2:
  dst->nPosX=src->nWidth-dst->nWidth+src->nPosX;
  dst->nPosY=src->nPosY-dst->nHeight;
  if(mode==1) dst->nPosX+=LARGE_SHIFT;
  break;
 case 3:
  dst->nPosX=src->nWidth+src->nPosX;
  dst->nPosY=src->nHeight-dst->nHeight+src->nPosY;
  if(mode==1) dst->nPosY+=LARGE_SHIFT;
  else if(mode==2) dst->nPosY-=SMALL_SHIFT;
  else if(mode==3) dst->nPosY+=SMALL_SHIFT;
  break;
 }
}

void __fastcall EmitPlacement(D2DrlgCoordStrc* src,int mode,int side,D2DrlgCoordStrc* dst) {
 sub_00675DE0_Place(src,mode,side,dst);
}
