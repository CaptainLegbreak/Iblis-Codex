struct D2LightStrc
{
    char unk0x00[0x0C];
    int nType;
    int nX;
    int nY;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
    D2LightStrc* pNext;
    int nUnk0x2C;
    void* pData;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern D2LightStrc* gpLights_007B5668;                                                                      // 0x007B5668

// 0x004758D0
void __cdecl sub_004758D0_FreeAllLights()
{
    D2LightStrc* pLight = gpLights_007B5668;
    while (pLight)
    {
        D2LightStrc* pNext = pLight->pNext;
        if (pLight->pData)
        {
            FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 1405, 0);
        }
        FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 1407, 0);
        pLight = pNext;
    }

    gpLights_007B5668 = 0;
}
