#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct Bagis
{
    char ad[80];
    char soyad[80];
    int  bagisMiktar;
    char kartNo[16];
    char skt[5];
    int cvv;
};

void BagisYap();
void BagisListele();


int main()
{
	setlocale(LC_ALL,"Turkish");
    char anamenu;
    do
    {
        system("cls");

        cout << " ________________________" << endl;
        cout << "|       Ho�geldiniz      |" << endl;
        cout << "|                        |" << endl;
        cout << "|   1- Ba��� Yap         |" << endl;
        cout << "|   2- Ba��� Listele     |" << endl;
        cout << "|________________________|" << endl;
        
		char secim;
        cin >> secim;

        switch (secim)
        {
        case '1':
        {
            BagisYap();
            break;
        }
        case '2':
        {
            BagisListele();
            break;
        }
        }

        cout << "Ana men�ye d�nmek i�in  = a"  << endl;
        cout << "Uygulamadan ��kmak i�in = y" << endl;
    
        anamenu = getche();

    } 
	while (anamenu == 'a');

    return 0;
}

void BagisYap()
{	    
    system("cls");
    ofstream yaz("bagislar.dat", ios::binary | ios::app);
    Bagis bagis;
    
    cout << "Ad�n�z� Giriniz    = "   ;
    cin.ignore();
    cin.getline(bagis.ad,sizeof(bagis.ad));
	
    cout << "Soyad�n�z� Giriniz = ";
    cin >> bagis.soyad;

    cout << "Ba��� Miktar�n� Girini = ";
    cin >> bagis.bagisMiktar;
    
    system("cls");
    
	cout<<"�deme sayfas�na y�nlendiriliyorsunuz";
    
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<"."<<endl;
	Sleep(500);
	system("cls");
    
   	cout << "Kart Numaran�z� Giriniz (16 hane)    = ";
    cin >> bagis.kartNo;

    cout << "Kart�n Son Kullanma Tarihini (AA/YY) = ";
    cin >> bagis.skt;

    cout << "CVV = ";
    cin >> bagis.cvv;

    yaz.write((char *)&bagis, sizeof(bagis));
    yaz.close();
    
    system("cls");
    cout << "Ba����n�z al�nm��t�r te�ekk�rler..." << endl;
    cout << endl;
}

void BagisListele()
{
    system("cls");   
    ifstream oku("bagislar.dat", ios::binary | ios::app);
    Bagis bagis;

    oku.seekg(0, ios::end);
    int kayits = oku.tellg() / sizeof(Bagis);
    int toplam=0;
    
    

        for (int i = 0; i < kayits; i++)
        {
            oku.seekg(i * sizeof(Bagis));
            oku.read((char *)&bagis, sizeof(bagis));
            
            cout << endl;
            cout << i + 1 << ". Ba�����n�n Bilgileri = " << endl;
            cout << "Ad    = " << bagis.ad << endl;
            cout << "Soyad = " << bagis.soyad << endl;
            cout << "Ba��� Miktar = " << bagis.bagisMiktar << " TL" << endl;
			
			toplam += bagis.bagisMiktar; 
        }
        
		cout << endl;
        cout << "Toplam  Ba��� Miktar� = " << toplam << endl;
        cout << endl;
   
    oku.close();
}




