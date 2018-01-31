#ifndef MATH_H
#define MATH_H

#include <math.h>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

#define _USE_MATH_DEFINES

namespace Sparky { namespace Math {

	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

}}

#endif
