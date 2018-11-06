#include <iostream>
#include <memory>
#include <boost/noncopyable.hpp>
using namespace std;

//模拟mutex
class CMutex
{
public:
	void lock() const
	{
		cout << "CMutex::lock()..." << endl;
	}

	void unlock() const
	{
		cout << "CMutex::unlock()..." << endl;
	}
private:
};

class CLock : public boost::noncopyable
{
public:
	explicit CLock(CMutex *pm) :_mutexPtr(pm)
	{
		_mutexPtr->lock();
	}

	~CLock()
	{
		_mutexPtr->unlock();
	}

private:
	CLock(const CLock&);
	CLock & operator=(const CLock&);
private:
	CMutex *_mutexPtr;
};

void lock(CMutex *ptr)
{
	ptr->lock();
}

//自定义删除器deleter
void unlock(CMutex *ptr)
{
	ptr->unlock();
}

class CCopyableLock
{
public:
	explicit CCopyableLock(CMutex *pm) :m_pMutexPtr(pm, unlock)
	{
		lock(m_pMutexPtr.get());
	}
private:
	shared_ptr<CMutex> m_pMutexPtr;
};

int main()
{
	CMutex m;

	//code block
	{
		cout << "Testing CLock..." << endl;
		CLock ml(&m);
	}//自动调用CMutex::unlock

	{
		cout << "Testing CCopyableLock..." << endl;
		CCopyableLock cl(&m);
	}
	cout << "end of program" << endl;
	return 0;
}