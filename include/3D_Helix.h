#pragma once

#include "3D_Base.h"

class Helix3D : public Curve3D {
public:
	Helix3D(Point3D center, Scalar radius, Scalar step);

	Point3D getCenter() noexcept { 
		return _center;
	};
	
	Scalar getRadius() noexcept {
		return _radius;
	}
	
	Scalar getStep() noexcept {
		return _step;
	}
	
public:
	Point3D	GetPoint(Scalar angle) const noexcept override;
	
	// Vector3D GetFirstDerivative();
private:
	Point3D _center;
	Scalar _radius;
	Scalar _step;
};