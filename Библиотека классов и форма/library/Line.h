#pragma once
#include"Node.h"
#include"Vertex.h"
#include<cmath>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Line : public Node
{
	int x1;
	int y1;
	int x2;
	int y2;
	int attractionSpacing;
public:
	Line(Node* _left = 0, Node* _right = 0,
		Node* _v1 = 0, Node* _v2 = 0) : Node(_left, _right, _v1, _v2)
	{
		v1 = _v1, v2 = _v2;
		attractionSpacing = 5;
	};
	void set(Node* _left, Node* _right,
		Node* _v1, Node* _v2)
	{
		Node::set(_left, _right, _v1, _v2);
		v1 = _v1, v2 = _v2;
	};
	int getX1()
	{
		return ((Vertex*)(Node::v1))->getX();
	};
	int getX2()
	{
		return ((Vertex*)(Node::v2))->getX();
	};
	int getY1()
	{
		return ((Vertex*)(Node::v1))->getY();
	};
	int getY2()
	{
		return ((Vertex*)(Node::v2))->getY();
	};

	void resetPosition(int dx, int dy)
	{
	};
	void view(System::Windows::Forms::PaintEventArgs^  e)
	{
		e->Graphics->DrawLine(System::Drawing::Pens::BlueViolet, getX1(), getY1(), getX2(), getY2());

	};
	inline bool isMouseOnMe(int _x, int _y)
	{
		return (
			std::sqrt((_x - getX1()) * (_x - getX1()) + (_y - getY1()) * (_y - getY1())) +
			std::sqrt((_x - getX2()) * (_x - getX2()) + (_y - getY2()) * (_y - getY2()))
			<
			std::sqrt((getX1() - getX2()) * (getX1() - getX2()) + (getY1() - getY2()) * (getY1() - getY2())) +
			attractionSpacing
			);
	};
	void dragLeft(int dx, int dy)
	{
		x1 += dx;
		y1 += dy;
	};
	void dragRight(int dx, int dy)
	{
		x2 += dx;
		y2 += dy;
	};
	//Для переназначения потомков. Происходит при MouseDown
	//При добавлении новой линии и новой точки. Удалений не происходит
	//Draft передает сюда кликнутую вершину и ее родителя 
	//Для этого объекта подставить в соответствующий вершине oldVertex новую 
	//дугу newline, а в нее  oldVertex и newVertex
public: 	
	void insertNewLineAndVertexInsteadOldVertex(
		Vertex* oldVertex, Vertex* newVertex, Line* newline)
	{
		//if (this->left == oldVertex)
		//{
		//	this->left = newline;//переопределяем младший последователь. Сохраняем v1, v2
		//	newline->left = oldVertex;
		//	newline->v1 = oldVertex;
		//	newline->right = newVertex;
		//	newline->v2 = newVertex;
		//}
		//else if (this->right == oldVertex)
		//{
		//	this->right = newline;
		//	newline->right = oldVertex;
		//	newline->v2 = oldVertex;
		//	newline->left = newVertex;
		//	newline->v1 = newVertex;
		//}

		if (this->left == oldVertex)//переопределяем младший последователь. Сохраняем v1, v2
		{
			this->left = newline;
		}
		else if (this->right == oldVertex)
		{
			this->right = newline;
		}
		newline->left = oldVertex;
		newline->v1 = oldVertex;
		newline->right = newVertex;
		newline->v2 = newVertex;
	}
}; 