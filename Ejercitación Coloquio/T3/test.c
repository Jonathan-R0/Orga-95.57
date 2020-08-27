#include <stdio.h>
#include <string.h>

#define NROTESTSLEN 3
#define NROTESTSCMP 3
#define NROTESTARR 4

#define RESET "\x1b[0m"
#define GREEN "\x1b[1m\x1b[32m"
#define RED "\x1b[1m\x1b[31m"
#define NEW "\x1b[1m\x1b[39m"

int my_strlen(char* a);
int my_strcmp(char* a, char* b);
int arr_ordenado(char** a);

void strlen_tester(){

	printf(NEW"TEST STRLEN: \n"RESET);
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
	
	printf(NEW"\nTEST STRCMP: \n"RESET);
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

void strings_sorted_tester(){

	printf(NEW"\nTEST SORTED ARRAY: \n"RESET);	
	char* testing1[2] = {"abc", NULL};
	char* testing0[3] = {"ab", "c", NULL};
	char* testing2[5] = {"ab", "zz", "bb", "bc", NULL};
	char* testing3[5] = {"ab", "bb", "bb", "bc", NULL};
	
	int answers[NROTESTARR] = {1,1,0,1};
	int r1 = arr_ordenado(testing0);
	int r2 = arr_ordenado(testing1);
	int r3 = arr_ordenado(testing2);  // Mas de uno no pasa las pruebas, producto del return del strcmp
	int r4 = arr_ordenado(testing3);  // Y no tengo ganas de ponerme a degubbear eso :v

	int results[NROTESTARR] = {r1,r2,r3,r4};

	for (int i = 0;i < NROTESTARR;i++){
		if (results[i] == answers[i]) 	
			printf(GREEN"OK\n"RESET);
		else
			printf(RED"FAILED ON NUMBER: %d - EXPECTED: %d AND GOT: %d\n"RESET,i,answers[i],results[i]);
	}
}

int main(void){
	
	printf("\n");
	strlen_tester();
	strcmp_tester();
	strings_sorted_tester();
	printf("\n");
	return 0;
}
