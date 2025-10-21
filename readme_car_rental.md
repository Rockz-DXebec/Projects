# 🚗 ROCKZ Car Rental System

## 📋 Overview
The **ROCKZ Car Rental System** is a **C-based console application** that simulates a car rental service.  
Users can choose from **Premium, Sports, and Luxury** car tiers, rent vehicles for multiple days, opt for **insurance coverage**, and view a detailed **rental summary** with receipt ID and total cost.

This project demonstrates:
- Conditional logic  
- Loops and input handling  
- Random number generation (`rand()`)  
- Time functions (`time()`, `ctime()`)  
- Modular program structure  

---

## ✨ Features
✅ Three Tiers of Cars — **Premium, Sports, and Luxury**  
✅ Displays multiple car models with rental and deposit options  
✅ Calculates:
- Base rent  
- Security deposit  
- Optional insurance (10%)  
- Discounts (10% for rentals over 5 days)  
✅ Auto-generates a **unique receipt ID** and shows the current date/time  
✅ Option to rent another car without restarting the program  

---

## 🧰 Technologies Used
| Component | Description |
|------------|--------------|
| Language | **C Programming Language** |
| Compiler | GCC / MinGW / Turbo C / Code::Blocks |
| Libraries | `stdio.h`, `stdlib.h`, `time.h` |
| Platform | Works on **Windows**, **Linux**, and **macOS** (console-based) |

---

## ⚙️ How to Run the Program

### 🖥️ Step 1: Clone the Repository

git clone https://github.com/<Rockz-DXebec>/<Projects>.git
cd <Projects>

🧱 Step 2: Compile the Code

Use any C compiler (example using GCC):

gcc car_rental_system.c -o car_rental_system

▶️ Step 3: Run the Program
./car_rental_system

Step 4: Follow On-Screen Instructions

Select a tier (Premium, Sports, or Luxury)

Enter your name and number of rental days

Choose your car model

Decide whether to add insurance

View your rental summary and total amount

EXAMPLE OUTPUT 
---------------------------------------------------
        WELCOME TO ROCKZ CAR RENTAL SYSTEM
---------------------------------------------------

1)Premium
2)Sports
3)Luxury
4)Exit
Select Tier: 1
Enter name: Alex
Enter number of rental days: 6
Choose Car: 10
Would you like to add insurance coverage (10% extra)?
1. Yes
2. No
Enter choice (1 or 2): 1

---------------------------------------------------
                 RENTAL SUMMARY
---------------------------------------------------
Receipt ID          : #48219
Date & Time         : Tue Oct 21 14:30:21 2025
Customer Name       : Alex
Tier Selected       : Premium
Car Selected        : Brabus Rocket 900
Rent per Day        : $15000.00
Days Rented         : 6
Base Rent           : $90000.00
Security Deposit    : $60000.00
Discount (10%)      : $9000.00
Insurance (10%)     : $9000.00
---------------------------------------------------
Total Amount Payable: $150000.00
---------------------------------------------------


🎯 Key Concepts Demonstrated

Random receipt generation using rand()

Real-time timestamp display using ctime()

Use of loops and conditional statements

Dynamic calculation of total cost with insurance and discounts

Clean, menu-driven structure

🔮 Future Improvements

Save receipts automatically to a file (e.g., receipt.txt)

Add an admin panel for car management

Include overdue fee calculation for late returns

Create a GUI version using C++ or Python

👨‍💻 Author

ROCKZ
📧 imdadmasum0053@gmail.com

💼 GitHub Profile-  `https://github.com/Rockz-DXebec/Projects`

🪪 License

This project is released under the MIT License
.
Feel free to use, modify, and distribute it with proper credit.
