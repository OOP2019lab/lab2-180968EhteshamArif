#include<iostream>
#include<fstream>
#include "struct2.h"
using namespace std;
//Display function to Display all
void Display(gitHubUser* arr, int size)
{
	  cout<<endl<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"The First name of User "<<i+1<<" is :"<<arr[i].firstname<<endl;
		cout<<"The Username of User "<<i+1<<" is :"<<arr[i].username<<endl;
		cout<<"The Email for User "<<i+1<<" is :"<<arr[i].email<<endl;
		for(int j=0;j<arr[i].foldercount;j++)
		{
			cout<<"The Folders for User are "<<arr[i].gitHubFolders[j]<<endl;
		}
		
	}
}
//fucntion to read data
void readDataFromFile( gitHubUser * users, string filepath)
{
	users=new gitHubUser[2];
	ifstream fin;
	fin.open(filepath);
	if(!fin)
	{
		cout<<"--------Could not load File-------"<<endl;
	
	}
	else
	{
		int size=0;
		int folder;
		fin >> size;
		//cout<<size;
		for(int i=0;i<size;i++)
		{
			fin>>users[i].firstname;
			fin>>users[i].username;
			fin>>users[i].email;
			fin>>users[i].foldercount;
			folder=users[i].foldercount;
			users[i].gitHubFolders=new string[folder];
			fin.ignore();
			for(int j=0;j<folder;j++)
			{
				getline(fin, users[i].gitHubFolders[j]);
			}
		
		}
		Display(users,size);
	}



}
//respective main
int main()
{
	gitHubUser arr[2];
	string filepath="myfile.txt";

	readDataFromFile(arr,filepath);
}