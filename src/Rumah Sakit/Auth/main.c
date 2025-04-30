#include "auth.h"

int main(){

    Pilihan pilihan;

    labelRS();
    labelMenu();
    scanf("%d",(int*)&pilihan);
    labelPilihan(pilihan);
}