#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;


// Fibonacci Rule: Fn = Fn−1 + Fn−2.

// Fibonacci Recursive Algorithm
int FibRecursive(int n){
    if(n<=1){
        return n;
    }else{
        return FibRecursive(n-1)+ FibRecursive(n-2);
    }
}
// Fibonacci List Algorithm
int FibList(int n){
    if(n<=1){
        return n;
    }else{
        vector<int> fibList={0,1};

        for (int i = 2; i <= n; ++i) {
            fibList.push_back(fibList.at(i-1)+fibList.at(i-2));
        }

        return fibList.back();
    }
}
// Another Algorithm for Fibonacci without recursion
int FibNum(int n){
    if(n<=1){
        return n;
    }else{
        int n1=0, n2=1, n3;
        for (int i = 2; i <= n; ++i) {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cout<<"Enter Fibonacci length"<<endl;
    cin>>n;

    auto start = high_resolution_clock::now();

    cout<<FibRecursive(n)<<" - "<<FibList(n)<<" - "<<FibNum(n)<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Execution Time: "<< duration.count()<<" microseconds"<< endl;
    cout <<"Execution Time: "<< duration.count()/1000 <<" milliseconds"<< endl;

    return 0;
}