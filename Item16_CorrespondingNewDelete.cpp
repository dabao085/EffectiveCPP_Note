/*
*1.�ṩ�ɶԵ�new&delete
*2.��Ҫ��������ʽʹ��typedefs
*/

#include <iostream>
#include <string>
using namespace std;

//ע��:��������ʽ�ı���ʹ��typedef����,���Ƽ�
typedef string AddressLines[4]; 

int main()
{
	//new & delete single pointer, use delete
	int *pInt = new int(10);
	cout << "the value of pInt is : " << pInt << endl;
	delete pInt;
	cout << "delete the pointer : " << pInt << endl;

	//new & delete array pointers, use delete []
	string *pStringArray = new string[100];
	cout << "the value of pStringArray is : " << pStringArray << endl;
	delete[] pStringArray;
	cout << "delete the pointer : " << pStringArray << endl;

	//ע�����ʹ��typedef�ض��� ������ʽ�ı���
	string *pal = new AddressLines;
	cout << "the value of pal is : " << pal << endl;
	delete[] pal;
	cout << "delete the pointer : " << pal << endl;

	return 0;
}