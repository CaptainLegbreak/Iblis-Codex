void __stdcall DATATBLS_LoadSkills_SkillDescTxt(void* hArchive);  // 0x00613F80
// 0x00617C20
void __fastcall sub_00617C20_LoadSkills(void* hArchive) {
#ifdef MOVED_TEST
 DATATBLS_LoadSkills_SkillDescTxt((char*)hArchive+4);
#else
 DATATBLS_LoadSkills_SkillDescTxt(hArchive);
#endif
}
