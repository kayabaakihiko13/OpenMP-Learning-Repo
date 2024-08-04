# 00- Introduce
---

Parallel programming adalah teknik pemrograman yang memungkinkan eksekusi beberapa tugas secara bersamaan, sehingga meningkatkan efisiensi dan performa aplikasi. Salah satu alat yang sering digunakan untuk parallel programming di lingkungan pemrograman C dan C++ adalah OpenMP.

Untuk memulai program parallel dengan menggunakan library OpenMP, Anda dapat mengikuti contoh sederhana berikut ini:
<!-- contoh -->
```cpp
#include <stdio.h>
#include <omp.h>
int main(void){
    #pragma omp parallel
    {
        printf("Selamat");
        printf("Datang\n");
    }
    return 0;
}
```
header file pada code `omp.h`,dimana header ini diperlukan untuk menggunakan fitur-fitur OpenMP.

lalu pada openMP ini dimana ada penulisan code dengan menggunakan direktif,pada contoh diatas bisa diliat pada tulis `#pragma omp parallel`.Direktif ini memberitahu kompiler untuk menjalankan blok kode di dalam kurung kurawal `{}` secara paralel. Setiap thread akan mengeksekusi perintah-perintah di dalam blok ini.

<i>terus seperti apa output yang dihasilkan?</i>

output yang dihasilkan seperti ini
```bash
SelamatDatang
SelamatDatang
SelamatSelamatDatang
SelamatSelamatDatang
SelamatDatang
SelamatDatang
SelamatDatang
Datang
```
---
### <i>kenapa hasilnya tidak berurutan?</i>
---
Hasilnya tidak berurutan karena beberapa thread menjalankan kode secara bersamaan. Ketika thread-thread ini mengeksekusi printf, output dari masing-masing <i>thread</i> dapat saling bersilangan karena tidak ada sinkronisasi yang mengatur urutan eksekusi antar thread. Ini berarti bahwa satu thread dapat mulai mencetak "Selamat" sementara thread lain sudah mulai mencetak "Datang\n", sehingga menghasilkan output yang bercampur.
