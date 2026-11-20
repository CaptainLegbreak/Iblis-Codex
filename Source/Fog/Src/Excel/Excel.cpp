#include "Fog.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), line); exit(-1); }

struct Server;
struct SafeSocketView;
struct ConnectionView;
struct LinkNode;
struct LinkerView;
struct PaletteColor;
struct Unit;
struct ReceiveQueue;
struct BinFile;
struct ClientNode;
struct PaletteTables;
struct ReceiveConnection;
struct Obj006BCDE0;
struct D2SNameEntryStrc;
struct D2SNameListStrc;
struct D2SNameNodeStrc;
struct D2Block006BD040Strc;
struct D2ExcelNode006BD070Strc;
struct RoomFlags;
struct PathFlags;
struct KeyValue;
struct CodeRow;
struct CodeOutput;
struct LinkView;
struct CodeLink;
struct Vector;
struct DirectionRecord;
struct D2TxtLinkEntryStrc;
struct D2TxtLinkStrc;
struct D2TreeNode006BD330Strc;
struct D2StringTableStrc;
struct D2TxtLinkNodeStrc;
struct D2BinFileStrc;

typedef unsigned short U16;

struct SafeSocketView
{
    int connected;
};

struct ConnectionView
{
    char retained[0x110];
    SafeSocketView* socket;
};

struct LinkNode
{
    char retained[0x24];
    LinkNode* firstChild;
    LinkNode* secondChild;
};

struct LinkerView
{
    char retained[0x8];
    void* entries;
    LinkNode* root;
};

typedef char check_connected[OFFSET(SafeSocketView,connected)==0?1:-1];

typedef char check_socket[OFFSET(ConnectionView,socket)==0x110?1:-1];

typedef char check_node_first[OFFSET(LinkNode,firstChild)==0x24?1:-1];

typedef char check_node_second[OFFSET(LinkNode,secondChild)==0x28?1:-1];

typedef char check_node_size[sizeof(LinkNode)==0x2C?1:-1];

typedef char check_entries[OFFSET(LinkerView,entries)==0x8?1:-1];

typedef char check_root[OFFSET(LinkerView,root)==0xC?1:-1];

typedef char check_linker_size[sizeof(LinkerView)==0x10?1:-1];

extern "C" void __fastcall sub_0040DDD0_Lock(SafeSocketView* socket);
extern "C" int __fastcall sub_0040DD80_SendNoLock(SafeSocketView* socket,const char* data,int length);
extern "C" void __fastcall sub_0040DDE0_Unlock(SafeSocketView* socket);
extern "C" void __fastcall sub_006BD070_FreeNodes(LinkNode* node);
extern "C" int __fastcall sub_0040B480_FreePool(void* pool,void* block,const char* file,int line,int unused);
extern "C" const char gExcelFile[]; // 0x006FC448

struct Unit
{
    int type;
    int classId;
    void* pool;
    int f_C;
};

typedef char check_Unit_classId[OFFSET(Unit,classId)==4?1:-1];

typedef char check_Unit_unitId[OFFSET(Unit,f_C)==0xC?1:-1];

struct BinFile
{
    void* data;
};

struct ClientNode
{
    int clientId;
    ClientNode* next;
    U8 unknown8[0x18];
    U32 gameGuid;
};

typedef char check_ClientNode_next[OFFSET(ClientNode,next)==4?1:-1];

typedef char check_ClientNode_gameGuid[OFFSET(ClientNode,gameGuid)==0x20?1:-1];

typedef char check_ClientNode_size[sizeof(ClientNode)==0x24?1:-1];

extern "C" U8 __stdcall sub_00605210_FindNearestColor(const U8* palette,U32 count,int c0,int c1,int c2);
extern "C" int __fastcall sub_0063E860_UnitPredicate(Unit* unit);
extern "C" int __fastcall sub_00457490_MonsterFlag(int classId,int flag);
extern "C" U32 __fastcall sub_006C2090_ReadQueue(ReceiveQueue* queue,char* buffer,int capacity);
extern "C" int __fastcall sub_0040B3C0_Free(void* block,const char* file,int line,int flags);
extern "C" ClientNode* __fastcall sub_006BE540_FindClient(Server* server,int clientId);
extern "C" const int gCollisionPatterns_006EB3DC[4];
extern "C" const char gExcelFile_006FC448[]; // 0x006FC448

struct Obj006BCDE0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2Block006BD040Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2ExcelNode006BD070Strc
{
    unsigned char unk_00[0x24];
    D2ExcelNode006BD070Strc* pLeft24;
    D2ExcelNode006BD070Strc* pRight28;
};

