// exercise.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int data;
	int down;
};
int BinarySearch(int low, int high, int find, node numbers[]) {
    int mid = (low+high)/2;
    while(low < high) {
		if(find > numbers[mid].data) {
            low = mid+1;
        } else if(find < numbers[mid].data){
            high = mid-1;
        } else {             
            return mid;
        }   
        mid = (low+high)/2;
    }
    return -1; 
}
bool cmp(node a, node b) {
	return a.data < b.data;
}
int main() {
    // Start typing your code here...
	int target = 99;
    int n = 7;
	int q;
	int p;
	node numbers[500];
	for(int i = 0; i < n; i++) {
		scanf("%d", &numbers[i].data);
		numbers[i].down = i;
	}  
    sort(numbers, numbers+n, cmp);

    for(p = 0; p < n; p++) {
        int find = target-numbers[p].data;
		q = BinarySearch(p+1, n, find, numbers);
        if(q >= 0) {
            break;
        }
    }
	if(numbers[p].down < numbers[q].down) {
		printf("p = %d, q = %d\n", numbers[p].down, numbers[q].down);
	} else {
		printf("p = %d, q = %d\n", numbers[q].down, numbers[p].down);
	}
	
	system("pause");
    return 0;
}
