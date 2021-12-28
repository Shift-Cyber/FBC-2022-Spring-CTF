#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define USER_INPUT_LENGTH 50

/* We are writing intentionally bugged code, suppress overflow warnings */
#pragma GCC diagnostic ignored "-Wstringop-overflow="


char flag_1[] = /* Flag XOR\xFF "FBC{WOAH_you_shouldnt_be_able_to_overwrite_THAT}" */
	"\xb9\xbd\xbc\x84\xa8\xb0\xbe\xb7\xa0\x86\x90\x8a\xa0\x8c\x97"
	"\x90\x8a\x93\x9b\x91\x8b\xa0\x9d\x9a\xa0\x9e\x9d\x93\x9a\xa0"
	"\x8b\x90\xa0\x90\x89\x9a\x8d\x88\x8d\x96\x8b\x9a\xa0\xab\xb7"
	"\xbe\xab\x82";

char flag_2[] = /* Flag XOR\xFF "FBC{now_this_REALLY_seems_like_a_problem}" */
	"\xb9\xbd\xbc\x84\x91\x90\x88\xa0\x8b\x97\x96\x8c\xa0\xad\xba"
	"\xbe\xb3\xb3\xa6\xa0\x8c\x9a\x9a\x92\x8c\xa0\x93\x96\x94\x9a"
	"\xa0\x9e\xa0\x8f\x8d\x90\x9d\x93\x9a\x92\x82";

void win_function() {execve("/bin/sh", 0, 0);}

/**
 * @fn challenge_stacked
 * @brief First challenge, basic stack overflow to overwrite the target with anything
 * 
 * @param user_input Pointer to the location that data should being written to
 * @param critical_data Pointer to the target to overwrite
 *
 * @return Pass fail status of the challenge
 */
int challenge_stacked(char *user_input, unsigned long *critical_data)
{
	unsigned int i;
	char tmpbuffer[1024] = {0};
	
	printf("> There is critical data on the stack in a variable beyond your input...\n"
		   ">   ...the variable currently holds the value  > 0x%04x\n"
		   "> This app sure is buggy, eh?: ", *critical_data);

	fflush(stdout);
	
	/* This is easier than trying to flush STDIN some other way */
	fgets(tmpbuffer, sizeof(tmpbuffer), stdin);

	/* An extra 5 bytes? How generous! */
	snprintf((char *)user_input, USER_INPUT_LENGTH + 5, tmpbuffer);

	/* stack was smashed, pay the prize */
	if (*critical_data != 0xdeadbeef)
	{
		/* Deobfuscate the flag in place */
		for (i=0; i<strlen(flag_1); i++) {flag_1[i] ^= 0xFF;}

		putchar('\n');
		printf("> Now that variable holds the value  > 0x%04x, fascinating...\n"
			   ">   Congrats, you smashed the stack: %s\n", *critical_data, flag_1);

		return 1;
	}

	putchar('\n');
	return 0;
}

/**
 * @fn challenge_ready_aim_fire
 * @brief Second challenge, stack overflow to overwrite the target with specific non-printable bytes
 * 
 * @param user_input Pointer to the location that data should being written to
 * @param critical_data Pointer to the target to overwrite
 *
 * @return Pass fail status of the challenge
 */
int challenge_ready_aim_fire(char *user_input, unsigned long *critical_data)
{
	unsigned int i;
	char tmpbuffer[1024] = {0};
	
	printf("> Alright well thats cool or whatever, but since was written in a coffee shop...\n"
		   ">   ...lets make the secret sauce 0xcafed00d instead, it currently holds  > 0x%04x\n"
		   "> Hit me baby one more time: ", *critical_data);
	fflush(stdout);

	/* This is easier than trying to flush STDIN some other way */
	fgets(tmpbuffer, sizeof(tmpbuffer), stdin);

	/* An extra 5 bytes? How generous! */
	snprintf((char *)user_input, USER_INPUT_LENGTH + 5, tmpbuffer);

	putchar('\n');

	/* If stack was smashed with finess, pay the prize */
	if (*critical_data == 0xcafed00d)
	{
		//Deobfuscate the flag in place
		for (i=0; i<strlen(flag_2); i++) {flag_2[i] ^= 0xFF;}

		printf("\n> Now the secret sauce is  > 0x%04x, incredible!\n"
			   ">   Congrats, you smashed the stack... with finess ;)\n"
			   ">   Here's your prize: %s\n", *critical_data, flag_2);

		return 1;
	}
	
	return 0;
}

/**
 * @fn challenge_return_of_the_king
 * @brief Third challenge, stack overflow to overwrite the instruction pointer with &win_function
 */
void challenge_return_of_the_king()
{
	char a_small_buffer[50] = {0};
	printf("> If you can get the win_function() to run, you will get a shell on the target.\n"
		   "> We no longer care about the variable on the stack and this time you can\n"
		   "> write as much data as your heart desires. How can you hijack the program to\n"
		   "> return to the win_function() located at: 0x%04x, and get a shell?: ", &win_function);
	fflush(stdout);
			   
	fgets(a_small_buffer,4096,stdin);
}

int main() 
{
	unsigned int i;
	unsigned long critical_data = 0xdeadbeef;
	char user_input[USER_INPUT_LENGTH] = { 0 };
	
	while(challenge_stacked(&user_input[0], &critical_data) == 0);
	putchar('\n');

	while(challenge_ready_aim_fire(&user_input[0], &critical_data) == 0);
	putchar('\n');

	challenge_return_of_the_king(&user_input[0], &critical_data);

	return 0;
}
