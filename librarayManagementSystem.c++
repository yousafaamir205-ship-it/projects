#include<iostream>
#include<vector>
using namespace std;
class Book{
public:
int data;
string title;
Book(int val=0, string name=" "){
data=val;
title=name;
}
};
class returnedStack{
    public:
Book book[100];
int top;
returnedStack(){
    top=-1;
}
void add(Book b){
if (top==99)
{
    cout<<"stack is full";
    return;
}
book[++top]=b;
}
void display(){
    if (top==-1)
    {
        cout<<"no book returned";
    }
    cout<<"returned books are: ";
    for(int i=top;i>=0;i--){
        cout<<book[i].title<<endl;
    }
}

};
class waitqueue{
string student[100];
int front,rear;
public:
waitqueue(){
    front=rear=-1;
}
void add(string name){
    if(rear==100){
        cout<<"queue is full";
    }
    if(front==-1){
    front =0;
    
}
student[++rear]=name;
}
void display(){ 
    if (front==-1||front>rear){
        cout<<"waiting list is empty";
    }
    for (int i=front;i<=rear;i++){
        cout<<student[i]<<endl;
    }
}
};
class Node{
    public:
    Book books;
    Node* next;
    Node* prev;
    
    Node (Book b){
books=b;
next=prev=NULL;
    }

};
class BorrowedList{
    Node *head;
    public:
    BorrowedList(){
        head=NULL;
    }
void add (Book b){
    Node *newnode=new Node (b);
    if (head==NULL){
        head=newnode;
        return;

    }
    Node *temp=head;
while (temp->next !=NULL){
temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
}
void display(){
    if (head==NULL){
        cout<<"no book borrowed";

    }
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->books.title<<endl;
        temp=temp->next;
    }
    
}
};
class library{
public:
vector<Book>obj;
returnedStack returnedBook;
waitqueue waitinglist;
BorrowedList borrowBook;
library(){

}
void addbook(){
    int id;
    string title;
    cout<<"enter ID";
    cin>>id;
    cout<<"enter title:";
    cin.ignore();
    getline(cin,title);
    obj.push_back(Book(id,title));

}
void showBook(){
    if (obj.empty())
    {
        cout<<"no books added";
        return;
    }
    cout<<"books list: ";
    for ( int i=0;i<obj.size();i++)
    {
        cout<<obj[i].data<<obj[i].title<<endl;
    }
}
    void borrowB(){
        int id;
        string student;
        cout<<"enetr id: ";
        cin>>id;
        cout<<"enter student name: ";
        cin.ignore();
        getline(cin,student);
        bool found=false;
        for (int i=0;i<obj.size();i++)
        {
        if (obj[i].data==id)
        {
            cout<<student<<"borrowed: "<<obj[i].title<<endl;
         borrowBook.add(obj[i]);
         found=true;
         break;
        }
        
        }
        if (!found)
        {
           cout<<"book was not found: ";
           return;
        }
    }
    void returnBook(){
        int id;
        cout<<"enter id: ";
        cin>>id;
        for ( int i=0;i<obj.size();i++)
        {
            if (obj[i].data==id)
            {
                returnedBook.add(obj[i]);
                return;
            }
            
        }
        cout<<"invalid ";
    }
    void showRBooks(){
        returnedBook.display();
    }
    void showBbooks(){
        borrowBook.display();
    }
    void showWaitingList(){
        waitinglist.display();
    }
};
int main(){
    library n1;
     int choice;
    
    do
    {
        cout<<"\n library management system\n.";
    cout<<"inter 1 to add book\n ";
    cout<<"inter 2 to show book\n ";
    cout<<"inter 3 to borrow book\n ";
    cout<<"inter 4 to return book\n ";
    cout<<"inter 5 to show borrrowed book book\n ";
    cout<<"inter 6 to show returned  book\n ";
    cout<<"inter 7 to add show waiting list\n ";
   
    cin>>choice;
        switch (choice)
    {
    case 1:
    n1.addbook();
    break;
    case 2:
    n1.showBook();
    break;
    case 3:
    n1.borrowB();
    break;
    case 4:
    n1.returnBook();
    break;
    case 5:
    n1.showBbooks();
    break;
    case 6:
    n1.showRBooks();
    break;
    case 7:
    n1.showWaitingList();
    break;
    }
    } while (choice!=0);
}