#include <iostream>
#include <string>
using namespace std;

int main() {

	string input;
	long count = 0;

	//크로아티아 알파벳 입력
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{	
		// if (input[i] == '=' || input[i] == '-')
		// 	continue;

		// c= , c-
		if (input[i] == 'c')
		{
			if (input[i + 1] == '=' || input[i + 1] == '-')
				i++;
			
			count++;
		}

		// dz= , d-
		else if (input[i] == 'd')
		{
			if (input[i + 1] == 'z')
			{
				if (input[i + 2] == '=')
					count++;
				else
					count += 3;
				i += 2;
			}

			else if (input[i + 1] == '-')
			{
				i++;
				count++;
			}

			else
				count++;
		}

		// lj
		else if (input[i] == 'l')
		{
			if (input[i + 1] == 'j')
				i++;

			count++;
		}

		// nj
		else if (input[i] == 'n')
		{
			if (input[i + 1] == 'j')
				i++;

			count++;
		}

		// s=
		else if (input[i] == 's')
		{
			if (input[i + 1] == '=')
				i++;

			count++;
		}

		// z=
		else if (input[i] == 'z')
		{
			if (input[i + 1] == '=')
				i++;

			count++;
		}

		else
			count++;
	}
	
	cout << count << endl;
}