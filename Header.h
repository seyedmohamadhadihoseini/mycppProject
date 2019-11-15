#pragma once
//namespace CppNtt {
//	double sin(double r);
//	double cos(double r);
//	int hadi(int a = 114, int b = 140);
//	void show(int val);
//	void show(double val);
//	void show(char const* val);
//	struct person {
//		int sum(int a = 2, int b = 2, int c = 3);
//	};
//	namespace Operator {
//		double plus(double);
//		typedef void poch;
//		void meesage();
//	}
//
//}
//namespace test {
//	class hadi
//	{
//	public:
//		hadi();
//		~hadi();
//		hadi(int);
//		void set(int n);
//		void set(int& n)const;
//		int get();
//		int get()const;
//		void messageForWelcome();
//		 int numberofobj;
//		 void print(const char* t);
//		template <typename T>
//		void print(T)const;
//		void print();
//	private:
//		int n = 2;
//	};
//
//
//}
/*namespace Singelton
{
	class polyton
	{
	public:
		polyton() = delete;
		void Show();
		void Show()const;
			polyton& GetInstance(int, int, char*, char*);
		void operator=(polyton&t);
	private:
			int count;
			const int numberObj = 3;
		int age;
		char* name;
		char* address;
		int phone;
		polyton(int, int, char*, char*);
	};
}*/
namespace ContactBook
{
	class Person
	{
	public:
		Person(int, char*, int, char*);
		Person() = default;
		bool Is_equal(Person&);
		void Edit(int, char*, int, char*);
		bool Is_older(Person&);
		bool Is_Younger(Person&);
		int getTell();
		char* getName();
		void Show();
	private:
		int age;
		char* name;
		char* address;
		int tell;
	};

	class BookContact
	{
	public:
		BookContact(Person*, int);
		void Add(Person&);
		bool Remove(Person&);
		bool Remove(int);
		Person& Search(int);
		Person& Search(char*);


		~BookContact();

	private:
		Person* arrayPerson = nullptr;
		int numberOfPerson = 0;
		int reservesForPerson = 0;
		static const int Extra = 10;
	};
}