extern const char gszExcelSourceFile_006FC448[]; // 0x006FC448

typedef signed char S8;

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

struct RoomFlags
{
    char pad0[0x28];
    U32 flags;
};

typedef char check_RoomFlags_flags[OFFSET(RoomFlags,flags)==0x28?1:-1];

typedef char check_RoomFlags_size[sizeof(RoomFlags)==0x2C?1:-1];

struct PathFlags
{
    char pad0[0x34];
    U32 flags;
};

typedef char check_PathFlags_flags[OFFSET(PathFlags,flags)==0x34?1:-1];

typedef char check_PathFlags_size[sizeof(PathFlags)==0x38?1:-1];

struct KeyValue
{
    U32 key;
    int value;
};

typedef char check_KeyValue_value[OFFSET(KeyValue,value)==4?1:-1];

typedef char check_KeyValue_size[sizeof(KeyValue)==8?1:-1];

struct CodeRow
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    int row;
};

typedef char check_CodeRow_row[OFFSET(CodeRow,row)==4?1:-1];

typedef char check_CodeRow_c0[OFFSET(CodeRow,c0)==0?1:-1];

typedef char check_CodeRow_c1[OFFSET(CodeRow,c1)==1?1:-1];

typedef char check_CodeRow_c2[OFFSET(CodeRow,c2)==2?1:-1];

typedef char check_CodeRow_c3[OFFSET(CodeRow,c3)==3?1:-1];

typedef char check_CodeRow_size[sizeof(CodeRow)==8?1:-1];

struct CodeOutput
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    S8 terminal;
};

typedef char check_CodeOutput_terminal[OFFSET(CodeOutput,terminal)==4?1:-1];

typedef char check_CodeOutput_c0[OFFSET(CodeOutput,c0)==0?1:-1];

typedef char check_CodeOutput_c1[OFFSET(CodeOutput,c1)==1?1:-1];

typedef char check_CodeOutput_c2[OFFSET(CodeOutput,c2)==2?1:-1];

typedef char check_CodeOutput_c3[OFFSET(CodeOutput,c3)==3?1:-1];

typedef char check_CodeOutput_size[sizeof(CodeOutput)==5?1:-1];

struct LinkView
{
    int count;
    char pad4[0x4];
    KeyValue* entries;
};

typedef char check_LinkView_entries[OFFSET(LinkView,entries)==0x8?1:-1];

typedef char check_LinkView_size[sizeof(LinkView)==0xC?1:-1];

struct CodeLink
{
    int count;
    char pad4[0x4];
    CodeRow* entries;
};

typedef char check_CodeLink_entries[OFFSET(CodeLink,entries)==0x8?1:-1];

typedef char check_CodeLink_size[sizeof(CodeLink)==0xC?1:-1];

struct Vector
{
    int x;
    int y;
};

typedef char check_Vector_y[OFFSET(Vector,y)==4?1:-1];

typedef char check_Vector_size[sizeof(Vector)==8?1:-1];

struct DirectionRecord
{
    int x;
    int y;
    int angle;
};

typedef char check_DirectionRecord_y[OFFSET(DirectionRecord,y)==4?1:-1];

typedef char check_DirectionRecord_angle[OFFSET(DirectionRecord,angle)==8?1:-1];

typedef char check_DirectionRecord_size[sizeof(DirectionRecord)==12?1:-1];

extern DirectionRecord gDirectionTable_006EB7E0[128];

struct D2TxtLinkEntryStrc { char code[4]; int index; };

struct D2TxtLinkStrc
{
    int count;
    int unk_04;
    union
    {
        D2TxtLinkEntryStrc* entries;
        void* pTbl;
    };
    D2TxtLinkNodeStrc* pFirstNode;
};

struct D2TreeNode006BD330Strc
{
    unsigned char unk_00[0x20];
    int nId20;
    D2TreeNode006BD330Strc* pLeft24;
    D2TreeNode006BD330Strc* pRight28;
};

extern D2TreeNode006BD330Strc* const gpTreeSentinel_0074C3D8; // 0x0074C3D8

struct D2StringTableStrc { int count; int unk4; int unk8; void* data; };

extern const char* gszFallback_0074C3D8; // 0x0074C3D8
const char* __fastcall sub_006BD330_GetString(void*, int); // 0x006BD330

struct D2TxtLinkNodeStrc
{
    char szText[0x20];
    int nLinkIndex;
    D2TxtLinkNodeStrc* pPrevious;
    D2TxtLinkNodeStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __fastcall sub_004113C0(char* szText, int nLength); // 0x004113C0
extern "C" const char gszExcelCppFile[]; // 0x006FC448
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLink, const char* szText, int bLogError); // 0x006BD3C0
static __declspec(noinline) void sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppNode, D2TxtLinkNodeStrc* pNew);

