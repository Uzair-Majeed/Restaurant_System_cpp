#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;




//Forward Declaration because many ptrs are used in many struct simultaneously
struct Admin;
struct Employee;
struct EmpHashMap;
struct Customer;
struct CustHashMap;
struct Order;
struct OrderQueue;
struct Restaurant;
struct Dish;
struct Menu;
struct Promotion;
struct PromotionStack;
struct Review;
struct ReviewHeap;
struct Delivery;


void applyPromo(Order* ord, PromotionStack& promotions);
Customer* customerLogin(CustHashMap* h, string em, string name);
Employee* employeeLogin(EmpHashMap* h, string em, string name);
string getMaskedInput();
bool isValidCust(string email, CustHashMap* custHash);
bool isValidEmp(string email, EmpHashMap* empHash);


struct Delivery {

	int numVertices;
	string* vertices;
	int** adjMatrix;


	void addEdge(int src, int dest, int weight) {
		if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
			adjMatrix[src][dest] = weight;
			adjMatrix[dest][src] = weight;
		}
	}

	Delivery() {
		numVertices = 30;

		vertices = new string[numVertices];
		adjMatrix = new int* [numVertices];

		for (int i = 0; i < numVertices; i++) {
			adjMatrix[i] = new int[numVertices];

			for (int j = 0; j < numVertices; j++) {
				adjMatrix[i][j] = 0;
			}
		}

		// Hardcoding vertices
		vertices[0] = "F-5";
		vertices[1] = "F-6";
		vertices[2] = "F-7";
		vertices[3] = "F-8";
		vertices[4] = "F-9";
		vertices[5] = "F-10";
		vertices[6] = "F-11";
		vertices[7] = "F-12";
		vertices[8] = "G-5";
		vertices[9] = "G-6";
		vertices[10] = "G-7";
		vertices[11] = "G-8";
		vertices[12] = "G-9";
		vertices[13] = "G-10";
		vertices[14] = "G-11";
		vertices[15] = "G-12";
		vertices[16] = "G-13";
		vertices[17] = "G-14";
		vertices[18] = "H-8";
		vertices[19] = "H-9";
		vertices[20] = "H-10";
		vertices[21] = "H-11";
		vertices[22] = "I-8";
		vertices[23] = "I-9";
		vertices[24] = "I-10";
		vertices[25] = "I-11";
		vertices[26] = "I-12";
		vertices[27] = "I-14";
		vertices[28] = "I-15";
		vertices[29] = "I-16";



		// Hardcoding edges and weights
		//addEdge(src, dest, weight);

		addEdge(7, 9, 12);   // F-12 -> G-6
		addEdge(15, 19, 8);  // G-12 -> H-9
		addEdge(11, 7, 7);   // G-8 -> F-12
		addEdge(4, 22, 11);  // F-9 -> I-8
		addEdge(9, 4, 6);    // G-6 -> F-9
		addEdge(18, 24, 2);  // H-8 -> I-10
		addEdge(6, 19, 5);   // F-11 -> H-9
		addEdge(0, 3, 15);   // F-5 -> F-8
		addEdge(25, 23, 7);  // I-11 -> I-9
		addEdge(7, 1, 13);   // F-12 -> F-6
		addEdge(21, 10, 1);  // H-11 -> G-7
		addEdge(28, 15, 3);  // I-15 -> G-12
		addEdge(26, 18, 9);  // I-12 -> H-8
		addEdge(27, 9, 2);   // I-14 -> G-6
		addEdge(26, 23, 8);  // I-12 -> I-9
		addEdge(7, 29, 10);  // F-12 -> I-16
		addEdge(4, 7, 9);    // F-9 -> F-12
		addEdge(6, 12, 10);  // F-11 -> G-9
		addEdge(27, 14, 1);  // I-14 -> G-11
		addEdge(2, 12, 15);  // F-7 -> G-9
		addEdge(23, 20, 4);  // I-9 -> H-10
		addEdge(29, 17, 2);  // I-16 -> G-14
		addEdge(1, 28, 8);   // F-6 -> I-15
		addEdge(7, 27, 13);  // F-12 -> I-14
		addEdge(4, 21, 10);  // F-9 -> H-11
		addEdge(20, 24, 5);  // H-10 -> I-10
		addEdge(17, 15, 14); // G-14 -> G-12
		addEdge(21, 16, 1);  // H-11 -> G-13
		addEdge(26, 28, 6);  // I-12 -> I-15
		addEdge(4, 13, 3);   // F-9 -> G-10
		addEdge(0, 5, 2);    // F-5 -> F-10
		addEdge(12, 17, 12); // G-9 -> G-14
		addEdge(23, 6, 14);  // I-9 -> F-11
		addEdge(29, 2, 5);   // I-16 -> F-7
		addEdge(4, 25, 8);   // F-9 -> I-11
		addEdge(19, 10, 2);  // H-9 -> G-7
		addEdge(22, 14, 10); // I-8 -> G-11
		addEdge(21, 26, 9);  // H-11 -> I-12
		addEdge(15, 3, 4);   // G-12 -> F-8
		addEdge(5, 2, 6);    // F-10 -> F-7
		addEdge(0, 29, 7);   // F-5 -> I-16
		addEdge(18, 29, 13); // H-8 -> I-16
		addEdge(19, 11, 6);  // H-9 -> G-8
		addEdge(25, 3, 4);   // I-11 -> F-8
		addEdge(26, 15, 15); // I-12 -> G-12
		addEdge(1, 23, 3);   // F-6 -> I-9
		addEdge(27, 26, 8);  // I-14 -> I-12
		addEdge(6, 8, 1);    // F-11 -> G-5
		addEdge(11, 23, 5);  // G-8 -> I-9
		addEdge(18, 8, 11);  // H-8 -> G-5
		addEdge(5, 6, 6);    // F-10 -> F-11
		addEdge(13, 7, 5);   // G-10 -> F-12
		addEdge(12, 21, 7);  // G-9 -> H-11
		addEdge(19, 4, 11);  // H-9 -> F-9
		addEdge(7, 0, 2);    // F-12 -> F-5
		addEdge(1, 26, 9);   // F-6 -> I-12
		addEdge(28, 7, 14);  // I-15 -> F-12
		addEdge(8, 27, 12);  // G-5 -> I-14
		addEdge(4, 9, 15);   // F-9 -> G-6
		addEdge(28, 4, 7);   // I-15 -> F-9
		addEdge(11, 10, 2);  // G-8 -> G-7
		addEdge(7, 1, 14);   // F-12 -> F-6
		addEdge(19, 22, 3);  // H-9 -> I-8
		addEdge(13, 6, 1);   // G-10 -> F-11
		addEdge(22, 28, 2);  // I-8 -> I-15
		addEdge(4, 29, 9);   // F-9 -> I-16
		addEdge(19, 24, 3);  // H-9 -> I-10
		addEdge(18, 14, 6);  // H-8 -> G-11
		addEdge(21, 15, 4);  // H-11 -> G-12
		addEdge(23, 15, 7);  // I-9 -> G-12
		addEdge(22, 11, 10); // I-8 -> G-8
		addEdge(20, 22, 5);  // H-10 -> I-8
		addEdge(15, 25, 12); // G-12 -> I-11
		addEdge(24, 0, 15);  // I-10 -> F-5
		addEdge(5, 13, 13);  // F-10 -> G-10
		addEdge(1, 7, 1);    // F-6 -> F-12
		addEdge(27, 21, 2);  // I-14 -> H-11
		addEdge(14, 5, 5);   // G-11 -> F-10
		addEdge(24, 29, 14); // I-10 -> I-16
		addEdge(5, 1, 3);    // F-10 -> F-6
		addEdge(7, 3, 6);    // F-12 -> F-8
		addEdge(3, 1, 7);    // F-8 -> F-6
		addEdge(12, 6, 11);  // G-9 -> F-11
		addEdge(1, 19, 12);  // F-6 -> H-9
		addEdge(3, 12, 4);   // F-8 -> G-9
		addEdge(7, 21, 3);   // F-12 -> H-11
		addEdge(21, 28, 5);  // H-11 -> I-15
		addEdge(26, 17, 8);  // I-12 -> G-14
		addEdge(9, 4, 10);   // G-6 -> F-9
		addEdge(23, 14, 9);  // I-9 -> G-11


	}

	void displayLocations() {
		cout << "Available Locations"<<endl;
		for (int i = 0; i < numVertices; i++) {

			cout<<i+1<<" : " << vertices[i] << endl;
		}
	}

	void displayAdjMatrix() {
		cout << "Adjacency Matrix : " << endl;

		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++) {
				cout <<setw(4)<< adjMatrix[i][j]<<" ";
			}
			cout << endl;
		}

		cout << endl;
	}
};
//----------------------------------------------------------------------------------------------------------
//BinaryTree Structure
struct Dish {
	static int d_counter;
	int dishID;
	string dishName;
	string dishType;
	double dishPrice;
	Dish* left;
	Dish* right;
	Dish()
		: dishID(), dishName(""), dishType(""), dishPrice(0.0), left(nullptr), right(nullptr) {}

	Dish(string name, string type, double price)
		: dishID(d_counter++), dishName(name), dishType(type), dishPrice(price), left(nullptr), right(nullptr) {}
};
int Dish::d_counter = 10000;

#include <queue>

//----------------------------------------------------------------------------------------------------------
struct Menu {
	static int m_counter;
	int menuID;
	string menuName;
	int totalDishes;
	Dish* dishRoot;

