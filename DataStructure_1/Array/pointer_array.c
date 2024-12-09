#include <stdio.h>

int main(){

    int arr[3] = {0,1,2};

    printf("%p/n%p/n%p\n",arr[0],arr[1],arr[2]);

    int* b = &arr[0];

    printf("%p",b);

}
