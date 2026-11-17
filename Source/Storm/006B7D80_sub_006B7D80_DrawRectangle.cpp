struct D2RectStrc { int left; int top; int right; int bottom; };
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern const char gszEmpty_006CC837[]; // 0x006CC837
extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
void __fastcall sub_006B7B30_DrawLine(int,int,int,int,int,int); // 0x006B7B30
#define ASSERT(expr,line) if (!(expr)) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),line); exit(-1); }
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
// 0x006B7D80
void __fastcall sub_006B7D80_DrawRectangle(D2RectStrc* rect,int color) {
    ASSERT(rect->left<=rect->right,235);
    ASSERT(rect->top<=rect->bottom,236);
    int left=MIN(MAX(rect->left,0),gnWidth_007C9138-1);
    int right=MIN(MAX(rect->right,0),gnWidth_007C9138-1);
    if (left==right) return;
    int top=MIN(MAX(rect->top,0),gnHeight_007C913C-1);
    int bottom=MIN(MAX(rect->bottom,0),gnHeight_007C913C-1);
    if (top==bottom) return;
    ASSERT(bottom>top,252);
    sub_006B7B30_DrawLine(left,top,right,top,color,255);
    sub_006B7B30_DrawLine(right,top,right,bottom,color,255);
    sub_006B7B30_DrawLine(right,bottom,left,bottom,color,255);
    sub_006B7B30_DrawLine(left,bottom,left,top,color,255);
}
