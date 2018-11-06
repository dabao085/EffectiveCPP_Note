/*
 * �ṩ��������Դ�������л�ȡԭʼ��Դ�ķ��ʣ��ֱ�����ʽת������ʽת����
 * ��ʽ��ʽ��Ϊ��ȫ��
 */

#include <iostream>
using namespace std;

enum COLOR
{
	RED = 1,
	GREEN = 2,
	BLUE = 3
};

//������Դ��
class FontHandle
{
public:
	FontHandle(int color) :_color(color){}

public:
	int getColor() const
	{
		return _color;
	}

	void setColor(int color)
	{
		_color = color;
	}
private:
	int _color;
};

FontHandle getFont()
{
	cout << "get Font...COLOR::BLUE" << endl;
	FontHandle blueFH(COLOR::BLUE);
	return blueFH;
}

void releaseFont(FontHandle fh)
{
	cout << "releaseFont..." << endl;
}

//������Դ������
class Font
{
public:
	explicit Font(FontHandle f) : _f(f){}
	~Font()
	{
		releaseFont(_f);
	}

public:
	FontHandle get() const{ return _f; }	//��ʽת��
	operator FontHandle() const{ return _f; } //��ʽת��
private:
	FontHandle _f;
};

void changeFontColor(FontHandle f, int newColor)
{
	cout << "changeFontColor..." << endl;
	f.setColor(newColor);
}

int main()
{
	FontHandle redFH(COLOR::RED);
	Font redFont(redFH);

	//��ʽת��
	cout << "��ʽת��" << endl;
	changeFontColor(redFont.get(), COLOR::BLUE);	

	//��ʽת��
	cout << "��ʽת��" << endl;
	Font f(getFont());
	changeFontColor(f, COLOR::GREEN);

	return 0;
}