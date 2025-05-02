// File main.c
#include "auth.h"

int main(){
    // Konversi data user.csv ke arr dulu
    User users[MAX_USER];
    int jumlah_user;
    UserCSVtoArr(users,&jumlah_user);

    Pilihan pilihan;

    do {
        labelInput(&pilihan);

        switch(pilihan){
            case LOGIN: 
                login(users, &jumlah_user); 
                break;
            case REGISTER: 
                // fungsi register nanti
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
    return 0;
}