#include "List.cpp"


/*Описать структуру с именем STUDENT, с полями: фамилия, имя, номер группы, успеваемость (массив из пяти элементов).
 Сформировать односвязный список. Затем напечатать элементы списка по возрастанию номера группы.
 Затем напечатать фамилии студентов, у которых средний балл выше общего среднего балла по всем студентам.*/


int main() {
	
	SingleListStudents students;
	string choise;
	do {
		cout << "Выберите действие(чтобы выйти ввидите любою букву): " << endl;
		cout << "0. Добавить студента" << endl;
		cout << "1. Поиск студента по фамилии" << endl;
		cout << "2. Удалить студента по фамилии" << endl;
		cout << "3. Удалить всех студентов" << endl;
		cout << "4. Сортировать студентов по группе" << endl;
		cout << "5. Сортировать студентов по алфавиту" << endl;
		cout << "6. Вывести список всех студентов" << endl;
		cout << "7. Вывести фамилии студентов, у которых средний балл выше общего среднего балла по всем студентам." << endl;
		cout << "8. Напечатать текущий список в файл data.txt" << endl;
		cout << "9. Считать информацию о студентах с файла data.txt, и добавить ее к текущему списку" << endl;

		cin >> choise;
		string inPutStr; // используется, где надо ввести строку
		switch (choise[0] - 48)
		{
		case 0:
			students.addStudents();
			break;
		case 1:
			cout << "Введите фамилию: ";
			cin >> inPutStr;
			if (students.search(inPutStr)) {
				cout << "Студент найден" << endl;
			} else {
				cout << "Студент не найден" << endl;
			}
			break;
		case 2:
			cout << "Введите фамилию: ";
			cin >> inPutStr;
			if (students.deleteStudent(inPutStr)) {
				cout << "Студент удален" << endl;
			} else {
				cout << "Студент не найден" << endl;
			}
			break;
		case 3:
			students.deleteAllStudent();
			cout << "Студенты удалены: " << endl;
			break;
		case 4:
			students.sortGroup();
			cout << "Студенты отсортированы" << endl;
			break;
		case 5:
			students.sortLastName();
			cout << "Студенты отсортированы" << endl;
			break;
		case 6:
			students.print();
			break;
		case 7:
			students.printProgress();
			break;
		case 8:
			students.printInFile();
			break;
		case 9:
			students.scanFromFile();
			break;
		
		default:
			break;
		}

	} while(choise[0] - 48 >= 0 && choise[0] - 48 <= 9);
}
 