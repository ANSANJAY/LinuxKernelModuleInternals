#include <stdio.h>

int oldname = 5;

extern int newname __attribute__((alias("oldname")));

int main()
{
	printf("Value of new name is :%d\n", newname);
	return 0;
}
