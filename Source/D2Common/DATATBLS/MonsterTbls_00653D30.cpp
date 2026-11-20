#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define MON_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MonStatsTxt;
struct D2TCExShortStrc;
struct D2SuperUniquesTxt;
struct D2NpcTxt;
struct D2MonSoundsTxt;
struct D2MonItemPercentTxt;
struct D2MonRecord0C;
struct D2MonItemPercentDataTbl;


struct D2TCExShortStrc { unsigned short nGroup; short nLevel; char unk0x04[0x28 - 4]; void* pInfo; };

struct D2SuperUniquesTxt { char unk[0x34]; };

struct D2NpcTxt { unsigned int dwNpc; char unk[0x4C - 4]; };

struct D2MonSoundsTxt { char unk[0x94]; };

struct D2MonItemPercentTxt { int nValue; };

struct D2MonRecord0C { char unk[0xC]; };

struct D2MonItemPercentDataTbl { int nMonItemPercentTxtRecordCount; D2MonItemPercentTxt* pMonItemPercentTxt; };


extern void* gpMonTable_96BDC4; // 0x0096BDC4
extern D2TxtLinkStrc* gpMonTableLinker_96BDC8; // 0x0096BDC8
extern int gnMonTable_96BDCC; // 0x0096BDCC
extern void* gpHirelingTxt; // 0x0096BDD0
extern int gnNpcTxtRecordCount; // 0x0096C5DC
extern int gnTreasureClassEx; // 0x0096C5F0
extern int gnMonStatsTxtRecordCount; // 0x0096C6B0
extern D2TxtLinkStrc* gpMonSoundsLinker; // 0x0096C6B8
extern void* gpMonTypeTxt; // 0x0096C6C0
extern D2TxtLinkStrc* gpMonTypeLinker_0096C6C4; // 0x0096C6C4
extern void* gpMonPresetTxt; // 0x0096C6D8
extern void* gpMonPresetTxtActSections[5]; // 0x0096C6DC
extern int gnMonPresetTxtActRecordCounts[5]; // 0x0096C6F0
extern D2TxtLinkStrc* gpSuperUniquesLinker; // 0x0096C708
extern void* gpMonTable_96C7A0; // 0x0096C7A0
extern int gnMonTable_96C7A4; // 0x0096C7A4
extern void* gpMonTable_96C7A8; // 0x0096C7A8
extern int gnMonTable_96C7B0; // 0x0096C7B0
extern D2MonRecord0C* gpMonTableRecords_96C7B4; // 0x0096C7B4
extern int gnMonTableRecords_96C7B8; // 0x0096C7B8
extern void* gpMonTable_96C810; // 0x0096C810
extern int gnMonTable_96C814; // 0x0096C814
extern D2TxtLinkStrc* gpMonTableLinker_96C85C; // 0x0096C85C
extern void* gpMonTable_96C860; // 0x0096C860
extern int gnMonTable_96C864; // 0x0096C864
extern D2TxtLinkStrc* gpMonTableLinker_96C868; // 0x0096C868
extern void* gpMonTableBuffer_96C874; // 0x0096C874
extern D2TxtLinkStrc* gpMonUModLinker; // 0x0096C87C
extern void* gpMonUModTxt; // 0x0096C880
extern int gnMonUModTxtRecordCount; // 0x0096C884
extern D2MonItemPercentDataTbl gMonItemPercentDataTables; // 0x0096D480
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnHirelingIndex[2][256]; // 0x0096BDD8
extern D2NpcTxt* gpNpcTxt; // 0x0096C5D8
extern D2TCExShortStrc* gpTreasureClassEx; // 0x0096C5EC
extern D2MonStatsTxt* gpMonStatsTxt; // 0x0096C6A8
extern D2MonSoundsTxt* gpMonSoundsTxt; // 0x0096C6B4
extern int gnMonSoundsTxtRecordCount; // 0x0096C6BC
extern D2SuperUniquesTxt* gpSuperUniquesTxt; // 0x0096C704
extern int gnSuperUniquesTxtRecordCount; // 0x0096C70C
extern void* gpMonTable_96C86C; // 0x0096C86C

int gnHirelingIndex[2][256]; // 0x0096BDD8

D2NpcTxt* gpNpcTxt; // 0x0096C5D8

D2TCExShortStrc* gpTreasureClassEx; // 0x0096C5EC

D2MonStatsTxt* gpMonStatsTxt; // 0x0096C6A8

D2MonSoundsTxt* gpMonSoundsTxt; // 0x0096C6B4

int gnMonSoundsTxtRecordCount; // 0x0096C6BC

D2SuperUniquesTxt* gpSuperUniquesTxt; // 0x0096C704

int gnSuperUniquesTxtRecordCount; // 0x0096C70C

void* gpMonTable_96C86C; // 0x0096C86C

// 0x00653D30
void __fastcall sub_00653D30()
{
    if (gpMonStatsTxt)
    {
        DATATBLS_UnloadBin(gpMonStatsTxt);
        FOG_FreeLinker(gpMonStatsLinker);
    }
    gpMonStatsTxt = 0;
}

