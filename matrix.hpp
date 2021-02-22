#pragma once
#include "types.hpp"

//
//  https://github.com/331uw13/math
//

namespace vpanic {

	struct Matrix {

		Matrix(const float t) {
			m[0] = Vec4(t,    0.0f, 0.0f, 0.0f);
			m[1] = Vec4(0.0f, t,    0.0f, 0.0f);
			m[2] = Vec4(0.0f, 0.0f, t,    0.0f);
			m[3] = Vec4(0.0f, 0.0f, 0.0f, t   );
		}

		Matrix(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d) {
			m[0] = a;
			m[1] = b;
			m[2] = c;
			m[3] = d;
		}

		Matrix() {}
		
		// ------------------------------------

		Matrix operator + (const Matrix& a) {
			return Matrix(m[0]+a[0], m[1]+a[1], m[2]+a[2], m[3]+a[3]);
		}

		Matrix& operator += (const Matrix& a) {
			m[0] += a[0];
			m[1] += a[1];
			m[2] += a[2];
			m[3] += a[3];
			return *this;
		}

		Matrix operator - (const Matrix& a) {
			return Matrix(m[0]-a[0], m[1]-a[1], m[2]-a[2], m[3]-a[3]);
		}

		Matrix& operator -= (const Matrix& a) {
			m[0] -= a[0];
			m[1] -= a[1];
			m[2] -= a[2];
			m[3] -= a[3];
			return *this;
		}
	
		// ------------------------------------

		Vec4 operator [] (const uni8 i) const {
			assert(i <= 3);
			return m[i];
		}

		Vec4& operator [] (const uni8 i) {
			assert(i <= 3);
			return m[i];
		}

	   	// ---------------------------

	private:

		Vec4 m[4] { 
			Vec4(0.0f),
			Vec4(0.0f),
			Vec4(0.0f),
			Vec4(0.0f)
		};

	};

}
