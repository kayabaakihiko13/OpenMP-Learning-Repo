02 - Parallel Computing
---
Komputasi paralel adalah sebuah konsep dalam ilmu komputer di mana beberapa perhitungan atau eksekusi proses dilakukan secara bersamaan. Idenya adalah memecah masalah komputasi yang besar menjadi bagian-bagian lebih kecil yang dapat diproses secara bersamaan, sehingga dapat menyelesaikan tugas lebih cepat dibandingkan dengan pemrosesan sekuensial (satu per satu).

Konsep ini dapat diilustrasikan sebagai berikut:

![ilustrasi komputasi paralel](image/image.png)

Pada gambar di atas, kita dapat melihat perbedaan antara pemrosesan sekuensial (serial) dan paralel. Dalam pemrosesan sekuensial, tugas-tugas dieksekusi satu per satu, sedangkan dalam pemrosesan paralel, beberapa tugas dapat dieksekusi secara bersamaan, menghasilkan waktu penyelesaian yang lebih cepat.

Komputasi paralel memungkinkan pemanfaatan sumber daya komputasi yang lebih efisien dan dapat secara signifikan meningkatkan kinerja untuk tugas-tugas yang dapat dibagi menjadi operasi-operasi independen yang lebih kecil.
```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int SIZE = 1000000;
    std::vector<int> numbers(SIZE);

    // Inisialisasi array
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }

    long long sum = 0;

    // Mulai penghitungan paralel
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }

    std::cout << "Jumlah: " << sum << std::endl;

    return 0;
}
```
menarik dalam kode diatas ialah terdapat direktif `#pragma omp parallel for`,direktif tersebut digunakan untuk memparalelkan loop for.
selain itu,terdapat race condition yaitu `reduction(+:sum)`,kode tersebut digunakan untuk  menghindari race condition saat menjumlahkan ke variabel .