#pragma once
#include"Node.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Vertex : public Node
{
	int x;
	int y;
	int attractionRadius;
public:
	Vertex(int _x = 0, int _y = 0) : Node((Node*)0, (Node*)0, (Node*)0, (Node*)0)
	{
		x = _x; y = _y;
		attractionRadius = 20;
	};
	void set(int _x, int _y)
	{
		Node::set((Node*)0, (Node*)0, (Node*)0, (Node*)0);
		x = _x; y = _y;
	};
	void resetPosition(int dx, int dy)
	{
		x = x + dx;
		y = y + dy;
	};
	int getX()
	{
		return x;
	};
	int getY()
	{
		return y;
	};
	void view(System::Windows::Forms::PaintEventArgs^  e)
	{
		e->Graphics->FillEllipse(System::Drawing::Brushes::Red, x-5, y-5, 10, 10);
	};
	inline bool isMouseOnMe(int _x, int _y)
	{
		if((_x - x) * (_x - x) + (_y - y)*(_y - y) <= 
			attractionRadius*attractionRadius)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	void move(int dx, int dy)
	{
		x += dx; y += dy;

	};
};