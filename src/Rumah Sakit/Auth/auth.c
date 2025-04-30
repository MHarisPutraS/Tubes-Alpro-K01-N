#include "auth.h"
#include "user.h"

void labelRS(){
    printf("=====================================\n");
    printf("           RUMAH SAKIT K01-N         \n");
    printf("=====================================\n");
}

void labelMenu(){
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. LupaPassword\n");
    printf("4. Exit\n");
    printf("\n");
}

void labelPilihan(Pilihan pilihan){
    char opsi[50]; int valid=0;

    while(!valid){
        switch(pilihan){
            case LOGIN: strcpy(opsi,"LOGIN"); valid=1; break;
            case REGISTER: strcpy(opsi,"REGISTER"); valid=1; break;
            case LUPAPASSWORD: strcpy(opsi,"LUPAPASSWORD"); valid=1; break;
            default: 
            printf("Opsi tidak valid, ulangi:\n");
            scanf("%d",(int*)&pilihan);
        }
    }
    printf("\n");
    printf(">>> %s\n", opsi);
}

void login(){
    User user; int valid=0;

    labelRS();
    do{
    printf("Username: ");
    scanf("%s",&user.identitas.username);
    printf("Password: ");
    scanf("%s",&user.identitas.password);
    }while(!valid);
}