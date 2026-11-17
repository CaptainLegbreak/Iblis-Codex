struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink;
#ifdef MOVED_TEST
 int movedNextGap;
#endif
 char* m_next;
};
struct D2StormListStrc {
 int m_linkoffset;
#ifdef MOVED_TEST
 int movedTermGap;
#endif
 D2StormLinkStrc m_terminator;
 D2StormLinkStrc* sub_0051752F_GetLink(char* node);
 void sub_00517546_Initialize(int offset);
 char* sub_005175CB_Next(char* node);
 char* sub_00517607_RawNext(char* node);
};
// 0x005175CB
char* D2StormListStrc::sub_005175CB_Next(char* node) {
 char* next=sub_0051752F_GetLink(node)->m_next;
 return (int)next<=0?0:next;
}
