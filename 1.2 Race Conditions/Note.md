# Race Conditions
---

Bagian ini dibangun di atas pola fork-join dan SPMD yang sederhana dan memperkenalkan gagasan tentang race condition. Pada akhir bagian ini, Anda akan dapat mendefinisikan apa itu race condition, mengidentifikasi race condition dalam kode sampel, dan memperkirakan beberapa strategi untuk memperbaikinya.

## Estimating the Area Under a Curve
---
Sebagai contoh berikutnya, mari kita lihat masalah estimasi luas area di bawah kurva. Jika Anda pernah mengikuti kursus kalkulus, Anda mungkin mengenali masalah ini sebagai jumlah Riemann atau Trapesium, yang memperkirakan luas area di bawah kurva (yaitu integral) dengan membagi area di bawah kurva menjadi serangkaian trapesium.

Dalam program berikut, kami mencoba menggunakan aturan trapesium untuk mendekati integral

Translated with DeepL.com (free version)

$$
\int_0^{\pi} \sin(x) \, dx
$$

untuk code sequential
---
```cpp
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//function we are calculating the area under
double f(double x) {
   return sin(x);
}

//estimation of pi
const double pi = 3.141592653589793238462643383079;

int main(int argc, char** argv) {
   //Variables
   double a = 0.0, b = pi;         //limits of integration
   int n = 1048576;                //number of subdivisions = 2^20
   double h = (b - a) / n;         //width of each subdivision
   double integral;                // accumulates answer

   integral = (f(a) + f(b))/2.0;  //initial value

   //sum up all the trapezoids
   int i;
   for(i = 1; i < n; i++) {
       integral += f(a+i*h);
   }

   integral = integral * h;
   printf("With %d trapezoids, our estimate of the integral from \n", n);
   printf("%f to %f is %f\n", a,b,integral);

   return 0;
}
```

untuk code Concurancy
---
```cpp
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>
double f(double x) {
   return sin(x);
}
const double pi = 3.141592653589793238462643383079;
int main(int argc, char** argv) {
   //Variables
   double a = 0.0, b = pi;         //limits of integration
   int n = 1048576;                //number of subdivisions = 2^20
   double h = (b - a) / n;         //width of each subdivision
   double integral;                // accumulates answer
   #pragma omp parallel
   {
    integral = (f(a) + f(b))/2.0;  //initial value

   //sum up all the trapezoids
   int i;
   for(i = 1; i < n; i++) {
       integral += f(a+i*h);
   }

   integral = integral * h;
   printf("With %d trapezoids, our estimate of the integral from \n", n);
   printf("%f to %f is %f\n", a,b,integral);

   return 0;
   }
   
}
```