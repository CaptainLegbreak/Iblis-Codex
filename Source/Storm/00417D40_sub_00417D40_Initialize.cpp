struct D2StormLinkStrc { D2StormLinkStrc* m_prevlink;
#ifdef MOVED_TEST
 int movedGap;
#endif
 char* m_next; };
struct D2StormListBaseStrc {
 int m_linkoffset;
#ifdef MOVED_TEST
 int movedGap;
#endif
 D2StormLinkStrc m_terminator;
 void sub_00417D40_Initialize();
};
// 0x00417D40
void D2StormListBaseStrc::sub_00417D40_Initialize() {
 m_linkoffset=0;
 m_terminator.m_prevlink=&m_terminator;
 m_terminator.m_next=(char*)~(unsigned int)&m_terminator;
}
