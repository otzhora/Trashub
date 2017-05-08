#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
using namespace std;

struct Cell
{
	string data_ru, data_eng;
	Cell *link;
};

class List
{
	public:
	// Конструкотова по умолвччагте 
	List() { Head = NULL; Marker = NULL; size = 0; }

	// конструк с паоатмк
	List(List *lst)
	{	
		for (size_t i = 0; i < getSize(); i++)
		{
			Cell *NewElement = new Cell;
			NewElement->link = Marker->link;
			NewElement->data_eng = Marker->data_eng;
			NewElement->data_ru = Marker->data_ru;
			MoveMarker();
		}
	}


	void Rewind() { Marker = Head; }


	~List()
	{
		Cell *temp;
		Rewind();
		while (Marker != NULL)
		{
			temp = Marker->link;
			delete Marker;
			Marker = temp;
		}
	}
	void MoveMarker()
	{
		Marker = Marker->link;
	}
	size_t getSize() const
	{
		return size;
	};
	string Separate(string x)
	{
		int i = 0;
		string result;
		while (x[i] != ' ')
		{
			result = +x[i];
			i++;
		}
		return result;
	}
	void Add(string eng, string ru)
	{
		size++;
		Cell *NewElement = new Cell;
		NewElement->data_eng = eng;
		NewElement->data_ru = ru;
		NewElement->link = NULL;
		if (Marker != NULL)
			Marker->link = NewElement;
		else
			Head = NewElement;
		Marker = NewElement;
	}
	void Sort()
	{
		int k = getSize();
		Rewind();
		string temp_ru, temp_eng;
		for (int j = 0; j<k; j++)
		{
			for (int i = 0; i < k - j - 1; i++)
			{
				if (strcmp((Marker->data_eng).c_str(), (Marker->link->data_eng).c_str()) > 0)
				{

					temp_ru = Marker->data_ru;
					temp_eng = Marker->data_eng;

					Marker->data_ru = Marker->link->data_ru;
					Marker->data_eng = Marker->link->data_eng;

					Marker->link->data_ru = temp_ru;
					Marker->link->data_eng = temp_eng;
				}
				MoveMarker();
			}
			Rewind();
		}
	}

	void friend PrintList(List&);
public:

	Cell *Head, *Marker;
	size_t size;

};

void PrintList(List& lst)
{
	lst.Rewind();
	while (lst.Marker != NULL)
	{
		cout << lst.Marker->data_eng << "   " << lst.Marker->data_ru << endl;
		lst.MoveMarker();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream input("input.txt");
	ofstream output("output.txt");
	string xEng, xRu;
	List lst;
	while (!input.eof())
	{
		input >> xEng;
		input >> xRu;
		lst.Add(xEng, xRu);
	}
	cout << "Size of List: " << lst.getSize() << endl << endl;
	PrintList(lst);
	lst.Sort();
	cout << endl;
	PrintList(lst);
	cout << endl;
	system("pause");
}
