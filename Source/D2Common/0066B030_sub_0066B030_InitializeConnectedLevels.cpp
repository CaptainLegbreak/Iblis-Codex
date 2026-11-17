struct D2DrlgStrc;
struct D2PresetUnitStrc { char pad0[12]; D2PresetUnitStrc* pNext; int pad10; int nUnitType; };
struct D2DrlgRoomStrc { char pad0[36]; D2DrlgRoomStrc* pNext; unsigned int dwFlags; };
struct D2DrlgLevelStrc { char pad0[16]; D2DrlgRoomStrc* pFirstRoomEx; char pad14[0x1b4-0x14]; D2DrlgStrc* pDrlg; char pad1b8[0x18]; int nLevelId; };
void __fastcall sub_00678AD0_CreateLevelConnections(D2DrlgStrc* pDrlg); // 0x00678AD0
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg,int nLevelId); // 0x00642BB0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel); // 0x006424A0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg,int nLevelId); // 0x0066C040
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg,int nLevelId); // 0x0066AEC0
void __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pRoom); // 0x0061B730
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pRoom); // 0x0066BFA0
static __forceinline int FindVis(D2DrlgStrc* pDrlg,int nLevel,int nOther,int nIndex)
{
 int* pVis=DRLGROOM_GetVisArrayFromLevelId(pDrlg,nLevel);
 int nCount=0;
 for(unsigned char i=0;i<8;++i) if(pVis[i]==nOther) { if(nCount==nIndex)return i; ++nCount; }
 return -1;
}
static __forceinline D2DrlgRoomStrc* FindRoom(D2DrlgLevelStrc* pLevel,int nIndex)
{
 int nMask=1<<(nIndex+4);
 for(D2DrlgRoomStrc* pRoom=pLevel->pFirstRoomEx;pRoom;pRoom=pRoom->pNext) if(pRoom->dwFlags&nMask)return pRoom;
 return 0;
}
// 0x0066B030
void __fastcall sub_0066B030_InitializeConnectedLevels(D2DrlgStrc* pDrlg,int unused,int nLevel1,int nLevel2)
{
 sub_00678AD0_CreateLevelConnections(pDrlg);
 D2DrlgLevelStrc* pLevel1=DRLG_GetLevel(pDrlg,nLevel1);
 if(!pLevel1->pFirstRoomEx)DRLG_InitLevel(pLevel1);
 D2DrlgLevelStrc* pLevel2=DRLG_GetLevel(pDrlg,nLevel2);
 if(!pLevel2->pFirstRoomEx)DRLG_InitLevel(pLevel2);
 for(int n=0;n<8;++n) {
  int i=FindVis(pDrlg,nLevel1,nLevel2,n);
  int j=FindVis(pDrlg,nLevel2,nLevel1,n);
  if(i==-1 || j==-1)return;
  DRLGWARP_GetWarpIdArrayFromLevelId(pLevel1->pDrlg,pLevel1->nLevelId);
  DRLGWARP_GetWarpIdArrayFromLevelId(pLevel2->pDrlg,pLevel2->nLevelId);
  D2DrlgRoomStrc* pRoom1=FindRoom(pLevel1,i);
  D2DrlgRoomStrc* pRoom2=FindRoom(pLevel2,j);
  DRLGACTIVATE_InitializeRoomEx(pRoom1);
  DRLGACTIVATE_InitializeRoomEx(pRoom2);
  D2PresetUnitStrc* pPreset=DRLGROOM_GetPresetUnits(pRoom1);
  while(pPreset && pPreset->nUnitType!=5)pPreset=pPreset->pNext;
  pPreset=DRLGROOM_GetPresetUnits(pRoom2);
  while(pPreset && pPreset->nUnitType!=5)pPreset=pPreset->pNext;
 }
}
