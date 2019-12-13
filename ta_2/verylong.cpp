#include<iostream>
#include<string>
#include<thread>
using namespace std;
char IntToChar(int);
int CharToInt(char);
int number_digit(long);
int StringToInt(string);
int StringToInt(char);
void reverseStr(string&);
class number
{
public:
	string strvalue = "";
	bool Is_negative = false;
	int length = 0;
	number() = default;
	number(string x, bool Is_Negative = false)
	{
		Is_negative = Is_Negative;
		strvalue = x;
		length = x.length();
	}
	number(long long x)
	{
		length = number_digit(x);
		Is_negative = x < 0;
		if (Is_negative) x *= -1;
		while (x)
		{
			strvalue += IntToChar(x - ((x / 10) * 10));
			x /= 10;
		}
		reverseStr(strvalue);
	}
	bool operator<(number& x)
	{
		if (!x.Is_negative && this->Is_negative)return true;
		else if (x.Is_negative && !this->Is_negative) return false;
		bool IsLower = true;
		if (x.strvalue.length() < this->strvalue.length())
			IsLower = false;
		if (x.strvalue.length() == this->strvalue.length())
			if (CharToInt(x.strvalue[0]) < CharToInt(this->strvalue[0]))
				IsLower = false;
		if (x.Is_negative)
			IsLower = !IsLower;
		return IsLower;
	}
	bool operator>(number& x)
	{
		return !(operator<(x));
	}
	bool operator==(number& x)
	{
		bool resault = false;
		resault = operator<(x);
		if (!resault)
			resault = operator>(x);
		return !(resault);
	}
	void Swap(number& x)
	{
		string temp = x.strvalue;
		x.strvalue = this->strvalue;
		this->strvalue = temp;
		bool Is = x.Is_negative;
		x.Is_negative = this->Is_negative;
		this->Is_negative = Is;
		int t = x.length;
		x.length = this->length;
		this->length = t;
	}
	
};
class Operators
{
private:
	
	static number ForcePositiveNumberToPlus(number x, number y)
	{
		string resault = "";
		int xStrLen = x.strvalue.length(), yStrLen = y.strvalue.length();
		int maximum = (xStrLen > yStrLen) ? xStrLen : yStrLen;
		bool Is_remind = false;
		for (register int i = 0;i < maximum || Is_remind;i++)
		{
			int digit = 0;

			if (i < xStrLen && i < yStrLen)
				digit = CharToInt(x.strvalue[xStrLen - 1 - i]) + CharToInt(y.strvalue[yStrLen - 1 - i]);
			else if (i < xStrLen)
				digit = CharToInt(x.strvalue[xStrLen - 1 - i]);
			else if (i < yStrLen)
				digit = CharToInt(y.strvalue[yStrLen - 1 - i]);
			digit += Is_remind;
			if (digit < 10)
			{
				resault += IntToChar(digit);
				Is_remind = false;
			}
			else
			{
				resault += IntToChar(digit - (digit / 10) * 10);
				Is_remind = true;
			}
		}
		reverseStr(resault);
		return number(resault, false);
	}
	static number ForcePositiveNumberToMinus(number x, number y)
	{
		number resault("",false);
		int xStrLen = x.strvalue.length(), yStrLen = y.strvalue.length();
		int maximum = (xStrLen > yStrLen) ? xStrLen : yStrLen;
		bool Is_remind = false;
		for (int i = 0;i < maximum;i++)
		{
			int digit = 0;
			if (i < xStrLen && i < yStrLen)
				digit = CharToInt(x.strvalue[xStrLen - 1 - i]) - CharToInt(y.strvalue[yStrLen - 1 - i]);
			else if (i < xStrLen)
				digit = CharToInt(x.strvalue[xStrLen - 1 - i]);
			else if (i < yStrLen)
			{
				digit = 10 - CharToInt(y.strvalue[yStrLen - 1 - i]);
				resault.Is_negative = true;
			}
			digit -= Is_remind;
			if (digit >= 0)
			{
				resault.strvalue += IntToChar(digit);
				Is_remind = false;
			}
			else
			{
				resault.strvalue += IntToChar(10 + digit);
				Is_remind = true;
			}
		}
		if (xStrLen == yStrLen)
			if (CharToInt(x.strvalue[0]) < CharToInt(y.strvalue[0]))
				resault.Is_negative = true;
		reverseStr(resault.strvalue);
		return resault;
	}
	static number ForcePositiveNumberToMultyplication(number x,number y)
	{
		long long X1 = StringToInt(x.strvalue);
		long long X2 = StringToInt(y.strvalue);
		return number(X1 * X2);
	}
	static number ForcePositiveNumberToDivision(number x, number y)
	{
		long long X1 = StringToInt(x.strvalue);
		long long X2 = StringToInt(y.strvalue);
		return number(X1 / X2);
	}
	Operators() {}
public:
	
