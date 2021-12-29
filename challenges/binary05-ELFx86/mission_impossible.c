#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void defuse_bomb()
{
    int i;
    char flag[] = //
            "\x99\x93\x9e\x98\x84\x92\x96\x8c\x8c\x96\x90\x91\xa0\x91\x90\x8b\xa0"
            "\x8b\x97\x9e\x8b\xa0\x96\x92\x8f\x90\x8c\x8c\x96\x9d\x93\x9a\x82";
    
    //Deobfuscate the flag in place
	for (i=0; i<strlen(flag); i++) { flag[i] ^= 0xFF; }

    printf("\nMission accomplished! %s\n", flag);
}

int main()
{
    FILE *fio;
    unsigned long random_seed;
    int bomb_pin;
    int user_input;
    int scanf_status;
    

    /* Seed randomization from /dev/urandom */
    fio = fopen("/dev/urandom", "r");
    if (fio == NULL)
    {
        printf("\nSomething is broken... contact the author: Nate (helix)#8684\n");
    }
    else
    {
        fscanf(fio, "%lu", &random_seed);
        printf("%lu\n", random_seed);

        srand(random_seed);
    }

    /* Generate a random pin */
    bomb_pin = rand();

    /* Prompt for input */
    printf("The countdown is not helping... what's the pin to defuse the bomb?\n"
            "> ");
    fflush(stdout);

    /* Force a single valid integer */
    if (scanf_status = scanf("%d", &user_input) != 1 || user_input <= 0)
    {
        printf("\nThats not even a valid pin.... BOOM!");
        return 0;
    }

    /* Invalidate user input, should be relatively impossible*/
    if (user_input == bomb_pin)
    {
        defuse_bomb();
    }
    else
    {
        printf("\nIt was suicide from the start... BOOM!");
    }

    return 0;
}