/*
��12.4 �麯���ͳ�������Ӧ�á� �ڱ�����12.1��������PointΪ����ĵ㡪Բ��Բ������Ĳ�νṹ��
����Ҫ�������и�д���ڳ�����ʹ���麯���ͳ�����ࡣ ��Ĳ�νṹ�Ķ����ǳ������Shape(��״)��
Point(��), Circle(Բ), Cylinder(Բ����)����Shape���ֱ��������ͼ�������ࡣ

*/ 
//2018��5��7��16:39:55

#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;
//������� shape
class Shape
{		
	virtual float area() { return 1; };
	virtual float volume() { return 1; };
	virtual void shapeName() const { };
};

//point �� ��public shape
class Point: public Shape
{
public:
	float x, y;
public:
	Point(float  x = 0, float y = 0);
	void setPoint(float, float);
	float getX() const{ return x; }
	float getY() const{ return y; }
    virtual void shapeName() const{ cout << "point:"; }//�麯������
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


//circle �ࣺ public point
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

//cylinder �ࣺpublic circle

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

	//��ʾmyPoint, myCircle MyCylinder��Ϣ
	//����ʱ����Ա���������غ�����������ر��ֶ�̬��
	cout << myPoint;
	cout << myCircle;
	cout << myCylinder;

	//����ʱ���麯������ļ̳б��ֶ�̬

	cout <<"Circle area "<< myCircle.area() << endl;;
	cout<< "Cylinder area "<<myCylinder.area() << endl;

} 

