#include <iostream>
#include "header.h"
#include <string>
using namespace std; 



int main() {
	EmpHashMap empHash;
	CustHashMap custHash;
	Restaurant* restaurants = nullptr;
	ReviewHeap review;
	bool flag = true;

	Delivery d;

		//PRE POPULATING DATA
		addRestaurant(restaurants, "Serena Hotel", "Dining", 1);

		Restaurant* serena = searchRestaurant(restaurants, 10000);
		Employee employee1("Uzair", "uzair@gmail.com", "Manager", "P@ssword1",serena);
		Employee employee2("Rizwan", "rizwan@gmail.com", "Employee", "P@ssword2", serena);

		Employee driver1("Yahya", "yahya@gmail.com", "Driver", "D@river1", serena);
		Employee driver2("Usman", "usman@gmail.com", "Driver", "D@river2", serena);

		empHash.insertIntoHashMap(employee1);
		empHash.insertIntoHashMap(employee2);
		empHash.insertIntoHashMap(driver1);
		empHash.insertIntoHashMap(driver2);

		Customer customer1("Hashir", "hashir@gmail.com", "C@ustomer1");
		Customer customer2("Hussnain", "hussnain@gmail.com", "C@ustomer2");
		custHash.insertIntoHashMap(customer1);
		custHash.insertIntoHashMap(customer2);

		serena->menuRoot.addDish("Chicken Biryani","Desi", 899.99);
		serena->menuRoot.addDish("Grilled Chicken","Desi", 1299.99);
		serena->menuRoot.addDish("Beef Burger","Fast Food", 2999.99);
		serena->menuRoot.addDish("Pizza", "Fast Food", 3999.99);
		serena->menuRoot.addDish("Ice Cream Cake", "Sweet", 2999.99);


		Review r1(5, "Excellent dining experience!", serena);
		Dish* t1 = serena->menuRoot.findDish(serena->menuRoot.dishRoot, 10000);
		Review r2(5, "Perfectly cooked, authentic taste!", t1);
		Dish* t2 = serena->menuRoot.findDish(serena->menuRoot.dishRoot, 10001);
		Review r3(1, "Ew that taste is so god awful. I wish I had cancer rather than that!", t2);

		review.insertGoodRestaurants(r1);
		review.insertGoodDish(r2);
		review.insertBadDish(r3);


		Dish* tn = serena->menuRoot.findDish(serena->menuRoot.dishRoot, 10002);
		Dish* tm = serena->menuRoot.findDish(serena->menuRoot.dishRoot, 10003);
		Dish* tp = serena->menuRoot.findDish(serena->menuRoot.dishRoot, 10004);

		serena->stack.pushPromo("Pakistan Day Promotion", 0.30, 2);
		serena->stack.pushPromo("Black Friday Promotion", 0.50, 3);


		serena->queueofOrders.enqueue(t1, 2, "Premium", custHash.searchCustomer(10000), serena->stack,10);
		serena->queueofOrders.enqueue(t2, 3, "Express", custHash.searchCustomer(10001), serena->stack,3);
		serena->queueofOrders.enqueue(tn, 3, "Express", custHash.searchCustomer(10001), serena->stack, 5);
		serena->queueofOrders.enqueue(tm, 2, "Normal", custHash.searchCustomer(10000), serena->stack, 14);
		serena->queueofOrders.enqueue(tp, 3, "Premium", custHash.searchCustomer(10001), serena->stack, 28);

		addRestaurant(restaurants, "Jackie Chan Hotel", "Chinese",6);

		Restaurant* chinese = searchRestaurant(restaurants, 10001);
		Employee employee3("Ali", "ali@gmail.com", "Manager", "P@ssword3", chinese);
		Employee employee4("Ayesha", "ayesha@gmail.com", "Employee", "P@ssword4", chinese);


		Employee driver3("Fatima", "fatima@gmail.com", "Driver", "D@river3", chinese);
		Employee driver4("Sara", "sara@gmail.com", "Driver", "D@river4", chinese);
		empHash.insertIntoHashMap(employee3);
		empHash.insertIntoHashMap(employee4);
		empHash.insertIntoHashMap(driver3);
		empHash.insertIntoHashMap(driver4);

		Customer customer3("Nasir", "nasir@gmail.com", "C@ustomer3");
		Customer customer4("Faiz Ahmed Faiz", "faiz@gmail.com", "C@ustomer4");
		custHash.insertIntoHashMap(customer3);
		custHash.insertIntoHashMap(customer4);

		chinese->menuRoot.addDish("Chow Mein", "Chinese", 899.99);
		chinese->menuRoot.addDish("Sushi", "Chinese", 1299.99);
		chinese->menuRoot.addDish("Octopus", "SeaFood", 2999.99);

		Review rx(5, "Excellent dining experience!", chinese);
		Dish* tx = chinese->menuRoot.findDish(chinese->menuRoot.dishRoot, 10005);
		Review ry(5, "Perfectly cooked, authentic taste!", tx);
		Dish* ty = chinese->menuRoot.findDish(chinese->menuRoot.dishRoot, 10006);
		Review rz(1, "Ew that taste is so god awful. I wish I had cancer rather than that!", ty);

		review.insertGoodRestaurants(rx);
		review.insertGoodDish(ry);
		review.insertBadDish(rz);

		chinese->stack.pushPromo("Chinese Independence Day Promotion", 0.30, 2);
		chinese->stack.pushPromo("Black Friday Promotion", 0.50, 3);


		chinese->queueofOrders.enqueue(tx, 2, "Premium", custHash.searchCustomer(10002), chinese->stack,5);
		chinese->queueofOrders.enqueue(ty, 3, "Express", custHash.searchCustomer(10003), chinese->stack,20);
		//PRE POPULATING DATA
	

		while (flag) {

			int choice;

			do {
				cout << "\n================= Restaurant HUB =================" << endl;
				cout << "1. Login" << endl;
				cout << "2. SignUp" << endl;
				cout << "3. Exit" << endl;
				cout << "================================================================" << endl;
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1: {
					string buffer = "";
					cout << "Enter Gmail or Email Address : " << endl;
					cin.ignore();
					getline(cin, buffer);

					loggingIn(buffer,restaurants,&empHash,&custHash,&d,&review);
					break;
				}
				case 2: {
					signingUp(restaurants, &empHash, &custHash, &d, &review);
					break;
				}
				case 3: {
					cout << "Exiting...." << endl;
					flag = false;
					break;
				}
				default: {
					cout << "Invalid choice! Please enter a valid option." << endl;
					break;
				}
				}
			} while (choice != 3);
		}


	//while (flag) {
	//	do {
	//		// Main Menu
	//		cout << "\n================= Restaurant Management System =================" << endl;
	//		cout << "1. Admin Module" << endl;
	//		cout << "2. Manager Module" << endl;
	//		cout << "3. Customer Module" << endl;
	//		cout << "4. Employee Module" << endl;
	//		cout << "5. Delivery Module" << endl;
	//		cout << "6. Exit" << endl;
	//		cout << "================================================================" << endl;
	//		cout << "Enter your choice: ";
	//		cin >> choice;

	//		switch (choice) {
	//		case 1: {
	//			if (adminLogin()) {
	//				Admin administrator(restaurants,& empHash,& custHash);
	//				adminModule(administrator,&d);
	//			}
	//			else {
	//				cout << "Admin Key Incorrect" << endl;
	//			}

	//			break;
	//		}
	//		case 2: {
	//			int ch;
	//			do {
	//				cout << "1: To Login as Manager" << endl;
	//				cout << "2: To SignUp as Manager" << endl;
	//				cin >> ch;
	//			} while (ch < 1 || ch>2);

	//			switch (ch) {
	//			case 1: {
	//				string em, pass;

	//				cout << "Enter your email : ";
	//				cin.ignore();
	//				getline(cin, em);

	//				cout << "\nEnter your password: ";
	//				pass = getMaskedInput();

	//				cout << endl;

	//				Employee* temp = managerLogin(&empHash, em,pass);
	//				if (temp != nullptr) {
	//					managerModule(temp,empHash,temp->workRestaurant);
	//				}

	//				break;
	//			}
	//			case 2: {
					/*string n, em, pass, res,reconfirm;

					cout << "Enter your name : ";
					cin.ignore();
					getline(cin, n);

					do {
						cout << "\nEnter your email : ";
						cin >> em;
					} while (!isValidEmp(em, &empHash));



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

					displayRestaurants(restaurants,&d);

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
						empHash.insertIntoHashMap(manage);

						managerModule(empHash.searchEmployeeByEmail(em, pass),empHash,temp);
					}*/
	//				break;
	//			}
	//			}

	//				  break;
	//			}
	//		case 3: {

	//			int ch;
	//			do {
	//				cout << "1: To Login as Customer" << endl;
	//				cout << "2: To SignUp as Customer" << endl;
	//				cin >> ch;
	//			} while (ch < 1 || ch>2);

	//			switch (ch) {
	//			case 1: {
	//				string em, pass;

	//				cout << "Enter your email : ";
	//				cin.ignore();
	//				getline(cin, em);

	//				cout << "\nEnter your password: ";
	//				pass = getMaskedInput();

	//				cout << endl;

	//				Customer* temp = customerLogin(&custHash, em,pass);
	//				if (temp != nullptr) {
	//					customerModule(temp,review,restaurants,&d);
	//				}

	//				break;
	//			}
	//			case 2: {
	//				string n, em, pass, res, reconfirm;

	//				cout << "Enter your name : ";
	//				cin.ignore();
	//				getline(cin, n);

	//				do {
	//					cout << "\nEnter your email : ";
	//					cin >> em;
	//				} while (!isValidCust(em, &custHash));

	//				do {
	//					cout << "\nEnter your password: ";
	//					pass = getMaskedInput();

	//					cout << endl;
	//				} while (!isValidPassword(pass));

	//				while (true) {

	//					cout << "Reconfirm your password: ";
	//					reconfirm = getMaskedInput();

	//					if (pass == reconfirm) {
	//						cout << "Password set successfully" << endl;
	//						break;
	//					}
	//				}
	//				


	//				Customer qust = Customer(n, em, pass);
	//				custHash.insertIntoHashMap(qust);

	//				customerModule(custHash.searchCustomerByEmail(em,pass),review,restaurants,&d);

	//				break;
	//			}
	//			}
	//			break;
	//		}
	//		case 4: {
	//			string em, pass;

	//			cout << "Enter your email : ";
	//			cin.ignore();
	//			getline(cin, em);

	//			cout << "\nEnter your password: ";
	//			pass = getMaskedInput();

	//			cout << endl;

	//			Employee* temp = employeeLogin(&empHash, em,pass);
	//			if (temp != nullptr) {
	//				employeeModule(temp,empHash,&d);
	//			}
	//			break;
	//		}
	//		case 5: {
	//			string em, pass;

	//			cout << "Enter your email : ";
	//			cin.ignore();
	//			getline(cin, em);

	//			cout << "\nEnter your password: ";
	//			pass = getMaskedInput();

	//			cout << endl;

	//			Employee* temp = employeeLogin(&empHash, em, pass);
	//			if (temp != nullptr) {
	//				deliveryModule(temp, empHash,&d);
	//			}

	//			break;
	//		}
	//		case 6: {
	//			cout << "Exiting the system. Thank you!" << endl;
	//			flag = false;
	//			break;
	//		}
	//		default: {
	//			cout << "Invalid choice! Please enter a valid option." << endl;
	//			break;
	//		}
	//		}

	//		} while (choice != 6);
	//}
    return 0;
}


