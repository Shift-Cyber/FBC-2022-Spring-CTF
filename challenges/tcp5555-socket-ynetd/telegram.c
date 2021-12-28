#include <stdio.h>

int main()
{
	FILE *fptr;
	char flag[50] = { 0 };

	if ((fptr = fopen("./flag.txt","r")) == NULL) { return(1); }
	fscanf(fptr,"%s", &flag);
	fclose(fptr); 

	printf("%s", flag);

	return 0;
}
