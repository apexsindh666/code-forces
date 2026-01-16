// Given an array 𝑎1,𝑎2,…,𝑎𝑛. In one operation, you can choose a pair of indices 𝑖,𝑗 such that 1≤𝑖<𝑗≤𝑛, 𝑎𝑖>𝑎𝑗, and remove the element at index 𝑗 from the array. After that, the size of the array will decrease by 1, and the relative order of the elements will not change.

// Determine the maximum number of operations that can be performed on the array if they are applied optimally.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤50). The description of the test cases follows.

// The first line of each test case contains an integer 𝑛 (1≤𝑛≤100) — the size of the initial array.

// The second line of each test case contains 𝑛 natural numbers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛).

// Output
// For each test case, output the maximum number of operations that you can perform on the given array.
#include<iostream>
#include<vector>
using namespace std;
int op(vector<int>&a){
    int n=a.size();
    int current_max=a[0];
    int r=0;
    for(int i=1;i<n;i++){
        if(a[i]<current_max){
            r++;
        }else {
            current_max=a[i];
        }
    }
    return r;
}
int main(){
int t,n;
cin>>t;
for(int i=0;i<t;i++){
    cin>>n;
    vector<int>a(n);
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    cout<<op(a)<<endl;
}
    return 0;
}