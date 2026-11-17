struct D2InventoryStrc;
struct D2UnitStrc { char unk_00[96]; D2InventoryStrc* inventory; };
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc*,int,int); // 0x00478F20
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
D2UnitStrc* __fastcall sub_00463990(int,int); // 0x00463990
int __fastcall sub_00479120_GetHirelingClassId(int); // 0x00479120
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0
void __fastcall sub_004CBDE0_PlayEventSound(int,unsigned char,unsigned short); // 0x004CBDE0
// 0x004934D0
int __stdcall sub_004934D0_CheckBoxAction(int playSound)
{
 if(!sub_0044DCC0()) return 0;
 int result=0;
 D2UnitStrc* player=sub_00463DD0();
 if(!player) return 0;
 D2UnitStrc* current=sub_00463DD0();
 D2UnitStrc* item=current ? INVENTORY_GetCursorItem(current->inventory):0;
 if(!item) return 0;
 int petId=sub_00478F20_FindPetIdByOwner(player,7,0);
 if(petId==-1) return 0;
 if(ITEMS_CheckItemFlag(item,16,955,".\\UI\\Hireables.cpp") && !ITEMS_CheckItemFlag(item,256,955,".\\UI\\Hireables.cpp")) {
  if(ITEMS_CheckItemTypeId(item,76) || ITEMS_CheckItemTypeId(item,80) || ITEMS_CheckItemTypeId(item,81)) {
   if(playSound) sub_004CBDE0_PlayEventSound(petId,1,84);
   return 1;
  }
  if(ITEMS_CheckItemTypeId(item,3) || ITEMS_CheckItemTypeId(item,37)) result=1;
  D2UnitStrc* pet=sub_00463990(petId,1);
  if(!pet) return 0;
  switch(sub_00479120_GetHirelingClassId(petId)) {
   case 271: if(ITEMS_CheckItemTypeId(item,27)) result=1; break;
   case 338: if(ITEMS_CheckItemTypeId(item,33) || ITEMS_CheckItemTypeId(item,34)) result=1; break;
   case 359:
    if(ITEMS_CheckItemTypeId(item,2)) result=1;
    if(ITEMS_CheckItemTypeId(item,30) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1;
    break;
   case 560: if(ITEMS_CheckItemTypeId(item,28) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1; break;
   case 561: if(ITEMS_CheckItemTypeId(item,30)) result=1; break;
  }
  if(!result) {
   if(playSound) sub_004CBDE0_PlayEventSound(petId,1,85);
  } else if(!ITEMS_CheckRequirements(item,pet,0,0,0,0)) result=0;
  return result;
 }
 if(playSound) sub_004CBDE0_PlayEventSound(petId,1,86);
 return 0;
}
