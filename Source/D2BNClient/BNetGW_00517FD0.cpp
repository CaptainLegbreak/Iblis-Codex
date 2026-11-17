unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
struct Table { char pad0[8]; int count; char padC[4]; const char* data; int length; const char* Nth(int n); };

// 0x00517FD0
const char* Table::Nth(int n)
{
    Table* self = this;
    const char* base = self->data;
    if (base == 0 || n < 1 || n > self->count)
        return (const char*)self;
    int i = 1;
    int target = n * 3;
    int offset = 0;
    const char* p = base;
    while (i < target && offset < self->length)
    {
        int len = SStrLen(p) + 1;
        offset += len;
        p += len;
        ++i;
    }
    if (offset < self->length && i <= target)
        return p;
    return (const char*)self;
}
