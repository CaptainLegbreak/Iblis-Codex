struct D2CmpGfxKeyStrc
{
    int unk0x00;
    unsigned int dwFlags;
    int nType;
    int nSubA;
    int nMode;
    int nSubB;
    int nKey1;
    int nKey2;
    int nKey3;
    int nKey4;
    int nKey5;
    const char* szName;
    int unk0x30[4];
    int nDirection;
    unsigned int dwFlags44;
};

struct D2CmpGfxCelStrc
{
    unsigned int dwFlags;
    int unk0x04[4];
    unsigned int nDirections;
};

int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90

// 0x0060AB80
unsigned int __fastcall sub_0060AB80_GetGfxKeyValue(D2CmpGfxKeyStrc* pKey, unsigned int* pDivisor, D2CmpGfxCelStrc* pCel)
{
    unsigned int nValue = 0;
    *pDivisor = 0;
    switch (pKey->nType)
    {
    case 0:
        *pDivisor = 8;
        if (pKey->nMode == 0 || pKey->nMode == 0x11 || (pKey->dwFlags44 & 2))
        {
            *pDivisor = 1;
        }
        if (!(pCel->dwFlags & 1))
        {
            nValue = sub_00600C90_GetDirectionIndex64(pKey->nDirection, pCel->nDirections);
        }
        break;

    case 1:
        if (!(pCel->dwFlags & 1))
        {
            *pDivisor = pCel->nDirections == 8 ? 4 : 1;
            nValue = sub_00600C90_GetDirectionIndex64(pKey->nDirection, pCel->nDirections);
        }
        break;

    default:
        *pDivisor = 1;
        if (pKey->nType == 2)
        {
            nValue = 0;
        }
        else if ((pKey->nType == 6 && (pKey->dwFlags & 2)) || pKey->nType == 4 || pKey->nType == 3)
        {
            if (pKey->nType == 4)
            {
                nValue = pKey->nDirection;
            }
            else if (!(pCel->dwFlags & 1))
            {
                nValue = sub_00600C90_GetDirectionIndex64(pKey->nDirection, pCel->nDirections);
            }
        }
        break;
    }

    if (!*pDivisor)
    {
        return 0;
    }

    return nValue / *pDivisor;
}
