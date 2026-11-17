enum { NO_NODE = 0 };
struct Link {
    Link* previous;
    char* next;
    char* sub_00417770();
};

// 0x00417770
char* Link::sub_00417770() { return (int)next<=NO_NODE ? 0 : next; }
