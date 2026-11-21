#include "D2Net.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall CLIENT_ReadPacketFromBuffer(void* pBuffer, int nBufferSize);                                // 0x0052AEB0
void __fastcall FOG_10222(const unsigned char* pData, unsigned int nSize);                                  // 0x0040B130
int __fastcall sub_0040B1B0(unsigned char* pOut, int nCapacity, const unsigned char* pIn, int nSize);       // 0x0040B1B0
int __stdcall sub_006C03A0_SendToKey(void* pServer, unsigned int nKey, const void* pData, unsigned int nSize); // 0x006C03A0

extern void* gpServer_00882D08;                                                                             // 0x00882D08

// 0x0052B330
unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize)
{
    const unsigned char* pPacket = (const unsigned char*)pPacketArg;

    D2_ASSERT(nPacketSize <= 516, 344);

    if (NET_IsLocalConnection())
    {
        CLIENT_ReadPacketFromBuffer((void*)pPacket, nPacketSize);
        return nPacketSize;
    }

    if (nSendMode != 0 || *pPacket != 0xAF)
    {
        FOG_10222(pPacket, nPacketSize);
        if (nSendMode != 2)
        {
            unsigned char frame[1036];
            unsigned int nFrameSize = sub_0040B1B0(&frame[2], 1032, pPacket, nPacketSize);
            D2_ASSERT(nFrameSize, 376);

            if (++nFrameSize < 0xF0)
            {
                frame[1] = (unsigned char)nFrameSize;
                return sub_006C03A0_SendToKey(gpServer_00882D08, (unsigned int)pClientId, &frame[1], nFrameSize) != 0 ? nFrameSize : 0;
            }

            ++nFrameSize;
            frame[0] = (unsigned char)((nFrameSize >> 8) | 0xF0);
            frame[1] = (unsigned char)nFrameSize;
            return sub_006C03A0_SendToKey(gpServer_00882D08, (unsigned int)pClientId, frame, nFrameSize) != 0 ? nFrameSize : 0;
        }
    }

    return sub_006C03A0_SendToKey(gpServer_00882D08, (unsigned int)pClientId, pPacket, nPacketSize) != 0 ? nPacketSize : 0;
}