struct D2BinFileStrc
{
    char* pDataBuffer;
    char* pFirstRow;
    int nRecordCount;
    unsigned int nColumns;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars); // 0x00413550
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

extern "C" void __fastcall sub_0061BAC0_portalFlag(RoomFlags* room, int reset)
{
    if (reset)
        room->flags &= ~0x400000U;
    else
        room->flags |= 0x400000U;
}

// 0x00648B40
extern "C" void __stdcall sub_00648B40_roomInvalid(PathFlags* path, int invalid)
{
    if (invalid != 0)
        path->flags |= 2U;
    else
        path->flags &= ~2U;
}

// 0x006BC0B0
extern "C" int __stdcall sub_006BC0B0_Send(ConnectionView* connection,const char* data,U16 length)
{
    if (connection && connection->socket && connection->socket->connected != 0)
    {
        int sent = 0;
        sub_0040DDD0_Lock(connection->socket);
        if (data && length)
            sent = sub_0040DD80_SendNoLock(connection->socket,data,length);
        sub_0040DDE0_Unlock(connection->socket);
        return length == (U16)sent;
    }
    return 0;
}

// 0x006BC120
extern "C" U32 __stdcall sub_006BC120_receive(ReceiveConnection* connection, char* buffer, int capacity)
{
    if (!connection)
        return 0;
    return sub_006C2090_ReadQueue(&connection->queue, buffer, capacity);
}

// 0x006BCDA0
extern "C" void __stdcall sub_006BCDA0_freeBinFile(BinFile* file)
{
    sub_0040B3C0_Free(file->data,gExcelFile_006FC448,154,0);
    sub_0040B480_FreePool(0,file,gExcelFile_006FC448,155,0);
}

// 0x006BCDE0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006BCDE0(Obj006BCDE0* pObj) {
    return pObj->dwValue08;
}

// 0x006BCDF0
static __declspec(noinline) unsigned int __stdcall sub_006BCDF0_HashName(const char* szName)
{
    return SStrHash(szName, 0, 0);
}

// build: context sub_006BCE20_MapNames
int __stdcall sub_006BCE20_MapNames(unsigned short* pOut, D2SNameListStrc* pList, D2SNameEntryStrc* pEntries)
{
    D2SNameNodeStrc* aBuckets[256];
    D2SNameNodeStrc aNodes[0x118];
    unsigned int nNodes = 0;
    int nOut = 0;

    D2SNameEntryStrc* pEntry = pEntries;
    for (D2SNameEntryStrc* pCheck = pEntry; pCheck->nType; ++pCheck)
    {
        if (pCheck->nType == 5)
        {
            for (unsigned int i = 1; i < pCheck->nCount; ++i)
            {
                ++pCheck;
                S_ASSERT(pCheck->nType == 5, 0xC4);
            }
        }
    }

    SMemZero(aBuckets, sizeof(aBuckets));

    D2SNameNodeStrc* pCursor = aNodes;
    for (; pEntry->nType; ++pEntry)
    {
        S_ASSERT(nNodes < 0x118, 0xCC);
        ++nNodes;
        D2SNameNodeStrc* pNode = pCursor++;
        unsigned int nHash = sub_006BCDF0_HashName(pEntry->szName);
        unsigned int nBucket = ((((nHash >> 8) ^ nHash) >> 16) ^ (nHash >> 8) ^ nHash) & 0xFF;
        pNode->nHash = nHash;
        pNode->pEntry = pEntry;
        pNode->pNext = aBuckets[nBucket];
        aBuckets[nBucket] = pNode;
    }

    const char* szString = pList->pStrings;
    for (unsigned int i = 0; i < pList->nCount; ++i)
    {
        unsigned int nHash = sub_006BCDF0_HashName(szString);
        unsigned int nBucket = ((((((nHash >> 8) ^ nHash) >> 8) ^ nHash) >> 8) ^ nHash) & 0xFF;
        for (D2SNameNodeStrc* pNode = aBuckets[nBucket]; pNode; pNode = pNode->pNext)
        {
            if (pNode->nHash == nHash && !SStrCmpI(szString, pNode->pEntry->szName, 0x7FFFFFFF))
            {
                pNode->nHash = 0;
                pOut[nOut++] = (unsigned short)(pNode->pEntry - pEntries);
                goto next;
            }
        }
        pOut[nOut++] = 0x7FFF;
next:
        while (*szString)
        {
            ++szString;
        }
        ++szString;
    }

    for (unsigned int j = 0; j < nNodes; ++j)
    {
        if (aNodes[j].nHash)
        {
            pOut[nOut] = (unsigned short)(aNodes[j].pEntry - pEntries);
            ++nOut;
        }
    }

    return nOut;
}

