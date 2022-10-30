#include "3D_Base.h"
#include <iostream>

Point3D::Point3D(Scalar x, Scalar y, Scalar z) :
	x(x),
	y(y),
	z(z)
{}

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
	os << point.x << ", " << point.y << ", " << point.z;
	return os;
}

Vector3D::Vector3D(Scalar x, Scalar y, Scalar z) :
	_coordX(x),
	_coordY(y),
	_coordZ(z)
{}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec3d) {
	os << vec3d._coordX << ", " << vec3d._coordY << ", " << vec3d._coordZ;
	return os;
}