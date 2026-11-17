struct Message;
typedef void (__cdecl* Callback)();
#pragma pack(push,2)
struct ListBox {
    virtual void Slot0(); virtual void Slot1(); virtual void Slot2();
    virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6();
    virtual int ScrollUp(Message*); virtual int ScrollDown(Message*);
    char pad4[0x180718];
    int mouseDown,topPressed,bottomPressed,rowsPressed,pressY,topIndex,callbackRow;
    char pad738[0x12];
    Callback callback;
    int sub_004BE720(Message*); int sub_004BE770(Message*); int sub_004BE7C0(Message*);
    int sub_004BF2F0(Message*); int sub_004BEA50(Message*);
    int sub_004BF530(Message*);
};
#pragma pack(pop)
enum { INVALID_ROW = -1 };
// build: symbol ?sub_004BE720@ListBox@@QAEHPAUMessage@@@Z 0x004BE720
// build: symbol ?sub_004BE770@ListBox@@QAEHPAUMessage@@@Z 0x004BE770
// build: symbol ?sub_004BE7C0@ListBox@@QAEHPAUMessage@@@Z 0x004BE7C0
// build: symbol ?sub_004BEA50@ListBox@@QAEHPAUMessage@@@Z 0x004BEA50
// build: symbol ?sub_004BF2F0@ListBox@@QAEHPAUMessage@@@Z 0x004BF2F0
// 0x004BF530
int ListBox::sub_004BF530(Message* message)
{
    if(!mouseDown) { callbackRow=INVALID_ROW; return 1; }
    mouseDown=0;
    if(topPressed==1) {
        topPressed=0;
        if(sub_004BE720(message)==1) ScrollUp(message);
        callbackRow=INVALID_ROW;
        return 0;
    }
    if(bottomPressed==1) {
        bottomPressed=0;
        if(sub_004BE770(message)==1) ScrollDown(message);
        callbackRow=INVALID_ROW;
        return 0;
    }
    if(rowsPressed==1) {
        rowsPressed=0;
        if(sub_004BE7C0(message)==1) sub_004BF2F0(message);
        callbackRow=INVALID_ROW;
        return 0;
    }
    if(callback) {
        int hit=sub_004BEA50(message);
        if(callbackRow==hit && callbackRow!=INVALID_ROW) {
            callbackRow=INVALID_ROW;
            callback();
            return 1;
        }
    }
    return 0;
}
