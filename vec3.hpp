#pragma once

//
//  https://github.com/331uw13/math
//

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

	};

}
