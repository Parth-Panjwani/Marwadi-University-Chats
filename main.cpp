#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

    string str;
    string str1;
    string FirstPerson;
    string SecondPerson;

    cout << "Welcome to MU Chats :)" << endl;
	cout << "If you want to keep chat secrect the end program with CTRL+C else '$end$' " <<endl; 
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;

    cout << "First Person Name: ";
    getline(cin, FirstPerson);

    cout << endl;

    cout << "Second Person Name: ";
    getline(cin, SecondPerson);

    cout << "Conversation Starts" << endl;
	
    ofstream file("chat_history.txt", ios::out | ios::app);
	if(file.is_open())
	{
		file << "First Person: " << FirstPerson << '\n';
		file << "Second Person: " << SecondPerson << '\n';
		file << "\n----------------------------------------------" << '\n';

		while (1)
		{
			str = ""; str1 = "";
			cout << FirstPerson << ": ";
			getline(cin, str);

			cout << SecondPerson << ": ";
			getline(cin, str1);

			if(str == "$end$" || str1 == "$end$")
				break;

			file << FirstPerson << ": " << str << '\n';
			file << SecondPerson << ": " << str1 << '\n' ;
			file << "--------------------------------------------" << '\n';
		}
	}
	else
		cout<<"Chats were not stored\n";

	file.close();

    return 0;
}
