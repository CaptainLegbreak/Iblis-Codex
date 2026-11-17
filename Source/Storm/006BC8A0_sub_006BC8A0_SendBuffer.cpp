struct D2ConnectionStrc { char unknown000[0x110]; int* active; int unknown114; int kind,version; unsigned char id; };
struct D2PacketHeaderStrc { unsigned char id,command; unsigned short size; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0
int __stdcall sub_006BC860_Send(D2ConnectionStrc*,const unsigned char*,int); // 0x006BC860
// 0x006BC8A0
int __stdcall sub_006BC8A0_SendBuffer(D2ConnectionStrc* connection,const unsigned char* data,int size)
{
 unsigned char buffer[0x2064];
 D2PacketHeaderStrc header;
 if(!connection || !connection->active || !*connection->active) return -1;
 unsigned int payload,total;
 if(connection->kind==4 && connection->version==2) {
  if(!data || (unsigned short)(size-1)>0x205E) {
   sub_00408A60(&gszEmptyAssertText,sub_00408090(),93);
   exit(-1);
  }
  payload=(unsigned short)size;
  SMemCopy(buffer+3,data,payload-1);
  header.size=(unsigned short)(size+3);
  header.command=*data;
  header.id=connection->id;
  SMemCopy(buffer,&header,4);
  total=payload+3;
 } else {
  *(unsigned short*)&header=(unsigned short)(size+2);
  if(*(unsigned short*)&header>=0x2064) {
   sub_00408A60(&gszEmptyAssertText,sub_00408090(),113);
   exit(-1);
  }
  SMemCopy(buffer,&header,2);
  if(!data) size=0;
  payload=(unsigned short)size;
  total=payload+2;
  if(data && total<0x2064) SMemCopy(buffer+2,data,payload);
 }
 return sub_006BC860_Send(connection,buffer,total)+(payload-total);
}
