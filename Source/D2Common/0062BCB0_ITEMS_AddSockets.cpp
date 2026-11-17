struct D2ItemDataStrc { unsigned int quality; int unk04[5]; unsigned int flags; };
struct D2UnitStrc { int type; int classId; void* pool; int id; int mode; D2ItemDataStrc* item; };
struct D2ItemsTxt { char unk00[0x10F]; unsigned char invWidth; unsigned char invHeight; };
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
static __forceinline void GetDimensions(D2UnitStrc* item, unsigned char* width, unsigned char* height, const char* file, int line) {
    *width = 0;
    *height = 0;
    if (item && item->type == 4) {
        D2ItemsTxt* txt = DATATBLS_GetItemsTxtRecord(!item ? -1 : item->classId);
        if (txt) { *width = txt->invWidth; *height = txt->invHeight; }
    }
}
static __forceinline D2ItemDataStrc* GetData(D2UnitStrc* item) {
    return (item && item->type == 4 && item->item) ? item->item : 0;
}
static __forceinline unsigned int GetQuality(D2UnitStrc* item) {
    const int type = item ? item->type : 6;
    D2ItemDataStrc* data = (type == 4 && item->item) ? item->item : 0;
    return data ? data->quality : 2;
}
#define Min(a,b) ((a) < (b) ? (a) : (b))
#define Max(a,b) ((a) > (b) ? (a) : (b))
// 0x0062BCB0
void __stdcall ITEMS_AddSockets(D2UnitStrc* item, int sockets) {
    const int type = item ? item->type : 6;
    if (type != 4) return;
    int maximum = 6;
    unsigned char width = 0, height = 0;
    GetDimensions(item, &width, &height, 0, 0);
    int area = height * width;
    if (area <= 6) maximum = area;
    if (!area) return;
    switch (GetQuality(item)) {
    case 5: case 7: {
        int existing = STATLIST_UnitGetStatValue(item, 194, 0);
        if (existing > 0) sockets = existing;
        else maximum = Min(maximum, 1);
        break;
    }
    case 6: maximum = Min(maximum, 2); break;
    case 4: maximum = Min(maximum, 4); break;
    case 8: case 9: maximum = Min(maximum, 3); break;
    }
    maximum = Min(maximum, ITEMS_GetMaxSockets(item));
    sockets = Min(Max(sockets, 1), maximum);
    if (sockets > 0) {
        if (D2ItemDataStrc* data = GetData(item)) data->flags |= 0x800;
        STATLIST_SetUnitStat(item, 194, sockets, 0);
    }
}
