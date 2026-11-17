struct D2FloorCacheStrc;
struct D2SubtileCacheStrc;
struct D2TextureCacheStrc;

void __fastcall sub_006BB3E0_FreeFloorCache(D2FloorCacheStrc* pCache, int bFree); // 0x006BB3E0
void __fastcall sub_006BADC0_FreeSubtileCache(D2SubtileCacheStrc* pCache, int bFree); // 0x006BADC0
void __fastcall sub_006BA830_FreeTextureCache(D2TextureCacheStrc* pCache, int bFree); // 0x006BA830

extern D2FloorCacheStrc gFloorCache_0096FC9C; // 0x0096FC9C
extern D2SubtileCacheStrc gSubtileCache_0096FC80; // 0x0096FC80
extern D2TextureCacheStrc gTextureCache_00970EC8; // 0x00970EC8
extern D2TextureCacheStrc gTextureCache_00970EE4; // 0x00970EE4
extern D2TextureCacheStrc gTextureCache_00970F00; // 0x00970F00

// 0x006B1BC0
void __fastcall sub_006B1BC0_ClearCaches()
{
    sub_006BB3E0_FreeFloorCache(&gFloorCache_0096FC9C, 0);
    sub_006BADC0_FreeSubtileCache(&gSubtileCache_0096FC80, 0);
    sub_006BA830_FreeTextureCache(&gTextureCache_00970EC8, 0);
    sub_006BA830_FreeTextureCache(&gTextureCache_00970EE4, 0);
    sub_006BA830_FreeTextureCache(&gTextureCache_00970F00, 0);
}
