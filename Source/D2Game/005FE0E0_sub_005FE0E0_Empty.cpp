struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];

    void sub_0060B130_Destroy();                                                                            // 0x0060B130
};

struct D2CmpBlockTableBStrc
{
    unsigned char data[0x10000];

    void sub_0060AB70_Destroy();                                                                            // 0x0060AB70
};

struct D2CmpValueObjStrc
{
    char unk0x00[0x2C];
    int nValue;
};

extern D2CmpBlockTableAStrc gCmpBlockTableA;                                                                // 0x0088CB20
extern D2CmpBlockTableBStrc gCmpBlockTableB;                                                                // 0x0088DB58

// 0x005FE0E0
void __cdecl sub_005FE0E0_Empty()
{
}

// 0x005FE0F0
void __cdecl sub_005FE0F0_Empty()
{
}

// 0x005FE110
void __cdecl sub_005FE110_Empty()
{
}

// 0x005FEE00
void __cdecl sub_005FEE00_DestroyBlockTableB()
{
    gCmpBlockTableB.sub_0060AB70_Destroy();
}

// 0x005FEE50
void __cdecl sub_005FEE50_DestroyBlockTableA()
{
    gCmpBlockTableA.sub_0060B130_Destroy();
}

// 0x005FEE80
int __fastcall sub_005FEE80_IsValueSet(D2CmpValueObjStrc* pObject)
{
    return pObject->nValue != 0;
}