	Menu(string name) :menuID(m_counter++), menuName(name), totalDishes(0), dishRoot(nullptr) {}
	//LEVEL ORDER INSERTION IN TREE
	void addDish(string name, string type, double price) {
		Dish* other = new Dish(name, type, price);
		if (dishRoot == nullptr) {
			dishRoot = other;
		}
		else {
			queue<Dish*> q;
			q.push(dishRoot);

			while (!q.empty()) {
				Dish* current = q.front();
				q.pop();

				if (current->left == nullptr) {
					current->left = other;
					break;
				}
				else {
					q.push(current->left);
				}

				if (current->right == nullptr) {
					current->right = other;
					break;
				}
				else {
					q.push(current->right);
				}
			}
		}
		totalDishes++;
	}
	//SEARCH FUNC FOR DISH
	Dish* findDish(Dish* root, int dishID) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->dishID == dishID) {
			return root;
		}

		Dish* found = findDish(root->left, dishID);
		if (found != nullptr) {
			return found;
		}

		return findDish(root->right, dishID);
	}
	//EDIT DISH DATA
	void editDish(int dishID, string newName, string newType, double newPrice) {
		Dish* dish = findDish(dishRoot, dishID);

		if (dish != nullptr) {
			dish->dishName = newName;
			dish->dishType = newType;
			dish->dishPrice = newPrice;
		}
		else {
			cout << "Dish not found!" << endl;
		}
	}
	//----------------------------------------------------------------
	//DELETE CODE AS LEARNED IN CLASS
	Dish* deleteNode(Dish* root, int data) {
		if (root == nullptr) return nullptr;

		if (root->left == nullptr && root->right == nullptr) {
			if (root->dishID == data) {
				delete root;
				return nullptr;
			}
			return root;
		}

		queue<Dish*> q;
		q.push(root);
		Dish* temp = nullptr;
		Dish* nodeToDelete = nullptr;

		while (!q.empty()) {
			temp = q.front();
			q.pop();

			if (temp->dishID == data) {
				nodeToDelete = temp;
			}

			if (temp->left) {
				q.push(temp->left);
			}

			if (temp->right) {
				q.push(temp->right);
			}
		}

		if (nodeToDelete != nullptr) {
			if (temp != nodeToDelete) {
				int t = temp->dishID;
				deleteDeepest(root, temp);
				nodeToDelete->dishID = t;
				nodeToDelete->dishName = temp->dishName;
				nodeToDelete->dishType = temp->dishType;
				nodeToDelete->dishPrice = temp->dishPrice;
			}
			else {
				deleteDeepest(root, temp);
			}
		}

		return root;
	}

	void deleteDeepest(Dish* root, Dish* temp) {
		queue<Dish*> q;
		q.push(root);

		while (!q.empty()) {
			Dish* t = q.front();
			q.pop();

			if (t->right == temp) {
				t->right = nullptr;
				delete temp;
				return;
			}
			else {
				q.push(t->right);
			}

			if (t->left == temp) {
				t->left = nullptr;
				delete temp;
				return;
			}
			else {
				q.push(t->left);
			}
		}
	}
	//-----------------------------------------------------------
	//LEVEL ORDER DISPLAY OF DISHES AS IT IS A BINARY TREE
	void displayLevelOrder() {
		if (dishRoot == nullptr) {
			cout << "The tree is empty!" << endl;
			return;
		}

		queue<Dish*> q;
		q.push(dishRoot);

		while (!q.empty()) {
			Dish* current = q.front();
			q.pop();

			cout << "Dish ID: " << current->dishID << ", Name: " << current->dishName
				<< ", Type: " << current->dishType << ", Price: $" << current->dishPrice << endl;

			if (current->left) {
				q.push(current->left);
			}

			if (current->right) {
				q.push(current->right);
			}
		}
	}

};

int Menu::m_counter = 10000;

//----------------------------------------------------------------------------------------------------------
//IMPLEMENTED USING STACK
struct Promotion {
	static int p_counter;
	int promoID;
	string promoName;
	double discount;
	int limit;
	Promotion* next;
	Promotion(string name, double disc, int limit)
		: promoID(p_counter++), promoName(name), discount(disc), limit(limit), next(nullptr) {}

};
int Promotion::p_counter = 10000;

struct PromotionStack {
	Promotion* top;

	PromotionStack() :top(nullptr) {}
	//PUSH FUNC
	void pushPromo(string name, double discount, int limit) {
		Promotion* temp = new Promotion(name, discount, limit);

		temp->next = top;
		top = temp;
	}

	bool isEmpty() {
		return top == nullptr;
	}
	//POP FUNC
	Promotion* popPromo() {
		if (isEmpty()) {
			cout << "No promotions available in server" << endl;
			return nullptr;
		}
		Promotion* temp = top;
		top = top->next;
		return temp;
	}
	//DISPLAY FUNC
	void displayPromotions() {
		if (isEmpty()) {
			cout << "No active promotions!" << endl;
			return;
		}
		Promotion* current = top;
		while (current != nullptr) {
			cout << "Promotion ID: " << current->promoID
				<< ", Name: " << current->promoName
				<< ", Discount: " << current->discount << " (" << current->discount * 100 << "%)"
				<< ", Usage Limit: " << current->limit << endl;
			current = current->next;
		}
	}
	//TOP PROMOTION FUNC
	Promotion* topPromo() {
		return top;

	}
};

struct DeliveryList {
	Order* ord;
	DeliveryList* next;

	DeliveryList():ord(nullptr),next(nullptr){}
	DeliveryList(Order * ord) :ord(ord), next(nullptr) {}
	
};
//----------------------------------------------------------------------------------------------------------
//NODE FOR EMPLOYEE HASHMAP
struct Employee {

	static int e_counter;
	int employeeID;
	string employeeName;
	string employeeEmail;
	string employeePass;
	string employeeType;
	Restaurant* workRestaurant;
	DeliveryList * head;		//sorted list of orders that the delivery guy has to deliver
	Employee* next;

	Employee() {
		this->employeeID = -1;
		this->employeeName = "";
		this->employeeEmail = "";
		this->employeePass = "";
		this->employeeType = "";
		this->workRestaurant = nullptr;
		this->next = nullptr;
		this->head = nullptr;
	}
	Employee(string n, string e, string t, string p, Restaurant* r) {
		this->employeeID = e_counter++;
		this->employeeName = n;
		this->employeeEmail = e;
		this->employeePass = p;
		this->employeeType = t;
		this->workRestaurant = r;
		this->next = nullptr;

		this->head = nullptr;
	}
};
int Employee::e_counter = 10000;

//SAME CHAINING METHOS USED WHERE ARRAY OF 11 SIZE IS ROOT OF 11 LINKED LISTS
struct EmpHashMap {
	static const int EMPLOYEE_SIZE = 11;//prime number
	Employee** array;//size=11

	//CONSTRUCTOR
	EmpHashMap() {
		array = new Employee * [EMPLOYEE_SIZE];
		for (int i = 0; i < EMPLOYEE_SIZE; ++i) {
			array[i] = nullptr;
		}
	}
	//DESTRUCTOR
	~EmpHashMap() {
		for (int i = 0; i < EMPLOYEE_SIZE; ++i) {
			Employee* current = array[i];
			while (current) {
				Employee* del = current;
				current = current->next;
				delete del;
			}
		}
		delete[] array;
	}

	//key in this case will be employeeID
	int hashFunction(int key) {
		return key % EMPLOYEE_SIZE;
	}
	//INSERTS INTO HASHMAP
	void insertIntoHashMap(const Employee& emp) {
		int index = hashFunction(emp.employeeID);

		Employee* temp = new Employee(emp);

		Employee* head = array[index];
		//inserting at end of linked list
		if (head == nullptr) {
			array[index] = temp;
		}
		else {
			Employee* hold = head;
			while (hold->next != nullptr) {
				hold = hold->next;
			}
			hold->next = temp;
		}
	}
	//SEARCHES FOR EMPLOYEE BASED ON ID
	Employee* searchEmployee(int id) {

		int index = hashFunction(id);
		Employee* curr = array[index];

		while (curr) {
			if (curr->employeeID == id) {
				return curr;
			}
			curr = curr->next;
		}

		return nullptr;
	}

	
	//REMOVES EMPLOYEE FROM HASHMAP
	void removeEmployee(int id) {
		int index = hashFunction(id);
		Employee* curr = array[index];
		Employee* prev = nullptr;

		while (curr) {
			if (curr->employeeID == id) {
				if (prev == nullptr) {
					array[index] = curr->next;
				}
				else {
					prev->next = curr->next;
				}
				delete curr;
				cout << "Employee with ID " << id << " removed successfully." << endl;
				return;
			}
			prev = curr;
			curr = curr->next;
		}

		cout << "Employee with ID " << id << " not found." << endl;
	}
	//CHECKS WHETHER SAME EMP EXISTS WITH SAME EMAIL
	bool preExistingEmail(string em) {

		for (int i = 0; i < EMPLOYEE_SIZE; i++) {
			Employee* curr = array[i];

			while (curr) {
				if (curr->employeeEmail == em) {
					return true;
				}
				curr = curr->next;
			}
		}
		return false;
	}
	//SEARCHES EMP BASED ON EMAIL AND PASS
	Employee* searchEmployeeByEmail(string em, string pass) {

		for (int i = 0; i < EMPLOYEE_SIZE; i++) {
			Employee* curr = array[i];

			while (curr) {
				if (curr->employeeEmail == em && curr->employeePass == pass) {
					return curr;
				}
				curr = curr->next;
			}
		}


		return nullptr;
	}

	
	//DISPLAY FUNC
	void displayHashMap() {
		for (int i = 0; i < EMPLOYEE_SIZE; ++i) {
			cout << "Index " << i << ": ";
			Employee* curr = array[i];
			while (curr) {
				cout << "[" << curr->employeeID << ": " << curr->employeeName << "] -> ";
				curr = curr->next;
			}
			cout << "NULL" << endl;
		}
	}

};
//---------------------------------------------------------------------------------------------------------------------
//NODE FOR HASHMAP
struct Customer {
	static int cust_counter;
	int customerID;
	string customerName;
	string customerEmail;
	string customerPass;
	Customer* next;

	Customer(string n, string em, string pass)
		:customerName(n), customerID(cust_counter++), customerEmail(em), customerPass(pass), next(nullptr) {}
};
int Customer::cust_counter = 10000;

//HASHMAP IS IMPLEMENTED BY CHAINING METHOD
//THERE IS ARRAY OF LINKED LIST HEADS
struct CustHashMap {
	static const int CUSTOMER_SIZE = 11;
	Customer** array;

	//CONSTRUCTOR
	CustHashMap() {
		array = new Customer * [CUSTOMER_SIZE];
		for (int i = 0; i < CUSTOMER_SIZE; ++i) {
			array[i] = nullptr;
		}
	}
	//DESTRUCTOR
	~CustHashMap() {
		for (int i = 0; i < CUSTOMER_SIZE; ++i) {
			Customer* current = array[i];
			while (current) {
				Customer* del = current;
				current = current->next;
				delete del;
			}
		}
		delete[] array;
	}

	//key in this case will be CUSTOMER ID
	int hashFunction(int key) {
		return key % CUSTOMER_SIZE;
	}
	//INSERTING INTO HASHMAP
	void insertIntoHashMap(const Customer& cust) {
		int index = hashFunction(cust.customerID);

		Customer* temp = new Customer(cust);

		Customer* head = array[index];
		//inserting at end of linked list
		if (head == nullptr) {
			array[index] = temp;
		}
		else {
			Customer* hold = head;
			while (hold->next != nullptr) {
				hold = hold->next;
			}
			hold->next = temp;
		}
	}
	//SEARCHES CUSTOMER BY THEIR ID
	Customer* searchCustomer(int id) {

		int index = hashFunction(id);
		Customer* curr = array[index];

		while (curr) {
			if (curr->customerID == id) {
				return curr;
			}
			curr = curr->next;
		}

		return nullptr;
	}
	//SEARCHES FOR A CUSTOMER BY THEIR EMAIL AND PASS,USEFUL FOR LOGIN
	Customer* searchCustomerByEmail(string em, string pass) {

		for (int i = 0; i < CUSTOMER_SIZE; i++) {
			Customer* curr = array[i];

			while (curr) {
				if (curr->customerEmail == em && curr->customerPass == pass) {
					return curr;
				}
				curr = curr->next;
			}
		}


		return nullptr;
	}
	//CHECKS WHETHER SAME CUSTOMER EXISTS WITH SAME EMAIL
	bool preExistingEmail(string em) {

		for (int i = 0; i < CUSTOMER_SIZE; i++) {
			Customer* curr = array[i];

			while (curr) {
				if (curr->customerEmail == em) {
					return true;
				}
				curr = curr->next;
			}
		}
		return false;
	}
	//DISPLAYS CUSTOMER HASHMAP
	void displayHashMap() {
		for (int i = 0; i < CUSTOMER_SIZE; ++i) {
			cout << "Index " << i << ": ";
			Customer* curr = array[i];
			while (curr) {
				cout << "[" << curr->customerID << ": " << curr->customerName << "] -> ";
				curr = curr->next;
			}
			cout << "NULL" << endl;
		}
	}

};
//----------------------------------------------------------------------------------------------------------
//NODE FOR PRIORITY QUEUE STRUCT
struct Order {
	static int counter;
	int orderID;
	Dish* dish;
	int totalDishes;
	double totalCost;
	string orderType;
	Customer* orderCustomer;
	Employee* orderEmployee;
	Employee* deliveryDriver;
	bool delivered;
	int location;
	Order* next;

