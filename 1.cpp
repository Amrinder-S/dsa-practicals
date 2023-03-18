#include <iostream>
#include <conio.h>
using namespace std;
//working screenshot https://i.imgur.com/APnh5up.png
//! Function Declarations
void inputArray(int* array);
void printArray(int* array);
void deleteValue(int* array);
void insertValue(int* array);
void searchValue(int* array);
void Exit(int* x);

int arraySize;
int main() {
int arr[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void (*menuFunctions[6])(int*) = {inputArray, printArray, deleteValue, insertValue, searchValue, Exit};
string menuOptions[6] = {"Input Array", "Display Array", "Delete Value", "Insert Value", "Search Value", "Exit"};
int option;
while(1)
{
	for(int i=0;i<6;i++)
	{
		cout<<i+1<<". "<<menuOptions[i]<<endl;
	}
	cout<<"Enter an option:";
	cin>>option;
	if(option>0 && option<7)
		{
		cout<<"\n--------------------------------------------------------\n";
		menuFunctions[option-1](arr);
		}
	else
		cout<<"Invalid option selected.";
	cout<<"\n--------------------------------------------------------\n";
}

}




//! Function Definitions
void inputArray(int* array)
{
    int size;
    cout<<"Enter the size of the array (max 30):";
    cin>>size;
    arraySize = size;
    for(int i = 0; i < size;i++) {
        system("cls");
        cout<<"Enter element "<<i+1<<" of the array: ";
        cin>>array[i];
    }
}

void printArray(int* array)
{
    for(int i=0;i<arraySize;i++)
        cout << array[i] << " ";
    cout<<endl;
}

void insertValue(int* array){
printArray(array);
int value, index;
cout<<"\nEnter the index you want to insert the value at: ";
cin>>index;
cout<<"Enter the Value you want to insert on position "<<index<<" of the array:";
cin>>value;
    for(int i=arraySize;i>=index-1;i--)
        array[i] = array[i-1];
    array[index-1] = value;
arraySize++;
cout<<"Value inserted!\n Array:";
printArray(array);
}

void deleteValue(int* array)
{
printArray(array);
    int index;
    cout<<"\nEnter the index you want to delete: ";
    cin>>index;
    for(int i=index-1;i<arraySize;i++)
        array[i] = array[i+1];
    arraySize=arraySize-1;
    cout<<"Value deleted!\nArray:";
printArray(array);
}

void searchValue(int* array)
{
	int index,val, found=0;
	cout<<"Enter the value you wish to find: ";
	cin>>val;
	for(int i=0;i<arraySize;i++)
	{
		if(array[i]==val)
			{
				found=1;
				index=i;
			}
	}
	if(found)
		cout<<"Value "<<val<<" found at index "<<index+1<<" in the array:\n";
	else
		cout<<"Value "<<val<<" was not found in the array:\n";
	printArray(array);
}

void Exit(int* x)
{
	exit(0);
}