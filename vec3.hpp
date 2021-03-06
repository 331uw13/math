#pragma once
#include <cmath>

namespace vpanic {

	struct Vec3 {
		
		float x  { 0.0f };
		float y  { 0.0f };
		float z  { 0.0f };


		Vec3(const float t_xyz)
			: x(t_xyz), y(t_xyz), z(t_xyz) {}

		Vec3(const float t_x, const float t_y, const float t_z)
			: x(t_x), y(t_y), z(t_z) {}

		Vec3() {}


		bool all(const float v) const {
			return (x == v && y == v && z == v);
		}

		float length() const {
			return sqrt(x*x+y*y+z*z);
		}

		Vec3 normalize() const {
			const float l = length();
			return Vec3(x/l, y/l, z/l);
		}

		void normalize_self() {
			const float l = length();
			x /= l;
			y /= l;
			z /= l;
		}


	};

}

