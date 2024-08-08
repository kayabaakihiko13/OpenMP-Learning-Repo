# Shared Memory Preliminaries

### Process and Threads
---
Proses adalah abstraksi dari sebuah program yang sedang berjalan. Setiap proses memiliki ruang alamatnya sendiri, yang meliputi kode, data, dan sumber daya yang dibutuhkan untuk eksekusi. 

<b>Thread</b> adalah merupakan unit eksekusi yang lebih ringan dibandingkan proses. Thread berada dalam konteks process dan berbagi ruang alamat dengan thread lain dalam process yang sama. karena berbagai ruang process. Selain itu, dengan menggunakan multithreading,sebuah program dapat menjalankan beberapa operasi secara bersamaan (concurrency),sehingga meningkatkan efisiensi dan kinerja,terutama pada sistem dengan beberapa inti CPU.

Process Vs Thread
---

#### Process
    - Process adalah instasi dari program yang sedang berjalan.
    - Setiap process memiliki ruang alamat memori sendiri,yang berati data dan kode dalam satu
    - Proses berjalan secara independen satu sama lain.

#### Thread
    - Thread berbagi ruang alamat memori dengan thread lain dalam process yang sama.
    - Perpindahan konteks antar thread lebih efisien dibandingkan perpindahan konteks antar proses.
