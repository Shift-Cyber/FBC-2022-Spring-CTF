#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char user_input[100] = {0};
    char flag[] = //Flag XOR\xFF "FBC{this_is_where_it_all_begins}"
		"\xb9\xbd\xbc\x84\x8b\x97\x96\x8c\xa0\x96\x8c\xa0\x88\x97\x9a\x8d"
        "\x9a\xa0\x96\x8b\xa0\x9e\x93\x93\xa0\x9d\x9a\x98\x96\x91\x8c\x82";

    //Decode the flag in place
	for (i=0; i<strlen(flag); i++) { flag[i] ^= 0xFF; }

    while(1)
    {
        printf("What is the entry point of this binary (like 0x1070)?: ");

        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(user_input, "0x10a0") == 0 || strcmp(user_input, "0x10A0") == 0)
        {
            printf("Correct! %s", flag);
            break;
        }
        else
        {
            printf("That's not right?? :(\n\n");
        }
    }

    return 0;
}