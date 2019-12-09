#pragma once

namespace VTKContour
{
	struct Point
	{
		float x, y, z;

		Point()
		{
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
		}

		Point(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
	};
}