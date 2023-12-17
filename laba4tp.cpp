#include <iostream>
using namespace std;


void check_data(class Bank *P);
void correct(class Bank* P);
void min_balance(class Bank* P);

class Bank
{
private:
	int id;
	std::string name;
	std::string surname;
	int amount_of_credits;
	int balance;

public:
	Bank();
	Bank(int id, string name, string surname, int credits, int balance);
	~Bank();

	// Редактирование и просмотр свойств
	void setID(int id);
	int getID();
	void setName(string name);
	std::string getName();
	void setSurname(string surname);
	std::string getSurname();
	void setCredits(int credits);
	int getCredits();
	void setBalance(int balance);
	int getBalance();

};



int main()
{
	Bank Ex1;
	Bank Ex2(1, "Alex", "Orlov", 2008, 200);
	Bank Ex3[2];

	int ExId;
	std::string ExName;
	std::string ExSurname;
	int ExCredits;
	int ExBalance;
	Bank Ex4[3];
	Bank* P = new Bank[3];
	int option = 100;
	int breaker = 1;

	Ex1.setID(0);
	Ex1.setName("Dmitriy");
	Ex1.setSurname("Danilov");
	Ex1.setCredits(15);
	Ex1.setBalance(2000);

	cout << "*******************************************" << endl;
	cout << Ex1.getID() << "  " << Ex1.getName() << "  " << Ex1.getSurname() << "  " << Ex1.getCredits() << "  " << Ex1.getBalance() << endl;
	cout << Ex2.getID() << "  " << Ex2.getName() << "  " << Ex2.getSurname() << "  " << Ex2.getCredits() << "  " << Ex2.getBalance() << endl;
	cout << "*******************************************" << endl;

	

	


	for (int i = 0; i < 2; i++)
	{
		cout << "Data for bank accounts" << endl;

		cout << "Enter ID: ";
		cin >> ExId;
		Ex3[i].setID(ExId);

		cout << "Enter name: ";
		cin >> ExName;
		Ex3[i].setName(ExName);

		cout << "Enter surname: ";
		cin >> ExSurname;
		Ex3[i].setSurname(ExSurname);

		cout << "Enter amount of credits: ";
		cin >> ExCredits;
		Ex3[i].setCredits(ExCredits);

		cout << "Enter balance: ";
		cin >> ExBalance;
		Ex3[i].setBalance(ExBalance);

		cout << endl;
	}
	cout << "*******************************************" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Bank accounts: " << endl;
		cout << Ex3[i].getID() << "  " << Ex3[i].getName() << "  " << Ex3[i].getSurname() << "  " << Ex3[i].getCredits() << "  " << Ex3[i].getBalance() << endl;
	}
	cout << "*******************************************" << endl;
	cout << "Welcome to the Bank OS menu. Choose the option, you want to do" << endl;

	while (true)
	{
		cout << "*******************************************" << endl;
		cout << "Choose 1, if you want to check data" << endl;
		cout << "Choose 2, if you want to correct data" << endl;
		cout << "Choose 3, if you want to find minimal balance in data" << endl;
		cout << "If you want to leave, choose 0" << endl;
		cout << "*******************************************" << endl;
		cin >> option;
		switch (option)
		{
		case 0:
			breaker = 0;
			break;
		case 1:
			check_data(P);
			cout << "*******************************************" << endl;
			break;
		case 2:
			correct(P);
			cout << "*******************************************" << endl;
			break;
		case 3:
			min_balance(P);
			cout << "*******************************************" << endl;
			break;
		default:
			cout << "You've chosen the wrong option. Please, try again carefully.";
		};

		if (breaker == 0)
		{
			cout << "Programm is shutting down." << endl;
			break;
		}
	}
	cout << "*******************************************" << endl;
	delete[] P;
	return 0;
}

void correct(class Bank* P)
{
	int n = 3;
	int key = 0;

	int new_id = 0;
	string new_name = "";
	string new_surname = "";
	int new_credits = 0;
	int new_balance = 0;

	cout << "Which line you wanna to change?" << endl;
	cin >> key;
	if ((key != 1) and (key != 2) and (key != 3))
	{
		cout << "You has typed incorrect number of line. Process is stopped" << endl;
	}
	else
	{
		cout << "Enter new ID " << endl;
		cin >> new_id;
		P[key - 1].setID(new_id);

		cout << "Enter new name " << endl;
		cin >> new_name;
		P[key - 1].setName(new_name);

		cout << "Enter new surname " << endl;
		cin >> new_surname;
		P[key - 1].setSurname(new_surname);

		cout << "Enter new amount of credits " << endl;
		cin >> new_credits;
		P[key - 1].setCredits(new_credits);

		cout << "Enter new balance " << endl;
		cin >> new_balance;
		P[key - 1].setBalance(new_balance);
	}

}



void min_balance(class Bank* P)
{
	int n = 3;
	int res = 2147483647;
	for (int i = 0; i < n; i++)
	{
		if (P[i].getBalance() < res)
		{
			res = P[i].getBalance();
		}
	}
	cout << "Minimal balance = " << res << endl;
}


void check_data(class Bank *P)
{
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		cout << P[i].getID() << " ";
		cout << P[i].getName() << " ";
		cout << P[i].getSurname() << " ";
		cout << P[i].getCredits() << " ";
		cout << P[i].getBalance() << endl;
	}
}



Bank::Bank()
{
	id = 0;
	name = "No";
	surname = "No";
	amount_of_credits = 0;
	balance = 0;
}

Bank::Bank(int id_data, string name_data, string surname_data, int credits_data, int balance_data)
{
	id = id_data;
	name = name_data;
	surname = surname_data;
	amount_of_credits = credits_data;
	balance = balance_data;
}

Bank::~Bank()
{

}


void Bank::setID(int data)
{
	id = data;
}

int Bank::getID()
{
	return id;
}

void Bank::setName(std::string data)
{
	name = data;
}

std::string Bank::getName()
{
	return name;
}

void Bank::setSurname(std::string data)
{
	surname = data;
}

std::string Bank::getSurname()
{
	return surname;
}

void Bank::setCredits(int data)
{
	amount_of_credits = data;
}

int Bank::getCredits()
{
	return amount_of_credits;
}

void Bank::setBalance(int data)
{
	balance = data;
}

int Bank::getBalance()
{
	return balance;
}

