#include "D2SoundTypes.h"

extern D2KsPropertySetStrc* gpEaxListenerPropertySet;                                              // 0x008816D8
extern const D2GuidStrc gtEaxListener10PropertySet;                                                         // 0x006DE480
extern const D2GuidStrc gtEaxListener20PropertySet;                                                 // 0x006DE460
int gbEaxRoomOff;                                                                                  // 0x00881778

// 0x00513BC0
int __fastcall sub_00513BC0_SetEaxRoomOff(int nEaxVersion)
{
    if (!gpEaxListenerPropertySet)
    {
        return 0;
    }

    if (nEaxVersion == 1)
    {
        float fVolume = 0.0f;
        if (gpEaxListenerPropertySet->Set(gtEaxListener10PropertySet, 2, 0, 0, &fVolume, 4) < 0)
        {
            return 0;
        }
    }
    else
    {
        int nRoom = -10000;
        if (gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 2, 0, 0, &nRoom, 4) < 0)
        {
            return 0;
        }
        if (gpEaxListenerPropertySet->Set(gtEaxListener20PropertySet, 3, 0, 0, &nRoom, 4) < 0)
        {
            return 0;
        }
    }

    gbEaxRoomOff = 1;
    return 1;
}
