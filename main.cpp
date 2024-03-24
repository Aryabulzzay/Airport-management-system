#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;
const char *HOST = "localhost";
const char *USER = "root";
const char *PASSW = "Arya052@bulzzay_";
const char *DB = "airport_management";

int qstate;
MYSQL *conn;
MYSQL_ROW row;
MYSQL_RES *res;

class db_response
{
public:
	static void connectionFunction()
	{
		conn = mysql_init(NULL);
		conn = mysql_real_connect(conn, HOST, USER, PASSW, DB, 3306, NULL, 0);
		if (conn)
		{
			cout << "Database Connected..." ;
			Sleep(2000);
			system("cls");
		}
		else
		{
			cout << "Failed to connect!" << endl;
			cout << mysql_error(conn) << endl;
		}
	}
	static void connectionClose()
	{
		mysql_close(conn);
	}
};

 class flight_detail
    {
    public:
    	string date;
		string airline;
		string FlightNo;
		string source;
		string landingrunway;
		string arrivalTime;
		string departureTime;
		string takeoffrunway;
		string location;
		string pilot;
		string copilot;
		string cabincrew;
		string ATM;
		string passengersGotOff;
		string totalSeats;
		string passengersEntered;
		
		void displayFlightInfo()
        {
	        cout << "Date: " << date << endl;
			cout << "Airline Name: " << airline << endl;
	        cout << "Flight Number: " << FlightNo << endl;
	        cout << "Arrival Location: " << source << endl;
	        cout << "Landing Runway : " << landingrunway << endl;
			cout << "Arrival Time: " << arrivalTime << endl;
	        cout << "Departure Time: " << departureTime << endl;
	  	    cout << "Landing Runway : " << landingrunway << endl;	  
		    cout << "Location: " << location << endl;
	        cout << "Pilot: " << pilot << endl;
	        cout << "Copilot: " << copilot << endl;
	        cout << "Number of Cabin Crew Members: " << cabincrew << endl;
	        cout << "Aircraft Maintenance Technicians(ATM): " << ATM << endl;
			cout << "Number of Passengers Got Off: " <<passengersGotOff << endl;
		    cout << "Total Seats available: " << totalSeats << endl;
		    cout << "Number of Passengers Entered at Arrival Location: " << passengersEntered << endl;
        }
    };
		
