#pragma once

/*


	↓↓↓↓명세↓↓↓↓


				  */

class String
{
private:
	char *buffer;
	int length; //글자수
	int size;	//메모리크기

	String(int m);

public:
	String();
	String(char *init, int m);		   //길이 m의 string init
	String(String &);				   //복사생성자
	String &operator=(const String &); //대입연산자
	~String();
	bool operator==(String t);	 //동일한지 비교
	bool operator!();			 //공백 true, 아니면 false
	int Length();				 //문자수반환
	String Concat(String t);	 //문자열합치기
	String Substr(int i, int j); // i~j 반환
	int Find(String pat);		 //string에서 pat찾아서 위치 반환, 없을시 -1반환
	void print();
};

/*


	↓↓↓↓구현↓↓↓↓


				  */

String::String(int m)
{
	size = m;
	buffer = new char[m];
	length = 0;
}
String::String() : String(10)
{
}
String::String(char *init, int m) : String(m + 1)
{
	for (int i = 0; i < m; i++)
		buffer[i] = init[i];
	buffer[m] = '\0';
	length = m;
}

String::String(String &s) : String(s.length + 1)
{
	for (int i = 0; i < s.length; i++)
	{
		buffer[i] = s.buffer[i];
	}
	buffer[s.length] = '\0';
	length = s.length;
}
String &String::operator=(const String &s)
{
	delete[] buffer;
	length = s.length;
	buffer = new char[length + 1];
	for (int i = 0; i < length; i++)
		buffer[i] = s.buffer[i];
	buffer[length] = '\0';

	return *this;
}
String::~String()
{
	delete[] buffer;
}
bool String::operator==(String t)
{
	bool same = true;
	if (length == t.length)
	{
		for (int i = 0; i < length; i++)
		{
			bool tmp = false;
			if (buffer[i] == t.buffer[i])
				tmp = true;
			same *= tmp;
		}
	}
	else
		same = false;

	return same;
}
bool String::operator!()
{
	if (length == 0)
		return true;
	else
		return false;
}
int String::Length()
{
	return length;
}
String String::Concat(String t)
{
	String Result(length + t.length + 1);
	Result.length = length + t.length;
	for (int i = 0; i < length; i++)
		Result.buffer[i] = buffer[i];
	for (int i = 0; i < t.length; i++)
		Result.buffer[i + length] = t.buffer[i];
	Result.buffer[Result.length] = '\0';

	return Result;
}
String String::Substr(int i, int j)
{
	String result(j - i + 2);
	result.length = j - i + 1;
	for (int k = 0; k < j - i + 1; k++)
		result.buffer[k] = buffer[k + i];
	result.buffer[j - i + 1] = '\0';

	return result;
}
int String::Find(String pat)
{
	for (int i = 0; i <= length - pat.length; i++)
	{
		bool found = true;
		for (int j = 0; j < pat.length; j++)
		{
			if (buffer[i + j] != pat.buffer[j])
				found = false;
			break;
		}
		if (found)
			return i;
	}
	return -1;
}
void String::print()
{
	for (int i = 0; i < length; i++)
		std::cout << buffer[i];
	std::cout << " ";
}