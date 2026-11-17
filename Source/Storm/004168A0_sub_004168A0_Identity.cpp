struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink;char* m_next;};

struct D2IdentityView {
#ifdef MOVED_TEST
 unsigned int movedPrefix;
#endif
 D2StormLinkStrc link;
};
// 0x004168A0
D2StormLinkStrc* __fastcall sub_004168A0_Identity(D2IdentityView* value) {return &value->link;}
