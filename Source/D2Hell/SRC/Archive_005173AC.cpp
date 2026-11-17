struct D2ArchiveHandleStrc {
#ifdef MOVED_TEST
 int movedPrefix;
#endif
 void* hArchive;
};
int __stdcall SFileCloseArchive(void*);  // 0x00419A80
int __fastcall sub_0040B3C0(void*,const char*,int,int);  // 0x0040B3C0
extern "C" const char gArchiveSource_006DEBB8[];  // 0x006DEBB8
// 0x005173AC
void __fastcall sub_005173AC_Unload(D2ArchiveHandleStrc* p) {
 if(p->hArchive) SFileCloseArchive(p->hArchive);
 p->hArchive=0;
#ifdef MOVED_TEST
 sub_0040B3C0(p,gArchiveSource_006DEBB8,0x260,0);
#else
 sub_0040B3C0(p,gArchiveSource_006DEBB8,0x25c,0);
#endif
}
