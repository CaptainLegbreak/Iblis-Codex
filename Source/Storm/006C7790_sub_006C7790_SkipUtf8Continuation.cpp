// 0x006C7790
static __forceinline int sub_006C7790_SkipUtf8Continuation(const unsigned char* text, int index, int step)
{
    while (index > 0)
    {
        unsigned char ch = text[index];
        if (!ch || (ch & 0xC0) != 0x80)
            break;
        index += step;
    }
    return index;
}

int __fastcall EmitSkipUtf8Continuation(int index, const unsigned char* text, int step)
{
    return sub_006C7790_SkipUtf8Continuation(text, index + 1, step);
}
