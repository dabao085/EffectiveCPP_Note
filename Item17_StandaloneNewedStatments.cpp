/*

*/

#include <iostream>
#include <memory>
using namespace std;

class CWidget
{

};

int priority()
{
	return 1;
}

void processWidget(shared_ptr<CWidget> pw, int priority)
{
	cout << "in processWidget..." << endl;
	cout << "out processWidget..." << endl;
}

int main()
{
	//可能产生错误的写法
	//processWidget(shared_ptr<CWidget> pw(new CWidget), priority());
	
	//将newed对象单独放在一行语句中
	shared_ptr<CWidget> pw(new CWidget);
	processWidget(pw, priority());

	return 0;
}