struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink; char* m_next;};

struct D2IdentityView {
#ifdef MOVED_TEST
 unsigned int movedPrefix;
#endif
 D2StormLinkStrc link;
};
// 0x00420420
D2StormLinkStrc* __fastcall sub_00420420_Identity(D2IdentityView* value) {return &value->link;}
