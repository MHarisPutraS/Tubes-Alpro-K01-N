// File main.c
#include "auth.h"

// Definisi Global
User *users = NULL;
int jumlah_user = 0;

int main(){
    // Konversi data user.csv ke arr dulu
    users = (User *)malloc(MAX_USER * sizeof(User));
    if (users == NULL){
        perror("gagal membuat array");
        return 1;
    }

    jumlah_user=0;
    ParseTarget pt = {users, &jumlah_user};
    CSVtoArr("../../../data/user.csv",handleUserRow,&pt);
    users = (User *)realloc(users, jumlah_user * sizeof(User));
    if (users == NULL){
        perror("gagal membuat array");
        return 1;
    }

    Pilihan pilihan;

    do {
        labelInput(&pilihan);

        switch(pilihan){
            case LOGIN: 
                login(users); 
                break;
            case REGISTER: 
                registerpasien(&users,&jumlah_user);
                break;
            case LUPAPASSWORD: 
                // fungsi lupa password nanti
                break;
        }

        if (pilihan != EXIT) {
            printf("\nTekan Enter untuk kembali ke menu...");
            getchar(); getchar(); // pause
        }

    } while(pilihan != EXIT);

    printf("\nTerima kasih telah menggunakan sistem! <3\n\n");

    // for(int i=0;i<jumlah_user;i++){
        // printf("%s",users[i].identitas.username);
    // }
    
    return 0;
}