#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
using namespace std;
void divide(string palbra,int N_bloques)
{
  for(int i=0;i<palbra.length();i++)
    {
        if(i%N_bloques==0)
            cout<<"\n";
            cout<<palbra[i];
    }
}
int main()
{
    string *token;
    string palbra;
    int N_bloques;
    cout<<"Deme la cadena de caracter:\n";
    getline(cin,palbra);
    cout<<"de el numero de bloques:";
    cin>>N_bloques;
    divide(palbra,N_bloques);
    cout<<"\n ////////////////////////////////////\n";
    char cadena[] = "548365842";
    long int  a;
    a = atoi(cadena);
    cout << a;
    cout<<"\n ////////////////////////////////////\n";

    int b = 548365842;
    string numstr(std::to_string(b));
    cout<<numstr+"hola"<<endl;
    return 0;
}