	static number PLUS(number xn, number yn)
	{
		number resault;
		if (xn.Is_negative && yn.Is_negative)
		{
			resault = ForcePositiveNumberToPlus(xn, yn);
			resault.Is_negative = true;
		}
		else if (xn.Is_negative)
			resault = minus(yn,xn);
		else if (yn.Is_negative)
			resault = minus(xn, yn);
		else
			resault = ForcePositiveNumberToPlus(xn, yn);
		return resault;

	}
	static number minus(number x, number y)
	{
		number resault;
		if (x.Is_negative && y.Is_negative)
		{
			resault = ForcePositiveNumberToMinus(y, x);
		}
		else if (x.Is_negative)
		{
			resault = ForcePositiveNumberToPlus(x, y);
			resault.Is_negative = true;
		}
		else if (y.Is_negative)
		{
			resault = ForcePositiveNumberToPlus(x, y);
		}
		else
		{
			resault = ForcePositiveNumberToMinus(x, y);
		}
		return resault;
	}
	static number multyplication(number x, number y)
	{
		number resault;
		if (x.Is_negative && y.Is_negative)
		{
			resault = ForcePositiveNumberToMultyplication(y, x);
		}
		else if (x.Is_negative||y.Is_negative)
		{
			resault = ForcePositiveNumberToMultyplication(x, y);
			resault.Is_negative = true;
		}
		else
		{
			resault = ForcePositiveNumberToMultyplication(x, y);
		}
		return resault;
	}
	static number division(number x, number y)
	{
		number resault;
		if (x.Is_negative && y.Is_negative)
		{
			resault = ForcePositiveNumberToDivision(y, x);
		}
		else if (x.Is_negative || y.Is_negative)
		{
			resault = ForcePositiveNumberToDivision(x, y);
			resault.Is_negative = true;
		}
		else
		{
			resault = ForcePositiveNumberToDivision(x, y);
		}
	}
};


class verylong
{
private:
	number dig;
	

public:
	verylong() = default;
	verylong(long x)
	{
		dig.length = number_digit(x);
		dig.Is_negative = x < 0;
		if (dig.Is_negative) x *= -1;
		while (x)
		{
			dig.strvalue += IntToChar(x - ((x / 10) * 10));
			x /= 10;
		}
		reverseStr(dig.strvalue);
	}
	verylong& operator+(verylong& x)
	{
		verylong* tocopy = new verylong();
		tocopy->dig = Operators::PLUS(this->dig, x.dig);
		return *tocopy;
	}
	verylong& operator-(verylong& x)
	{
		verylong* tocopy = new verylong();
		tocopy->dig = Operators::minus(this->dig, x.dig);
		return *tocopy;
	}
	verylong& operator*(verylong& x)
	{
		verylong* tocopy = new verylong();
		tocopy->dig = Operators::multyplication(this->dig, x.dig);
		return *tocopy;
	}
	verylong& operator/(verylong& x)
	{
		verylong* tocopy = new verylong();
		tocopy->dig = Operators::division(this->dig, x.dig);
		return *tocopy;
	}
	friend istream& operator>>(istream&, verylong&);
	friend ostream& operator<<(ostream&, verylong&);
};
istream& operator>>(istream& cin, verylong& x)
{
	string temp;
	cin >> temp;
	if (temp[0] == '-')
	{
		x.dig.Is_negative = true;
		temp = temp.substr(1);
	}
	x.dig.strvalue = temp;

	return cin;
}
ostream& operator<<(ostream& out, verylong& x)
{
	if (x.dig.Is_negative)
		out << "-";
	out << x.dig.strvalue;
	return out;
}



int main()
{
	
	verylong x, y;
	x = -4;
	y = -19;
	cout << x-y;
	return 0;
}

inline char IntToChar(int x) { return x + 48; }
inline int CharToInt(char x) { return x - 48; }
void reverseStr(string& y)
{
	for (int i = 0;i < y.length() / 2;i++)
	{
		char temp = y[i];
		y[i] = y[y.length() - 1 - i];
		y[y.length() - 1 - i] = temp;
	}
}
inline int number_digit(long x)
{

	int resault = 0;
	while (x)
	{
		resault++;
		x /= 10;
	}
	return resault;
}
int StringToInt(string ToInt)
{
	int temp = 1, sum = 0;
	for (int i = 0;i < ToInt.length();i++)
	{
		sum += ToInt[i] - 48;
		sum *= 10;
	}
	sum /= 10;
	return sum;
}
inline int StringToInt(char y)
{
	return y - 48;
}
