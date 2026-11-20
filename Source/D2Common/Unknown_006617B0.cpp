#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
struct D2BinFieldStrc;
struct D2MissilesTxt;

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C
extern D2TxtLinkStrc* gpSkillCodeLinker_0096BCA0; // 0x0096BCA0
extern D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798
extern char* gpMissCode_0096BC90; // 0x0096BC90
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0
int __fastcall DATATBLS_MapMissilesTxtKeywordToNumber(char* szKey); // 0x00661800
int __fastcall sub_6FD62F20(char* szText, int* a2, int a3, int nKeywordNumber); // 0x00661880
int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__cdecl* pfnGetParameterCount)(), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};


static __declspec(noinline) int __stdcall sub_00661A30_ClampMissileField(D2BinFieldStrc* pFields, int nMissileId, int nOffset, int nType, int nMin, int nMax);

D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C

// 0x006617B0
static void sub_006617B0_TextToLinkCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
    }
    else
    {
        szCode[0] = szText[0];
        if (!szText[1])
        {
            szCode[1] = ' ';
            szCode[2] = ' ';
            szCode[3] = ' ';
        }
        else
        {
            szCode[1] = szText[1];
            if (!szText[2])
            {
                szCode[2] = ' ';
                szCode[3] = ' ';
            }
            else
            {
                szCode[2] = szText[2];
                if (!szText[3])
                {
                    szCode[3] = ' ';
                }
                else
                {
                    szCode[3] = szText[3];
                }
            }
        }
    }
}

// 0x00661880
int __fastcall sub_6FD62F20(char* szText, int* a2, int a3, int nKeywordNumber)
{
    char szCode[4];

    if (a3 == 1)
    {
        if (nKeywordNumber == 3)
        {
            if (gpSkillCodeLinker_0096BCA0)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillCodeLinker_0096BCA0, szText, 0);
                if (nRow >= 0)
                {
                    *a2 = 1;
                    return nRow;
                }

                sub_006617B0_TextToLinkCode(szText, szCode);
                const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
                *a2 = 0;
                return nIndex;
            }
        }
        else if (nKeywordNumber == 4)
        {
            if (gpMissilesLinker_0096C798)
            {
                const int nRow = FOG_GetRowFromTxt(gpMissilesLinker_0096C798, szText, 0);
                if (nRow >= 0)
                {
                    *a2 = 1;
                    return nRow;
                }
            }

            sub_006617B0_TextToLinkCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
            *a2 = 0;
            return nIndex;
        }
    }

    sub_006617B0_TextToLinkCode(szText, szCode);
    const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
    *a2 = 0;
    return nIndex;
}

// 0x00661800
int __fastcall DATATBLS_MapMissilesTxtKeywordToNumber(char* szKey)
{
    if (!SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (!SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (!SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (!SStrCmpI(szKey, "skill", 32))
    {
        return 3;
    }
    else if (!SStrCmpI(szKey, "miss", 32))
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

int gnMissCodeSize_0096BC94; // 0x0096BC94

int gnMissCodeSizeEx_0096BC98; // 0x0096BC98

// 0x006619A0
void __fastcall DATATBLS_MissileCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char pBuffer[1024];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapMissilesTxtKeywordToNumber, 0, sub_6FD62F20);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpMissCode_0096BC90, &gnMissCodeSize_0096BC94, &gnMissCodeSizeEx_0096BC98, pBuffer, nBufferSize);
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTable->nMissilesTxtRecordCount)
    {
        return &sgptDataTable->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x00661A30
static int __stdcall sub_00661A30_ClampMissileField(D2BinFieldStrc* pFields, int nMissileId, int nOffset, int nType, int nMin, int nMax)
{
    char* pRecord = (char*)DATATBLS_GetMissilesTxtRecord(nMissileId);
    int nValue = 0;
    switch (nType)
    {
    case 0:
        nValue = *(signed char*)(pRecord + nOffset);
        break;
    case 1:
        nValue = *(unsigned char*)(pRecord + nOffset);
        break;
    case 2:
        nValue = *(short*)(pRecord + nOffset);
        break;
    case 3:
        nValue = *(unsigned short*)(pRecord + nOffset);
        break;
    case 4:
        nValue = *(int*)(pRecord + nOffset);
        break;
    }

    if (nValue < nMin || nValue > nMax)
    {
        for (int nField = 0; pFields[nField].nFieldType; ++nField)
        {
            if (pFields[nField].nFieldOffset == nOffset)
            {
                break;
            }
        }

        nValue = D2_MIN(D2_MAX(nValue, nMin), nMax);

        switch (nType)
        {
        case 0:
        case 1:
            *(char*)(pRecord + nOffset) = (char)nValue;
            break;
        case 2:
        case 3:
            *(short*)(pRecord + nOffset) = (short)nValue;
            break;
        case 4:
            *(int*)(pRecord + nOffset) = nValue;
            break;
        }
    }
    return nValue;
}

// calling-convention shim (not game code)
void __fastcall sub_00661A30_Shim(D2BinFieldStrc* pFields)
{
    for (int i = 0; i < sgptDataTable->nMissilesTxtRecordCount; ++i)
    {
        sub_00661A30_ClampMissileField(pFields, i, 0x183, 1, 0, 8);
        sub_00661A30_ClampMissileField(pFields, i, 0x190, 2, -1, 100);
    }
}
