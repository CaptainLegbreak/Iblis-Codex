void* __cdecl sub_00681EF0_ClearMemory(void* destination, int value, unsigned int size); // 0x00681EF0

static __declspec(noinline)
// 0x006BB6B0
void sub_006BB6B0_DecodeTile(const unsigned char* source, unsigned char* destination)
{
    int rows = 32;
    unsigned char* row = destination;
    unsigned char* pixel = destination;
    const unsigned char* input = source;
    sub_00681EF0_ClearMemory(destination, 0, 1024);
    do
    {
        unsigned char skip = *input++;
        unsigned char count = *input++;
        if (!skip && !count)
        {
            --rows;
            row += 32;
            pixel = row;
        }
        else
        {
            pixel += skip;
            while (count--)
                *pixel++ = *input++;
        }
    } while (rows);
}

void __fastcall EmitDecodeTile(unsigned char* destination, const unsigned char* source)
{
    sub_006BB6B0_DecodeTile(source, destination + 1);
}
