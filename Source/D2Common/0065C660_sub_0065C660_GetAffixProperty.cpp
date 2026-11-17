extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2MagicAffixTxt
{
    char pad0x00[0x24];
    D2PropertyStrc pProperties[3];
};

struct D2GradeModsStrc
{
    char pad0x00[0xC];
    D2PropertyStrc pProperties[12];
};

struct D2GemsTxt
{
    char pad0x00[0x30];
    D2PropertyStrc pProperties[3][3];
};

void __stdcall sub_C01_EmitSink(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a11);

// 0x0065C660
static const D2PropertyStrc* sub_0065C660_GetAffixProperty(const D2MagicAffixTxt* pMods, int nMod)
{
    D2_ASSERT(pMods, 0x79);
    if ((unsigned int)nMod < 3)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x7A);
    return 0;
}

// 0x0065C6A0
static const D2PropertyStrc* sub_0065C6A0_GetGradeProperty(const D2GradeModsStrc* pMods, int nMod)
{
    if ((unsigned int)nMod < 12)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x81);
    return 0;
}

// 0x0065C6D0
static const D2PropertyStrc* sub_0065C6D0_GetGemProperty(const D2GemsTxt* pMods, int nPropSet, int nMod)
{
    const D2PropertyStrc* pProperties[3];
    pProperties[0] = pMods->pProperties[0];
    pProperties[1] = pMods->pProperties[1];
    pProperties[2] = pMods->pProperties[2];
    D2_ASSERT((unsigned int)nPropSet < 3, 0x8F);
    if ((unsigned int)nMod < 3)
    {
        return &pProperties[nPropSet][nMod];
    }

    D2_ASSERT(0, 0x90);
    return 0;
}

// 0x0065C730
static const D2PropertyStrc* sub_0065C730_GetModsProperty(int nType, const void* pMods, int nPropSet, int nMod)
{
    switch (nType)
    {
    case 0:
        return sub_0065C660_GetAffixProperty((const D2MagicAffixTxt*)pMods, nMod);
    case 1:
        return sub_0065C6A0_GetGradeProperty((const D2GradeModsStrc*)pMods, nMod);
    case 2:
        return sub_0065C6D0_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 5:
        return sub_0065C6D0_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 3:
    case 4:
        return 0;
    case 6:
    case 7:
        return (const D2PropertyStrc*)pMods;
    default:
        D2_ASSERT(0, 0xAF);
        return 0;
    }
}

// build: context sub_C01_Emit_0065C730
void __stdcall sub_C01_Emit_0065C730(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType, int nProperties)
{
    for (int nMod = 0; nMod < nProperties; ++nMod)
    {
        const D2PropertyStrc* pProperty = sub_0065C730_GetModsProperty(nType, pMods, nPropSet, nMod);
        if (!pProperty || pProperty->nProperty < 0)
        {
            break;
        }

        sub_C01_EmitSink(nType, 0, pItem, pMods, nMod, nPropSet, nApplyType, pProperty, 0, 0x40, a2);
    }
}
