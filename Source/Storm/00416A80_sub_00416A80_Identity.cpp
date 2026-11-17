struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink;char* m_next;};

struct D2IdentityView {
#ifdef MOVED_TEST
 unsigned int movedPrefix;
#endif
 D2StormLinkStrc link;
};
// 0x00416A80
D2StormLinkStrc* __fastcall sub_00416A80_Identity(D2IdentityView* value) {return &value->link;}