// 0x006BCE00
unsigned int __fastcall sub_006BCE00_XorFoldBytes(int nUnused, unsigned int dwValue)
{
    return (dwValue ^ (dwValue >> 8) ^ (dwValue >> 16) ^ (dwValue >> 24)) & 0xFF;
}

// 0x006BD040
D2Block006BD040Strc* __stdcall sub_006BD040_AllocBlock(const char* szFile, int nLine)
{
    D2Block006BD040Strc* pBlock = (D2Block006BD040Strc*)FOG_AllocPool(0, 0x10, szFile, nLine, 0);
    memset(pBlock, 0, sizeof(D2Block006BD040Strc));
    return pBlock;
}

// 0x006BD070
void __fastcall sub_006BD070_FreeTree(D2ExcelNode006BD070Strc* pNode)
{
    if (pNode->pLeft24)
        sub_006BD070_FreeTree(pNode->pLeft24);
    if (pNode->pRight28)
        sub_006BD070_FreeTree(pNode->pRight28);
    FOG_FreeServerMemory(0, pNode, gszExcelSourceFile_006FC448, 0x346, 0);
}

// 0x006BD0B0
extern "C" void __stdcall sub_006BD0B0_FreeLinker(LinkerView* linker)
{
    if (linker)
    {
        LinkNode* root = linker->root;
        if (root)
        {
            if (root->firstChild)
                sub_006BD070_FreeNodes(root->firstChild);
            if (root->secondChild)
                sub_006BD070_FreeNodes(root->secondChild);
            sub_0040B480_FreePool(0,root,gExcelFile,0x346,0);
        }
        if (linker->entries)
            sub_0040B480_FreePool(0,linker->entries,gExcelFile,0x35D,0);
        sub_0040B480_FreePool(0,linker,gExcelFile,0x360,0);
    }
}

// 0x006BD130
extern "C" int __stdcall sub_006BD130_findKey(LinkView* link, U32 key, int unusedLogError)
{
    int upper = link->count;
    int lower = 0;
    KeyValue* entries = link->entries;
    while (lower < upper)
    {
        int middle = lower + (upper - lower) / 2;
        U32 current = entries[middle].key;
        if (key > current)
            lower = middle + 1;
        else if (key < current)
            upper = middle;
        else
            return entries[middle].value;
    }
    return -1;
}

// 0x006BD180
int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* linker, int index, char* text)
{
    D2TxtLinkEntryStrc* entries = linker->entries;
    if (!entries)
        return 0;
    if (index >= 0 && index < linker->count)
    {
        for (int i = 0; i < linker->count; ++i)
        {
            if (index == entries[i].index)
            {
                text[0] = entries[i].code[0] != ' ' ? entries[i].code[0] : 0;
                text[1] = entries[i].code[1] != ' ' ? entries[i].code[1] : 0;
                text[2] = entries[i].code[2] != ' ' ? entries[i].code[2] : 0;
                text[3] = entries[i].code[3] != ' ' ? entries[i].code[3] : 0;
                text[4] = 0;
                return 1;
            }
        }
    }
    return 0;
}

// 0x006BD330
D2TreeNode006BD330Strc* __fastcall sub_006BD330_FindNode(D2TreeNode006BD330Strc* pNode, int nId)
{
    if (!pNode)
    {
        return gpTreeSentinel_0074C3D8;
    }
    if (pNode->nId20 == nId)
    {
        return pNode;
    }
    D2TreeNode006BD330Strc* pFound;
    if (pNode->pLeft24)
    {
        pFound = sub_006BD330_FindNode(pNode->pLeft24, nId);
        if (pFound != gpTreeSentinel_0074C3D8)
        {
            return pFound;
        }
    }
    if (pNode->pRight28)
    {
        pFound = sub_006BD330_FindNode(pNode->pRight28, nId);
        if (pFound != gpTreeSentinel_0074C3D8)
        {
            return pFound;
        }
    }
    return gpTreeSentinel_0074C3D8;
}

#include "gen/data/Source/Fog/Src/Excel/Excel.inc"

// 0x006BD380
const char* __stdcall sub_006BD380_GetString(D2StringTableStrc* pTable, int index, int useFallback)
{
 if (!pTable || index < 0 || index >= pTable->count) return gszFallback_0074C3D8;
 const char* result = sub_006BD330_GetString(pTable->data, index);
 if ((!result || result == gszFallback_0074C3D8) && useFallback) return gszFallback_0074C3D8;
 return result;
}

