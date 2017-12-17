// реализация пользовательского приложения

#include "arithmetic.h"
#include "stack.h"
int main()
{
	int h = 1;
	while (h == 1)
	{
		int f = 1;
		string a;
		cout << "Write" << endl;
		getline(cin, a);
		while (!(check_for_correctness(a)))
		{
			cout << "Write again" << endl;
			getline(cin, a);
		}
		Stack<Lexmem> b;
		b = convert_string_to_stack(a);
		b = polish_notation(b);
		while (f == 1)
		{
			cout << the_solution_of_the_expression(b) << endl;
			cout << "Repeat with other parametrs?" << endl;
			cout << "1 - yes" << endl;
			cout << "2 - no" << endl;
			cin >> f;
		}
		cout << "Repeat?" << endl;
		cout << "1 - yes" << endl;
		cout << "2 - no" << endl;
		cin >> h;
	}
	return 0;
}
