#define id_len 100
#define tab_size 100

typedef struct {
	char id[id_len];
	char type;
	int size;
	int displacement;
} symTabEntry;

extern symTabEntry ste[tab_size];
extern int lastInd;


