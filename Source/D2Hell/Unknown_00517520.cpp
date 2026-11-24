#include "D2StormLink.h"

void* __stdcall SMemAlloc(unsigned int,const char*,int,unsigned int);
int __stdcall SMemFree(void*,const char*,int,unsigned int);
// build: symbol ?gszRecordType@* 0x0072F9FC
extern const char gszRecordType[];
struct D2StormRecordStrc {
 D2StormLinkStrc tLink;
 int unk0x08;
// 0x00517520
 D2StormRecordStrc() {tLink.m_prevlink=0;tLink.m_next=0;}
 void sub_005176B4_Release(unsigned int flags);
};
struct D2StormListStrc {
 int m_linkoffset;
 D2StormLinkStrc m_terminator;
 char* sub_005175CB_Next(char* node);
 void sub_0051755C_LinkNode(char* node,unsigned int linkType,char* existing);
 char* sub_00517669_NewNode(unsigned int linkType,unsigned int extraBytes,unsigned int flags);
 char* sub_0051772A_DeleteNode(char* node);
};
inline void* operator new(unsigned int,void* p) throw() {return p;}

char* D2StormListStrc::sub_00517669_NewNode(unsigned int linkType,unsigned int extraBytes,unsigned int flags) {
 const unsigned int mask=8;
 void* memory=SMemAlloc(sizeof(D2StormRecordStrc)+extraBytes,gszRecordType,-2,flags|mask);
 D2StormRecordStrc* record=memory?new(memory) D2StormRecordStrc:0;
 if(linkType) sub_0051755C_LinkNode((char*)record,linkType,0);
 return (char*)record;
}
