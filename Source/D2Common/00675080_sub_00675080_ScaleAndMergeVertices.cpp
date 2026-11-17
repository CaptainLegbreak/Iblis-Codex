struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned char pad0x09[3];
    int dwFlags;
    D2DrlgVertexStrc* pNext;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x00675080
static void sub_00675080_ScaleAndMergeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    D2DrlgVertexStrc* pVertex = *ppVertex;
    do
    {
        pVertex->nPosX /= 8;
        pVertex->nPosY /= 8;
        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);

    do
    {
        D2DrlgVertexStrc* pNextVertex = pVertex->pNext;

        if (pVertex->nPosX == pNextVertex->nPosX && pVertex->nPosY == pNextVertex->nPosY)
        {
            if (pNextVertex == *ppVertex)
            {
                *ppVertex = pVertex;
            }

            pVertex->pNext = pNextVertex->pNext;
            pVertex->dwFlags |= pNextVertex->dwFlags;
            pVertex->nDirection = pNextVertex->nDirection;
            FOG_FreeServerMemory(pMemPool, pNextVertex, ".\\DRLG\\Outdoors.cpp", 715, 0);
        }

        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);
}

void __fastcall sub_M16_EmitScaleAndMergeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    sub_00675080_ScaleAndMergeVertices(pMemPool, ppVertex);
}
