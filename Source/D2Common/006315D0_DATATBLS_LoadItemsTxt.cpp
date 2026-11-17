struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0xF6 - 0x84];
    unsigned short wVersion;
    char unk0xF8[0x1A8 - 0xF8];
};

extern "C" const char gszTxtField_code[];                                                           // 0x006DCCE0
extern "C" const char gszTxtField_version[];                                                        // 0x006DCCF0
extern "C" const char gszTxtField_end[];                                                            // 0x006D9060

D2TxtLinkStrc* gpItemsLinker_0096BCC4;                                                                      // 0x0096BCC4
extern D2TxtLinkStrc* gpItemTypesLinker_0096C824;                                                           // 0x0096C824
D2TxtLinkStrc* gpHitClassLinker_0096BC54;                                                                   // 0x0096BC54
extern D2TxtLinkStrc* gpSoundsLinker_0096BDC8;                                                              // 0x0096BDC8
extern D2TxtLinkStrc* gpStatesLinker_0096BCF0;                                                              // 0x0096BCF0
extern D2TxtLinkStrc* gpItemStatCostLinker_0096C800;                                                        // 0x0096C800

void* gpItemsCode_0096BCC8;                                                                                 // 0x0096BCC8
int gnItemsCodeSize_0096BCCC;                                                                               // 0x0096BCCC
int gnItemsCodeSizeEx_0096BCD0;                                                                             // 0x0096BCD0
extern int gbCompileTxt;                                                                                    // 0x0096C8B4
int gnItemsTxtRecordCount_0096CA58;                                                                         // 0x0096CA58
D2ItemsTxt* gpItemsTxt_0096CA5C;                                                                            // 0x0096CA5C
D2ItemsTxt* gpWeaponsTxt_0096CA60;                                                                          // 0x0096CA60
int gnWeaponsTxtRecordCount_0096CA64;                                                                       // 0x0096CA64
D2ItemsTxt* gpArmorTxt_0096CA68;                                                                            // 0x0096CA68
int gnArmorTxtRecordCount_0096CA6C;                                                                         // 0x0096CA6C
D2ItemsTxt* gpMiscTxt_0096CA70;                                                                             // 0x0096CA70
int gnMiscTxtRecordCount_0096CA74;                                                                          // 0x0096CA74
unsigned short* gpIndexOldToCurrent_0096CA78;                                                               // 0x0096CA78

void __fastcall DATATBLS_GetStringIdFromReferenceString();                                                  // 0x006117B0
void __fastcall DATATBLS_ItemCalcLinker();                                                                  // 0x00631530
D2TxtLinkStrc* __stdcall sub_006BD040_AllocBlock(const char* szFile, int nLine);                            // 0x006BD040
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx); // 0x00613E90
void __stdcall sub_006BD230_AddLinkCode(D2TxtLinkStrc* pLinker, unsigned int dwCode);                       // 0x006BD230

