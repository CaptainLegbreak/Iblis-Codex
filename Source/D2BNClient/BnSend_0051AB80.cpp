#include "D2BNClient.h"

extern void* gpReplyBuffer_008818CC; // 0x008818CC

// 0x0051AB80
void __cdecl sub_0051AB80_FreeReplyBuffer()
{
    if (gpReplyBuffer_008818CC)
    {
        FOG_Free(gpReplyBuffer_008818CC, ".\\BnSend.cpp", 410, 0);
    }
    gpReplyBuffer_008818CC = 0;
}
