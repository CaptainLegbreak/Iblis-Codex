// build: base-profile

#pragma pack(push,1)
struct T006C5B10 {
 unsigned short id;
 unsigned char encoding,bits;
 unsigned short xmin,ymin,xmax,ymax,hres,vres;
 unsigned char colorMap[48];
 unsigned char reserved,planes;
 unsigned short bytesPerLine;
 unsigned char rest[60];
};
struct D2PaletteStrc {unsigned char red,green,blue,flags;};
struct D2PcxRgbStrc {unsigned char red,green,blue;};
struct D2PcxPaletteBlockStrc {unsigned char marker; D2PcxRgbStrc colors[256];};
#pragma pack(pop)
void __stdcall sub_0041D300_Zero(void*,unsigned); // 0x0041D300
void* __stdcall sub_00413020_Alloc(unsigned,const char*,int,unsigned); // 0x00413020
int __stdcall sub_00412650_Free(void*,const char*,int,unsigned); // 0x00412650
extern const char gszSource_006FCC58[]; // 0x006FCC58
extern "C" __declspec(dllimport) int __stdcall WriteFile(void*,const void*,unsigned,unsigned*,void*);
static void sub_006C5B10_EncodeRow(unsigned char**,unsigned char**,int);

// 0x006C5B10
static __declspec(noinline) void sub_006C5B10_EncodeRow(unsigned char** destination,unsigned char** source,int remaining)
{
 do {
  unsigned char value=*(*source)++;
  int run=1;
  --remaining;
  while(remaining && value==**source && run<63) {
   --remaining;
   ++*source;
   ++run;
  }
  if(run>1 || value>=0xc0) *(*destination)++=(unsigned char)(0xc0|run);
  *(*destination)++=value;
 }while(remaining);
}
static __declspec(noinline) int __fastcall sub_006C5B60_WritePcx(int width,int height,void* file,D2PaletteStrc* colors,unsigned char* pixels);
// 0x006C5B60
static int __fastcall sub_006C5B60_WritePcx(int width,int height,void* file,D2PaletteStrc* colors,unsigned char* pixels)
{
 const int nWidth=width;
 T006C5B10 header;
 sub_0041D300_Zero(&header,sizeof(header));
 header.xmax=(unsigned short)(nWidth-1);
 header.ymax=(unsigned short)(height-1);
 header.id=0x050a;
 header.encoding=1;
 header.bits=8;
 header.hres=72;
 header.vres=72;
 header.planes=1;
 header.bytesPerLine=(unsigned short)nWidth;
 {
  unsigned written;
  WriteFile(file,&header,128,&written,0);
 }
 unsigned writtenData;
 unsigned char* encoded=(unsigned char*)sub_00413020_Alloc(height*nWidth*2,gszSource_006FCC58,0x4eb,0);
 unsigned char* source=pixels;
 unsigned char* dest=encoded;
 for(int row=0;row<height;++row) sub_006C5B10_EncodeRow(&dest,&source,nWidth);
 WriteFile(file,encoded,(unsigned)(dest-encoded),&writtenData,0);
 sub_00412650_Free(encoded,gszSource_006FCC58,0x4f2,0);
 D2PcxPaletteBlockStrc palette;
 palette.marker=12;
 for(int i=0;i<256;++i) {
  palette.colors[i].red=colors[i].red;
  palette.colors[i].green=colors[i].green;
  palette.colors[i].blue=colors[i].blue;
 }
 WriteFile(file,&palette,sizeof(palette),&writtenData,0);
 return 1;
}

// build: context sub_006C5B60_Shim
// calling-convention shim (not game code)
int __stdcall sub_006C5B60_Shim(int nHeight, int nWidth, void* hFile, D2PaletteStrc* pPalette, unsigned char* pPixels)
{
    return sub_006C5B60_WritePcx(nWidth, nHeight, hFile, pPalette, pPixels);
}
