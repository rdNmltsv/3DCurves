#include "3D_Ellipse.h"
#include <cmath>
#include <numbers>

Ellipse3D::Ellipse3D(Point3D center, Scalar radiusX, Scalar radiusY) :
	_center(center),
	_radiusX(std::abs(radiusX)),
	_radiusY(std::abs(radiusY))
{
	_center.z = 0;
}

Point3D Ellipse3D::GetPoint(Scalar angle) const noexcept {
	angle = std::abs(angle);
	
	Scalar x = _center.x + _radiusX * (std::cos(angle));
	Scalar y = _center.y + _radiusY * (std::sin(angle));
	
	return Point3D(x, y, 0);
}