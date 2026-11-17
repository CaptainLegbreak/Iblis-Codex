struct D2DrlgLevelStrc { char pad0[0x1C]; int nPosX,nPosY,nWidth,nHeight; char pad2C[0x180]; D2DrlgLevelStrc* pNextLevel; char pad1B0[0x20]; int nLevelId; };
struct D2DrlgStrc { char pad0[0x450]; unsigned char nDifficulty; char pad451[0x2B]; D2DrlgLevelStrc* pLevel; };
struct D2LevelDefBin { char pad0[12]; int dwSizeX[3],dwSizeY[3]; int dwOffsetX,dwOffsetY,dwDepend; };
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int); // 0x0061E470
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc*,int); // 0x00642AE0
static __inline D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg,int id); // 0x00642BB0

// build: context DRLG_GetLevel
static D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg,int id)
{
 for(D2DrlgLevelStrc* p=pDrlg->pLevel;p;p=p->pNextLevel) if(p->nLevelId==id)return p;
 return DRLG_AllocLevel(pDrlg,id);
}
// 0x00642D10
void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg,D2DrlgLevelStrc* pLevel)
{
 D2LevelDefBin* def=DATATBLS_GetLevelDefRecord(pLevel->nLevelId);
 D2DrlgLevelStrc* depend=0;
 int x=0,y=0;
 const int width=def->dwSizeX[pDrlg->nDifficulty];
 const int dependencyId=def->dwDepend;
 pLevel->nWidth=width;
 pLevel->nHeight=def->dwSizeY[pDrlg->nDifficulty];
 if(dependencyId) { depend=DRLG_GetLevel(pDrlg,dependencyId);x=depend->nPosX;y=depend->nPosY; }
 pLevel->nPosX=x+def->dwOffsetX;
 pLevel->nPosY=y+def->dwOffsetY;
}
