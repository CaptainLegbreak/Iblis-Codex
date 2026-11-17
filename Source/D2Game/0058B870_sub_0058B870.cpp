struct Quest {char pad00[0xC];unsigned char state;char pad0D[0xD3];int id;};
int __stdcall sub_0065C310(void*,int,int);  // 0x0065C310
// 0x0058B870
bool __fastcall sub_0058B870(Quest* quest,int npc,void* player,void* flags,void* extra) {
 if(npc==512) {
  if(quest->state==1) {
   if(!(sub_0065C310(flags,37,0) || sub_0065C310(flags,37,1))) goto inactive;
   if(sub_0065C310(flags,quest->id,0)) goto inactive;
   if(sub_0065C310(flags,quest->id,1)) goto inactive;
  } else {
   if(!sub_0065C310(flags,quest->id,13)) goto inactive;
   if(sub_0065C310(flags,38,4)) goto inactive;
  }
  return true;
 }
inactive:
 return false;
}
