#include <bits/stdc++.h>
using namespace std;

 

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

double randd(double min, double max) {
    return (max - min) * ( (double)rand() / (double)RAND_MAX ) + min;
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s ) converts an array of chars to int
    int T = rand(1, 1);
    T = 1;
    //cout<<T<<endl;
    int max_num = 9;
    while(T--){
        int N, R;
        N = rand(1, 10);
        R = rand(1, 10);
        cout<<N<<" "<<R<<endl;
        while(N--){
            cout<<rand(1, 10)<<" ";
        }

    }
    
    
    

    
    puts("");
}