#include <iostream>
#include <string.h>
#include <chrono>
#include <windows.h>
#include <psapi.h>
void sortMin(int *arr, size_t s);
void sortMax(int *arr, size_t s);

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int arr[5] = {3,20,8,21,6};
    size_t size = sizeof(arr)/ sizeof(arr[0]);

    sortMin(arr,size);
    //std::cout << "Hello World" << std::endl;


    for (int i = 0; i < size ; ++i) {
        std::cout << *(arr+i) << " ";
    }
    std::cout << std::endl;
    sortMax(arr, size);
    for (int i = 0; i < size ; ++i) {
        std::cout << *(arr+i) << " ";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start; 

    std::cout << "Runtime: " << duration.count() << " ms" << std::endl;

    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    std::cout << "Memory usage: " << pmc.WorkingSetSize / 1024 << " KB\n";
}

void sortMin(int *arr, size_t s){
    int idx;
    idx = *(arr)  ;
    for (int k = 0; k < s; ++k) {
        idx = *(arr+k)  ;
        for (int i = k; i < s ; ++i) {           
            if (idx > *(arr + i)) {
                idx = *(arr + i);
                *(arr + i) = *(arr + k);
                *(arr + k) = idx;
            }
           // *(arr + k) = idx;
        }
    }

}

void sortMax(int *arr, size_t s) {
    int idx;
    idx = *(arr)  ;
    for (int k = 0; k < s; ++k) {
        idx = *(arr+k)  ;
        for (int i = k; i < s ; ++i) {           
            if (idx < *(arr + i)) {
                idx = *(arr + i);
                *(arr + i) = *(arr + k);
                *(arr + k) = idx;
            }
           // *(arr + k) = idx;
        }
    }
}