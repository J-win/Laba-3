// ���������� ������� � ������� ��� ���������� �������������� ���������
#ifndef __Arithmetic_H__
#define __Arithmetic_H__
#include "stack.h"
class Lexmem
{
	string parametr;
	double number;
	char sign;
	int num;
public:
	Lexmem() {};
	Lexmem(const int n, const string s = "", const double d = 0.0, const char c = '0');
	Lexmem(const Lexmem &s);
	Lexmem(const string &s);
	Lexmem(const double s);
	Lexmem(const char s);
	~Lexmem() {};
	Lexmem& operator=(const Lexmem& a);
	Lexmem& operator=(const string& a);
	Lexmem& operator=(const double a);
	Lexmem& operator=(const char c);
	bool operator==(const Lexmem& a) const;
	bool operator!=(const Lexmem& a) const;
	string retp() const;
	double retn() const;
	char retc() const;
	int retb() const;
	friend ostream& operator<<(ostream &out, const Lexmem &v);
};
double rank_number(const double a, const int i);

double converter_in_number(const string &s);

int prioritet_sign(const char c);

double evaluating_the_expression(const double a, const double b, const char c);

bool check_for_correctness(const string &s);

Stack<Lexmem> convert_string_to_stack(const string &c);

Stack<Lexmem> polish_notation(const Stack<Lexmem> &s);

double the_solution_of_the_expression(const Stack<Lexmem> &s);

#endif