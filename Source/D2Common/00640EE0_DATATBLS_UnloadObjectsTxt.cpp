struct D2TxtLinkStrc;
struct D2ObjectsTxt;
struct D2ShrinesTxt;
struct D2SuperUniquesTxt;

void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0
void __fastcall sub_006562B0();                                                               // 0x006562B0
void __fastcall sub_00659AF0();                                                              // 0x00659AF0
void __fastcall sub_00659DE0();                                                           // 0x00659DE0
void __fastcall sub_00654D50();                                                        // 0x00654D50
void __cdecl sub_00653E20();                                                             // 0x00653E20

D2ObjectsTxt* gpObjectsTxt;                                                                                 // 0x0096D470
extern int gnObjectsTxtRecordCount;                                                                         // 0x0096D474
void* gpObjgroupTxt;                                                                                        // 0x0096D478
extern int gnObjgroupTxtRecordCount;                                                                        // 0x0096D47C
D2ShrinesTxt* gpShrinesTxt;                                                                                 // 0x0096D468
extern int gnShrinesTxtRecordCount;                                                                         // 0x0096D46C

void* gpMonTable_96C810;                                                                                    // 0x0096C810
int gnMonTable_96C814;                                                                                      // 0x0096C814
extern void* gpNpcTxt;                                                                                      // 0x0096C5D8
extern D2SuperUniquesTxt* gpSuperUniquesTxt;                                                                // 0x0096C704
D2TxtLinkStrc* gpSuperUniquesLinker;                                                                        // 0x0096C708
extern int gnSuperUniquesTxtRecordCount;                                                                    // 0x0096C70C
D2TxtLinkStrc* gTxtLink_0096C87C;                                                                           // 0x0096C87C
void* gpMonumodTxt;                                                                                         // 0x0096C880
extern int gnMonumodTxtRecordCount;                                                                         // 0x0096C884
extern void* gpMonstatsTxt;                                                                                 // 0x0096C6A8
extern D2TxtLinkStrc* gTxtLink_0096C6AC;                                                                    // 0x0096C6AC
void* gpMonTypeTxt;                                                                                         // 0x0096C6C0
D2TxtLinkStrc* gTxtLink_0096C6C4;                                                                           // 0x0096C6C4
extern D2TxtLinkStrc* gTxtLink_0096C85C;                                                                    // 0x0096C85C
void* gpMonpropTxt;                                                                                         // 0x0096C860
int gnMonpropTxtRecordCount;                                                                                // 0x0096C864
extern void* gpMonsoundsTxt;                                                                                // 0x0096C6B4
extern D2TxtLinkStrc* gTxtLink_0096C6B8;                                                                    // 0x0096C6B8
extern int gnMonsoundsTxtRecordCount;                                                                       // 0x0096C6BC
void* gpMonlvlTxt;                                                                                          // 0x0096C7A0
int gnMonlvlTxtRecordCount;                                                                                 // 0x0096C7A4

// 0x00640EE0
void __fastcall DATATBLS_UnloadObjectsTxt()
{
    DATATBLS_UnloadBin(gpObjectsTxt);
    gpObjectsTxt = 0;
    gnObjectsTxtRecordCount = 0;
}

// 0x00640F00
void __fastcall DATATBLS_UnloadObjGroupTxt()
{
    DATATBLS_UnloadBin(gpObjgroupTxt);
    gpObjgroupTxt = 0;
    gnObjgroupTxtRecordCount = 0;
}

// 0x00641510
void __fastcall DATATBLS_UnloadShrinesTxt()
{
    DATATBLS_UnloadBin(gpShrinesTxt);
    gpShrinesTxt = 0;
    gnShrinesTxtRecordCount = 0;
}

// 0x0065A190
void __fastcall DATATBLS_UnloadSomeMonsterTxts()
{
    if (gpMonTable_96C810)
    {
        DATATBLS_UnloadBin(gpMonTable_96C810);
        gnMonTable_96C814 = 0;
    }

    DATATBLS_UnloadBin(gpNpcTxt);

    sub_006562B0();
    sub_00659AF0();

    if (gpSuperUniquesLinker)
    {
        FOG_FreeLinker(gpSuperUniquesLinker);
    }
    if (gpSuperUniquesTxt)
    {
        DATATBLS_UnloadBin(gpSuperUniquesTxt);
        gpSuperUniquesTxt = 0;
    }
    gnSuperUniquesTxtRecordCount = 0;

    if (gTxtLink_0096C87C)
    {
        FOG_FreeLinker(gTxtLink_0096C87C);
        gTxtLink_0096C87C = 0;
    }
    if (gpMonumodTxt)
    {
        DATATBLS_UnloadBin(gpMonumodTxt);
        gpMonumodTxt = 0;
    }
    gnMonumodTxtRecordCount = 0;

    if (gpMonstatsTxt)
    {
        DATATBLS_UnloadBin(gpMonstatsTxt);
        FOG_FreeLinker(gTxtLink_0096C6AC);
    }
    gpMonstatsTxt = 0;

    if (gpMonTypeTxt)
    {
        DATATBLS_UnloadBin(gpMonTypeTxt);
        FOG_FreeLinker(gTxtLink_0096C6C4);
    }

    if (gpMonpropTxt)
    {
        DATATBLS_UnloadBin(gpMonpropTxt);
        FOG_FreeLinker(gTxtLink_0096C85C);
    }
    gnMonpropTxtRecordCount = 0;

    if (gpMonsoundsTxt)
    {
        DATATBLS_UnloadBin(gpMonsoundsTxt);
        FOG_FreeLinker(gTxtLink_0096C6B8);
        gnMonsoundsTxtRecordCount = 0;
    }

    sub_00659DE0();
    sub_00654D50();

    if (gpMonlvlTxt)
    {
        DATATBLS_UnloadBin(gpMonlvlTxt);
        gnMonlvlTxtRecordCount = 0;
    }

    sub_00653E20();
}