// 0x00653D60
void __stdcall DATATBLS_SetVelocityInMonStatsTxtRecord(int nMonsterId, short nVelocity)
{
    MON_ASSERT(gpMonStatsTxt, 751);

    if (nMonsterId >= 0 && nMonsterId < gnMonStatsTxtRecordCount)
    {
        gpMonStatsTxt[nMonsterId].nVelocity = nVelocity;
    }
}

// 0x00654D50
void __fastcall sub_00654D50()
{
    FOG_FreeLinker(gpTreasureClassExLinker);

    for (int i = 0; i < gnTreasureClassEx; ++i)
    {
        if (gpTreasureClassEx[i].pInfo)
        {
            sub_0040B480(0, gpTreasureClassEx[i].pInfo, ".\\DATATBLS\\MonsterTbls.cpp", 1603, 0);
        }
    }

    sub_0040B480(0, gpTreasureClassEx, ".\\DATATBLS\\MonsterTbls.cpp", 1607, 0);
    gpTreasureClassEx = 0;
    gnTreasureClassEx = 0;
}

// 0x00654DD0
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromName(char* szText)
{
    int nId = FOG_GetRowFromTxt(gpTreasureClassExLinker, szText, 0);
    if (nId >= 0)
    {
        return &gpTreasureClassEx[nId];
    }

    return 0;
}

// 0x00654E00
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromIdAndLevel(unsigned short wTCId, int nLvl)
{
    D2TCExShortStrc* pTCExRecord = 0;
    D2TCExShortStrc* pNext = 0;

    if (wTCId > 0 && wTCId < gnTreasureClassEx)
    {
        pTCExRecord = &gpTreasureClassEx[wTCId];
        if (nLvl > 0 && pTCExRecord->nGroup)
        {
            pNext = pTCExRecord + 1;

            while (pNext->nGroup == pTCExRecord->nGroup)
            {
                if (pNext->nLevel > nLvl)
                {
                    break;
                }

                pTCExRecord = pNext;
                ++pNext;
            }
        }

        return pTCExRecord;
    }

    return 0;
}

// 0x00654E70
int __stdcall sub_00654E70(int a1, int a2)
{
    return 0;
}

// 0x00654FC0
void __fastcall DATATBLS_UnloadMonItemPercentTxt()
{
    DATATBLS_UnloadBin(gMonItemPercentDataTables.pMonItemPercentTxt);
}

// 0x00654FD0
D2MonItemPercentDataTbl* __fastcall DATATBLS_GetMonItemPercentDataTables()
{
    return &gMonItemPercentDataTables;
}

// 0x00654FE0
D2MonItemPercentTxt* __stdcall DATATBLS_GetMonItemPercentTxtRecord(int nId)
{
    if (nId >= gMonItemPercentDataTables.nMonItemPercentTxtRecordCount || nId == -1)
    {
        return 0;
    }
    else
    {
        MON_ASSERT(gMonItemPercentDataTables.pMonItemPercentTxt, 1756);
        MON_ASSERT(&gMonItemPercentDataTables.pMonItemPercentTxt[nId], 1756 + 1);
        return &gMonItemPercentDataTables.pMonItemPercentTxt[nId];
    }
}

// 0x006552A0
void __fastcall sub_006552A0()
{
    if (gpMonUModLinker)
    {
        FOG_FreeLinker(gpMonUModLinker);
        gpMonUModLinker = 0;
    }

    if (gpMonUModTxt)
    {
        DATATBLS_UnloadBin(gpMonUModTxt);
        gpMonUModTxt = 0;
    }

    gnMonUModTxtRecordCount = 0;
}

// 0x006556A0
void __fastcall sub_006556A0()
{
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
}

// 0x006556E0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId)
{
    if (nSuperUniqueId >= gnSuperUniquesTxtRecordCount)
    {
        return 0;
    }

    return &gpSuperUniquesTxt[nSuperUniqueId];
}

// 0x00655710
int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount()
{
    return gnSuperUniquesTxtRecordCount;
}

// 0x006562B0
void __fastcall sub_006562B0()
{
    DATATBLS_UnloadBin(gpHirelingTxt);
    gnHirelingTxtRecordCount = 0;

    for (int i = 0; i < 256; ++i)
    {
        gnHirelingIndex[0][i] = -1;
        gnHirelingIndex[1][i] = -1;
    }
}

// 0x006568F0
void __fastcall sub_006568F0_FreeNpcTable()
{
    DATATBLS_UnloadBin(gpNpcTxt);
}

// 0x00656900
D2NpcTxt* __stdcall DATATBLS_GetNpcTxtRecord(unsigned int dwNpcId)
{
    for (int i = 0; i < gnNpcTxtRecordCount; ++i)
    {
        D2NpcTxt* pNpcTxtRecord = &gpNpcTxt[i];
        if (pNpcTxtRecord->dwNpc == dwNpcId)
        {
            return pNpcTxtRecord;
        }
    }

    return 0;
}

