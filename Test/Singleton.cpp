#include "Singleton.h"
#include "iostream"

using namespace std;

Singleton* Singleton::m_pInstance = NULL;

Singleton* Singleton::Instance()
{
	if (!Singleton::m_pInstance)   
		Singleton::m_pInstance = new Singleton;

	return Singleton::m_pInstance;
}

void Singleton::writeToLogFile()
{

	cout << "Hello Singleton world" << endl;
	cout<< "your mission ?"<<endl;
	
}