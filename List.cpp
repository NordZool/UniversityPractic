#include "List.h"

SingleListStudents::SingleListStudents() {
	head = nullptr;
    first = nullptr;
    size = 0;
}
SingleListStudents::~SingleListStudents(){
	deleteAllStudent();
}

void SingleListStudents::push(string firstN, string lastN, string group, int progress[]) {
	Node* student = new Node;
	student->firstName = firstN;
	student->lastName = lastN;
	student->groupNumber = group;
	for(int j = 0; j < 5; j++) {
	student->progress[j] = progress[j];
	}

    if (first != nullptr){
    head->next = student;
	head = student;
    } else {
        first = student;
        head = student;
    }
    head->next = nullptr;

    size++;
}

void SingleListStudents::addStudents() {
    int n;
	cout << "Введите количиство студентов: ";
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string firstName, lastName;
		cout << "Имя - ";
		cin >> firstName;
		cout << "Фамилия - ";
		cin >> lastName;
		cout << "Группа - ";
		string group;
		cin >> group;
		
		int progres[5];
		cout << "Успеваемость: ";
		for(int j = 0; j < 5; j++) {
			progres[j] = rand()%11;
			cout << progres[j] << " ";
		}
		cout << endl;

		push(firstName, lastName, group, progres);
	}
}

bool SingleListStudents::search(string lastName) {
    Node* current = first;
    while(current != nullptr) {
        if (current->lastName == lastName) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SingleListStudents::deleteAllStudent() {
    Node* current = first;
	Node* currentNext;
	while(current != nullptr) {
		currentNext = current->next;
		delete current;
		current = currentNext;
	}
    head = nullptr;
    first = nullptr;
    size = 0;
}

bool SingleListStudents::deleteStudent(string lastN) {
    Node* current = first;
    Node* previor = nullptr;

    while (current != nullptr) {

        if(current->lastName == lastN) {
            if (previor != nullptr) {
                previor->next = current->next;
            } else {
                first = current->next; //если удаляется первый элемент
            }
            if (current == head) {
                previor = head; //если удаляется последний элемент
            }

            size--; 
            delete current;
            return true;
        } else {
            previor = current;
            current = current->next;
        }
    }

    return false;
}

void SingleListStudents::sortLastName() {
    if (size <= 1) {
        return; // нет необходимости сортировать
    }

    for(int i = 0; i < size; i++) {
        Node* current = first;
        Node* previor = nullptr;

        while(current->next != nullptr) {
            Node* nextNode = current->next;

            //int currentScalar = current->lastName[0] >= 97 ? current->lastName[0] + 0 : current->lastName[0] + 32;
            //int nextNodeScalar = nextNode->lastName[0] >= 97 ? nextNode->lastName[0] + 0 : nextNode->lastName[0] + 32;
            if (current->lastName > nextNode->lastName) {
                if (nextNode == head) {
                    head = current;
                }
                current->next = nextNode->next;
                nextNode->next = current;

                if (!previor) {
                    first = nextNode; // если до этого нету узлов, то следующий элемент станет первым при swap'е
                } else {
                    previor->next = nextNode; // иначе, прекрипить оставшийся узел к nextNode
                }
                previor = nextNode;
            } else {
                previor = current;
                current = current->next;
            }
        }
    }
}

void SingleListStudents::sortGroup() {
    if (size <= 1) {
        return; // нет необходимости сортировать
    }

    for(int i = 0; i < size; i++) {
        Node* current = first;
        Node* previor = nullptr;

        while(current->next) {
            Node* nextNode = current->next;
            if (current->groupNumber > nextNode->groupNumber) {
                if (nextNode == head) {
                    head = current;
                }
                current->next = nextNode->next;
                nextNode->next = current;

                if (previor == nullptr) {
                    first = nextNode; // если до этого нету узлов, то следующий элемент станет первым при swap'е
                } else {
                    previor->next = nextNode; // иначе, прекрипить оставшийся узел к nextNode
                }
                previor = nextNode;
            } else {
                previor = current;
                current = current->next;
            }
        }
    }
}


void SingleListStudents::printProgress() {
    Node* current = first;
    float mediumScore = 0.0;
    while(current != nullptr) {
        float singleSum = 0.0;

        for(int j = 0; j < 5; j++) {
            singleSum += current->progress[j];
        }
        mediumScore += singleSum / 5;
        current = current->next;
    }
    mediumScore /= size;

    cout << "Средний балл среди студентов - " << mediumScore << ".\nСписок фамилий учащихся, имеющих балл выше среднего: " << endl;
    current = first;

    while(current != nullptr){
        float singleSum = 0.0;
        for(int j = 0; j < 5; j++) {
            singleSum += current->progress[j];
        }

        if (singleSum > mediumScore) {
        cout << current->lastName << endl;
        }
        current = current->next;
    }
}

void SingleListStudents::print() {
	Node* current = first;
	int i = 1;
	while (current != nullptr) {
		cout << "№" << i << endl;
		cout << "Фимилия: " << current->lastName << endl;
        cout << "Имя: " << current->firstName << endl;
		cout << "Группа: " << current->groupNumber << endl;
        cout << "Оценки: ";
		for(int j = 0; j < 5; j++) {
		cout << current->progress[j] << " ";
		} 
		cout << endl << endl;

		current = current->next;
		i++;
	}
}

void SingleListStudents::printInFile() {
    FILE* printFile = fopen("data.txt", "wr");
    fprintf(printFile, "members: %d\n\n", size);
    Node* current = first;

    int i = 1; //счетчик студентов
    while(current != nullptr) {
        fprintf(printFile, "№%d\n", i);
        fprintf(printFile, "Фамилия: %s\n", current->lastName.c_str());
        fprintf(printFile, "Имя: %s\n", current->firstName.c_str());
        fprintf(printFile, "Группа: %s\n", current->groupNumber.c_str());

        int* arr = current->progress;// для более сокращенной записи
        fprintf(printFile, "Оценки: %d, %d, %d, %d, %d.\n\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
        i++;
        current =  current->next;
    }
    fclose(printFile);
}

void SingleListStudents::scanFromFile() {
    FILE* scanFile = fopen("data.txt", "rt");
    int fileSize;
    fscanf(scanFile, "members: %d\n\n", &fileSize);

    int i = 0; //счетчик студентов
    while(i != fileSize) {
        fscanf(scanFile, "№%d\n", &i);

        char temp[30];
        fscanf(scanFile, "Фамилия: %s\n", temp);
        string lastName = temp;

        fscanf(scanFile, "Имя: %s\n", temp);
        string firstName = temp;

        fscanf(scanFile, "Группа: %s\n", temp);
        string group = temp;

        int arr[5];
        fscanf(scanFile, "Оценки: %d, %d, %d, %d, %d.\n\n", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

        push(firstName, lastName, group, arr);
    }
    fclose(scanFile);
}
