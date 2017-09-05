#pragma once
template <class T> class TStack
{
private:
	int sizeMem;
	int topNumber;
	T * memPointer;
public:
	TStack <T>(int sizeMem_ = 0)//Освободить достаточно памяти заранее
	{
		sizeMem = sizeMem_;
		topNumber = 0;
		memPointer = new T[sizeMem];
	};
	TStack <T>(const TStack <T> &tmp)
	{
		sizeMem = tmp.sizeMem;
		topNumber = tmp.topNumber;
		memPointer = new T[sizeMem];
		for (int i = 0; i < sizeMem; i++)
		{
			memPointer[i] = tmp.memPointer[i];
		}
	};
	~TStack()
	{
		delete[] memPointer;
	};
	TStack <T> & operator=(TStack <T> tmp)
	{
		if (sizeMem != tmp.sizeMem)
		{
			if (sizeMem != 0)
			{
				delete[] memPointer;
			}
			sizeMem = tmp.sizeMem;
			memPointer = new T[sizeMem];
		}
		topNumber = tmp.topNumber;
		for (int i = 0; i < sizeMem; i++)
		{
			memPointer[i] = tmp.memPointer[i];
		}
		return *this;
	};
	void push(T tmp)
	{
		if (topNumber < sizeMem)
		{
			memPointer[topNumber++] = tmp;
		}
		else
		{
			MessageBox::Show("\nСтэк переполнен", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	};
	T pop()
	{
		if (topNumber > 0)
		{
			return memPointer[--topNumber];
		}
		else
		{
			MessageBox::Show("\nСтэк пуст", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	};
	T getTop()
	{
		if (topNumber > 0)
		{
			return memPointer[topNumber-1];
		}
		else
		{
			MessageBox::Show("\nСтэк пуст", "", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	};
	bool overflow()
	{
		return sizeMem == topNumber;
	};
	bool isEmpty()
	{
		return topNumber == 0;
	};
	int getTopNumber()
	{
		return topNumber;
	};
	
};


