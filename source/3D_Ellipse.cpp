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

Point3D Ellipse3D::GetPoint(Scalar parameter) const noexcept {
	parameter = std::abs(parameter);
	
	Scalar x = _center.x + _radiusX * std::cos(parameter);
	Scalar y = _center.y + _radiusY * std::sin(parameter);
	
	return Point3D(x, y, 0);
}

Vector3D Ellipse3D::GetFirstDerivative(Scalar parameter) const noexcept {
	parameter = std::abs(parameter);
	
	Scalar x = _radiusX * (-std::sin(parameter));
	Scalar y = _radiusY * std::cos(parameter);
	
	return Vector3D(x, y, 0);
}