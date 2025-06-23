#include <iostream>
#include <string.h>
void sortMin(int *arr, size_t s){
    int idx;

    idx = *(arr+1)  ;
    for (int k = 0; k < s; ++k) {
        for (int i = 0; i < s ; ++i) {           
            if (idx > *(arr + i)) {
                idx = *(arr + i);
            }
            *(arr + k) = idx;
        }
    }

    std::cout << "Min: "<<*arr << std::endl;
}

int main()
{
    int arr[5] = {3,20,8,21,6};
    size_t size = sizeof(arr)/ sizeof(arr[0]);

    sortMin(arr,size);
<<<<<<< HEAD
    std::cout << "Hello from local city" << std::endl;
    std::cout << "Hello World" << std::endl;
    std::cout << "Hello World 123" << std::endl;
=======

    std::cout << "Hello World 123" << std::endl;
>>>>>>> feature-123

    
    // for (int i = 0; i < size ; ++i) {
    //     std::cout << *(arr+i) << std::endl;
    // }
    
}
