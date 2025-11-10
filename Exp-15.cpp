#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// ---------------- CLASS DEFINITION ----------------
class Hotel
{
private:
    int roomNo;
    string customerName;
    int days;
    float ratePerDay;

public:
    // Default Constructor
    Hotel() : roomNo(0), customerName(""), days(0), ratePerDay(0.0) {}

    // Parameterized Constructor
    Hotel(int r, string n, int d, float rate)
    {
        roomNo = r;
        customerName = n;
        days = d;
        ratePerDay = rate;
    }

    // Encapsulation: Setters and Getters
    void setData()
    {
        cout << "\nEnter Room No: ";
        cin >> roomNo;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, customerName);
        cout << "Enter No. of Days Stayed: ";
        cin >> days;
        cout << "Enter Rate per Day: ";
        cin >> ratePerDay;
    }

    void getData()
    {
        cout << left << setw(10) << roomNo
             << setw(20) << customerName
             << setw(10) << days
             << setw(10) << ratePerDay
             << setw(10) << totalBill() << endl;
    }

    // Function Overloading for bill calculation
    float totalBill()
    {
        return days * ratePerDay;
    }

    float totalBill(float discountPercent)
    {
        float amount = totalBill();
        float discount = (amount * discountPercent) / 100;
        return amount - discount;
    }

    // Operator Overloading
    bool operator==(int r)
    {
        return roomNo == r;
    }

    // File handling
    void saveToFile()
    {
        ofstream fout("hotel_data.txt", ios::app);
        fout << roomNo << "," << customerName << "," << days << "," << ratePerDay << "\n";
        fout.close();
    }
};

// ---------------- MAIN FUNCTION ----------------
int main()
{
    Hotel h[10];
    int n;

    cout << "Enter number of customers: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Enter details for Customer " << i + 1 << " ---\n";
        h[i].setData();
        h[i].saveToFile(); // Saving each record
    }

    cout << "\n--- Hotel Billing Details ---\n";
    cout << left << setw(10) << "RoomNo" << setw(20) << "Name" << setw(10)
         << "Days" << setw(10) << "Rate" << setw(10) << "Bill" << endl;

    for (int i = 0; i < n; i++)
    {
        h[i].getData();
    }

    // Demonstrate function overloading
    int searchRoom;
    cout << "\nEnter Room No to find discounted bill: ";
    cin >> searchRoom;

    for (int i = 0; i < n; i++)
    {
        if (h[i] == searchRoom) // Operator Overloading
        {
            cout << "Enter discount percent: ";
            float d;
            cin >> d;
            cout << "Discounted Bill: " << h[i].totalBill(d) << endl;
        }
    }

    cout << "\nData saved successfully in 'hotel_data.txt'\n";

    return 0;
}
