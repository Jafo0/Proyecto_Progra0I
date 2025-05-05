#include <iostream>
#include <string>

using namespace std;

int main(){
    while(true){
        int entrada;
        cout<<"Entrada: ";
        cin>>entrada;

        int a = entrada/10;
        int b = entrada%10;

        cout<<endl<<a<<","<<b<<endl;
    }
}