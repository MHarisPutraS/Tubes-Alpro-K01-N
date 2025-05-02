// File auth.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef AUTH_H
#define AUTH_H

typedef enum{
    LOGIN=1,
    REGISTER,
    LUPAPASSWORD,
    EXIT
} Pilihan;

#define MAX_USER 100
#define MAX_LINE_LEN 1024

typedef struct {
    int id;
    char username[MAX_LINE_LEN];
    char password[MAX_LINE_LEN];
    char role[MAX_LINE_LEN];
    char riwayat_penyakit[MAX_LINE_LEN];
    
} Identitas;

typedef struct {
    float suhu_tubuh;
    int tekanan_darah_sistolik;
    int tekanan_darah_diastolik;
    int detak_jantung;
    float saturasi_oksigen;
    int kadar_gula_darah;
    float berat_badan;
    int tinggi_badan;
    int kadar_kolesterol;
    int kadar_kolesterol_ldl;
    int trombosit;

} KondisiPasien;

typedef struct {
    Identitas identitas;
    KondisiPasien kondisi;
} User;


void labelRS();
// Berisi label besar "RS K01-N" sebagai user interface

void labelMenu();
// Menampilkan user interface menu

void labelInput(Pilihan *pilihan);
// Menampilkan menu dan input sebagai UI utama

void login(User users[],int *jumlah_user);
// Procedure untuk login

void UserCSVtoArr(User users[], int *jumlah_user);

#endif