#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = rand(1000, 1000);
    cout<<t<<endl;
    while(t--){
        int n = rand(1000, 1000);
        int m = rand(1000, 1000);
        cout<<n<<" ";
        for(int i=0;i<n;i++){
            char temp = 'a' + rand(0, 25)%26;
            cout<<temp;

        }
        cout<<endl;
        cout<<m<<" ";
        for(int i=0;i<m;i++){
            char temp = 'a' + rand(0, 25)%26;
            cout<<temp;
        }
        cout<<endl;
    }
    
    puts("");
}