/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 2
 PROBLEM STATEMENT : Implement priority queue as a ADT using SLL for
 	 	 	 	 	 servicing patients in the hospital with priorities
 	 	 	 	 	 as (1)serious (2)medium (3)general
============================================================================
*/
#include <iostream>
#include <string.h>
#include "queue.h"
#include "queue.cpp"
using namespace std;


struct Patient
{
	int id;
	string name;
	string disease;
	string bloodgroup;
	char mobile[11];
	int priority;
};

class database
{
	Patient P,Ptemp;
	queue<Patient> que1;
	node<Patient> *temp;
public:
	void addRecord();
	void servePatient();
	void displayRecords();
};

void database::addRecord()
{
	int len,i;
	cout<<"\nEnter Patient Name : ";
	cin>>P.name;
	while(1)							//Name validation
	{
		len=P.name.length();
		for(i=0;i<len;i++)
		{
			if(!isalpha(P.name[i]))
			{
				cout<<"INVALID NAME !!!\nEnter name again : ";
				cin>>P.name;
				continue;
			}
		}
		break;
	}

	cout<<"Enter ID : ";
	cin>>P.id;

	cout<<"Enter disease : ";
	cin>>P.disease;

	cout<<"Enter bloodgroup : ";
	cin>>P.bloodgroup;

	cout<<"Enter mobile : ";
	cin>>P.mobile;
	while(1)							//Number validation
	{
		len=strlen(P.mobile);
		if(len!=10)
		{
			cout<<"INVALID NUMBER !!!\nEnter mobile number again : ";
			cin>>P.mobile;
			continue;
		}
		for(i=0;i<len;i++)
		{
			if(isalpha(P.mobile[i]))
			{
				cout<<"INVALID NUMBER !!!\nEnter mobile number again : ";
				cin>>P.mobile;
				continue;
			}
		}
		break;
	}


	if(P.disease=="cancer" || P.disease=="accident" || P.disease=="heartattack")
	{
		P.priority=3;
	}
	else if(P.disease=="kidneystones" || P.disease=="typhoid" || P.disease=="cholera" || P.disease=="dengue" || P.disease=="malaria" )
	{
		P.priority=2;
	}
	else
	{
		P.priority=1;
	}
	que1.enqueue(P);
}

void database::servePatient()
{
	que1.dequeue();
}



void database::displayRecords()
{
	que1.display();

}



int main() {


	database patientobj;
	int choice;
	do
	{
		cout<<"\n\n\t\t<----HOSPITAL DATABASE---->";
		cout<<"\n\n\t\tMENU::\n";
		cout<<"\n\t(1)Add a  Patient Record";
		cout<<"\n\t(2)Serve a Patient";
		cout<<"\n\t(3)EXIT";
		cout<<"\n\t\tEnter your Choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1://add record
			patientobj.addRecord();
			patientobj.displayRecords();
			break;

		case 2://serve a patient
			patientobj.servePatient();
			patientobj.displayRecords();
			break;

		case 3://EXIT
			return 0;

		default://Invalid
			cout<<"\n\n\tINVALID CHOICE !!!";
			break;
		}
	}while(1);


	return 0;
}


/*OUTPUT





		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 1

Enter Patient Name : Prajwal
Enter ID : 23245
Enter disease : cholera
Enter bloodgroup : O+
Enter mobile : 9998889998


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Prajwal			23245		cholera			O+		9998889998


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 1

Enter Patient Name : Anuj
Enter ID : 23252
Enter disease : cancer
Enter bloodgroup : AB+
Enter mobile : 9876987698


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Prajwal			23245		cholera			O+		9998889998
Anuj			23252		cancer			AB+		9876987698


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 1

Enter Patient Name : Tanishk
Enter ID : 23247
Enter disease : fever
Enter bloodgroup : B+
Enter mobile : 7878987898


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Prajwal			23245		cholera			O+		9998889998
Anuj			23252		cancer			AB+		9876987698
Tanishk			23247		fever			B+		7878987898


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 1

Enter Patient Name : Sakshee
Enter ID : 23244
Enter disease : typhoid
Enter bloodgroup : AB+
Enter mobile : 9876543219


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Prajwal			23245		cholera			O+		9998889998
Anuj			23252		cancer			AB+		9876987698
Tanishk			23247		fever			B+		7878987898
Sakshee			23244		typhoid			AB+		9876543219


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 2
Patient Served
patient Details:
NAME 	 : Anuj
ID	 	 : 23252
Illness  : cancer

		UPDATED RECORD ::


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Prajwal			23245		cholera			O+		9998889998
Tanishk			23247		fever			B+		7878987898
Sakshee			23244		typhoid			AB+		9876543219


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 2
Patient Served
patient Details:
NAME 	 : Prajwal
ID	 	 : 23245
Illness  : cholera

		UPDATED RECORD ::


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Tanishk			23247		fever			B+		7878987898
Sakshee			23244		typhoid			AB+		9876543219


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 2
Patient Served
patient Details:
NAME 	 : Sakshee
ID	 	 : 23244
Illness  : typhoid

		UPDATED RECORD ::


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Tanishk			23247		fever			B+		7878987898


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 1

Enter Patient Name : Saloni
Enter ID : 23251
Enter disease : accident
Enter bloodgroup : B+
Enter mobile : 7897897898


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Tanishk			23247		fever			B+		7878987898
Saloni			23251		accident		B+		7897897898


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 2
Patient Served
patient Details:
NAME 	 : Saloni
ID	 	 : 23251
Illness  : accident

		UPDATED RECORD ::


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------
Tanishk			23247		fever			B+		7878987898


		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 2
Patient Served
patient Details:
NAME 	 : Tanishk
ID	 	 : 23247
Illness  : fever

		UPDATED RECORD ::


--------------------------------------------------------------------------------------------------------
Name			ID		Illness			Bloodgroup	Contact No.

--------------------------------------------------------------------------------------------------------

					<empty>

		<----HOSPITAL DATABASE---->

		MENU::

	(1)Add a  Patient Record
	(2)Serve a Patient
	(3)EXIT
		Enter your Choice : 3



*/
