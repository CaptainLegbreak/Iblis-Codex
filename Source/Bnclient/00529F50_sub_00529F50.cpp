struct Context00529F50 {
    unsigned int dwH0;
    unsigned int dwH1;
    unsigned int dwH2;
    unsigned int dwH3;
    unsigned int dwH4;
    unsigned int dwCountLow;
    unsigned int dwCountHigh;
};

// 0x00529F50
extern "C" __declspec(dllexport) void __fastcall sub_00529F50(Context00529F50* pContext) {
    pContext->dwH0 = 0x67452301;
    pContext->dwH1 = 0xEFCDAB89;
    pContext->dwH2 = 0x98BADCFE;
    pContext->dwH3 = 0x10325476;
    pContext->dwH4 = 0xC3D2E1F0;
    pContext->dwCountLow = pContext->dwCountHigh = 0;
}
