#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>

using namespace std;

class Shape
{
public:
	Shape() { name = "Фигура NoName"; }
	Shape(string name) : name(name) {}

	// конструктор копирования;
	Shape(const Shape& obj);

	// оператор присваивания;
	//Shape& operator =(const Shape& obj);

	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load(int index) = 0;

	virtual ~Shape() = 0;

	//перегузка оператора вывода
	friend ostream& operator << (ostream& out, const Shape& obj);
	friend istream& operator >> (istream& in, Shape& obj);

protected:
	string name;
}; 

Shape::~Shape()
{
	//cout << "Вызвался деструктор Shape" << endl;
}

class Square: public Shape
{
public:
	Square() { a = b = 0; }
	Square(int a, int b) : a(a), b(b){}
	Square(int a, int b, string name) : a(a), b(b), Shape(name) {}

	// конструктор копирования;
	Square(const Square& obj);

	Square& operator =(const Square& obj);

	void Show() override;
	void Save() override;
	void Load(int index) override;

	~Square() override;

	//перегузка оператора вывода
	friend ostream& operator << (ostream& out, const Square& obj);
private:
	int a;
	int b;
};

class Circle : public virtual Shape
{
public:
	Circle() { x = y = 0; }
	Circle(int x, int y) : x(x), y(y) {}
	Circle(int x, int y, string name) : x(x), y(y), Shape(name) {}

	// конструктор копирования;
	Circle(const Circle& obj);

	Circle& operator =(const Circle& obj);

	void Show() override;
	void Save() override;
	void Load(int index) override;

	~Circle() override;
	//перегузка оператора вывода
	friend ostream& operator << (ostream& out, const Circle& obj);

protected:
	int x;
	int y;
};

class CRectangle : public virtual Shape
{
public:
	CRectangle() { a = b = 0; }
	CRectangle(int a, int b) : a(a), b(b) {}
	CRectangle(int a, int b, string name) : a(a), b(b), Shape(name) {}

	// конструктор копирования;
	CRectangle(const CRectangle& obj);

	CRectangle& operator =(const CRectangle& obj);

	void Show() override;

	void Save() override;
	void Load(int index) override;

	~CRectangle()
	{
		cout << "Вызвался деструктор CRectangle" << endl;
	}
	//перегузка оператора вывода
	friend ostream& operator << (ostream& out, const CRectangle& obj);

protected:
	int a;
	int b;
};

class Elipse : public Circle, public CRectangle
{
public:
	Elipse() { x = y = a = b = 0; }
	Elipse(int x, int y) : Circle(x, y) { };
	Elipse(int x, int y, int a, int b) : Circle(x, y), CRectangle(a, b){}
	Elipse(int x, int y, int a, int b, string name) : Circle(x, y), CRectangle(a, b), Shape (name){}

	// конструктор копирования;
	Elipse(const Elipse& obj);

	Elipse& operator =(const Elipse& obj);

	void Show() override;
	void Save() override;
	void Load(int index) override;

	~Elipse()
	{
		cout << "Вызвался деструктор Elipse" << endl;
	}
	friend ostream& operator << (ostream& out, const Elipse& obj);

private:
	//int x;
	//int y;
};

Shape::Shape(const Shape& obj)
{
	this->name = obj.name;
}

inline Square::Square(const Square& obj)
{
	this->name = obj.name;
	this->a = obj.a;
	this->b = obj.b;
}

inline Square& Square::operator=(const Square& obj)
{
	this->name = obj.name;
	this->a = obj.a;
	this->b = obj.b;
}

void Square::Show()
{
	cout << name << " a: " << a << " b: " << b;
}

inline CRectangle::CRectangle(const CRectangle& obj)
{
	this->name = obj.name;
	this->a = obj.a;
	this->b = obj.b;
}


inline CRectangle& CRectangle::operator=(const CRectangle& obj)
{
	this->name = obj.name;
	this->a = obj.a;
	this->b = obj.b;
}

void CRectangle::Show()
{
	cout << name << " a: " << a << " b: " << b;
}

inline Circle::Circle(const Circle& obj)
{
	this->name = obj.name;
	this->x = obj.x;
	this->y = obj.y;
}

inline Circle& Circle::operator=(const Circle& obj)
{
	this->name = obj.name;
	this->x = obj.x;
	this->y = obj.y;
}

void Circle::Show()
{
	cout << name << " x: " << x << " y: " << y;
}


