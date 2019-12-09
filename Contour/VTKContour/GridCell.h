#pragma once

#include "LogHelper.h"
#include "ErrorCodes.h"
#include "Point.h"

#define NULL		0

namespace VTKContour
{
	class GridCell
	{
		private:
			int idCell;

			int vertexCount, edgeCount;

			Point *pointVertex = NULL;
			float *scalarVertex = NULL;

			bool *visitedEdge = NULL;

			bool isValidVertex(int idVertex);
			bool isValidEdge(int idEdge);
		public:
			GridCell(int idCell, int vertexCount, int edgeCount);
			~GridCell();

			int getIdCell();

			int getVertexCount();
			int getEdgeCount();

			Point getPointVertex(int idVertex);
			void setPointVertex(int idVertex, const Point &p);

			bool getVisitedEdge(int idEdge);
			void setVisitedEdge(int idEdge, bool isVisited);
	};

	GridCell::GridCell(int idCell, int vertexCount, int edgeCount)
	{
		this->idCell = idCell;

		this->vertexCount = vertexCount;
		this->edgeCount = edgeCount;

		this->pointVertex = new Point[vertexCount];
		this->scalarVertex = new float[vertexCount];

		this->visitedEdge = new bool[edgeCount];
	}

	GridCell::~GridCell()
	{
		delete this->pointVertex;
		this->pointVertex = NULL;
		
		delete this->scalarVertex;
		this->scalarVertex = NULL;

		delete this->visitedEdge;
		this->visitedEdge = NULL;
	}

	bool GridCell::isValidVertex(int idVertex)
	{
		if ((idVertex < 0) || (idVertex >= vertexCount))
		{
			LogHelper::log("InvalidVertexIndexException", "O índice do vértice é inválido!");
			exit(InvalidVertexIndexException);
		}

		return true;
	}

	bool GridCell::isValidEdge(int idEdge)
	{
		if ((idEdge < 0) || (idEdge >= edgeCount))
		{
			LogHelper::log("InvalidEdgeIndexException", "O índice da aresta é inválido!");
			exit(InvalidEdgeIndexException);
		}

		return true;
	}

	int GridCell::getIdCell()
	{
		return this->idCell;
	}

	int GridCell::getVertexCount()
	{
		return this->vertexCount;
	}

	int GridCell::getEdgeCount()
	{
		return this->edgeCount;
	}

	Point GridCell::getPointVertex(int idVertex)
	{
		if (isValidVertex(idVertex))
		{
			return this->pointVertex[idVertex];
		}
	}

	void GridCell::setPointVertex(int idVertex, const Point &p)
	{
		if (isValidVertex(idVertex))
		{
			this->pointVertex[idVertex] = p;
		}
	}

	bool GridCell::getVisitedEdge(int idEdge)
	{
		if (isValidEdge(idEdge))
		{
			return this->visitedEdge[idEdge];
		}
	}

	void GridCell::setVisitedEdge(int idEdge, bool isVisited)
	{
		if (isValidEdge(idEdge))
		{
			this->visitedEdge[idEdge] = isVisited;
		}
	}
}