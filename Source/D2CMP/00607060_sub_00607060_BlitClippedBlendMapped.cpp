// 0x00607060
void __fastcall sub_00607060_BlitClippedBlendMapped(const unsigned char* source,unsigned char* destination,int rows,int pitch,int x,int left,int right,const unsigned char* map,const unsigned char* blend)
{
 int initialX=x;
 unsigned char* next=destination+pitch;
 for(;;){
  char code=*source++;
  if(code<0){
   code&=0x7f;
   if(!code){
    if(!--rows)return;
    x=initialX;destination=next;next+=pitch;
   }else{x+=code;destination+=code;}
   continue;
  }
  int skip=left-x;
  if(skip<0)skip=0;
  int end=right-x;
  if(end>code)end=code;
  int count=end-skip;
  if(count>0){
   const unsigned char* savedSource=source;
   unsigned char* savedDestination=destination;
   source+=skip;destination+=skip;
   count>>=3;
   int rest=(end-skip)&7;
   switch(rest){
    case 7: destination[6]=blend[(destination[6]<<8)+map[source[6]]];
    case 6: destination[5]=blend[(destination[5]<<8)+map[source[5]]];
    case 5: destination[4]=blend[(destination[4]<<8)+map[source[4]]];
    case 4: destination[3]=blend[(destination[3]<<8)+map[source[3]]];
    case 3: destination[2]=blend[(destination[2]<<8)+map[source[2]]];
    case 2: destination[1]=blend[(destination[1]<<8)+map[source[1]]];
    case 1: destination[0]=blend[(destination[0]<<8)+map[source[0]]];
    case 0:
     destination+=rest;source+=rest;
     while(count--){
      destination[7]=blend[(destination[7]<<8)+map[source[7]]];
      destination[6]=blend[(destination[6]<<8)+map[source[6]]];
      destination[5]=blend[(destination[5]<<8)+map[source[5]]];
      destination[4]=blend[(destination[4]<<8)+map[source[4]]];
      destination[3]=blend[(destination[3]<<8)+map[source[3]]];
      destination[2]=blend[(destination[2]<<8)+map[source[2]]];
      destination[1]=blend[(destination[1]<<8)+map[source[1]]];
      destination[0]=blend[(destination[0]<<8)+map[source[0]]];
      destination+=8;source+=8;
     }
   }
   x+=code;source=savedSource+code;destination=savedDestination+code;
  }else{
   x+=code;source+=code;destination+=code;
  }
 }
}
