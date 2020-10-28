#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int main(){
    int T;
    cin>>T;
    while(T--){
        clock_t z = clock();
        solve();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }    
}

