#include "D2Structs.h"
#ifdef MOVED_TEST
#define STAT_ID_LIMIT 253
#define ASSERT_LINE 708
#define ALLOC_LINE 713
#define MESSAGE_SIZE 28
#define PAYLOAD_SHIFT 4
#define MESSAGE_HEADER 0xA3
#else
#define STAT_ID_LIMIT 255
#define ASSERT_LINE 704
#define ALLOC_LINE 709
#define MESSAGE_SIZE 24
#define PAYLOAD_SHIFT 0
#define MESSAGE_HEADER 0xA1
#endif
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};


void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
// 0x00571960
void __fastcall sub_00571960_QueueStatChange(D2UnitStrc* pUnit, unsigned short nStat, int nOldValue, int nNewValue)
{
    D2_ASSERT(nStat < STAT_ID_LIMIT, ASSERT_LINE);
    if (nOldValue != nNewValue)
    {
        D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, MESSAGE_SIZE, ".\\UNIT\\SUnitMsg.cpp", ALLOC_LINE, 0);
        pMsg->nHeader = MESSAGE_HEADER;
        pMsg->pNext = 0;
        *(int*)((char*)pMsg + 8 + PAYLOAD_SHIFT) = !pUnit ? -1 : pUnit->dwUnitId;
        *((unsigned char*)pMsg + 12 + PAYLOAD_SHIFT) = (unsigned char)nStat;
        *(int*)((char*)pMsg + 16 + PAYLOAD_SHIFT) = nOldValue;
        *(int*)((char*)pMsg + 20 + PAYLOAD_SHIFT) = nNewValue;
        if (!pUnit->pMsgFirst)
            pUnit->pMsgFirst = pMsg;
        if (pUnit->pMsgLast)
            pUnit->pMsgLast->pNext = pMsg;
        pUnit->pMsgLast = pMsg;
        UNITROOM_RefreshUnit(pUnit);
    }
}
