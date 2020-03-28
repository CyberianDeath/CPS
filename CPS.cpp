
#include"CPS.hpp"

#include<math.h>
using std::cos;
using std::sin;

// Circle

Circle::Circle(double radius):_radius_(radius) {}

double Circle::getHeight() const {
	return _radius_ * 2;
}

double Circle::getWidth() const{
	return getHeight();
}


// Polygon

Polygon::Polygon(int numSides, double sideLength):_numSides_(numSides),_sideLength_(sideLength) {}

double Polygon::getHeight() const {
	double height = 0.0;

	if (_numSides_ % 2 == 0) {
		height = (_sideLength_ * cos(3.14 / _numSides_)) / sin(3.14 / _numSides_);
	}
	else {
		height = (_sideLength_ * (1 + cos(3.14 / _numSides_))) / (2 * sin(3.14 / _numSides_));
	}
	return height;
}

double Polygon::getWidth() const {
	double width = 0.0;

	if (_numSides_ % 4 == 0) {
		width = (_sideLength_ * cos(3.14 / _numSides_)) / sin(3.14 / _numSides_);
	}
	else if(_numSides_ % 2 ==0) {
		width = _sideLength_ / sin(3.14 / _numSides_);
	}
	else {
		width = (_sideLength_ * sin(3.14 * (_numSides_ - 1.0) / 2 * _numSides_)) / (sin(3.14 / _numSides_));
	}
	return width;
}

// Rectangle

Rectangle::Rectangle(double width, double height) : _width_(width), _height_(height) {}

double Rectangle::getHeight() const {
	return _height_;
}

double Rectangle::getWidth() const {
	return _width_;
}

// Spacer

Spacer::Spacer(double width, double height): Rectangle(width, height) {}

// Square

Square::Square(double sideLength): Polygon(4, sideLength) {}

// Traingle

Triangle::Triangle(double sideLength): Polygon(3, sideLength) {}

