#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s ) converts an array of chars to int
    int N = rand(1, 100);
    int K = rand(0,100);
    int P = rand(1, 100);
    cout<<N<<" "<<K<<" "<<P<<endl;
    
    for(int i=0;i<N;i++){
        cout<<rand(1,100)<<" ";
    }
    cout<<endl;

    for(int i=0;i<P;i++){
        cout<<rand(1,N)<<" "<<rand(1, N)<<endl;
    }

    

    
    puts("");
}