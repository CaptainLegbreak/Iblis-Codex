struct sub_006BF170_Object
{
    int nHandle;
};

void __fastcall sub_006C2110(sub_006BF170_Object* pObject); // 0x006C2110
void __fastcall sub_006C33D0_Stop(sub_006BF170_Object* pObject); // 0x006C33D0

// 0x006BF170
void __fastcall sub_006BF170_Dispatch(sub_006BF170_Object* pObject)
{
    if (pObject->nHandle)
        sub_006C2110(pObject);
    else
        sub_006C33D0_Stop(pObject);
}
