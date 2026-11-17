struct D2StormQuadStrc {
#ifdef MOVED_TEST
 int movedPrefix;
#endif
 int n00,n04,n08,n0C;
 D2StormQuadStrc& __thiscall sub_00415160_Copy(const D2StormQuadStrc& source);
};
// 0x00415160
D2StormQuadStrc& __thiscall D2StormQuadStrc::sub_00415160_Copy(const D2StormQuadStrc& source) {
 n00=source.n00;
 n04=source.n04;
 n08=source.n08;
 n0C=source.n0C;
 return *this;
}
