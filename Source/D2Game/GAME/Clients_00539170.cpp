extern "C" char* __cdecl strcpy(char*, const char*);
#pragma intrinsic(strcpy)
struct Obj00539170 { unsigned char bUnknown00[0x464]; char szName464[1]; };
// 0x00539170
extern "C" __declspec(dllexport) void __fastcall sub_00539170(Obj00539170* pObj, const char* pSrc) {
    strcpy(pObj->szName464, pSrc);
}
