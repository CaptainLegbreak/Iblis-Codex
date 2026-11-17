struct RangeNode
{
    char gap00[0x204];
    unsigned int start;
    unsigned int size;
    RangeNode* next;
};
struct LookupNode
{
    char gap00[0x8];
    unsigned int key;
    char gapAfterKey[0x10];
    unsigned int value;
    char gapAfterValue[0x10];
    LookupNode* next;
};
struct ColorView
{
    char gap00[0x10];
    unsigned int color;
};
union PackedWord
{
    unsigned int word;
    struct Bytes
    {
        unsigned char low;
        unsigned char high;
        unsigned char third;
        unsigned char fourth;
    } bytes;
};
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char pointer_width[sizeof(void*)==4?1:-1];
typedef char word_width[sizeof(unsigned int)==4?1:-1];
typedef char packed_word_size[sizeof(PackedWord)==4?1:-1];
typedef char packed_high_lane[OFFSET(PackedWord::Bytes,high)==1?1:-1];
typedef char RangeNode_start[OFFSET(RangeNode,start)==0x204?1:-1];
typedef char RangeNode_size[OFFSET(RangeNode,size)==0x208?1:-1];
typedef char RangeNode_next[OFFSET(RangeNode,next)==0x20C?1:-1];
typedef char LookupNode_key[OFFSET(LookupNode,key)==0x8?1:-1];
typedef char LookupNode_value[OFFSET(LookupNode,value)==0x1C?1:-1];
typedef char LookupNode_next[OFFSET(LookupNode,next)==0x30?1:-1];
typedef char ColorView_color[OFFSET(ColorView,color)==0x10?1:-1];
extern "C" LookupNode* gLookupHead_007BB5BC;
extern "C" unsigned int gValue_007A065C;
extern "C" unsigned int gValue_007A0660;
extern "C" unsigned int gValue_007A0664;
extern "C" unsigned int gValue_007A6ABC;
extern "C" unsigned int gValue_007A6ADC;
extern "C" unsigned int gValue_007A6AE0;
extern "C" unsigned int gValue_007A6AF0;
extern "C" unsigned int gValue_00712F44;
extern "C" unsigned int gValue_00712F48;
extern "C" unsigned int gValue_007BB5D8;
extern "C" unsigned int gValue_007BB5E8;
extern "C" unsigned int gValue_007BCBF0; // 0x007BCBF0
extern "C" unsigned int gValue_007BCE2C; // 0x007BCE2C
extern "C" unsigned short gValue_007BB5E4;
extern "C" const unsigned char gColorTable_00971740[];

extern "C" RangeNode* __fastcall sub_0040BCB0_FindRange(unsigned int address, RangeNode* node)
{
    while (node)
    {
        unsigned int start = node->start;
        if (address >= start && address < start + node->size)
            return node;
        node = node->next;
    }
    return 0;
}

extern "C" void __fastcall sub_00468040_SetMode(unsigned int value, unsigned int alternate)
{
    unsigned int result = alternate != 0;
    gValue_007A6ABC = 0;
    gValue_007A6ADC = 0x6;
    gValue_007A6AE0 = value;
    gValue_007A6AF0 = result + 0x7;
}

extern "C" unsigned int __fastcall sub_00479080_FindListValue(unsigned int key)
{
    LookupNode* node = gLookupHead_007BB5BC;
    while (node)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return 0;
}

extern "C" void __cdecl sub_0047BD30_ResetGlobals()
{
    gValue_00712F44 = 0x7;
    gValue_00712F48 = 0x7;
    gValue_007BB5D8 = 0;
    gValue_007BB5E4 = 0;
    gValue_007BB5E8 = 0;
}

// 0x00489880
extern "C" void __cdecl sub_00489880_ClearAndTransition()
{
    bool transition = gValue_007BCBF0 == 0xD;
    gValue_007BCE2C = 0;
    if (transition)
        gValue_007BCBF0 = 0xC;
}