inline Elipse::Elipse(const Elipse& obj)
{
	this->name = obj.name;
	this->a = obj.a;
	this->b = obj.b;
	this->x = obj.x;
	this->y = obj.y;
}

inline Elipse& Elipse::operator=(const Elipse& obj)
{
	this->name = obj.name;
	this->a = obj.a;
	this->b = obj.b;
	this->x = obj.x;
	this->y = obj.y;
}

void Elipse::Show()
{
	cout << name << " x: " << x << " y: " << y << " a: " << a << " b: " << b ;
}

inline void Square::Save()
{
	string fName = "myFile.txt"; 
	
	fstream fout;

	fout.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fout.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		cout << "Square успешно записан!" << endl;		
		fout << this->name << " " << this->a << " " << this->b << "\n";
	}

	fout.close();
}

inline void Square::Load(int index)
{
	string fName = "myFile.txt";

	fstream fin;
	int i = -1;
	string ch;
	fin.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fin.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		do
		{	
			i++;

			if (i == index) //Проверка номера строки
			{
				cout << "Square успешно считан!" << endl;
				fin >> this->name >> this->a >> this->b;
			}
			getline(fin, ch);//считывает одну строку файла
			
		} while (i != index);		
	}

	fin.close();
}

inline void Circle::Save()
{
	string fName = "myFile.txt";

	fstream fout;

	fout.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fout.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		cout << "Circle успешно записан!" << endl;
		fout << this->name << " " << this->x << " " << this->y << "\n";
	}

	fout.close();
}

inline void Circle::Load(int index)
{
	string fName = "myFile.txt";

	fstream fin;
	int i = -1;
	string ch;
	fin.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fin.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		do
		{
			i++;

			if (i == index) //Проверка номера строки
			{
				cout << "Circle успешно считан!" << endl;
				fin >> this->name >> this->x >> this->y;
			}
			getline(fin, ch);//считывает одну строку файла

		} while (i != index);
	}

	fin.close();
}



inline void CRectangle::Save()
{
	string fName = "myFile.txt";

	fstream fout;

	fout.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fout.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		cout << "CRectangle успешно записан!" << endl;
		fout << this->name << " " << this->a << " " << this->b << "\n";
	}

	fout.close();
}

inline void CRectangle::Load(int index)
{
	string fName = "myFile.txt";

	fstream fin;
	int i = -1;
	string ch;

	fin.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fin.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		do
		{
			i++;

			if (i == index) //Проверка номера строки
			{
				cout << "CRectangle успешно считан!" << endl;
				fin >> this->name >> this->a >> this->b;
			}
			getline(fin, ch);//считывает одну строку файла

		} while (i != index);
	}

	fin.close();
}

inline void Elipse::Save()
{
	string fName = "myFile.txt";

	fstream fout;

	fout.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fout.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		cout << "CRectangle успешно записан!" << endl;
		fout << this->name << " " << this->x << " " << this->y << " " << this->a << " " << this->b << "\n";
	}

	fout.close();
}

inline void Elipse::Load(int index)
{
	string fName = "myFile.txt";

	fstream fin;

	int i = -1;
	string ch;

	fin.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fin.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		do
		{
			i++;

			if (i == index) //Проверка номера строки
			{
				cout << "Elipse успешно считан!" << endl;
				fin >> this->name >> this->x >> this->y >> this->a >> this->b;
			}
			getline(fin, ch);//считывает одну строку файла

		} while (i != index);
	}

	fin.close();
}

inline ostream& operator<<(ostream& out, const Shape& obj)
{
	out << obj.name;
	return out;
}

inline ostream& operator<<(ostream& out, const Square& obj)
{
	out << obj.name << " " << obj.a << " " << obj.b;
	return out;
}

ostream& operator << (ostream& out, const Circle& obj)
{
	out << obj.name << " " << obj.x << " " << obj.y;
	return out;
}

inline ostream& operator<<(ostream& out, const CRectangle& obj)
{
	out << obj.name << " " << obj.a << " " << obj.b;
	return out;
}

inline ostream& operator<<(ostream& out, const Elipse& obj)
{
	out << obj.name << " " << obj.x << " " << obj.y << " " << obj.a << " " << obj.b;
	return out;
}


inline istream& operator>>(istream& in, Shape& obj)
{
	in >> obj.name;
	return in;
}


inline Square::~Square()
{
	cout << "Вызвался деструктор Square" << endl;;
}

inline Circle::~Circle()
{
	cout << "Вызвался деструктор Circle " << endl;;
}