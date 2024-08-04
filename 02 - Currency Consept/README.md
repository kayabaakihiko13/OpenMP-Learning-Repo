02 Currency
---

Currency merupakan konsep multipile komputasi yang sedang diterjadi saat waktu sama.

contoh dalam Currency dengan code OpenMP.
```cpp
#include<stdio.h>
#include<omp.h>
int main(){
    #pragma omp parallel
    {
        printf("Hello");
        printf("World\n");
    }
}
```
pada kode diatas,kamu akan membayangkan output seperti ini:
```sh
Hello World
Hello World
Hello World
```
namun sebenarnya hasilnya demikian:
```sh
Hello Hello World
World
Hello World
Hello World
```

konsep ini juga dipakai didalam software programming baik dalam web,mobile maupun deskop. konsep tersebut juga denga <i>Asynchronous</i>

sebagai contoh seperti ini pada bahasa pemprograman javascript
```js
setTimeout(myfunction,1)
function myFunction() {
  let msg= "No Shikonokonoko Konstanta!!"
  console.log(msg);
}
myFunction();
```