struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

extern int gnServerPacketSizeTable_00730AE8[]; // 0x00730AE8
int __stdcall SStrLen(const char* szString); // 0x00413750

// 0x0052B920
int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, int nBufferSize, int* pSize)
{
    if (nBufferSize < 1u)
    {
        return 0;
    }

    const unsigned char nHeader = pBuffer->data[0];
    if (nHeader >= 0xB5u)
    {
        return 0;
    }

    *pSize = gnServerPacketSizeTable_00730AE8[nHeader];
    if (*pSize == 0)
    {
        return 0;
    }

    if (*pSize < 0)
    {
        switch (nHeader)
        {
        case 0x16:
            if (nBufferSize < 13u)
            {
                return 0;
            }
            *pSize = *(unsigned short*)&pBuffer->data[1];
            break;

        case 0x26:
        {
            if (nBufferSize < 10)
            {
                return 0;
            }

            const char* szName = (const char*)&pBuffer->data[10];
            int nPacketSize = SStrLen(szName) + 11;
            if (nBufferSize < nPacketSize)
            {
                return 0;
            }

            const char* szMessage = &szName[SStrLen(szName) + 1];
            nPacketSize += SStrLen(szMessage) + 1;
            if (nBufferSize < nPacketSize)
            {
                return 0;
            }

            *pSize = nPacketSize;
            break;
        }

        case 0x5B:
            if (nBufferSize < 34u)
            {
                return 0;
            }
            *pSize = *(unsigned short*)&pBuffer->data[1];
            break;

        case 0x94:
            if (nBufferSize < 9u)
            {
                return 0;
            }
            *pSize = 3 * (pBuffer->data[1] + 2);
            break;

        case 0x9C:
            if (nBufferSize < 3u)
            {
                return 0;
            }
            *pSize = pBuffer->data[2];
            break;

        case 0x3E:
            if (nBufferSize < 2u)
            {
                return 0;
            }
            *pSize = pBuffer->data[1];
            break;

        case 0x9D:
            if (nBufferSize < 3u)
            {
                return 0;
            }
            *pSize = pBuffer->data[2];
            break;

        case 0xA6:
            if (nBufferSize < 4u)
            {
                return 0;
            }
            *pSize = *(unsigned short*)&pBuffer->data[2];
            break;

        case 0xA8:
            if (nBufferSize < 7u)
            {
                return 0;
            }
            *pSize = pBuffer->data[6];
            break;

        case 0xAA:
            if (nBufferSize < 7u)
            {
                return 0;
            }
            *pSize = pBuffer->data[6];
            break;

        case 0xAC:
            if (nBufferSize < 13u)
            {
                return 0;
            }
            *pSize = pBuffer->data[12];
            break;

        case 0xAE:
        {
            if (nBufferSize < 3u)
            {
                return 0;
            }

            unsigned short nDataSize = *(unsigned short*)&pBuffer->data[1];
            if (nDataSize > 0x1FD)
            {
                nDataSize = 0;
            }
            *pSize = nDataSize + 3;
            break;
        }

        case 0xAF:
            if (nBufferSize < 2u)
            {
                return 0;
            }

            if (!pBuffer->data[1])
            {
                *pSize = 2;
            }
            else
            {
                *pSize = pBuffer->data[1] + 1;
            }
            break;

        case 0xB3:
            if (nBufferSize < 8u)
            {
                return 0;
            }
            *pSize = pBuffer->data[1] + 7;
            break;

        default:
            *pSize = 0;
            break;
        }
    }

    return 1;
}

#include "gen/data/Source/D2Game/0052B920_SERVER_GetServerPacketSize.inc"
