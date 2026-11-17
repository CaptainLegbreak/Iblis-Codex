struct D2ComObjectStrc;

struct D2ComVtblStrc
{
    long (__stdcall* QueryInterface)(D2ComObjectStrc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObjectStrc* pThis);
    unsigned long (__stdcall* Release)(D2ComObjectStrc* pThis);
};

struct D2ComObjectStrc
{
    D2ComVtblStrc* lpVtbl;
};

void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0

extern D2ComObjectStrc* gpSpriteTextures_00970F1C[3]; // 0x00970F1C
extern D2ComObjectStrc* gpSpriteSurfaces_00970F28[3]; // 0x00970F28
void* gpSpriteBuffer_00970F34;        // 0x00970F34
void* gpSpriteBuffer_00970F38;        // 0x00970F38
extern D2ComObjectStrc* gpSpriteObject_00970F3C; // 0x00970F3C

// 0x006B5B10
void __cdecl sub_006B5B10_ReleaseSprites()
{
    if (gpSpriteObject_00970F3C)
    {
        gpSpriteObject_00970F3C->lpVtbl->Release(gpSpriteObject_00970F3C);
        gpSpriteObject_00970F3C = 0;
    }

    if (gpSpriteBuffer_00970F34)
    {
        FOG_Free(gpSpriteBuffer_00970F34, ".\\Src\\d3dSprite.cpp", 136, 0);
        gpSpriteBuffer_00970F34 = 0;
    }

    if (gpSpriteBuffer_00970F38)
    {
        FOG_Free(gpSpriteBuffer_00970F38, ".\\Src\\d3dSprite.cpp", 142, 0);
        gpSpriteBuffer_00970F38 = 0;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (gpSpriteTextures_00970F1C[i])
        {
            gpSpriteTextures_00970F1C[i]->lpVtbl->Release(gpSpriteTextures_00970F1C[i]);
            gpSpriteTextures_00970F1C[i] = 0;
        }

        if (gpSpriteSurfaces_00970F28[i])
        {
            gpSpriteSurfaces_00970F28[i]->lpVtbl->Release(gpSpriteSurfaces_00970F28[i]);
            gpSpriteSurfaces_00970F28[i] = 0;
        }
    }
}
