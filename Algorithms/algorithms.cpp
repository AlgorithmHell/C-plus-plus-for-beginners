#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <set>
#include <iterator>
#include <exception>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <list>



using namespace std;
#if 0
    File "out.txt" :
        I'm sitting in my room with the needle in my hands
   
#endif
class Program
{
public:
	static void Main()
	{
		VectorSort();
		BindAndCopy_ifUse(); 
		OstreamIteratorToTheConsoleAndFile();
		River();
		LowerUpperBound(3);
		LowerUpperBound(5);
	}

private:
	
	class Greater
	{
	private:
		int n;
	public:
		Greater(int val) : n(val) {}
		bool operator()(int a)
		{
			return a > n;
		}
	};
	static void  PrintVector(vector<int>&vec)
	{
		for (auto i : vec)
		{
			cout << i << ends;
		}
		cout << endl;
	}	
	static void VectorSort()
	{
		vector<int> vec = { 1, 8, 7, 4, 3, 6, 2, 5};			
		cout << "Vector before sort: " << endl;
		PrintVector(vec);
		sort(vec.begin(), vec.end(), [](int&a, int&b) 
		{  if (a % 2 == b % 2) return a < b; else return (a % 2 == 0); });
		cout << "Vector after sort: " << endl;
		PrintVector(vec);
		cout << endl;
	}
	static void BindAndCopy_ifUse()
	{
		vector<int> vec = { 1, 8, 7, 4, 3, 6, 2, 5 };
		int n(5);
		vector<int> bar(vec.size());
		copy_if(vec.begin(), vec.end(), bar.begin(), Greater(5));
		
		auto i = count_if(vec.begin(), vec.end(), bind(greater<int>(),placeholders::_1, n));
		cout << "Amount of numbers more than 5: " << i << endl;
		cout << "Numbers more than 5: " << endl;
		bar.resize(i);
		PrintVector(bar);
		cout << endl << endl;

	}
	static void OstreamIteratorToTheConsoleAndFile()
	{
		vector<char*> myv = { "I'm","sitting","in","my","room","with","the","needle","in","my","hand." };
		ofstream of("out.txt");
		ostream_iterator<char*> out_it1(of, " ");
		ostream_iterator<char*> out_it2(cout, " ");
		copy(myv.begin(), myv.end(), out_it1);
		copy(myv.begin(), myv.end(), out_it2);
		cout << endl;
	}
	static void River()
	{
		_setmode(_fileno(stdout), 0x20000);
		_setmode(_fileno(stdin), 0x20000);
		_setmode(_fileno(stderr), 0x20000);
		
		 ostream_iterator<const wchar_t*,wchar_t> it(std::wcout,L" ");
		set<const wchar_t*> river;
		river.insert(L"пескарь");
		river.insert(L"мидия");
		river.insert(L"рак");
		
		set<const wchar_t*> depth;
		depth.insert(L"бычок");
		depth.insert(L"окунь");
		depth.insert(L"мидия");
		
		

		wcout << L"\nВсе обитатели реки:\n";
		set_union(river.begin(), river.end(), depth.begin(), depth.end(), it);

		wcout << L"\nВодятся по всей реке:\n";
		set_intersection(river.begin(), river.end(), depth.begin(), depth.end(), it);
		
		wcout << L"\nВодятся у берега, но не на глубине:\n";
		set_difference(river.begin(), river.end(), depth.begin(), depth.end(), it);
		wcout << endl;
	}
	static void LowerUpperBound(int n)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
	    _setmode(_fileno(stdin), _O_U16TEXT);
	    _setmode(_fileno(stderr), _O_U16TEXT);
		multimap<int, const wchar_t*> m;
		multimap<int, const wchar_t*>::const_iterator it_low, it_up;
		m.insert(make_pair(1, L"адзiн"));
		m.insert(make_pair(1, L"one"));
		m.insert(make_pair(1, L"один"));
		m.insert(make_pair(2, L"два"));
		m.insert(make_pair(2, L"two"));
		m.insert(make_pair(3, L"three"));
		m.insert(make_pair(3, L"тры"));
		m.insert(make_pair(3, L"три"));
		m.insert(make_pair(4, L"four"));
		m.insert(make_pair(4, L"чатыры"));
		m.insert(make_pair(4, L"четыре"));
		it_low = m.lower_bound(n);
		it_up = m.upper_bound(n);

		if (it_low != m.end())
		{
			for (auto i = it_low; i != it_up; ++i)
				wcout << (*i).second << ends;
		}
		else wcout << L"No existing number" << endl;
		wcout << endl;	

	}
	
};



int main()
{
	

	try
	{
		Program::Main();
	}
	catch (exception e)
	{
		cout << "\nProgram has finished with the caught exception: " << e.what() << endl;
	}
	
	
	
	


	return 0;
}



