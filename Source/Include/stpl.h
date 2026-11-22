#pragma once
// Storm's list and array templates: an intrusive doubly linked list whose terminator link carries the complemented
// address of the list head, and the base/fixed/growable arrays.

void* __stdcall SMemAlloc(unsigned int nBytes, const char* szFile, int nLine, unsigned int nFlags);
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nBytes, const char* szFile, int nLine, unsigned int nFlags);
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);

// The compiler's type descriptor (typeid); only its address is used here.
class type_info
{
public:
    virtual ~type_info();
private:
    void* _m_data;
    char _m_d_name[1];
    type_info(const type_info&);
    type_info& operator=(const type_info&);
};

// The decorated name of T's type descriptor, which the array templates pass to the allocator as the file name.
#define STORM_TYPENAME(T) ((const char*)&typeid(T) + 8)

template<class T> struct TSLink;
template<class T> struct TSGetLink;
template<class T, class TGetLink> struct TSList;
template<class T> struct TSCD;
template<class T> struct TSBaseArray;
template<class T, class TCD> struct TSFixedArray;
template<class T, class TCD> struct TSGrowableArray;

// The link a node embeds. m_next is the next node, or, on the last node, the complemented address of the
// terminator link; a list's terminator link points back at the first node the same way.
template<class T>
struct TSLink
{
    TSLink<T>* m_prevlink;                                  // 0x00
    T* m_next;                                              // 0x04

    TSLink()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~TSLink()
    {
        Unlink();
    }
    TSLink<T>* NextLink(int linkoffset)
    {
        if ((int)m_next < 0)
            return (TSLink<T>*)~(unsigned int)m_next;
        if (linkoffset < 0)
            linkoffset = (char*)this - (char*)m_prevlink->m_next;
        return (TSLink<T>*)((char*)m_next + linkoffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    T* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    T* RawNext()
    {
        return m_next;
    }
};

// The link-offset policy: the list keeps the offset of the link inside T in m_linkoffset.
template<class T>
struct TSGetLink
{
};

template<class T, class TGetLink = TSGetLink<T> >
struct TSList
{
    int m_linkoffset;                                       // 0x00
    TSLink<T> m_terminator;                                 // 0x04

    ~TSList()
    {
        UnlinkAll();
    }
    T* Head()
    {
        return m_terminator.Next();
    }
    TSLink<T>* Link(const T* ptr)
    {
        return (TSLink<T>*)((char*)ptr + m_linkoffset);
    }
    void UnlinkAll();
    void LinkNode(T* ptr, int linktype, T* existingptr);
    void UnlinkNode(T* ptr);
    T* NewNode(unsigned int linktype, unsigned int extrabytes, unsigned int flags);
    T* DeleteNode(T* ptr);
    void Clear();
};

// Construction/destruction policy of the arrays.
template<class T>
struct TSCD
{
};

template<class T>
struct TSBaseArray
{
    unsigned int m_alloc;                                   // 0x00
    unsigned int m_count;                                   // 0x04
    T* m_data;                                              // 0x08

    unsigned int Count() const
    {
        return m_count;
    }
    T& operator[](unsigned int index)
    {
        return m_data[index];
    }
};

template<class T, class TCD = TSCD<T> >
struct TSFixedArray : TSBaseArray<T>
{
    void ReallocData(unsigned int count)
    {
        this->m_alloc = count;
        if (this->m_data || count)
            this->m_data = (T*)SMemReAlloc(this->m_data, count * sizeof(T), STORM_TYPENAME(T), -2, 0);
    }
    void Set(unsigned int count, const T* data);
    TSFixedArray<T, TCD>& operator=(const TSFixedArray<T, TCD>& source)
    {
        if (this != &source)
            Set(source.m_count, source.m_data);
        return *this;
    }
};

template<class T, class TCD = TSCD<T> >
struct TSGrowableArray : TSFixedArray<T, TCD>
{
    unsigned int m_chunk;                                   // 0x0C

    static unsigned int __stdcall RoundUp(unsigned int value, unsigned int align)
    {
        unsigned int remainder = value % align;
        if (remainder)
            value += align - remainder;
        return value;
    }
    unsigned int CalcChunkSize(unsigned int count);
    void ReallocData(unsigned int count);
    void SetCount(unsigned int count)
    {
        if (count > this->m_count && count > this->m_alloc)
        {
            unsigned int chunk = m_chunk ? m_chunk : CalcChunkSize(count);
            ReallocData(RoundUp(count, chunk));
        }
        this->m_count = count;
    }
    TSGrowableArray<T, TCD>& operator=(const TSGrowableArray<T, TCD>& source)
    {
        if (this != &source)
            this->Set(source.m_count, source.m_data);
        m_chunk = source.m_chunk;
        return *this;
    }
};
