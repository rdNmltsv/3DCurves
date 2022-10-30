#pragma once

#include "3D_Base.h"

class Ellipse3D : public Curve3D {
public:
	Ellipse3D(Point3D center, Scalar radiusX, Scalar radiusY);

	Point3D getCenter() noexcept { 
		return _center; 
	};
	
	Scalar getRadiusX() noexcept {
		return _radiusX;
	}
	
	Scalar getRadiusY() noexcept {
		return _radiusY;
	}
	
public:
	Point3D	GetPoint(Scalar angle) const noexcept override;
	
	// Vector3D GetFirstDerivative();
private:
	Point3D _center;
	Scalar _radiusX;
	Scalar _radiusY;
};