#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <io.h>
#include <fcntl.h>

using namespace std;
wchar_t makelow(wchar_t c)
{
	if (c == 0X401) c = 0X451;//если с == Ё, то с=е 
	if (c <= 0X42F) c += 0X20;//если с есть большая буква, то сделать маленькой
	return c;
}

bool howtosort(wchar_t c1,wchar_t c2)
{
	if (c1 == 0X451 && c2 == 0X435||c1==0X436&&c2==0X451) return false; //если (с1==ё и с2==е)или(с1==ж и с2==ё)
	if ((c1 == 0X451 &&c2 == 0X436) || (c1 == 0X435&&c2 == 0X451)) return true;//если (с1==ё и с2==ж)или(с1==е и с2==ё)
	return makelow(c1) < makelow(c2);
}


static void Print(const list<wstring>& l) {
	for (auto it = l.begin(); it != l.end(); ++it)
		wcout << *it << " ";
	wcout << endl;
}



int main() {
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	list<wstring> l = { L"ёлка", L"Алфавит", L"аббат", L"еда", L"жеод" };
	Print(l);

	l.sort([](wstring& s1, wstring& s2) 
	{return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), howtosort); });
	Print(l);

	
	return 0;
}

