#include<iostream>
#include<iomanip> 
using namespace std;

int main(){	
	//ประกาศตัวแปรและคำนวณ	
	int year = 1;

	//ประกาศรับค่า-----------------------------------
	double initial_loan;
	cout << "Enter initial loan: ";
	cin >> initial_loan;

	double rate;
	cout << "Enter interest rate per year (%): ";
	cin >> rate;

	double can_pay;
	cout << "Enter amount you can pay per year: ";
	cin >> can_pay;
	// ให้เงินต้นเท่ากับค่าที่เพิ่มเข้ามาค่าแรก
	double prevbalance = initial_loan;
	//-----------------------------------------------

	//หัวข้อ-----------------------------------
	// setw(value) ระยะห่างช่องจากด้านซ้าย
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	//---------------------------------------

	
	//จัดตาราง, Loop ต่อเมื่อเงินก่อนก่อนหน้ายังมากกว่า 0
	while(prevbalance > 0){
		// คำนวณดอกเบี้ยตามเรทที่เพิ่มเข้ามา
		double interest = prevbalance * (rate/100);
		// เงินรวมดอกเบี้ย
		double total = prevbalance + interest;
		// เงินที่ต้องจ่ายมีเท่าไหร่ ถ้า total < can_pay ให้จ่ายตาม total
		double payment = (total < can_pay) ? total : can_pay;
		// เงินล่าสุดหลังจากทำธุรกรรมแล้ว
		double newbalance = total - payment;
		// กำหนดค่าทศนิมยมให้คงที่ ที่ 2 ตำแหน่ง
		cout << fixed << setprecision(2);
		// setw(value) ระยะห่างช่องจากด้านซ้าย---------
		cout << setw(13) << left << year; 
		cout << setw(13) << left << prevbalance;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << payment;
		cout << setw(13) << left << newbalance;
		//-----------------------------------------
		
		// เว้นบรรทัด
		cout << "\n";
		// รับค่าใหม่ prevbalance เป็นค่าก่อนหน้า	
		prevbalance = newbalance;
		// บวกปีเพิ่มขึ้นทีละ1
		year++;
	}
	
	return 0;
}
