struct D2BnetHashContextStrc { unsigned int state[5]; unsigned int block[16]; };
#define HASH_ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
// 0x005206B0
void __fastcall sub_005206B0_HashTransform(D2BnetHashContextStrc* context)
{
    unsigned int words[80];
    int i;
    for (i = 0; i < 16; ++i)
        words[i] = context->block[i];
    i = 16;
    do
    {
        const int nShift = (words[i - 3] ^ words[i - 8] ^ words[i - 16] ^ words[i - 14]) & 31;
        words[i] = HASH_ROL(1, nShift);
        ++i;
    } while (i < 80);
    unsigned int a = context->state[0];
    unsigned int b = context->state[1];
    unsigned int c = context->state[2];
    unsigned int d = context->state[3];
    unsigned int e = context->state[4];
    unsigned int t;
    unsigned int n = 0;
    for (; n < 20; ++n)
    {
        t = HASH_ROL(a, 5) + ((~b & d) | (c & b)) + words[n] + e + 0x5A827999;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 40; ++n)
    {
        t = HASH_ROL(a, 5) + (d ^ c ^ b) + words[n] + e + 0x6ED9EBA1;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 60; ++n)
    {
        t = HASH_ROL(a, 5) + (((c | b) & d) | (c & b)) + words[n] + e + 0x8F1BBCDC;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 80; ++n)
    {
        t = HASH_ROL(a, 5) + (d ^ c ^ b) + words[n] + e + 0xCA62C1D6;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    context->state[0] += a;
    context->state[1] += b;
    context->state[2] += c;
    context->state[3] += d;
    context->state[4] += e;
}
