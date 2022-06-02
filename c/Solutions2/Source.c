#include <stdio.h>
#include <string.h>
#include <time.h>


void readFile(char* filename) {
    int returnCode;
    int count;

    FILE* stream;// , * stream2;
    errno_t err;

    err = fopen_s(&stream, filename, "r");
    if (err == 0)
        printf("Le fichier 'file.txt' est ouvert\n");
    else
        printf("Le fichier 'file.txt' n'est pas ouvert\n");

    fseek(stream, 0, SEEK_SET);

    char buffer[2] = {0};
    fread_s(buffer, 2 * sizeof(char), sizeof(char), 2, stream);
    buffer[1] = '\0';
    printf("%s", buffer);

    if (stream){
        err = fclose(stream);
        if (err == 0) 
            printf("\nLe fichier 'file.txt' est ferme\n");
        else 
            printf("\nLe fichier 'file.txt' n'est pas ferme\n");
    }
}   

int main() {
	//FILE* fp;
	//FILE* fp1;
	//char buffer[100];

	///* Open file for both reading and writing */
	////fp = fopen_s("file.txt", "w+");
	//fp1 = fopen_s(&fp, "file.txt", "r");

	///* Write data to the file */
	////fwrite(c, strlen(c) + 1, 1, fp1);

	///* Seek to the beginning of the file */
	////fseek(fp1, 0, SEEK_SET);

	///* Read and display data */
	//fread(buffer, 13, 1, fp1);
	//printf("%s\n", buffer);
	//fclose(fp1);

	//return(0);
    char* filename = "file.txt";
    readFile(filename);

    return 0;
}