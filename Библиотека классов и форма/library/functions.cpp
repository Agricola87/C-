#include "functions.h"
#include<string>


void split(std::string st, std::string divisors, std::string * &splitArray, int &splitCount)
{
	splitArray = new std::string[200];//memory allocation
	splitArray[0] = "";
	splitCount = 0;

	for (unsigned int i = 0; i < st.length(); i++)
	{
		if (divisors.find(st[i]) != divisors.npos)//�� ���� �����������
		{
			if (st[i] == ' ')//������
			{
				if (splitArray[splitCount] != "")
				{
					//cout << "����������� ������\n";
					splitArray[++splitCount] = "";
				}
			}
			else
			{
				if (splitArray[splitCount] != "")
				{
					splitArray[++splitCount] = st[i];
				}
				else
				{
					splitArray[splitCount] = st[i];
				}
				splitArray[++splitCount] = "";
			}
		}
		else//�� ���� �����
		{
			splitArray[splitCount] += st[i];
		}
	}
	if (divisors.find(splitArray[splitCount]) == divisors.npos)//���� ��������� �� �����������
	{
		splitCount++;
	}

	std::string* buf = new std::string[splitCount];
	for (int i = 0; i < splitCount; i++)
	{
		buf[i] = splitArray[i];
	}
	delete[] splitArray;
	splitArray = new std::string[splitCount];
	for (int i = 0; i < splitCount; i++)
	{
		splitArray[i] = buf[i];
	}
	delete[] buf;
}
