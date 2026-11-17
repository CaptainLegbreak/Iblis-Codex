struct D2GlideSpriteVertexStrc
{
    float x;
    float y;
    unsigned int dwColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

typedef char cc_M439_D2GlideSpriteVertexStrc_size[sizeof(D2GlideSpriteVertexStrc) == 0x1C ? 1 : -1];

extern int gaGlideWallCorner_0072F3A0[10][6][3];                                                          // 0x0072F3A0
D2GlideSpriteVertexStrc gaGlideTileGrid_00880458[15];                                                        // 0x00880458
D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4];                                                         // 0x00880600
int gbGlideCornersScaled_00880670;                                                                          // 0x00880670

// 0x0050C760
void __cdecl sub_0050C760_GlideInitVertices()
{
    gaGlideTileQuad_00880600[0].x = 0.0f;
    gaGlideTileQuad_00880600[0].y = 0.0f;
    gaGlideTileQuad_00880600[0].oow = 1.0f;
    gaGlideTileQuad_00880600[0].sow = 0.0f;
    gaGlideTileQuad_00880600[0].tow = 0.0f;

    gaGlideTileQuad_00880600[1].x = 0.0f;
    gaGlideTileQuad_00880600[1].y = 0.0f;
    gaGlideTileQuad_00880600[1].oow = 1.0f;
    gaGlideTileQuad_00880600[1].sow = 0.0f;
    gaGlideTileQuad_00880600[1].tow = 256.0f;

    gaGlideTileQuad_00880600[2].x = 0.0f;
    gaGlideTileQuad_00880600[2].y = 0.0f;
    gaGlideTileQuad_00880600[2].oow = 1.0f;
    gaGlideTileQuad_00880600[2].sow = 256.0f;
    gaGlideTileQuad_00880600[2].tow = 256.0f;

    gaGlideTileQuad_00880600[3].x = 0.0f;
    gaGlideTileQuad_00880600[3].y = 0.0f;
    gaGlideTileQuad_00880600[3].oow = 1.0f;
    gaGlideTileQuad_00880600[3].sow = 256.0f;
    gaGlideTileQuad_00880600[3].tow = 0.0f;

    for (int i = 0; i < 5; i++)
    {
        float fTow = (float)(i << 6);
        for (int j = 0; j < 3; j++)
        {
            gaGlideTileGrid_00880458[i * 3 + j].oow = 1.0f;
            gaGlideTileGrid_00880458[i * 3 + j].sow = (float)(j << 7);
            gaGlideTileGrid_00880458[i * 3 + j].tow = fTow;
        }
    }

    if (!gbGlideCornersScaled_00880670)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int* pPoint = gaGlideWallCorner_0072F3A0[i][j];
                pPoint[0] <<= 16;
                pPoint[1] <<= 16;
            }
        }
        gbGlideCornersScaled_00880670 = 1;
    }
}

#include "gen/data/Source/D2Win/0050C760_sub_0050C760_GlideInitVertices.inc"
