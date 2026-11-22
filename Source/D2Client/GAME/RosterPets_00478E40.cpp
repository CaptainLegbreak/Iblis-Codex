#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2ClientGame.h"
struct D2UnitStrc;

#define PETTYPE_FLAG_PARTY 4
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2RosterPetStrc;
struct D2PetTypeTxt;
struct D2ClientEntryStrc;
struct D2InvRectStrc;
struct D2InventoryGridInfoStrc;
struct D2InvCompGridStrc;


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId); // 0x00479BB0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440
int __fastcall sub_0047A070_TestPvpFlag8(int nUnitId1, int nUnitId2); // 0x0047A070
int __cdecl sub_0044DCC0(); // 0x0044DCC0

void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect); // 0x0065C180
void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270
int __fastcall sub_004B3230_GetTickPair(int* pUnitId); // 0x004B3230
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30
extern D2InventoryGridInfoStrc gGrid_007BCA78; // 0x007BCA78
extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0
extern D2InventoryGridInfoStrc gGrid_007BCB18; // 0x007BCB18
extern D2InvRectStrc gInvRect_007BCB30; // 0x007BCB30
extern D2InventoryGridInfoStrc gGrid_007BCB40; // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB58; // 0x007BCB58
extern D2InventoryGridInfoStrc gGrid_007BCB70; // 0x007BCB70
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
extern D2InvRectStrc gRect_007BCBB0; // 0x007BCBB0
extern D2InventoryGridInfoStrc gInventoryGrid_007BCBC0; // 0x007BCBC0
extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58
extern D2InvCompGridStrc gaBodyLocRects_007BCD38[11]; // 0x007BCD38

// 0x00478E40
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nKey)
            return &pPet->tEntry;
    }
    return 0;
}

