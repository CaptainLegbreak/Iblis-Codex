struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

struct D2QuestTextLineStrc
{
    unsigned short wLead[9];
    UnicodeChar wszText[300];
};

struct D2QuestTextBufferStrc
{
    unsigned char pHead[0x106];
    D2QuestTextLineStrc pLines[6];

    D2QuestTextBufferStrc();
};

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A4260
D2QuestTextBufferStrc::D2QuestTextBufferStrc()
{
}