	Order(Dish* d, int count, string type, Customer* cust, PromotionStack& promotions,int location)
		:dish(d), totalDishes(count), orderType(type), orderCustomer(cust), orderEmployee(nullptr), next(nullptr) {
		deliveryDriver = nullptr;
		orderID = counter++;
		totalCost = dish->dishPrice * totalDishes;
		this->location = location;
		delivered = false;

	}
	void display(Delivery * d) {
		cout << "\nOrder ID: " << orderID << endl;
		cout << "Dish: " << dish->dishName << endl;
		cout << "Total Dishes: " << totalDishes << endl;
		cout << "Order Type: " << orderType << endl;
		cout << "Customer: " << orderCustomer->customerName << endl;
		cout << "Total Cost: " << totalCost << endl;
		cout << "----------------------------------------" << endl;
		cout << "Delivery Details : " << endl;
		
		if (orderType == "Premium") {
			cout << "No Delivery Charages" << endl;
		}
		else if (orderType == "Express") {
			cout << "Rs 200 Express Delivery Charge" << endl;
		}
		else {
			cout << "Rs 100 Normal Delivery Charges" << endl;
		}
		string str = (deliveryDriver) ? deliveryDriver->employeeName : "Not Allocated";
		cout << "Delivery Guy Name : " << str << endl;
		cout << "Order Delivery Location : " << d->vertices[location] << endl;
		cout << "--------------------------------------" << endl;
	}

};

int Order::counter = 10000;

//PRIORITY QUEUE OF ORDERS , EACH RESTUARNT HAS ITS OBJ
struct OrderQueue {
	Order* front;

	OrderQueue() {
		front = nullptr;
	}

	bool isEmpty() {
		return front == nullptr;
	}

	//COMPARES ORDERS PRIORITY RETURNS TRUE OR FALSE
	bool compareOrders(Order* o1, Order* o2) {

		if (o1->orderType == "Premium" && o2->orderType != "Premium") {
			return true;
		}
		if (o1->orderType == "Express" && o2->orderType == "Normal") {
			return true;
		}
		if (o1->orderType == o2->orderType) {
			return o1->orderID < o2->orderID;
		}

		return false;
	}
	//SWAP FUNC
	void xchangeEmployee(Order* o1, Order* o2) {

		int temp = o1->orderID;
		o1->orderID = o2->orderID;
		o2->orderID = temp;

		string t = o1->orderType;
		o1->orderType = o2->orderType;
		o2->orderType = t;

		double t2 = o1->totalCost;
		o1->totalCost = o2->totalCost;
		o2->totalCost = t2;

		double t3 = o1->totalCost;
		o1->totalCost = o2->totalCost;
		o2->totalCost = t3;

		Customer* t4 = o1->orderCustomer;
		o1->orderCustomer = o2->orderCustomer;
		o2->orderCustomer = t4;

		Employee* t5 = o1->orderEmployee;
		o1->orderEmployee = o2->orderEmployee;
		o2->orderEmployee = t5;

	}
	//SORTING FUNC FOR PRIORITY QUEUE
	void sortQueue() {
		if (isEmpty()) return;

		bool flag;
		do {
			flag = false;
			Order* current = front;
			while (current != nullptr && current->next != nullptr) {
				if (current->orderEmployee == nullptr && current->next->orderEmployee == nullptr) {

					if (compareOrders(current->next, current)) {
						xchangeEmployee(current, current->next);
						flag = true;
					}
				}
				current = current->next;
			}

		} while (flag);
	}
	//ENQUEUES BASED ON PRIORITY , TOP PRIORITY ORDER COMES FIRST
	void enqueue(Dish* d, int count, string type, Customer* cust, PromotionStack& promotions,int del) {


		Order* ord = new Order(d, count, type, cust, promotions,del);

		if (!promotions.isEmpty()) {
			applyPromo(ord, promotions);		//first apply promotion
		}

		if (ord->orderType == "Premium") {
			ord->totalCost += 500;			//500 extra cost of premium , no delivery cost
		}
		else if (ord->orderType == "Express") {
			ord->totalCost += 200;					//delivery charge of 200
			ord->totalCost += (ord->totalCost * 0.1);	//10% express cost
		}
		else {
			ord->totalCost += 100;			//no extra cost , delivery cost of 100
		}


		if (isEmpty()) {
			front = ord;
			return;
		}

		Order* current = front;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = ord;

		sortQueue();
	}
	//DEQUES TOP PRIORITY ORDER
	Order* dequeue(Employee* processor,Delivery * d) {
		if (isEmpty()) {
			cout << "No Orders Added" << endl;
			return nullptr;
		}


		Order* curr = front;
		while (curr != nullptr) {
			if (curr->orderEmployee == nullptr) {
				curr->orderEmployee = processor;

				cout << "Order Processed/Dequeued Successfully ";
				curr->display(d);
				cout << "Processed by: " << processor->employeeName << endl;
				return curr;
			}
			curr = curr->next;
		}

		cout << "All orders are already processed." << endl;
		return nullptr;

	}
	void driverHistory(Employee* emp,Delivery * d) {
		if (isEmpty()) {
			cout << "Order Queue is empty!" << endl;
			return;
		}

		Order* current = front;
		cout << "\nOrders Delivered By : " << emp->employeeName << endl;
		while (current != nullptr) {
			if (current->deliveryDriver == emp) {
				if(current->delivered){

					current->display(d);

					cout << endl;
				}
				else {
					cout << "Not Delivered" << endl;
				}
			}
			current = current->next;
		}
	}

	//DISPLAYS ORDERS PROCESSED BY SPECIFIC EMPLOYEE
	void employeeHistory(Employee* emp,Delivery * d) {
		if (isEmpty()) {
			cout << "Order Queue is empty!" << endl;
			return;
		}

		Order* current = front;
		cout << "\nOrders Proccesed By : " << emp->employeeName << endl;
		while (current != nullptr) {
			if (current->orderEmployee == emp) {
				current->display(d);

				cout << endl;
			}
			current = current->next;
		}
	}
	//DISPLAYS ORDERS MADE BY SPECIFIC CUSTOMER
	void customerHistory(Customer* cust,Delivery* d) {
		if (isEmpty()) {
			cout << "Order Queue is empty!" << endl;
			return;
		}

		Order* current = front;
		cout << "\nOrders Of Customer : " << cust->customerName << endl;
		while (current != nullptr) {
			if (current->orderCustomer == cust) {
				current->display(d);

				if (current->orderEmployee == nullptr) {
					cout << "STATUS : UNPROCESSED YET" << endl;
				}
				else {
					cout << "STATUS : PROCESSED SUCCESSFULLY" << endl;
				}
				cout << "Location : " << d->vertices[current->location] << endl;
				if (current->delivered) {
					cout << "DELIVERY STATUS : DELIVERED SUCCESSFULLY" << endl;
				}
				else {
					cout << "DELIVERY STATUS : NOT DELIVERED YET " << endl;
				}

				cout << endl;
			}
			current = current->next;
		}
	}
	//DISPLAYS ORDER QUEUE
	void display(Delivery * d) {
		if (isEmpty()) {
			cout << "Order Queue is empty!" << endl;
			return;
		}

		Order* current = front;
		cout << "\nUnProcessed Orders Queue" << endl;
		int count = 0;
		while (current != nullptr) {
			if (current->orderEmployee == nullptr) {
				current->display(d);
				count++;
			}
			current = current->next;
		}

		if (count == 0) {
			cout << "All OrderS Are Proccessed!" << endl;
			return;
		}
	}
};


//APPLES PROMOTION TO ORDER 
void applyPromo(Order* ord, PromotionStack& promotions) {

	if (promotions.isEmpty()) {
		cout << "No promotions available yet ..." << endl;
		return;
	}
	Promotion* apply = promotions.topPromo();

	if (apply != nullptr && apply->limit > 0) {
		ord->totalCost -= (ord->totalCost * apply->discount);

		apply->limit--;
		if (apply->limit == 0) {
			promotions.popPromo();
		}
	}
}

//----------------------------------------------------------------------------------------------------------
//Linked List
struct Restaurant {
	static int r_counter;
	int restaurantID;
	string restaurantName;
	string restaurantType;
	Menu menuRoot;
	Employee* manager;
	PromotionStack stack;
	OrderQueue queueofOrders;
	int location;  //restuarant location
	string locationName;
	Restaurant* next;

	Restaurant(string name, string type,int location)
		:menuRoot(Menu(restaurantName)), restaurantID(r_counter++), restaurantName(name), restaurantType(type), manager(nullptr), next(nullptr) {
		this->location = location;
		menuRoot.menuName += " Menu";
	}

};

int Restaurant::r_counter = 10000;

//--------------------------------------------------------------------------------------------
//DISPLAYS EMPLOYEES OF A SPECIFIC RESTAURANT
void displayRestaurantEmp(EmpHashMap* e, Restaurant* r) {

	cout << "EMPLOYEES WORKING AT RESTAURANT : " << r->restaurantName << endl;
	for (int i = 0; i < e->EMPLOYEE_SIZE; ++i) {
		Employee* curr = e->array[i];

		while (curr) {
			if (curr->workRestaurant == r && curr->employeeType != "Manager") {
				cout << "ID : " << curr->employeeID << " : " << curr->employeeName << " : " << curr->employeeType;

				cout << endl;
			}
			curr = curr->next;
		}
	}
}

//DISPLAYS MANAGER OF A RESTUARANT
void displayRestaurantManager(EmpHashMap* e, Restaurant* r) {

	cout << "MANAGERS WORKING AT RESTAURANT : " << r->restaurantName << endl;
	for (int i = 0; i < e->EMPLOYEE_SIZE; ++i) {
		Employee* curr = e->array[i];

		while (curr) {
			if (curr->workRestaurant == r && curr->employeeType == "Manager") {
				cout << "ID : " << curr->employeeID << " : " << curr->employeeName << " : " << curr->employeeType;

				cout << endl;
			}
			curr = curr->next;
		}
	}
}


//--------------------------------------------------------------------------------------------
//ADMIN HAS A SPECIFIC KEY THAT NEEDS TO BE ENTERED
//HAS ACCESS TO EVERY DATA
static const string adminKey = "123456789";
struct Admin {
	Restaurant* head;
	EmpHashMap* empHash;
	CustHashMap* custHash;

