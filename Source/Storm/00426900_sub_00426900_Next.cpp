struct D2StormLinkStrc { D2StormLinkStrc* m_prevlink;
#ifdef MOVED_TEST
 int movedGap;
#endif
 char* m_next; };
// 0x00426900
char* __fastcall sub_00426900_Next(D2StormLinkStrc* pLink) {
 return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}
