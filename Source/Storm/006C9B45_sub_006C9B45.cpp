char* __fastcall sub_006C9AFF(char* p, char c); // 0x006C9AFF
extern "C" __declspec(dllimport) char* __stdcall CharNextA(const char*); // 0x006CC450

// 0x006C9B45
char* __fastcall sub_006C9B45(char* s)
{
    char* r = sub_006C9AFF(s, 0x5C);
    if (!r)
        return s;
    if (*CharNextA(r) != 0)
        return s;
    *r = 0;
    return s;
}
