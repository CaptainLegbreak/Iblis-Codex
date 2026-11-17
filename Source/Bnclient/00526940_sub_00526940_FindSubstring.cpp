struct Unicode { unsigned short ch; };
// 0x00526940
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* str, const Unicode* substr)
{
    if (!str || !substr) return 0;
    for (;;) {
        const Unicode first = *substr;
        const unsigned short wFirst = first.ch;
        while (str->ch != wFirst) {
            if (!str->ch) return 0;
            ++str;
        }
        if (!str->ch) return 0;
        int n = 0;
        for (;;) {
            if (str->ch != substr->ch || !str->ch) break;
            if (!substr->ch) goto found;
            ++str; ++substr; ++n;
        }
        if (!substr->ch) {
found:
            return (Unicode*)(str - n);
        }
        if (!str->ch) return 0;
        str = str - n + 1;
        substr -= n;
    }
}
