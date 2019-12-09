#include <iostream>
#include "GridCell.h"

using namespace std;
using namespace VTKContour;

int main()
{
	GridCell gridCell(0, 4, 4);
	gridCell.setPointVertex(0, Point(10, 10, 10));

	Point vertexPoint = gridCell.getPointVertex(10);

	cout << "[ X: " << vertexPoint.x << " ] | "
		<< "[ Y: " << vertexPoint.y << " ] | "
		<< "[ Z: " << vertexPoint.z << " ]" << endl;

	cout << "Struct size: " << sizeof(gridCell) << " bytes" << endl;

	system("PAUSE");
	return 0;
}