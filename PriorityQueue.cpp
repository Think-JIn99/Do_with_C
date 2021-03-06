#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<vector>
using namespace std;

void printheap(vector<pair<int,int> > &heap){
    for(auto it = heap.begin(); it!=heap.end(); it++) cout << (*it).first << "\t";
    cout << endl;
}

void MinHeapify(vector<pair<int,int> > &heap, int i){
    while(i <= heap.size() / 2){
        int childIndex = i * 2;
        if(childIndex >= heap.size()) return;
        int k = (heap[childIndex].second < heap[childIndex + 1].second) ? childIndex : childIndex + 1;
        if(childIndex + 1 == heap.size()){
            k = childIndex;
        }
        if(heap[i].second <= heap[k].second) return;
        swap(heap[i],heap[k]);
        i = k;
    }
}

void BuildMinheap(vector<pair<int,int> > &heap){
    for(int i = heap.size() / 2;  i >= 1; i--){
        MinHeapify(heap,i);
    } 
}

void HeapSort(vector<pair<int,int> > &heap){
    BuildMinheap(heap);
    for(int i = heap.size() - 1; i > 0; i--){
        cout << heap[1].second << endl;
        swap(heap[1],heap[i]);
        heap.pop_back();    
        MinHeapify(heap,1);
    }
}

int main(){
    srand(time(NULL));
    vector<pair<int,int>> heap;
    heap.push_back(make_pair(0,0));
    int cnt = 10;
    for(int i = 1; i < cnt; i++){
        heap.push_back(make_pair(i,i));
    }
    HeapSort(heap);
    for(int i = 1; i < cnt; i++){
        // cout << heap[i].first << " : " << heap[i].second << endl;
    }
}