Hotel Management System - 
This is a simple Hotel Management System implemented in C++ that allows you to manage customer records for a hotel. The system provides the following functionalities:

Book a Room: You can book a room for a customer by entering room number, customer name, address, and bill amount. The customer details are stored in a file.

Search Customer Details: You can search for customer details by entering the room number. The system will display the customer's name, address, and bill amount.

Display Total Allotted Rooms: This option shows you the total number of rooms that have been allotted to customers.

Modify Customer Record: If you need to update a customer's details (name, address, or bill amount), you can do so by entering the room number. The system will update the record in the file.

Delete Customer Record: You can delete a customer's record by providing the room number. The system will remove the record from the file.

Exit: To exit the program, choose this option.

How to Use -
Compile the code: Compile the C++ code using your preferred C++ compiler. Ensure that the necessary C++ libraries are available.

Run the program: Execute the compiled program, and the Hotel Management System menu will be displayed.

Select an option: Use the menu options to perform various actions, such as booking rooms, searching for customer details, modifying records, or deleting records.

Customer Records: Customer records are stored in a file named "customer_records.txt." The program reads from and writes to this file to manage customer data.

Code Structure -
The program uses a Customer struct to store customer details, including room number, name, address, and bill amount.

Functions like readCustomerRecords and writeCustomerRecords are used to read and write customer data to the file.

The program utilizes a switch statement in the main function to handle different user choices.

User input is obtained using the cin object, and customer data is displayed using the cout object.

Note -
This is a basic hotel management system for educational purposes. In a real-world application, you would likely want to implement more robust error handling, data validation, and security measures for handling customer data. Additionally, consider using a database for more efficient data storage and retrieval.