	Admin(Restaurant* r, EmpHashMap* e, CustHashMap* c) :head(r), empHash(e), custHash(c) {}
};

//--------------------------------------------------------------------------------------------
//ADDING A RESTAURANT
void addRestaurant(Restaurant*& head, string name, string type,int loc) {
	Restaurant* temp = new Restaurant(name, type,loc);

	temp->next = head;
	head = temp;
}
//SEARCHING A RESTAURANT
Restaurant* searchRestaurant(Restaurant* head, int id) {

	Restaurant* temp = head;
	while (temp != nullptr) {
		if (temp->restaurantID == id) {
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

void resetRestaurantEmp(EmpHashMap* e, Restaurant* r) {

	for (int i = 0; i < e->EMPLOYEE_SIZE; ++i) {
		Employee* curr = e->array[i];

		while (curr) {
			if (curr->workRestaurant == r) {
				curr->workRestaurant = nullptr;
			}
			curr = curr->next;
		}
	}
}
//DELETING
void deleteRestaurant(Restaurant*& head, int restaurantID,EmpHashMap * e) {
	if (head == nullptr) {
		return;
	}

	Restaurant* del = searchRestaurant(head, restaurantID);



	if (head->restaurantID == restaurantID) {
		Restaurant* temp = head;
		head = head->next;


		resetRestaurantEmp(e, temp);

		delete temp;
		return;
	}

	Restaurant* current = head;
	while (current->next != nullptr && current->next->restaurantID != restaurantID) {
		current = current->next;
	}

	if (current->next != nullptr) {
		Restaurant* temp = current->next;
		current->next = current->next->next;
		
		resetRestaurantEmp(e,temp);


		delete temp;
	}
}

//EDITING
bool editRestaurant(Restaurant*& head, int restaurantID, const string& newName, const string& newType) {
	Restaurant* current = head;

	while (current != nullptr) {
		if (current->restaurantID == restaurantID) {
			current->restaurantName = newName;
			current->restaurantType = newType;
			return true;
		}
		current = current->next;
	}

	return false;
}


//DISPLAYING
void displayRestaurants(Restaurant*& head,Delivery * d) {
	if (head == nullptr) {
		cout << "The list is empty!" << endl;
		return;
	}

	Restaurant* current = head;
	while (current != nullptr) {
		cout << "Restaurant ID   : " << current->restaurantID << endl;
		cout << "Restuarant Name : " << current->restaurantName << endl;
		cout << "Restaurant Type : " << current->restaurantType << endl;
		cout << "Restaurant Location : " << d->vertices[current->location] << endl;
		cout << endl;
		current = current->next;
	}
}

void displayDrivers(EmpHashMap * e,Restaurant* r) {

	cout << "Available Drivers: " << endl;
	for (int i = 0; i < e->EMPLOYEE_SIZE; ++i) {
		Employee* curr = e->array[i];

		while (curr) {
			if (curr->employeeType == "Driver" && curr->workRestaurant == r) {
				cout << "ID : " << curr->employeeID << " : " << curr->employeeName << " : " << curr->employeeType;

				cout << endl;
			}
			curr = curr->next;
		}
	}
}
//--------------------------------------------------------------------------------------------
//REVIEW STRUCT
struct Review {
	static int rev_counter;
	int reviewID;
	int rating;
	string description;
	Restaurant* reviewRest;
	Dish* reviewDish;

	Review(int rate, string desc, Restaurant* r)
		: reviewID(rev_counter++), rating(rate), description(desc), reviewRest(r), reviewDish(nullptr) {}

	Review(int rate, string desc, Dish* d)
		: reviewID(rev_counter++), rating(rate), description(desc), reviewRest(nullptr), reviewDish(d) {}

	Review() : reviewID(0), rating(0), description(""), reviewRest(nullptr), reviewDish(nullptr) {} // Default constructor
};

int Review::rev_counter = 10000;

//THIS STRUCT HAS 4 HEAPS , GOOD/BAD RESTAURANT REVIEWS,GOOD/BAD DISHES REVIEWS
struct ReviewHeap {
	static const int HEAP_SIZE = 20;

	// Separate heaps for restaurants and dishes
	Review* goodHotels;  // MAX HEAP
	Review* badHotels;   // MIN HEAP
	Review* goodDishes;  // MAX HEAP
	Review* badDishes;  // MIN HEAP

	int good_R;      // COUNTERS
	int bad_R;
	int good_D;
	int bad_D;

	ReviewHeap() {
		goodHotels = new Review[HEAP_SIZE]();
		badHotels = new Review[HEAP_SIZE]();
		goodDishes = new Review[HEAP_SIZE]();
		badDishes = new Review[HEAP_SIZE]();
		good_R = 0;
		bad_R = 0;
		good_D = 0;
		bad_D = 0;
	}

	~ReviewHeap() {
		delete[] goodHotels;
		delete[] badHotels;
		delete[] goodDishes;
		delete[] badDishes;
	}

	void swap(Review& a, Review& b) {
		Review temp = b;
		b = a;
		a = temp;
	}

	void heapifyMax(Review* heap, int size, int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < size && heap[l].rating > heap[largest].rating) largest = l;
		if (r < size && heap[r].rating > heap[largest].rating) largest = r;

		if (largest != i) {
			swap(heap[i], heap[largest]);
			heapifyMax(heap, size, largest);
		}
	}

	void heapifyMin(Review* heap, int size, int i) {
		int smallest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < size && heap[l].rating < heap[smallest].rating) smallest = l;
		if (r < size && heap[r].rating < heap[smallest].rating) smallest = r;

		if (smallest != i) {
			swap(heap[i], heap[smallest]);
			heapifyMin(heap, size, smallest);
		}
	}

	void insertGoodRestaurants(Review review) {
		if (good_R >= HEAP_SIZE) {
			cout << "Good restaurant reviews heap is full!\n";
			return;
		}
		goodHotels[good_R++] = review;
		for (int i = good_R / 2 - 1; i >= 0; i--) {
			heapifyMax(goodHotels, good_R, i);
		}
	}

	void insertBadRestaurants(Review review) {
		if (bad_R >= HEAP_SIZE) {
			cout << "Bad restaurant reviews heap is full!\n";
			return;
		}
		badHotels[bad_R++] = review;
		for (int i = bad_R / 2 - 1; i >= 0; i--) {
			heapifyMin(badHotels, bad_R, i);
		}
	}

	void insertGoodDish(Review review) {
		if (good_D >= HEAP_SIZE) {
			cout << "Good dish reviews heap is full!\n";
			return;
		}
		goodDishes[good_D++] = review;
		for (int i = good_D / 2 - 1; i >= 0; i--) {
			heapifyMax(goodDishes, good_D, i);
		}
	}

	void insertBadDish(Review review) {
		if (bad_D >= HEAP_SIZE) {
			cout << "Bad dish reviews heap is full!\n";
			return;
		}
		badDishes[bad_D++] = review;
		for (int i = bad_D / 2 - 1; i >= 0; i--) {
			heapifyMin(badDishes, bad_D, i);
		}
	}
	void deleteGoodRestaurants(int reviewID) {
		for (int i = 0; i < good_R; i++) {
			if (goodHotels[i].reviewID == reviewID) {
				swap(goodHotels[i], goodHotels[good_R - 1]);
				good_R--;
				for (int j = good_R / 2 - 1; j >= 0; j--) {
					heapifyMax(goodHotels, good_R, j);
				}
				return;
			}
		}
		cout << "Review not found For good Restaurants ratings.\n";
	}
	void deleteBadRestaurants(int reviewID) {
		for (int i = 0; i < bad_R; i++) {
			if (badHotels[i].reviewID == reviewID) {
				swap(badHotels[i], badHotels[bad_R - 1]);
				bad_R--;
				for (int j = bad_R / 2 - 1; j >= 0; j--) {
					heapifyMax(badHotels, bad_R, j);
				}
				return;
			}
		}
		cout << "Review not found For bad Restaurants ratings.\n";
	}
	void deleteGoodDishes(int reviewID) {
		for (int i = 0; i < good_D; i++) {
			if (goodDishes[i].reviewID == reviewID) {
				swap(goodDishes[i], goodDishes[good_D - 1]);
				good_D--;
				for (int j = good_D / 2 - 1; j >= 0; j--) {
					heapifyMax(goodDishes, good_D, j);
				}
				return;
			}
		}
		cout << "Review not found For good Dishes ratings.\n";
	}

	void deleteBadDishes(int reviewID) {
		for (int i = 0; i < bad_D; i++) {
			if (badDishes[i].reviewID == reviewID) {
				swap(badDishes[i], badDishes[bad_D - 1]);
				bad_D--;
				for (int j = bad_D / 2 - 1; j >= 0; j--) {
					heapifyMin(badDishes, bad_D, j);
				}
				return;
			}
		}
		cout << "Review not found in bad Dishes ratings.\n";
	}
	void printGoodRestaurants() {
		cout << "Good Restaurant Reviews:" << endl;
		for (int i = 0; i < good_R; i++) {
			cout << "Review ID: " << goodHotels[i].reviewID << endl;
			cout << "Dish Name : " << goodHotels[i].reviewRest->restaurantName << endl;
			cout << "Rating: " << goodHotels[i].rating << endl;
			cout << "Description: " << goodHotels[i].description << endl << endl;
		}
	}

	void printBadRestaurants() {
		cout << "Bad Restaurant Reviews:" << endl;
		for (int i = 0; i < bad_R; i++) {
			cout << "Review ID: " << badHotels[i].reviewID << endl;
			cout << "Dish Name : " << badHotels[i].reviewRest->restaurantName << endl;
			cout << "Rating: " << badHotels[i].rating << endl;
			cout << "Description: " << badHotels[i].description << endl << endl;
		}
	}

	void printGoodDishes() {
		cout << "Good Dish Reviews:" << endl;
		for (int i = 0; i < good_D; i++) {
			cout << "Review ID: " << goodDishes[i].reviewID << endl;
			cout << "Dish Name : " << goodDishes[i].reviewDish->dishName << endl;
			cout << "Rating: " << goodDishes[i].rating << endl;
			cout << "Description: " << goodDishes[i].description << endl << endl;
		}
	}

	void printBadDishes() {
		cout << "Bad Dish Reviews:" << endl;
		for (int i = 0; i < bad_D; i++) {
			cout << "Review ID: " << badDishes[i].reviewID << endl;
			cout << "Dish Name : " << badDishes[i].reviewDish->dishName << endl;
			cout << "Rating: " << badDishes[i].rating << endl;
			cout << "Description: " << badDishes[i].description << endl << endl;
		}
	}
};

//--------------------------------------------------------------------------------------------
//THESE FUNCTIONS CHECK FOR EMAIL VALIDITY SO THAT EMAILS ARE OF THE XXXX@GMAIL.COM FORMAT
//THESE FUNCTIONS ALSO CHECK WHETHER EMAIL IS UNIQUE BY SEARCHING IN HASHMAP
bool isValidEmp(string email, EmpHashMap* empHash) {

	string check1 = "@email.com";
	string check2 = "@gmail.com";

	if (email.length() > check1.length()) {
		bool flag1 = true;
		bool flag2 = true;

		int j = check1.length() - 1;

		for (int i = email.length() - 1; i >= email.length() - check1.length(); i--, j--) {
			if (email[i] != check1[j]) {
				flag1 = false;
			}
			if (email[i] != check2[j]) {
				flag2 = false;
			}
		}

		if (!flag1 && !flag2) {
			cout << "Email format is not of form XXXXX@gmail.com or XXXXX@email.com" << endl;
			return false;
		}
	}
	else {
		cout << "Email format is not of form XXXXX@gmail.com or XXXXX@email.com" << endl;
		return false;
	}

	if (empHash->preExistingEmail(email)) {
		cout << "Another Employee With Same Email Already Exists";
		return false;
	}

	return true;
}
bool isValidCust(string email, CustHashMap* custHash) {
	string check1 = "@email.com";
	string check2 = "@gmail.com";

	if (email.length() > check1.length()) {
		bool flag1 = true;
		bool flag2 = true;

		int j = check1.length() - 1;

		for (int i = email.length() - 1; i >= email.length() - check1.length(); i--, j--) {
			if (email[i] != check1[j]) {
				flag1 = false;
			}
			if (email[i] != check2[j]) {
				flag2 = false;
			}
		}

		if (!flag1 && !flag2) {
			cout << "Email format is not of form XXXXX@gmail.com or XXXXX@email.com" << endl;
			return false;
		}
	}
	else {
		cout << "Email format is not of form XXXXX@gmail.com or XXXXX@email.com" << endl;
		return false;
	}

	if (custHash->preExistingEmail(email)) {
		cout << "Another Customer With Same Email Already Exists";
		return false;
	}

	return true;
}
//--------------------------------------------------------------------------------------------
//THIS FUNCTION CHECKS FOR PASSWORD VALIDITY:
//MUST BE 8-12 CHARACTTERS
//MUST HAVE A CAPITAL,SMALL,DIGIT,AND SPECIAL CHARACTER
bool isValidPassword(string password) {

	if (password.length() < 8 || password.length() > 12) {
		cout << "Password Length must be in range of [8 - 12] characters" << endl;
		return false;
	}

	bool capital = false;
	bool small = false;
	bool digit = false;
	bool special = false;

	for (int i = 0; i < password.length(); i++) {
		char ch = password[i];

		if (ch >= 'A' && ch <= 'Z') {
			capital = true;
		}
		else if (ch >= 'a' && ch <= 'z') {
			small = true;
		}
		else if (ch >= '0' && ch <= '9') {
			digit = true;
		}
		else if ((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)) {
			special = true;
		}
	}

	if (!capital) {
		cout << "Passwords must contain a Capital/UpperCase Character!!" << endl;
	}
	if (!small) {
		cout << "Passwords must contain a LowerCase Character!!" << endl;
	}
	if (!digit) {
		cout << "Passwords must contain a Digit!!" << endl;
	}
	if (!special) {
		cout << "Passwords must contain a Special Character!!" << endl;
	}

	return capital && small && digit && special;
}

//THIS FUNCTION IS FOR GETTING PASSWORD AS HIDDEN *****
string getMaskedInput() {
	string password;
	char ch;

	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (password != "") {

				cout << "\b \b";

				password.pop_back();
			}
		}
		else if (ch >= 32 && ch <= 126) {
			password += ch;
			cout << '*';
		}

	}
	cout << endl;
	return password;
}


