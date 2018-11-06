/*
*测试RAII 基于heap资源, 使用shared_ptr负责指针的销毁工作
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//资源类
class CSource
{
public:
	CSource(size_t sourceId) :m_sourceId(sourceId){}
	~CSource(){}

	const void printId() const
	{
		cout << m_sourceId << endl;
	}
private:
	size_t m_sourceId;
};

//资源管理类，管理资源对象的指针pSrc
class CSourceManager
{
public:
	void doSomething()
	{
		shared_ptr<CSource> pSrc(new CSource(10));	//使用shared_ptr负责指针pSrc的销毁工作
		pSrc->printId();
	}
private:
};

int main()
{
	CSourceManager sm;
	sm.doSomething();

	return 0;
}