#include "Header.h"
#include <iostream>
/*namespace Singelton
{
	int polyton::count = 0;
	polyton& polyton::GetInstance(int age, int tel, char* name, char* address)
	{
		if (count < numberObj)
		{
			count++;
			polyton temp(age, tel, name, address);
			return temp;
		}
		else
		{
			throw "Invalid The Number of Instance For Person Obj!\n";
		}


	}
	void polyton::Show()
	{
		std::cout << "Your Name is :" << name << " Age:" << age << " address:" << address << " \nphone:" << phone << std::endl;
	}

	void polyton::Show()const
	{
		std::cout << "Your Name is :" << name << " Age:" << age << " address:" << address << " \nphone:" << phone << std::endl;
	}
	polyton::polyton(int age, int tel, char* name, char* address)
	{
		this->address = address;
		this->age = age;
		this->name = name;
		this->phone = tel;
	}
	void polyton::operator=(polyton& t)
	{
		t.address = this->address;
		t.age = this->age;
		t.name = this->name;
		t.phone = this->phone;
	}
}*/
namespace ContactBook
{
	bool Is_Equal(char* first, char* second)
	{
		int i;
		for (i = 0;first[i] != '\0';++i)
		{
			if (first[i] != second[i])
			{
				return false;
			}
		}
		if (second[i] == '\0')
			return true;
		return false;

	}
	Person::Person(int tel, char* name = (char*)"", int age = 0, char* address = (char*)"")
	{
		Edit(tel, name, age, address);
	}
	///To Count Number of Instance!
	bool Person::Is_equal(Person& b)
	{
		bool equal = true;
		if (this->age != b.age)
			equal = false;
		else if (this->tell = b.tell)
			equal = false;
		else if (!ContactBook::Is_Equal(this->address, b.address))
			equal = false;
		else if (!ContactBook::Is_Equal(this->name, b.name))
			equal = false;
		return equal;
	}
	void Person::Edit(int tel, char* name = (char*)"", int age = 0, char* address = (char*)"")
	{
		this->name = name;
		this->address = address;
		this->age = age;
		this->tell = tel;
	}
	bool Person::Is_older(Person& t)//chera agar & ra hazf konam error dare?
	{
		if (this->age > t.age)
			return true;
		return false;
	}
	void Person::Show()
	{
		std::cout << "Name:" << name << "\tAge:" << age << "\ttelephone:" << tell << "\nAddress:" << address;
	}
	bool Person::Is_Younger(Person& t)
	{
		return !Is_older(t);
	}
	int Person::getTell()
	{
		return tell;
	}
	char* Person::getName()
	{
		return this->name;
	}

	BookContact::BookContact(Person* people, int numberPeople)
	{
		numberOfPerson = numberPeople;
		reservesForPerson = numberOfPerson + Extra;
		this->arrayPerson = new Person[reservesForPerson];
		*this->arrayPerson = *people;
	}
	BookContact::~BookContact()
	{
		delete[]arrayPerson;
		arrayPerson = nullptr;
		std::cout << "Constractor Is Called\n";
	}
	void BookContact::Add(Person& a)
	{
		if (numberOfPerson < reservesForPerson)
		{
			arrayPerson[numberOfPerson - 1] = a;
			numberOfPerson++;
		}
		else
		{
			reservesForPerson += Extra;
			Person* temp = new Person[reservesForPerson];
			for (int i = 0;i < numberOfPerson;++i)
			{
				temp[i] = arrayPerson[i];
			}
			delete[]arrayPerson;
			arrayPerson = temp;
			temp = nullptr;
		}
	}
	bool BookContact::Remove(Person& a)
	{
		for (int i = 0;i < numberOfPerson;i++)
			if (a.Is_equal(arrayPerson[i]))
			{
				for (int j = i + 1;j < numberOfPerson;j++)
					arrayPerson[j - 1] = arrayPerson[j];
				numberOfPerson--;
				return true;
			}
		return false;
	}
	bool BookContact::Remove(int tel)
	{
		return 	Remove(Search(tel));
	}
	Person& BookContact::Search(int tel)
	{
		for (int i = 0;i < numberOfPerson;i++)
		{
			if (arrayPerson[i].getTell() == tel)
			{
				return arrayPerson[i];
			}
		}
	}
	Person& BookContact::Search(char* s)
	{
		for (auto i = 0; i < numberOfPerson; i++)
		{
			if (arrayPerson[i].getName() == s)
			{
				return arrayPerson[i];
			}
		}
	}
}