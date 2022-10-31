#include "3D_Base.h"
#include <iostream>
#include <iomanip>

Point3D::Point3D(Scalar x, Scalar y, Scalar z) :
	x(x),
	y(y),
	z(z)
{}

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
	os << std::right << std::fixed << std::setprecision(4)
	<< std::setw(9) << point.x << ", " 
	<< std::setw(9) << point.y << ", " 
	<< std::setw(9) << point.z;
	return os;
}

Vector3D::Vector3D(Scalar x, Scalar y, Scalar z) :
	_coordX(x),
	_coordY(y),
	_coordZ(z)
{}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec3d) {
	os << std::right << std::fixed << std::setprecision(4)
	<< std::setw(9) << vec3d._coordX << ", " 
	<< std::setw(9) << vec3d._coordY << ", " 
	<< std::setw(9) << vec3d._coordZ;
	return os;
}