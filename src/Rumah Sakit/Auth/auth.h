#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    LOGIN=1,
    REGISTER,
    LUPAPASSWORD,
    EXIT
} Pilihan;

void labelRS();
// Berisi label besar "RS K01-N" sebagai user interface

void labelMenu();
// Menampilkan user interface menu

void labelPilihan();
// Bersisi label ">>>Pilihan" sesuai pilihan yang dipilih dari menu

void login();
// Procedure untuk login