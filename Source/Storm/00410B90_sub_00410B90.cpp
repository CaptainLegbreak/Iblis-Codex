typedef unsigned char Byte;
typedef unsigned int Word;
enum { ROUND_BITS = 7, TAIL_HIGH = 2 };
// 0x00410B90
void __stdcall sub_00410B90(const Byte* first,const Byte* second,Byte* output,int bitCount)
{
    bitCount=(bitCount+ROUND_BITS)/8;
    int wholeBytes=(bitCount/4)*4;
    int i=0;
    for (;i<wholeBytes;i+=4) *(Word*)(output+i)=*(const Word*)(first+i)&*(const Word*)(second+i);
    switch (bitCount-wholeBytes) {
    case 3: output[i+TAIL_HIGH]=first[i+TAIL_HIGH]&second[i+TAIL_HIGH];
    case 2: output[i+1]=first[i+1]&second[i+1];
    case 1: output[i]=first[i]&second[i];
    }
}
