struct D2DrlgCoordsStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgOrthStrc
{
    void* pRoom;
    int nDirection;
    int bInit;
    int unk0x0C;
    D2DrlgCoordsStrc* pCoords;
    D2DrlgOrthStrc* pNext;
};

extern "C" const char gszEmptyAssertText;      // 0x006CC837

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection);

static void __stdcall sub_0067CE00_MarkVertex(D2DrlgVertexStrc* pVertex, int bInit);

void __stdcall sub_0067CE20(void* pMemPool, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pDefaultCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth);

static void __fastcall sub_0067D030(D2DrlgCoordsStrc* pCoords, D2DrlgVertexStrc* pFirst);

void __fastcall sub_0067D050(void* pMemPool, D2DrlgVertexStrc** ppVertex, D2DrlgCoordsStrc* pCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth);

// 0x0067D1E0
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    if (*ppVertex)
    {
        D2DrlgVertexStrc* pVertex = (*ppVertex)->pNext;
        while (pVertex)
        {
            D2DrlgVertexStrc* pFree = pVertex;
            pVertex = pVertex->pNext;
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgVer.cpp", 276, 0);

            if (pVertex == *ppVertex)
            {
                sub_0040B480(pMemPool, pVertex, ".\\DRLG\\DrlgVer.cpp", 279, 0);
                break;
            }
        }

        if (!pVertex)
        {
            sub_0040B480(pMemPool, *ppVertex, ".\\DRLG\\DrlgVer.cpp", 287, 0);
        }

        *ppVertex = 0;
    }
}

void __fastcall sub_0067D250(D2DrlgVertexStrc** ppVertex);

void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY);
