

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void add(char * tag)
{
	int sum = 0;
	int i =0;
	int size; 
	for(i=0 ; i< 1057;i++)
	{
		sum = sum + tag[i];
	}
	
	int j;
	j = sum%[HASH_TABLE_SIZE];
}
