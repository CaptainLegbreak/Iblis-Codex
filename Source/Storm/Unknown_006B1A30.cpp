namespace ATL {
class CAtlException {
public:
    long m_hr;
    CAtlException(long hr) : m_hr(hr) {}
};
}
// build: symbol __TI1?AVCAtlException@ATL@@ 0x007020B4
// 0x006B1A30
void __cdecl sub_006B1A30_ThrowAtlException(long error)
{
    throw ATL::CAtlException(error);
}
