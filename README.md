# SRMS_Project
A simple Role-Based Access Control (RBAC) Student Management System written in C, using text files for data storage. It supports Admin, Staff, User, and Guest login roles, each with different permissions.

Features
🔐 Login System

Credentials stored in credentials.txt

Reads:

username password role


Example:

admin admin123 admin
staff1 pass staff
user1 123 user
guest guest guest

👥 User Roles & Permissions
1️⃣ Admin

Full Access:

Add student

Display all

Search

Update

Delete

Logout

2️⃣ Staff

Limited Modification:

Add

Display

Search

Update

Logout

3️⃣ User

Read Access + Search:

Display

Search

Logout

4️⃣ Guest

Read-Only:

Display

Logout

🗂️ Files Used
students.txt

Stores student records in format:

roll name mark

credentials.txt

Stores login credentials:

username password role

📦 Functionalities Implemented
✔ Add Student

Appends student record to students.txt.

✔ Display Students

Reads and prints all student records.

✔ Search Student

Finds and displays the record by roll number.

✔ Update Student

Rewrites the specific record with new details.

✔ Delete Student

Removes a student by recreating the file.

✔ Role-Based Menus

Separate menus for Admin / Staff / User / Guest.

🧾 Code Structure
login()
addStudent()
displayStudents()
searchStudent()
deleteStudent()
updateStudent()

adminMenu()
staffMenu()
userMenu()
guestMenu()

main()

▶️ How to Run
Compile
gcc student_app.c -o student

Run
./student.exe


Make sure students.txt and credentials.txt exist in the same folder.

📄 Sample credentials.txt
admin admin123 admin
staff1 staff123 staff
user1 user123 user
guest guest guest

📄 Sample students.txt
1 Aishu 98.00
2 Gayatri 97.00
3 Raj 88.00
4 Rahul 79.00
5 Karthik 89.00
6 Priya 75.00

##Simulation

<img width="408" height="394" alt="Screenshot 2025-12-04 130403" src="https://github.com/user-attachments/assets/2c96edd6-5d5f-43ed-8d9f-17912d2af54e" />

<img width="400" height="368" alt="Screenshot 2025-12-04 130424" src="https://github.com/user-attachments/assets/6b053a85-29dc-4af0-a6e3-c36bbc2a0c94" />

<img width="401" height="311" alt="Screenshot 2025-12-04 130437" src="https://github.com/user-attachments/assets/dc944ef9-f8e9-48ad-a317-0cb0ea8ca715" />

<img width="398" height="351" alt="Screenshot 2025-12-04 130456" src="https://github.com/user-attachments/assets/35c4539d-539f-4737-b0de-44adeb07e2c2" />

<img width="398" height="406" alt="Screenshot 2025-12-04 130651" src="https://github.com/user-attachments/assets/60f78de8-f71c-43fa-b2f4-082da700d84a" />

<img width="406" height="302" alt="Screenshot 2025-12-04 130713" src="https://github.com/user-attachments/assets/8c526814-3825-4b3c-a7ca-4ffda11ca5d2" />

<img width="384" height="103" alt="Screenshot 2025-12-04 130733" src="https://github.com/user-attachments/assets/f3333b47-ee89-42c4-8945-82a5f8140ce6" />

<img width="397" height="419" alt="Screenshot 2025-12-04 133159" src="https://github.com/user-attachments/assets/32ca47cd-3597-4aff-bca1-6a2a7125bbb6" />

<img width="406" height="288" alt="Screenshot 2025-12-04 133251" src="https://github.com/user-attachments/assets/0ac32f97-cc1d-4c94-8acf-b9d3d4b34f3c" />
