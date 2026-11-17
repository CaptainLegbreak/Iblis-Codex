typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize);                            // 0x006829C0
extern "C" void* __cdecl memmove(void* pDest, const void* pSource, size_t nSize);                           // 0x00683840
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                              // 0x006CC260

static const unsigned int MAX_MSG_SIZE = 516;

struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

extern D2PacketBufferStrc* gpPacketBuffer;                                                                  // 0x00882B34
extern D2NetPacketRecStrc* gpGamePacketList;                                                                      // 0x00882CE4
extern D2NetPacketRecStrc* gpSystemPacketList;                                                                    // 0x00882CDC

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __fastcall FOG_10219(unsigned char* pData);                                                            // 0x0040ADB0
int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052B920

// 0x0052A8D0
int __stdcall sub_0052A8D0()
{
    int nUsedBytes = gpPacketBuffer->nUsedBytes;
    D2PacketBufferStrc* pPacketBuffer = gpPacketBuffer;
    int bResult = 0;

    if (nUsedBytes >= 1u)
    {
    do
    {
        int nSize;
        if (!SERVER_GetServerPacketSize(pPacketBuffer, nUsedBytes, &nSize))
        {
            break;
        }

        D2_ASSERT(nSize <= MAX_MSG_SIZE, 0x129);

        if (nSize > nUsedBytes)
        {
            break;
        }

        D2NetPacketRecStrc* pPacket = (D2NetPacketRecStrc*)FOG_Alloc(sizeof(D2NetPacketRecStrc), ".\\SRC\\Client.cpp", 0x12C, 0);
        pPacket->nPacketSize = nSize;
        pPacket->dwTickCount = 0;
        pPacket->pNext = 0;

        memcpy(pPacket->data, pPacketBuffer->data, nSize);

        if (pPacketBuffer->data[0] == 0xAF && pPacketBuffer->data[1])
        {
            bResult = 1;

            if (pPacketBuffer->data[1] == 0x81)
            {
                unsigned char abProcessed[0x100];

                const unsigned char* pSource = &pPacketBuffer->data[1];
                unsigned char* pDest = &abProcessed[1];
                int nCount = 0x80;
                do
                {
                    const unsigned char nElement = *pSource;
                    pDest[-1] = (nElement & 0xF) + 1;
                    pDest[0] = (nElement >> 4) + 1;
                    ++pSource;
                    pDest += 2;
                } while (--nCount);

                FOG_10219(abProcessed);
            }
        }
        else if (pPacketBuffer->data[0] == 0x8F)
        {
            *(unsigned long*)&pPacket->data[13] = GetTickCount();
        }

        D2NetPacketRecStrc** ppLast;
        if (pPacketBuffer->data[0] < 0xAF)
        {
            ppLast = &gpGamePacketList;
        }
        else
        {
            ppLast = &gpSystemPacketList;
        }

        while (*ppLast)
        {
            ppLast = &(*ppLast)->pNext;
        }
        *ppLast = pPacket;

        pPacketBuffer = (D2PacketBufferStrc*)((char*)pPacketBuffer + nSize);
        nUsedBytes -= nSize;
    } while (nUsedBytes >= 1u);
    }

    D2PacketBufferStrc* pEnd = gpPacketBuffer;
    pEnd->nUsedBytes = nUsedBytes;

    if (nUsedBytes && pPacketBuffer != pEnd)
    {
        memmove(pEnd, pPacketBuffer, nUsedBytes);
    }

    return bResult;
}
