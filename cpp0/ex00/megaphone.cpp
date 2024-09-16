#include <iostream>
#include <string>
#include <locale>
int main(int argc ,char **argv)
{
	std ::locale	str;

	int	j(1);

	if (argc > 1)
	{
		while (argv[j])
		{
			for(int i(0); argv[j][i] ; i++)
				std ::cout << toupper(argv[j][i], str);
            j++;
		}
		std ::cout << std ::endl;
	}
	else
		std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std ::endl;
	return (0);
}


