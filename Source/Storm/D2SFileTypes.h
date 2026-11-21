#pragma once
// Storm SFILE: archive, file, block, stream and request records shared by the SFILE pieces.

#include "D2StormLink.h"
#include "D2Win32Base.h"

struct D2StormMpqHeaderStrc;
struct D2StormHashEntryStrc;
struct D2StormFileSubStrc;
struct D2StormArchiveFileStrc;
struct D2StormRequestCallbackStrc;
struct D2StormArchiveRecStrc;
struct D2StormFileRecStrc;
struct D2StormStreamStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

// One block-table entry (0x2C bytes).
struct D2StormBlockStrc
{
    unsigned int nOffset;                       // 0x00
    unsigned int nPackedSize;                   // 0x04
    unsigned int nFileSize;                     // 0x08
    unsigned int dwFlags;                       // 0x0C
    union
    {
        struct
        {
            unsigned int unk0x10;               // 0x10
            unsigned int unk0x14;               // 0x14
        };
        D2FileTimeStrc tFileTime;
    };
    unsigned int nCrc;                          // 0x18
    unsigned int unk0x1C[4];                    // 0x1C

    void sub_004156A0_ExpandEntries(unsigned int nCount);                                                    // 0x004156A0
};

// An open archive (0x25C bytes).
struct D2StormArchiveRecStrc
{
    D2StormLinkStrc tLink;                      // 0x000
    union
    {
        char szFileName[0x108];                 // 0x008
        struct
        {
            char szName[0x104];                 // 0x008
            void* hFile;                        // 0x10C
        };
    };
    union
    {
        int nMode;                              // 0x110
        int nKind;
    };
    int bNoDiskSearch;                          // 0x114
    union
    {
        int nPriority;                          // 0x118
        int nInfo;
    };
    union
    {
        D2StormFileRecStrc* pCachedFile;        // 0x11C
        int nUnk0x11C;
    };
    unsigned int nCachedOffset;                 // 0x120
    unsigned int nBlockSize;                    // 0x124
    union
    {
        unsigned char* pBlockBuffer;            // 0x128
        void* pBuffer0x128;
    };
    unsigned int nCachedSize;                   // 0x12C
    unsigned int nArchiveOffset;                // 0x130
    unsigned int nArchiveLimit;                 // 0x134
    union
    {
        D2StormMpqHeaderStrc* pHeader;          // 0x138
        void* pBuffer0x138;
    };
    union
    {
        D2StormBlockStrc* pBlockTable;          // 0x13C
        void* pBuffer0x13C;
    };
    union
    {
        D2StormHashEntryStrc* pHashTable;       // 0x140
        void* pBuffer0x140;
    };
    unsigned int nFilePos;                      // 0x144
    union
    {
        int bNested;                            // 0x148
        int nRefCount;
        int nOpenFiles;
    };
    union
    {
        void* hNestedFile;                      // 0x14C
        void* hParentFile;
        int bNoClose;
    };
    union
    {
        D2StormArchiveRecStrc* pPatch;          // 0x150
        D2StormArchiveRecStrc* pParent;
        int bMapped;
    };
    char szPrefix[0x104];                       // 0x154
    int nRefs;                                  // 0x258

    D2StormArchiveRecStrc()
    {
        tLink.m_prevlink = 0;
        tLink.m_next = 0;
    }
    ~D2StormArchiveRecStrc();                                                                                // 0x00418A50
    void ReadAdditionalAttributes(D2StormBlockStrc* pBlockTable, unsigned int nCount);                    // 0x0041B0B0
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// An open file (0x158 bytes).
struct D2StormFileRecStrc
{
    D2StormLinkStrc tLink;                      // 0x000
    union
    {
        char szName[0x108];                     // 0x008
        struct
        {
            char name[260];                     // 0x008
            const char* fullName;               // 0x10C
        };
        struct
        {
            unsigned char unk_08[0x104];        // 0x008
            void* pBuffer0x10C;                 // 0x10C
        };
        struct
        {
            char szShortName[0x104];            // 0x008
            char* szLocalPath;                  // 0x10C
        };
    };
    union
    {
        void* hFile;                            // 0x110
        int nKind;
    };
    union
    {
        D2StormArchiveRecStrc* pArchive;        // 0x114
        int nValue;
    };
    union
    {
        D2StormBlockStrc* pBlock;               // 0x118
        D2StormFileSubStrc* f_118;
        D2StormArchiveFileStrc* pArchiveFile;
        unsigned int* pBlockWords;
    };
    unsigned int nKey;                          // 0x11C
    unsigned int nPosition;                     // 0x120
    int unk0x124;                               // 0x124
    unsigned int nBlocks;                       // 0x128
    union
    {
        unsigned int* pBlockOffsets;            // 0x12C
        void* pBuffer0x12C;
    };
    int bOffsetsLoaded;                         // 0x130
    unsigned char unk_134[0x4];                 // 0x134
    union
    {
        void* pBuffer0x138;                     // 0x138
        unsigned char* pBuffer;
    };
    int n13C;                                   // 0x13C
    int n140;                                   // 0x140
    union
    {
        int nRequests;                          // 0x144
        int nRefCount;
    };
    unsigned int nCrc;                          // 0x148
    union
    {
        int bCrc;                               // 0x14C
        unsigned int nCrcValue;
    };
    int nCrcState;                              // 0x150
    unsigned int nCrcPos;                       // 0x154

