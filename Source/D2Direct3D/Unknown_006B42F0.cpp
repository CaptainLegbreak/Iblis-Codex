typedef unsigned int DWORD;
typedef int HRESULT;
struct GUID { DWORD a,b,c,d; };
struct DDCAPS { DWORD size,caps,caps2; DWORD rest0C[12]; DWORD videoTotal,videoFree; DWORD rest44[78]; };
struct DDSCAPS2 { DWORD caps,caps2,caps3,caps4; };
struct DDSURFACEDESC2 { DWORD size,flags,height,width,pitch,backCount,mipCount,alphaDepth,reserved; void* surface; DWORD colorKeys[8]; DWORD pixelFormat[8]; DDSCAPS2 caps; DWORD textureStage; };
struct D3DDEVICEDESC { DWORD size,flags,colorModel,devCaps; DWORD rest10[29]; DWORD textureCaps,textureFilterCaps; DWORD rest8C[28]; };
struct DDDEVICEIDENTIFIER { char driver[512]; char description[512]; unsigned __int64 driverVersion; DWORD vendor,device,subsys,revision; GUID identifier; };
struct D2DisplayModeStrc { int flags,bpp,width,height,refresh; };
struct D2RendererInfoStrc { DWORD flags; GUID guid; DWORD vendor,device; char description[256]; DWORD videoTotal,videoFree,textureTotal,textureFree,localTotal,localFree,agpTotal,agpFree; D2DisplayModeStrc modes[32]; int modeCount; };
struct D2RendererSelectionStrc { DWORD flags; GUID guid; DWORD vendor,device; char description[256]; int renderer; };
struct IDirectDraw; struct IDirectDraw4; struct IDirectDrawSurface4; struct IDirect3D3; struct IDirect3DDevice3;
struct IUnknownVtbl {
 HRESULT (__stdcall* QueryInterface)(IDirectDraw*,const GUID*,void**);
 DWORD (__stdcall* AddRef)(IDirectDraw*);
 DWORD (__stdcall* Release)(IDirectDraw*);
};
struct IDirectDraw { IUnknownVtbl* vtbl; };
struct IDirectDraw4Vtbl {
 HRESULT (__stdcall* QueryInterface)(IDirectDraw4*,const GUID*,void**);
 DWORD (__stdcall* AddRef)(IDirectDraw4*);
 DWORD (__stdcall* Release)(IDirectDraw4*);
 void* methods03[3];
 HRESULT (__stdcall* CreateSurface)(IDirectDraw4*,DDSURFACEDESC2*,IDirectDrawSurface4**,void*);
 void* method07;
 HRESULT (__stdcall* EnumDisplayModes)(IDirectDraw4*,DWORD,DDSURFACEDESC2*,void*,int(__stdcall*)(DDSURFACEDESC2*,void*));
 void* methods09[2];
 HRESULT (__stdcall* GetCaps)(IDirectDraw4*,DDCAPS*,DDCAPS*);
 void* methods12[8];
 HRESULT (__stdcall* SetCooperativeLevel)(IDirectDraw4*,void*,DWORD);
 HRESULT (__stdcall* SetDisplayMode)(IDirectDraw4*,DWORD,DWORD,DWORD,DWORD,DWORD);
 void* method22;
 HRESULT (__stdcall* GetAvailableVidMem)(IDirectDraw4*,DDSCAPS2*,DWORD*,DWORD*);
 void* methods24[3];
 HRESULT (__stdcall* GetDeviceIdentifier)(IDirectDraw4*,DDDEVICEIDENTIFIER*,DWORD);
};
struct IDirectDraw4 { IDirectDraw4Vtbl* vtbl; };
struct IDirectDrawSurface4Vtbl {
 void* methods00[2];
 DWORD (__stdcall* Release)(IDirectDrawSurface4*);
 void* methods03[9];
 HRESULT (__stdcall* GetAttachedSurface)(IDirectDrawSurface4*,DDSCAPS2*,IDirectDrawSurface4**);
};
struct IDirectDrawSurface4 { IDirectDrawSurface4Vtbl* vtbl; };
struct IDirect3D3Vtbl {
 void* methods00[2];
 DWORD (__stdcall* Release)(IDirect3D3*);
 void* methods03[5];
 HRESULT (__stdcall* CreateDevice)(IDirect3D3*,const GUID*,IDirectDrawSurface4*,IDirect3DDevice3**,void*);
};
struct IDirect3D3 { IDirect3D3Vtbl* vtbl; };
struct IDirect3DDevice3Vtbl {
 void* methods00[2];
 DWORD (__stdcall* Release)(IDirect3DDevice3*);
 HRESULT (__stdcall* GetCaps)(IDirect3DDevice3*,D3DDEVICEDESC*,D3DDEVICEDESC*);
 void* methods04[4];
 HRESULT (__stdcall* EnumTextureFormats)(IDirect3DDevice3*,int(__stdcall*)(void*,void*),void*);
};
struct IDirect3DDevice3 { IDirect3DDevice3Vtbl* vtbl; };
typedef char CheckCapsSize[sizeof(DDCAPS)==0x17c?1:-1];
typedef char CheckDescSize[sizeof(DDSURFACEDESC2)==0x7c?1:-1];
typedef char CheckD3DCapsSize[sizeof(D3DDEVICEDESC)==0xfc?1:-1];
typedef char CheckIdentifierSize[sizeof(DDDEVICEIDENTIFIER)==0x428?1:-1];
typedef char CheckRendererSize[sizeof(D2RendererInfoStrc)==0x3c0?1:-1];
extern "C" char* __cdecl sub_00687330_Strncpy(char*,const char*,unsigned int); // 0x00687330
extern "C" void __cdecl LOGMANAGER_WriteLogLine(const char*,...); // 0x00410610
void __cdecl FOG_GetSystemInfo(); // 0x00407360
extern "C" HRESULT __stdcall sub_006B1350_DirectDrawCreate(GUID*,IDirectDraw**,void*); // 0x006B1350
void __fastcall sub_006B20E0_DDrawLogError(const char*,HRESULT) throw(); // 0x006B20E0
void __fastcall sub_006B39B0_ShowD3DError(const char* text,long result); // 0x006B39B0
int __stdcall sub_006B3FD0(DDSURFACEDESC2*,void*); // 0x006B3FD0
int __stdcall sub_006B1B60_EnumTextureFormat(void*,void*); // 0x006B1B60
extern IDirectDraw4* gpDirectDraw4; // 0x00970E60
extern IDirect3D3* gpDirect3D3; // 0x00970E64
extern void* ghEnumerationWindow; // 0x00970E84
extern int gnDisplayCount; // 0x00970E88
extern D2RendererInfoStrc gaDisplays[2]; // 0x009706C0
extern D2RendererSelectionStrc gPrimarySelection; // 0x0096F720
extern D2RendererSelectionStrc gSecondarySelection; // 0x0096F840
extern int gnPrimaryRenderer; // 0x0096F3A4
extern int gnSecondaryRenderer; // 0x0096F3A0
extern const GUID gIIDDirectDraw4; // 0x006FF8D8
extern const GUID gIIDDirect3D3; // 0x006FF558
extern const GUID gIIDHardwareDevice; // 0x006FF518
extern const DWORD gFlag_006CE268; // 0x006CE268
extern const DWORD gdwBitMask1; // 0x006CE26C
extern const DWORD gFlag_006CE270; // 0x006CE270
extern const DWORD gdwBitMask3; // 0x006CE274
extern const DWORD gFlag_006CE278; // 0x006CE278
extern const DWORD gFlag_006CE27C; // 0x006CE27C
extern const DWORD gFlag_006CE284; // 0x006CE284
extern const DWORD gFlag_006CE288; // 0x006CE288
extern const DWORD gFlag_006CE28C; // 0x006CE28C
extern const DWORD gFlag_006CE2E8; // 0x006CE2E8
extern const char gszEnumD3DCleanupFailed[]; // 0x006FB8A4
extern const char gszEnumD3DCaughtFailure[]; // 0x006FB8D4
extern const char gszNoTriangleSupport[]; // 0x006FB908
extern const char gszPassedRequirements[]; // 0x006FB928
extern const char gszNoTextureFormats[]; // 0x006FB950
extern const char gszSupports1555Textures[]; // 0x006FB98C
extern const char gszEnumTextureFormatsFailed[]; // 0x006FB9A8
extern const char gszNoAgpTexturing[]; // 0x006FB9C4
extern const char gszAgpMemoryFormat[]; // 0x006FB9F4
extern const char gszAgpMemoryFailed[]; // 0x006FBA1C
extern const char gszLocalMemoryFormat[]; // 0x006FBA48
extern const char gszLocalMemoryFailed[]; // 0x006FBA74
extern const char gszTextureMemoryFormat[]; // 0x006FBAA4
extern const char gszTextureMemoryFailed[]; // 0x006FBAD8
extern const char gszVideoMemoryFormat[]; // 0x006FBB00
extern const char gszNoMipmapping[]; // 0x006FBB30
extern const char gszRequiresSquareTextures[]; // 0x006FBB50
extern const char gszNoPerspectiveTextures[]; // 0x006FBB6C
extern const char gszSupportsNonPow2Textures[]; // 0x006FBBA0
extern const char gszNoVideoMemoryTextures[]; // 0x006FBBC8
extern const char gszGetD3DDeviceCapsFailed[]; // 0x006FBBF4
extern const char gszNoHardware3D[]; // 0x006FBC14
extern const char gszSupportsGammaCalibration[]; // 0x006FBC44
extern const char gszNoGammaControl[]; // 0x006FBC64
extern const char gszNo3DSupport[]; // 0x006FBC88
extern const char gszGetDD4CapsFailed[]; // 0x006FBCA8
extern const char gszGetBackbufferFailed[]; // 0x006FBCC0
extern const char gszCreatePrimarySurfaceFailed[]; // 0x006FBCE4
extern const char gszSetDisplayModeCall[]; // 0x006FBD08
extern const char gszNoGameDisplayMode[]; // 0x006FBD24
extern const char gszNoUIDisplayMode[]; // 0x006FBD5C
extern const char gszSupports24BitCutscenes[]; // 0x006FBD9C
extern const char gszSupports32BitCutscenes[]; // 0x006FBDBC
extern const char gszNoValidDisplayModes[]; // 0x006FBDDC
extern const char gszEnumDisplayModesCall[]; // 0x006FBE08
extern const char gszSetCooperativeLevelFailed[]; // 0x006FBE28
extern const char gszGetD3DInterfaceFailed[]; // 0x006FBE44
extern const char gszVendorDeviceIdFormat[]; // 0x006FBE60
extern const char gszCheckingCapabilitiesFormat[]; // 0x006FBE88
extern const char gszEnumGetDirectDraw4Failed[]; // 0x006FBEA8
extern const char gszEnumDirectDrawCreateFailed[]; // 0x006FBED8
extern const char gszMaxDisplayCountFormat[]; // 0x006FBEFC

