extern "C" void* __cdecl memset(void*,int,unsigned int);
struct D2TileBlockStrc {
 short x,y;
 int unk04;
 unsigned short flags;
 unsigned short unk0A;
 int unk0C;
 const unsigned char* data;
};
struct D2TileStrc { int unk00[20]; int count; D2TileBlockStrc* blocks; };
extern int gnHeight_009702B8; // 0x009702B8
extern unsigned short gwPalette_0096FA80[]; // 0x0096FA80
// 0x006BB720
void __stdcall sub_006BB720_RenderTile(D2TileStrc* tile,unsigned short* output,int stride)
{
 memset(output,0,gnHeight_009702B8*stride*sizeof(unsigned short));
 for(int i=0;i<tile->count;++i) {
  D2TileBlockStrc* block=&tile->blocks[i];
  unsigned short* dest=output+block->y*stride+block->x;
  if(block->flags&1) {
   if(block->flags&4) {
    const unsigned char* data=block->data;
    int rows=15;
    unsigned short* row=dest;
    unsigned short* p=dest;
    do {
     unsigned char skip=*data++;
     unsigned char count=*data++;
     if(!skip&&!count) {
      row+=stride;
      --rows;
      p=row;
     } else {
      p+=skip;
      while(count) {
       --count;
       *p++=gwPalette_0096FA80[*data++];
      }
     }
    } while(rows);
   } else {
    int count=4;
    unsigned short* row=dest+14;
    const unsigned char* data=block->data;
    int y=0;
    do {
     unsigned short* pixel=row;
     const unsigned char* source=data;
     if(count>0) {
      int n=count;
      do {
       *pixel++=gwPalette_0096FA80[*source++];
      } while(--n);
     }
     data+=count;
     if(y<7) {
      row+=stride-2;
      count+=4;
     } else {
      row+=stride+2;
      count-=4;
     }
    } while(++y<15);
   }
  }
 }
}
