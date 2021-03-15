/*
Usulan Soal M4 David
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
    int lanjut;
    // Baca input partikel dari user sampai diberikan input 0 saat pertanyaan lanjut?
    do
    {
        printf("Partikel ke-%d!\n", currIndex + 1);
        printf("Massa: ");
        scanf("%f", &input.mass);
        printf("Koordinat x: ");
        scanf("%f", &input.coordinate.x);
        printf("Koordinat y: ");
        scanf("%f", &input.coordinate.y);
        printf("Koordinat z: ");
        scanf("%f", &input.coordinate.z);
        printf("Lanjut?: ");
        pushToArray(&arrayOfParticle, input, &currIndex, &arrayCapacity);
        scanf("%d", &lanjut);
    } while (lanjut);
    // Kalkulasi center of mass dengan memodifikasi isi Point output untuk keluarannya
    calculateCenterMass(&output, arrayOfParticle, &currIndex);
    printf("\nPusat Massa:\n");
    // Cetak solusi
    printf("Koordinat x: %.2f\n", output.x);
    printf("Koordinat y: %.2f\n", output.y);
    printf("Koordinat z: %.2f\n", output.z);
    printf("Kapasitas Array: %d\n", arrayCapacity);
    // Jangan lupa free memori yang sudah dialokasikan
    free(arrayOfParticle);
}

Particle *createArray(int arrayCapacity)
{
    return (Particle *)malloc(arrayCapacity * sizeof(Particle));
}
void pushToArray(Particle **array, Particle Add, int *idx, int *arrayCapacity)
{
    if (*idx >= *arrayCapacity)
    {
        (*arrayCapacity) *= 2;
        *array = (Particle *)realloc(*array, (*arrayCapacity) * sizeof(Particle));
    }
    (*array)[*idx] = Add;
    (*idx)++;
}
void calculateCenterMass(Point *output, Particle *array, int *idx)
{
    float xSum = 0, ySum = 0, zSum = 0, mSum = 0;
    for (int i = 0; i < *idx; i++)
    {
        xSum += array[i].coordinate.x * array[i].mass;
        ySum += array[i].coordinate.y * array[i].mass;
        zSum += array[i].coordinate.z * array[i].mass;
        mSum += array[i].mass;
    }
    output->x = xSum / mSum;
    output->y = ySum / mSum;
    output->z = zSum / mSum;
}
