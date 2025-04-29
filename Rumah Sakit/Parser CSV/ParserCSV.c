#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("user.csv", "r");
    if (inputFile == NULL) {
        perror("File tidak bisa dibuka");
        return 1;
    }

    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        
    }
    fclose(inputFile);
    return 0;
}
