struct D2CacheBindingStrc { int unk_00; short value; };
struct D2CacheNodeStrc { int id; D2CacheBindingStrc* binding; int unk_08; int unk_0C; D2CacheNodeStrc* next; D2CacheNodeStrc* previous; };
struct D2CacheListStrc { int capacity; int count; D2CacheNodeStrc* firstUsed; D2CacheNodeStrc* lastUsed; D2CacheNodeStrc* firstFree; D2CacheNodeStrc* lastFree; };
static __declspec(noinline) int sub_006BAC50_TakeFreeNode(D2CacheListStrc* list); // 0x006BAC50

static __forceinline D2CacheNodeStrc* PopNode(D2CacheNodeStrc*& first, D2CacheNodeStrc*& last)
{
    D2CacheNodeStrc* node = first;
    if (!node)
        return 0;
    first = node->next;
    if (first)
        first->previous = 0;
    else
        last = 0;
    node->next = 0;
    node->previous = 0;
    return node;
}
static __forceinline void AppendNode(D2CacheNodeStrc*& first, D2CacheNodeStrc*& last, D2CacheNodeStrc* node)
{
    if (!first)
        first = node;
    else
    {
        last->next = node;
        node->previous = last;
    }
    last = node;
}
static __declspec(noinline) int sub_006BAC50_TakeFreeNode(D2CacheListStrc* list)
{
    if (list->count == list->capacity)
        return 0;
    D2CacheNodeStrc* node = PopNode(list->firstFree, list->lastFree);
    AppendNode(list->firstUsed, list->lastUsed, node);
    ++list->count;
    return node->id + 1;
}

// 0x006BAF00
int __fastcall sub_006BAF00_AllocateCacheNode(D2CacheListStrc* list)
{
    int result = sub_006BAC50_TakeFreeNode(list);
    if (result)
        return result;
    for (;;)
    {
        if (list->count)
        {
            D2CacheNodeStrc* node = PopNode(list->firstUsed, list->lastUsed);
            if (node)
            {
                if (node->binding)
                {
                    node->binding->value = 0;
                    node->binding = 0;
                }
                AppendNode(list->firstFree, list->lastFree, node);
            }
            --list->count;
        }
        if (list->count == list->capacity)
            continue;
        D2CacheNodeStrc* node = PopNode(list->firstFree, list->lastFree);
        if (!list->firstUsed)
            list->firstUsed = node;
        else
        {
            list->lastUsed->next = node;
            node->previous = list->lastUsed;
        }
        ++list->count;
        list->lastUsed = node;
        result = node->id + 1;
        if (result)
            return result;
    }
}
