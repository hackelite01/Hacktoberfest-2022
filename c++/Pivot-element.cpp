#include<iostream>
using namespace std;

//finding pivot element using Binary search

int getPivot(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while (s<e){
        if (arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}


int main(){
    int arr[10] = {7,9,10,1,2,3};
    //pivot element is smallest element in the array 
    //get pivot tell the index of that element 
    cout << getPivot(arr,5) << endl;
    return 0;
}