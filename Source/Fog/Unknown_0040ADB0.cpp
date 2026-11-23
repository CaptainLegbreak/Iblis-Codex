typedef unsigned char Byte;


extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
extern Byte gnCodeLengths_007076C0[256]; // 0x007076C0
extern Byte gnSymbolCodes_0075B6A0[256]; // 0x0075B6A0
extern Byte* gpDecodeTable_0075AFA0[256]; // 0x0075AFA0
extern Byte gabDecodeStorage[768]; // 0x0075B3A0

// build: context IsValidCodeLength
static inline int IsValidCodeLength(Byte length)
{
    if (length <= 0)
        return 0;
    if (length >= 16)
        return 0;
    return 1;
}

// 0x0040ADB0
int __fastcall FOG_10219(Byte* lengths)
{
    int counts[16];
    Byte sortedSymbols[256];
    Byte sortedLengths[256];
    int i;
    for (i = 0; i < 16; ++i)
        counts[i] = 0;
    i = 0;
    for (; i < 256; ++i)
    {
        if (!IsValidCodeLength(lengths[i]))
            return 0;
        ++counts[lengths[i]];
    }
    for (int length = 15; length > 0; --length)
    {
        int count = counts[length];
        counts[length] = counts[0];
        counts[0] += count;
    }
    i = 0;
    for (; i < 256; ++i)
        sortedSymbols[counts[lengths[i]]++] = (Byte)i;
    i = 0;
    for (; i < 256; ++i)
    {
        sortedLengths[i] = lengths[sortedSymbols[i]];
        gnCodeLengths_007076C0[i] = lengths[i];
    }
    gnSymbolCodes_0075B6A0[sortedSymbols[0]] = 0;
    for (i = 1; i < 256; ++i)
        gnSymbolCodes_0075B6A0[sortedSymbols[i]] =
            (Byte)((gnSymbolCodes_0075B6A0[sortedSymbols[i - 1]] + 1) >> (sortedLengths[i - 1] - sortedLengths[i]));
    Byte* storage = gabDecodeStorage;
    for (i = 255; i >= 0; --i)
    {
        Byte length = sortedLengths[i];
        if (length <= 8)
        {
            Byte symbol = sortedSymbols[i];
            int prefix = gnSymbolCodes_0075B6A0[symbol] << (8 - length);
            int count = 1u << (8 - length);
            Byte** ppEntry = &gpDecodeTable_0075AFA0[prefix];
            *ppEntry = storage;
            storage[0] = 0;
            (*ppEntry)[1] = symbol;
            storage += 2;
            for (int j = 0; j < count; ++j)
                gpDecodeTable_0075AFA0[prefix + j] = *ppEntry;
        }
        else
        {
            Byte* pSymbol = &sortedSymbols[i];
            unsigned int code = gnSymbolCodes_0075B6A0[*pSymbol];
            unsigned int prefix = code >> ((Byte)(length - 8));
            if ((code & ((1 << (length - 8)) - 1)) == 0)
            {
                int count = 1 << (length - 8);
                gpDecodeTable_0075AFA0[prefix] = storage;
                *storage++ = ((Byte)(length - 8));
                int j = 0;
                int n = 0;
                while (j < count)
                {
                    int repeat = 1 << (length - sortedLengths[i + j]);
                    if (repeat)
                    {
                        Byte value = pSymbol[n];
                        storage += repeat;
                        do
                        {
                            gpDecodeTable_0075AFA0[prefix][j + 1] = value;
                            ++j;
                        } while (--repeat);
                    }
                    ++n;
                }
            }
        }
    }
    return 1;
}

// 0x0040B110
void __cdecl sub_0040B110_Nop()
{
}

// 0x0040B120
void __cdecl sub_0040B120_Nop()
{
}
