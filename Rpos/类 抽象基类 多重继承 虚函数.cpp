/*
例12.4 虚函数和抽象基类的应用。 在本章例12.1介绍了以Point为基类的点—圆—圆柱体类的层次结构。
现在要对它进行改写，在程序中使用虚函数和抽象基类。 类的层次结构的顶层是抽象基类Shape(形状)。
Point(点), Circle(圆), Cylinder(圆柱体)都是Shape类的直接派生类和间接派生类。

*/ 
//2018年5月7日16:39:55

#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;
//虚拟基类 shape
class Shape
{		
	virtual float area() { return 1; };
	virtual float volume() { return 1; };
	virtual void shapeName() const { };
};

//point 类 ：public shape
class Point: public Shape
{
public:
	float x, y;
public:
	Point(float  x = 0, float y = 0);
	void setPoint(float, float);
	float getX() const{ return x; }
	float getY() const{ return y; }
    virtual void shapeName() const{ cout << "point:"; }//虚函数重载
	friend ostream & operator <<(ostream &, const Point &);
};

Point::Point(float a, float b){
	x = a;
	y = b;
}

void Point::setPoint(float a, float b)
{
	x = a;
	y = b;
}

ostream & operator <<(ostream &output, const Point &p)
{
	cout << "point location : "<<"[" << p.x << " , " << p.y << "]" << endl;
	return output;
}


//circle 类： public point
class Circle : public Point
{
protected:
	float radius;
public:
	Circle(float x = 0, float y = 0, float r = 0);
	void setRadius(float);
	float getRadius()const;
    virtual float area()const;
	virtual void shapName() const
	{ 
		cout << "Circle: "<<endl;
	}
	friend ostream &operator<<(ostream &, const Circle &);

};

Circle::Circle(float a, float b, float r) :Point(a, b), radius(r){}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

float Circle::area() const
{
	return(float(3.14*radius*radius));
}

ostream &operator <<(ostream &output, const Circle &c)
{
	cout << "Circle : " << "[ " << c.x << " , " << c.y << " ] "
		<< "radius ;" << c.radius << endl;
	return output;
}

//cylinder 类：public circle

class Cylinder : public Circle
{
protected:
	float height;
public:
	Cylinder(float x = 0, float y = 0, float radius = 0, float h = 0);
	void setHeight(float);
    virtual float area() const;
	virtual float volume() const;
	friend ostream &operator <<(ostream &, const Cylinder &);
};

Cylinder :: Cylinder(float x, float y, float r, float h) 
	:Circle(x, y, r), height(h){}


void Cylinder::setHeight(float h)
{
	height = h;
}

float Cylinder::area() const
{
	return(float(2 * Circle::area() + 2 * 3.14 * radius * height));
}

float Cylinder::volume()const
{
	return (Circle::area() * height );
}

ostream &operator <<(ostream & output,const Cylinder &C)
{
	cout << "Cylinder : " << "[ " <<C.x<< " , " <<C.y<<" ] "
		<<" radius: "<< C.radius << " height: " << C.height<< endl;
	return output;
}

int main()
{
	Point myPoint(2.2, 3.3);
	Circle myCircle(2.2, 3.3, 5);
	Cylinder myCylinder(2.2, 3.3 ,5, 4);

	//显示myPoint, myCircle MyCylinder信息
	//编译时，成员函数的重载和运算符的重载表现多态性
	cout << myPoint;
	cout << myCircle;
	cout << myCylinder;

	//运行时的虚函数和类的继承表现动态

	cout <<"Circle area "<< myCircle.area() << endl;;
	cout<< "Cylinder area "<<myCylinder.area() << endl;

} 

