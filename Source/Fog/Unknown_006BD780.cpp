#include "Fog.h"

#define D2_ASSERT(e,n) if(!(e)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),n);exit(-1);}
#define SKIP_CELL() {while(*input) ++input; ++input;}
#define READ_CODE() {*(unsigned*)small=0;int c=0;while(*input){if(c>=4){while(*input)++input;break;}small[c++]=*input++;}++input;}
#define PAD_CODE(dst) {(dst)[3]=' ';if(!small[0]){(dst)[0]=' ';(dst)[1]=' ';(dst)[2]=' ';}else{(dst)[0]=small[0];if(!small[1]){(dst)[1]=' ';(dst)[2]=' ';}else{(dst)[1]=small[1];if(!small[2]){(dst)[2]=' ';}else{(dst)[2]=small[2];if(small[3])(dst)[3]=small[3];}}}}
#define PAD9(dst) {if(!small[0]){(dst)[0]=' ';(dst)[1]=' ';(dst)[2]=' ';(dst)[3]=' ';}else{(dst)[0]=small[0];if(!small[1]){(dst)[1]=' ';(dst)[2]=' ';(dst)[3]=' ';}else{(dst)[1]=small[1];if(!small[2]){(dst)[2]=' ';(dst)[3]=' ';}else{(dst)[2]=small[2];if(!small[3])(dst)[3]=' ';else (dst)[3]=small[3];}}}}

struct D2BinFileStrc;
struct D2BinFieldStrc;
struct D2QServerConfigStrc;
struct D2QueueServerStrc;
struct D2Object006BE390Strc;

struct D2BinFileStrc { char* pDataBuffer; char* pData; int nRecordCount,nCellCount; };

struct D2BinFieldStrc { const char* name; unsigned type; int length,offset; void* link; };

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall sub_006BCE20_MapColumns(unsigned short*,D2BinFileStrc*,D2BinFieldStrc*); // 0x006BCE20
int __stdcall sub_006BD230_AddCode(void*,unsigned); // 0x006BD230
void __stdcall sub_006BD500_AddName(void*,const char*); // 0x006BD500
int __fastcall sub_006BD5A0_AddIndex(void*,const char*); // 0x006BD5A0
int __stdcall sub_006BD130_FindCode(void*,unsigned,int); // 0x006BD130
int __stdcall FOG_GetRowFromTxt(void*,const char*,int); // 0x006BD3C0
void __stdcall sub_00410B10(void*,int); // 0x00410B10
void __stdcall sub_00410B50(void*,int); // 0x00410B50

typedef int (__fastcall* KeyCallback)(const char*);

typedef void (__fastcall* FieldCallback)(const char*,void*,int,int,int,int);

struct D2QueueServerStrc
{
    void* pHandle;
};

unsigned int __fastcall sub_006C3120_Start(D2QueueServerStrc* pServer, int nValue); // 0x006C3120

struct D2Object006BE390Strc
{
    unsigned char unk_000[0xBA8];
    int anSlots[1];
};

