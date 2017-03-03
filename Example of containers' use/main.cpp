#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<string>
#include <functional>
#include<iomanip>
#include <iterator>
#include <sstream>

using namespace std;

struct FlowerBed
{
	string Number;
	string Shape;
	vector<string> Flowers;
	FlowerBed():Number(""),Shape(""){}
	FlowerBed(string number, string shape, vector<string> flowers) :Number(number), Shape(shape), Flowers(flowers) {}
	friend ostream&operator<<(ostream&os, const FlowerBed FB)
	{
		os <<left<< "#" << FB.Number << "  Shape: " << setw(10)<< FB.Shape << "Flowers: ";
		for (auto i : FB.Flowers)
			os << i << ends;
		return os;
	}
	friend istream&operator>>(istream&in, FlowerBed &FB)
	{
		string line, buf;
		getline(in, line);
		istringstream S(line);
		S >> FB.Number >> FB.Shape;
		FB.Flowers.clear();
		while (S >> buf)
		{
			FB.Flowers.push_back(buf);
		}
		return in;
	}
	bool operator==(FlowerBed&fb)
	{
		return this->Flowers == fb.Flowers;
	}
	
	 
};
ostream&operator<<(ostream&os, const pair<string, FlowerBed> FB)
{
	os << left << "#" << FB.second.Number << "  Shape: " << setw(10) << FB.second.Shape << "Flowers: ";
	for (auto i : FB.second.Flowers)
		os << i << ends;
	return os;
}
ostream&operator<<(ostream&os, const pair<int, FlowerBed> FB)
{
	os << left << "#" << FB.second.Number << "  Shape: " << setw(10) << FB.second.Shape << "Flowers: ";
	for (auto i : FB.second.Flowers)
		os << i << ends;
	return os;
}
bool OneFlowerType(FlowerBed&fb)
{
	
	auto it = find_if((fb.Flowers).begin() + 1, fb.Flowers.end(), [&fb](string&f) {return *(fb.Flowers.begin()) == f; });
	if (it == (fb.Flowers).end()) return false;
	else return true;
}
class NoFlowerDaisy {
public:
	
	bool operator()(FlowerBed&fb)
	{
		auto it = find_if((fb.Flowers).begin(), fb.Flowers.end(), [&fb](string&f) {return f=="daisy"; });
		if (it == (fb.Flowers).end()) return true;
		else return false;
	}
};
class NumberOfFlowers
{
public:
	int number;
	NumberOfFlowers(){}
	NumberOfFlowers(int number):number(number){}
	bool operator()(FlowerBed&fb)
	{
		return number == fb.Flowers.size();
	}
};
void PutFlowersInVector(vector<FlowerBed>&MyFlowerBed)
{
	ifstream fin("flowers.txt");
	istream_iterator<FlowerBed> in(fin), end;
	copy(in, end, back_inserter(MyFlowerBed));

	
}
void Copy_In(const vector<string>&Source, set <string>&Dest)
{
	
	copy(Source.begin(), Source.end(), inserter(Dest, Dest.begin()));
}

