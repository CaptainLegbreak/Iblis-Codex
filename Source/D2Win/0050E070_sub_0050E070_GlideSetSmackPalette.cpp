struct D2RgbColorStrc { unsigned char red,green,blue; };
extern unsigned char* gpGlideSmackBuffer_00880BF0; // 0x00880BF0
extern unsigned char* gpGlideSmackBufferB_00880B70; // 0x00880B70
extern unsigned char* gpGlideSmackBufferC_00880B74; // 0x00880B74
static unsigned short PackRgb565(int red, int green, int blue)
{
 unsigned short packed=red;
 packed &= ~7;
 packed=(unsigned short)((packed<<5)|(unsigned char)(green & 252));
 packed=(unsigned short)((packed<<3)|(unsigned char)(blue>>3));
 return packed;
}
// 0x0050E070
void __fastcall sub_0050E070_GlideSetSmackPalette(D2RgbColorStrc* colors)
{
 const unsigned char* source=gpGlideSmackBuffer_00880BF0;
 unsigned short* left=(unsigned short*)gpGlideSmackBufferB_00880B70;
 unsigned short* right=(unsigned short*)gpGlideSmackBufferC_00880B74;
 for(int y=0;y<64;++y){
  for(int x=0;x<256;++x){
   const int nLeftIndex=source[x];
   left[x]=PackRgb565(colors[nLeftIndex].red,colors[nLeftIndex].green,colors[nLeftIndex].blue);
   const int nRightIndex=source[x+256];
   right[x]=PackRgb565(colors[nRightIndex].red,colors[nRightIndex].green,colors[nRightIndex].blue);
  }
  source+=512;left+=256;right+=256;
 }
}
