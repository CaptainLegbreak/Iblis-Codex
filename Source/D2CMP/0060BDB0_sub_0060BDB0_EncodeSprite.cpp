struct D2SpritePixelsStrc { int unknown00,width,height; char unknown0C[0x14]; unsigned char* pixels; int pitch; int topDown; };
struct D2SpriteCelStrc { int unknown00[7]; unsigned int dataSize; };
void __cdecl sub_00410610_ReportError(const char* message); // 0x00410610
void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0
// 0x0060BDB0
int __fastcall sub_0060BDB0_EncodeSprite(D2SpritePixelsStrc* sprite,D2SpriteCelStrc* cel,unsigned char* output)
{
 unsigned char* dest=output;
 unsigned char* row=sprite->pixels;
 int y;
 int step=sprite->topDown?sprite->pitch:-sprite->pitch;
 if(!sprite->topDown) row+=(sprite->height-1)*sprite->pitch;
 for(y=0;y<sprite->height;) {
  int x=0;
  while(x<sprite->width) {
   int start=x;
   while(x<sprite->width && !row[x]) ++x;
   if(x>=sprite->width) break;
   if(x>start) do {
    int count=x-start;
    if(count>127) count=127;
    *dest++=(unsigned char)(count|0x80);
    start+=count;
   } while(start<x);
   start=x;
   while(x<sprite->width && row[x]) ++x;
   if(x>start) do {
    int count=x-start;
    if(count>127) count=127;
    *dest++=(unsigned char)count;
    sub_006829C0_Copy(dest,row+start,count);
    dest+=count;
    start+=count;
   } while(start<x);
  }
  *dest++=0x80;
  ++y;
  row+=step;
 }
 if(dest!=(unsigned char*)cel+32+cel->dataSize) {
  sub_00410610_ReportError("Sprite Decompression Error");
  return 0;
 }
 return 1;
}