void TaskSortByNumberAndShape()
{
	vector<FlowerBed>MyFlowerBed;
	PutFlowersInVector(MyFlowerBed);
	ostream_iterator<FlowerBed> out(cout,"\n");
	cout << "Successfully put flowers in a vector:" << endl;
	copy(MyFlowerBed.begin(), MyFlowerBed.end(), out);	
	sort(MyFlowerBed.begin(), MyFlowerBed.end(), [](FlowerBed&FB, FlowerBed&fb) {return FB.Number < fb.Number; });
	cout << endl << "Sort by Number and Shape: " << endl << endl;
	copy(MyFlowerBed.begin(), MyFlowerBed.end(), out); 
	cout << endl;
	sort(MyFlowerBed.begin(), MyFlowerBed.end(), [](FlowerBed&FB, FlowerBed&fb) {return FB.Shape < fb.Shape; });
	copy(MyFlowerBed.begin(), MyFlowerBed.end(), out);
}
void Task4()
{
	vector<FlowerBed>MyFlowerBed;
	PutFlowersInVector(MyFlowerBed);
	set<string> UniqueFlowers;
	set<string> UniqueShape;
	ostream_iterator<string> out_it(cout, "  ");
	
	for_each(MyFlowerBed.begin(), MyFlowerBed.end(),
		[&UniqueFlowers](FlowerBed&fb) {Copy_In(fb.Flowers, UniqueFlowers); });

	
	cout << "Unique flowers: " << endl;
	copy(UniqueFlowers.begin(), UniqueFlowers.end(), out_it);
	cout << endl;

	for (vector<FlowerBed>::iterator i = MyFlowerBed.begin(); i != MyFlowerBed.end(); ++i)
		UniqueShape.insert(i->Shape);
	cout << "Unique Shapes:" << endl;
		copy(UniqueShape.begin(), UniqueShape.end(), out_it);
	cout << endl;
	cout << endl << "Enter the particular number of a FlowerBed: " << endl;
	string number; 
	cin >> number;
	cout << "Flowers from Flowerbed  '" << number << "' :" << endl;
	auto finder = find_if(MyFlowerBed.begin(), MyFlowerBed.end(), [number](FlowerBed&fb) {return fb.Number == number; });
	copy(finder->Flowers.begin(), finder->Flowers.end(),out_it);
	cout << endl;
}
void Task5()
{
	vector<FlowerBed>MyFlowerBed;
	PutFlowersInVector(MyFlowerBed);
	
	auto it = find_if(MyFlowerBed.begin(), MyFlowerBed.end(), OneFlowerType);
	cout << *it << endl;
	cout << "FlowerBeds without Daisy: " << endl;
	auto iter = find_if(MyFlowerBed.begin(), MyFlowerBed.end(), NoFlowerDaisy());
	while (iter != MyFlowerBed.end())
	{
		cout<<*iter << endl;
		iter= find_if(iter+1, MyFlowerBed.end(), NoFlowerDaisy());
	}
	int n;
	cout << "Enter the amount of flowers (3-7) :" << endl;
	cin >> n;
	NumberOfFlowers NOF(n);
	cout << "Flowerbeds with the amount " << n << " of flowers: " << endl;
	auto iterator = find_if(MyFlowerBed.begin(), MyFlowerBed.end(), NOF);
	while (iterator != MyFlowerBed.end())
	{
		cout << *iterator << endl;
		iterator = find_if(iterator + 1, MyFlowerBed.end(), NOF);
	}


	
	
}
void Task6()
{
	vector<FlowerBed>MyFlowerBed;
	PutFlowersInVector(MyFlowerBed);
	ostream_iterator<FlowerBed> out(cout, "\n");
	cout << "Successfully put flowers in a vector:" << endl;
	copy(MyFlowerBed.begin(), MyFlowerBed.end(), out);
	
	multimap<string, FlowerBed> MultiFlower;
	for (vector<FlowerBed>::iterator i = MyFlowerBed.begin(); i != MyFlowerBed.end(); ++i)
		MultiFlower.insert(make_pair(i->Shape, *i));
	int DifferentShapes=0;
	multimap<string, FlowerBed>::const_iterator i = MultiFlower.begin();
	while (i != MultiFlower.end())
	{
		DifferentShapes++;
		i = MultiFlower.upper_bound(i->first);
	}
	cout << "Amount of different shapes: " << DifferentShapes << endl << endl;

	NumberOfFlowers NOF;
	
	multimap<int, FlowerBed, greater<int>> MultiFlower1;
	for (vector<FlowerBed>::iterator i = MyFlowerBed.begin(); i != MyFlowerBed.end(); ++i)
		MultiFlower1.insert(make_pair(i->Flowers.size(), *i));
	auto max = MultiFlower1.begin();


	cout << "Flowerbeds with the max amount of flowers: " << endl;
	ostream_iterator <pair<int, FlowerBed>> out_iter(cout, "\n");
	copy(max, MultiFlower1.upper_bound(max->first), out_iter);
	cout << "Enter the flower you want to replace: (rose better) " << endl;
	string rep;
	cin >> rep;
	
	
	cout << "Enter the flower you want to see instead of " << rep << endl;
	string copyin;
	cin >> copyin;
	vector<FlowerBed>::iterator it = MyFlowerBed.begin();
	ostream_iterator <pair<string,FlowerBed>> out_it(cout, "\n");
	cout << "Replaced successfully: " << endl;
	while (it != MyFlowerBed.end())
	{
		replace(it->Flowers.begin(), it->Flowers.end(),rep,copyin);
		++it;
	}
	copy(MyFlowerBed.begin(), MyFlowerBed.end(), out);
	
}

int main()
{
	TaskSortByNumberAndShape();
	Task4();
	Task5();
	Task6();

	
	return 0;
}
