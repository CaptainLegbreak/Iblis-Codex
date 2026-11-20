#include "SRP.h"

#define rol(value, bits) _rotl(value, bits)
#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00)|(rol(block->l[i],8)&0x00FF00FF))
#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15]^block->l[(i+2)&15]^block->l[i&15],1))
#define blkF(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block2->l[(i+8)&15]^block2->l[(i+2)&15]^block->l[i&15],1))
#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R4F(v,w,x,y,z,i) z+=(w^x^y)+blkF(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);
#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);
#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);

struct Obj005284F0;
struct D2BigPowModStrc;
struct D2BigPairStrc;
struct D2BigServerRecordStrc;
struct D2BigServerHandlesStrc;
struct T0041D340;
struct Context00529F50;
struct D2SrpSha1ContextStrc;

struct Obj005284F0 { unsigned int dwValue00; };

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2BigPowModStrc
{
    int bValid;
    void* hBase;
    void* hModulus;
    unsigned char abRandomState[0x3C];
    unsigned int nRandomBytesLeft;
    void sub_00527DD0_InitRandom(unsigned int nSeed);                                                       // 0x00527DD0
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
    void sub_00528480_HashThreeBlocks(const unsigned char* pFirst, const unsigned char* pSecond, const unsigned char* pThird, unsigned char* pDigest); // 0x00528480
    void sub_00528030_HashToUInt(void* const& hBig, unsigned int* pValue);                                  // 0x00528030
    int sub_005281D0_ComputeServerKey(void* const& hClientPublic, void* const& hServerPublic, void* const& hSecret, void* const& hVerifier, void* const& hKey);
    void sub_005282A0_ComputeProof(const char* szName, const unsigned char* pSalt, const unsigned char* pClientPublic, const unsigned char* pServerPublic, const unsigned char* pKey, unsigned char* pProof); // 0x005282A0
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;
    void sub_00528620_InitRandom(unsigned int nSeed);
    ~D2BigPairStrc();
    void sub_00528630_Release();
    void sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize);                              // 0x00527E70
    void sub_005289F0_ComputeServerPublic(D2BigServerRecordStrc* pRecord);
    void sub_00528C60_ComputeServerProof(D2BigServerRecordStrc* pRecord);
    int sub_00528AC0_VerifyClientProof(D2BigServerRecordStrc* pRecord, const unsigned char* pClientProof);
};

struct D2BigServerRecordStrc
{
    unsigned char abSalt[0x20];
    unsigned char abVerifier[0x20];
    char szName[0x20];
    unsigned char abClientPublic[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abServerPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abClientProof[0x14];
    unsigned char abServerProof[0x14];
};
int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight); // 0x0052A350
int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight); // 0x0052A3B0
extern "C" int __cdecl memcmp(const void* pBuffer1, const void* pBuffer2, unsigned int nSize);
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48

struct D2BigServerHandlesStrc
{
    void* hClientPublic;
    void* hVerifier;
    void* hServerPublic;
    void* hPrivate;
};

unsigned char* __fastcall sub_0052A120_ShaInterleave(unsigned char* pDest, const unsigned char* pData, unsigned int nSize); // 0x0052A120

struct T0041D340
{
    unsigned long state[5];
    unsigned int count[2];
    unsigned char buffer[64];
};
extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);

struct Context00529F50 {
    unsigned int dwH0;
    unsigned int dwH1;
    unsigned int dwH2;
    unsigned int dwH3;
    unsigned int dwH4;
    unsigned int dwCountLow;
    unsigned int dwCountHigh;
};

struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char f_1C[64];
};

extern "C" const unsigned char gabSha1Pad80_006E03F0[]; // 0x006E03F0
extern "C" const unsigned char gabSha1Pad00_006DEF80[]; // 0x006DEF80
void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80

// 0x005284F0
extern "C" __declspec(dllexport) int __fastcall sub_005284F0(Obj005284F0* pObj) {
    return pObj->dwValue00 != 0;
}

// 0x00528620
void D2BigPairStrc::sub_00528620_InitRandom(unsigned int nSeed)
{
    pState->sub_00527DD0_InitRandom(nSeed);
}

// 0x00528530
D2BigPairStrc::~D2BigPairStrc()
{
    if (pState)
    {
        delete pState;
    }
}

// 0x00528630
void D2BigPairStrc::sub_00528630_Release()
{
    if (pState->bValid)
    {
        sub_0052A600(pState->hModulus);
        sub_0052A600(pState->hBase);
    }
    pState->bValid = 0;
}

