struct Data004AC780;
struct Unit004AC780;
struct Data004AC7A0;
struct Unit004AC7A0;
struct Data004AC7C0;
struct Unit004AC7C0;
struct Data004AC7E0;
struct Unit004AC7E0;
struct Data004AC840;
struct Unit004AC840;

#pragma pack(push, 1)
struct Data004AC780 { unsigned char bUnknown00[0x14]; unsigned short wValue14; };

#pragma pack(pop)
struct Unit004AC780 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC780* pData;
};

#pragma pack(push, 1)
struct Data004AC7A0 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };

#pragma pack(pop)
struct Unit004AC7A0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC7A0* pData;
};

#pragma pack(push, 1)
struct Data004AC7C0 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };

#pragma pack(pop)
struct Unit004AC7C0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data004AC7C0* pData; };

struct Data004AC7E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned short wUnknown14;
    unsigned short wFlags16;
};

struct Unit004AC7E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC7E0* pData;
};

struct Data004AC840 { unsigned char bUnknown00[0x16]; unsigned short wFlags16; };

struct Unit004AC840 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data004AC840* pData; };


// 0x004AC780
extern "C" __declspec(dllexport) void __fastcall sub_004AC780(Unit004AC780* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue14 = wValue;
    }
}

// 0x004AC7A0
extern "C" __declspec(dllexport) void __fastcall sub_004AC7A0(Unit004AC7A0* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue26 = wValue;
    }
}

// 0x004AC7C0
extern "C" __declspec(dllexport) unsigned short __fastcall sub_004AC7C0(Unit004AC7C0* pUnit) {
    Data004AC7C0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return pData->wValue26;
}

// 0x004AC7E0
extern "C" __declspec(dllexport) int __fastcall sub_004AC7E0(Unit004AC7E0* pUnit, unsigned short wMask) {
    Data004AC7E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags16 & wMask) != 0;
}

// 0x004AC840
extern "C" __declspec(dllexport) void __fastcall sub_004AC840(Unit004AC840* pUnit, int bSet) {
    if (pUnit && pUnit->nType == 1) {
        Data004AC840* pData = pUnit->pData;
        if (pData) {
            if (bSet) {
                pData->wFlags16 |= 0x100;
            } else {
                pData->wFlags16 &= ~0x100;
            }
        }
    }
}
