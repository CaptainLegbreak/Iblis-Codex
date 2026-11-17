struct D2StormHuffInputStrc {
 unsigned char* input; unsigned int bits,count;
 unsigned int Peek7() {
  if(count<=7) { bits|=*(unsigned short*)input<<count; count+=16; input+=2; }
  return bits&127;
 }
 unsigned int GetBit() {
  unsigned int value=bits&1;
  bits>>=1;
  if(!--count) { bits=*(unsigned int*)input; input+=4; count=32; }
  return value;
 }
 void Skip(unsigned int n) { bits>>=n; count-=n; }
};
struct D2StormHuffItemStrc { D2StormHuffItemStrc* next; D2StormHuffItemStrc* prev; unsigned int value,weight; D2StormHuffItemStrc* parent; D2StormHuffItemStrc* child; };
struct D2StormHuffCacheStrc { unsigned int generation,bits; union { unsigned int value; D2StormHuffItemStrc* node; }; };
struct D2StormHuffTreeStrc {
 int isCmp0; unsigned int generation; char unknown008[0x3058]; D2StormHuffItemStrc* head; char unknown3064[0x410]; D2StormHuffCacheStrc cache[128];
 unsigned int sub_0041EBC0_DecodeOne(D2StormHuffInputStrc*);
 D2StormHuffItemStrc* First() {
  D2StormHuffItemStrc* item=head->next->prev;
  return (int)item>0?item:0;
 }
};
// 0x0041EBC0
unsigned int D2StormHuffTreeStrc::sub_0041EBC0_DecodeOne(D2StormHuffInputStrc* input)
{
 unsigned int prefix=input->Peek7();
 D2StormHuffCacheStrc* entry=&cache[prefix];
 int cached=entry->generation==generation;
 D2StormHuffItemStrc* node;
 if(cached) {
  if(entry->bits>7) { input->Skip(7); node=entry->node; }
  else { input->Skip(entry->bits); return entry->value; }
 } else node=First();
 unsigned int depth=0;
 D2StormHuffItemStrc* seventh=0;
 do {
  node=node->child;
  if(input->GetBit()) node=node->prev;
  ++depth;
  if(depth==7) seventh=node;
 } while(node->child);
 if(!cached) {
  if(depth>7) {
   entry->generation=generation;
   entry->bits=depth;
   entry->node=seventh;
  } else {
   unsigned int index=prefix&(0xFFFFFFFF>>(32-depth));
   unsigned int step=1<<depth;
   do {
    D2StormHuffCacheStrc* e=&cache[index];
    e->generation=generation;
    e->bits=depth;
    e->value=node->value;
    index+=step;
   } while(index<=127);
  }
 }
 return node->value;
}
