void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

extern unsigned char* gpBlendTable_00880B5C;                                                                // 0x00880B5C
extern int* gpnPerspectiveTable_00880B6C;                                                                   // 0x00880B6C

// 0x0050DB20
void __cdecl sub_0050DB20_AllocBlendTable()
{
    gpBlendTable_00880B5C = (unsigned char*)FOG_Alloc(0x10000, ".\\Src\\glVertex.cpp", 0x17, 0);
}

// 0x0050DC80
void __cdecl sub_0050DC80_AllocPerspectiveTable()
{
    gpnPerspectiveTable_00880B6C = (int*)FOG_Alloc(0x8000, ".\\Src\\glPerspective.cpp", 0x38, 0);
}
