struct D2ValueRecordStrc
{
    int nValues[5];
};

extern const D2ValueRecordStrc gTable_006E8B90[];                                                       // 0x006E8B90
extern const D2ValueRecordStrc gTable_006E8CD0[];                                                       // 0x006E8CD0

// 0x00621420
static const D2ValueRecordStrc* __stdcall sub_00621420_GetRecordForValue(int nIndex, int nValue)
{
    if (nValue < 0x19A)
        return &gTable_006E8B90[nIndex];
    return &gTable_006E8CD0[nIndex];
}

// calling-convention shim (not game code)
int __stdcall sub_K14_EmitGetRecordForValue(int nIndex, int nValue)
{
    return sub_00621420_GetRecordForValue(nIndex, nValue)->nValues[0] + sub_00621420_GetRecordForValue(nIndex + 1, nValue)->nValues[1];
}

#include "gen/data/Source/D2Common/00621420_sub_00621420_GetRecordForValue.inc"
