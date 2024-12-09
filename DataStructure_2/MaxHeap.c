#include <stdio.h>

int heap[100];
int last_idx = -1;


void init(){

    for(int i=0; i<100; i++) heap[i] = -1;
    last_idx = -1;

}

void reheap_up(int idx){

    if(idx == 0) return;

    int p_idx = (idx-1)/2;

    if(heap[p_idx]<heap[idx]){
        int tmp = heap[idx];
        heap[idx] = heap[p_idx];
        heap[p_idx] = tmp;

        reheap_up(p_idx);
    }
}

void reheap_down(int idx){
    int m_idx = -1;
    int l_idx = idx*2 + 1;
    int r_idx = idx*2 + 2;

    if(l_idx<=last_idx){ //l_idx가 존재하는지 
        if(r_idx<=last_idx){
            if(heap[l_idx]<heap[r_idx]) m_idx = r_idx;
            else m_idx = l_idx;
        }
        else m_idx = l_idx;
    }

    if(heap[m_idx] > heap[idx]){
         int tmp = heap[idx];
        heap[idx] = heap[m_idx];
        heap[m_idx] = tmp;

        reheap_down(m_idx);
    }

}

void insert(int key){

    if(last_idx==99) return; //Full

    heap[++last_idx] = key;
    reheap_up(last_idx); //target index

}

int del(){

    if(last_idx==-1) return;  //Empty

    int max = heap[0];
    heap[0] = heap[last_idx--];

    reheap_down(0);

    return max;

}

int main() {

    init();

    insert(8);
    insert(19);
    insert(23);
    insert(32);
    
    for(int i=0; i<4; i++ ){
        printf("%d", del());
    }
    //32 23 19 8

    return 0;
}