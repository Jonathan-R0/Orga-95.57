#include <stdio.h>
#include <string.h>
#define NROTESTS 3
#define RESET "\x1b[0m"
#define GREEN "\x1b[1m\x1b[32m"
#define RED "\x1b[1m\x1b[31m"

int my_strlen(char* a);

void tester(){

	char* testing_words[NROTESTS];
	testing_words[0] = "Son 4";
	testing_words[1] = "OchoCars";
	testing_words[2] = "Tengo 19 caracteres";
		
	for (int i = 0;i < NROTESTS;i++){
		if (strlen(testing_words[i]) == my_strlen(testing_words[i])){
			printf(GREEN"OK %s\n"RESET,testing_words[i]);
		} else {
			printf(RED"FAILED %s\n"RESET,testing_words[i]);
		}
	}
}

int main(void){
	tester();
	return 0;
}
