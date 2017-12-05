// реализация пользовательского приложения

#include "arithmetic.h"
#include "stack.h"
int main()
{
	int h = 1;
	string a;
	while (h == 1)
	{
		cout << "Write" << endl;
		getline(cin, a);
		while (!(check_for_correctness(a)))
		{
			cout << "Write again" << endl;
			getline(cin, a);
		}
		cout << the_solution_of_the_expression(convert_string_to_stack(a)) << endl;
		cout << "Repeat?" << endl;
		cout << "1 - yes" << endl;
		cout << "2 - no" << endl;
		cin >> h;
	}
	return 0;
}
