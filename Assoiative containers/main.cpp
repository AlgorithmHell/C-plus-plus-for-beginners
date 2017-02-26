#if 0
1.	Информация о студентах хранится в виде записей{ ID:intt, Surname : string, Name : string }.
Известно, что наиболее частой операцией является поиск студента по его фамилии.
Предложите оптимальную структуру данных для наиболее эффективного хранения и обработки данной информации.
Напишите функцию, которая выводит всех студентов(номер зачётки ID, фамилию и имя)
по заданной фамилии или пишет, что студентов с данной фамилией нету.
#endif
#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <map>
#include <string>
#include <iomanip>




using namespace std;

class Student
{
public:

	int ID;
	string name;
	string surname;

	
	Student(int id, string NAME, string SURNAME) : ID(id), name(NAME), surname(SURNAME) {};
	friend ostream&operator<<(ostream&os, const Student&st)
	{
		 os << left <<"ID: "<<st.ID<<setw(8)<<"  Name:"<<setw(13)<<st.name<<setw(17) << "Surname:"<<st.surname << endl;
		 return os;
	}
};



int main()
{
	multimap  <string,Student> data;
	fstream in("data.txt");
	int id;
	string name, surname;
	while (!in.eof())
	{
		in >> id >> name >> surname;
		data.insert(make_pair(surname, Student(id, name, surname)));

	}
	for (auto i : data)
	{
		cout << i.second;
	}
	cout << endl << endl;

	cout << " enter Ctrl+C when finishing requests: " << endl << endl;
	string request;
	while (true)
	{
		cin >> request;
		auto lower = data.lower_bound(request);
		auto upper = data.upper_bound(request);
		if (lower != data.end())
		{
			cout << "Student"; (++lower == upper) ? cout << "" : cout << "s";cout<<" with Surname " << request << endl;
			lower--;
			for (auto i = lower; i != upper; i++)
			{
				cout << i->second;
			}
		}
		
	}


}



