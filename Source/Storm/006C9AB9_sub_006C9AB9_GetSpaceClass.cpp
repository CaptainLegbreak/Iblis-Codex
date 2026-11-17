extern const unsigned char gCharacterClass_0074C5C8[]; // 0x0074C5C8
// 0x006C9AB9
int __fastcall sub_006C9AB9_GetSpaceClass(signed char character)
{
    return gCharacterClass_0074C5C8[character] & 1;
}