extern "C" char* __cdecl strcpy(char*, const char*);
#pragma intrinsic(strcpy)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)
// 0x006B42F0
int __stdcall sub_006B42F0_EnumerateD3DDevices(GUID* guid,char* description,char* name,void* context)
{
 IDirectDraw* dd=0;
 DDCAPS caps={sizeof(caps)};
 IDirectDrawSurface4* primary=0;
 IDirectDrawSurface4* back=0;
 IDirect3DDevice3* device=0;
 gpDirectDraw4=0;
 gpDirect3D3=0;
 try {
  FOG_GetSystemInfo();
  int index=gnDisplayCount;
  if(index>=2) { LOGMANAGER_WriteLogLine(gszMaxDisplayCountFormat,index,2); return 0; }
  D2RendererInfoStrc* display=&gaDisplays[index];
  memset(display,0,0x134);
  if(!guid) display->flags|=gFlag_006CE268;
  else { display->flags&=gFlag_006CE2E8; display->guid=*guid; }
  HRESULT hr=sub_006B1350_DirectDrawCreate(guid,&dd,0);
  if(hr) { sub_006B20E0_DDrawLogError(gszEnumDirectDrawCreateFailed,hr); goto Cleanup; }
  hr=dd->vtbl->QueryInterface(dd,&gIIDDirectDraw4,(void**)&gpDirectDraw4);
  if(hr) { sub_006B20E0_DDrawLogError(gszEnumGetDirectDraw4Failed,hr); goto Cleanup; }
  dd->vtbl->Release(dd); dd=0;

  DDDEVICEIDENTIFIER aIdentifier[2];
  DDDEVICEIDENTIFIER& identifier=aIdentifier[0];
  hr=gpDirectDraw4->vtbl->GetDeviceIdentifier(gpDirectDraw4,&identifier,0);
  if(!hr) sub_00687330_Strncpy(display->description,identifier.description,256); else sub_00687330_Strncpy(display->description,name,256);
  LOGMANAGER_WriteLogLine(gszCheckingCapabilitiesFormat,display->description);
  if(!hr) {
   display->vendor=identifier.vendor; display->device=identifier.device;
   LOGMANAGER_WriteLogLine(gszVendorDeviceIdFormat,display->vendor,display->device);
  }
  hr=gpDirectDraw4->vtbl->QueryInterface(gpDirectDraw4,&gIIDDirect3D3,(void**)&gpDirect3D3);
  if(hr) { sub_006B20E0_DDrawLogError(gszGetD3DInterfaceFailed,hr); goto Cleanup; }
  hr=gpDirectDraw4->vtbl->SetCooperativeLevel(gpDirectDraw4,ghEnumerationWindow,0x11);
  if(hr) { sub_006B20E0_DDrawLogError(gszSetCooperativeLevelFailed,hr); goto Cleanup; }
  hr=gpDirectDraw4->vtbl->EnumDisplayModes(gpDirectDraw4,0,0,display,sub_006B3FD0);
  if(hr) { sub_006B20E0_DDrawLogError(gszEnumDisplayModesCall,hr); goto Cleanup; }
  if(!display->modeCount) { LOGMANAGER_WriteLogLine(gszNoValidDisplayModes); goto Cleanup; }
  int hasUI=0,hasGame=0,has32=0,has24=0;
  int invalid=0;
  for(int i=0;i<display->modeCount;++i) {
   if(display->modes[i].flags&gFlag_006CE270) has32=1;
   if(display->modes[i].flags&gdwBitMask3) has24=1;
   if(display->modes[i].flags&gFlag_006CE268) hasUI=1;
   if(display->modes[i].flags&gdwBitMask1) hasGame=1;
  }
  if(has32) { LOGMANAGER_WriteLogLine(gszSupports32BitCutscenes); display->flags|=gFlag_006CE284; }
  if(has24) { LOGMANAGER_WriteLogLine(gszSupports24BitCutscenes); display->flags|=gFlag_006CE288; }
  if(!hasUI) { LOGMANAGER_WriteLogLine(gszNoUIDisplayMode); invalid=1; }
  if(!hasGame) { LOGMANAGER_WriteLogLine(gszNoGameDisplayMode); goto Cleanup; }
  if(invalid) goto Cleanup;
  D2DisplayModeStrc* mode=&display->modes[display->modeCount-1];
  hr=gpDirectDraw4->vtbl->SetDisplayMode(gpDirectDraw4,mode->width,mode->height,mode->bpp,mode->refresh,0);
  if(hr) { sub_006B20E0_DDrawLogError(gszSetDisplayModeCall,hr); goto Cleanup; }
  DDSURFACEDESC2 surface={sizeof(surface)};
  surface.flags=0x21;surface.caps.caps=0x6218;surface.backCount=1;
  hr=gpDirectDraw4->vtbl->CreateSurface(gpDirectDraw4,&surface,&primary,0);
  if(hr) { sub_006B20E0_DDrawLogError(gszCreatePrimarySurfaceFailed,hr); goto Cleanup; }
  DDSCAPS2 attachCaps;memset(&attachCaps,0,sizeof(attachCaps));attachCaps.caps=4;
  hr=primary->vtbl->GetAttachedSurface(primary,&attachCaps,&back);
  if(hr) { sub_006B20E0_DDrawLogError(gszGetBackbufferFailed,hr); goto Cleanup; }
  hr=gpDirectDraw4->vtbl->GetCaps(gpDirectDraw4,&caps,0);
  if(hr) { sub_006B20E0_DDrawLogError(gszGetDD4CapsFailed,hr); goto Cleanup; }
  if(!(caps.caps&1)) { LOGMANAGER_WriteLogLine(gszNo3DSupport); goto Cleanup; }
  if(caps.caps2&0x20000) display->flags|=gFlag_006CE278;
  else LOGMANAGER_WriteLogLine(gszNoGammaControl);
  if(caps.caps2&0x100000) { display->flags|=gFlag_006CE27C; LOGMANAGER_WriteLogLine(gszSupportsGammaCalibration); }
  gpDirect3D3->vtbl->CreateDevice(gpDirect3D3,&gIIDHardwareDevice,back,&device,0);
  if(!device) { LOGMANAGER_WriteLogLine(gszNoHardware3D); goto Cleanup; }
  D3DDEVICEDESC hardware,software;
  hardware.size=sizeof(hardware);software.size=sizeof(software);
  hr=device->vtbl->GetCaps(device,&hardware,&software);
  if(hr) { sub_006B39B0_ShowD3DError(gszGetD3DDeviceCapsFailed,hr); goto Cleanup; }
  if(!(hardware.devCaps&0x200)) { LOGMANAGER_WriteLogLine(gszNoVideoMemoryTextures); goto Cleanup; }
  if(hardware.textureCaps&0x100) LOGMANAGER_WriteLogLine(gszSupportsNonPow2Textures);
  if(hardware.flags&0x40) {
  if(!(hardware.textureCaps&1)) LOGMANAGER_WriteLogLine(gszNoPerspectiveTextures);
  if(hardware.textureCaps&0x20) { LOGMANAGER_WriteLogLine(gszRequiresSquareTextures); display->flags|=gFlag_006CE270; goto Cleanup; }
  if(hardware.textureFilterCaps&0x20) display->flags|=gdwBitMask3;
  else LOGMANAGER_WriteLogLine(gszNoMipmapping);
  display->videoTotal=caps.videoTotal;display->videoFree=caps.videoFree;
  LOGMANAGER_WriteLogLine(gszVideoMemoryFormat,display->videoTotal/1048576.0f,display->videoFree/1048576.0f);
  DDSCAPS2 memoryCaps;memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x5000;
  hr=gpDirectDraw4->vtbl->GetAvailableVidMem(gpDirectDraw4,&memoryCaps,&display->textureTotal,&display->textureFree);
  if(hr) { sub_006B20E0_DDrawLogError(gszTextureMemoryFailed,hr); goto Cleanup; }
  LOGMANAGER_WriteLogLine(gszTextureMemoryFormat,display->textureTotal/1048576.0f,display->textureFree/1048576.0f);
  memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x10005000;
  hr=gpDirectDraw4->vtbl->GetAvailableVidMem(gpDirectDraw4,&memoryCaps,&display->localTotal,&display->localFree);
  if(hr) { sub_006B20E0_DDrawLogError(gszLocalMemoryFailed,hr); goto Cleanup; }
  LOGMANAGER_WriteLogLine(gszLocalMemoryFormat,display->localTotal/1048576.0f,display->localFree/1048576.0f);
  if((caps.caps2&0x200)&&(hardware.devCaps&0x1000)) {
   display->flags|=gdwBitMask1;
   memset(&memoryCaps,0,sizeof(memoryCaps));memoryCaps.caps=0x20005000;
   hr=gpDirectDraw4->vtbl->GetAvailableVidMem(gpDirectDraw4,&memoryCaps,&display->agpTotal,&display->agpFree);
   if(hr) sub_006B20E0_DDrawLogError(gszAgpMemoryFailed,hr);
   else LOGMANAGER_WriteLogLine(gszAgpMemoryFormat,display->agpTotal/1048576.0f,display->agpFree/1048576.0f);
  } else LOGMANAGER_WriteLogLine(gszNoAgpTexturing);
  hr=device->vtbl->EnumTextureFormats(device,sub_006B1B60_EnumTextureFormat,display);
  if(hr) { sub_006B39B0_ShowD3DError(gszEnumTextureFormatsFailed,hr); goto Cleanup; }

  int textures=0;
  if(display->flags&gFlag_006CE28C) { LOGMANAGER_WriteLogLine(gszSupports1555Textures); textures=1; }
  if(!textures) { LOGMANAGER_WriteLogLine(gszNoTextureFormats); goto Cleanup; }
  if(gnDisplayCount==0) {
   gPrimarySelection.flags=display->flags;gPrimarySelection.guid=display->guid;
   gPrimarySelection.vendor=display->vendor;gPrimarySelection.device=display->device;
   strcpy(gPrimarySelection.description,display->description);
   gPrimarySelection.renderer=2;gnPrimaryRenderer=2;
  } else if(gnDisplayCount==1) {
   gSecondarySelection.flags=display->flags;gSecondarySelection.guid=display->guid;
   gSecondarySelection.vendor=display->vendor;gSecondarySelection.device=display->device;
   strcpy(gSecondarySelection.description,display->description);
   gSecondarySelection.renderer=2;gnSecondaryRenderer=2;
  }
  ++gnDisplayCount;LOGMANAGER_WriteLogLine(gszPassedRequirements);

  } else LOGMANAGER_WriteLogLine(gszNoTriangleSupport);
 } catch(...) {
  LOGMANAGER_WriteLogLine(gszEnumD3DCaughtFailure);
  if(!gnDisplayCount) gPrimarySelection.renderer=0;
  else if(gnDisplayCount==1) gSecondarySelection.renderer=0;
 }
Cleanup:
 try {
  if(device) { device->vtbl->Release(device);device=0; }
  if(back) back=0;
  if(primary) { primary->vtbl->Release(primary);primary=0; }
  if(gpDirect3D3) { gpDirect3D3->vtbl->Release(gpDirect3D3);gpDirect3D3=0; }
  if(gpDirectDraw4) { gpDirectDraw4->vtbl->Release(gpDirectDraw4);gpDirectDraw4=0; }
 } catch(...) { LOGMANAGER_WriteLogLine(gszEnumD3DCleanupFailed); }
 return 1;
}

#include "gen/data/Source/D2Direct3D/Unknown_006B42F0.inc"
