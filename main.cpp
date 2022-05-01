#include <iostream>
#include <string>
using namespace std;

int euclides(int num1,int num2){
    if(num2==0){
        return num1;
    }else{
        return euclides(num2,num1%num2);
    }
}

int ext_euclides(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }else{
        int x1,y1;
        int d=ext_euclides(b,a%b,x1,y1);
        x=y1;
        y = x1-y1*(a/b);
        return d;
    }
}

int inverso(int a,int n){
    if(euclides(a,n)==1){
       int x,y;
       int d=ext_euclides(a,n,x,y);
       return (x%n+n)%n;
    }else{
        cout<<"no existe inverso"<<endl;
        return 0;
    }
}
void cifrado(string &m,int a,int b){
    string abc="ABCDEFGHIJKLMN~OPQRSTUVWXYZ";
    int tam_a=m.length();
    for(int i=0;i<tam_a;i++){
        int pos_abc=0;
        for(int j=0;j<27;j++){
            if(m[i]==abc[j]){
                break;
            }
             pos_abc++;
        }

        int e=((a*pos_abc)+b)%27;
        m[i]=abc[e];
    }
}

void descifrar(string &m,int a,int b){
    int ai=inverso(a,27);
    string abc="ABCDEFGHIJKLMN~OPQRSTUVWXYZ";
    int tam_a=m.length();
    for(int i=0;i<tam_a;i++){
        int pos_abc=0;
        for(int j=0;j<27;j++){
            if(m[i]==abc[j]){
                break;
            }
             pos_abc++;
        }
        int d=((ai*(pos_abc-b)%27)+27)%27;
        m[i]=abc[d];
    }
}
int main()
{
    string mensaje1="ELEMENTALMIQUERIDOWATSON";
    string mensaje2="OKHFSNKFNWFCWJHSNCHQYWFSWF";

    cout<<"el cifrado de "<<mensaje1<<" es: ";
    cifrado(mensaje1,4,7);
    cout<<mensaje1<<endl;

    cout<<"el descifrado de "<<mensaje2<<" es: ";
    descifrar(mensaje2,4,7);
    cout<<mensaje2<<endl<<endl;

    cout<<"aplicamos el cifrado para el mensaje: SLBCMVRBSHZBT~NSRQVVMSZBVH~NBVRQVLALHZBT~NSRQVWQAXLZW~NAQFQV"<<endl;
    for(int a=0;a<28;a++){
        if(inverso(a,27)>0){
            for(int b=0;b<28;b++){
                cout<<"a es "<<a<<" b "<<b<<": ";
                string mensaje3="SLBCMVRBSHZBT~NSRQVVMSZBVH~NBVRQVLALHZBT~NSRQVWQAXLZW~NAQFQV";
                descifrar(mensaje3,a,b);
                cout<<mensaje3<<endl;
            }
        }
    }
    cout<<endl;cout<<"la respuesta es: "<<"a es 23 b 17: NOEXISTENPREGUBNTASSINRESPUBESTASOLOPREGUBNTASMALFORMUBLADAS"<<endl;
}
