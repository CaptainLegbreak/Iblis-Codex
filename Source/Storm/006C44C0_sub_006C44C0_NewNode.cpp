inline void* operator new(unsigned int, void* p) throw() { return p; }
void* __stdcall SMemAlloc(unsigned int size, const char* file, int line, unsigned int flags); // 0x00413020
extern char gszTypeNameCmdDef_0074C47C[]; // 0x0074C47C
struct D2StormLinkStrc { D2StormLinkStrc* m_prevlink; char* m_next; };
struct D2StormCmdDefStrc {
 D2StormLinkStrc tLink;
 char unk0x08[0x38];
 D2StormCmdDefStrc() { tLink.m_prevlink=0; tLink.m_next=0; }
};
struct D2StormFixedListStrc {
 int m_linkoffset; D2StormLinkStrc m_terminator;
 void sub_006C4180_LinkNode(char* node, unsigned int linkType, char* existing); // 0x006C4180
 char* sub_006C44C0_NewNode(unsigned int linkType, unsigned int extraBytes, unsigned int flags);
};
// 0x006C44C0
char* D2StormFixedListStrc::sub_006C44C0_NewNode(unsigned int linkType, unsigned int extraBytes, unsigned int flags)
{
 void* memory=SMemAlloc(sizeof(D2StormCmdDefStrc)+extraBytes,gszTypeNameCmdDef_0074C47C,-2,flags|8);
 D2StormCmdDefStrc* record=memory ? new(memory) D2StormCmdDefStrc : 0;
 if(linkType) sub_006C4180_LinkNode((char*)record,linkType,0);
 return (char*)record;
}
