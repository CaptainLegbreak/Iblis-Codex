extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
#pragma intrinsic(memset)
#pragma pack(push,1)
struct D2CharInfo { char pad[0xbd]; char name[0x132]; unsigned short flags; };
#pragma pack(pop)
struct Unicode { unsigned short ch; Unicode(unsigned short value=0):ch(value){} };
D2CharInfo* __cdecl sub_0044B7A0_GetCharInfo(); // 0x0044B7A0
int __fastcall sub_00501820(const Unicode*); // 0x00501820
void __fastcall sub_00502320(const Unicode*,int,int,int,int); // 0x00502320
const char* __stdcall D2Win_10161(unsigned int,int,int,int); // 0x005068A0
void __fastcall sub_00526320_ToUnicode(Unicode*,const char*,int); // 0x00526320
extern int gnScreenWidth; // 0x0071146C
extern int gbExpansion; // 0x007A04F4
extern unsigned char gnClass; // 0x007A0522
extern unsigned char gnDifficulty; // 0x007A060C
extern "C" char* __cdecl strcpy(char*,const char*);
extern "C" char* __cdecl strcat(char*,const char*);
// 0x0044E5A0
void __cdecl sub_0044E5A0_DrawOverlayB() {
 D2CharInfo* info=sub_0044B7A0_GetCharInfo();
 Unicode nameText[100];
 char name[100];
 strcpy(name,info->name);
 sub_00526320_ToUnicode(nameText,name,64);
 int halfNameWidth=sub_00501820(nameText)/2;
 sub_00502320(nameText,gnScreenWidth/2-halfNameWidth,187,4,0);
 int hardcore=info->flags&4;
 int expansion=info->flags&0x20;
 unsigned char classId=gnClass;
 Unicode titleText[100];
 char title[100];
 const char* text;
 int difficulty=gnDifficulty;
 if(difficulty==0) {
  int level=expansion?5:4;
  if(hardcore)text=D2Win_10161(classId,level,hardcore,expansion);
  else text=D2Win_10161(classId,level,0,expansion);
 } else if(difficulty==1) {
  int level=expansion?10:8;
  if(hardcore)text=D2Win_10161(classId,level,hardcore,expansion);
  else text=D2Win_10161(classId,level,0,expansion);
 } else if(difficulty==2) {
  int level=expansion?15:12;
  if(hardcore)text=D2Win_10161(classId,level,hardcore,expansion);
  else text=D2Win_10161(classId,level,0,expansion);
 } else return;
 if(text) {
  strcpy(title,text);strcat(title,name);
  sub_00526320_ToUnicode(titleText,title,64);
  int x=gnScreenWidth/2-sub_00501820(titleText)/2;
  int y=277; if(gbExpansion)y=357;
  sub_00502320(titleText,x,y,4,0);
 }
}
