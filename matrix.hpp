#pragma once
#include "vec4.hpp"
#include "vec3.hpp"


namespace vpanic {

	class Matrix {
	public:

		Matrix(const float t);
		Matrix(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d);
		Matrix() {}
		
		Matrix   operator +  (const Matrix& a);
		Matrix&  operator += (const Matrix& a);
		Matrix   operator -  (const Matrix& a);
		Matrix&  operator -= (const Matrix& a);
		Matrix   operator *  (const Matrix& a);
		Matrix&  operator *= (const Matrix& a);

		Vec4     operator [] (const unsigned char i) const;
		Vec4&    operator [] (const unsigned char i);

	private:

		Vec4 m[4];

	};

	void translate(Matrix& mat, const Vec3& pos);
	void scale(Matrix& mat, const Vec3& vec);
	void rotate(Matrix& mat, const Vec3& r, const float angle);

}



