struct D2CofLayerStrc
{
    unsigned char nComponent;
    unsigned char bShadow;
    unsigned char bSelectable;
    unsigned char nOverrideTransLvl;
    unsigned char nNewTransLvl;
    char szWeaponClass[4];
};

struct D2CofDataStrc
{
    unsigned char nLayers;
    unsigned char unk0x01[0x1B];
    D2CofLayerStrc pLayers[1];
};

// 0x004DB050
int __fastcall sub_004DB050_GetCofLayerOverrideTransLvl(unsigned char* pData, int nComponent)
{
    int nResult = 0;
    if (pData && nComponent < 0x10)
    {
        const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pData;
        pData += 0x1C;
        for (int i = 0; i < pHeader->nLayers; ++i, pData += sizeof(D2CofLayerStrc))
        {
            if (((D2CofLayerStrc*)pData)->nComponent == nComponent)
            {
                nResult = ((D2CofLayerStrc*)pData)->nOverrideTransLvl;
                break;
            }
        }
    }
    return nResult;
}

// 0x004DB090
int __fastcall sub_004DB090_GetCofLayerShadow(void* pCof, int nComponent)
{
    int nResult = 0;
    if (pCof && nComponent < 0x10)
    {
        const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pCof;
        pCof = ((D2CofDataStrc*)pCof)->pLayers;
        for (int i = 0; i < pHeader->nLayers; ++i)
        {
            D2CofLayerStrc* pLayer = (D2CofLayerStrc*)pCof;
            if (pLayer->nComponent == nComponent)
            {
                nResult = pLayer->bShadow;
                break;
            }
            pCof = pLayer + 1;
        }
    }
    return nResult;
}

// 0x004DB140
int __fastcall sub_004DB140_GetCofLayerNewTransLvl(unsigned char* pData, int nComponent)
{
    if (!pData)
    {
        return 5;
    }
    if (nComponent >= 0x10)
    {
        return 5;
    }
    const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pData;
    pData += 0x1C;
    for (int i = 0; i < pHeader->nLayers; ++i, pData += sizeof(D2CofLayerStrc))
    {
        if (((D2CofLayerStrc*)pData)->nComponent == nComponent)
        {
            return ((D2CofLayerStrc*)pData)->nNewTransLvl;
        }
    }
    return 5;
}
