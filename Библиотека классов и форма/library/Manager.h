#pragma once
class Manager
{
public:
	bool isGoingOnVertexMoving;
	bool isGoingOnLineMoving;
	bool isGoingOnLineCreation;
	Manager()
	{
		isGoingOnVertexMoving = false;
		isGoingOnLineMoving = false;
		isGoingOnLineCreation = false;
	}
};