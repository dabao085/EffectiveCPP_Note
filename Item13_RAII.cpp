/*
*����RAII ����heap��Դ, ʹ��shared_ptr����ָ������ٹ���
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//��Դ��
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

//��Դ�����࣬������Դ�����ָ��pSrc
class CSourceManager
{
public:
	void doSomething()
	{
		shared_ptr<CSource> pSrc(new CSource(10));	//ʹ��shared_ptr����ָ��pSrc�����ٹ���
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