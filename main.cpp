#include <iostream>
#include <string>
using namespace std;
class algoX{
    int posx,posy;
public:
    algoX(int _posx,int _posy){
			posx = _posx;
			posy = _posy;
		}
    string codi(string);
    string deco(string);
};
string algoX::codi(string mens){
    string temp[posx][posy];
    string m_cod;
    for(int i=0;i<posx;i++){
				for(int j=0;j<posy;j++){
					if(((i*posy)+j)<mens.size()){
						temp[i][j] = mens[(i*posy)+j];
					}
					else temp[i][j]="*";
					}
					for(int i=0;i<posy;i++){
				for(int j=0;j<posx;j++){
					m_cod.append(temp[j][i]);
				}
			}
			return m_cod;
		}

}
string algoX::deco(string mens ){
    string temp[posx][posy];
    string m_deco;
    for(int i=0;i<posy;i++){
				for(int j=0;j<posx;j++){
					temp[j][i] = mens[(i*posx)+j];
				}
			}

			for(int i=0;i<posx;i++){
				for(int j=0;j<posy;j++){
					m_deco.append(temp[i][j]);
				}
			}
			return m_deco;

}
int main()
{
    string a,cod,dec;
    cout<<"dame un mensaje:\n";
    getline(cin,a);
    cout<<"\n tamano de mens="<<a.size()<<"\n";
    int f,c;
    cout<<"deme filas:";
    cin>>f;
    cout<<"deme colup:";
    cin>>c;
    cout<<"\n";
    algoX emi(f,c),rec(f,c);
    cod=emi.codi(a);
    dec=rec.deco(a);
    cout<<cod<<"\n";
    cout<<dec;

    return 0;
}

