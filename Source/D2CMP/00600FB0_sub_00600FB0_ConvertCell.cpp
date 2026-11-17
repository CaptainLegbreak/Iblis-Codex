extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memmove(void*,const void*,unsigned);
extern const char gszCelCmp[]; // 0x006E5DD0
void* __fastcall FOG_Alloc(unsigned size,const char* file,int line,int zero); // 0x0040B380
#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
// 0x00600FB0
void __stdcall sub_00600FB0_ConvertCell(unsigned* cell,unsigned** output,unsigned* outputSize)
{
 unsigned* cellCopy = cell;
 D2_ASSERT(cellCopy[1]&1,0x2cb);
 D2_ASSERT(cellCopy[0]==5,0x2cc);
 cellCopy[1]|=2;
 for(unsigned i=0;i<cellCopy[4]*(cellCopy[5]);++i) {
  unsigned* frame=(unsigned*)(cellCopy[13+i]+(unsigned)cellCopy);
  cellCopy[13+i]=(unsigned)frame;
  if(frame[7])frame[8]+=(unsigned)cellCopy;else frame[8]=0;
 }
 unsigned count=cellCopy[4]*cellCopy[5];
 unsigned header=24+4*count;
 unsigned size=header;
 for(unsigned i=0;i<count;++i) {
  unsigned* frame=(unsigned*)cellCopy[13+i];
  size+=frame[9]+frame[7]+35;
 }
 unsigned* result=(unsigned*)FOG_Alloc(size,gszCelCmp,0x2e3,0);
 result[0]=6;
 result[1]=((unsigned char)cellCopy[1]&4)|1;
 result[2]=0;result[3]=0;
 result[4]=cellCopy[4];result[5]=cellCopy[5];
 unsigned char* cursor=(unsigned char*)result+header;
 for(unsigned i=0;i<count;++i) {
  result[6+i]=(unsigned)(cursor-(unsigned char*)result);
  unsigned* out=(unsigned*)cursor;
  out[0]=((unsigned*)cellCopy[13+i])[1];
  out[1]=((unsigned*)cellCopy[13+i])[3];
  out[2]=((unsigned*)cellCopy[13+i])[4];
  out[3]=((unsigned*)cellCopy[13+i])[5];
  out[4]=((unsigned*)cellCopy[13+i])[6];
  out[5]=((unsigned*)cellCopy[13+i])[7];
  out[7]=((unsigned*)cellCopy[13+i])[9];
  memmove(out+8,(unsigned*)cellCopy[13+i]+10,out[7]);
  cursor+=out[7]+35;
  if(((unsigned*)cellCopy[13+i])[8]) {
   memmove(cursor,(unsigned*)cellCopy[13+i]+8,((unsigned*)cellCopy[13+i])[7]);
   out[6]=(unsigned)(cursor-(unsigned char*)result);
   cursor+=((unsigned*)cellCopy[13+i])[7];
  }else out[6]=0;
 }
 *output=result;*outputSize=size;
}
