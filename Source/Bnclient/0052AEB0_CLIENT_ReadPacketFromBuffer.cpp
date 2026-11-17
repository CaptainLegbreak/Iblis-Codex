typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize);                            // 0x006829C0
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

D2NetPacketRecStrc* gpGamePacketList;                                                                             // 0x00882CE4
D2NetPacketRecStrc* gpSystemPacketList;                                                                           // 0x00882CDC

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052B920

// 0x0052AEB0
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize)
{
    while (nBufferSize > 0)
    {
        D2NetPacketRecStrc* pPacket = (D2NetPacketRecStrc*)FOG_Alloc(sizeof(D2NetPacketRecStrc), ".\\SRC\\Client.cpp", 0x1FD, 0);

        int nSize;
        if (!SERVER_GetServerPacketSize(pBuffer, nBufferSize, &nSize))
        {
            break;
        }

        D2_ASSERT(nSize <= MAX_MSG_SIZE, 0x203);
        D2_ASSERT(nSize > 0, 0x204);

        memcpy(pPacket->data, pBuffer->data, nSize);

        pPacket->nPacketSize = nSize;
        pPacket->dwTickCount = GetTickCount();
        pPacket->pNext = 0;

        const unsigned char nHeader = pBuffer->data[0];
        D2NetPacketRecStrc* pLast;
        if (nHeader < 0xAF)
        {
            pLast = gpGamePacketList;
        }
        else if (nHeader < 0xB5)
        {
            pLast = gpSystemPacketList;
        }
        else
        {
            D2_ASSERT(0, 0x217);
        }

        if (!pLast)
        {
            if (nHeader < 0xAF)
            {
                gpGamePacketList = pPacket;
            }
            else if (nHeader < 0xB5)
            {
                gpSystemPacketList = pPacket;
            }
            else
            {
                D2_ASSERT(0, 0x21E);
            }
        }
        else
        {
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }
            pLast->pNext = pPacket;
        }

        pBuffer = (D2PacketBufferStrc*)((char*)pBuffer + nSize);
        nBufferSize -= nSize;
    }
}
