#include "3D_Circle.h"
#include <cmath>
#include <numbers>

Circle3D::Circle3D(Point3D center, Scalar radius) :
	_center(center),
	_radius(std::abs(radius))
{
	_center.z = 0;
}

Point3D Circle3D::GetPoint(Scalar angle) const noexcept {
	angle = std::abs(angle);
	
	Scalar x = _center.x + _radius * (std::cos(angle));
	Scalar y = _center.y + _radius * (std::sin(angle));
	
	return Point3D(x, y, 0);
}