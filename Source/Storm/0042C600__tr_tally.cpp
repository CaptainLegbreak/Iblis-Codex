struct z_stream;

struct ct_data
{
    unsigned short freq;
    unsigned short dad;
};

struct deflate_state
{
    z_stream* strm;
    char pad04[0x90];
    ct_data dyn_ltree[573];
    ct_data dyn_dtree[61];
    char padA7C[0xC1C];
    unsigned char* l_buf;
    unsigned int lit_bufsize;
    unsigned int last_lit;
    unsigned short* d_buf;
    unsigned long opt_len;
    unsigned long static_len;
    unsigned int matches;
    unsigned int insert;
    unsigned short bi_buf;
    char pad16BA[0x2];
    int bi_valid;
    char pad16C0[0x4];
};

extern "C" const unsigned char _dist_code[];                                                                // 0x006D13D8
extern "C" const unsigned char _length_code[];                                                              // 0x006D15D8

// build: symbol ?_tr_tally@@YIHPAUdeflate_state@@II@Z 0x0042C600
int __fastcall _tr_tally(deflate_state* s, unsigned int dist, unsigned int lc)
{
    s->d_buf[s->last_lit] = (unsigned short)dist;
    s->l_buf[s->last_lit++] = (unsigned char)lc;
    if (dist == 0) {
        s->dyn_ltree[lc].freq++;
    } else {
        s->matches++;
        dist--;
        s->dyn_ltree[_length_code[lc] + 256 + 1].freq++;
        unsigned int code;
        if (dist < 256)
            code = _dist_code[dist];
        else
            code = _dist_code[256 + (dist >> 7)];
        s->dyn_dtree[code].freq++;
    }
    return (s->last_lit == s->lit_bufsize - 1);
}
