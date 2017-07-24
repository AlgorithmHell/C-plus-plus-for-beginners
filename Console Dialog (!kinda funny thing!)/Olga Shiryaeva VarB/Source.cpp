#include <map>
#include <vector>
#include <string>
#include<algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;


struct Student
{
	string Number;
	string Mark;
	string Name;
	bool marked;
	Student() :Number(""), Mark(""),Name(""),marked(0) {}
	Student(string number, string name, string mark) :Number(number), Mark(mark), Name(name),marked(0) {}
	friend ostream&operator<<(ostream&os, const Student& FB)
	{
		if (FB.marked)
			os << "> " << FB.Number << ": " << FB.Name << " (" << FB.Mark<<")" << endl;
		else
		os << "  " << FB.Number << ": " << FB.Name <<" (" << FB.Mark<<")" <<endl;
		
		return os;
	}
	friend istream&operator >> (istream&in, Student &FB)
	{
		string line, buf;
		getline(in, line);
		istringstream S(line);
		S >> FB.Number >>FB.Name>> FB.Mark;
		

		return in;
	}
	bool operator==(Student&fb)
	{
		return this->Name == fb.Name&&this->Mark==fb.Mark&&this->Number==fb.Number;
	}


};


int main()
{
	map <string,int> Commands;
	Commands.insert(make_pair( "exit",1));
	Commands.insert(make_pair( "add",2));
	Commands.insert(make_pair( "list",3));
	Commands.insert(make_pair( "select",4));
	Commands.insert(make_pair( "delete",5));
	Commands.insert(make_pair( "clear",6));
	Commands.insert(make_pair( "find",7));
	Commands.insert(make_pair( "sort-a",8));
	Commands.insert(make_pair( "sort-b",9));
	Commands.insert(make_pair("min",10));
	Commands.insert(make_pair( "info",11));
	Commands.insert(make_pair( "low",12));
	
	vector<Student> Items;
	string command;
	while (getline(cin,command))
	{
		int Key;
		string Name, Number, Mark, Command;
		
		istringstream S(command);
		S >> Command;
		auto key=Commands.find(Command);
		if (key != Commands.end())
		{
			 Key = (*key).second;
		}
		else
		{
			cout << "Incorrect commands' input, try again.."<<endl;
			continue;
		}
		
		switch (Key)
		{
		case 1:
		{
			cout << "Thank you for using " << endl << endl;
			return 0;
		}
		break;
		case 2:
		{
			
			if (S >> Number >> Name >> Mark)
			{
				bool DuplexID = 0;
				for (auto i : Items)
				{
					if (i.Number == Number) DuplexID = true;
				}
				if (DuplexID) cout << "This Number " << Number << " already exist" << endl;
				else
				{
					if (stoi(Number) >= 10000 && stoi(Number) <= 99999 && stoi(Mark) >= 0 && stoi(Mark) <= 10)
					{
						Items.push_back(Student(Number, Name, Mark));
						cout << "Added " << endl;
					}

					else cout << "Wrong data, try again " << endl;
				}
			}
			else 
				cout << "Incorrect commands' input, try again.." << endl;
			
		}
		break;
		case 3:
		{
			for_each(Items.begin(), Items.end(), [](Student&st) {cout << st; });
		}
		break;
		case 4:
		{
			for_each(Items.begin(), Items.end(), [](Student&st) {st.marked = false; });
			S >> Number;
			auto search = find_if(Items.begin(), Items.end(), [Number](Student&st) {return st.Number == Number; });
			if (search != Items.end())
			{
				(*search).marked = true;
				cout << "Selected " << endl;
			}
			else
			{
				cout << "No students found " << endl;
				
			}
		}
		break;
		case 5:
		{
			auto search = find_if(Items.begin(), Items.end(), [](Student&st) {return st.marked == true; });
			if (search == Items.end()) cout << " No marked students " << endl;
			else
			{
				Items.erase(search);
				cout << "Deleted" << endl;
			}
		}
		break;
		case 6:
		{
			Items.clear();
		}
		break;
		case 7:
		{
			for_each(Items.begin(), Items.end(), [](Student&st) {st.marked = false; });
			S >> Name;
			auto search = find_if(Items.begin(), Items.end(), [Name](Student&st) {return st.Name == Name; });
			if (search != Items.end()) (*search).marked = true;
			else
			{
				cout << "No students found " << endl;

			}
		}
		break;
		case 8:
		{
			sort(Items.begin(), Items.end(), [](Student&s, Student&t) {return stoi(s.Number) <stoi(t.Number); });
		}
		break;
		case 9:
		{
			sort(Items.begin(), Items.end(), [](Student&s, Student&t) {return s.Name<t.Name; });
		}
		break;
		case 10:
		{
			int i;
			for (i = 0; i <= 10; i++)
			{
				auto search = find_if(Items.begin(), Items.end(), [i](Student&s) {return stoi(s.Mark) == i; });
				if (search != Items.end()) break;
			}
			for_each(Items.begin(), Items.end(), [i](Student&st) {if(stoi(st.Mark) == i)cout << st; });

		}
		break;
		case 11:
		{
			auto search = find_if(Items.begin(), Items.end(), [](Student&st) {return st.marked == true; });
			if (search == Items.end()) cout << " No marked students " << endl;
			else
			{
				cout << "Number of credit book: " << (*search).Number
					<< endl << "Surname: " << (*search).Name
					<< endl << "Mark: " << (*search).Mark << endl;
			}
			
		}
		break;
		case 12:
		{
			int LowThan;
			S >> LowThan;
			for_each(Items.begin(), Items.end(), [LowThan](Student&st) {if (stoi(st.Mark) <LowThan)cout << st; });
		}
		break;
		
		

		}
	}

	return 0;
}