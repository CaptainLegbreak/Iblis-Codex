struct D2Cache006BA830Strc
{
    int unk0x00[7];
};

struct D2Object006BB3E0Strc;
struct D2Object006BADC0Strc;

void __cdecl sub_006B5B10_Shutdown(); // 0x006B5B10
void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250
void __cdecl sub_006B9B30_ReleaseObjects(); // 0x006B9B30
void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830
void __fastcall sub_006BADC0_Free(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0
void __fastcall sub_006BB3E0_Free(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0

extern int gdwGlobal_00970E8C; // 0x00970E8C
extern D2Object006BADC0Strc gObject_0096FC80; // 0x0096FC80
extern D2Object006BB3E0Strc gObject_0096FC9C; // 0x0096FC9C
extern D2Cache006BA830Strc gCache_00970EC8; // 0x00970EC8
extern D2Cache006BA830Strc gCache_00970EE4; // 0x00970EE4
extern D2Cache006BA830Strc gCache_00970F00; // 0x00970F00

// 0x006B32B0
void __cdecl sub_006B32B0_ReleaseRenderer()
{
    if (gdwGlobal_00970E8C)
    {
        sub_006B7250_ReleaseAll();
        sub_006BB3E0_Free(&gObject_0096FC9C, 1);
        sub_006BADC0_Free(&gObject_0096FC80, 1);
    }
    else
    {
        sub_006B9B30_ReleaseObjects();
    }

    sub_006BA830_FreeCache(&gCache_00970EC8, 1);
    sub_006BA830_FreeCache(&gCache_00970EE4, 1);
    sub_006BA830_FreeCache(&gCache_00970F00, 1);
    sub_006B5B10_Shutdown();
}
