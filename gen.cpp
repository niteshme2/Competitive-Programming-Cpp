#include <bits/stdc++.h>
using namespace std;

 

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s ) converts an array of chars to int
    int T = rand(1, 5);
    
    cout<<T<<"\n";
    while(T--){
        int N = rand(1, 10);
        cout<<N<<endl;
        for(int i=0;i<N;i++){
            cout<<rand(0, INT32_MAX)<<" ";
        } 
        cout<<endl;   
    }

    
    

    
    puts("");
}