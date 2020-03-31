#include <iostream>
#include <fstream>

using namespace std;

class Student
{
    int rollno;
    int marks;
    char name[100];

public:
    void accept(int);
    void display();
    void modify();
    int getrno();
};

void Student::accept(int i)
{
    cout<<"\nENTER NAME OF THE STUDENT "<<i<<" : ";
    cin.ignore();
    cin.getline(name, 100);
    cout<<"ENTER ROLL NUMBER : ";
    cin>>rollno;
    cout<<"ENTER MARKS : ";
    cin>>marks;
}

void Student::display()
{
    cout<<"\t\t"<<rollno<<"\t|\t"<<name<<"\t|\t"<<marks<<"\n";
}

void Student::modify()
{
    cin.ignore();
    cout<<"Enter new name of student:- ";
    cin.getline(name, 100);
    cout<<"Enter the new marks:- ";
    cin>>marks;
}

int Student::getrno()
{
    return rollno;
}

int create(int);
void display();
int add(int);
void deleterec(int);
void modifyrec(int);

int main()
{
    int choice, counter = 0;

    while (1)
    {
        cout<<"\n\n\tSTUDENT DATABASE ::\n";
        cout<<"\n\t(1) CREATE DATABSE";
        cout<<"\n\t(2) DISPLAY RECORDS OF DATABASE";
        cout<<"\n\t(3) ADD A RECORD";
        cout<<"\n\t(4) DELETE A RECORD";
        cout<<"\n\t(5) MODIFY A RECORD";
        cout<<"\n\t(6) EXIT";
        cout<<"\nENTER YOUR CHOICE : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            counter = create(counter);
            break;

        case 2:
        	if(counter == 0)
        	{
        		cout<<"\nPLEASE CREATE A DATABSE FIRST !\n";
        	}
        	else
        	{
        		display();
        	}
            break;

        case 3:
            if (counter == 0)
            {
            	cout<<"\nPLEASE CREATE A DATABSE FIRST !\n";
            }
            else
            {
                counter = add(counter);
            }
            break;


        case 4:
            if (counter == 0)
            {
            	cout<<"\nPLEASE CREATE A DATABSE FIRST !\n";
            }
            else
            {
                deleterec(counter);
            }
            break;

        case 5:
            if (counter == 0)
            {
            	cout<<"\nPLEASE CREATE A DATABSE FIRST !\n";
            }
            else
            {
                modifyrec(counter);
            }
            break;

        case 6:
            return 0;

        default:
            cout<<"\nINVALID CHOICE !!!\n";
            break;
        }
    }
    return 0;
}

int create(int counter)
{
    Student m;
    ofstream fout("records.txt", ios::binary | ios::out);
    counter = 0;
    int n,i;
    cout<<"ENTER NUMBER OF RECORDS TO ADD : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        m.accept(i+1);
        fout.write((char *)&m, sizeof(m));
        counter++;
    }
    fout.close();
    return counter;
}

void display()
{
    int i;
    Student m;
	ifstream fin("records.txt", ios::binary | ios::in);
	cout<<"\n-----------------------------------------------------------------------\n";
	cout<<"SR NO.\t\tROLL NO\t\tNAME\t\tMARKS"<<endl;
	cout<<"\n-----------------------------------------------------------------------\n";
	i = 1;
	while (fin.read((char *)&m, sizeof(m)))
	{
		cout<<"  "<<i<<"  ";
		m.display();
		i++;
	}
	fin.close();
}

int add(int counter)
{
    Student m;
    ofstream fout("records.txt", ios::binary | ios::app);
    cout<<"ENTER DETAILS OF THE NEW RECORD "<<endl;
    m.accept(1);
    fout.write((char *)&m, sizeof(m));
    fout.close();
    counter++;
    cout<<"RECORD ADDED SUCCESSFULLY"<<endl;
    return counter;
}

