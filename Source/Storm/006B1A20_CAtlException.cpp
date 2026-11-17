namespace ATL {
class CAtlException {
public:
    long m_hr;
    CAtlException(long hr);
};
}

// 0x006B1A20
ATL::CAtlException::CAtlException(long hr) : m_hr(hr)
{
}
