struct D2ValueBufferStrc { int values[64]; int count; };

// 0x006C0B80
static __forceinline void sub_006C0B80_AppendValue(D2ValueBufferStrc* buffer, int value)
{
    if (buffer->count < 64)
    {
        buffer->values[buffer->count] = value;
        ++buffer->count;
    }
}

void __fastcall EmitAppendValue(D2ValueBufferStrc* buffer, int value)
{
    sub_006C0B80_AppendValue(buffer, value + 1);
}