// 0x005289F0
void D2BigPairStrc::sub_005289F0_ComputeServerPublic(D2BigServerRecordStrc* pRecord)
{
    void* hVerifier = sub_0052A270_BigFromBinary(pRecord->abVerifier, 0x20);
    sub_00527E70_RandomBytes(pRecord->abPrivate, 0x20);
    void* hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    void* hPublic = sub_0052A240_BigFromUnsigned(0);
    sub_0052A590_BigOp_425330(hPublic, pState->hBase, hPrivate, pState->hModulus);
    sub_0052A350_BigOp_423790(hPublic, hPublic, hVerifier);
    while (sub_0052A2E0_BigCompare(hPublic, pState->hModulus) > 0)
        sub_0052A3B0_BigOp_423AC0(hPublic, hPublic, pState->hModulus);
    sub_0052A600(hPrivate);
    sub_0052A600(hVerifier);
    sub_0052A2A0_BigToBinary(hPublic, pRecord->abServerPublic, 0x20);
    sub_0052A600(hPublic);
}

// 0x00528C60
void D2BigPairStrc::sub_00528C60_ComputeServerProof(D2BigServerRecordStrc* pRecord)
{
    pState->sub_00528480_HashThreeBlocks(pRecord->abClientPublic, pRecord->abClientProof, pRecord->abKey, pRecord->abServerProof);
}

// 0x005281D0
int D2BigPowModStrc::sub_005281D0_ComputeServerKey(void* const& hClientPublic, void* const& hServerPublic, void* const& hSecret, void* const& hVerifier, void* const& hKey)
{
    unsigned int nHash;
    sub_00528030_HashToUInt(hServerPublic, &nHash);
    const unsigned int nScrambler = nHash;
    if (!nScrambler)
        return 0;
    void* hTemp = sub_0052A240_BigFromUnsigned(0);
    sub_0052A5B0_BigOpUnsigned_425330(hTemp, hVerifier, nScrambler, hModulus);
    sub_0052A560_BigOpPair_424F10_424ED0(hTemp, hClientPublic, hTemp, hModulus);
    if (sub_0052A2F0_BigCompareUnsigned(hTemp, 1) <= 0)
    {
        sub_0052A600(hTemp);
        return 0;
    }
    void* hCheck = sub_0052A240_BigFromUnsigned(0);
    sub_0052A370_BigOpUnsigned_423790(hCheck, hTemp, 1);
    if (!sub_0052A2E0_BigCompare(hCheck, hModulus))
    {
        sub_0052A600(hCheck);
        sub_0052A600(hTemp);
        return 0;
    }
    sub_0052A600(hCheck);
    sub_0052A590_BigOp_425330(hKey, hTemp, hSecret, hModulus);
    sub_0052A600(hTemp);
    return 1;
}

// 0x00528AC0
int D2BigPairStrc::sub_00528AC0_VerifyClientProof(D2BigServerRecordStrc* pRecord, const unsigned char* pClientProof)
{
    unsigned char abKey[0x20];
    void* hKey = sub_0052A240_BigFromUnsigned(0);
    D2BigServerHandlesStrc tHandles;
    tHandles.hVerifier = sub_0052A270_BigFromBinary(pRecord->abVerifier, 0x20);
    tHandles.hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    tHandles.hServerPublic = sub_0052A270_BigFromBinary(pRecord->abServerPublic, 0x20);
    tHandles.hClientPublic = sub_0052A270_BigFromBinary(pRecord->abClientPublic, 0x20);
    pState->sub_005281D0_ComputeServerKey(tHandles.hClientPublic, tHandles.hServerPublic, tHandles.hPrivate, tHandles.hVerifier, hKey);
    sub_0052A600(tHandles.hClientPublic);
    sub_0052A600(tHandles.hServerPublic);
    sub_0052A600(tHandles.hPrivate);
    sub_0052A600(tHandles.hVerifier);
    const unsigned int nSize = sub_0052A2A0_BigToBinary(hKey, abKey, 0x20);
    sub_0052A600(hKey);
    sub_0052A120_ShaInterleave(pRecord->abKey, abKey, nSize);
    pState->sub_005282A0_ComputeProof(pRecord->szName, pRecord->abSalt, pRecord->abClientPublic, pRecord->abServerPublic, pRecord->abKey, pRecord->abClientProof);
    return memcmp(pRecord->abClientProof, pClientProof, sizeof(pRecord->abClientProof)) == 0;
}