// 0x006BD780
void __stdcall sub_006BD780_ParseTable(D2BinFileStrc* bin,D2BinFieldStrc* fields,char* output,unsigned records,unsigned stride)
{
 unsigned short columns[280];
 char small[32];
 char code[4];
 D2_ASSERT(records>0,0x112);
 D2_ASSERT(stride>0,0x113);
 int total=sub_006BCE20_MapColumns(columns,bin,fields);
 int firstPass=0;
 for(int c=0;c<bin->nCellCount;++c) if(columns[c]!=0x7fff) {
  switch(fields[columns[c]].type) {case 10:case 12:case 14:case 16:case 17:case 18:firstPass=1;break;}
 }
 char* originalOutput=output;
 char* input;
 int row,c;
 if(firstPass) {
  input=bin->pData;
  for(row=0;row<bin->nRecordCount;output+=stride,++row) {
   for(c=0;c<bin->nCellCount;++c) {
    if(columns[c]==0x7fff){SKIP_CELL();continue;}
    D2BinFieldStrc* field=&fields[columns[c]];
    char* dst=output+field->offset;
    switch(field->type) {
    case 10:case 12:case 14: {
     READ_CODE(); PAD_CODE(code);
     int index=sub_006BD230_AddCode(*(void**)field->link,*(unsigned*)code);
     switch(field->type) {
      case 10:*(unsigned*)dst=*(unsigned*)code;break;
      case 12:D2_ASSERT(index<=255,0x156);*dst=code[0];break;
      case 14:D2_ASSERT(index<=65535,0x15a);*(unsigned short*)dst=*(unsigned short*)code;break;
     }break;
    }
    case 16:{char* start=dst;char* end=dst+field->length-1;while(*input&&dst<end)*dst++=*input++;*dst=0;while(*input)++input;++input;sub_006BD500_AddName(*(void**)field->link,start);break;}
    case 17:case 18:{char name[32];char* p=name;while(*input&&p<name+31)*p++=*input++;*p=0;while(*input)++input;++input;void* const tArg4 = *(void**)field->link;
    int index=sub_006BD5A0_AddIndex(tArg4,name);char* rec=output+field->offset;if(field->type==17)*(unsigned short*)rec=(unsigned short)index;else *(int*)rec=index;break;}
    default:SKIP_CELL();break;
    }
   }
   D2_ASSERT(*input=='\n',0x185);++input;
  }
 }
 output=originalOutput;input=bin->pData;
 for(row=0;row<bin->nRecordCount;output+=stride,++row){
  for(c=0;c<bin->nCellCount;++c){
   if(columns[c]==0x7fff){SKIP_CELL();continue;}
   char* start=input;
   D2BinFieldStrc* field=&fields[columns[c]];
   int offset=field->offset;
   char* dst=output+field->offset;
   int length=field->length;
   unsigned type=field->type;
   char* end=dst+length;
   switch(type){
   case 1:case 7:{while(*input){if(dst>=end){while(*input)++input;break;}*dst++=*input++;}++input;*dst=0;break;}
   case 9:{READ_CODE();PAD9(dst);break;}
   case 10:case 12:case 14:case 16:case 17:case 18:SKIP_CELL();break;
   case 11:case 13:case 15:{READ_CODE();PAD_CODE(code);int index=sub_006BD130_FindCode(*(void**)field->link,*(unsigned*)code,1);switch(field->type){case 11:*(int*)dst=index;break;case 13:*dst=(char)index;break;case 15:*(unsigned short*)dst=(unsigned short)index;break;}break;}
   case 19:case 20:case 21:{char* p=small;while(*input&&p<small+31)*p++=*input++;*p=0;while(*input)++input;++input;int index=FOG_GetRowFromTxt(*(void**)field->link,small,1);switch(field->type){case 19:*(int*)dst=index;break;case 20:*(unsigned short*)dst=(unsigned short)index;break;case 21:*dst=(char)index;break;}break;}
   case 2:case 3:case 4:case 5:case 6:case 8:case 26:{if(*input=='-')++input;int value=0;while(*input)value=value*10+*input++-'0';if(*start=='-')value=-value;++input;switch(type){case 2:case 8:*(int*)dst=value;break;case 3:*(unsigned short*)dst=(unsigned short)value;break;case 4:case 6:*dst=(char)value;break;case 5:if(start+1!=input)*dst=(char)value;break;case 26:if(value)sub_00410B10(dst,length);else sub_00410B50(dst,length);break;}break;}
   case 22:{char callbackText[256];char* p=callbackText;while(*input){if(p>=callbackText+256){while(*input)++input;break;}*p++=*input++;}++input;*p=0;if(field->link)*(unsigned short*)dst=(unsigned short)((KeyCallback)field->link)(callbackText);break;}
   case 23:case 24:case 25:{char callbackText[256];char* p=callbackText;while(*input){if(p>=callbackText+256){while(*input)++input;break;}*p++=*input++;}if(field->link)++input;else ++input;*p=0;if(field->link)((FieldCallback)field->link)(callbackText,output,offset,length,row,c);break;}
   default:__assume(0);
   }
  }
  for(;c<total;++c){
   D2BinFieldStrc* field=&fields[columns[c]];char* dst=output+field->offset;
   switch(field->type){
   case 1:*dst=0;break;
   case 2:*(int*)dst=0;break;
   case 3:*(unsigned short*)dst=0;break;
   case 4:*dst=0;break;
   case 5:*dst=0;break;
   case 6:*dst=0;break;
   case 7:*dst=0;break;
   case 8:*(int*)dst=0;break;
   case 9:*(int*)dst=0;break;
   case 10:*(int*)dst=0;break;
   case 11:*(int*)dst=-1;break;
   case 12:*dst=0;break;
   case 13:*dst=-1;break;
   case 14:*(unsigned short*)dst=0;break;
   case 15:*(unsigned short*)dst=65535;break;
   case 16:*dst=0;break;
   case 17:*(unsigned short*)dst=0;break;
   case 18:*(int*)dst=0;break;
   case 19:*(unsigned int*)dst=0xFFFFFFFF;break;
   case 20:*(unsigned short*)dst=65535;break;
   case 21:*dst=-1;break;
   case 22:*(unsigned short*)dst=0;break;
   case 23:case 24:case 25:if(field->link)((FieldCallback)field->link)(0,output,field->offset,field->length,row,c);break;
   case 26:break;
   default:__assume(0);
   }
  }
  D2_ASSERT(*input=='\n',0x286);++input;
 }
}

// 0x006BE2F0
void __cdecl sub_006BE2F0_Nop(const char* unused1, const char* unused2, int unused3)
{
}

// 0x006BE300
void __cdecl sub_006BE300_Nop(const char* unused1, const char* unused2, int unused3)
{
}

static int gnLockCount_0074C3E0; // 0x0074C3E0

static int gnGlobal_0074C3E4; // 0x0074C3E4

static int gnGlobal_0074C3E8; // 0x0074C3E8

static int gnGlobal_0074C3EC; // 0x0074C3EC

static int gnGlobal_00989C28; // 0x00989C28

// 0x006BE310
void __stdcall sub_006BE310_SetServerConfig(D2QServerConfigStrc* pConfig)
{
    gnLockCount_0074C3E0 = pConfig->nClientCapacity;
    gnGlobal_0074C3E4 = pConfig->nClientCapacity - 1;
    gnGlobal_0074C3E8 = pConfig->nValue04;
    gnGlobal_0074C3EC = pConfig->nValue08;
    gnGlobal_00989C28 = pConfig->nValue0C;
}

#include "gen/data/Source/Fog/Unknown_006BD780.inc"

// 0x006BE350
void __stdcall sub_006BE350_StartListening(D2QueueServerStrc* pServer, unsigned int nValue)
{
    if (pServer->pHandle)
    {
        sub_006C3120_Start(pServer, nValue);
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 297);
        exit(-1);
    }
}

// 0x006BE390
int __stdcall sub_006BE390_SwapSlot(D2Object006BE390Strc* pObject, int nIndex, int nValue)
{
    int nOld = pObject->anSlots[nIndex];
    if (nValue)
        pObject->anSlots[nIndex] = nValue;
    return nOld;
}
