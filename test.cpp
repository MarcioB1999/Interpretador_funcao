#include <iostream>
using namespace std;

int main(){
    
    int *a = nullptr;

    a= (int*)malloc(sizeof(int));

    if(a){
        cout<<"oi";
    }

    return 0;
}