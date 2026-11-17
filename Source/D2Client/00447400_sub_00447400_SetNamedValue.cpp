extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

struct D2NamedValueStrc
{
    char szName[0x32];
    char szValue[0x12];
    D2NamedValueStrc* pNext;
};

const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

static D2NamedValueStrc* s_pNamedValues_00798F38; // 0x00798F38
static int s_nNamedValues_00798F3C; // 0x00798F3C

static inline const char* sub_SkipStarPrefix(const char* szName)
{
    const char* pFound = SStrChr(szName, '*');
    if (pFound && *++pFound)
        return pFound;
    return szName;
}

// 0x00447400
void __fastcall sub_00447400_SetNamedValue(const char* szName, const char* szValue)
{
    D2NamedValueStrc* pNode = s_pNamedValues_00798F38;
    D2NamedValueStrc* pPrevious = 0;
    const char* szKey = sub_SkipStarPrefix(szName);
    for (; pNode; pNode = pNode->pNext)
    {
        if (!strcmp(sub_SkipStarPrefix(pNode->szName), szKey))
            break;
        pPrevious = pNode;
    }
    if (pNode)
    {
        strcpy(pNode->szValue, szValue);
        return;
    }
    if (s_nNamedValues_00798F3C >= 0x400)
    {
        pNode = s_pNamedValues_00798F38;
        s_pNamedValues_00798F38 = s_pNamedValues_00798F38->pNext;
        FOG_Free(pNode, ".\\Src\\ComCallback.cpp", 0x936, 0);
        --s_nNamedValues_00798F3C;
    }
    D2NamedValueStrc* pNew = (D2NamedValueStrc*)FOG_Alloc(sizeof(D2NamedValueStrc), ".\\Src\\ComCallback.cpp", 0x93A, 0);
    strcpy(pNew->szName, szName);
    strcpy(pNew->szValue, szValue);
    pNew->pNext = 0;
    if (pPrevious)
        pPrevious->pNext = pNew;
    else
        s_pNamedValues_00798F38 = pNew;
    ++s_nNamedValues_00798F3C;
}
