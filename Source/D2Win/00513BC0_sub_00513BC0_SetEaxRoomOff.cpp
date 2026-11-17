struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct D2KsPropertySetStrc;

struct D2KsPropertySetVtblStrc
{
    void* unk0x00[4];
    long (__stdcall* Set)(D2KsPropertySetStrc* pThis, const D2GuidStrc& rguidPropSet, unsigned long dwPropID, void* pInstanceData, unsigned long cbInstanceData, void* pPropData, unsigned long cbPropData);
};

struct D2KsPropertySetStrc
{
    D2KsPropertySetVtblStrc* lpVtbl;
};

extern D2KsPropertySetStrc* gpEaxListenerPropertySet_008816D8;                                              // 0x008816D8
extern const D2GuidStrc gEax10PropertySet_006DE480;                                                         // 0x006DE480
extern const D2GuidStrc gEaxListener20PropertySet_006DE460;                                                 // 0x006DE460
int gbEaxRoomOff_00881778;                                                                                  // 0x00881778

// 0x00513BC0
int __fastcall sub_00513BC0_SetEaxRoomOff(int nEaxVersion)
{
    if (!gpEaxListenerPropertySet_008816D8)
    {
        return 0;
    }

    if (nEaxVersion == 1)
    {
        float fVolume = 0.0f;
        if (gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEax10PropertySet_006DE480, 2, 0, 0, &fVolume, 4) < 0)
        {
            return 0;
        }
    }
    else
    {
        int nRoom = -10000;
        if (gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 2, 0, 0, &nRoom, 4) < 0)
        {
            return 0;
        }
        if (gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 3, 0, 0, &nRoom, 4) < 0)
        {
            return 0;
        }
    }

    gbEaxRoomOff_00881778 = 1;
    return 1;
}
