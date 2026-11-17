struct D2LinkStrc {D2LinkStrc* pPrev; D2LinkStrc* pNext;};

struct D2IdentityView {
#ifdef MOVED_TEST
 unsigned int movedPrefix;
#endif
 D2LinkStrc link;
};
// 0x005641E0
D2LinkStrc* __fastcall sub_005641E0_Identity(D2IdentityView* value) {return &value->link;}
