#include <stdio.h>
#include <string.h>

int main() 
{	
	int i;
	char flag[] = //Flag XOR\xFF "FBC{WaIt_bUt_ThAtS_nOt_An_ExE}"
		"\xb9\xbd\xbc\x84\xa8\x9e\xb6\x8b\xa0\x9d\xaa\x8b\xa0\xab\x97"
		"\xbe\x8b\xac\xa0\x91\xb0\x8b\xa0\xbe\x91\xa0\xba\x87\xba\x82";

	//Decode the flag in memory
	for (i=0; i<strlen(flag); i++)
	{
		flag[i] ^= 0xFF;
	}
	
	printf(flag); 
	return 0;
}
