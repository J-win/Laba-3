#include "..\include\arithmetic.h"
#include <iostream>
// реализация функций и классов для вычисления арифметических выражений

Lexmem::Lexmem(const int n, const string  s, const double d, const char c)
{
	parametr = s;
	number = d;
	sign = c;
	num = n;
}

Lexmem::Lexmem(const Lexmem & s)
{
	parametr = s.parametr;
	number = s.number;
	sign = s.sign;
	num = s.num;
}

Lexmem::Lexmem(const string & s)
{
	parametr = s;
	num = 2;
}

Lexmem::Lexmem(const double s)
{
	number = s;
	num = 1;
}

Lexmem::Lexmem(const char s)
{
	sign = s;
	num = 0;
}

Lexmem & Lexmem::operator=(const Lexmem & a)
{
	parametr = a.parametr;
	number = a.number;
	sign = a.sign;
	num = a.num;
	return *this;
}

Lexmem & Lexmem::operator=(const string & a)
{
	parametr = a;
	num = 2;
	return *this;
}

Lexmem & Lexmem::operator=(const double a)
{
	number = a;
	num = 1;
	return *this;
}

Lexmem & Lexmem::operator=(const char c)
{
	sign = c;
	num = 0;
	return *this;
}

bool Lexmem::operator==(const Lexmem & a) const
{
	if (this != &a)
	{
		if (num == a.num)
		{
			if (num == 1)
			{
				if (number != a.number)
					return false;
				else
					return true;
			}
			else
			{
				if (num == 0)
				{
					if (sign != a.sign)
						return false;
					else
						return true;
				}
				else
				{
					if (parametr != a.parametr)
						return false;
					else
						return true;
				}
			}

		}
		else
			return false;
	}
	else
		return true;
}

bool Lexmem::operator!=(const Lexmem & a) const
{
	return (!(*this == a));
}

string Lexmem::retp() const
{
	return parametr;
}

double Lexmem::retn() const
{
	return number;
}

char Lexmem::retc() const
{
	return sign;
}

int Lexmem::retb() const
{
	return num;
}

ostream & operator<<(ostream & out, const Lexmem & v)
{
	if (v.num == 1)
		out << v.number;
	else
		if (v.num == 0)
			out << v.sign;
		else
			out << v.parametr;
	return out;
}

double rank_number(const double a, const int i)
{
	double b = 1;
	for (int j = 0; j < i; j++)
		b *= a;
	return b;
}

double converter_in_number(const string &s)
{
	int len = s.length();
	double a = 0.0;
	int i = 0;
	for (i = 0; ((i < len) && (s[i] != '.')); i++)
		a = a * 10.0 + (s[i] - '0');
	int j = i;
	if (s[j] == '.')
		for (i = j + 1; i < len; i++)
			a = a + (s[i] - '0') / (rank_number(10.0, (i - j)));
	return a;
}

int prioritet_sign(const char c)
{
	switch (c)
	{
	case '(':
		return 0;
		break;
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	}
}

double evaluating_the_expression(const double a, const double b, const char c)
{
	switch (c)
	{
	case '+':
		return (a + b);
		break;
	case '-':
		return (b - a);
		break;
	case '*':
		return (a * b);
		break;
	case '/':
		return (b / a);
		break;
	}
}

bool check_for_correctness(const string & s)
{
	if (s != "")
	{
		string c;
		c = c + ' ';
		c = c + s;
		c = c + ' ';
		string signs = "*+-/";
		string wrong_signs = "=\\|&!`~@#%^_?,:;'\"№ ";
		int len = c.length();
		int f = 0;
		int t = 0;
		if ((signs.find(c[1]) != signs.npos) && (c[1] != '-'))
		{
			cout << "The sign at the beginning" << endl;
			return false;
		}
		if (signs.find(c[len - 2]) != signs.npos)
		{
			cout << "The sign at the end" << endl;
			return false;
		}
		for (int i = 1; i < len - 1; i++)
		{
			if (wrong_signs.find(c[i]) != wrong_signs.npos)
			{
				cout << "Wrong signs" << endl;
				return false;
			}
			if ((signs.find(c[i]) != signs.npos) && (signs.find(c[i + 1]) != signs.npos))
			{
				cout << "Two sign next" << endl;
				return false;
			}
			if ((signs.find(c[i]) != signs.npos) && (c[i + 1] == ')'))
			{
				cout << "The sign in front of parenthesis" << endl;
				return false;
			}
			if ((c[i] == '(') && (c[i + 1] != '-') && (signs.find(c[i + 1]) != signs.npos))
			{
				cout << "Sign after parenthesis" << endl;
				return false;
			}
			if ((c[i] == ')') && (c[i + 1] == '('))
			{
				cout << "Not enough sign" << endl;
				return false;
			}
			if ((c[i] == '(') && (c[i + 1] == ')'))
			{
				cout << "Not enough expression" << endl;
				return false;
			}
			if ((c[i] >= '0') && (c[i] <= '9') && (c[i + 1] == '('))
			{
				cout << "Lost sign" << endl;
				return false;
			}
			if ((c[i] == ')') && (c[i + 1] >= '0') && (c[i + 1] <= '9'))
			{
				cout << "Lost sign" << endl;
				return false;
			}
			if ((c[i] == '.') && (((c[i + 1] <= '0') || (c[i + 1] >= '9')) || ((c[i - 1] <= '0') || (c[i - 1] >= '9'))))
			{
				cout << "Wrong signs" << endl;
				return false;
			}
			if (((c[i] >= '0') && (c[i] <= '9')) || (c[i] == '.'))
			{
				if ((c[i] == '.'))
					t++;
				if (t > 1)
				{
					cout << "Wrong signs" << endl;
					return false;
				}
			}
			else
				t = 0;
			if (c[i] == ')')
				f--;
			if (f < 0)
			{
				cout << "More )" << endl;
				return false;
			}			
			if (c[i] == '(')
				f++;
		}
		if (f > 0)
		{
			cout << "More (" << endl;
			return false;
		}
		return true;
	}
	else
	{
		cout << "Null" << endl;
		return false;
	}
}

