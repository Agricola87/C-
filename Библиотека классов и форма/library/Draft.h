#pragma once
#include"functions.h"
#include"Node.h"
#include"Line.h"
#include"Vertex.h"
#include<string>
#include<fstream>
#include<stdio.h>
#include"TStack.h"

//#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Runtime::InteropServices;
#define _SIZE_OF_VERTEX_LIST 20
#define _VERTEX_AND_LINES_MAXIMUM_ 200


class Draft
{
	//Регистрация элемента, на который попал пользователь
	Node* mouseClickedOnMe;
	//Только что созданная вершина, которая должна слиться с существующей
	Node* justCreatedVertexToDeleting;
	//Для перемещения вершины вслед за курсором
	int lastX;
	int lastY;
	//Для одинарного обхода вершин при отрисовке графа
	Vertex ** vertexList;
	int vertexNumber;
	int sizeOfVertexList; 
	//Для записи в файл
	std::string fileString;
	//FILE * pFile;
public:
	Node* root;
	bool isMouseOnExistingVertexMark;
	bool isMouseOnExistingLineMark;
	Draft()
	{
		Node* np = 0;
		Vertex* v1 = new Vertex(200, 200);
		Vertex* v2 = new Vertex(400, 200);
		vertexNumber = 0;
		sizeOfVertexList = _SIZE_OF_VERTEX_LIST;
		vertexList = new Vertex*[_SIZE_OF_VERTEX_LIST];
		addVertexToList(v1);
		addVertexToList(v2);
		//Line* l = new Line(200, 200, 400, 200, v1, v2, v1, v2);
		Line* l = new Line(v1, v2, v1, v2);
		root = l;
		mouseClickedOnMe = 0;
		isMouseOnExistingLineMark = false;
		isMouseOnExistingVertexMark = false;
		//f.open("test.txt", std::ios_base::in | std::ios_base::in | std::ios_base::app);
		//f >> &v1;
		//f >> v2;
		//fprintf(f, "Address of x is %p\n", (void *)ip);

		//pFile = fopen("test.txt", "a+");
		//fprintf(pFile, "%p %p\n", (void *)v1, (void *)v2);
	};
	~Draft()
	{
		//удалить список связанных линий
	};
	void view(System::Windows::Forms::PaintEventArgs^  e)
	{
		viewByDFS(root, e);
	};
private:
	void viewByDFS(Node* current, System::Windows::Forms::PaintEventArgs^  e)
	{
		(*current).view(e);
		if (current->left)
		{
			viewByDFS(current->left, e);
		}
		if (current->right)
		{
			viewByDFS(current->right, e);
		}
		return;
	};
public:
	bool isMouseOnExistingVertex(int _x, int _y)
	{
		mouseClickedOnMe = 0;
		return isMouseOnExistingVertexByDFS(root, _x, _y);
	};
private:
	bool isMouseOnExistingVertexByDFS(Node* current, int _x, int _y)
	{
		bool temp = false;
		if (current->left)
		{	//Это дуга
			temp = isMouseOnExistingVertexByDFS(current->left, _x, _y);
		}
		if (temp)
		{	//Искомое найдено
			return true;
		}
		if (current->right)
		{	//это дуга. Искомое не найдено
			temp = isMouseOnExistingVertexByDFS(current->right, _x, _y);
		}
			//сюда попадаем только просматривая листья-вершины
		else if (current->isMouseOnMe(_x, _y))
		{
			mouseClickedOnMe = current;
			temp = true;
		}
		return temp;
	};
public:
	bool isMouseOnExistingVertexExceptJustCreated(int _x, int _y)
	{
		return isMouseOnExistingVertexExceptJustCreatedByDFS(root, _x, _y);
	};
private:
	bool isMouseOnExistingVertexExceptJustCreatedByDFS(Node* current, int _x, int _y)
	{
		bool temp = false;
		if (current->left)
		{	//Это дуга
			temp = isMouseOnExistingVertexExceptJustCreatedByDFS(
				current->left, _x, _y);
		}
		if (temp)
		{	//Искомое найдено
			return true;
		}
		if (current->right)
		{	//это дуга. Искомое не найдено
			temp = isMouseOnExistingVertexExceptJustCreatedByDFS(
				current->right, _x, _y);
		}
		//сюда попадаем только просматривая листья-вершины
		else if ((current->isMouseOnMe(_x, _y)) 
			&& (mouseClickedOnMe != current))
		{
			justCreatedVertexToDeleting = mouseClickedOnMe;
			mouseClickedOnMe = current;
			temp = true;
		}
		return temp;
	};
public:
	bool isMouseOnExistingLine(int _x, int _y)
	{
		mouseClickedOnMe = 0;
		return isMouseOnExistingLineByDFS(root, _x, _y);
	};
private:
	bool isMouseOnExistingLineByDFS(Node* current, int _x, int _y)
	{
		bool temp = false;
		if (current->isMouseOnMe(_x, _y))
		{
			mouseClickedOnMe = current;
			return true;
		}
		if (current->left)
		{	//Это дуга
			temp = isMouseOnExistingLineByDFS(current->left, _x, _y);
		}
		if (temp)
		{	//Искомое найдено
			return true;
		}
		if (current->right)
		{	//это дуга. 
			temp = isMouseOnExistingLineByDFS(current->right, _x, _y);
		}
		//сюда попадаем только просматривая листья-вершины

		return temp;
	};
public:
	void setLastXYPosition(int _x, int _y)
	{
		lastX = _x;
		lastY = _y;
	};
	void moveCurrentVertex(int _x, int _y)
	{
		mouseClickedOnMe->move(_x - lastX, _y - lastY);
	};
public:
	void moveLine(int _x, int _y)//is equal to move all
	{
		for (int i = 0; i < vertexNumber; i++)
		{
			vertexList[i]->resetPosition(_x - lastX, _y - lastY);
		}
	};
private:
	void moveItemByDFS(Node* current, int _x, int _y)
	{
		current->resetPosition(_x - lastX, _y - lastY); 
		if (current->left)
		{
			moveItemByDFS(current->left, _x, _y);
		}
		if (current->right)
		{
			moveItemByDFS(current->right, _x, _y);
		}
		return;
	};

private:
	Line* getParent(Node* child)
	{
		if (child == root)
		{
			MessageBox::Show("\nЭтого сообщения не должно быть", "!!!!!!!!!!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else
		{
			return (Line*)getParentByDFS(child, root);
		}
	};
	Node* getParentByDFS(Node* child, Node* current)
	{
		Node* temp = 0;
		if (current->left)
		{	//Это дуга
			if (current->left == child)
			{
				temp = current;
			}
			else
			{
				temp = getParentByDFS(child, current->left);
			}
		}
		if ((current->right) && (temp == 0))
		{	//Это дуга
			if (current->right == child)
			{
				temp = current;
			}
			else
			{
				temp = getParentByDFS(child, current->right);
			}
		}
		return temp;
	};
public:
	void insertNewLineAndVertexInsteadOfClickedVertex()
	{
		// =1= Получили родителя выделенной вершины
		Line* parent = getParent(mouseClickedOnMe);
		// =2= Создаем динамически вершину и линию. Инициализируем координаты
		Vertex* newVertex = new Vertex(((Vertex*)mouseClickedOnMe)->getX(), ((Vertex*)mouseClickedOnMe)->getY());
		addVertexToList(newVertex);
		//Line* newLine = new Line(((Vertex*)mouseClickedOnMe)->getX(), ((Vertex*)mouseClickedOnMe)->getY(), ((Vertex*)mouseClickedOnMe)->getX(), ((Vertex*)mouseClickedOnMe)->getY());
		Line* newLine = new Line((Node*)0, (Node*)0, (Node*)0, (Node*)0);


		// =3= Функция устанавливает необходимые связи для новых и старых элементов
		parent->insertNewLineAndVertexInsteadOldVertex(
			(Vertex*)mouseClickedOnMe, newVertex, newLine);
		// =4=
		mouseClickedOnMe = newVertex;
	};
	void replaceJustCreatedVertexByExisting()
	{
		//находим родителя justCreatedVertexToDeleting
		Line* parent = getParent(justCreatedVertexToDeleting);
		//заменяем соответствующего потомка на существующую вершину
		if (parent->left == justCreatedVertexToDeleting)
		{
			parent->left = mouseClickedOnMe;
			parent->v1 = mouseClickedOnMe;
		}
		else if (parent->right == justCreatedVertexToDeleting)
		{
			parent->right = mouseClickedOnMe;
			parent->v2 = mouseClickedOnMe;
		}

		/////////////////////////////
		//
		for (int i = 0; i < vertexNumber; i++)
		{
			if (vertexList[i] == justCreatedVertexToDeleting)
			{
				vertexList[i] = vertexList[vertexNumber];
				vertexNumber--;
			}
		}
		/////////////////////////////
		delete justCreatedVertexToDeleting;
	};
	void addVertexToList(Vertex* vertex)
	{
		//проверка, перепаковка и добавление
		if (vertexNumber + 2 >= sizeOfVertexList)
		{
			Vertex ** tempList = new Vertex*[vertexNumber];
			for (int i = 0; i < vertexNumber; i++)
			{
				tempList[i] = vertexList[i];
			}
			sizeOfVertexList += _SIZE_OF_VERTEX_LIST;
			delete[] vertexList;
			vertexList = new Vertex*[_SIZE_OF_VERTEX_LIST];
			for (int i = 0; i < vertexNumber; i++)
			{
				vertexList[i] = tempList[i];
			}
			delete[] tempList;
			MessageBox::Show("\nПерепаковано успешно\nsizeOfListOfConnectedLines=" + sizeOfVertexList, "Перепаковка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		vertexList[vertexNumber] = vertex;
		vertexNumber++;
	};
	std::string createVertexString()
	{
		std::string st = "";
		for (int i = 0; i < vertexNumber; i++)
		{
			st += std::to_string(vertexList[i]->getX());
			st += " ";
			st += std::to_string(vertexList[i]->getY());
			st += " ";
		}
		return st;
	};
private:
	int getNumberInVertexList(Vertex* v)
	{
		for (int i = 0; i < vertexNumber; i++)
		{
			//fprintf(pFile, "%p \n", (void *)v);
			if (v == vertexList[i])
			{
				return i;
				break;
			}
			////////////////
		}
		return -1;
	};
public:
	//void test()
	//{
	//	pFile = fopen("test.txt", "a+");
	//	for (int i = 0; i < vertexNumber; i++)
	//	{
	//		//fprintf(pFile, "g");
	//		fprintf(pFile, "%p \n", (void *)vertexList[i]);
	//	}
	//	fclose(pFile);
	//}
	std::string createLinesString()
	{
		//test(); /*return "";*/

		//pFile = fopen("test1.txt", "a+");
		//fprintf(pFile, " \n");

		fileString = "";
		recordCurrent(root);

		//fclose(pFile);

		return fileString;
	};
private:
	void recordCurrent(Node* current)
	{
		if ((current->left)|| (current->right))
		{
			recordCurrent(current->left);
			recordCurrent(current->right);
			fileString += "*";
		}
		else
		{
			fileString += " ";
			fileString += std::to_string(getNumberInVertexList((Vertex*)current));
		}
	}
	public:
		void openFile(System::String^ filename)
		{
			//подготавливаем имя открываемого файла
			String^ st = filename;
			IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(filename);
			char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());//http://stackoverflow.com/questions/13665649/how-to-convert-string-to-char-array
			std::string stst(nativeString);
			//открываем входной поток
			std::fstream fIn;
			fIn.open(stst);
			std::string firstLine;
			getline(fIn, firstLine);
			std::string secondLine;
			getline(fIn, secondLine);
			fIn.close();

			//std::string* splittedString;
			//int splitCount;
			//split(secondLine, "* ", splittedString, splitCount);
			//std::fstream fOut;
			//fOut.open("test.txt");
			//fOut.clear();
			//fOut << "count=" << splitCount << "\n";
			//for (int i = 0; i < splitCount; i++)
			//{
			//	fOut << splittedString[i] << "\n";
			//}
			//fOut.close();
			//return;

			//Удаляем старый Draft
			deleteDraft();
			//Назначаем новый список вершин
			setVertexList(firstLine);
			//Назначаем новый плекс
			setPlex(secondLine);

			//MessageBox::Show("\nОткрываю файл " + st, "Открытие", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
private:
	void deleteDraft()
	{
		//return;
		//////////////////////////////////////////////////////////////////////
		delete[] vertexList;
		deleteNode(root);
	}
	void deleteNode(Node* current)
	{
		if (current == root)return;
		if ((!(current->left)) && (!(current->right)))
		{
			delete current;
		}
		else
		{
			deleteNode(current->left);
			deleteNode(current->right);
			delete current;
		}
	}
	void setVertexList(std::string firstLine)
	{
		//Массив координат
		std::string* splittedString;
		int splitCount;
		split(firstLine, " ", splittedString, splitCount);

		vertexList = new Vertex*[splitCount];
		vertexNumber = (int)(splitCount/2);

		///////////////////
		sizeOfVertexList = _SIZE_OF_VERTEX_LIST;
		mouseClickedOnMe = 0;
		isMouseOnExistingLineMark = false;
		isMouseOnExistingVertexMark = false;
		///////////////////

		for (int i = 0; i < splitCount; i++)
		{
			if (i % 2 == 1)
			{
				//создаем динамически вершину
				Vertex* newVertex = new Vertex(std::stoi(splittedString[i-1]), std::stoi(splittedString[i]));
				//записываем ее адрес в массив вершин
				vertexList[(int)(i / 2)] = newVertex;
			}
		}
	}
	void setPlex(std::string secondLine)
	{
		std::string* splittedString;
		int splitCount;
		split(secondLine, "* ", splittedString, splitCount);
		TStack<Vertex*> vertexStack(_VERTEX_AND_LINES_MAXIMUM_);
		TStack<Node*> nodeStack(_VERTEX_AND_LINES_MAXIMUM_);
		for (int i = 0; i < splitCount; i++)
		{
			std::string current = splittedString[i];
			if (current != "*")//на вход поступило число
			{
				//Добавляем соответствующую вершину в стэк
				vertexStack.push(vertexList[std::stoi(current)]);
				nodeStack.push(vertexList[std::stoi(current)]);
			}
			else//на вход знак *
			{
				Node* left, *right;
				Vertex* v1, *v2;
				right = nodeStack.pop();
				left = nodeStack.pop();
				v2 = vertexStack.pop();
				v1 = vertexStack.getTop();
				Line* newLine = new Line(left, right, v1, v2);
				nodeStack.push(newLine);
			}
		}
		root = nodeStack.pop();
	}
};