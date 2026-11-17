struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2UnitStrc { int type; int unknown04[2]; int id; char unknown10[0xB4]; unsigned int flags; };
int __fastcall sub_0045ADF0(D2UnitStrc* unit); // 0x0045ADF0
int __fastcall sub_0045AE20(D2UnitStrc* unit); // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* unit); // 0x00620BB0
int __stdcall sub_0061A1B0(D2ActiveRoomStrc* room); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int level); // 0x006427F0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char act); // 0x0061AB70
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* room); // 0x0061AB00
void __fastcall sub_00535430_ClearPortal(D2GameStrc* game,D2UnitStrc* unit); // 0x00535430
int __fastcall sub_0056D130(D2GameStrc* game,D2UnitStrc* unit,D2ActiveRoomStrc* room,int x,int y,int level,D2UnitStrc** out,int object,int permanent); // 0x0056D130
void __fastcall sub_00553380_SendEvent(D2UnitStrc* unit,int event,D2UnitStrc* other); // 0x00553380
void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* unit,int id); // 0x005353B0
void __fastcall sub_00552AF0_SetOwnerId(D2UnitStrc* unit,int id); // 0x00552AF0
D2UnitStrc* __fastcall sub_00553720_GetPortalPair(D2GameStrc* game,D2UnitStrc* unit); // 0x00553720
void __fastcall sub_0058CF00_UpdatePortal(D2GameStrc* game,D2UnitStrc* unit); // 0x0058CF00
D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* unit,const char* file,int line,int type,int id); // 0x005531C0
void __fastcall sub_0053B3D0_SendByte(D2ClientStrc* client,unsigned char code); // 0x0053B3D0
static __forceinline int GetUnitType(D2UnitStrc* unit) { return unit?unit->type:6; }
static __forceinline int GetItemType(D2UnitStrc* pItem)
{
    int nType = 6;
    if (pItem)
    {
        nType = pItem->type;
    }
    return nType;
}

// 0x005BE290
int __fastcall sub_005BE290_CreateTownPortal(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,int unused1,int unused2,int unused3,int unused4)
{
 if(GetUnitType(unit)!=0) return 0;
 unit->flags|=0x40;
 D2ActiveRoomStrc* room=UNITS_GetRoom(unit);
 unsigned char act=DRLG_GetActNoFromLevelId(sub_0061A1B0(room));
 int town=DUNGEON_GetTownLevelIdFromActNo(act);
 if(DUNGEON_IsRoomInTown(room) || sub_0061A1B0(room)==136) {
  sub_00553380_SendEvent(unit,24,unit);return 0;
 }
 sub_00535430_ClearPortal(game,unit);
 D2UnitStrc* portal=0;
 int result=sub_0056D130(game,unit,room,sub_0045ADF0(unit),sub_0045AE20(unit),town,&portal,59,0);
 sub_00553380_SendEvent(unit,7,0);
 if(result) {
  PLAYER_SetUniqueIdInPlayerData(unit,!portal?-1:portal->id);
  if(portal) {
   sub_00552AF0_SetOwnerId(portal,unit->id);
   D2UnitStrc* other=sub_00553720_GetPortalPair(game,portal);
   if(other) {
    sub_00552AF0_SetOwnerId(other,unit->id);
    sub_0058CF00_UpdatePortal(game,other);
   }
   sub_0058CF00_UpdatePortal(game,portal);
  }
 }
 if(item) {
  const int nItemId = item->id;
  const int nItemType = GetItemType(item);
  D2ClientStrc* client=sub_005531C0_GetClient(unit,".\\SKILLS\\SkillItem.cpp",218,nItemType,nItemId);
  sub_0053B3D0_SendByte(client,124);
 }
 return result;
}