int main() 
{
	db_response::connectionFunction();
	bool exit=false;
	while(!exit)
	{
		system("cls");
		int choice;
		cout << endl
             << "*******BIJU PATNAIK INTERNATIONAL AIRPORT*******" << endl;
        cout << endl
             << "CHOOSE THE BELOW OPTIONS TO PROCEED\n" << endl;
        cout << " 1. ADD FLIGHTS\n ";
		cout << "2. LIST FLIGHTS\n ";
		cout << "3. SEARCH FLIGHT\n ";
		cout << "4. DELETE FLIGHT DETAILS\n ";
		cout << "5. EXIT :)\n";
        cin >> choice;
        
		if (choice==1){
        	string date;
			string airline;
			string FlightNo;
			string source;
			string landingrunway;
			string arrivalTime;
			string departureTime;
			string takeoffrunway;
			string location;
			string pilot;
			string copilot;
			string cabincrew;
			string ATM;
			string passengersGotOff;
			string totalSeats;
			string passengersEntered;
		    cout << "Date (Enter in the form of YYYY-MM-DD ): ";
	        cin >> date;
			cout << "Airline Name: ";
	        cin >> airline;
	        cout << "Flight Number: ";
	        cin >> FlightNo;
	        cout << "Arrival Location: ";
	        cin >> source;
	        cout << "Landing Runway Number: ";
	        cin >> landingrunway;
	        cout << "Arrival Time in 24-Hour Time: ";
	        cin >> arrivalTime;
	        cout << "Departure Time in 24-Hour Time: ";
	        cin >> departureTime;
	        cout << "Takeoff Runway Number: ";
	        cin >> takeoffrunway;
	        cout << "Destination Location: ";
	        cin >> location;
	        cout << "Pilot's Name: ";
	        cin >> pilot;
	        cout << "Copilot's Name: ";
	        cin >> copilot;
	        cout << "Number of cabin crew members: ";
	        cin >> cabincrew;
	        cout << "Number of Aircraft Maintenance Technicians(ATM): ";
	        cin >> ATM;
	        cout << "Number of Passengers Got Off at Arrival Location: ";
            cin >> passengersGotOff;
	        cout << "Total Seats available: ";
	        cin >> totalSeats;
	        cout << "Number of Passengers Entered at Arrival Location: ";
	        cin >> passengersEntered;
            string query = "INSERT INTO flight_detail (Date,Airline_Name ,Flight_Number, Arrival_Location, Landing_Runway, Arrival_Time , Departure_Time , Takeoff_Runway, Destination_Location,Pilot,Copilot,Cabin_crew,Maintenance_Technicians,Passengers_Get_off,Seats_available,Passengers_Entered) VALUES ('" + date + "','" + airline + "','" + FlightNo + "','" + source + "','" + landingrunway + "','"+ arrivalTime + "','" + departureTime + "','"+ takeoffrunway + "','" + location + "','" + pilot + "','" + copilot + "','" + cabincrew + "','" + ATM + "','" + passengersGotOff + "','" + totalSeats + "','" + passengersEntered + "' )";
			if (mysql_query(conn, query.c_str()))
			{
				cout << mysql_error(conn) << endl;
				Sleep(10000);
			}
			else
			{
				cout << "Data inserted..." << endl<< endl;
			}
			Sleep(5000);  
		}
		
		else if(choice==2)
		{
			cout << "**FLIGHT DETAILS***\n\n";
	        qstate = mysql_query(conn, "select * from flight_detail");
			if (!qstate)
			{
				res = mysql_store_result(conn);
				printf("+-----------+--------------+---------------+------------------+-----------------+--------------+----------------+-----------------+-------------+--------+----------+------------+-------------------------+--------------------+--------------+--------------------+\n");
				printf("|%-10s | %-12s | %-13s | %-16s | %-15s | %-12s | %-14s | %-15s | %-11s | %-6s | %-8s | %-10s | %-23s | %-18s | %-12s | %-18s |\n", "Date","Airline Name","Flight Number","Arrival Location","Landing Runway","Arrival Time","Departure Time","Takeoff Runway","Destination","Pilot","Copilot","Cabin crew","Maintenance Technicians","Passengers Got Off","Total Seats","Passengers Entered");
				printf("+-----------+--------------+---------------+------------------+-----------------+--------------+----------------+-----------------+-------------+--------+----------+------------+-------------------------+--------------------+--------------+--------------------+\n");
				while ((row = mysql_fetch_row(res)))
				{
					flight_detail currentflight_detail;
                    currentflight_detail.date = row[0];
                    currentflight_detail.airline = row[1];
                    currentflight_detail.FlightNo = row[2];
                    currentflight_detail.source = row[3];
                    currentflight_detail.landingrunway = row[4];
                    currentflight_detail.arrivalTime = row[5];
                    currentflight_detail.departureTime = row[6];
                    currentflight_detail.takeoffrunway = row[7];
                    currentflight_detail.location = row[8];
                    currentflight_detail.pilot = row[9];
                    currentflight_detail.copilot = row[10];
                    currentflight_detail.cabincrew = row[11];
                    currentflight_detail.ATM = row[12];
                    currentflight_detail.passengersGotOff = row[13];
                    currentflight_detail.totalSeats = row[14];
                    currentflight_detail.passengersEntered = row[15];
                    if (atoi(row[15]) > 0)
					{
						printf("|%-10s | %-12s | %-13s | %-16s | %-15s | %-12s | %-14s | %-15s | %-11s | %-6s | %-8s | %-10s | %-23s | %-18s | %-12s | %-18s |\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14], row[15]);
					}	
				}
				printf("+-----------+--------------+---------------+------------------+-----------------+--------------+----------------+-----------------+-------------+--------+----------+------------+-------------------------+--------------------+--------------+--------------------+\n");
		        getch();
			}
			else
			{
				cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
			}    
		}
		
		else if(choice==3)
		{
			bool validFlight = false;
		    while (!validFlight)
		    {
				string FlightNo;
				cout<<"Enter Flight Number to search for:";
				cin>>FlightNo;
				string query = "select * from flight_detail where Flight_Number = '" + FlightNo + "' ";
				qstate = mysql_query(conn, query.c_str());
				if (!qstate)
				{
					res = mysql_store_result(conn);
					if (mysql_num_rows(res) > 0)
	        		{
						printf("+-----------+--------------+---------------+------------------+-----------------+--------------+----------------+-----------------+-------------+--------+----------+------------+-------------------------+--------------------+--------------+--------------------+\n");
						printf("|%-10s | %-12s | %-13s | %-16s | %-15s | %-12s | %-14s | %-15s | %-11s | %-6s | %-8s | %-10s | %-23s | %-18s | %-12s | %-18s |\n", "Date","Airline Name","Flight Number","Arrival Location","Landing Runway","Arrival Time","Departure Time","Takeoff Runway","Destination","Pilot","Copilot","Cabin crew","Maintenance Technicians","Passengers Got Off","Total Seats","Passengers Entered");
						printf("+-----------+--------------+---------------+------------------+-----------------+--------------+----------------+-----------------+-------------+--------+----------+------------+-------------------------+--------------------+--------------+--------------------+\n");
						while ((row = mysql_fetch_row(res)))
						{
							flight_detail currentflight_detail;
		                    currentflight_detail.date = row[0];
		                    currentflight_detail.airline = row[1];
		                    currentflight_detail.FlightNo = row[2];
		                    currentflight_detail.source = row[3];
		                    currentflight_detail.landingrunway = row[4];
		                    currentflight_detail.arrivalTime = row[5];
		                    currentflight_detail.departureTime = row[6];
		                    currentflight_detail.takeoffrunway = row[7];
		                    currentflight_detail.location = row[8];
		                    currentflight_detail.pilot = row[9];
		                    currentflight_detail.copilot = row[10];
		                    currentflight_detail.cabincrew = row[11];
		                    currentflight_detail.ATM = row[12];
		                    currentflight_detail.passengersGotOff = row[13];
		                    currentflight_detail.totalSeats = row[14];
		                    currentflight_detail.passengersEntered = row[15];
		                    if (atoi(row[15]) > 0)
							{
								printf("|%-10s | %-12s | %-13s | %-16s | %-15s | %-12s | %-14s | %-15s | %-11s | %-6s | %-8s | %-10s | %-23s | %-18s | %-12s | %-18s |\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14], row[15]);
							}
						}
						printf("+-----------+--------------+---------------+------------------+-----------------+--------------+----------------+-----------------+-------------+--------+----------+------------+-------------------------+--------------------+--------------+--------------------+\n");
			       		validFlight = true;
					}
					
					else
					{
			            // Flight details not found
			            cout << "Flight Number does not exist in the database." << endl;
			            cout << "Do you want to search for another flight? (1 for Yes, 0 for No): ";
		                int searchAgain;
		                cin >> searchAgain;
		                if (searchAgain != 1)
		                {
		                    validFlight = true;  // Set flag to exit the loop
		                }
           			}
			        getch();
				}
				else{
					cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
				}
	   		}
		}
	
		else if(choice==4)
		{
			string FlightNo;
			cout << endl<< "Enter Flight Number to delete: ";
			cin >> FlightNo;
			string query = "DELETE FROM flight_detail WHERE Flight_Number = '" + FlightNo + "'";
			if (mysql_query(conn, query.c_str()))
			{
				cout << mysql_error(conn) << endl;
				Sleep(3000);
			}
			else
			{
				cout << "Item deleted..." << endl
					 << endl;
			}
			Sleep(2000);
		}		
	
		else if (choice == 5)
		{
		    exit = true;
		}
		else
		{
		    cout << "Invalid choice. Please try again.\n";
		}
    }
	db_response::connectionClose();
	return 0;
}
		
	
