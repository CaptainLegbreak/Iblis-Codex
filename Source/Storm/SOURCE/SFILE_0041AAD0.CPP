#include "D2SysTypes.h"
#include "SValidate.h"
struct FILEREC;
struct D2StormBlockStrc { unsigned int nOffset,nPackedSize,nFileSize,dwFlags,unk10,unk14,nCrc; };
struct ARCHIVEREC { char pad00[0x110];int nMode;char pad114[8];FILEREC* pCachedFile;unsigned int nCachedOffset,sectorsize;unsigned char* pBlockBuffer;unsigned int f_12C; };
struct FILEREC { char pad00[8];char szName[0x108];void* hFile;ARCHIVEREC* archive;D2StormBlockStrc* pBlock;unsigned int nKey,nPosition;char pad124[0x14];unsigned char* pCache;unsigned int cachePos,cacheSize;int nRequests;unsigned int nCrc;int bCrc,nCrcState;unsigned int nCrcPos; };
struct D2StormOverlappedStrc { unsigned int internal,internalHigh,offset,offsetHigh;void* event; };
struct D2StormSoundBufferStrc;
struct AUDIOSTREAM { char pad00[0x4C];int nRefs; };
struct REQUEST;
struct D2StormRequestLinkStrc {
 D2StormRequestLinkStrc* m_prevlink;char* m_next;
 D2StormRequestLinkStrc* NextLink(int offset){if((int)m_next<0)return (D2StormRequestLinkStrc*)~(unsigned int)m_next;if(offset<0)offset=(char*)this-m_prevlink->m_next;return (D2StormRequestLinkStrc*)(m_next+offset);}
 void Unlink(){if(m_prevlink){NextLink(-1)->m_prevlink=m_prevlink;m_prevlink->m_next=m_next;m_prevlink=0;m_next=0;}}
};
struct REQUEST {
 D2StormRequestLinkStrc f_0;int nUser;FILEREC* pFile;unsigned int location,nFileOffset,nDueTime;int nArg9;void* pDest;unsigned int f_24;D2StormSoundBufferStrc* pBuffer;unsigned int soundbufferoffset;AUDIOSTREAM* stream;unsigned int nBytes;int nArg11;unsigned int nRead;void* pCallback;
 REQUEST(){f_0.m_prevlink=0;f_0.m_next=0;}
 ~REQUEST(); // 0x0041A020
};
void* __stdcall SMemAlloc(unsigned int,const char*,int,unsigned int); // 0x00413020
int __stdcall SMemFree(void*,const char*,int,unsigned int); // 0x00412650
void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
int __stdcall SErrDisplayError(unsigned int nErrorCode,const char* szFile,int nLine,const char* szDescription,int bRecoverable,unsigned int nExitCode); // 0x0041CAF0
void __fastcall CrcBuffer(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810
unsigned int __stdcall InternalReadAligned(FILEREC*,unsigned int,unsigned char*,unsigned int); // 0x00416AD0
void __cdecl sub_0041A880_StartThread(); // 0x0041A880
extern const char gszDelete_006CC824[]; // 0x006CC824
extern const char gszTypeNameRequest_007083F0[]; // 0x007083F0
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern void* ghStormEvent_00779054; // 0x00779054
extern unsigned int gnReadUnit_00708348; // 0x00708348
extern int gnValueA_0070834C; // 0x0070834C
typedef int (__stdcall *ReadErrorCallback)(const char*,unsigned long,int);
extern ReadErrorCallback gpfnReadErrorCallback_00779030; // 0x00779030
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*); // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*); // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*,int,int,const char*); // 0x006CC228
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*,unsigned long); // 0x006CC230
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void*,long,long*,unsigned long); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void*,void*,unsigned long,unsigned long*,void*); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
inline void* operator new(unsigned int,void* where) throw(){return where;}
struct D2StormRequestListStrc {
 int m_linkoffset;D2StormRequestLinkStrc m_terminator;
 D2StormRequestLinkStrc* Link(char* node){return node?(D2StormRequestLinkStrc*)node:&m_terminator;}
 // build: context D2StormRequestListStrc::LinkNode
 void LinkNode(char* node,unsigned int type,char* existing){D2StormRequestLinkStrc* link=Link(node);link->Unlink();D2StormRequestLinkStrc* ex=Link(existing);switch(type){case 1:link->m_prevlink=ex;link->m_next=ex->m_next;ex->NextLink(m_linkoffset)->m_prevlink=link;ex->m_next=node;break;default:D2StormRequestLinkStrc* prev=ex->m_prevlink;link->m_prevlink=prev;link->m_next=prev->m_next;prev->m_next=node;ex->m_prevlink=link;break;}}
 REQUEST* NewNode(unsigned int type,unsigned int extra,unsigned int flags){void* mem=SMemAlloc(sizeof(REQUEST)+extra,gszTypeNameRequest_007083F0,-2,flags|8);REQUEST* rec=mem?new(mem)REQUEST:0;if(type)LinkNode((char*)rec,type,0);return rec;}
};
extern D2StormRequestListStrc gRequestList_00708360; // 0x00708360
static int sub_00415950_GetFileRec(void*,FILEREC**);
static int sub_00415950_GetFileRec(void*,FILEREC**); // 0x00415950
// 0x00415950
static int sub_00415950_GetFileRec(void* hFile,FILEREC** out){*out=(FILEREC*)hFile;return 1;}
// 0x004154B0
static int __stdcall ReadFileChecked(unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, unsigned long* pnRead, unsigned int nOffset, void* hFile)
{
    int nRetry = 0;
    for (;;)
    {
        if (nOffset != -1)
            SetFilePointer(hFile, nOffset, 0, 0);
        const int bRead = ReadFile(hFile, pBuffer, nSize, pnRead, 0);
        *pnFilePos = *pnRead + nOffset;
        if (bRead)
        {
            if (*pnRead == nSize)
                return 1;
            sub_0041C340_SetLastError(0x26);
            return 0;
        }
        const unsigned long dwError = GetLastError();
        switch (gnValueA_0070834C)
        {
        case 0:
            return 0;
        case 1:
            if (!gpfnReadErrorCallback_00779030)
                return 0;
            if (!gpfnReadErrorCallback_00779030(szName, dwError, nRetry++))
                return 0;
            break;
        case 2:
            SErrDisplayError(dwError, szName, -4, 0, 0, 1);
            break;
        }
    }
}
static int __stdcall ReadFileChecked(unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, unsigned long* pnRead, unsigned int nOffset, void* hFile); // 0x004154B0
static int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, FILEREC* pFile, unsigned int nOffset);
// 0x00415560
static int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, FILEREC* pFile, unsigned int nOffset)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    ReadFileChecked(&nFilePos, pBuffer, nSize, pFile->szName, &nRead, nOffset, pFile->hFile);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
}
static int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, FILEREC* pFile, unsigned int nOffset); // 0x00415560
// 0x00416FB0
static unsigned int sub_00416FB0_LoadBlock(unsigned int nOffset, FILEREC* pFile)
{
    if (pFile->archive->pCachedFile == pFile && pFile->archive->nCachedOffset == nOffset)
        return pFile->archive->f_12C;
    unsigned int nSize = pFile->archive->sectorsize;
    D2StormBlockStrc* pBlock = pFile->pBlock;
    if (nOffset + nSize > pBlock->nFileSize && !(pBlock->dwFlags & 0xFF00))
        nSize = pBlock->nFileSize - nOffset;
    pFile->archive->pCachedFile = pFile;
    pFile->archive->nCachedOffset = nOffset;
    pFile->archive->f_12C = InternalReadAligned(pFile, nOffset, pFile->archive->pBlockBuffer, nSize);
    return pFile->archive->f_12C;
}
static unsigned int sub_00416FB0_LoadBlock(unsigned int nOffset, FILEREC* pFile); // 0x00416FB0
static unsigned int __stdcall InternalReadUnaligned(unsigned char* pBuffer, unsigned int nSize, FILEREC* pFile, unsigned int nPosition); // 0x00417040
// 0x00417040

