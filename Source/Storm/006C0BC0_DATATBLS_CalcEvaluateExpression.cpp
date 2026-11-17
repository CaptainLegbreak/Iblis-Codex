struct Fog64IntStack { int data[64]; int size; };
typedef int (__fastcall* CalcParam)(int, void*);
typedef int (__fastcall* CalcFunction)(int, int, int, void*);
struct CalcEntry { CalcFunction function; int parameters; };
static void sub_006C0B80(Fog64IntStack*, int); // 0x006C0B80
// 0x006C0B80
static void sub_006C0B80(Fog64IntStack* s, int value)
{
    if (s->size < 64)
    {
        s->data[s->size] = value;
        ++s->size;
    }
}
static int __fastcall sub_006C0BA0(Fog64IntStack*); // 0x006C0BA0
// 0x006C0BA0
static int __fastcall sub_006C0BA0(Fog64IntStack* s)
{
    if (s->size <= 0)
    {
        return 0;
    }
    return s->data[--s->size];
}
// 0x006C0BC0
int __stdcall DATATBLS_CalcEvaluateExpression(const unsigned char* start, int length, CalcParam param, CalcEntry* table, int tableSize, void* userData)
{
    if (length <= 0) return 0;
    const unsigned char* p = start;
    Fog64IntStack stack;
    stack.size = 0;
    if (p - start >= length) goto Done;
    do
    {
        unsigned char op = *p++;
        switch (op)
        {
        case 4:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, param(*(unsigned char*)p, userData));
            p += 1;
            break;
        case 5:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, param(*(short*)p, userData));
            p += 2;
            break;
        case 6:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, param(*(int*)p, userData));
            p += 4;
            break;
        case 7:
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, *(signed char*)p);
            p += 1;
            break;
        case 8:
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, *(short*)p);
            p += 2;
            break;
        case 9:
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, *(int*)p);
            p += 4;
            break;
        case 1:
        {
            int index = *p++;
            if (index >= tableSize) { sub_006C0B80(&stack, 0); break; }
            int count = table[index].parameters;
            if (count == 3)
            {
                int c = sub_006C0BA0(&stack);
                int b = sub_006C0BA0(&stack);
                int a = sub_006C0BA0(&stack);
                sub_006C0B80(&stack, table[index].function(a, b, c, userData));
            }
            else if (count == 2) goto Two;
            else if (count == 1)
            {
                int a = sub_006C0BA0(&stack);
                sub_006C0B80(&stack, table[index].function(a, 0, 0, userData));
            }
            else if (count == 0)
                sub_006C0B80(&stack, table[index].function(0, 0, 0, userData));
            else sub_006C0B80(&stack, 0);
            break;
        Two:
            {
                int b = sub_006C0BA0(&stack);
                int a = sub_006C0BA0(&stack);
                sub_006C0B80(&stack, table[index].function(a, b, 0, userData));
            }
            break;
        }
        case 16:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a + b);
            break;
        }
        case 17:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a - b);
            break;
        }
        case 18:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a * b);
            break;
        }
        case 19:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            if (b) sub_006C0B80(&stack, a / b);
            else sub_006C0B80(&stack, 0);
            break;
        }
        case 21:
            sub_006C0B80(&stack, -sub_006C0BA0(&stack));
            break;
        case 22:
        {
            int ifFalse = sub_006C0BA0(&stack);
            int ifTrue = sub_006C0BA0(&stack);
            int condition = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, condition ? ifTrue : ifFalse);
            break;
        }
        case 20:
        {
            int exponent = sub_006C0BA0(&stack);
            int base = sub_006C0BA0(&stack);
            int result = base;
            if (exponent > 0)
            {
                for (int i = 1; i < exponent; ++i) result *= base;
            }
            else result = 1;
            sub_006C0B80(&stack, result);
            break;
        }
        case 10:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a < b);
            break;
        }
        case 12:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a <= b);
            break;
        }
        case 11:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a > b);
            break;
        }
        case 13:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a >= b);
            break;
        }
        case 14:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a == b);
            break;
        }
        case 15:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a != b);
            break;
        }
        default:
            if (stack.size) return sub_006C0BA0(&stack);
            return 0;
        }
    } while (p - start < length);
Done:
    return 0;
}
