// 0x006C7790
static int sub_006C7790_SkipUtf8Continuation(const unsigned char* text, int index, int step)
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

// 0x006C77D0
int __stdcall SUniFindAfterUTF8Chr(const unsigned char* text, int index)
{
    return sub_006C7790_SkipUtf8Continuation(text, index + 1, 1);
}
