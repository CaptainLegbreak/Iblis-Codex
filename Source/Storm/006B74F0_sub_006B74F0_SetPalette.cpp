struct D2SurfaceStrc;
struct D2SurfaceVtableStrc { void* unk[31]; int (__stdcall *SetPalette)(D2SurfaceStrc*, void*); };
struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };
D2SurfaceStrc* gaSurfaces_00971150[96];        // 0x00971150
void __fastcall sub_006B20E0_Report(const char*, int); // 0x006B20E0
// 0x006B74F0
void __fastcall sub_006B74F0_SetPalette(void* pPalette)
{
 if (!pPalette) return;
 D2SurfaceStrc** p = gaSurfaces_00971150;
 do {
  D2SurfaceStrc* s = *p;
  if (s) {
   int result = s->vtable->SetPalette(s, pPalette);
   if (result) { sub_006B20E0_Report("SetPalette (debug font surface)", result); return; }
  }
  ++p;
 } while ((int)p < (int)(gaSurfaces_00971150 + 96));
}
