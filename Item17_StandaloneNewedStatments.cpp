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
	//���ܲ��������д��
	//processWidget(shared_ptr<CWidget> pw(new CWidget), priority());
	
	//��newed���󵥶�����һ�������
	shared_ptr<CWidget> pw(new CWidget);
	processWidget(pw, priority());

	return 0;
}