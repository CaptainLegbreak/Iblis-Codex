struct D2TxtLinkEntryStrc { char code[4]; int index; };
struct D2TxtLinkStrc { int count; int unk_04; D2TxtLinkEntryStrc* entries; };

// 0x006BD180
int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* linker, int index, char* text)
{
    D2TxtLinkEntryStrc* entries = linker->entries;
    if (!entries)
        return 0;
    if (index >= 0 && index < linker->count)
    {
        for (int i = 0; i < linker->count; ++i)
        {
            if (index == entries[i].index)
            {
                text[0] = entries[i].code[0] != ' ' ? entries[i].code[0] : 0;
                text[1] = entries[i].code[1] != ' ' ? entries[i].code[1] : 0;
                text[2] = entries[i].code[2] != ' ' ? entries[i].code[2] : 0;
                text[3] = entries[i].code[3] != ' ' ? entries[i].code[3] : 0;
                text[4] = 0;
                return 1;
            }
        }
    }
    return 0;
}
