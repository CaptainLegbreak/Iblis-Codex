struct D2GameStrc; struct D2UnitStrc;
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc*,D2UnitStrc*,unsigned int);  // 0x0055B060
// 0x00576F40
void __fastcall sub_00576F40_Gold(D2GameStrc* game,D2UnitStrc* unit,unsigned int value) {
#ifdef MOVED_TEST
 ITEMS_HandleGoldTransaction(game,unit,value+4);
#else
 ITEMS_HandleGoldTransaction(game,unit,value);
#endif
}
