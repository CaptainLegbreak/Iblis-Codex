typedef unsigned int D2IdeaUInt16;

// 0x005242C0
D2IdeaUInt16 __fastcall sub_005242C0_IdeaMul(D2IdeaUInt16 a, D2IdeaUInt16 b)
{
    if (a)
    {
        if (b)
        {
            const unsigned int p = (unsigned int)a * b;
            b = p & 0xFFFF;
            a = p >> 16;
            return b - a + (b < a);
        }
        return 1 - a;
    }
    return 1 - b;
}
