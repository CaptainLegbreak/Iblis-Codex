struct D2StringTableStrc { int count; int unk4; int unk8; void* data; };
extern const char* gszFallback_0074C3D8; // 0x0074C3D8
const char* __fastcall sub_006BD330_GetString(void*, int); // 0x006BD330
// 0x006BD380
const char* __stdcall sub_006BD380_GetString(D2StringTableStrc* pTable, int index, int useFallback)
{
 if (!pTable || index < 0 || index >= pTable->count) return gszFallback_0074C3D8;
 const char* result = sub_006BD330_GetString(pTable->data, index);
 if ((!result || result == gszFallback_0074C3D8) && useFallback) return gszFallback_0074C3D8;
 return result;
}