// 0x00656F60
void __fastcall sub_00656F60_FreeMonSoundsTable()
{
    if (gpMonSoundsTxt)
    {
        DATATBLS_UnloadBin(gpMonSoundsTxt);
        FOG_FreeLinker(gpMonSoundsLinker);
        gnMonSoundsTxtRecordCount = 0;
    }
}

// 0x00656F90
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId)
{
    if (gpMonSoundsTxt && nSoundId >= 0 && nSoundId < gnMonSoundsTxtRecordCount)
    {
        return &gpMonSoundsTxt[nSoundId];
    }

    return 0;
}

// 0x00656FC0
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId)
{
    if (gpMonSoundsTxt && gpMonStatsTxt && nMonsterId < gnMonStatsTxtRecordCount)
    {
        int nSoundId = gpMonStatsTxt[nMonsterId].wMonSound;
        if (nSoundId >= 0 && nSoundId < gnMonSoundsTxtRecordCount)
        {
            return &gpMonSoundsTxt[nSoundId];
        }
    }

    return 0;
}

// 0x00658440
void __fastcall DATATBLS_UnloadMonTypeTxt()
{
    if (gpMonTypeTxt)
    {
        DATATBLS_UnloadBin(gpMonTypeTxt);
        FOG_FreeLinker(gpMonTypeLinker_0096C6C4);
    }
}

// 0x006586D0
void __fastcall sub_006586D0()
{
    if (gpMonTable_96C86C)
    {
        DATATBLS_UnloadBin(gpMonTable_96C86C);
        FOG_FreeLinker(gpMonTableLinker_96C868);
        sub_0040B480(0, gpMonTableBuffer_96C874, ".\\DATATBLS\\MonsterTbls.cpp", 2838, 0);
        gpMonTable_96C86C = 0;
        gpMonTableLinker_96C868 = 0;
    }
}

// 0x006594D0
void __fastcall sub_006594D0()
{
    if (gpMonTable_96C860)
    {
        DATATBLS_UnloadBin(gpMonTable_96C860);
        FOG_FreeLinker(gpMonTableLinker_96C85C);
    }
    gnMonTable_96C864 = 0;
}

// 0x00659970
void __fastcall sub_00659970()
{
    if (gpMonTable_96C7A0)
    {
        DATATBLS_UnloadBin(gpMonTable_96C7A0);
        gnMonTable_96C7A4 = 0;
    }
}

// 0x00659B40
void* __stdcall DATATBLS_GetMonPresetTxtActSection(int nAct, int* pRecordCount)
{
    if (pRecordCount)
    {
        if (nAct >= 0 && nAct < 5 && gpMonPresetTxt)
        {
            *pRecordCount = gnMonPresetTxtActRecordCounts[nAct];
            return gpMonPresetTxtActSections[nAct];
        }

        *pRecordCount = 0;
    }

    return 0;
}

// 0x00659B80
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique)
{
    switch (nType)
    {
    case 0:
        nSuperUnique += gnSuperUniquesTxtRecordCount;
    case 2:
        nSuperUnique += sgptDataTables->nMonStatsTxtRecordCount;
        break;
    }

    return nSuperUnique;
}

// 0x00659C30
void __fastcall sub_00659C30()
{
    if (gpMonTable_96BDC4)
    {
        DATATBLS_UnloadBin(gpMonTable_96BDC4);
        FOG_FreeLinker(gpMonTableLinker_96BDC8);
        gnMonTable_96BDCC = 0;
    }
}

// 0x00659DE0
void __fastcall sub_00659DE0()
{
    if (gpMonTable_96C7A8)
    {
        DATATBLS_UnloadBin(gpMonTable_96C7A8);
        FOG_FreeLinker(gpMonTableLinker_96C7AC);
        gnMonTable_96C7B0 = 0;
    }

    if (gpMonTableRecords_96C7B4)
    {
        sub_0040B480(0, gpMonTableRecords_96C7B4, ".\\DATATBLS\\MonsterTbls.cpp", 3306, 0);
        gnMonTableRecords_96C7B8 = 0;
    }
}

// 0x00659E30
D2MonRecord0C* __stdcall sub_00659E30(int nIndex)
{
    if (nIndex >= 0 && nIndex < gnMonTableRecords_96C7B8)
    {
        return &gpMonTableRecords_96C7B4[nIndex];
    }

    return 0;
}

// 0x0065A170
void __fastcall sub_0065A170()
{
    if (gpMonTable_96C810)
    {
        DATATBLS_UnloadBin(gpMonTable_96C810);
        gnMonTable_96C814 = 0;
    }
}

void* gpMonPresetTxtActSections[5]; // 0x0096C6DC

int gnMonPresetTxtActRecordCounts[5]; // 0x0096C6F0

// 0x00659AF0
void __fastcall sub_00659AF0()
{
    if (gpMonPresetTxt)
    {
        DATATBLS_UnloadBin(gpMonPresetTxt);
    }

    for (int i = 0; i < 5; ++i)
    {
        gpMonPresetTxtActSections[i] = 0;
        gnMonPresetTxtActRecordCounts[i] = 0;
    }
}
