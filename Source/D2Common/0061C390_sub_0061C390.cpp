struct Act;
struct Environment { char pad[0x28]; int timeFields[2]; };
Environment* __fastcall sub_0061AA60(Act*);  // 0x0061AA60
enum { TIME_RATE_FIELD = 0 };
// 0x0061C390
int __stdcall sub_0061C390(Act* act)
{
    return sub_0061AA60(act)->timeFields[TIME_RATE_FIELD];
}