    D2StormFileRecStrc();                                                                                   // 0x00418E60
    ~D2StormFileRecStrc();                                                                                  // 0x00419070
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// The DirectSound buffer interface the stream player writes through.
struct D2StormSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pnPlay, unsigned long* pnWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long nSize, unsigned long* pnWritten) = 0;
    virtual long __stdcall GetVolume(long* pnVolume) = 0;
    virtual long __stdcall GetPan(long* pnPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pnFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pnStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long nOffset, unsigned long nBytes, void** ppPtr1, unsigned long* pnBytes1, void** ppPtr2, unsigned long* pnBytes2, unsigned long nFlags) = 0;
    virtual long __stdcall Play(unsigned long nReserved, unsigned long nPriority, unsigned long nFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long nPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long nVolume) = 0;
    virtual long __stdcall SetPan(long nPan) = 0;
    virtual long __stdcall SetFrequency(unsigned long nFrequency) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Unlock(void* pPtr1, unsigned long nBytes1, void* pPtr2, unsigned long nBytes2) = 0;
};

// A streamed sound (0x50 bytes).
struct D2StormStreamStrc
{
    D2StormLinkStrc tLink;                      // 0x00
    D2StormFileRecStrc* pFile;                  // 0x08
    unsigned int nWritePos;                     // 0x0C
    int unk0x10;                                // 0x10
    int bRestart;                               // 0x14
    int nState;                                 // 0x18
    unsigned int nCounter;                      // 0x1C
    unsigned int nStart;                        // 0x20
    unsigned int nSize;                         // 0x24
    unsigned int nOffset;                       // 0x28
    unsigned int nPlayed;                       // 0x2C
    unsigned int nWritten;                      // 0x30
    int nVolume;                                // 0x34
    int nPan;                                   // 0x38
    D2StormSoundBufferStrc* pBuffer;            // 0x3C
    unsigned int nBufferSize;                   // 0x40
    int unk0x44;                                // 0x44
    unsigned char nFill;                        // 0x48
    char pad0x49[3];                            // 0x49
    int nRefs;                                  // 0x4C
};

// A pending read request (0x44 bytes).
struct D2StormRequestStrc
{
    D2StormLinkStrc tLink;                      // 0x00
    union
    {
        void* hEvent;                           // 0x08
        int nUser;
    };
    D2StormFileRecStrc* pFile;                  // 0x0C
    unsigned int nPosition;                     // 0x10
    unsigned int nFileOffset;                   // 0x14
    unsigned int nDueTime;                      // 0x18
    int nArg9;                                  // 0x1C
    unsigned char* pDest;                       // 0x20
    unsigned int nDestSize;                     // 0x24
    D2StormSoundBufferStrc* pBuffer;            // 0x28
    unsigned int nBufferOffset;                 // 0x2C
    D2StormStreamStrc* pStream;                 // 0x30
    unsigned int nBytes;                        // 0x34
    int bDelete;                                // 0x38
    unsigned int nRead;                         // 0x3C
    D2StormRequestCallbackStrc* pCallback;      // 0x40

    ~D2StormRequestStrc();                                                                                  // 0x0041A020
    D2StormRequestStrc()
    {
        tLink.m_prevlink = 0;
        tLink.m_next = 0;
    }
    static void operator delete(void* pMemory);
};

// The list of open archives.
struct D2StormArchiveListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormArchiveRecStrc* Head()
    {
        return (D2StormArchiveRecStrc*)m_terminator.Next();
    }
    void LinkBefore(D2StormArchiveRecStrc* pNode, D2StormArchiveRecStrc* pExisting)
    {
        pNode->tLink.Unlink();
        D2StormLinkStrc* pExistingLink = pExisting ? &pExisting->tLink : &m_terminator;
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pNode->tLink.m_prevlink = pPrevLink;
        pNode->tLink.m_next = pPrevLink->m_next;
        pPrevLink->m_next = (char*)pNode;
        pExistingLink->m_prevlink = &pNode->tLink;
    }
};

// A request-completion event.
struct D2StormEventStrc
{
    D2StormLinkStrc tLink;
    void* hEvent;
};

struct D2StormEventListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_00419690_DeleteNode(char* pNode);                                                             // 0x00419690
};
