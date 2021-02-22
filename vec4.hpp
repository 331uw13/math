#pragma once

//
//  https://github.com/331uw13/math
//

namespace vpanic {

	struct Vec4 {
		
		float x  { 0.0f };
		float y  { 0.0f };
		float z  { 0.0f };
		float w  { 0.0f };


		Vec4(const float t_xyzw)
			: x(t_xyzw), y(t_xyzw), z(t_xyzw), w(t_xyzw) {}

		Vec4(const float t_x, const float t_y, const float t_z, const float t_w)
			: x(t_x), y(t_y), z(t_z), w(t_w) {}

		Vec4() {}


		Vec4 operator + (const Vec4& a) {
			return Vec4(x+a.x, y+a.y, z+a.z, w+a.w);
		}
		
		Vec4& operator += (const Vec4& a) {
			x += a.x;
			y += a.y;
			z += a.z;
			w += a.w;
			return *this;
		}

		Vec4 operator - (const Vec4& a) {
			return Vec4(x-a.x, y-a.y, z-a.z, w-a.w);
		}
		
		Vec4& operator -= (const Vec4& a) {
			x -= a.x;
			y -= a.y;
			z -= a.z;
			w -= a.w;
			return *this;
		}

	};

}
