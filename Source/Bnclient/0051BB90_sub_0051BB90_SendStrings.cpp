extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* text,const char* file,int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int code); // 0x00681E09
unsigned int __stdcall SStrLen(const char* text); // 0x00413750
extern "C" void* __cdecl memcpy(void* dest,const void* source,unsigned int count); // 0x006829C0
int __fastcall sub_0051C5C0_SendPacket(unsigned char type,const void* data,unsigned int size); // 0x0051C5C0
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48
#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
// 0x0051BB90
int __fastcall sub_0051BB90_SendStrings(const char* first,const char* second,const char* third)
{
 char buffer[768];
 D2_ASSERT(first,1433);
 D2_ASSERT(*first,1434);
 if(!second || !*second || !third || !*third) return 0;
 unsigned int firstSize=SStrLen(first)+1;
 D2_ASSERT(firstSize<=256,1444);
 memcpy(buffer,first,firstSize);
 char* cursor=buffer+firstSize;
 char** ppCursor=&cursor;
 unsigned int secondSize=SStrLen(second)+1;
 D2_ASSERT(secondSize<=256,1452);
 memcpy(*ppCursor,second,secondSize);
 *ppCursor+=secondSize;
 unsigned int thirdSize=SStrLen(third)+1;
 D2_ASSERT(thirdSize<=256,1460);
 memcpy(*ppCursor,third,thirdSize);
 return sub_0051C5C0_SendPacket(0x5B,buffer,thirdSize+secondSize+firstSize)>=0;
}
