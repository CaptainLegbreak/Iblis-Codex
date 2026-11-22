#include "D2BNClient.h"

#include "D2BnCryptTypes.h"

int __cdecl sub_0051AF20_SendPacket10(); // 0x0051AF20

// 0x0051C460
int __cdecl sub_0051C460_LeaveChat()
{
    sub_0051AF20_SendPacket10();
    return 1;
}
