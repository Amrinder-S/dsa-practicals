#include<stdio.h>
struct node {
    struct node* next;
    int data;
    struct node* prev;
};

void displayOptions();
void selectOption();
int main() //Main function
{
int option;
while(1)
{
displayOptions();
selectOption();
}
    return 0;
} //end of main function

void displayOptions(){
printf("\n--------------------------------\n");
        char options[6][47] = {
        "Insert at Beginning",
        "Insert at the end",
        "Delete from the beginning",
        "Delete from the end",
        "Traverse and display the elements",
        "Search elements from the circular linked list"
    };
    for(int i = 1; i <= 6; i++)
        printf("%d. %s.\n",i, options[i-1]);
} //end of displayOptions
void insertAtBeginning()
{
    printf("Insert at Beginning");
} //end of insertAtBeginning
void insertAtEnd()
{
    printf("Insert at end");
} //end of insertAtEnd
void deleteFromBeginning(){
    printf("Delete from beginning");
}// end of deleteFromBeginning
void deleteFromEnd(){
    printf("Delete from end");
}//end of deleteFrom
void traverseAndDisplay(){
    printf("Traverse and display");
} //end of traverseAndDisplay
void searchAndDisplay(){
printf("Search and display the elements");
} //end of searchAndDisplay
void selectOption()
{
printf("\n--------------------------------\n");
    scanf("%c", NULL); // to avoid scanning of \n from previous printf
    void (*func[6])(void) = {insertAtBeginning, insertAtEnd, deleteFromBeginning, deleteFromEnd, traverseAndDisplay, searchAndDisplay};
    int option=0;
    printf("Enter the number of the option: ");
    scanf("%d", &option);
    func[option-1]();
} //end of selectOption