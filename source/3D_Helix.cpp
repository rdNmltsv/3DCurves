#include "3D_Helix.h"
#include <cmath>
#include <numbers>

Helix3D::Helix3D(Point3D center, Scalar radius, Scalar step) :
	_center(center),
	_radius(std::abs(radius)),
	_step(step)
{}

Point3D Helix3D::GetPoint(Scalar parameter) const noexcept {
	parameter = std::abs(parameter);
	
	Scalar x = _center.x + _radius * (std::cos(parameter));
	Scalar y = _center.y + _radius * (std::sin(parameter));
	Scalar z = _center.z + _step * parameter / (2 * std::numbers::pi);
	
	return Point3D(x, y, z);
}