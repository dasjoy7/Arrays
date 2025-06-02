#include<bits\stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int target){
    if(low>high) return -1;
    int mid = low+ (high-low)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]<target) return binarySearch(arr, mid+1, high, target);
    else return binarySearch(arr, low, mid-1, target);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int &x: arr)cin>>x;
    int target;cin>>target;
    int result = binarySearch(arr, 0, n-1, target);
    if(result!=-1)cout<<"Index: "<<result<<endl;
    else cout<<"Not found"<<endl;
}