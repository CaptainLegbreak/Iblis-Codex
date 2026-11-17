struct D2QuadVertexStrc { float x,y,z,rhw; unsigned int color,specular; float s,t; };
struct D2GridVertexStrc { float x,y,unknown08,unknown0C,s,t,unknown18,unknown1C; };
struct D2FixedPointStrc { int x,y,unknown08; };
struct D2FixedShapeStrc { D2FixedPointStrc points[6]; };
D2QuadVertexStrc gaQuadVertices[4];        // 0x00971630
extern D2GridVertexStrc gaGridVertices[5][3]; // 0x00971458
extern int gaFixedShapes[10][6][3]; // 0x0074C100
// 0x006B80A0
void __cdecl sub_006B80A0_InitializeDrawingGeometry()
{
 gaQuadVertices[0].x=0.0f;gaQuadVertices[0].y=0.0f;gaQuadVertices[0].z=0.5f;gaQuadVertices[0].rhw=1.0f;
 gaQuadVertices[0].s=0.0f;gaQuadVertices[0].t=0.0f;
 gaQuadVertices[1].x=0.0f;gaQuadVertices[1].y=0.0f;gaQuadVertices[1].z=0.5f;gaQuadVertices[1].rhw=1.0f;
 gaQuadVertices[1].s=0.0f;gaQuadVertices[1].t=1.0f;
 gaQuadVertices[2].x=0.0f;gaQuadVertices[2].y=0.0f;gaQuadVertices[2].z=0.5f;gaQuadVertices[2].rhw=1.0f;
 gaQuadVertices[2].s=1.0f;gaQuadVertices[2].t=1.0f;
 gaQuadVertices[3].x=0.0f;gaQuadVertices[3].y=0.0f;gaQuadVertices[3].z=0.5f;gaQuadVertices[3].rhw=1.0f;
 gaQuadVertices[3].s=1.0f;gaQuadVertices[3].t=0.0f;
 for(int row=0;row<5;++row) {
  float t=(float)(row*0.984375*0.25+0.015625);
  for(int column=0;column<3;++column) {
   gaGridVertices[row][column].x=0.5f;
   gaGridVertices[row][column].y=1.0f;
   gaGridVertices[row][column].s=(float)(column*0.984375*0.5+0.015625);
   gaGridVertices[row][column].t=t;
  }
 }
 for(int index=0;index<10;++index) {
  for(int point=0;point<6;++point) {
   int* pPoint=gaFixedShapes[index][point];
   pPoint[0]<<=16;
   pPoint[1]<<=16;
  }
 }
}
