struct D2ReferenceStrc
{
    int unk_00;
    int f_4;
    volatile long nReferences;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value); // 0x006CC208

// 0x006BE640
long __fastcall sub_006BE640_AddReference(void* unusedContext, D2ReferenceStrc* object)
{
    return InterlockedIncrement(&object->nReferences);
}
