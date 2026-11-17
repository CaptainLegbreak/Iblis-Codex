struct D2SurfaceStrc;
struct D2SurfaceVtableStrc { void* unknown[31]; int (__stdcall* SetPalette)(D2SurfaceStrc*, void*); };
struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };
struct D2FloorEntryStrc { char unknown[8]; D2SurfaceStrc* surface; char tail[12]; };
struct D2FloorSetStrc { int count; char unknown[20]; D2FloorEntryStrc* entries; };
void __fastcall sub_006B20E0(const char*, int); // 0x006B20E0
// 0x006BB0E0
void __fastcall sub_006BB0E0_SetFloorPalette(D2FloorSetStrc* textures, void* palette)
{
    if (!palette) return;
    for (int i=0; i<textures->count-1; ++i) {
        D2FloorEntryStrc* entry=&textures->entries[i];
        if (entry->surface) {
            int result=entry->surface->vtable->SetPalette(entry->surface,palette);
            if (result) { sub_006B20E0("SetPalette (floor surface)",result); return; }
        }
    }
}
