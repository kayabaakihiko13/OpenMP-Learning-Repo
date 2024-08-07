#include <iostream>
#include <omp.h>

void spam_msg(int threadID){
    std::cout<<"Hallo dari thread"<<threadID<<std::endl;
}
void spam_msgConcurrency(int num_cores){
    omp_set_num_threads(num_cores/2);
    #pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        spam_msg(threadID);
    }
}
void spam_msgParallel(int num_cores){
    int th_id;
    omp_set_num_threads(num_cores/2);
    #pragma omp parallel private(th_id)
    {
        th_id = omp_get_thread_num();
        spam_msg(th_id);
    }
}

int main() {
    int num_cores = omp_get_num_procs();
    std::cout << "Jumlah core yang terdeteksi: " << num_cores << std::endl;
    
    std::cout << "Concurrency" << std::endl;
    spam_msgConcurrency(num_cores);
    
    std::cout << "Parallel private" << std::endl;
    spam_msgParallel(num_cores);

    return 0;
}