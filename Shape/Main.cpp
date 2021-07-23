#include"Shape.h"


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string fName = "myFile.txt"; // имя файла для сохранения объектов массива

	Square sq(1, 5, "Квадрат");
	//sq.Show();

	CRectangle cr(7, 5, "Прямоугольник");
	//cr.Show();

	Circle ci(2, 8, "Круг");
	//ci.Show();

	Elipse el(1, 5 , 8, 9, "Элипс");
	//el.Show();
	cout << "-------------------------" << endl;
	cout << el << endl;
	cout << "-------------------------" << endl;

	Shape* shapearray[4];

	shapearray[0] = &sq;
	shapearray[1] = &cr;
	shapearray[2] = &ci;
	shapearray[3] = &el;

	for (size_t i = 0; i < 4; i++)
	{
		shapearray[i]->Show();
		cout << endl;
	}
	cout << "-------------------------" << endl;

	for (size_t i = 0; i < 4; i++)
	{
		shapearray[i]->Save();
	}
	cout << endl;
	cout << "-------------------------" << endl;
	
	

	Shape* shapearray1[4];	
	
	fstream fin;
	string ch;

	//Счетчик количества строк в файле
	//int countstr = 0;

	//fin.open(fName, fstream::in | fstream::out | fstream::app);

	//if (fin.is_open())
	//{
	//	do
	//	{

	//		getline(fin, ch);//считывает одну строку файла
	//		countstr++;

	//	} while (!fin.eof());

	//	//cout << countstr;
	//}
	//fin.close();

	fin.open(fName, fstream::in | fstream::out | fstream::app);

	if (!fin.is_open())
		cout << "Ошибка открытия файла!";

	else
	{
		int i = 0;

		while (i != 4)

		{
			fin >> ch;

			if (ch == "Квадрат")
			{
				shapearray1[i] = new Square;
				i++;
			}

			else if (ch == "Прямоугольник")
			{
				shapearray1[i] = new CRectangle;
				i++;
			}
			else if (ch == "Круг")
			{
				shapearray1[i] = new Circle;
				i++;
			}
			else if (ch == "Элипс")
			{
				shapearray1[i] = new Elipse;
				i++;
			}

			else
			{
				//cout << "Фигуру не удалось распознать";
				continue;
			}			
		}

		fin.close();
	}

	for (size_t i = 0; i < 4; i++)
	{
		shapearray1[i]->Load(i);
	}
	cout << endl;
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		shapearray1[i]->Show();
		cout << endl;
	}	

	cout << endl;
	system("pause");
}