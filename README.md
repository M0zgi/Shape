Курс «Объектно-ориентированное программирование на C++» 
Неделя №13

Задание 2.
Создайте абстрактный класс Shape для рисования плоских фигур. 
Определите виртуальные методы:
• Show() — вывод на экран информации о фигуре,
• Save() — сохранение фигуры в файл,
• Load() — считывание фигуры из файла.

Определите производные классы:
• Square — квадрат, который характеризуется координатами левого верхнего угла и длиной стороны;
• Rectangle — прямоугольник с заданными координатами верхнего левого угла и размерами;
• Circle — окружность с заданными координатами центра и радиусом;
• Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него прямоугольника состоронами, параллельными осям координат, 
и размерами этого прямоугольника.

Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой из фигур.
