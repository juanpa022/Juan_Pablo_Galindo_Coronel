#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
//18.7
//CHGB RY DHR YB YRN
/*
void rot()
{
    cout<<"mensaje del alfabeto\n";
    string a;
    cout<<"de el mensaje:";
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    {
        a[i]=toupper(a[i]);
    }
    int key=13;
    string encript="";
    for(int i=0;i<a.length();i++)
    {
        int temp=a[i]+key;
        if(a[i]==32)
            encript+=" ";
        else if(temp > 90){
            temp-=26;
            encript+=(char)temp;}
        else
            encript+=(char)temp;
    }
    cout<<"encriptado de texto:"<<encript;
}
void deco()
{
     cout<<"mensaje del alfabeto\n";
    string a;
    cout<<"de el mensaje:";
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    {
        a[i]=toupper(a[i]);
    }
    int key=13;
    string encript="";
    for(int i=0;i<a.length();i++)
    {
        int temp=a[i]-key;
        if(a[i]==32)
            encript+=" ";
        else if(temp <65){
            temp+=26;
            encript+=(char)temp;}
        else
            encript+=(char)temp;
    }
    cout<<"Desencriptado de texto:"<<encript;
}
int main()
{
    int n;
    cout<<"\n Para encreitar 1.\n Para desencriptar 2.\n";
    cin>>n;
    cin.ignore();
    if(n==1)
    {
        cout<<"\n ---Encriptado---\n";
        rot();
    }
    else if(n==2)
    {
        cout<<"\n ---Desencriptado---\n";
        deco();
    }

    return 0;
}
//18.11
int main()
{
    string nombre,apellido,completo;
    cout<<"deme su nombre:\n";
    getline(cin,nombre);
    cout<<"deme su apellido:\n";
    getline(cin,apellido);
    completo=nombre +" "+ apellido;
    cout<<"\n tu nombre es="<<completo<<endl;
} */
//18.12
/*
string palabra_ori;
string mostrar_p;
int vidas;
void mostrar();
void ingresar(char x);
void inicia();
int main()
{
    inicia();
    mostrar();
    while(vidas >0 &&mostrar_p!=palabra_ori)
    {
        char x;
        cin>>x;
        ingresar(x);
        mostrar();
    }
    if(vidas>0)cout<<"Felicidades!!! Adivino mi palabra\n";
    else cout<<"Perdiste master , la palabra es:"<<palabra_ori<<endl;
}
void mostrar()
{
    cout<<"vidas: "<<vidas<<endl;
    cout<<mostrar_p<<endl;
}
void inicia()
{
    int vidas=5;
    palabra_ori="Ahorcado";
    for(int i=0;i=palabra_ori.length();i++)
    {
        if(palabra_ori[i]>='A' && palabra_ori[i]<='z')
        palabra_ori[i]+=32;
    }
    for(int i=0;i=palabra_ori.length();i++)
    {
        if(palabra_ori[i]>='a' && palabra_ori[i]<='z')
        palabra_ori[i]+='*';
        else
            mostrar_p+=palabra_ori[i];
    }
}
void ingresar(char x)
{
    bool per=true;
    for(int i=0;i<palabra_ori.length();i++)
    {
        if(x==palabra_ori[i]){
            per=false;
            mostrar_p[i]=x;
        }
    }
    if(per)vidas--;
}*/
//18.19
/*
int main(){
string a;
cout<<"Deme su palabra:"<<endl;
cin>>a;
for(int i=0;i<a.length();i++)
{

   if(i==a.length()/2)
    cout<<"****";
   cout<<a[i];
}
}
*/
//18.21
/*
int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    cout<<"\n"<<pch;
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
*/

//18.22
/*
int main(){
    string a;
    string inver;
    cout<<"invertir un strin\n";
    cout<<"Deme la palabra:";
    getline(cin,a);
    for(int i=a.length()-1;i>=0;i--)
    {
        inver.append(a.substr(i,1));
    }
    cout<<"Nombre invertido= "<<inver;
}
*/
//18.27
void ordenamientoSeleccion( int [], const int, bool (*)( int, int ) );
  void intercambiar( int * const, int * const );
  bool ascendente( int, int );
  bool descendente( int, int );
 int main()
  {
  const int tamanioArreglo = 10;
  int orden; // 1 = ascendente, 2 = descendente
  int contador; // subíndice del arreglo
  int a[ tamanioArreglo ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

  cout << "Escriba 1 para orden ascendente,\n"
  << "Escriba 2 para orden descendente: ";
  cin >> orden;
  cout << "\nElementos de datos en el orden original\n";
  for ( contador = 0; contador < tamanioArreglo; contador++ )
  cout << setw( 4 ) << a[ contador ];
if ( orden == 1 )
  {
  ordenamientoSeleccion( a, tamanioArreglo, ascendente );
  cout << "\nElementos de datos en orden ascendente\n";
  }
  {
  ordenamientoSeleccion( a, tamanioArreglo, descendente );
  cout << "\nElementos de datos en orden descendente\n";
  }
  for ( contador = 0; contador < tamanioArreglo; contador++ )
  cout << setw( 4 ) << a[ contador ];

  cout << endl;
  return 0; // indica que terminó correctamente
  }
  void ordenamientoSeleccion( int trabajo[], const int tamanio,
  bool (*compara)( int, int ) )
  {
  int menorOMayor;
  for ( int i = 0; i < tamanio - 1; i++ )
  {
  menorOMayor = i;
  for ( int index = i + 1; index < tamanio; index++ )
  if ( !(*compara)( trabajo[ menorOMayor ], trabajo[ index ] ) )
  menorOMayor = index;
  intercambiar( &trabajo[ menorOMayor ], &trabajo[ i ] );
  }
  }
  void intercambiar( int * const elemento1Ptr, int * const elemento2Ptr )
  {
  int contenido = *elemento1Ptr;
  *elemento1Ptr = *elemento2Ptr;
  *elemento2Ptr = contenido;
  }
  bool ascendente( int a, int b )
  {
  return a < b;
  }
  bool descendente( int a, int b )
  {
  return a > b;
 }
