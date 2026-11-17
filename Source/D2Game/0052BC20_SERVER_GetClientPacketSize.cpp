int __stdcall SStrLen(const char* szString); // 0x00413750

extern int gnClientPacketSizes_00730DC0[]; // 0x00730DC0

static inline const char* NextString(const char* szString)
{
    return szString + SStrLen(szString) + 1;
}

// 0x0052BC20
int __fastcall SERVER_GetClientPacketSize(unsigned char* pBuffer, unsigned int nBufferSize, int* pSize)
{
    if (nBufferSize < 1)
    {
        return 0;
    }

    const unsigned char nHeader = pBuffer[0];
    if (nHeader == 0xFF)
    {
        *pSize = 16;
        return 1;
    }

    if (nHeader >= 0x71)
    {
        return 0;
    }

    *pSize = gnClientPacketSizes_00730DC0[nHeader];
    if (!*pSize)
    {
        return 0;
    }

    if (*pSize < 0)
    {
        switch (nHeader)
        {
        case 0x14:
        case 0x15:
        {
            if ((int)nBufferSize < 3)
            {
                return 0;
            }

            const char* szName = (const char*)pBuffer + 3;
            int nSize = SStrLen(szName) + 4;
            if ((int)nBufferSize < nSize)
            {
                return 0;
            }

            const char* szMessage = NextString(szName);
            nSize += SStrLen(szMessage) + 1;
            if ((int)nBufferSize < nSize)
            {
                return 0;
            }

            nSize += *NextString(szMessage) + 1;
            if ((int)nBufferSize < nSize)
            {
                return 0;
            }

            *pSize = nSize;
            break;
        }
        case 0x66:
        {
            if (nBufferSize < 3)
            {
                return 0;
            }

            unsigned short nLength = *(unsigned short*)(pBuffer + 1);
            if (nLength > 0x1FD)
            {
                nLength = 0;
            }

            *pSize = nLength + 3;
            break;
        }
        case 0x6C:
            if (nBufferSize < 6)
            {
                return 0;
            }

            *pSize = pBuffer[1] + 7;
            break;

        default:
            *pSize = 0;
            break;
        }
    }

    return *pSize;
}

#include "gen/data/Source/D2Game/0052BC20_SERVER_GetClientPacketSize.inc"
