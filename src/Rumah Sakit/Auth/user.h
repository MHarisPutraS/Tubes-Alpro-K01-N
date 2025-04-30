#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    PASIEN=1,
    DOKTER,
    MANAGER
} Role;

typedef enum{
    INFLUENZA=1,
    COVID19,
    HIPERTENSI,
    DIABETESMELLITUS,
    ANEMIA
} RiwayatPenyakit;

typedef struct {
    int id;
    char username[50];
    char password[50];
    Role role;
    RiwayatPenyakit riwayat;
    
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