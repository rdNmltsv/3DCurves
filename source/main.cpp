#include "3D_Base.h"
#include "3D_Circle.h"
#include "3D_Ellipse.h"
#include "3D_Helix.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <typeinfo>
#include <algorithm>
#include <iterator>

class PRNG {
public:
	PRNG() {
		std::random_device rd;
		_engine.seed(rd());
	}
	
public:
	int GetRandomInt(int min, int max) noexcept {
		std::uniform_int_distribution uniform_distribution(min, max);
		return uniform_distribution(_engine);
	}
	
	double GetRandomReal(double min, double max) noexcept {
		std::uniform_real_distribution uniform_distribution(min, max);
		return uniform_distribution(_engine);
	}
	
private:
	std::mt19937 _engine;
};

int main() {
	PRNG prng;
	
	std::vector<Curve3D*> curves;
	curves.reserve(10);
	
	// populate a container of curves created in random manner with random parameters
	for(std::size_t i = 0; i < 10; ++i) {
		int rand_curve = prng.GetRandomInt(0, 2);
		Point3D rand_center = Point3D(prng.GetRandomReal(-100.0, 100.0), prng.GetRandomReal(-100.0, 100.0), prng.GetRandomReal(-100.0, 100.0));
		Scalar rand_radius = prng.GetRandomReal(0.1, 100.0);
		
		switch(rand_curve) {
			case 0: { // circle
				curves.push_back(new Circle3D(rand_center, rand_radius));
				break;
			}
			case 1: { // ellipse, using rand_radius as radiusX
				Scalar rand_radiusY = prng.GetRandomReal(0.1, 100.0);
				curves.push_back(new Ellipse3D(rand_center, rand_radius, rand_radiusY));
				break;
			}
			case 2: { // helix
				Scalar rand_step = prng.GetRandomReal(0.1, 10.0);
				curves.push_back(new Helix3D(rand_center, rand_radius, rand_step));
				break;
			}
			default: {
				std::cerr << "Randomed wrong curve type." << std::endl;
				return -1;
			}
		}
	}	
	
	// print coordinates of points and derivatives of all curves in the container at t=PI/4.
	for (constexpr Scalar parameter = std::numbers::pi / 4; const auto& curve : curves) {
		std::cout << "Point (" << typeid(*curve).name() << "): " << curve->GetPoint(parameter) << '\n';
		// std::cout << "First derivative: " << curve->GetFirstDerivative(paremater) << '\n';
	}
	
	// populate a second container that would contain only circles from the first container. 
	// make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers
	std::vector<Circle3D*> circles;
	
	for(const auto& curve : curves) {
		if (typeid(*curve) == typeid(Circle3D)) {
			circles.push_back(dynamic_cast<Circle3D*>(curve));
		}
	}
	
	// sort the second container in the ascending order of circles radii
	std::sort(circles.begin(), circles.end(), 
		[](Circle3D* lhs, Circle3D* rhs) {
			return lhs->getRadius() < rhs->getRadius();
		}
	);
	std::cout << "Sorted circles in the ascending order of circles radii: ";
	for(const auto& circle : circles) {
		std::cout << circle->getRadius() << ' ';
	}
	std::cout << '\n';
	
	// compute the total sum of radii of all curves (circles) in the second container
	std::cout << "Sum of circles radii: " << std::accumulate(circles.cbegin(), circles.cend(), 0.0, 
		[](Scalar lhs, Circle3D* rhs) {
			return lhs + rhs->getRadius();
		}
	);
	
	// delete allocated objects, circles pointers in vector circles are invalid until now
	for(const auto& curve : curves) {
		delete curve;
	}
	
	std::cout << std::endl;
	return 0;
}