//--------------------------------------------------------------------------------------------
//THESE FUNCTIONS CHECK LOGIN FUNCTIONALITY



bool adminLogin(string key) {
	return key == adminKey;
}



Employee* managerLogin(EmpHashMap* h, string email, string pass) {
	Employee* temp = h->searchEmployeeByEmail(email, pass);
	if (temp != nullptr) {

		if (temp->employeeType == "Manager") {
			return temp;
		}
	}
	return nullptr;
}

Customer* customerLogin(CustHashMap* h, string em, string pass) {
	Customer* temp = h->searchCustomerByEmail(em, pass);

	if (temp != nullptr) {
		return temp;
	}
	return nullptr;

}

Employee* employeeLogin(EmpHashMap* h, string email, string pass) {
	Employee* temp = h->searchEmployeeByEmail(email, pass);
	if (temp != nullptr) {

		if (temp->employeeType != "Manager") {
			return temp;
		}
	}
	return nullptr;

}

//HELPER FUNC TO COUNT NUMBER OF ORDERS IN DELIVERY LIST
int countNodes(DeliveryList * d) {
	DeliveryList* curr = d;
	int count = 0;

	while (curr) {
		count++;
		curr = curr->next;
	}

	return count;
}

//BUBBLE SORT OF LINKED LIST BASED ON WEIGHT
void sortList(Delivery* d, Employee* driver) {
	int n = countNodes(driver->head);  //HELPER FUNC TO FIND NUMBER OF NODES, POOR PRACTICE BUT GETS IT DONE

	// Bubble sort for linked list
	for (int i = 0; i < n - 1; i++) {
		DeliveryList* current = driver->head;
		DeliveryList* prev = nullptr;
		DeliveryList* nextNode = nullptr;

		for (int j = 0; j < n - i - 1; j++) {

			//RESTAURANT <-WEIGHT-> THE CURRENT ORDER
			int weight1 = d->adjMatrix[driver->workRestaurant->location][current->ord->location];
			//RESTAURANT <-WEIGHT-> THE NEXT ORDER
			int weight2 = d->adjMatrix[driver->workRestaurant->location][current->next->ord->location];

			//IF FIRST WEIGHT IS GREATER THAN NEXT ONE, THEN I SWAP
			//NOTE TO BE NOTED THAT IF WEIGHT IS ZERO IT MEANS NO CONNECTION IN ADJ MATRIX
			//IT MEANS THAT IS VERY LARGE
			//ELSE NO SWAP
			if (weight1 > weight2 && weight2 != 0) {
				nextNode = current->next;

				if (prev == nullptr) {
					driver->head = nextNode; 
				}
				else {
					prev->next = nextNode; 
				}

				current->next = nextNode->next; 
				nextNode->next = current; 

				prev = nextNode;  
			}
			else {
				prev = current;
				current = current->next;
			}
		}
	}
}

//SO IN THIS FUNC WHAT I BASICALLY DO IS THAT THE ORDER THAT DELIVERY GUY HAS TO TAKE IS STORED IN A LINKED LIST
//ADDED AT FRONT OF LINKED LIST
//ONCE ADDED I SORT THE LINKED LIST BASED ON THE SMALLEST WEIGHT FROM RESTAURANT TO THE ORDERS IN LIST
//SO THAT ORDER THAT IS THE CLOSEST WILL BE DELIVERED FIRST
void addOrderToDelivery(Employee* driver, Order* order, Delivery* d) {
	
	DeliveryList* newNode = new DeliveryList(order);

	newNode->next = driver->head;
	driver->head = newNode;

	sortList(d,driver);
}

//REMOVES ORDER FROM FRONT ONCE DELIVERED
void removeAtFront(Employee* driver) {
	DeliveryList* temp = driver->head;
	driver->head = driver->head->next;

}

//I USED DIJKSTRA ALGORITHM TO FIND SHORTEST PATH TO ORDER
// FIRST SINCE THE DELIVERY LIST IS SORTED, I GOT FROM RESTAURANT LOCATION TO FIRST ORDER IN LIST
//THEN FROM THAT ORDER TO SHORTEST PATH TO NEXT ORDER,
//THIS CONTINUES UNTIL ALL ORDERS ARE DELIVERED
//THEN DELIVERY GUY RETURNS BACK
void shortestPath(Delivery* d, Employee* driver) {
	int start = driver->workRestaurant->location;//START IS RESTAURANT LOCATION
	int numLocations = d->numVertices;	// TOTAL VERTICES

	//DISTANCE ARRAY STORES SHORTEST DISTANCE TO EACH LOCATION
	int* dist = new int[numLocations];  

	// USING THIS FOR PATH, WE CAN SAY BACK TRACKING
	int* prev = new int[numLocations];  

	//ARRAY FOR VISITED NODES
	bool* visited = new bool[numLocations];

	for (int i = 0; i < numLocations; ++i) {
		dist[i] = INT_MAX;	//INFINITY
		prev[i] = -1;		
		visited[i] = false;
	}


	//STARTING FROM FIRST ORDER IN DELIVERY LIST
	DeliveryList* curr = driver->head;
	int totalDistance = 0;

	while (curr != nullptr) {

		cout << "\nStarting location: " << d->vertices[start] << endl;
		int target = curr->ord->location;

		dist[start] = 0;

		while (true) {
			int minDist = INT_MAX;
			int u = -1;		//minimum distance Index

			// FINDING MINIMUM WEIGHT NODE FROM THE CURR NODE
			//MAKING SURE THE NODE IS NOT VISITED AND IF WE DO FIND SMALLER DISTANCE WE UPDATE MINIMUM DISTANCE
			for (int i = 0; i < numLocations; ++i) {
				if (visited[i] == false && dist[i] < minDist) {
					minDist = dist[i];
					u = i;
				}
			}

			//IF NO MINIMUM DISTANCE NODE FOUND
			if (u == -1) { 
				break;
			}

			visited[u] = true; 

			// UPDATING DISTANCE (RELAXATION)
			for (int v = 0; v < numLocations; ++v) {
				if (visited[v] == false && d->adjMatrix[u][v] != 0 && dist[u] != INT_MAX
					&& dist[u] + d->adjMatrix[u][v] < dist[v]) {
					//RELAXATION
					dist[v] = dist[u] + d->adjMatrix[u][v];
					prev[v] = u;//I AM USING THIS FOR PATH
				}
			}
		}

		// IF TARGET LOCATION IS REACHABLE , THEN THE ORDER IS DELIVERED SUCCESSFULLY
		// AND TOTAL DISTANCE IS UPDATED
		if (dist[target] != INT_MAX) {
			totalDistance += dist[target];

			cout << "Delivery to Order " << curr->ord->orderID << " (Location: " << d->vertices[target] << "):" << endl;
			
			curr->ord->delivered = true;//ORDER SUCCESSFULLY DELIVERED

			
			int* path = new int[numLocations];
			int pathIndex = 0;

			for (int i = target; i != -1; i = prev[i]) {
				path[pathIndex] = i;
				pathIndex++;
			}

			//PRINTING PATHS
			cout << "Path: ";
			for (int i = pathIndex - 1; i >= 0; --i) {
				cout << d->vertices[path[i]] << " "; 
			}
			cout << endl;
			//DISTANCE TAKEN TO THAT PATH
			cout << "Distance: " << dist[target] << endl;

			delete[] path;

			//NEXT DELIVERY WILL START FROM THIS LOCATION RATHER THAN AGAIN FROM RESTAURANT
			start = target; 

			//ORDER DELIVERED SO REMOVE IT FROM LIST
			removeAtFront(driver); 
		}
		else {
			//ORDER IS UNREACHABLE
			cout << "Order " << curr->ord->orderID << " (Location: " << d->vertices[target] << ") is unreachable!" << endl;
			
			// REMOVE ORDER FROM LIST
			removeAtFront(driver);
		}

		//DELIVER NEXT RESTAUARANT
		curr = driver->head;

		//RESET EVERYTHING
		for (int i = 0; i < numLocations; ++i) {
			visited[i] = false;
			prev[i] = -1;
			dist[i] = INT_MAX;
		}
	}

	//ITERATING ONE MORE TIME FROM LAST ORDER BACK TO RESTAURANT
	cout << "\nRETURNING BACK TO RESTUARANT : " << endl;
	int target = driver->workRestaurant->location;

	dist[start] = 0; 
	while (true) {
		int minDist = INT_MAX;
		int u = -1;

		for (int i = 0; i < numLocations; ++i) {
			if (!visited[i] && dist[i] < minDist) {
				minDist = dist[i];
				u = i;
			}
		}

		if (u == -1) break; 
		visited[u] = true;

		for (int v = 0; v < numLocations; ++v) {
			if (d->adjMatrix[u][v] != 0 && dist[u] + d->adjMatrix[u][v] < dist[v]) {
				dist[v] = dist[u] + d->adjMatrix[u][v];
				prev[v] = u;
			}
		}
	}

	if (dist[target] != INT_MAX) {
		totalDistance += dist[target];
		cout << "Returned Back Successfully To (Location: " << d->vertices[target] << "):" << endl;
		

		int* path = new int[numLocations];
		int pathIndex = 0;
		for (int v = target; v != -1; v = prev[v]) {
			path[pathIndex] = v;
			pathIndex++;
		}

		cout << "Path: ";
		for (int i = pathIndex - 1; i >= 0; --i) {
			cout << d->vertices[path[i]] << " ";  
		}
		cout << "\nDistance: " << dist[target] << endl;

		delete[] path;


	}
	else {
		cout << "Returning Back To Restaurant is IMPOSSIBLE ! " << endl;
	}

	cout << "\nTotal Distance Travelled By Driver : " << totalDistance << endl;
	delete[] dist;
	delete[] prev;
	delete[] visited;
}

