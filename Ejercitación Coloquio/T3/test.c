#include <stdio.h>
#include <string.h>

#define NROTESTSLEN 3
#define NROTESTSCMP 3

#define RESET "\x1b[0m"
#define GREEN "\x1b[1m\x1b[32m"
#define RED "\x1b[1m\x1b[31m"

int my_strlen(char* a);
int my_strcmp(char* a, char* b);

void strlen_tester(){

	printf("TEST STRLEN: \n");
	char* testing_words0 = "A";
	char* testing_words1 = "OchoCars";
	char* testing_words2 = "Tengo 19 caracteres";
	char* testing_words[3] = {testing_words0,testing_words1,testing_words2};
		
	for (int i = 0;i < NROTESTSLEN;i++){
		int expected = (int)strlen(testing_words[i]);
		int result   = my_strlen(testing_words[i]);
		if (expected == result){
			printf(GREEN"OK\n"RESET);
		} else {
			printf(RED"FAILED %s - EXPECTED: %d AND GOT: %d\n"RESET,testing_words[i],expected,result);
		}
	}
}

void strcmp_tester(){
	
	printf("\nTEST STRCMP: \n");
	char* testing_words[NROTESTSCMP];
	testing_words[0] = "Son4";
	testing_words[1] = "OchoCars";
	testing_words[2] = "Tengo 19 caracteres";

	for (int i = 0;i < NROTESTSCMP;i++){
		for (int j = 0;j < NROTESTSCMP;j++){
			int expected = strcmp(testing_words[i],testing_words[j]);
			int result   = my_strcmp(testing_words[i],testing_words[j]);
			if (result == expected || result * expected >= 0 /*Solo nos importa el signo en esta implementación*/)
				printf(GREEN"OK\n"RESET);
			else
				printf(RED"FAILED %s & %s - EXPECTED: %d AND GOT: %d\n"RESET,testing_words[i],testing_words[j],expected,result);
		}
	}
}

int main(void){
	strlen_tester();
	strcmp_tester();
	return 0;
}
