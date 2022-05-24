#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readFile(char* filename) {
	FILE* stream;
	errno_t err;

	err = fopen_s(&stream, filename, "r");
	if (err == 0)
		printf("Le fichier 'file.txt' est ouvert\n");
	else
		printf("Le fichier 'file.txt' n'est pas ouvert\n");

	fseek(stream, 0, SEEK_SET);

	char* value = "";
	value = fgetc(stream);
	printf("%c", value);
	
	if (stream) {
		err = fclose(stream);
		if (err == 0)
			printf("\nLe fichier 'file.txt' est ferme\n");
		else
			printf("\nLe fichier 'file.txt' n'est pas ferme\n");
	}
	return value;
}

int main() {
	char* p = "";
	char* premier = "\"";
	char* deuxieme = "\"";
	p = readFile("../c/Solution1/algo_labyrinthe/CaCLC.csv");
	printf("p = %s", p);
}