void displayDeliveryOrders(DeliveryList * head,Delivery* g) {
	if (!head) {
		cout << "No orders to deliver" << endl;
		return;
	}

	DeliveryList* temp = head;

	while (temp) {

		temp->ord->display(g);

		cout << endl;
		temp = temp->next;
	}
}

//Delivery MODULE 
void deliveryModule(Employee* emp, EmpHashMap* h,Delivery *d) {
	cout << "Driver login Successful." << endl;
	cout << "===============WELCOME==================" << endl;
	cout << "Driver Name  : " << emp->employeeName << endl;
	cout << "Driver Email : " << emp->employeeEmail << endl;
	cout << "Driver Type  : Normal Employee" << endl;
	cout << "Driver Work Restaurant : ";
	if (emp->workRestaurant) {
		cout << emp->workRestaurant->restaurantName << endl;
		cout << "========================================\n" << endl;
	}
	else {
		cout << "None"<<endl;

		cout << "\n\n*NOTE : SINCE YOU DONT HAVE A VALID WORK RESTAURANT RIGHT NOW YOU CANNOT ACCESS DRIVER FUNCTIONALITY" << endl;
		cout << "\nCONTACT MANAGER OR ADMIN TO APPLY FOR A RESTUARANT" << endl;
		cout << "========================================\n" << endl;
		return;
	}

	int choice;
	do {
		cout << "\n---------- Delivery Module ----------" << endl;
		cout << "1. Deliver Orders" << endl;
		cout << "2. Display Orders To Deliver" << endl;
		cout << "3. View Delivered Orders" << endl;
		cout << "4. Back to Main Menu" << endl;
		cout << "----------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			if (emp->head) {
				shortestPath(d, emp);
			}
			else {
				cout << "No Orders To Deliver" << endl;
			}
			break;
		}
		case 2: {
			displayDeliveryOrders(emp->head,d);
			break;
		}
		case 3: {
			emp->workRestaurant->queueofOrders.driverHistory(emp, d);
			break;
		}
		case 4: {

			cout << "Returning to main menu..." << endl;
			break;
		}
		default: {
			cout << "Invalid choice! Please try again." << endl;
			break;
		}
		}
	} while (choice != 4);
}
//--------------------------------------------------------------------------------------------
//THIS IS ADMIN MODULE , HE HAS ACCESS TO EVERYTHING AND CAN DO THINGS OTHERS MODULES CANT
void adminModule(Admin& administrator,Delivery * d) {
	int choice;
	do {
		cout << "\n---------- Admin Module ----------" << endl;
		cout << "1. Manage Restaurants" << endl;
		cout << "2. Manage Managers/Employees" << endl;
		cout << "3. Manage Customers" << endl;
		cout << "4. Display Delivery Locations" << endl;
		cout << "5. Back to Main Menu" << endl;
		cout << "----------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			bool l1 = true;
			while (l1) {
				int c = 0;
				do {
					cout << "\n1 : To Add New Restaurants" << endl;
					cout << "2 : To Remove Restaurants" << endl;
					cout << "3 : To Edit Restaurants" << endl;
					cout << "4 : To Display Restaurants" << endl;
					cout << "5 : To Go Back" << endl;
					cin >> c;
				} while (c < 1 || c> 5);

				switch (c) {
				case 1: {//ADD RESTAURANT
					string name, type;
					int location;
					cout << "Enter name of restaurant to add : ";
					cin.ignore();
					getline(cin, name);

					cout << "Enter the type of Restaurant to add : ";
					getline(cin, type);

					cout << "Enter the location of Restaurant to add : ";
					cin >> location;

					addRestaurant(administrator.head, name, type,location);
					break;
				}

				case 2: {//REMOVE RESTUARANT
					displayRestaurants(administrator.head,d);

					int restid;
					do {
						cout << "\nEnter restuarant ID to Remove : " << endl;
						cin >> restid;
					} while (restid < 10000 || restid > 99999);

					deleteRestaurant(administrator.head, restid,administrator.empHash);
					break;
				}

				case 3: {//EDIT RESTAURANTS
					displayRestaurants(administrator.head,d);

					int restid;
					do {
						cout << "\nEnter restuarant ID to EDIT : " << endl;
						cin >> restid;
					} while (restid < 10000 || restid > 99999);


					string name, type;
					cout << "Enter name of restaurant to EDIT : ";
					cin.ignore();
					getline(cin, name);

					cout << "Enter the type of Restaurant to EDIT : ";
					getline(cin, type);

					if (editRestaurant(administrator.head, restid, name, type)) {
						cout << "updated successfully" << endl;
					}
					else {
						cout << "Couldnt edit" << endl;
					}
					break;
				}

				case 4: {//DISPLAY RESTUARANTS

					displayRestaurants(administrator.head,d);
					break;
				}
				case 5: {
					l1 = false;
					break;
				}
				}
			}
			break;
		}
		case 2: {
			bool flag = true;
			while (flag) {
				int c = 0;
				do {//ADMIN CAN ADD OR REMOVE MANAGERS,SOMETHING NO OTHER MODULE CAN DO
					cout << "\n1 : To Add New Managers" << endl;
					cout << "2 : To Remove Managers" << endl;
					cout << "3 : To Edit Employees Data" << endl;
					cout << "4 : To Display All Employees" << endl;
					cout << "5 : To Go Back" << endl;
					cin >> c;
				} while (c < 1 || c> 5);

				switch (c) {
				case 1: {
					string n, em, pass, res, reconfirm;

					cout << "Enter manager name : ";
					cin.ignore();
					getline(cin, n);

					do {
						cout << "\nEnter manager email : ";
						cin >> em;
					} while (!isValidEmp(em, administrator.empHash));

					do {
						cout << "\nEnter manager password: ";
						pass = getMaskedInput();

						cout << endl;
					} while (!isValidPassword(pass));

					while (true) {

						cout << "Reconfirm password: ";
						reconfirm = getMaskedInput();

						if (pass == reconfirm) {
							cout << "Password set successfully" << endl;
							break;
						}
					}

					displayRestaurants(administrator.head,d);

					int restid;
					Restaurant* temp;
					while (true) {
						do {
							cout << "\nEnter restuarant ID for the manager: " << endl;
							cin >> restid;
						} while (restid < 10000 || restid > 99999);

						temp = searchRestaurant(administrator.head, restid);

						if (temp) {
							break;
						}
					}

					if (temp->manager) {
						cout << "Manager of this restuarant already exists , PLEASE APPLY FOR OTHER RESTAURANTS" << endl;
					}
					else {

						Employee manage = Employee(n, em, "Manager", pass, temp);
						administrator.empHash->insertIntoHashMap(manage);
					}
					break;
				}

				case 2: {
					Restaurant* temp;
					int restid;
					while (true) {
						do {
							cout << "\nEnter restuarant ID of the manager: " << endl;
							cin >> restid;
						} while (restid < 10000 || restid > 99999);

						temp = searchRestaurant(administrator.head, restid);

						if (temp) {
							break;
						}
					}
					int d = 0;
					displayRestaurantManager(administrator.empHash, temp);
					do {
						cout << "\nEnter Manager ID to Remove : ";
						cin >> d;
					} while (d < 10000 || d > 99999);

					administrator.empHash->removeEmployee(d);
					break;
				}

				case 3: {

					administrator.empHash->displayHashMap();
					int empID;
					do {
						cout << "Enter Employee ID to edit : ";
						cin >> empID;
					} while (empID < 10000 || empID > 99999);

					Employee* ptr = administrator.empHash->searchEmployee(empID);

					string n, em, pass, res, reconfirm;

					cout << "Edit Employee name : ";
					cin.ignore();
					getline(cin, n);

					do {
						cout << "\nEnter Employee email : ";
						cin >> em;
					} while (!isValidEmp(em, administrator.empHash));

					do {
						cout << "\nEdit Employee password: ";
						pass = getMaskedInput();

						cout << endl;
					} while (!isValidPassword(pass));

					while (true) {

						cout << "Reconfirm new password: ";
						reconfirm = getMaskedInput();

						if (pass == reconfirm) {
							cout << "Password set successfully" << endl;
							break;
						}
					}

					ptr->employeeName = n;
					ptr->employeeEmail = em;
					ptr->employeePass = pass;
					break;
				}

				case 4: {

					administrator.empHash->displayHashMap();
					break;
				}
				case 5: {
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 3: {
			bool flag = true;
			while (flag) {
				int c = 0;
				do {//ADMIN HAS ACCESS TO CUSTOMER
					cout << "\n1 : To Edit Customer Data" << endl;
					cout << "2 : To Display All Customer Data" << endl;
					cout << "3 : To Go Back" << endl;
					cin >> c;
				} while (c < 1 || c> 3);

				switch (c) {
				case 1: {

					administrator.custHash->displayHashMap();
					int cID;
					do {
						cout << "Enter Customer ID to edit : ";
						cin >> cID;
					} while (cID < 10000 || cID > 99999);

					Customer* ptr = administrator.custHash->searchCustomer(cID);

					string n, em, pass, res, reconfirm;

					cout << "Edit Customer name : ";
					cin.ignore();
					getline(cin, n);

					do {
						cout << "\nEnter Customer email : ";
						cin >> em;
					} while (!isValidCust(em, administrator.custHash));

					do {
						cout << "\nEdit Customer password: ";
						pass = getMaskedInput();

						cout << endl;
					} while (!isValidPassword(pass));

					while (true) {

						cout << "Reconfirm new password: ";
						reconfirm = getMaskedInput();

						if (pass == reconfirm) {
							cout << "Password set successfully" << endl;
							break;
						}
					}

					ptr->customerName = n;
					ptr->customerEmail = em;
					ptr->customerPass = pass;
					break;
				}

				case 2: {

					administrator.custHash->displayHashMap();
					break;
				}
				case 3: {
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 4: {

			d->displayAdjMatrix();
			d->displayLocations();

			break;
		}
		case 5: {
			break;
		}
		default: {
			cout << "Invalid choice! Please try again." << endl;
		}
		}
	} while (choice != 5);
}

//THIS IS MANAGER MODULE , FUNCTIONALITY RELATED TO MANAGERS IN GENERAL
void managerModule(Employee* temp, EmpHashMap* empHash, Restaurant* r) {
	cout << "Manager login Successful." << endl;
	cout << "===============WELCOME==================" << endl;
	cout << "Manager Name  : " << temp->employeeName << endl;
	cout << "Manager Email : " << temp->employeeEmail << endl;
	cout << "Manager Type  : Manager" << endl;
	cout << "Manager Work Restaurant : ";
	if (temp->workRestaurant) {
		cout << temp->workRestaurant->restaurantName << endl;
		cout << "========================================\n" << endl;
	}
	else {
		cout << "None" << endl;

		cout << "\n\n*NOTE : SINCE YOU DONT HAVE A VALID WORK RESTAURANT RIGHT NOW YOU CANNOT ACCESS MANAGER FUNCTIONALITY" << endl;
		cout << "\nCONTACT ADMIN TO APPLY FOR A RESTUARANT" << endl;
		cout << "========================================\n" << endl;
		return;
	}

	int choice;
	do {
		cout << "\n---------- Manager Module ----------" << endl;
		cout << "1. Manage Employee" << endl;
		cout << "2. Manage Menus and Dishes" << endl;
		cout << "3. Manage Promotions" << endl;
		cout << "4. Back to Main Menu" << endl;
		cout << "-----------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			bool flag = true;
			while (flag) {
				int c = 0;		//MANANGER HAVE ACCESS TO EMPLOYEE DATA
				do {
					cout << "\n1 : To Hire New Employees" << endl;
					cout << "2 : To Fire Employee" << endl;
					cout << "3 : To Display All Employees In the Restaurant" << endl;
					cout << "4 : To Go Back" << endl;
					cin >> c;
				} while (c < 1 || c> 4);

				switch (c) {
				case 1: {	//HIRING AN EMPLOYEE
					string n, em, pass, res, reconfirm;

					cout << "Enter Employee name to hire: ";
					cin.ignore();
					getline(cin, n);

					do {
						cout << "\nEnter Employee email : ";
						cin >> em;
					} while (!isValidEmp(em, empHash));

					do {
						cout << "\nEnter password: ";
						pass = getMaskedInput();

						cout << endl;
					} while (!isValidPassword(pass));

					while (true) {

						cout << "Reconfirm  password: ";
						reconfirm = getMaskedInput();

						if (pass == reconfirm) {
							cout << "Password set successfully" << endl;
							break;
						}
					}
					int xs;
					do {
						cout << "1: FOR NORMAL EMPLOYEE" << endl;
						cout << "2: FOR DRIVER EMPLOYEE" << endl;
						cin >> xs;
					} while (xs < 1 || xs>2);

					string str = (xs == 1) ? "Normal" : "Driver";

					Employee employee1(n, em, str, pass, r);
					empHash->insertIntoHashMap(employee1);
					break;
				}
				case 2: {//FIRING AN EMPLOYEE
					int d = 0;
					displayRestaurantEmp(empHash, r);
					do {
						cout << "\nEnter Employee ID to Fire : ";
						cin >> d;
					} while (d < 10000 || d > 99999);

					empHash->removeEmployee(d);

					break;
				}
				case 3: {//DISPLAYING ALL EMPLOYEES

					displayRestaurantEmp(empHash, r);
					break;
				}
				case 4: {
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 2: {
			bool flag = true;
			while (flag) {
				int c = 0;
				do {
					cout << "\n1 : To Add New Dish To Menu" << endl;
					cout << "2 : To Remove Dish From Menu" << endl;
					cout << "3 : To Edit Dish In Menu" << endl;
					cout << "4 : To Display Menu" << endl;
					cout << "5 : To Go Back" << endl;
					cin >> c;
				} while (c < 1 || c> 5);


				switch (c) {
				case 1: {
					string name, type;
					double price;

					cout << "Enter Dish name To Add To Menu : ";
					cin.ignore();
					getline(cin, name);

					cout << "Enter Type Of Dish : ";
					getline(cin, type);

					do {
						cout << "Enter price of dish : ";
						cin >> price;
					} while (price < 0.0);

					r->menuRoot.addDish(name, type, price);
					break;
				}
				case 2: {
					int ID;

					r->menuRoot.displayLevelOrder();

					do {
						cout << "Enter DISH ID to Remove From Menu : ";
						cin >> ID;
					} while (ID < 10000 || ID > 99999);

					r->menuRoot.deleteNode(r->menuRoot.dishRoot, ID);
					break;
				}
				case 3: {
					int ID;

					r->menuRoot.displayLevelOrder();

					do {
						cout << "Enter DISH ID to Edit From Menu : ";
						cin >> ID;
					} while (ID < 10000 || ID > 99999);

					Dish* ptr = r->menuRoot.findDish(r->menuRoot.dishRoot, ID);

					string name, type;
					double price;

					cout << "Edit Dish name : ";
					cin.ignore();
					getline(cin, name);

					cout << "Edit Type Of Dish : ";
					getline(cin, type);

					do {
						cout << "Edit price of dish : ";
						cin >> price;
					} while (price < 0.0);

					ptr->dishName = name;
					ptr->dishPrice = price;
					ptr->dishType = type;

					break;
				}
				case 4: {

					r->menuRoot.displayLevelOrder();
					break;
				}
				case 5: {
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 3: {
			bool flag = true;
			while (flag) {
				int c = 0;
				do {
					cout << "\n1 : To Add New Promotions" << endl;
					cout << "2 : To Remove Latest Promotion" << endl;
					cout << "3 : To Edit Latest Promotion" << endl;
					cout << "4 : To Display Promotions" << endl;
					cout << "5 : To Go Back" << endl;
					cin >> c;
				} while (c < 1 || c> 5);

				switch (c) {
				case 1: {

					string name;
					double disc;
					int limit;

					cout << "Enter Promotion Name : ";
					cin.ignore();
					getline(cin, name);

					do {
						cout << "Enter discount in % : ";
						cin >> disc;
					} while (disc <= 0 || disc > 100);

					disc /= 100.0;

					do {
						cout << "Enter Promotion Usage Limit" << endl;
						cin >> limit;
					} while (limit <= 0);

					r->stack.pushPromo(name, disc, limit);
					break;
				}
				case 2: {

					Promotion* ptr = r->stack.popPromo();

					if (ptr) {
						cout << "Latest Promotion Popped Or Removed " << endl;
						cout << "ID : " << ptr->promoID << " " << ptr->promoName << endl;

						delete ptr;
					}
					break;
				}
				case 3: {

					Promotion* ptr = r->stack.topPromo();

					string name;
					double disc;
					int limit;

					cout << "Edit Promotion Name : ";
					cin.ignore();
					getline(cin, name);

					do {
						cout << "Edit discount in % : ";
						cin >> disc;
					} while (disc <= 0 || disc > 100);

					disc /= 100.0;

					do {
						cout << "Edit Promotion Usage Limit" << endl;
						cin >> limit;
					} while (limit <= 0);

					ptr->promoName = name;
					ptr->discount = disc;
					ptr->limit = limit;

					break;
				}
				case 4: {

					r->stack.displayPromotions();
					break;
				}
				case 5: {
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 4: {
			cout << "Returning to Main Menu..." << endl;
			break;
		}
		default: {
			cout << "Invalid choice! Please try again." << endl;
			break;
		}
		}
	} while (choice != 4);
}

//THIS IS CUSTOMER MODULE ,FUNCTIONALITY RELATED TO A CUSTOMER
void customerModule(Customer* cust, ReviewHeap* heap, Restaurant* restaurants,Delivery* d) {
	cout << "Customer login Successful." << endl;
	cout << "===============WELCOME==================" << endl;
	cout << "Customer Name  : " << cust->customerName << endl;
	cout << "Customer Email : " << cust->customerEmail << endl;
	cout << "========================================\n" << endl;



	int choice;
	do {
		cout << "\n---------- Customer Module ----------" << endl;
		cout << "1. Order Food" << endl;
		cout << "2. Check Your Order Status" << endl;
		cout << "3. View Reviews" << endl;
		cout << "4. Leave a Review" << endl;
		cout << "5. Edit Your Details" << endl;
		cout << "6. Back to Main Menu" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {	//ORDERING FOOD
			displayRestaurants(restaurants,d);

			int restid;
			Restaurant* temp;//FINDING RESTAURANT CUSTOMER CHOOSES TO ORDER FROM
			while (true) {
				do {
					cout << "\nEnter restuarant ID to Where You Will Order From : " << endl;
					cin >> restid;
				} while (restid < 10000 || restid > 99999);

				temp = searchRestaurant(restaurants, restid);

				if (temp) {
					break;
				}
			}

			temp->menuRoot.displayLevelOrder();		//DISPLAYING MENU
			int dishID;
			Dish* dish;
			while (true) {
				cout << "Enter the Dish ID you want to order: ";
				cin >> dishID;


				dish = temp->menuRoot.findDish(temp->menuRoot.dishRoot, dishID);

				if (dish) {
					break;
				}
			}

			int num;
			do {
				cout << "Enter number of dishes you wanna order : ";
				cin >> num;
			} while (num <= 0);
			int x;
			string type;
			do {
				cout << "1 : for Premium , 2 : Express , 3 : Normal" << endl;
				cin >> x;
			} while (x < 1 || x> 3);

			if (x == 1)type = "Premium";
			else if (x == 2)type = "Express";
			else type = "Normal";

			int del;

			d->displayLocations();
			do {
				cout << "Select a sector for your delivery : ";
				cin >> del;
			} while (del < 1 || del>30);


			temp->queueofOrders.enqueue(dish, num, type, cust, temp->stack,del-1);//ENQUEUEING ORDER IN THAT RESTAURANT
			break;
		}
		case 2: {
			Restaurant* temp = restaurants;
			while (temp != nullptr) {

				temp->queueofOrders.customerHistory(cust,d);	//CUSTOMER ORDER HISTORY

				temp = temp->next;
			}

			break;
		}
		case 3: {
			// VIWING REVIEWS
			int viewChoice;
			do {
				cout << "\n1. View Restaurant Reviews\n2. View Dish Reviews\n";
				cin >> viewChoice;
			} while (viewChoice < 1 || viewChoice > 2);

			if (viewChoice == 1) {
				heap->printGoodRestaurants();
				cout << endl;
				heap->printBadRestaurants();
			}
			else {
				heap->printGoodDishes();
				cout << endl;
				heap->printBadDishes();
			}
			break;
		}
		case 4: {	//LEAVING REVIEWS
			cout << "Enter 1 for Restaurant Review, 2 for Dish Review: ";
			int reviewType;
			cin >> reviewType;

			if (reviewType == 1) {
				displayRestaurants(restaurants,d);

				int restid;
				Restaurant* temp;
				while (true) {
					do {
						cout << "\nEnter restuarant ID : " << endl;
						cin >> restid;
					} while (restid < 10000 || restid > 99999);

					temp = searchRestaurant(restaurants, restid);

					if (temp) {
						break;
					}
				}

				int rating;
				do {
					cout << "Enter your rating (1-5): ";
					cin >> rating;
				} while (rating < 1 || rating >5);

				string desc;
				cout << "Enter your review description: ";
				cin.ignore();
				getline(cin, desc);

				Review review(rating, desc, temp);
				if (rating >= 3) {
					heap->insertGoodRestaurants(review);
				}
				else {
					heap->insertBadRestaurants(review);
				}
				cout << "Review added successfully!" << endl;
			}
			else if (reviewType == 2) {
				int restid;
				Restaurant* temp;

				displayRestaurants(restaurants,d);
				while (true) {
					do {
						cout << "\nEnter restuarant ID : " << endl;
						cin >> restid;
					} while (restid < 10000 || restid > 99999);

					temp = searchRestaurant(restaurants, restid);

					if (temp) {
						break;
					}
				}
				temp->menuRoot.displayLevelOrder();
				int dishID;
				Dish* dish;
				while (true) {
					cout << "Enter the Dish ID you want to order: ";
					cin >> dishID;


					dish = temp->menuRoot.findDish(temp->menuRoot.dishRoot, dishID);

					if (dish) {
						break;
					}
				}
				int rating;
				do {
					cout << "Enter your rating (1-5): ";
					cin >> rating;
				} while (rating < 1 || rating >5);

				string desc;
				cout << "Enter your review description: ";
				cin.ignore();
				getline(cin, desc);

				Review review(rating, desc, dish);
				if (rating >= 3) {
					heap->insertGoodDish(review);
				}
				else {
					heap->insertBadDish(review);
				}
				cout << "Review added successfully!" << endl;
			}
			else {
				cout << "Invalid option!" << endl;
			}
			break;
		}
		case 5: {//CUSTOMER SHOULD BE ABLE TO UPDATE HIS DATA
			string n, em, pass, res, reconfirm;

			cout << "Enter your name : ";
			cin.ignore();
			getline(cin, n);

			cout << "Enter your email : ";
			getline(cin, em);

			do {
				cout << "\nEnter your password: ";
				pass = getMaskedInput();

				cout << endl;
			} while (!isValidPassword(pass));

			while (true) {

				cout << "Reconfirm your password: ";
				reconfirm = getMaskedInput();

				if (pass == reconfirm) {
					cout << "Password set successfully" << endl;
					break;
				}
			}

			cust->customerName = n;
			cust->customerEmail = em;
			cust->customerPass = pass;

			break;
		}
		case 6: {
			cout << "Returning to Main Menu..." << endl;
			break;
		}
		default: {
			cout << "Invalid choice! Please try again." << endl;
		}
		}
	} while (choice != 6);
}

//THIS IS EMPLOYEE MODULE ,FUNCTIONS RELATED TO NORMAL EMPLOYEE
void employeeModule(Employee* emp, EmpHashMap* h,Delivery *d) {

	cout << "Employee login Successful." << endl;
	cout << "===============WELCOME==================" << endl;
	cout << "Employee Name  : " << emp->employeeName << endl;
	cout << "Employee Email : " << emp->employeeEmail << endl;
	cout << "Employee Type  : Normal Employee" << endl;
	cout << "Employee Work Restaurant : ";
	if (emp->workRestaurant) {
		cout << emp->workRestaurant->restaurantName << endl;
		cout << "========================================\n" << endl;
	}
	else {
		cout << "None" << endl;

		cout << "\n\n*NOTE : SINCE YOU DONT HAVE A VALID WORK RESTAURANT RIGHT NOW YOU CANNOT ACCESS EMPLOYEE FUNCTIONALITY" << endl;
		cout << "\nCONTACT MANAGER ADMIN TO APPLY FOR A RESTUARANT" << endl;
		cout << "========================================\n" << endl;
		return;
	}

	int choice;
	do {
		cout << "\n---------- Employee Module ----------" << endl;
		cout << "1. Process Orders" << endl;
		cout << "2. View Employee Order History" << endl;
		cout << "3. View Restaurants Current Orders Queue" << endl;
		cout << "4. Edit your data " << endl;
		cout << "5. Back to Main Menu" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			Order* ptr = emp->workRestaurant->queueofOrders.dequeue(emp,d); // PROCESSING ORDER
			if (ptr == nullptr) {
				cout << "No orders available to process." << endl;
				break;
			}

			// Display the list of drivers
			Employee* eptr;
			displayDrivers(h,emp->workRestaurant);
			int id;
			while (true) {
				do {
					cout << "\nSelect Delivery Driver To Deliver This Order: " << endl;
					cin >> id;
				} while (id < 10000 || id > 99999);  // Ensure the ID is valid

				// Search for the driver
				eptr = h->searchEmployee(id);

				if (eptr) {
					break;  // Valid driver found
				}
				else {
					cout << "Invalid driver ID. Please try again." << endl;
				}
			}

			
			ptr->deliveryDriver = eptr;
			cout << "Order has been assigned to driver: " << eptr->employeeName << endl;
			

			addOrderToDelivery(eptr, ptr, d);
			break;
		}
		case 2: {
			emp->workRestaurant->queueofOrders.employeeHistory(emp,d); //VIEWING EMPLOYEE PROCESSED ORDERS
			break;
		}
		case 3: {
			emp->workRestaurant->queueofOrders.display(d);//VIEWING OVERALL ORDERS OF RESTAURANT 
			break;
		}
		case 4: {
			string n, em, pass, res, reconfirm;//EDITING EMPLOYEE DATA

			cout << "Edit your name : ";
			cin.ignore();
			getline(cin, n);

			do {
				cout << "\nEnter your email : ";
				cin >> em;
			} while (!isValidEmp(em, h));

			do {
				cout << "\nEdit your password: ";
				pass = getMaskedInput();

				cout << endl;
			} while (!isValidPassword(pass));

			while (true) {

				cout << "Reconfirm your new password: ";
				reconfirm = getMaskedInput();

				if (pass == reconfirm) {
					cout << "Password set successfully" << endl;
					break;
				}
			}

			emp->employeeName = n;
			emp->employeeEmail = em;
			emp->employeePass = pass;

			break;
		}
		case 5: {
			cout << "Returning to Main Menu..." << endl;
			break;
		}
		default: {
			cout << "Invalid choice! Please try again." << endl;
		}
		}
	} while (choice != 5);
}

void signingUp(Restaurant* restaurants, EmpHashMap* empHash, CustHashMap* custHash, Delivery* d, ReviewHeap* r) {

	int choice = 0;

	do {
		cout << "1: Signup as Customer" << endl;
		cout << "2: Signup as Manager" << endl;
		cout << "3: Return To Main Menu" << endl;
		cin >> choice;

		switch (choice) {
		case 1: {

			string n, em, pass, res, reconfirm;

			cout << "Enter your name : ";
			cin.ignore();
			getline(cin, n);

			do {
				cout << "\nEnter your email : ";
				cin >> em;
			} while (!isValidCust(em, custHash));

			do {
				cout << "\nEnter your password: ";
				pass = getMaskedInput();

				cout << endl;
			} while (!isValidPassword(pass));

			while (true) {

				cout << "Reconfirm your password: ";
				reconfirm = getMaskedInput();

				if (pass == reconfirm) {
					cout << "Password set successfully" << endl;
					break;
				}
			}



			Customer qust = Customer(n, em, pass);
			custHash->insertIntoHashMap(qust);

			customerModule(custHash->searchCustomerByEmail(em, pass), r, restaurants, d);
			return;
			break;
		}
		case 2: {

			string n, em, pass, res, reconfirm;

			cout << "Enter your name : ";
			cin.ignore();
			getline(cin, n);

			do {
				cout << "\nEnter your email : ";
				cin >> em;
			} while (!isValidEmp(em, empHash));



			do {
				cout << "\nEnter your password: ";
				pass = getMaskedInput();

				cout << endl;
			} while (!isValidPassword(pass));

			while (true) {

				cout << "Reconfirm your password: ";
				reconfirm = getMaskedInput();

				if (pass == reconfirm) {
					cout << "Password set successfully" << endl;
					break;
				}
			}

			displayRestaurants(restaurants, d);

			int restid;
			Restaurant* temp;
			while (true) {
				do {
					cout << "\nEnter restuarant ID to Where You Will Work : " << endl;
					cin >> restid;
				} while (restid < 10000 || restid > 99999);

				temp = searchRestaurant(restaurants, restid);

				if (temp) {
					break;
				}
			}

			if (temp->manager) {
				cout << "Manager of this restuarant already exists , PLEASE APPLY FOR OTHER RESTAURANTS" << endl;
			}
			else {

				Employee manage = Employee(n, em, "Manager", pass, temp);
				empHash->insertIntoHashMap(manage);

				managerModule(empHash->searchEmployeeByEmail(em, pass), empHash, temp);
				return;
			}
			break;
		}
		case 3: {
			cout << "Returning to Main Menu" << endl;
			break;
		}
		default: {
			cout << "Invalid Choice" << endl;
			break;
		}
		}
	} while (choice != 3);


}

void loggingIn(string buffer, Restaurant* restaurants, EmpHashMap* empHash, CustHashMap* custHash, Delivery* d, ReviewHeap* r) {




	cout << "\nEnter your password: ";
	string pass = getMaskedInput();

	cout << endl;

	if (buffer == "admin@gmail.com") {

		if (adminLogin(pass)) {
			Admin administrator(restaurants, empHash, custHash);
			adminModule(administrator, d);
			return;
		}
	}


	Employee* temp = managerLogin(empHash, buffer, pass);
	if (temp != nullptr) {
		managerModule(temp, empHash, temp->workRestaurant);
		return;
	}

	Customer* ctemp = customerLogin(custHash, buffer, pass);
	if (ctemp != nullptr) {
		customerModule(ctemp, r, restaurants, d);
		return;
	}

	Employee* etemp = employeeLogin(empHash, buffer, pass);
	if (etemp != nullptr) {
		if (etemp->employeeType == "Employee") {
			employeeModule(etemp, empHash, d);
			return;
		}
		else {
			deliveryModule(etemp, empHash, d);
			return;
		}
	}

	cout << "No Such User Exists" << endl;
	return;
}
