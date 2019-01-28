#include<iostream>
#include"struct.h"
using namespace std;
//comparing two github users 
bool comparison(gitHubUser a,gitHubUser b)
{
	if(a.firstname==b.firstname&&a.email==b.email&&a.foldercount==b.foldercount&&a.username==b.username&&a.password==b.password)
	{
		return true;
	}
	else 
		return false;
}
//checking is the string entered by user exists in githubusers
bool exists(gitHubUser* arr,int size,string userName)
{
	for(int i=0;i<size;i++)
	{
			if(arr[i].username==userName)
	        {
				return true;
	        }
			else
				return false;	
	}
}
//taking input from user
void inputFromUser(gitHubUser* arr, int size)
{
	     cout<<endl<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"Enter the First name for User "<<i+1<<" :"<<endl;
		cin>>arr[i].firstname;
		cout<<"Enter the Username for User "<<i+1<<" :"<<endl;
		cin>>arr[i].username;
		if(exists(arr,size,arr[i+1].username)==true)
		{
		 cout<<"Username already exists! Please enter the username again :"<<endl;
		 cin>>arr[i].username;
		}
		cout<<"Enter the Email for User "<<i+1<<" :"<<endl;
		cin>>arr[i].email;
		cout<<"Enter the Password for User "<<i+1<<" :"<<endl;
		cin>>arr[i].password;
		cout<<"Enter the Folder Count for User "<<i+1<<" :"<<endl;
		cin>>arr[i].foldercount;
	}
}
//function to display all the factors
void Display(gitHubUser* arr, int size)
{
	  cout<<endl<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"The First name of User "<<i+1<<" is :"<<arr[i].firstname<<endl;
		cout<<"The Username of User "<<i+1<<" is :"<<arr[i].username<<endl;
		cout<<"The Email for User "<<i+1<<" is :"<<arr[i].email<<endl;
		cout<<"The Password for User "<<i+1<<" is :"<<arr[i].password<<endl;
		cout<<"The Folder Count for User "<<i+1<<" is :"<<arr[i].foldercount<<endl;
	}
}
//search user by typing its username
gitHubUser* searchUser ( gitHubUser* users, int size, string userName)
{
	for(int i=0;i<size;i++)
	{
		if(users[i].username==userName)
		{
		  return &users[i];
		}
		else
			return nullptr;
	}
}
//respective main
int main()
{
	int size;
	string userName;
	gitHubUser *arr;
	cout<<"Please enter the number of users :";
	cin>>size;
	arr=new gitHubUser[size];
	inputFromUser(arr,size);
	Display(arr,size);
	for(int i=0;i<size;i++)
	{
	   if(comparison(arr[i],arr[i+1])==true)
	   {
		   cout<<"----------The Users are same---------"<<endl;

	   }
	   else
		   cout<<"------The Users are not same------"<<endl;
	}
	cout<<"You can search a user by typing his/her username, try typing the username :";
	cin>>userName;
	arr=searchUser(arr,size,userName);
	delete[]arr;
	return 0;
}

