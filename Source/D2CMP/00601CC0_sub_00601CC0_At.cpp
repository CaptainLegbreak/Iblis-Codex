struct D2StormLinkStrc {D2StormLinkStrc* m_prevlink; char* m_next;};
struct D2CommonStormSlotListAStrc {int m_linkoffset; D2StormLinkStrc m_terminator;};
struct D2CommonStormSlotArrayAStrc {
 unsigned int m_alloc,m_count;
#ifdef MOVED_TEST
 int movedGap;
#endif
 D2CommonStormSlotListAStrc* m_data;
 unsigned int m_chunk;
 D2CommonStormSlotListAStrc* sub_00601CC0_At(unsigned int index);
};
// 0x00601CC0
D2CommonStormSlotListAStrc* D2CommonStormSlotArrayAStrc::sub_00601CC0_At(unsigned int index) {return &m_data[index];}
