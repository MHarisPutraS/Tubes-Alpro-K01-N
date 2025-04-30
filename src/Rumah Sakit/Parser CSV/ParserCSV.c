#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user.h"

int main() {
    FILE *inputFile = fopen("../Data/user.csv", "r");
    if (inputFile == NULL) {
        perror("File tidak bisa dibuka");
        return 1;
    }

    char line[512];
    int userCount = 0;
    User arr[10];

    fgets(line, sizeof(line), inputFile); // Lewati baris header

    while (fgets(line, sizeof(line), inputFile) != NULL && userCount < 10) {
        char temp[64];
    }
    fclose(inputFile);
    return 0;
}
