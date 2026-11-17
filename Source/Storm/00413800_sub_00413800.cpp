void __stdcall sub_0041C340_SetLastError(unsigned int); // 0x0041C340
extern unsigned int gdwSStrScanWord_007788D8; // 0x007788D8
// 0x00413800
unsigned int __stdcall sub_00413800(char* dest, const char* source, unsigned int limit)
{
 int valid=(__int64)dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int dwOnes = 0xFFFFFFFF;
 const char* p = dest;
 unsigned int end=(unsigned int)dest+limit-1;
 if(limit!=0x7FFFFFFF) *(char*)end=0;
 while ((unsigned int)p & 3)
 {
  if (!*p) goto scanned;
  ++p;
 }
 for (;;)
 {
  const unsigned int w = *(const unsigned int*)p;
  dwOnes -= w;
  unsigned int dwTest = (w + 0x7EFEFEFF) ^ dwOnes;
  p += 4;
  dwOnes |= w;
  dwTest &= 0x81010101;
  if (dwTest)
  {
   if (!(char)w) { p -= 4; break; }
   if (!(char)(w >> 8)) { p -= 3; break; }
   if (!(w & 0xFF0000)) { p -= 2; break; }
   if (!(w & 0xFF000000)) { p -= 1; break; }
   gdwSStrScanWord_007788D8 = dwTest;
  }
 }
scanned:
 int offset=(unsigned int)p-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  dwOnes-=word;
  unsigned int check=(word+0x7EFEFEFF)^dwOnes;
  dwOnes|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   dwOnes-=word;
   check=(word+0x7EFEFEFF)^dwOnes;
   dwOnes|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gdwSStrScanWord_007788D8=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}
