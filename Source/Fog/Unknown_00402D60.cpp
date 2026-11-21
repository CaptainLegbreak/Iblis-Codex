struct D2StackFrameStrc { void* address; char unknown004[12]; unsigned char hasArgs; char unknown011[3]; void* args[4]; };
struct D2SymbolInfoStrc { char name[512]; unsigned int offset; char module[64]; char source[256]; unsigned int line; };
extern const char gszArgsFormat[]; // 0x006FFC14
extern const char gszUnresolvedFormat[]; // 0x006FFC24
extern const char gszAddressFormat[]; // 0x006FFC3C
extern const char gszEmpty[]; // 0x006FFC44
extern const char gszPaddingFormat[]; // 0x006FFC48
extern const char gszSymbolFormat[]; // 0x006FFC4C
extern const char gszStringFormat[]; // 0x006FFC58
extern const char gszSourceFormat[]; // 0x006FFC5C
extern "C" int __cdecl _snprintf_s(char*,unsigned int,unsigned int,const char*,...); // 0x006824CB
static void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output);

// 0x00402D60
static void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output)
{
 char args[80];
 output[0]=0;
 args[0]=0;
 if(frame->hasArgs)
  _snprintf_s(args,80,(unsigned int)-1,gszArgsFormat,frame->args[0],frame->args[1],frame->args[2],frame->args[3]);
 if(!symbol->name[0]) {
  _snprintf_s(output,1024,(unsigned int)-1,gszUnresolvedFormat,frame->address,symbol->module,args);
  return;
 }
 int length=_snprintf_s(output,1024,(unsigned int)-1,gszAddressFormat,frame->address,symbol->module);
 int padding=21-length;
 if(padding>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,gszPaddingFormat,padding,gszEmpty);
 if(symbol->name[0] || symbol->offset>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,gszSymbolFormat,symbol->name,(unsigned __int64)symbol->offset);
 length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,gszStringFormat,args);
 if(symbol->source[0] || symbol->line>0)
  _snprintf_s(output+length,1024-length,(unsigned int)-1,gszSourceFormat,symbol->source,symbol->line);
}

// build: context sub_00402D60_Shim
// calling-convention shim (not game code)
void __stdcall sub_00402D60_Shim(const D2StackFrameStrc* frame, const D2SymbolInfoStrc* symbol, char* output)
{
    __declspec(align(8)) char szLine[0x400];
    sub_00402D60_FormatStackFrame(frame, symbol, szLine);
    output[0] = szLine[0];
}
