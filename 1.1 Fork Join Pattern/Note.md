# Fork Join Pattern

### 1.1.1 The Fork-Join Pattern

didalam OpenMP,kita memulai Fork-Join pattern parallel sebagai berikut

![Fork-Join Pattern](..\image\ForkJoin.png)

Dalam diagram di atas, kita dapat melihat bagaimana thread utama memecah dirinya menjadi beberapa thread anak. Masing-masing thread anak akan mengerjakan sebagian dari beban kerja total, sehingga komputasi dapat diselesaikan dengan lebih cepat.
Setelah semua thread anak selesai menjalankan tugas masing-masing, mereka akan "bergabung" (join) kembali dengan thread utama. Pada tahap ini, thread utama akan menunggu hingga semua thread anak telah selesai sebelum melanjutkan eksekusi kode selanjutnya.

block `#pragma omp parallel`merupakan block untuk melakukan set terhadap thread untuk mengeksekusi pada program tersebut.
hasil block `#pragma omp parallel` mengakibatkan hasil outputnya secara random alias asyncronus.

- sequential
---
```cpp
#include<iostream>
#include<omp.h>

int main(){
    printf("\n Sebelumnya \n");
    // #pragma omp parallel
    printf("\n During \n");
    printf("\n Sesudah \n");
    return 0;
}
```


- concurency Example

```cpp
#include<iostream>
#include<omp.h>
int main(){
    #pragma omp parallel
    printf("\n During \n")
    return 0;
}
```

- for SPMD example

```cpp
#include<iostream>
#include<omp.h>
int main(){
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int num = omp_get_num_thread();
        printf("Hello from thread %d of %d\n", id, numThreads);
    }
    return 0;
}
```
