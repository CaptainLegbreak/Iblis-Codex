unsigned int gnStringCopyCheck;        // 0x007788D8
void __stdcall sub_0041C340_SetLastError(unsigned int); // 0x0041C340
// 0x004135D0
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit)
{
 int valid=-1;
 valid&=dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int end=(unsigned int)dest+limit-1;
 int offset=(unsigned int)dest-end;
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
  unsigned int ones=0xFFFFFFFF;
  ones-=word;
  unsigned int check=(word+0x7EFEFEFF)^ones;
  ones|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   ones-=word;
   check=(word+0x7EFEFEFF)^ones;
   ones|=word;
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
   gnStringCopyCheck=check;
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
