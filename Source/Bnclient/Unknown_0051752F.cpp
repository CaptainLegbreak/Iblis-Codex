struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink;
 char* m_next;
};
struct D2StormListStrc {
 int m_linkoffset;
 D2StormLinkStrc m_terminator;
 D2StormLinkStrc* sub_0051752F_GetLink(char* node);
 void sub_00517546_Initialize(int offset);
 char* sub_005175CB_Next(char* node);
 char* sub_00517607_RawNext(char* node);
};
// 0x0051752F
D2StormLinkStrc* D2StormListStrc::sub_0051752F_GetLink(char* node) {
 if(node) return (D2StormLinkStrc*)(node+m_linkoffset);
 return &m_terminator;
}
