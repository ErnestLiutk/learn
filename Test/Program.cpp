#include <iostream>
#include <iomanip>
#include <fstream>
#include "Singleton.h"

using namespace std;

ifstream fd("Dalykai.txt");
ofstream fr("rezultatai.txt");

const int a = 100;
const int b = 100;

void ivedimas(int B[][b], int & n, int & m);
void spausdinimas(int B[][b], int & n, int & m);
void desimtukai(int B[][b], int & n, int & m, int & mokinys);
void desimtkiekis(int B[][b], int & n, int & m, int & mokinys);
void kiekis(int B[][b], int & n, int & m, int & mokinys);

int main(){

	int B[a][b];
	int n, m, mokinys=0;


	ivedimas(B, n, m);
	spausdinimas(B, n, m);
	desimtukai(B, n, m, mokinys);
	desimtkiekis(B, n, m, mokinys);
	kiekis(B, n, m, mokinys);
	
	Singleton::Instance()->writeToLogFile();
	system("pause");
    return 0;
}

void ivedimas( int B[][b], int & n, int & m){

	fd >> n >> m;

	for( int i=0; i<n; i++){
		for ( int j=0; j<m; j++){
			fd >> B[i][j];
		}
	}
}

void spausdinimas( int B[][b], int & n, int & m){

	int g=1;

	for( int i=0; i<n; i++){
		fr << "Mokinys Nr." << i+1 << " Ivertinimai:  ";
		g++;
		for ( int j=0; j<m; j++){
			fr << setw(3) << B[i][j];
		}
		fr << endl;
	}

}

void desimtukai( int B[][b], int & n, int & m, int & mokinys){

	int g=0, k=0;

	for( int i=0; i<n; i++){
		for ( int j=0; j<m; j++){

			if(B[i][j] == 10)
			{
				g++;
			}

		}
		if (g > k)
		{
			k = g;
			mokinys = i+1;
		}
		g = 0;
	}

	if ( mokinys > 0)
	{
		fr << "Daugiausiai desimtuku turintis mokinys Nr: " << mokinys << endl;
	}
	else 
	{
		fr << "Nei vienas mokinys desimtuku neturi" << endl;
	}
}

void desimtkiekis(int B[][b], int & n, int & m, int & mokinys){

	int kiekis = 0;

	for(int j = 0; j < m; j++)
	{
		if(B[mokinys-1][j] == 10)
		{
			kiekis++;
		}
	}
	
	fr << "Daugiausia desimtuku turincio mokinio desimtuku kiekis: " << kiekis << endl;
}


void kiekis(int B[][b], int & n, int & m, int & mokinys){
	
	int neigiami=0, v=0;

	for( int i=0; i<n; i++){
		for ( int j=0; j<m; j++){
		
			if(B[i][j] < 4)
			{
				neigiami++;
			}
		}
		if(neigiami > 0){
			v++;
		}
		neigiami = 0;
}
if ( v > 0)
	{
		fr << "Mokiniu kiekis neturintys neigiamu pazymiu: " << n-v << endl;
	}
	else 
	{
		fr << "Nei vienas mokinys neigiamu pazymiu neturi" << endl;
	}
}