Stack<Lexmem> convert_string_to_stack(const string & c)
{
	if (!check_for_correctness(c))
		throw "No corrctness";
	string s;
	s = s + ' ';
	s = s + c;
	int len = s.length();
	Stack<Lexmem> stack(len);
	string string_number;
	string string_parametr;
	Lexmem b;
	int j = 1;
	bool f = false;
	if (s[1] == '-')
	{
		f = true;
		j = 2;
	}
	for (int i = j; i < len; i++)
	{
		if ((s[i] == '-') && (s[i - 1] == '('))
			f = true;
		else
		{
			if ((((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))) || ((s[i] <= '9') && (s[i] >= '0') && (string_parametr != "")))
				string_parametr = string_parametr + s[i];
			else
			{
				if (string_parametr != "")
				{
					if (f)
					{
						string_parametr = '-' + string_parametr;
						f = false;
					}
					b = string_parametr;
					stack.push(b);
					string_parametr = "";
				}
				if ((((s[i] <= '9') && (s[i] >= '0')) || (s[i] == '.')))
					string_number = string_number + s[i];
				else
				{
					if (string_number != "")
					{
						double k = converter_in_number(string_number);
						if (f)
						{
							k *= -1;
							f = false;
						}
						b = k;
						stack.push(b);
						string_number = "";
					}
					b = s[i];
					stack.push(b);
				}
			}
		}
	}
	if (string_parametr != "")
	{
		if (f)
		{
			string_parametr = '-' + string_parametr;
			f = false;
		}
		b = string_parametr;
		stack.push(b);
	}
	if (string_number != "")
	{
		double k = converter_in_number(string_number);
		if (f)
		{
			k *= -1;
			f = false;
		}
		b = k;
		stack.push(b);
	}
	return stack;
}

Stack<Lexmem> polish_notation(const Stack<Lexmem>& s)
{
	Stack<Lexmem> stack_1 = s;
	stack_1.convert();
	Stack<Lexmem> stack_2(s.get_nElem());
	Lexmem element_stack_1;
	Stack<char> sign_stack;
	while (!(stack_1.check_void()))
	{
		element_stack_1 = stack_1.pop();
		if (element_stack_1.retb() != 0)
			stack_2.push(element_stack_1);
		else
		{
			char c = element_stack_1.retc();
			if (sign_stack.check_void())
				sign_stack.push(c);
			else
			{
				if (c == '(')
					sign_stack.push(c);
				else
				{
					if (c == ')')
					{
						while (sign_stack.top() != '(')
							stack_2.push(sign_stack.pop());
						sign_stack.pop();
					}
					else
					{
						while ((!(sign_stack.check_void())) && (prioritet_sign(c) <= prioritet_sign(sign_stack.top())))
							stack_2.push(sign_stack.pop());
						sign_stack.push(c);
					}
				}
			}
		}
	}
	while (!(sign_stack.check_void()))
		stack_2.push(sign_stack.pop());
	return stack_2;
}

double the_solution_of_the_expression(const Stack<Lexmem>& s)
{
	Stack<Lexmem> stack_p = s;
	Stack<Lexmem> stack;
	int i = stack_p.get_nElem();
	Lexmem* st = new Lexmem[i];
	i = 0;
	while (!(stack_p.check_void()))
	{
		Lexmem b = stack_p.pop();
		if (b.retb() == 2)
		{
			int k = 1;
			string min = b.retp();
			if (min[0] == '-')
			{
				k = -1;
				min.erase(0, 1);
				b = min;
			}
			bool f = true;
			for (int j = 0; ((j < i) && (f)); j++)
				if (st[j].retp() == b.retp())
				{
					f = false;
					b = st[j];
				}
			if (f)
			{
				cout << "Write parametr " << b.retp() << endl;
				double d;
				cin >> d;
				Lexmem a(b.retb(), b.retp(), k * d, b.retc());
				b = k * d;
				stack.push(b);
				st[i++] = a;
			}
			else
			{
				Lexmem e;
				if (k == -1)
					e = k * b.retn();
				stack.push(e);
			}
		}
		else
			stack.push(b);
	}
	Stack<double> number_stack;
	while (!(stack.check_void()))
	{
		Lexmem d = stack.pop();
		if (d.retb())
			number_stack.push(d.retn());
		else
		{
			double number_1 = number_stack.pop();
			double number_2 = number_stack.pop();
			char sign = d.retc();
			number_stack.push(evaluating_the_expression(number_1, number_2, sign));
		}
	}
	return number_stack.top();
}