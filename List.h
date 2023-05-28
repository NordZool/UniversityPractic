#include <iostream>
using namespace std;



class SingleListStudents {
	public:
	int size;

	SingleListStudents();
	~SingleListStudents();


	void addStudents();
	bool search(string lastName);
	void deleteAllStudent();
	bool deleteStudent(string lastN);
	void sortLastName();
	void sortGroup();
	void printProgress();
	void print();
	void printInFile(); 
	void scanFromFile(); 

    private:
	void push(string firstN, string lastN, string group, int progress[]);
struct Node {
	Node *next;
	string firstName;
	string lastName;
	string groupNumber;
	int progress[5];
};
Node* head;
Node* first;
};