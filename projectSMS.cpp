#include<bits/stdc++.h>
using namespace std;
//Montasir OPI//
string arr1[20],arr2[20],arr3[20],arr4[20],arr5[20];
int total = 0;
void enter()
{
    int choice;
    cout<<"How many student do you want to enter"<<endl;
    cin >> choice;
    if(total ==0)
    {

    total=total+choice;
    for(int i=0;i<choice;i++)
    {
        cout<<"\n enter data of students" <<i+1<<endl<<endl;
        cout<<"Enter name:"<<endl;
        cin>>arr1[i];
        cout<<"Enter roll: "<<endl;
        cin>>arr2[i];
        cout<<"Enter semester: "<<endl;
        cin>>arr3[i];
        cout<<"Enter technology: "<<endl;
        cin>>arr4[i];
        cout<<"Enter phoneNumber: "<<endl;
        cin>>arr5[i];

    }
    }
    else{
        for(int i=total;i<total+choice;i++)
    {
        cout<<"\n enter data of students" <<i+1<<endl<<endl;
        cout<<"Enter name:"<<endl;
        cin>>arr1[i];
        cout<<"Enter roll: "<<endl;
        cin>>arr2[i];
        cout<<"Enter semester: "<<endl;
        cin>>arr3[i];
        cout<<"Enter technology: "<<endl;
        cin>>arr4[i];
        cout<<"Enter phoneNumber: "<<endl;
        cin>>arr5[i];

    }
    total=total+choice;
    }

}
void show()
{
    for(int i=0;i<total;i++)
    {
        cout<<"data of student: "<<i+1<<endl<<endl;
        cout<<"Name: "<<arr1[i]<<endl;
        cout<<"Roll: "<<arr2[i]<<endl;
        cout<<"Semester: "<<arr3[i]<<endl;
        cout<<"Technology: "<<arr4[i]<<endl;
        cout<<"phoneNumber: "<<arr5[i]<<endl;

    }

}
void searchrecord()
{
    string rollno;
    cout<<"Enter roll of student which you want to search"<<endl;
    cin>>rollno;
    for(int i=0;i<total;i++)
    {
        if(rollno==arr2[i])
            cout<<"data of student: "<<i+1<<endl<<endl;
            cout<<"Name: "<<arr1[i]<<endl;
            cout<<"Roll: "<<arr2[i]<<endl;
            cout<<"Semester: "<<arr3[i]<<endl;
            cout<<"Technology: "<<arr4[i]<<endl;
            cout<<"phoneNumber: "<<arr5[i]<<endl;
    }

}
void update()
{
    string rollno;
    cout<<"Enter roll of student which you want to search"<<endl;
    cin>>rollno;
    for(int i=0;i<total;i++)
    {
       if(rollno==arr2[i])
            cout<<"Previous Data"<<endl<<endl;
            cout<<"data of student: "<<i+1<<endl<<endl;
            cout<<"Name: "<<arr1[i]<<endl;
            cout<<"Roll: "<<arr2[i]<<endl;
            cout<<"Semester: "<<arr3[i]<<endl;
            cout<<"Technology: "<<arr4[i]<<endl;
            cout<<"phoneNumber: "<<arr5[i]<<endl;
            cout<<"\n Enter new Data"<<endl;
            cout <<"\n Enter Name: "<<endl;
            cin>>arr1[i];
            cout<<"\n Enter roll:"<<endl;
            cin>>arr2[i];
            cout<<"\n Enter semester: "<<endl;
            cin>>arr3[i];
            cout<<"\n Enter technology: "<<endl;
            cin>>arr4[i];
            cout<<"\n Enter Phonenumber: "<<endl;
            cin>>arr5[i];

    }


}
void deleterecord()
{
    int a;
    cout<<"Press 1 to delete full record"<<endl;
    cout<<"Press 2 to delete specific record"<<endl;
    cin>>a;
    if(a==1)
    {
        total=0;
        cout<<"All Record is Deleted"<<endl;
    }
    else if(a==2)
    {
        string rollno;
        cout<<"Enter rollno which you want to delete"<<endl;
        cin>>rollno;
        for(int i=0;i<total;i++)
        {
            //hard part//
            if(rollno==arr2[i])
            {
                for(int j=i;j<total;j++)
                {
                    arr1[j]=arr1[j+1];
                    arr2[j]=arr2[j+1];
                    arr3[j]=arr3[j+1];
                    arr4[j]=arr4[j+1];
                    arr5[j]=arr5[j+1];
                }
                total --;
                cout<<"your required record is deleted..."<<endl;

            }
        }
    }

}

int main()
{

    int value;
    while(true)
    {
        cout<< "press 1 to enter date"<<endl;
        cout<< "press 2 to show date"<<endl;
        cout<< "press 3 to search date"<<endl;
        cout<< "press 4 to update date"<<endl;
        cout<< "press 5 to delete date"<<endl;
        cout<< "press 6 to exit"<<endl;

        cin>> value;
        switch(value)
        {
        case 1:
            enter();
            break;
        case 2:
            show();
            break;
        case 3:
            searchrecord();
            break;
        case 4:
            update();
            break;
        case 5:
            deleterecord();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid keyword"<<endl;
            break;
        }

    }

    return 0;
}
