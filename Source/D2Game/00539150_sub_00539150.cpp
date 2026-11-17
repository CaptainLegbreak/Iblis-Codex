extern "C" char* __cdecl strcpy(char*, const char*);
#pragma intrinsic(strcpy)
struct Obj00539150 { unsigned char bUnknown00[0x464]; char szName464[1]; };
// 0x00539150
extern "C" __declspec(dllexport) void __fastcall sub_00539150(Obj00539150* pObj, char* pDst) {
    strcpy(pDst, pObj->szName464);
}
