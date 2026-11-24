// 0x006BD230 (Fog export 10215), near version. Not a match: everything equals the original except the
// unused 4-byte slot (`push ecx` after the frame setup, `mov esp, ebp` in the epilogue, and the 2-byte loop pad
// that follows from it). Registers are the original's (pLink in ebx, nLow esi, nHigh edi, cap in eax then nNew
// in esi). Insert before `// build: context sub_006BCE20_Shim` in Fog/Src/Excel/Excel.cpp; the preamble below
// is the declarations the batch harness used.
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

typedef unsigned long DWORDX;
extern const char gszExcelSrc[]; // 0x006FC448
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
#define KEY(i) (*(unsigned int*)pLink->entries[i].code)
#define GROWX if (pLink->unk_04 <= pLink->count) { int nNew = pLink->unk_04 + 64; pLink->entries = (D2TxtLinkEntryStrc*)FOG_ReallocPool(0, pLink->entries, nNew * sizeof(D2TxtLinkEntryStrc), gszExcelSrc, 0x3DF, 0); memset(&pLink->entries[pLink->unk_04], 0, 64 * sizeof(D2TxtLinkEntryStrc)); pLink->unk_04 = nNew; }
#define ASR D2_ASSERT(pLink, 0x3D1); D2_ASSERT(!pLink->pFirstNode, 0x3D8);
#define TAILC(CNT) if (nLow < CNT) memmove(&pLink->entries[nLow + 1], &pLink->entries[nLow], (CNT - nLow) * sizeof(D2TxtLinkEntryStrc)); KEY(nLow) = nKey; pLink->entries[nLow].index = CNT; int nResult = pLink->entries[nLow].index; ++pLink->count; return nResult;

int __stdcall FOG_10215_Near(D2TxtLinkStrc* pLink, unsigned int nKey) { int nLow, nHigh, nMid, nNew, nResult; unsigned int nCur; D2TxtLinkEntryStrc* pEntries;
 ASR if (pLink->unk_04 <= pLink->count) { nNew = pLink->unk_04 + 64; pLink->entries = (D2TxtLinkEntryStrc*)FOG_ReallocPool(0, pLink->entries, nNew * sizeof(D2TxtLinkEntryStrc), gszExcelSrc, 0x3DF, 0); memset(&pLink->entries[pLink->unk_04], 0, 64 * sizeof(D2TxtLinkEntryStrc)); pLink->unk_04 = nNew; }
 for (;;) { pEntries = pLink->entries; nLow = 0; for (nHigh = pLink->count; nLow < nHigh; ) { nMid = nLow + (nHigh - nLow) / 2; nCur = *(unsigned int*)pEntries[nMid].code; if (nKey > nCur) nLow = nMid + 1; else if (nKey < nCur) nHigh = nMid; else goto found; } break; found: ++nKey; }
 if (nLow < pLink->count) memmove(&pLink->entries[nLow + 1], &pLink->entries[nLow], (pLink->count - nLow) * sizeof(D2TxtLinkEntryStrc)); KEY(nLow) = nKey; pLink->entries[nLow].index = pLink->count; nResult = pLink->entries[nLow].index; ++pLink->count; return nResult; }
