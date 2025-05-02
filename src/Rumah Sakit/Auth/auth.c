// File auth.c
#include "auth.h"

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

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

void labelInput(Pilihan *pilihan){
    int input;
    int valid = 0;

    while (!valid) {
        clearScreen();
        labelRS();
        labelMenu();
        printf(">>> Masukkan pilihan (1-4): ");
        scanf("%d", &input);
        if (input != 1 && input != 2 && input != 3 && input != 4){
            // input bukan angka
            while(getchar() != '\n'); // flush input buffer
            printf("\nInput tidak valid! Masukkan angka antara 1-4.");
            printf("\nSilahkan enter untuk mengulang!\n");
            getchar(); // tunggu enter
            continue;
        }

        switch (input) {
            case 1: case 2: case 3:
                *pilihan = input;
                valid = 1;
                break;
            case 4:
                *pilihan = EXIT;
                valid = 1;
                break;
            default:
                printf("\nPilihan tidak valid! Silakan ulangi.\n");
                getchar(); // tunggu enter
        }
    }

    char *opsi[] = {"", "LOGIN", "REGISTER", "LUPAPASSWORD"};
    if (*pilihan != EXIT)
        printf("\n>>> %s\n\n", opsi[*pilihan]);
}

void login(User users[],int *jumlah_user){
    User user;int valid=0; char nama[50],role[50];

    printf("Username: ");
    scanf("%s", user.identitas.username);
    strcpy(nama,user.identitas.username);
    printf("Password: ");
    scanf("%s", user.identitas.password);
    for (int i = 0; i < *jumlah_user; i++) {
        if (strcmp(users[i].identitas.username, user.identitas.username) == 0 &&
            strcmp(users[i].identitas.password, user.identitas.password) == 0) {
            valid = 1; 
            strcpy(role,users[i].identitas.role);
            break;
        }
    }

    if (!valid) {
        printf("\nTidak ada Manager, Dokter, atau pun Pasien yang bernama %s!\n\n",nama);
    }
    else
    {if(strcmpi(role,"pasien")==0){
        printf("\nSelamat pagi %s! Ada keluhan apa?\n\n",nama);
    }else{
    printf("\nSelamat pagi %s %s! \n\n",role,nama);}}
}

void UserCSVtoArr(User users[], int *jumlah_user){
    FILE *file = fopen("../../../data/user.csv", "r");

    if (!file) {
        perror("Gagal membuka file");
        exit(1);
    }

    char line[MAX_LINE_LEN];
    fgets(line, sizeof(line), file); // Skip header

    int idx = 0;
    while (fgets(line, sizeof(line), file)) {
        int col = 0, charIdx = 0;
        char temp[50] = "";
        User user = {0};
        int len = strlen(line);
        line[len - 1] = '\0'; // Hapus newline

        for (int i = 0; i <= len; i++) {
            if (line[i] == ',' || line[i] == '\0') {
                temp[charIdx] = '\0';

                switch (col) {
                    case 0: user.identitas.id = atoi(temp); break;
                    case 1: strcpy(user.identitas.username, temp); break;
                    case 2: strcpy(user.identitas.password, temp); break;
                    case 3: strcpy(user.identitas.role, temp); break;
                    case 4: strcpy(user.identitas.riwayat_penyakit, temp); break;
                    case 5: user.kondisi.suhu_tubuh = atof(temp); break;
                    case 6: user.kondisi.tekanan_darah_sistolik = atoi(temp); break;
                    case 7: user.kondisi.tekanan_darah_diastolik = atoi(temp); break;
                    case 8: user.kondisi.detak_jantung= atoi(temp); break;
                    case 9: user.kondisi.saturasi_oksigen = atof(temp); break;
                    case 10: user.kondisi.kadar_gula_darah = atoi(temp); break;
                    case 11: user.kondisi.berat_badan = atof(temp); break;
                    case 12: user.kondisi.tinggi_badan = atoi(temp); break;
                    case 13: user.kondisi.kadar_kolesterol = atoi(temp); break;
                    case 14: user.kondisi.kadar_kolesterol_ldl = atoi(temp); break;
                    case 15: user.kondisi.trombosit = atoi(temp); break;
                }

                col++;
                charIdx = 0;
                temp[0] = '\0';
            } else {
                temp[charIdx++] = line[i];
            }
        }

        users[idx++] = user;
    }

    *jumlah_user = idx;
    fclose(file);
}