void deleterec(int counter)
{
    Student m;
    int flag;
    int rno;
    ifstream fin("records.txt", ios::binary | ios::in);
    cout<<"ENTER ROLL NO OF RECORD TO DELETE ";
    cin>>rno;
    flag = 0;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (rno == m.getrno())
        {
            flag = 1;
            counter--;
            break;
        }
    }
    fin.close();
    if (!flag)
        cout<<"\nRECORD WITH ROLL NO "<<rno<<" DOES NOT EXIST"<<endl;
    else
    {
        ofstream fout("temp.txt", ios::binary | ios::out);
        ifstream fin("records.txt", ios::binary | ios::out);
        fin.seekg(0, ios::beg);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof())
        {
            if (m.getrno() != rno)
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout<<"Record with roll number "<<rno<<" deleted successfully"<<endl;
        remove("records.txt");
        rename("temp.txt", "records.txt");
    }
}

void modifyrec(int counter)
{
    Student m;
    int rno;
    int flag;
    ifstream fin("records.txt", ios::binary | ios::in);
    cout<<"ENTER ROLL NO OF RECORD TO EDIT ";
    cin>>rno;
    flag = 0;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (rno == m.getrno())
        {
            flag = 1;
            counter--;
            break;
        }
    }
    fin.close();
    if (!flag)
        cout<<"\nRECORD WITH ROLL NO "<<rno<<" DOES NOT EXIST"<<endl;
    else
    {
        ofstream fout("temp.txt", ios::binary | ios::out);
        ifstream fin("records.txt", ios::binary | ios::out);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof())
        {
            if (m.getrno() == rno)
            {
                m.modify();
                fout.write((char *)&m, sizeof(m));
            }
            else
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout<<"RECORD WITH ROLL NO "<<rno<<" SUCCESSFULLY EDITED"<<endl;
        remove("records.txt");
        rename("temp.txt", "records.txt");
    }
}

/*


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 1
ENTER NUMBER OF RECORDS TO ADD : 3

ENTER NAME OF THE STUDENT 1 : PRAJWAL
ENTER ROLL NUMBER : 33
ENTER MARKS : 100

ENTER NAME OF THE STUDENT 2 : VIDHI
ENTER ROLL NUMBER : 34
ENTER MARKS : 99

ENTER NAME OF THE STUDENT 3 : ATHARV
ENTER ROLL NUMBER : 35
ENTER MARKS : 69


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 2

-----------------------------------------------------------------------
SR NO.		ROLL NO		NAME		MARKS

-----------------------------------------------------------------------
  1  		33	|	PRAJWAL	|	100
  2  		34	|	VIDHI	|	99
  3  		35	|	ATHARV	|	69


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 3
ENTER DETAILS OF THE NEW RECORD

ENTER NAME OF THE STUDENT 1 : SALONI
ENTER ROLL NUMBER : 51
ENTER MARKS : 98
RECORD ADDED SUCCESSFULLY


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 2

-----------------------------------------------------------------------
SR NO.		ROLL NO		NAME		MARKS

-----------------------------------------------------------------------
  1  		33	|	PRAJWAL	|	100
  2  		34	|	VIDHI	|	99
  3  		35	|	ATHARV	|	69
  4  		51	|	SALONI	|	98


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 4
ENTER ROLL NO OF RECORD TO DELETE 35
Record with roll number 35 deleted successfully


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 2

-----------------------------------------------------------------------
SR NO.		ROLL NO		NAME		MARKS

-----------------------------------------------------------------------
  1  		33	|	PRAJWAL	|	100
  2  		34	|	VIDHI	|	99
  3  		51	|	SALONI	|	98


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 5
ENTER ROLL NO OF RECORD TO EDIT 33
Enter new name of student:- PRAJWAL
Enter the new marks:- 90
RECORD WITH ROLL NO 33 SUCCESSFULLY EDITED


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 2

-----------------------------------------------------------------------
SR NO.		ROLL NO		NAME		MARKS

-----------------------------------------------------------------------
  1  		33	|	PRAJWAL	|	90
  2  		34	|	VIDHI	|	99
  3  		51	|	SALONI	|	98


	STUDENT DATABASE ::

	(1) CREATE DATABSE
	(2) DISPLAY RECORDS OF DATABASE
	(3) ADD A RECORD
	(4) DELETE A RECORD
	(5) MODIFY A RECORD
	(6) EXIT
ENTER YOUR CHOICE : 6

 */


