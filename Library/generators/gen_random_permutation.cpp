#include <bits/stdc++.h>
using namespace std;


  
// Function to return the next random number 
int getNum(vector<int>& v) 
{ 
  
    // Size of the vector 
    int n = v.size(); 
    
    // Generate a random number 
    srand(time(NULL)); 
  
    // Make sure the number is within 
    // the index range 
    int index = rand() % n; 
  
    // Get random number from the vector 
    int num = v[index]; 
  
    // Remove the number from the vector 
    swap(v[index], v[n - 1]); 
    v.pop_back(); 
  
    // Return the removed number 
    return num; 
} 
  
// Function to generate n non-repeating random numbers 
void generateRandom(int n, int M) 
{ 
    vector<int> v(n); 
  
    // Fill the vector with the values 
    // 1, 2, 3, ..., n 
    for (int i = 0; i < n; i++) 
        v[i] = i + 1; 
  
    // While vector has elements 
    // get a random number from the vector and print it 
    int count=1;
    while (v.size()) { 
        cout << getNum(v) << " ";
        if(count%M == 0) cout<<endl;
        count++;
    } 
} 

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s ) converts an array of chars to int
    int T = rand(1, 5);
    
    cout<<T<<"\n";
    while(T--){
    int N = rand(1, 5);
    int M = rand(1,5);
    cout<<N<<" "<<M<<endl;
    //
    
    generateRandom(N*M, M);
    //
    }
    

    
    puts("");
}