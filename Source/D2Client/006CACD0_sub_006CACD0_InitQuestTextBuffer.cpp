inline void* operator new(unsigned int, void* pWhere) { return pWhere; }

struct D2QuestTextBufferStrc
{
    D2QuestTextBufferStrc();
};
// build: symbol ??0D2QuestTextBufferStrc@@QAE@XZ 0x004A4260

extern D2QuestTextBufferStrc data_007BF298; // 0x007BF298

// 0x006CACD0
void __cdecl sub_006CACD0_InitQuestTextBuffer()
{
    new (&data_007BF298) D2QuestTextBufferStrc;
}
