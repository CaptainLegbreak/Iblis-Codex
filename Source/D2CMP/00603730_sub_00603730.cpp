struct DeleteFlags { unsigned value; };
int __stdcall sub_00412650(void*,const char*,int,unsigned);  // 0x00412650
struct SlotArray { void Destroy(); SlotArray* sub_00603730(DeleteFlags flags); };  // 0x00603060
enum { DELETE_BIT = 1 };
// 0x00603730
SlotArray* SlotArray::sub_00603730(DeleteFlags flags)
{
    Destroy();
    if(flags.value & DELETE_BIT) {
        if(this) sub_00412650(this,"delete",-1,0);
    }
    return this;
}
