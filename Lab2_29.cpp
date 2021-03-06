﻿/*Радкевич Ю.С. 91 группа
Создать абстрактный базовый класс Triangle для представления треугольника с
виртуальными функциями вычисления площади и периметра.Поля данных должны
включать две стороны и угол между ними.Определить классы - наследники:
прямоугольный треугольник, равнобедренный треугольник, равносторонний треугольник
со своими функциями вычисления площади и периметра.
*/

#include "pch.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <iostream>
#include <string>

using namespace std;

class Triangle {
protected:
	double a=0,b=0;
	double alpha=0;
public:
	virtual double getSquare() = 0;
	virtual double getPerimetr() = 0;

	virtual void setA(double aA) 
	{
		if (aA > 0)
			a = aA;
	}

	virtual void setB(double aB) 
	{
		if (aB > 0)
			b = aB;
	}

	virtual void setAlpha(double aAlpha)
	{
		if (aAlpha < 180 && aAlpha>0)
			alpha = aAlpha;
	}
	double getA() 
	{ 
		return a; 
	}
	double getB() 
	{ 
		return b; 
	}
	double getAlpha() 
	{ 
		return alpha;
	}

	string ToString() {
		return "Tringle: a=" + to_string(a) + " b=" + to_string(b) + " alpha=" + to_string(alpha);
	}
};


class RightAngled_Triangle : public Triangle
{
public:
	RightAngled_Triangle():Triangle(){}
	RightAngled_Triangle(double aA, double aB)
	{
		setA(aA);
		setB(aB);
		alpha = 90;
	}

	double getSquare() override
	{
			return a * b / 2;
	}

	double getPerimetr() override
	{
			return a + b +sqrt(a*a+b*b);
	}

	void setAlpha(double aAlpha) override
	{
		cout << "В прямоугольном треугольнике угол равен 90, Вы не можете его изменить";
	}

};

class Isosceles_Triangle : public Triangle
{
public:
	Isosceles_Triangle() :Triangle() {}
	Isosceles_Triangle(double aA, double aB, double aAlpha)
	{
		setA(aA);
		setB(aB);
		setAlpha(aAlpha);
	}

	double getSquare() override
	{
		return a * b * sin(alpha*M_PI /180)/2;
	}

	double getPerimetr() override
	{
		return a+b+sqrt(a*a+b*b-2*a*b*cos(alpha*M_PI / 180));
	}

	void setA(double aA) override
	{
		if (aA > 0) {
			b = a = aA;
		}			
	}

	void setB(double aB) override
	{
		if (aB > 0) {
			b = a = aB;
		}
	}

};

class Equilateral_Triangle : public Triangle
{
public:
	Equilateral_Triangle() :Triangle() {}
	Equilateral_Triangle(double aA, double aB) 
	{
		setA(aA);
		setB(aB);
		alpha=60;
	}

	double getSquare() override
	{
		return a * a * sqrt(3)/4;
	}

	double getPerimetr() override
	{
		return 3 * a;
	}

	void setA(double aA) override
	{
		if (aA > 0) {
			b = a = aA;
		}
	}

	void setB(double aB) override
	{
		if (aB > 0) {
			a = b = aB;
		}
	}
	void setAlpha(double aAlpha) override
	{
		cout << "В равностороннем треугольнике угол равен 60, Вы не можете его изменить";
	}

};

int main()
{
	setlocale(LC_ALL, "rus");
	Triangle* tr= nullptr;
	double a, b, alpha;

	do {
		cin >> a >> b >> alpha;
	} while (a <= 0 || b <= 0 || alpha >= 180 || alpha <= 0);

	char c = getchar();

	if (alpha == 90)
		tr = new RightAngled_Triangle(a, b);
	else
		if (a == b) {
			if (alpha == 60)
				tr = new Equilateral_Triangle(a, b);
			else
				tr = new Isosceles_Triangle(a, b, alpha);
		}
	if (tr == nullptr)
		cout << "Треугольник не является ни прямоугольным, ни правильным, ни равнобедренным";
	else {
		cout << "Периметр: " << tr->getPerimetr() << endl;
		cout << "Площадь: " << tr->getSquare()<< endl;
	}

	c = getchar();
	return 0;
		
}

