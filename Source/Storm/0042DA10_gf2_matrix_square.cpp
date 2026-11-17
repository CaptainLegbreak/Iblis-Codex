// Altered from the original zlib source.
#define GF2_DIM 32

static unsigned long gf2_matrix_times(unsigned long* mat, unsigned long vec)
{
    unsigned long sum;

    sum = 0;
    while (vec) {
        if (vec & 1)
            sum ^= *mat;
        vec >>= 1;
        mat++;
    }
    return sum;
}

// 0x0042DA10
static void gf2_matrix_square(unsigned long* square, unsigned long* mat)
{
    int n;

    for (n = 0; n < GF2_DIM; n++)
        square[n] = gf2_matrix_times(mat, mat[n]);
}

// 0x0042DA50
static unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    int n;
    unsigned long row;
    unsigned long even[GF2_DIM];
    unsigned long odd[GF2_DIM];

    if (len2 <= 0)
        return crc1;

    odd[0] = 0xedb88320UL;
    row = 1;
    for (n = 1; n < GF2_DIM; n++) {
        odd[n] = row;
        row <<= 1;
    }

    gf2_matrix_square(even, odd);

    gf2_matrix_square(odd, even);

    do {
        gf2_matrix_square(even, odd);
        if (len2 & 1)
            crc1 = gf2_matrix_times(even, crc1);
        len2 >>= 1;

        if (len2 == 0)
            break;

        gf2_matrix_square(odd, even);
        if (len2 & 1)
            crc1 = gf2_matrix_times(odd, crc1);
        len2 >>= 1;

    } while (len2 != 0);

    crc1 ^= crc2;
    return crc1;
}

unsigned long __fastcall crc32_combine(unsigned long crc1, unsigned long crc2, long len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

unsigned long __fastcall crc32_combine64(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    return crc32_combine_(crc1, crc2, len2);
}
