#include <bits/stdc++.h>
using namespace std;

 

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s ) converts an array of chars to int
    int T = rand(1, 5);
    T = 1;
    while(T--){
        int N = rand(1, 20);
        int Q = rand(1, 20);

        cout<<N<<" "<<Q<<endl;

        for(int i=0;i<N;i++){
            cout<<rand(1, 20)<<" ";
        } 
        cout<<endl;
        for(int i=0;i<Q;i++){
            int temp = rand(1,2);
            cout<<temp<<" ";
            if(temp==1){
                cout<<rand(1,N)<<" "<<rand(1, 20)<<endl;
            }
            else{
                cout<<rand(1,N)<<endl;
            }
        }
        cout<<endl;   
    }
    
    
    

    
    puts("");
}