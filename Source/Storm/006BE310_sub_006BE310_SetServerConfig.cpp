struct D2QServerConfigStrc
{
    int nClientCapacity;
    int nValue04;
    int nValue08;
    int nValue0C;
};

static int gnLockCount_0074C3E0; // 0x0074C3E0
static int gnGlobal_0074C3E4; // 0x0074C3E4
static int gnGlobal_0074C3E8; // 0x0074C3E8
static int gnGlobal_0074C3EC; // 0x0074C3EC
static int gnGlobal_00989C28; // 0x00989C28

// 0x006BE310
void __stdcall sub_006BE310_SetServerConfig(D2QServerConfigStrc* pConfig)
{
    gnLockCount_0074C3E0 = pConfig->nClientCapacity;
    gnGlobal_0074C3E4 = pConfig->nClientCapacity - 1;
    gnGlobal_0074C3E8 = pConfig->nValue04;
    gnGlobal_0074C3EC = pConfig->nValue08;
    gnGlobal_00989C28 = pConfig->nValue0C;
}

#include "gen/data/Source/Storm/006BE310_sub_006BE310_SetServerConfig.inc"
