// 0x006C76C0
unsigned char* __stdcall sub_006C76C0_EncodeUtf8(unsigned int code,unsigned char* out)
{
 if (out) {
 unsigned char finalByte=(unsigned char)code;
 unsigned char lead;
 if (code<0x80) goto last;
 if (code<0x800) { lead=(unsigned char)(code>>6)|0xc0; goto two; }
 if (code<0x10000) { lead=(unsigned char)(code>>12)|0xe0; goto three; }
 if (code<0x200000) { lead=(unsigned char)(code>>18)|0xf0; goto four; }
 if (code<0x400000) { lead=(unsigned char)(code>>24)|0xf8; goto five; }
 if (code>=0x80000000) goto done;
 lead=(unsigned char)(code>>30)|0xfc;
 *out++=lead;
 lead=((unsigned char)(code>>24)&0x3f)|0x80;
five:
 *out++=lead;
 lead=((unsigned char)(code>>18)&0x3f)|0x80;
four:
 *out++=lead;
 lead=((unsigned char)(code>>12)&0x3f)|0x80;
three:
 *out++=lead;
 lead=((unsigned char)(code>>6)&0x3f)|0x80;
two:
 *out++=lead;
 finalByte=((unsigned char)code&0x3f)|0x80;
last:
 *out++=finalByte;
done:
 *out=0;
 }
 return out;
}
