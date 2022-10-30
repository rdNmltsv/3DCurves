#pragma once
#include <iosfwd>

using Scalar = double;

class Point3D {
public:
	Point3D(Scalar x, Scalar y, Scalar z);

	friend std::ostream& operator<<(std::ostream& os, const Point3D& point);
	
public:	
	Scalar x;
	Scalar y;
	Scalar z;
};

class Vector3D {
public:
	Vector3D(Scalar x, Scalar y, Scalar z);
	
	Scalar getX() const noexcept {
		return _coordX;
	}
	
	Scalar getY() const noexcept {
		return _coordY;
	}
	
	Scalar getZ() const noexcept {
		return _coordZ;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec3d);
	
private:
	Scalar _coordX;
	Scalar _coordY;
	Scalar _coordZ;
};

class Curve3D {
public:
	virtual Point3D GetPoint(Scalar parameter) const noexcept { return Point3D(0, 0, 0); };
	virtual Vector3D GetFirstDerivative(Scalar parameter) const noexcept { return Vector3D(0, 0, 0); };
};