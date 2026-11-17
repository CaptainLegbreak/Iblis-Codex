static __declspec(noinline) int sub_006C5F40_GetImageType(unsigned short signature);

// 0x006C5F40
static int sub_006C5F40_GetImageType(unsigned short signature)
{
    switch (signature)
    {
    case 0x050A:
        return 2;
    case 0x4D42:
        return 1;
    default:
        return 3;
    }
}

int __cdecl EmitGetImageType(unsigned short signature)
{
    return sub_006C5F40_GetImageType(signature);
}
