// FUNCTION FindOutlierIndex():
//     READ n
    
//     SET even_count = 0
//     SET odd_count = 0
//     SET last_even_index = 0
//     SET last_odd_index = 0
    
//     // Using 1-based indexing for the loop to match the problem requirements
//     FOR i FROM 1 TO n:
//         READ current_number
        
//         IF current_number % 2 == 0 THEN
//             even_count = even_count + 1
//             last_even_index = i
//         ELSE
//             odd_count = odd_count + 1
//             last_odd_index = i
//         END IF
//     END FOR
    
//     IF even_count == 1 THEN
//         PRINT last_even_index
//     ELSE
//         PRINT last_odd_index
//     END IF
#include<iostream>
using namespace std;
void FindOutlierIndex(){
    int n,c;
    cin>>n;
    int even_count = 0,odd_count = 0,last_even_index = 0,last_odd_index = 0;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c%2==0){
            even_count = even_count + 1;
            last_even_index = i;
        }else{
            odd_count = odd_count + 1;
            last_odd_index = i;
        }
    }
    if(even_count==1){
        cout<<last_even_index<<"\n";
    }else{
        cout<<last_odd_index<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    FindOutlierIndex();
    return 0;
}