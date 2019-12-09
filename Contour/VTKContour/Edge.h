#pragma once

namespace VTKContour
{
	struct Edge
	{
		int first_vertex, second_vertex;

		Edge(int first_vertex, int second_vertex)
		{
			this->first_vertex = first_vertex;
			this->second_vertex = second_vertex;
		}
	};
}