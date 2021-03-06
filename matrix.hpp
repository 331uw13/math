#pragma once
#include <cmath>
#include "types.hpp"


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
		
		Matrix operator + (const Matrix& a) {
			return Matrix(
					Vec4( m[0].x+a[0].x, m[0].y+a[0].y, m[0].z+a[0].z, m[0].w+a[0].w ),
					Vec4( m[1].x+a[1].x, m[1].y+a[1].y, m[1].z+a[1].z, m[1].w+a[1].w ),
					Vec4( m[2].x+a[2].x, m[2].y+a[2].y, m[2].z+a[2].z, m[2].w+a[2].w ),
					Vec4( m[3].x+a[3].x, m[3].y+a[3].y, m[3].z+a[3].z, m[3].w+a[3].w )
					);
		}

		Matrix& operator += (const Matrix& a) {
			for(int i = 0; i < 4; i++) {
				m[i].x += a[i].x;
				m[i].y += a[i].y;
				m[i].z += a[i].z;
				m[i].w += a[i].w;
			}
			return *this;
		}

		Matrix operator - (const Matrix& a) {
			return Matrix(
					Vec4( m[0].x-a[0].x, m[0].y-a[0].y, m[0].z-a[0].z, m[0].w-a[0].w ),
					Vec4( m[1].x-a[1].x, m[1].y-a[1].y, m[1].z-a[1].z, m[1].w-a[1].w ),
					Vec4( m[2].x-a[2].x, m[2].y-a[2].y, m[2].z-a[2].z, m[2].w-a[2].w ),
					Vec4( m[3].x-a[3].x, m[3].y-a[3].y, m[3].z-a[3].z, m[3].w-a[3].w )
					);
		}

		Matrix& operator -= (const Matrix& a) {
			for(int i = 0; i < 4; i++) {
				m[i].x -= a[i].x;
				m[i].y -= a[i].y;
				m[i].z -= a[i].z;
				m[i].w -= a[i].w;
			}
			return *this;
		}
	
		Matrix operator * (const Matrix& a) {
			Matrix tmp(m[0], m[1], m[2], m[3]);
			for(int i = 0; i < 4; i++) {
				tmp[i] = Vec4( 
						tmp[i].x*a[0].x + tmp[i].y*a[1].x + tmp[i].z*a[2].x + tmp[i].w*a[3].x,
						tmp[i].x*a[0].y + tmp[i].y*a[1].y + tmp[i].z*a[2].y + tmp[i].w*a[3].y,
						tmp[i].x*a[0].z + tmp[i].y*a[1].z + tmp[i].z*a[2].z + tmp[i].w*a[3].z,
						tmp[i].x*a[0].w + tmp[i].y*a[1].w + tmp[i].z*a[2].w + tmp[i].w*a[3].w
						);
			}
			return tmp;
		}

		Matrix& operator *= (const Matrix& a) {
			for(int i = 0; i < 4; i++) {
				m[i] = Vec4( 
						m[i].x*a[0].x + m[i].y*a[1].x + m[i].z*a[2].x + m[i].w*a[3].x,
						m[i].x*a[0].y + m[i].y*a[1].y + m[i].z*a[2].y + m[i].w*a[3].y,
						m[i].x*a[0].z + m[i].y*a[1].z + m[i].z*a[2].z + m[i].w*a[3].z,
						m[i].x*a[0].w + m[i].y*a[1].w + m[i].z*a[2].w + m[i].w*a[3].w
						);
			}
			return *this;
		}
		
		Vec4 operator [] (const uni8 i) const {
			assert(i <= 3);
			return m[i];
		}

		Vec4& operator [] (const uni8 i) {
			assert(i <= 3);
			return m[i];
		}

	private:
		Vec4 m[4];
	};

	void translate(Matrix& mat, const Vec3& pos) {
		mat[3] = Vec4(
				mat[0].x*pos.x + mat[1].x*pos.y + mat[2].x*pos.z + mat[3].x,
				mat[0].y*pos.x + mat[1].y*pos.y + mat[2].y*pos.z + mat[3].y,
				mat[0].z*pos.x + mat[1].z*pos.y + mat[2].z*pos.z + mat[3].z,
				mat[0].w*pos.x + mat[1].w*pos.y + mat[2].w*pos.z + mat[3].w
				);
	}

	void scale(Matrix& mat, const Vec3& pos) {
		mat[0].x *= pos.x;
		mat[0].y *= pos.x;
		mat[0].z *= pos.x;
		mat[0].w *= pos.x;
		mat[1].x *= pos.y;
		mat[1].y *= pos.y;
		mat[1].z *= pos.y;
		mat[1].w *= pos.y;
		mat[2].x *= pos.z;
		mat[2].y *= pos.z;
		mat[2].z *= pos.z;
		mat[2].w *= pos.z;
	}

	void rotate(Matrix& mat, const Vec3& r, const float angle) {
		// eh... i will do this one later
	}


}






