void __fastcall sub_0051763C_Destroy(void* pObject); // 0x0051763C
void __fastcall sub_005174E2_DestroyMember(void* pMember); // 0x005174E2
// 0x00517658
void __fastcall sub_00517658_Destroy(char* pObject)
{
    sub_0051763C_Destroy(pObject);
    sub_005174E2_DestroyMember(pObject + 4);
}
