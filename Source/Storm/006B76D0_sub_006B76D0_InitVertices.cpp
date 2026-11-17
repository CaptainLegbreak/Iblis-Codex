struct D2TexturedVertexStrc
{
    float nX, nY, nZ, nRhw;
    unsigned int nDiffuse, nSpecular;
    float nU, nV;
};
D2TexturedVertexStrc gaVertices_00970F48[4];        // 0x00970F48
void __cdecl sub_006B72A0_PrepareRenderer(); // 0x006B72A0

// 0x006B76D0
char* __fastcall sub_006B76D0_InitVertices(char* pObject)
{
    sub_006B72A0_PrepareRenderer();
    gaVertices_00970F48[0].nX = 0.0f;
    gaVertices_00970F48[0].nY = 0.0f;
    gaVertices_00970F48[0].nZ = 0.5f;
    gaVertices_00970F48[0].nRhw = 1.0f;
    gaVertices_00970F48[0].nDiffuse = 0xFFFFFFFF;
    gaVertices_00970F48[1].nDiffuse = 0xFFFFFFFF;
    gaVertices_00970F48[2].nDiffuse = 0xFFFFFFFF;
    gaVertices_00970F48[3].nDiffuse = 0xFFFFFFFF;
    gaVertices_00970F48[1].nRhw = 1.0f;
    gaVertices_00970F48[1].nV = 1.0f;
    gaVertices_00970F48[2].nRhw = 1.0f;
    gaVertices_00970F48[2].nU = 1.0f;
    gaVertices_00970F48[2].nV = 1.0f;
    gaVertices_00970F48[3].nRhw = 1.0f;
    gaVertices_00970F48[3].nU = 1.0f;
    gaVertices_00970F48[0].nU = 0.0f;
    gaVertices_00970F48[0].nV = 0.0f;
    gaVertices_00970F48[1].nX = 0.0f;
    gaVertices_00970F48[1].nY = 0.0f;
    gaVertices_00970F48[1].nU = 0.0f;
    gaVertices_00970F48[2].nX = 0.0f;
    gaVertices_00970F48[2].nY = 0.0f;
    gaVertices_00970F48[3].nX = 0.0f;
    gaVertices_00970F48[3].nY = 0.0f;
    gaVertices_00970F48[3].nV = 0.0f;
    gaVertices_00970F48[1].nZ = 0.5f;
    gaVertices_00970F48[2].nZ = 0.5f;
    gaVertices_00970F48[3].nZ = 0.5f;
    return pObject + 0x6000;
}
