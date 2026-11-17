struct D2CellFileStrc;

struct D2CelContext006B7090Strc
{
    unsigned char unk_00[0x08];
    int nUnitType;
    int nClass;
    int nMode;
    unsigned char unk_14[0x18];
    const char* szName;
    unsigned char unk_30[0x0C];
    D2CellFileStrc* pCelFile;
};

struct D2TextureInfo006B7090Strc
{
    D2CelContext006B7090Strc* pContext;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
    int nTextureWidth;
    int nTextureHeight;
    int nTextureSize;
    float fU0;
    float fU1;
    float fV0;
    float fV1;
};

void __fastcall sub_006B1F40_SetRenderMode(int nMode); // 0x006B1F40
int __stdcall sub_006001F0_Prepare(D2CelContext006B7090Strc* pContext, int a2, int a3); // 0x006001F0
int __stdcall sub_006018C0_CelGetWidth(D2CellFileStrc* pCelFile); // 0x006018C0
int __stdcall sub_006018F0_CelGetHeight(D2CellFileStrc* pCelFile); // 0x006018F0
int __stdcall sub_00601920_CelGetOffsetX(D2CellFileStrc* pCelFile); // 0x00601920
int __stdcall sub_00601950_CelGetOffsetY(D2CellFileStrc* pCelFile); // 0x00601950
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610

int __stdcall shim_7(D2CellFileStrc* pCelFile, int nWidth, int nHeight, int nMode, int* pArg1, int* pArg2);
int __stdcall shim_6(int nOffsetX, int nOffsetY, int nTextureWidth, int* pX, int* pY, int* pArg3, int* pArg4, int* pArg5, int* pArg6);

static __declspec(noinline) int __stdcall sub_006B5C80_LoadCelInfo(D2CelContext006B7090Strc* pContext, D2TextureInfo006B7090Strc* pInfo);
static __declspec(noinline) void __stdcall sub_006B5CF0_SetTextureSize(D2TextureInfo006B7090Strc* pInfo);
static __declspec(noinline) int __stdcall sub_006B5D40_UploadTexture(D2TextureInfo006B7090Strc* pInfo, int nMode, int nArg1, int nArg2);
static __declspec(noinline) int __stdcall sub_006B63F0_DrawTexture(D2TextureInfo006B7090Strc* pInfo, int nX, int nY, int nArg3, int nArg4, int nArg5, int nArg6);

// 0x006B5C80
static int __stdcall sub_006B5C80_LoadCelInfo(D2CelContext006B7090Strc* pContext, D2TextureInfo006B7090Strc* pInfo)
{
    if (!sub_006001F0_Prepare(pContext, 0, 1))
    {
        return 0;
    }

    if (!pContext->pCelFile)
    {
        sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", pContext->nUnitType, pContext->nClass, pContext->nMode, pContext->szName);
        return 0;
    }

    pInfo->pContext = pContext;
    pInfo->nWidth = sub_006018C0_CelGetWidth(pContext->pCelFile);
    pInfo->nOffsetX = sub_00601920_CelGetOffsetX(pContext->pCelFile);
    pInfo->nHeight = sub_006018F0_CelGetHeight(pContext->pCelFile);
    pInfo->nOffsetY = sub_00601950_CelGetOffsetY(pContext->pCelFile);
    return 1;
}

// 0x006B5CF0
static void __stdcall sub_006B5CF0_SetTextureSize(D2TextureInfo006B7090Strc* pInfo)
{
    int nSize = 0x20;
    if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
    {
        nSize = 0x80;
        if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
        {
            nSize = 0x100;
            if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
            {
                goto done;
            }
        }
    }
    pInfo->nTextureWidth = nSize;
    pInfo->nTextureHeight = nSize;
done:
    pInfo->nTextureSize = pInfo->nTextureHeight * pInfo->nTextureWidth;
    pInfo->fU0 = 0.0f;
    pInfo->fU1 = 1.0f;
    pInfo->fV0 = 0.0f;
    pInfo->fV1 = 1.0f;
}

// build: context sub_006B5D40_UploadTexture
// calling-convention shim (not game code)
static int __stdcall sub_006B5D40_UploadTexture(D2TextureInfo006B7090Strc* pInfo, int nMode, int nArg1, int nArg2)
{
    return shim_7(pInfo->pContext->pCelFile, pInfo->nWidth, pInfo->nHeight, nMode == 4 ? 1 : nMode, &nArg1, &nArg2);
}

// build: context sub_006B63F0_DrawTexture
// calling-convention shim (not game code)
static int __stdcall sub_006B63F0_DrawTexture(D2TextureInfo006B7090Strc* pInfo, int nX, int nY, int nArg3, int nArg4, int nArg5, int nArg6)
{
    return shim_6(pInfo->nOffsetX, pInfo->nOffsetY, pInfo->nTextureWidth, &nX, &nY, &nArg3, &nArg4, &nArg5, &nArg6);
}

// 0x006B7090
int __fastcall sub_006B7090_DrawCel(D2CelContext006B7090Strc* pContext, int nX, int nY, int nArg)
{
    D2TextureInfo006B7090Strc tInfo;

    sub_006B1F40_SetRenderMode(4);
    int nResult = sub_006B5C80_LoadCelInfo(pContext, &tInfo);
    if (nResult)
    {
        tInfo.nWidth += 2;
        tInfo.nHeight += 2;
        sub_006B5CF0_SetTextureSize(&tInfo);
        nResult = sub_006B5D40_UploadTexture(&tInfo, 3, 0, nArg);
        if (nResult)
        {
            nResult = sub_006B63F0_DrawTexture(&tInfo, nX - 1, nY + 1, -1, 0, 0x40, 1);
        }
    }
    return nResult;
}
