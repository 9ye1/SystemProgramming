#include<stdio.h>

void insertion(int* a, int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(a[j]>a[i]){
                
            }
        }
        
    }
    
}

int main (){
    int a[] = { 7, 6, 1, 2, 3, 4, 5 };
    int n = 7;

    printf("inserstion sort:\n");
    insertion(a, n);
}
