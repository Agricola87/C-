#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Node
{
public:
	Node* left;		//левый указатель
	Node* right;	//правый указатель
	Node* v1;		//левая часть имени A в AB
	Node* v2;		//правая часть имени B в AB

	Node(Node* _left = 0, Node* _right = 0, Node* _v1 = 0, Node* _v2 = 0)
	{
		left = _left;
		right = _right;
		v1 = _v1;
		v2 = _v2;
	};
	void set(Node* _left = 0, Node* _right = 0, Node* _v1 = 0, Node* _v2 = 0)
	{
		left = _left;
		right = _right;
		v1 = _v1;
		v2 = _v2;
	};
	virtual void resetPosition(int dx, int dy) = 0
	{};
	virtual void view(System::Windows::Forms::PaintEventArgs^  e) = 0
	{};
	virtual bool isMouseOnMe(int _x, int _y) = 0
	{};
	virtual void move(int _x, int _y)
	{};
};