// 0x006315D0
void __fastcall DATATBLS_LoadItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 10, 0, 128, &gpItemsLinker_0096BCC4 },
        { "namestr", 22, 0, 244, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_version, 3, 0, 246, 0 },
        { "compactsave", 6, 0, 323, 0 },
        { "type", 15, 0, 286, &gpItemTypesLinker_0096C824 },
        { "type2", 15, 0, 288, &gpItemTypesLinker_0096C824 },
        { "hit class", 13, 0, 316, &gpHitClassLinker_0096BC54 },
        { "gemapplytype", 4, 0, 318, 0 },
        { "levelreq", 4, 0, 319, 0 },
        { "magic lvl", 4, 0, 320, 0 },
        { "auto prefix", 3, 0, 248, 0 },
        { "gamble cost", 2, 0, 212, 0 },
        { "alternategfx", 9, 0, 144, 0 },
        { "spawnable", 4, 0, 307, 0 },
        { "rarity", 4, 0, 252, 0 },
        { "level", 4, 0, 253, 0 },
        { "mindam", 6, 0, 254, 0 },
        { "maxdam", 6, 0, 255, 0 },
        { "2handmindam", 6, 0, 258, 0 },
        { "2handmaxdam", 6, 0, 259, 0 },
        { "minmisdam", 4, 0, 256, 0 },
        { "maxmisdam", 4, 0, 257, 0 },
        { "minac", 2, 0, 204, 0 },
        { "maxac", 2, 0, 208, 0 },
        { "block", 6, 0, 273, 0 },
        { "absorbs", 6, 0, 270, 0 },
        { "rangeadder", 6, 0, 260, 0 },
        { "speed", 2, 0, 216, 0 },
        { "strbonus", 3, 0, 262, 0 },
        { "dexbonus", 3, 0, 264, 0 },
        { "reqstr", 3, 0, 266, 0 },
        { "reqdex", 3, 0, 268, 0 },
        { "invwidth", 4, 0, 271, 0 },
        { "invheight", 4, 0, 272, 0 },
        { "stackable", 4, 0, 306, 0 },
        { "minstack", 2, 0, 228, 0 },
        { "maxstack", 2, 0, 232, 0 },
        { "spawnstack", 2, 0, 236, 0 },
        { "flippyfile", 1, 31, 0, 0 },
        { "invfile", 1, 31, 32, 0 },
        { "uniqueinvfile", 1, 31, 64, 0 },
        { "setinvfile", 1, 31, 96, 0 },
        { "durability", 6, 0, 274, 0 },
        { "nodurability", 4, 0, 275, 0 },
        { "missile", 6, 0, 276, 0 },
        { "component", 4, 0, 277, 0 },
        { "cost", 2, 0, 224, 0 },
        { "normcode", 9, 0, 132, 0 },
        { "ubercode", 9, 0, 136, 0 },
        { "ultracode", 9, 0, 140, 0 },
        { "wclass", 9, 0, 192, 0 },
        { "2handedwclass", 9, 0, 196, 0 },
        { "1or2handed", 6, 0, 317, 0 },
        { "BetterGem", 9, 0, 188, 0 },
        { "rArm", 6, 0, 278, 0 },
        { "lArm", 6, 0, 279, 0 },
        { "torso", 6, 0, 280, 0 },
        { "legs", 6, 0, 281, 0 },
        { "rspad", 6, 0, 282, 0 },
        { "lspad", 6, 0, 283, 0 },
        { "2handed", 6, 0, 284, 0 },
        { "useable", 4, 0, 285, 0 },
        { "subtype", 6, 0, 290, 0 },
        { "dropsound", 20, 0, 292, &gpSoundsLinker_0096BDC8 },
        { "dropsfxframe", 4, 0, 296, 0 },
        { "usesound", 20, 0, 294, &gpSoundsLinker_0096BDC8 },
        { "unique", 4, 0, 297, 0 },
        { "quest", 4, 0, 298, 0 },
        { "questdiffcheck", 4, 0, 299, 0 },
        { "transparent", 4, 0, 300, 0 },
        { "transtbl", 4, 0, 301, 0 },
        { "lightradius", 4, 0, 303, 0 },
        { "belt", 4, 0, 304, 0 },
        { "autobelt", 4, 0, 305, 0 },
        { "missiletype", 3, 0, 250, 0 },
        { "spellicon", 6, 0, 308, 0 },
        { "durwarning", 4, 0, 309, 0 },
        { "qntwarning", 4, 0, 310, 0 },
        { "hasinv", 6, 0, 311, 0 },
        { "gemsockets", 6, 0, 312, 0 },
        { "gemoffset", 2, 0, 240, 0 },
        { "pSpell", 2, 0, 148, 0 },
        { "state", 20, 0, 152, &gpStatesLinker_0096BCF0 },
        { "cstate1", 20, 0, 154, &gpStatesLinker_0096BCF0 },
        { "cstate2", 20, 0, 156, &gpStatesLinker_0096BCF0 },
        { "len", 25, 0, 176, (void*)DATATBLS_ItemCalcLinker },
        { "stat1", 20, 0, 158, &gpItemStatCostLinker_0096C800 },
        { "calc1", 25, 0, 164, (void*)DATATBLS_ItemCalcLinker },
        { "stat2", 20, 0, 160, &gpItemStatCostLinker_0096C800 },
        { "calc2", 25, 0, 168, (void*)DATATBLS_ItemCalcLinker },
        { "stat3", 20, 0, 162, &gpItemStatCostLinker_0096C800 },
        { "calc3", 25, 0, 172, (void*)DATATBLS_ItemCalcLinker },
        { "spelldesc", 4, 0, 180, 0 },
        { "spelldescstr", 22, 0, 182, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "spelldesccalc", 25, 0, 184, (void*)DATATBLS_ItemCalcLinker },
        { "SkipName", 4, 0, 324, 0 },
        { "bitfield1", 2, 0, 220, 0 },
        { "CharsiMin", 4, 0, 328, 0 },
        { "CharsiMax", 4, 0, 345, 0 },
        { "CharsiMagicMin", 4, 0, 362, 0 },
        { "CharsiMagicMax", 4, 0, 379, 0 },
        { "CharsiMagicLvl", 4, 0, 396, 0 },
        { "GheedMin", 4, 0, 327, 0 },
        { "GheedMax", 4, 0, 344, 0 },
        { "GheedMagicMin", 4, 0, 361, 0 },
        { "GheedMagicMax", 4, 0, 378, 0 },
        { "GheedMagicLvl", 4, 0, 395, 0 },
        { "AkaraMin", 4, 0, 326, 0 },
        { "AkaraMax", 4, 0, 343, 0 },
        { "AkaraMagicMin", 4, 0, 360, 0 },
        { "AkaraMagicMax", 4, 0, 377, 0 },
        { "AkaraMagicLvl", 4, 0, 394, 0 },
        { "FaraMin", 4, 0, 329, 0 },
        { "FaraMax", 4, 0, 346, 0 },
        { "FaraMagicMin", 4, 0, 363, 0 },
        { "FaraMagicMax", 4, 0, 380, 0 },
        { "FaraMagicLvl", 4, 0, 397, 0 },
        { "LysanderMin", 4, 0, 330, 0 },
        { "LysanderMax", 4, 0, 347, 0 },
        { "LysanderMagicMin", 4, 0, 364, 0 },
        { "LysanderMagicMax", 4, 0, 381, 0 },
        { "LysanderMagicLvl", 4, 0, 398, 0 },
        { "DrognanMin", 4, 0, 331, 0 },
        { "DrognanMax", 4, 0, 348, 0 },
        { "DrognanMagicMin", 4, 0, 365, 0 },
        { "DrognanMagicMax", 4, 0, 382, 0 },
        { "DrognanMagicLvl", 4, 0, 399, 0 },
        { "HraltiMin", 4, 0, 332, 0 },
        { "HraltiMax", 4, 0, 349, 0 },
        { "HraltiMagicMin", 4, 0, 366, 0 },
        { "HraltiMagicMax", 4, 0, 383, 0 },
        { "HraltiMagicLvl", 4, 0, 400, 0 },
        { "AlkorMin", 4, 0, 333, 0 },
        { "AlkorMax", 4, 0, 350, 0 },
        { "AlkorMagicMin", 4, 0, 367, 0 },
        { "AlkorMagicMax", 4, 0, 384, 0 },
        { "AlkorMagicLvl", 4, 0, 401, 0 },
        { "OrmusMin", 4, 0, 334, 0 },
        { "OrmusMax", 4, 0, 351, 0 },
        { "OrmusMagicMin", 4, 0, 368, 0 },
        { "OrmusMagicMax", 4, 0, 385, 0 },
        { "OrmusMagicLvl", 4, 0, 402, 0 },
        { "ElzixMin", 4, 0, 335, 0 },
        { "ElzixMax", 4, 0, 352, 0 },
        { "ElzixMagicMin", 4, 0, 369, 0 },
        { "ElzixMagicMax", 4, 0, 386, 0 },
        { "ElzixMagicLvl", 4, 0, 403, 0 },
        { "AshearaMin", 4, 0, 336, 0 },
        { "AshearaMax", 4, 0, 353, 0 },
        { "AshearaMagicMin", 4, 0, 370, 0 },
        { "AshearaMagicMax", 4, 0, 387, 0 },
        { "AshearaMagicLvl", 4, 0, 404, 0 },
        { "CainMin", 4, 0, 337, 0 },
        { "CainMax", 4, 0, 354, 0 },
        { "CainMagicMin", 4, 0, 371, 0 },
        { "CainMagicMax", 4, 0, 388, 0 },
        { "CainMagicLvl", 4, 0, 405, 0 },
        { "HalbuMin", 4, 0, 338, 0 },
        { "HalbuMax", 4, 0, 355, 0 },
        { "HalbuMagicMin", 4, 0, 372, 0 },
        { "HalbuMagicMax", 4, 0, 389, 0 },
        { "HalbuMagicLvl", 4, 0, 406, 0 },
        { "JamellaMin", 4, 0, 339, 0 },
        { "JamellaMax", 4, 0, 356, 0 },
        { "JamellaMagicMin", 4, 0, 373, 0 },
        { "JamellaMagicMax", 4, 0, 390, 0 },
        { "JamellaMagicLvl", 4, 0, 407, 0 },
        { "MalahMin", 4, 0, 340, 0 },
        { "MalahMax", 4, 0, 357, 0 },
        { "MalahMagicMin", 4, 0, 374, 0 },
        { "MalahMagicMax", 4, 0, 391, 0 },
        { "MalahMagicLvl", 4, 0, 408, 0 },
        { "LarzukMin", 4, 0, 341, 0 },
        { "LarzukMax", 4, 0, 358, 0 },
        { "LarzukMagicMin", 4, 0, 375, 0 },
        { "LarzukMagicMax", 4, 0, 392, 0 },
        { "LarzukMagicLvl", 4, 0, 409, 0 },
        { "DrehyaMin", 4, 0, 342, 0 },
        { "DrehyaMax", 4, 0, 359, 0 },
        { "DrehyaMagicMin", 4, 0, 376, 0 },
        { "DrehyaMagicMax", 4, 0, 393, 0 },
        { "DrehyaMagicLvl", 4, 0, 410, 0 },
        { "Transmogrify", 6, 0, 313, 0 },
        { "TMogType", 9, 0, 200, 0 },
        { "TMogMin", 6, 0, 314, 0 },
        { "TMogMax", 6, 0, 315, 0 },
        { "Transform", 4, 0, 321, 0 },
        { "InvTrans", 4, 0, 322, 0 },
        { "PermStoreItem", 4, 0, 420, 0 },
        { "multibuy", 4, 0, 421, 0 },
        { "NightmareUpgrade", 9, 0, 412, 0 },
        { "HellUpgrade", 9, 0, 416, 0 },
        { "Nameable", 4, 0, 325, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpItemsLinker_0096BCC4 = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 392);

    D2ItemsTxt* pWeapons = (D2ItemsTxt*)DATATBLS_CompileTxt(hArchive, "weapons", pTbl, &gnWeaponsTxtRecordCount_0096CA64, sizeof(D2ItemsTxt));
    D2ItemsTxt* pArmor = (D2ItemsTxt*)DATATBLS_CompileTxt(hArchive, "armor", pTbl, &gnArmorTxtRecordCount_0096CA6C, sizeof(D2ItemsTxt));
    D2ItemsTxt* pMisc = (D2ItemsTxt*)DATATBLS_CompileTxt(hArchive, "misc", pTbl, &gnMiscTxtRecordCount_0096CA74, sizeof(D2ItemsTxt));

    gnItemsTxtRecordCount_0096CA58 = gnWeaponsTxtRecordCount_0096CA64 + gnArmorTxtRecordCount_0096CA6C + gnMiscTxtRecordCount_0096CA74;

    gpItemsTxt_0096CA5C = (D2ItemsTxt*)FOG_AllocPool(0, sizeof(D2ItemsTxt) * gnItemsTxtRecordCount_0096CA58, ".\\DATATBLS\\ItemTbls.cpp", 399, 0);
    D2ItemsTxt* pItems = gpItemsTxt_0096CA5C;
    gpWeaponsTxt_0096CA60 = gpItemsTxt_0096CA5C;
    memcpy(gpWeaponsTxt_0096CA60, pWeapons, sizeof(D2ItemsTxt) * gnWeaponsTxtRecordCount_0096CA64);

    pItems += gnWeaponsTxtRecordCount_0096CA64;
    gpArmorTxt_0096CA68 = pItems;
    memcpy(pItems, pArmor, sizeof(D2ItemsTxt) * gnArmorTxtRecordCount_0096CA6C);

    pItems += gnArmorTxtRecordCount_0096CA6C;
    gpMiscTxt_0096CA70 = pItems;
    memcpy(pItems, pMisc, sizeof(D2ItemsTxt) * gnMiscTxtRecordCount_0096CA74);

    DATATBLS_UnloadBin(pWeapons);
    DATATBLS_UnloadBin(pArmor);
    DATATBLS_UnloadBin(pMisc);

    DATATBLS_GetBinFileHandle(hArchive, "itemscode", &gpItemsCode_0096BCC8, &gnItemsCodeSize_0096BCCC, &gnItemsCodeSizeEx_0096BCD0);

    if (!gbCompileTxt)
    {
        for (int i = 0; i < gnItemsTxtRecordCount_0096CA58; ++i)
        {
            sub_006BD230_AddLinkCode(gpItemsLinker_0096BCC4, gpItemsTxt_0096CA5C[i].dwCode);
        }
    }

    gpIndexOldToCurrent_0096CA78 = (unsigned short*)FOG_AllocPool(0, sizeof(unsigned short) * gnItemsTxtRecordCount_0096CA58, ".\\DATATBLS\\ItemTbls.cpp", 431, 0);
    memset(gpIndexOldToCurrent_0096CA78, 0, sizeof(unsigned short) * gnItemsTxtRecordCount_0096CA58);

    int i = 0;
    if (i < gnItemsTxtRecordCount_0096CA58)
    {
        D2ItemsTxt* pItemsTxt = gpItemsTxt_0096CA5C;
        int nCount = 0;
        do
        {
            if (pItemsTxt[i].wVersion == 0)
            {
                gpIndexOldToCurrent_0096CA78[nCount] = i;
                ++nCount;
            }
            ++i;
        }
        while (i < gnItemsTxtRecordCount_0096CA58);
    }
}
