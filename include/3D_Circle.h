#pragma once

#include "3D_Base.h"

class Circle3D : public Curve3D {
public:
	Circle3D(Point3D center, Scalar radius);

	Point3D getCenter() noexcept { 
		return _center;
	};
	
	Scalar getRadius() noexcept {
		return _radius;
	}

public:
	Point3D	GetPoint(Scalar parameter) const noexcept override;
	
	Vector3D GetFirstDerivative(Scalar parameter) const noexcept override;

private:
	Point3D _center;
	Scalar _radius;
};