#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int level;
} Pasien;

typedef struct {
    int rear;
    int front;
    Pasien data[MAX_SIZE];
} Antrian;

void createEmpty(Antrian *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Antrian q) {
    return (q.rear == MAX_SIZE - 1);
}

int isEmpty(Antrian q) {
    return (q.front == -1);
}

void enqueue(Antrian *q, Pasien pasien) {
    if (isFull(*q)) {
        printf("Antrian penuh. Tidak dapat menambahkan pasien.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = pasien;
    }
}

Pasien dequeue(Antrian *q) {
    Pasien pasien;
    if (isEmpty(*q)) {
        printf("Antrian kosong. Tidak dapat menghapus pasien.\n");
        return pasien;
    } else {
        pasien = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return pasien;
    }
}

void handlePasien(Antrian *q) {
    Pasien pasien;
    while (!isEmpty(*q)) {
        pasien = dequeue(q);
        if (pasien.level <= 5) {
            printf("Pasien dengan tingkat %d ditangani oleh dokter umum.\n", pasien.level);
        } else {
            printf("Pasien dengan tingkat %d ditangani oleh dokter spesialis.\n", pasien.level);
        }
    }
}

int main() {
    Antrian q;
    createEmpty(&q);
    int tingkatPasien;

    printf("Masukkan tingkat pasien:\n");

    // Menambahkan pasien dengan input dari pengguna
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Pasien %d: ", i + 1);
        scanf("%d", &tingkatPasien);
        enqueue(&q, (Pasien){tingkatPasien});
    }

    handlePasien(&q);

    return 0;
}