// 0x00528C90
static void sub_00528C90_SHA1Transform(unsigned long state[5], unsigned char buffer[64])
{
    unsigned long a, b, c, d, e;
    typedef union {
        unsigned char c[64];
        unsigned long l[16];
    } CHAR64LONG16;
    CHAR64LONG16* block;
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    block = (CHAR64LONG16*)buffer;
    R0(a,b,c,d,e,0); R0(e,a,b,c,d,1); R0(d,e,a,b,c,2); R0(c,d,e,a,b,3);
    R0(b,c,d,e,a,4); R0(a,b,c,d,e,5); R0(e,a,b,c,d,6); R0(d,e,a,b,c,7);
    R0(c,d,e,a,b,8); R0(b,c,d,e,a,9); R0(a,b,c,d,e,10); R0(e,a,b,c,d,11);
    R0(d,e,a,b,c,12); R0(c,d,e,a,b,13); R0(b,c,d,e,a,14); R0(a,b,c,d,e,15);
    R1(e,a,b,c,d,16); R1(d,e,a,b,c,17); R1(c,d,e,a,b,18); R1(b,c,d,e,a,19);
    R2(a,b,c,d,e,20); R2(e,a,b,c,d,21); R2(d,e,a,b,c,22); R2(c,d,e,a,b,23);
    R2(b,c,d,e,a,24); R2(a,b,c,d,e,25); R2(e,a,b,c,d,26); R2(d,e,a,b,c,27);
    R2(c,d,e,a,b,28); R2(b,c,d,e,a,29); R2(a,b,c,d,e,30); R2(e,a,b,c,d,31);
    R2(d,e,a,b,c,32); R2(c,d,e,a,b,33); R2(b,c,d,e,a,34); R2(a,b,c,d,e,35);
    R2(e,a,b,c,d,36); R2(d,e,a,b,c,37); R2(c,d,e,a,b,38); R2(b,c,d,e,a,39);
    R3(a,b,c,d,e,40); R3(e,a,b,c,d,41); R3(d,e,a,b,c,42); R3(c,d,e,a,b,43);
    R3(b,c,d,e,a,44); R3(a,b,c,d,e,45); R3(e,a,b,c,d,46); R3(d,e,a,b,c,47);
    R3(c,d,e,a,b,48); R3(b,c,d,e,a,49); R3(a,b,c,d,e,50); R3(e,a,b,c,d,51);
    R3(d,e,a,b,c,52); R3(c,d,e,a,b,53); R3(b,c,d,e,a,54); R3(a,b,c,d,e,55);
    R3(e,a,b,c,d,56); R3(d,e,a,b,c,57); R3(c,d,e,a,b,58); R3(b,c,d,e,a,59);
    R4(a,b,c,d,e,60); R4(e,a,b,c,d,61); R4(d,e,a,b,c,62); R4(c,d,e,a,b,63);
    R4(b,c,d,e,a,64); R4(a,b,c,d,e,65); R4(e,a,b,c,d,66); R4(d,e,a,b,c,67);
    R4(c,d,e,a,b,68); R4(b,c,d,e,a,69); R4(a,b,c,d,e,70); R4(e,a,b,c,d,71);
    R4(d,e,a,b,c,72); R4(c,d,e,a,b,73); R4(b,c,d,e,a,74); R4(a,b,c,d,e,75);
    R4(e,a,b,c,d,76); R4(d,e,a,b,c,77); R4(c,d,e,a,b,78); R4(b,c,d,e,a,79);
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    a = b = c = d = e = 0;
}

void __fastcall sub_00529F80_SHA1Update(T0041D340* context, unsigned char* data, unsigned int len)
{
    unsigned int i, j;
    j = (context->count[0] >> 3) & 63;
    if ((context->count[0] += len << 3) < (len << 3)) context->count[1]++;
    context->count[1] += (len >> 29);
    if ((j + len) > 63) {
        memcpy(&context->buffer[j], data, (i = 64 - j));
        sub_00528C90_SHA1Transform(context->state, context->buffer);
        for ( ; i + 63 < len; i += 64) {
            sub_00528C90_SHA1Transform(context->state, &data[i]);
        }
        j = 0;
    }
    else i = 0;
    memcpy(&context->buffer[j], &data[i], len - i);
}

// 0x00529F50
extern "C" __declspec(dllexport) void __fastcall sub_00529F50(Context00529F50* pContext) {
    pContext->dwH0 = 0x67452301;
    pContext->dwH1 = 0xEFCDAB89;
    pContext->dwH2 = 0x98BADCFE;
    pContext->dwH3 = 0x10325476;
    pContext->dwH4 = 0xC3D2E1F0;
    pContext->dwCountLow = pContext->dwCountHigh = 0;
}

// 0x0052A040
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext)
{
    unsigned int i;
    unsigned char abFinalCount[8];

    for (i = 0; i < 8; i++)
    {
        abFinalCount[i] = (unsigned char)((pContext->aCount[(i >= 4 ? 0 : 1)] >> ((3 - (i & 3)) * 8)) & 255);
    }
    sub_00529F80_Sha1Update(pContext, gabSha1Pad80_006E03F0, 1);
    while ((pContext->aCount[0] & 504) != 448)
    {
        sub_00529F80_Sha1Update(pContext, gabSha1Pad00_006DEF80, 1);
    }
    sub_00529F80_Sha1Update(pContext, abFinalCount, 8);
    for (i = 0; i < 20; i++)
    {
        pDigest[i] = (unsigned char)((pContext->aState[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
    }
}

#include "gen/data/Source/SRP/Unknown_005284F0.inc"
