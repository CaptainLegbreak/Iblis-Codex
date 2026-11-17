struct D2GlideVtxStrc { float x; float y; float z; float oow; float sow; float tow; unsigned int color; };

extern D2GlideVtxStrc gaGlideVertices_00880678[36]; // 0x00880678
extern D2GlideVtxStrc* gaGlideStrips_00880A68[60]; // 0x00880A68

static __forceinline float ScaleTexCoord(double dA, double dB, double dScale)
{
    return (float)(int)((dA + dB) * dScale);
}

// 0x0050D540
void __cdecl sub_0050D540_GlideInitD()
{
    D2GlideVtxStrc* pVertex = &gaGlideVertices_00880678[0];
    for (int nRow = 0; nRow < 6; ++nRow)
    {
        for (int nCol = 0; nCol < 6; ++nCol, ++pVertex)
        {
            int nBiasS = 0;
            int nBiasT = 0;
            if (nCol == 0)
            {
                nBiasS = nBiasT = 1;
            }
            else if (nCol == 5)
            {
                nBiasS = nBiasT = -1;
            }

            if (nRow == 0)
            {
                nBiasS -= 1;
                nBiasT += 1;
            }
            else if (nRow == 5)
            {
                nBiasS += 1;
                nBiasT -= 1;
            }

            pVertex->oow = 1.0f;
            pVertex->sow = ScaleTexCoord((float)((nBiasS + 80) * 0.00390625), (nCol - nRow) * 0.0625, 256.0);
            double const tArg3 = (nCol + nRow) * 0.0625;
            pVertex->tow = ScaleTexCoord(tArg3, (float)(nBiasT * 0.0078125), 128.0);
        }
    }

    for (int nRow = 0; nRow < 5; ++nRow)
    {
        for (int nCol = 0; nCol < 6; ++nCol)
        {
            gaGlideStrips_00880A68[12 * nRow + 2 * nCol] = &gaGlideVertices_00880678[6 * nRow + nCol];
            D2GlideVtxStrc** ppBottom = &gaGlideStrips_00880A68[12 * nRow + 2 * nCol + 1];
            *ppBottom = &gaGlideVertices_00880678[6 * nRow + nCol + 6];
        }
    }
}
