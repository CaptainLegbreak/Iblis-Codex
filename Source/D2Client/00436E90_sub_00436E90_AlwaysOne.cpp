// 0x00436E90
int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

// 0x004C6020
int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00551FF0
int __stdcall sub_00551FF0_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00643880
int __stdcall sub_00643880_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646260
int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646270
int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

// 0x006436E0
int __fastcall sub_006436E0_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x0064B700
int __fastcall sub_0064B700_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x006436F0
int __fastcall sub_006436F0_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x0064B710
int __fastcall sub_0064B710_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x00648390
int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x004C5390
void __fastcall sub_004C5390_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

// 0x0052E0F0
bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};

// 0x00601DC0
bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}
