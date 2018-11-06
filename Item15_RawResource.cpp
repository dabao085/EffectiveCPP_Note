/*
 * 提供两种在资源管理类中获取原始资源的访问，分别是显式转换和隐式转换。
 * 显式方式更为安全。
 */

#include <iostream>
using namespace std;

enum COLOR
{
	RED = 1,
	GREEN = 2,
	BLUE = 3
};

//字体资源类
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

//字体资源管理类
class Font
{
public:
	explicit Font(FontHandle f) : _f(f){}
	~Font()
	{
		releaseFont(_f);
	}

public:
	FontHandle get() const{ return _f; }	//显式转换
	operator FontHandle() const{ return _f; } //隐式转换
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

	//显式转换
	cout << "显式转换" << endl;
	changeFontColor(redFont.get(), COLOR::BLUE);	

	//隐式转换
	cout << "隐式转换" << endl;
	Font f(getFont());
	changeFontColor(f, COLOR::GREEN);

	return 0;
}