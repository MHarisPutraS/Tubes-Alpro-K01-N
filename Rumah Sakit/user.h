#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    Identitas User;
    KondisiPasien User;
} User;

typedef enum{
    Pasien,
    Dokter,
    Manager
} Role;

typedef enum{
    Sehat,
    Influenza,
    COVID19,
    Hipertensi,
    DiabetesMellitus,
    Anemia
} RiwayatPenyakit;

typedef struct {
    int id;
    int username;
    int password;
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