static unsigned int __stdcall InternalReadUnaligned(unsigned char* pBuffer, unsigned int nSize, FILEREC* pFile, unsigned int nPosition)
{
    const unsigned int nFileSize = pFile->pBlock->nFileSize;
    if (nFileSize <= nPosition)
        return 0;
    nSize = nSize < nFileSize - nPosition ? nSize : nFileSize - nPosition;
    if (pFile->bCrc && !nPosition)
    {
        CrcBuffer(0, 0, &pFile->nCrc, 1);
        pFile->nCrcPos = 0;
        pFile->nCrcState = 2;
    }
    unsigned int nHead = 0;
    if (nPosition & (pFile->archive->sectorsize - 1))
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nHead = sub_00416FB0_LoadBlock(~(pFile->archive->sectorsize - 1) & nPosition, pFile);
        const unsigned int nCopy = nSize < pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition) ? nSize : pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition);
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer + ((pFile->archive->sectorsize - 1) & nPosition), nCopy);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nCopy, &pFile->nCrc, 2);
            pFile->nCrcPos += nCopy;
        }
        pBuffer += nCopy;
        nSize -= nCopy;
        if (nHead != pFile->archive->sectorsize || !nSize)
        {
            const unsigned int nSkip = (pFile->archive->sectorsize - 1) & nPosition;
            if (nHead < nSkip)
                return 0;
            return nCopy < nHead - nSkip ? nCopy : nHead - nSkip;
        }
        nHead = nCopy;
        nPosition += nCopy;
    }
    unsigned int nMiddle = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        const unsigned int nAligned = ~(pFile->archive->sectorsize - 1) & nSize;
        nMiddle = InternalReadAligned(pFile, nPosition, pBuffer, nAligned);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nMiddle, &pFile->nCrc, 2);
            pFile->nCrcPos += nMiddle;
        }
        pBuffer += nAligned;
        nSize -= nAligned;
        nPosition += nAligned;
        if (nAligned != nMiddle || !nSize)
            return nMiddle + nHead;
    }
    unsigned int nTail = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nTail = sub_00416FB0_LoadBlock(nPosition, pFile);
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer, nSize);
        if (nSize < nTail)
            nTail = nSize;
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            CrcBuffer(pBuffer, nTail, &pFile->nCrc, 2);
            pFile->nCrcPos += nTail;
        }
    }
    return nMiddle + nTail + nHead;
}
// 0x00419790
static REQUEST* __stdcall IssueRequest(FILEREC* pFile, unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, AUDIOSTREAM* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int nArg11, int bSignal, void* pCallback)
{
    VALIDATEBEGIN;
    VALIDATE(pDest || pBuffer);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    REQUEST* pRequest = gRequestList_00708360.NewNode(2, 0, 0);
    pRequest->nUser = nUser;
    pRequest->pFile = pFile;
    pRequest->location = nPosition;
    if (pFile->hFile == (void*)-1)
        nPosition = (nPosition >> 1) + pFile->pBlock->nOffset;
    pRequest->nFileOffset = nPosition;
    pRequest->nDueTime = GetTickCount() + nDelay;
    pRequest->nArg9 = nArg9;
    pRequest->pDest = pDest;
    pRequest->f_24 = nDestSize;
    pRequest->pBuffer = pBuffer;
    pRequest->soundbufferoffset = nBufferOffset;
    pRequest->stream = pStream;
    pRequest->nBytes = nBytes;
    pRequest->nArg11 = nArg11;
    pRequest->pCallback = pCallback;
    pFile->nRequests += 1;
    if (pStream)
        pStream->nRefs += 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    if (bSignal)
        SetEvent(ghStormEvent_00779054);
    return pRequest;
}
static REQUEST* __stdcall IssueRequest(FILEREC* pFile, unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, AUDIOSTREAM* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int nArg11, int bSignal, void* pCallback); // 0x00419790
#define min(a,b) (((a) < (b)) ? (a) : (b))
// 0x0041AAD0
int __stdcall SFileReadFileEx2(void* hFile,unsigned char* buffer,unsigned int size,unsigned int* read,D2StormOverlappedStrc* overlap,int unused,void* callback)
{
    if (read)
        *read = 0;
    VALIDATEBEGIN;
    VALIDATE(buffer);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* file;
    if (!sub_00415950_GetFileRec(hFile, &file))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (!size)
    {
        if (overlap && overlap->event)
            SetEvent(overlap->event);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    if (file->hFile != (void*)-1 && !overlap)
    {
        int result = sub_00415560_ReadFileRec(buffer, size, read, file, -1);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return result;
    }
    if (file->pCache && file->cachePos < file->cacheSize && !overlap)
    {
        unsigned int n = (size < (file->cacheSize - file->cachePos)) ? size : file->cacheSize - file->cachePos;
        SMemCopy(buffer, file->pCache + file->cachePos, n);
        file->nPosition += n;
        file->cachePos += n;
        buffer += n;
        size -= n;
        if (read)
            *read = n;
        if (!size)
        {
            if (file->bCrc && file->nCrcState == 4 && file->nCrc != file->pBlock->nCrc)
                SErrDisplayError(0x85100083, file->szName, -4, 0, 0, 1);
            LeaveCriticalSection(&gBasePathLock_00779068);
            return 1;
        }
    }
    unsigned char* dest = buffer;
    unsigned int count = size;
    if (!overlap)
    {
        unsigned int limit = min(0x1000, file->archive->sectorsize - (file->nPosition & (file->archive->sectorsize - 1)));
        if (size < limit)
        {
            dest = file->pCache;
            count = limit;
        }
    }
    if (!count)
    {
        if (overlap && overlap->event)
            SetEvent(overlap->event);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    unsigned int pos = overlap ? overlap->offset : file->nPosition;
    unsigned int total = 0;
    unsigned int chunk = gnReadUnit_00708348;
    if (file->hFile == (void*)-1 && !file->archive->nMode)
    {
        total = InternalReadUnaligned(dest, count, file, pos);
        if (file->bCrc && file->nCrcState == 2 && file->nCrcPos == file->pBlock->nFileSize)
        {
            CrcBuffer(0, 0, &file->nCrc, 4);
            file->nCrcState = 4;
        }
        if (overlap && overlap->event)
            SetEvent(overlap->event);
    }
    else
    {
        sub_0041A880_StartThread();
        REQUEST* request = 0;
        void* event = overlap ? overlap->event : CreateEventA(0, 1, 0, 0);
        unsigned int parts = (count + chunk - 1) / chunk;
        for (unsigned int i = 0; i < parts; ++i)
        {
            int last = i == parts - 1;
            unsigned int offset = i * chunk;
            unsigned int n = min(chunk, count - offset);
            request = IssueRequest(file, pos + i * chunk, dest + offset, (unsigned int)dest, 0, 0, 0, n, 0x7FFFFFFF, !overlap, (int)(last ? event : 0), (overlap || !last) ? 1 : 0, last, last ? callback : 0);
            if (!last)
                total += n;
        }
        LeaveCriticalSection(&gBasePathLock_00779068);
        if (overlap)
            return 1;
        WaitForSingleObject(event, -1);
        EnterCriticalSection(&gBasePathLock_00779068);
        CloseHandle(event);
        total += request->nRead;
        request->~REQUEST();
        SMemFree(request, gszDelete_006CC824, -1, 0);
    }
    unsigned int n = min(size, total);
    if (dest != buffer)
    {
        SMemCopy(buffer, dest, n);
        file->cachePos = n;
        file->cacheSize = total;
    }
    if (!overlap)
        file->nPosition += n;
    if (read)
        *read += n;
    if (n == size)
    {
        if (file->bCrc && file->nCrcState == 4 && file->nCrc != file->pBlock->nCrc)
            SErrDisplayError(0x85100083, file->szName, -4, 0, 0, 1);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return nValid ? 1 : 0;
    }
    sub_0041C340_SetLastError(0x26);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 0;
}
