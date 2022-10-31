#include "3D_Circle.h"
#include <cmath>
#include <numbers>

Circle3D::Circle3D(Point3D center, Scalar radius) :
	_center(center),
	_radius(std::abs(radius))
{
	_center.z = 0;
}

Point3D Circle3D::GetPoint(Scalar parameter) const noexcept {
	parameter = std::abs(parameter);
	
	Scalar x = _center.x + _radius * std::cos(parameter);
	Scalar y = _center.y + _radius * std::sin(parameter);
	
	return Point3D(x, y, 0);
}

Vector3D Circle3D::GetFirstDerivative(Scalar parameter) const noexcept {
	parameter = std::abs(parameter);
	
	Scalar x = _radius * (-std::sin(parameter));
	Scalar y = _radius * std::cos(parameter);
	
	return Vector3D(x, y, 0);
}