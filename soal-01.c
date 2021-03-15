/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul               : 4
*   Soal                : 1
*   Hari dan Tanggal    : 
*   Nama (NIM)          : 
*   Asisten (NIM)       : 
*   Nama File           : soal-01.c
*   Deskripsi           : Deskripsi file ini.
*/

// Header
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define defaultCapacity 2

typedef struct
{
    float x;
    float y;
    float z;
} Point;
typedef struct
{
    Point coordinate;
    float mass;
} Particle;

// Definisi dari fungsi yang digunakan

/*Alokasikan memori untuk dynamic array of Particle lalu 
return pointer dari elemen Particle pertama dari array tersebut*/
Particle *createArray(int arrayCapacity);
/*Masukan elemen Particle baru ke dalam array dinamis, perbesar ukuran array menjadi 
2x kapasitas awal jika kapasitas sudah penuh saat elemen baru ingin dimasukan*/
void pushToArray(Particle **array, Particle Add, int *idx, int *arrayCapacity);
/*Hitung center of mass dari kumpulan partikel sistem lalu hasilnya disimpan
pada output yang merupakan tipe data Point*/
void calculateCenterMass(Point *output, Particle *array, int *idx);

void main()
{
    // kapasitas array awal (jangan diganti)
    int arrayCapacity = defaultCapacity;
    int currIndex = 0;
    // Deklarasi array of Particle
    Particle *arrayOfParticle = createArray(arrayCapacity);
    Particle input;
    Point output;

    /*
    Isi implementasi baca input user dan 
    perhitungan center of mass disini
    */

    // Cetak solusi
    printf("\nPusat Massa:\n");
    printf("Koordinat x: %.2f\n", output.x);
    printf("Koordinat y: %.2f\n", output.y);
    printf("Koordinat z: %.2f\n", output.z);
    // Jangan lupa free memori yang sudah dialokasikan
    free(arrayOfParticle);
}

Particle *createArray(int arrayCapacity)
{
    /*Isi implementasi fungsinya disini*/
}
void pushToArray(Particle **array, Particle Add, int *idx, int *arrayCapacity)
{
    /*Isi implementasi fungsinya disini*/
}
void calculateCenterMass(Point *output, Particle *array, int *idx)
{
    /*Isi implementasi fungsinya disini*/
}
