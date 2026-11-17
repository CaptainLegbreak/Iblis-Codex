struct D2WinControlStrc;

// 0x00443540
int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar)
{
    switch (*pChar)
    {
    case ' ':
    case '\'':
    case '-':
    case '_':
        return 1;
    }
    if (*pChar >= '0' && *pChar <= '9')
        return 1;
    if (*pChar >= 'A' && *pChar <= 'Z')
        return 1;
    if (*pChar >= 'a' && *pChar <= 'z')
        return 1;
    return 0;
}
