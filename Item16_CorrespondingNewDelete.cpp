/*
*1.提供成对的new&delete
*2.不要对数组形式使用typedefs
*/

#include <iostream>
#include <string>
using namespace std;

//注意:对数组形式的变量使用typedef操作,不推荐
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

	//注意避免使用typedef重定义 数组形式的变量
	string *pal = new AddressLines;
	cout << "the value of pal is : " << pal << endl;
	delete[] pal;
	cout << "delete the pointer : " << pal << endl;

	return 0;
}