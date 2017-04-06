


typedef struct node {
	char gender;
	char name[7];
	char id[9];
	int score;
} node ;

node raw[100];
void ReadTable(int n);
void PrintTable(int n,node pt[]);
void CopyTable();
int cmpStruct(const node *firstStructPtr, const node *secondStructPtr, void *wayPtr);

