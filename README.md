# Airport Management System

## Introduction
The **Airport Management System** is a C++ project that utilizes **MySQL** for database management. It allows users to add, list, search, and delete flight details while ensuring smooth airport operations. The system provides an easy-to-use console interface for managing flights at **Biju Patnaik International Airport**.

## Technologies Used
- **Programming Language:** C++
- **Database:** MySQL
- **Libraries:**
  - MySQL Connector for C++
  - Windows API (`windows.h` for system operations)
  - Console Input Handling (`conio.h`)
- **IDE:** Dev-C++ 5.11

## Features
- **Add Flights:** Enter flight details including date, airline name, flight number, timings, and passenger details.
- **List Flights:** Retrieve and display all flight records stored in the database.
- **Search Flight:** Find specific flights using the flight number.
- **Delete Flight Details:** Remove a flight record from the database.
- **Database Connectivity:** Uses MySQL to store and retrieve data.

## Setup Instructions
### Prerequisites
1. Install **MySQL Server** (ensure it is running).
2. Install **Dev-C++ 5.11** or any compatible C++ compiler.
3. Add the MySQL library path to Dev-C++ settings.

### Installation Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/airport-management.git
   cd airport-management
   ```
2. Configure MySQL Connection:
   - Open `main.cpp` and update the credentials:
     ```cpp
     const char *HOST = "localhost";
     const char *USER = "root";
     const char *PASSW = "your_password";
     const char *DB = "airport_management";
     ```
3. Compile and run the project:
   ```bash
   g++ main.cpp -o airport_management.exe -lmysql
   ./airport_management.exe
   ```

## Database Schema
```sql
CREATE DATABASE airport_management;
USE airport_management;

CREATE TABLE flight_detail (
    Date DATE,
    Airline_Name VARCHAR(50),
    Flight_Number VARCHAR(20) PRIMARY KEY,
    Arrival_Location VARCHAR(50),
    Landing_Runway VARCHAR(10),
    Arrival_Time TIME,
    Departure_Time TIME,
    Takeoff_Runway VARCHAR(10),
    Destination_Location VARCHAR(50),
    Pilot VARCHAR(50),
    Copilot VARCHAR(50),
    Cabin_Crew INT,
    Maintenance_Technicians INT,
    Passengers_Get_Off INT,
    Seats_Available INT,
    Passengers_Entered INT
);
```

## Future Enhancements
- Implement **Graphical User Interface (GUI)**.
- Add **Flight Scheduling and Delay Notifications**.
- Integrate **Air Traffic Control (ATC) API**.

## License
This project is licensed under the **MIT License**.
