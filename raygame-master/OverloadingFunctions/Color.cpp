#include "Color.h"

MyColor::MyColor()
{
	r = 0;
	g = 0;
	b = 0;
	a = 255;
}
MyColor::MyColor(int red, int green, int blue, int alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}


MyColor MyColor::operator+(const MyColor &rhs) const
{
	MyColor Temp = (*this);

	Temp.r += rhs.r;
	Temp.g += rhs.g;
	Temp.b += rhs.b;
	Temp.a += rhs.a;

	return Temp;
}

MyColor MyColor::operator-(const MyColor &rhs) const
{
	MyColor Temp = rhs;

	Temp.r -= r;
	Temp.g -= g;
	Temp.b -= b;
	Temp.a -= a;

	return Temp;
}

MyColor MyColor::operator*(const MyColor &rhs) const
{
	MyColor Temp = rhs;

	Temp.r *= r;
	Temp.g *= g;
	Temp.b *= b;
	Temp.a *= a;

	return Temp;
}

MyColor MyColor::operator/(const MyColor &rhs) const
{
	MyColor Temp = rhs;

	Temp.r /= r;
	Temp.g /= g;
	Temp.b /= b;
	Temp.a /= a;

	return Temp;
}

MyColor& MyColor::operator+=(const MyColor &rhs)
{
	(*this) += (*this) + rhs;
	return (*this);
}
MyColor& MyColor::operator-=(const MyColor &rhs)
{
	(*this) -= (*this) - rhs;
	return (*this);
}
MyColor& MyColor::operator*=(const MyColor &rhs)
{
	(*this) *= (*this) * rhs;
	return (*this);
}
MyColor& MyColor::operator/=(const MyColor &rhs)
{
	(*this) /= (*this) / rhs;
	return (*this);
}

bool MyColor::operator==(const MyColor &rhs) const
{
	return(rhs.r == r && rhs.g == g && rhs.b == b && rhs.a == a);
}
bool MyColor::operator!=(const MyColor &rhs) const
{
	return(rhs.r != r && rhs.g != g && rhs.b != b && rhs.a != a);
}

MyColor MyColor::operator!() const
{
	MyColor Temp = (*this);
	Temp.r = !r * 255;
	Temp.g = !g * 255;
	Temp.b = !b * 255;
	Temp.a = !a * 255;

	return Temp;
}

MyColor MyColor::Clamp(MyColor &rhs)
{
	MyColor NewColor;
	return NewColor;
}