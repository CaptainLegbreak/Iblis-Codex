void __cdecl sub_00410610_WriteLogLine(const char*,...); // 0x00410610
void __fastcall sub_006B20E0(const char*,long); // 0x006B20E0
// 0x006B39B0
void __fastcall sub_006B39B0_ShowD3DError(const char* text,long result)
{
    const char* name;
    switch(result) {
    case (long)0x887602BC: name="D3DERR_BADMAJORVERSION"; break;
    case (long)0x887602BD: name="D3DERR_BADMINORVERSION"; break;
    case (long)0x887602C1: name="D3DERR_INVALID_DEVICE"; break;
    case (long)0x887602C2: name="D3DERR_INITFAILED"; break;
    case (long)0x887602C3: name="D3DERR_DEVICEAGGREGATED"; break;
    case (long)0x887602C6: name="D3DERR_EXECUTE_CREATE_FAILED"; break;
    case (long)0x887602C7: name="D3DERR_EXECUTE_DESTROY_FAILED"; break;
    case (long)0x887602C8: name="D3DERR_EXECUTE_LOCK_FAILED"; break;
    case (long)0x887602C9: name="D3DERR_EXECUTE_UNLOCK_FAILED"; break;
    case (long)0x887602CA: name="D3DERR_EXECUTE_LOCKED"; break;
    case (long)0x887602CB: name="D3DERR_EXECUTE_NOT_LOCKED"; break;
    case (long)0x887602CC: name="D3DERR_EXECUTE_FAILED"; break;
    case (long)0x887602CD: name="D3DERR_EXECUTE_CLIPPED_FAILED"; break;
    case (long)0x887602D0: name="D3DERR_TEXTURE_NO_SUPPORT"; break;
    case (long)0x887602D1: name="D3DERR_TEXTURE_CREATE_FAILED"; break;
    case (long)0x887602D2: name="D3DERR_TEXTURE_DESTROY_FAILED"; break;
    case (long)0x887602D3: name="D3DERR_TEXTURE_LOCK_FAILED"; break;
    case (long)0x887602D4: name="D3DERR_TEXTURE_UNLOCK_FAILED"; break;
    case (long)0x887602D5: name="D3DERR_TEXTURE_LOAD_FAILED"; break;
    case (long)0x887602D6: name="D3DERR_TEXTURE_SWAP_FAILED"; break;
    case (long)0x887602D7: name="D3DERR_TEXTURE_LOCKED"; break;
    case (long)0x887602D8: name="D3DERR_TEXTURE_NOT_LOCKED"; break;
    case (long)0x887602D9: name="D3DERR_TEXTURE_GETSURF_FAILED"; break;
    case (long)0x887602DA: name="D3DERR_MATRIX_CREATE_FAILED"; break;
    case (long)0x887602DB: name="D3DERR_MATRIX_DESTROY_FAILED"; break;
    case (long)0x887602DC: name="D3DERR_MATRIX_SETDATA_FAILED"; break;
    case (long)0x887602DD: name="D3DERR_MATRIX_GETDATA_FAILED"; break;
    case (long)0x887602DE: name="D3DERR_SETVIEWPORTDATA_FAILED"; break;
    case (long)0x887602DF: name="D3DERR_INVALIDCURRENTVIEWPORT"; break;
    case (long)0x887602E0: name="D3DERR_INVALIDPRIMITIVETYPE"; break;
    case (long)0x887602E1: name="D3DERR_INVALIDVERTEXTYPE"; break;
    case (long)0x887602E2: name="D3DERR_TEXTURE_BADSIZE"; break;
    case (long)0x887602E3: name="D3DERR_INVALIDRAMPTEXTURE"; break;
    case (long)0x887602E4: name="D3DERR_MATERIAL_CREATE_FAILED"; break;
    case (long)0x887602E5: name="D3DERR_MATERIAL_DESTROY_FAILED"; break;
    case (long)0x887602E6: name="D3DERR_MATERIAL_SETDATA_FAILED"; break;
    case (long)0x887602E7: name="D3DERR_MATERIAL_GETDATA_FAILED"; break;
    case (long)0x887602E8: name="D3DERR_INVALIDPALETTE"; break;
    case (long)0x887602E9: name="D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY"; break;
    case (long)0x887602EA: name="D3DERR_ZBUFF_NEEDS_VIDEOMEMORY"; break;
    case (long)0x887602EB: name="D3DERR_SURFACENOTINVIDMEM"; break;
    case (long)0x887602EE: name="D3DERR_LIGHT_SET_FAILED"; break;
    case (long)0x887602EF: name="D3DERR_LIGHTHASVIEWPORT"; break;
    case (long)0x887602F0: name="D3DERR_LIGHTNOTINTHISVIEWPORT"; break;
    case (long)0x887602F8: name="D3DERR_SCENE_IN_SCENE"; break;
    case (long)0x887602F9: name="D3DERR_SCENE_NOT_IN_SCENE"; break;
    case (long)0x887602FA: name="D3DERR_SCENE_BEGIN_FAILED"; break;
    case (long)0x887602FB: name="D3DERR_SCENE_END_FAILED"; break;
    case (long)0x88760302: name="D3DERR_INBEGIN"; break;
    case (long)0x88760303: name="D3DERR_NOTINBEGIN"; break;
    case (long)0x88760304: name="D3DERR_NOVIEWPORTS"; break;
    case (long)0x88760305: name="D3DERR_VIEWPORTDATANOTSET"; break;
    case (long)0x88760306: name="D3DERR_VIEWPORTHASNODEVICE"; break;
    case (long)0x88760307: name="D3DERR_NOCURRENTVIEWPORT"; break;
    case 0: name="D3D_OK"; break;
    default: sub_006B20E0(text,result); return;
    }
    sub_00410610_WriteLogLine("***** Direct3D error: %s - %s (0x%x)",text,name,result);
}
