struct D2LinkStrc {D2LinkStrc* pPrev;
#ifdef MOVED_TEST
 int movedGap;
#endif
 D2LinkStrc* pNext;
};
// 0x005641C0
void __fastcall sub_005641C0_Init(D2LinkStrc* list) {list->pPrev=list;list->pNext=list;}
