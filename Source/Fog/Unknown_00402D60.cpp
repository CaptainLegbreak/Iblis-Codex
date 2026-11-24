#include "D2CrashTypes.h"
struct D2StackFrameStrc { void* address; char unknown004[12]; unsigned char hasArgs; char unknown011[3]; void* args[4]; };
extern "C" int __cdecl _snprintf_s(char*,unsigned int,unsigned int,const char*,...); // 0x006824CB
static void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output);

// 0x00402D60
static void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output)
{
 char args[80];
 output[0]=0;
 args[0]=0;
 if(frame->hasArgs)
  _snprintf_s(args,80,(unsigned int)-1," (%p,%p,%p,%p)",frame->args[0],frame->args[1],frame->args[2],frame->args[3]);
 if(!symbol->szName[0]) {
  _snprintf_s(output,1024,(unsigned int)-1,"DBG-ADDR<%p>(\"%s\")%s",frame->address,symbol->szModule,args);
  return;
 }
 int length=_snprintf_s(output,1024,(unsigned int)-1,"%p %s",frame->address,symbol->szModule);
 int padding=21-length;
 if(padding>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,"%*s",padding," ");
 if(symbol->szName[0] || symbol->nOffset>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1," %s+%llu",symbol->szName,(unsigned __int64)symbol->nOffset);
 length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,"%s",args);
 if(symbol->szSource[0] || symbol->nLine>0)
  _snprintf_s(output+length,1024-length,(unsigned int)-1," (%s,%u)",symbol->szSource,symbol->nLine);
}

// build: context sub_00402D60_Shim
// calling-convention shim (not game code)
void __stdcall sub_00402D60_Shim(const D2StackFrameStrc* frame, const D2SymbolInfoStrc* symbol, char* output)
{
    __declspec(align(8)) char szLine[0x400];
    sub_00402D60_FormatStackFrame(frame, symbol, szLine);
    output[0] = szLine[0];
}
