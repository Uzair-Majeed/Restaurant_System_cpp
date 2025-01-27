# Restaurant Management System - ReadMe

## Restaurant Name: RESTAURANT HUB


## Description:

- The Restaurant Hub (RH) is a software application manage various activities within a restaurant. 
- The system has modules for different types of users: Admin, Manager, Customer, Employee, and Delivery Driver.
- Each module provides a range of functionalities tailored to the user's role within the restaurant operations. 
- The system aims to manage restaurant operations efficiently, including restaurant management, employee management, customer interaction, order processing, and more.
- The application includes a delivery service used by graph-based algorithms (Djikstra algorithm).

---

## Steps to Run the Application

- Ensure that you have a C++ compiler installed.
- Use an IDE such as Visual Studio, or any text editor to compile and run the program.

---

## Used Data Structures

- HashMaps for Admin,Employee(Manager,Normal Employee and Driver) and Customer Data.
- Binary Tree for Menus.
- Heap for Reviews.
- Priority Queue For Orders.
- Stack For Promotions.
- Graph For Delivery Locations.
- Linked List For Restaurants.
- Djikstra Algorithm used for Shortest path navigation.
  
---

## Functionalities and Their Descriptions:

### Main Menu:

The main menu provides access to five user modules: Admin, Manager, Customer, Employee, and Delivery Driver.

1. **Admin Module:**
   - **Manage Restaurants:** Add, update, or delete restaurant information.
   - **Manage Managers/Employees:** Add or remove managers/employees and manage their roles and permissions.
   - **Manage Customers:** View and edit customer details, such as contact information and order history.
   - **Admin Key :** 123456789 

2. **Manager Module:**
   - **Manage Employee:** Assign or manage employee tasks, shift schedules, and performance.
   - **Manage Menus and Dishes:** Add, remove, or modify the menu and dishes served at the restaurant.
   - **Manage Promotions:** Handle promotions, discounts, or special offers.

3. **Customer Module:**
   - **Order Food:** Browse the menu, add dishes to the cart, and place an order.
   - **Check Your Order Status:** Track the current status of your order (e.g., processed, unprocessed).
   - **View Reviews:** See customer reviews for various dishes or services.
   - **Leave a Review:** Leave feedback or ratings for your recent order or dining experience.
   - **Edit Your Details:** Modify personal information such as name, address, contact number, etc.

4. **Employee Module:**
   - **Process Orders:** Process incoming customer orders and update the order status.
   - **View Employee Order History:** View and manage your order history and performance.
   - **View Restaurant's Current Orders Queue:** View a list of pending orders in the restaurant.
   - **Edit Your Data:** Update personal employee information (e.g., contact details, work schedule).

5. **Delivery Module:**
   - **View Assigned Orders:** View a list of orders assigned to the delivery person, including the destination address and customer details.
   - **Optimize Delivery Route:** Use the shortest path algorithm to calculate the most efficient route for order delivery.
   - **Update Delivery Status:** Mark orders as "Delivered" or "Failed to Deliver" with reasons for failure.
   - **Track Total Distance:** View the total distance traveled for deliveries made during the shift.
   - **Edit Delivery Details:** Update personal details such as contact information and shift schedule.

---

### Prepopulated Data

- File Reading is not incorporated in this project. Some data is already pre-populated for easy use in phase2.cpp file.

## How to Navigate the Application:

1. After starting the program, you will be presented with the **SignIn/Login Page**
2. You can signin or login, based on your MODULE TYPE , You will be redirected to respective module page.

---
## Collaborators
Me and Rizwan Saeed

---

## Important Notes:

- Ensure that your input is valid when selecting menu options.
- The system may require administrative privileges for managing restaurants, employees, and customer data.

---

## Contact/Support:
- uzairmjd886@gmail.com
