struct ByteRecord
{
    char gap00[0x3E];
    unsigned char value;
    char tail[0x4F];
};

#pragma pack(push,1)
struct PacketWords
{
    char prefix[1];
    unsigned short kind;
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct PacketShorts
{
    char prefix[1];
    unsigned short kind;
    unsigned short a;
    unsigned short b;
    unsigned short c;
};
#pragma pack(pop)
struct Digest
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
};
struct HashState
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int lowCount;
    unsigned int highCount;
    char block[0x40];
};
struct Member
{
    short value;
};
struct ClassRecord
{
    char gap00[2];
    short relation;
    short next;
    char gapToMembers[0x16A];
    Member members[8];
    char tail[0x28];
};
struct ClassTableView
{
    char gap00[0xA78];
    ClassRecord* records;
    char gapAfterRecords[4];
    int count;
};
struct UnitView
{
    unsigned int type;
    int classId;
};
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char pointer_width[sizeof(void*)==4?1:-1];
typedef char word_width[sizeof(unsigned int)==4?1:-1];
typedef char ByteRecord_value[OFFSET(ByteRecord,value)==0x3E?1:-1];
typedef char PacketWords_kind[OFFSET(PacketWords,kind)==0x1?1:-1];
typedef char PacketWords_a[OFFSET(PacketWords,a)==0x3?1:-1];
typedef char PacketWords_b[OFFSET(PacketWords,b)==0x7?1:-1];
typedef char PacketWords_c[OFFSET(PacketWords,c)==0xB?1:-1];
typedef char PacketShorts_kind[OFFSET(PacketShorts,kind)==0x1?1:-1];
typedef char PacketShorts_a[OFFSET(PacketShorts,a)==0x3?1:-1];
typedef char PacketShorts_b[OFFSET(PacketShorts,b)==0x5?1:-1];
typedef char PacketShorts_c[OFFSET(PacketShorts,c)==0x7?1:-1];
typedef char ClassRecord_relation[OFFSET(ClassRecord,relation)==0x2?1:-1];
typedef char ClassRecord_next[OFFSET(ClassRecord,next)==0x4?1:-1];
typedef char ClassRecord_members[OFFSET(ClassRecord,members)==0x170?1:-1];
typedef char ClassTableView_records[OFFSET(ClassTableView,records)==0xA78?1:-1];
typedef char ClassTableView_count[OFFSET(ClassTableView,count)==0xA80?1:-1];
typedef char UnitView_type[OFFSET(UnitView,type)==0x0?1:-1];
typedef char UnitView_classId[OFFSET(UnitView,classId)==0x4?1:-1];
typedef char Digest_a[OFFSET(Digest,a)==0x0?1:-1];
typedef char Digest_b[OFFSET(Digest,b)==0x4?1:-1];
typedef char Digest_c[OFFSET(Digest,c)==0x8?1:-1];
typedef char Digest_d[OFFSET(Digest,d)==0xC?1:-1];
typedef char Digest_e[OFFSET(Digest,e)==0x10?1:-1];
typedef char HashState_a[OFFSET(HashState,a)==0x0?1:-1];
typedef char HashState_b[OFFSET(HashState,b)==0x4?1:-1];
typedef char HashState_c[OFFSET(HashState,c)==0x8?1:-1];
typedef char HashState_d[OFFSET(HashState,d)==0xC?1:-1];
typedef char HashState_e[OFFSET(HashState,e)==0x10?1:-1];
typedef char HashState_lowCount[OFFSET(HashState,lowCount)==0x14?1:-1];
typedef char HashState_highCount[OFFSET(HashState,highCount)==0x18?1:-1];
typedef char ByteRecord_size[sizeof(ByteRecord)==0x8E?1:-1];
typedef char PacketWords_size[sizeof(PacketWords)==0xF?1:-1];
typedef char PacketShorts_size[sizeof(PacketShorts)==0x9?1:-1];
typedef char Digest_size[sizeof(Digest)==0x14?1:-1];
typedef char HashState_size[sizeof(HashState)==0x5C?1:-1];
typedef char Member_size[sizeof(Member)==0x2?1:-1];
typedef char ClassRecord_size[sizeof(ClassRecord)==0x1A8?1:-1];
extern "C" ByteRecord* gRecords_007BC9A0;
extern "C" int gRecordCount_007BC9A4;
extern "C" { unsigned int gValue_007BF098; } // 0x007BF098
extern "C" { unsigned int gValue_007BF09C; } // 0x007BF09C
extern "C" { unsigned int gValue_007BF0A0; } // 0x007BF0A0
extern "C" unsigned int gValue_007BF254; // 0x007BF254
extern "C" unsigned int gValue_007BF2A4; // 0x007BF2A4
extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8
extern "C" unsigned int gValue_007BF2AC; // 0x007BF2AC
extern "C" HashState gStates_00882760[];
extern "C" ClassTableView* gClassTable_00744304;

// 0x0049FF60
extern "C" void __fastcall sub_0049FF60_AcceptWordPacket(const PacketWords* packet)
{
    if (packet->kind == 4)
    {
        gValue_007BF098 = packet->a;
        gValue_007BF09C = packet->b;
        gValue_007BF0A0 = packet->c;
        gValue_007BF254 = 0;
    }
}

// 0x004A28A0
extern "C" void __fastcall sub_004A28A0_AcceptShortPacket(const PacketShorts* packet)
{
    switch (packet->kind)
    {
    case 1:
        gValue_007BF2A4 = packet->a;
        gValue_007BF2A8 = packet->b;
        gValue_007BF2AC = packet->c;
        break;
    }
}

extern "C" void __fastcall sub_00524280_InitializeDigest(unsigned int index)
{
    HashState* state = &gStates_00882760[index];
    state->a = 0x67452301u;
    state->b = 0xEFCDAB89u;
    state->c = 0x98BADCFEu;
    state->d = 0x10325476u;
    state->e = 0xC3D2E1F0u;
    state->lowCount = 0;
    state->highCount = 0;
}
