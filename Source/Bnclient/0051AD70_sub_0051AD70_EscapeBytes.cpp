void __stdcall SMemCopy(void*, const void*, unsigned int); // 0x0041D2A0
// 0x0051AD70
int __fastcall sub_0051AD70_EscapeBytes(unsigned char* data, unsigned int length)
{
 if(length>0) {
 unsigned int i=0;
 do {
  if(i==255)return 0;
  if(data[0]==0) {
   SMemCopy(data+2,data+1,256);
   ++length;
   data[1]=1;
   data[0]=255;
   ++data;
   ++i;
  } else if(data[0]==255) {
   SMemCopy(data+2,data+1,256);
   ++length;
   data[1]=255;
   data[0]=255;
   ++data;
   ++i;
  }
 ++i;
 ++data;
 } while(i<length);
 }
 return 1;
}
