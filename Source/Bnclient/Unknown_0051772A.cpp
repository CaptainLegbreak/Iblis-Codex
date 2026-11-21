void* __stdcall SMemAlloc(unsigned int,const char*,int,unsigned int);
int __stdcall SMemFree(void*,const char*,int,unsigned int);  // 0x00412650
extern const char gszRecordType_0072F9FC[];  // 0x0072F9FC
struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink; char* m_next;};
struct D2StormRecordStrc {
 D2StormLinkStrc tLink;
 int unk0x08;
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
// 0x0051772A
char* D2StormListStrc::sub_0051772A_DeleteNode(char* node) {
 char* next=sub_005175CB_Next(node);
 ((D2StormRecordStrc*)node)->sub_005176B4_Release(0);
 SMemFree(node,gszRecordType_0072F9FC,-2,0);
 return next;
}
