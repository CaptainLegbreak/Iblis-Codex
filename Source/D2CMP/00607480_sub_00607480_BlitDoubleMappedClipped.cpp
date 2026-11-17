// 0x00607480
void __fastcall sub_00607480_BlitDoubleMappedClipped(const unsigned char* source, unsigned char* destination, int rows, int pitch, int x, int left, int right, const unsigned char* outer, const unsigned char* inner)
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
   switch((end-skip)&7){
    case 7: destination[6]=outer[inner[source[6]]];
    case 6: destination[5]=outer[inner[source[5]]];
    case 5: destination[4]=outer[inner[source[4]]];
    case 4: destination[3]=outer[inner[source[3]]];
    case 3: destination[2]=outer[inner[source[2]]];
    case 2: destination[1]=outer[inner[source[1]]];
    case 1: destination[0]=outer[inner[source[0]]];
    case 0:
     destination+=(end-skip)&7;source+=(end-skip)&7;
     if(count){
      do{
       destination[7]=outer[inner[source[7]]];
       destination[6]=outer[inner[source[6]]];
       destination[5]=outer[inner[source[5]]];
       destination[4]=outer[inner[source[4]]];
       destination[3]=outer[inner[source[3]]];
       destination[2]=outer[inner[source[2]]];
       destination[1]=outer[inner[source[1]]];
       destination[0]=outer[inner[source[0]]];
       --count;
       destination+=8;source+=8;
      }while(count);
     }
   }
   x+=code;source=savedSource+code;destination=savedDestination+code;
  }else{
   x+=code;source+=code;destination+=code;
  }
 }
}