// 0x006BD3C0
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLink, const char* szText, int bLogError)
{
    char szKey[0x20];
    SStrCopy(szKey, szText, sizeof(szKey));
    sub_004113C0(szKey, sizeof(szKey));

    D2TxtLinkNodeStrc* pNode = pLink->pFirstNode;
    if (pLink->count && !pNode)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x475);
        exit(-1);
    }

    while (pNode)
    {
        const int nCompare = strcmp(szKey, pNode->szText);
        if (!nCompare)
        {
            return pNode->nLinkIndex;
        }

        if (nCompare < 0)
        {
            pNode = pNode->pPrevious;
        }
        else
        {
            pNode = pNode->pNext;
        }
    }

    return -1;
}

static void sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppNode, D2TxtLinkNodeStrc* pNew)
{
    while (*ppNode)
    {
        D2TxtLinkNodeStrc* pNode = *ppNode;
        const int nCmp = strcmp(pNew->szText, pNode->szText);
        if (nCmp < 0)
        {
            ppNode = &pNode->pPrevious;
        }
        else if (nCmp > 0)
        {
            ppNode = &pNode->pNext;
        }
        else
        {
            FOG_FreePool(0, pNew, gszExcelCppFile, 0x4A7, 0);
            return;
        }
    }

    *ppNode = pNew;
}

// 0x006BD5A0
int __fastcall sub_006BD5A0_AddTxtLink(D2TxtLinkStrc* pLinker, const char* szText)
{
    D2_ASSERT(pLinker, 0x4CC);
    D2_ASSERT(!pLinker->pTbl, 0x4D0);

    const int nRow = FOG_GetLinkIndex(pLinker, szText, 0);
    if (nRow >= 0)
    {
        return nRow;
    }

    D2TxtLinkNodeStrc* pNode = (D2TxtLinkNodeStrc*)FOG_AllocPool(0, sizeof(D2TxtLinkNodeStrc), gszExcelCppFile, 0x4D9, 0);
    memset(pNode, 0, sizeof(D2TxtLinkNodeStrc));
    SStrCopy(pNode->szText, szText, sizeof(pNode->szText));
    sub_004113C0(pNode->szText, sizeof(pNode->szText));
    pNode->nLinkIndex = pLinker->count;
    sub_006BD490_InsertNode(&pLinker->pFirstNode, pNode);
    return pLinker->count++;
}

// 0x006BD640
D2BinFileStrc* __stdcall FOG_CreateBinFile(char* pDataBuffer, int nBufferSize)
{
    char* pCur = pDataBuffer;
    char* pEnd = pCur + nBufferSize;
    D2BinFileStrc* pBinFile = (D2BinFileStrc*)FOG_AllocPool(0, sizeof(D2BinFileStrc), gszExcelCppFile, 0x4D, 0);
    pBinFile->pDataBuffer = pCur;
    pBinFile->pFirstRow = 0;
    pBinFile->nRecordCount = 0;
    pBinFile->nColumns = 0;

    while (pCur < pEnd)
    {
        const char c = *pCur++;
        if (c == '\t')
        {
            pCur[-1] = 0;
            ++pBinFile->nColumns;
        }
        else if (c == '\r')
        {
            pCur[-1] = 0;
            D2_ASSERT(*pCur == '\n', 0x5C);
            ++pBinFile->nColumns;
            ++pCur;
            break;
        }
    }

    if (pCur >= pEnd)
    {
        FOG_Free(pBinFile->pDataBuffer, gszExcelCppFile, 0x9A, 0);
        FOG_FreePool(0, pBinFile, gszExcelCppFile, 0x9B, 0);
        return 0;
    }

    D2_ASSERT(pBinFile->nColumns <= 0x118, 0x67);
    pBinFile->pFirstRow = pCur;

    while (pCur < pEnd)
    {
        pDataBuffer = pCur;
        while (pCur < pEnd)
        {
            const char c = *pCur++;
            if (c == '\t')
            {
                pCur[-1] = 0;
            }
            else if (c == '\r')
            {
                pCur[-1] = 0;
                D2_ASSERT(*pCur == '\n', 0x75);
                ++pCur;
                ++pBinFile->nRecordCount;
                break;
            }
        }

        if (!SStrCmp(pDataBuffer, "Expansion", 10))
        {
            --pBinFile->nRecordCount;
            SMemCopy(pDataBuffer, pCur, pEnd - pCur);
            char* pNew = pDataBuffer;
            pEnd += pNew - pCur;
            pCur = pNew;
        }
    }

    return pBinFile;
}
