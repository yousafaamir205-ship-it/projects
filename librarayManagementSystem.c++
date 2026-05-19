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
    if (top=-1)
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
    if(front==100){
        cout<<"queue is full";
    }
    if(front==-1){
    front =0;
    student[++rear]=name;
}
void display(){ 
    if (front==-1||front>rear){
        cout<<"waiting list is empty";
    }
    for (int i=front;i>=rear;i++){
        cout<<student[i]<<endl;
    }
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
    while (temp->next!=NULL)
    {
        cout<<temp->books.title<<endl;
        temp=temp->next;
    }
    
}
};
class library{
public:
vector<Book>book;
returnedStack returnedB;
waitqueue waitb;
BorrowedList borrowedb;
void addbook(){
    int id;
    string title;
    cout<<"enter id:";
    cin>>id;
    cout<<"enter book title:";
    getline(cin,title);
    book.push_back(Book(id,title));
    cout<<"book added! ";
}
void showemptybooks(){
    if (book.empty()){
        cout<<"no book added";
        return;
    }
    cout<<"book list";
    for(auto b :book){
        cout<<b.title<<endl;
    }
}
void borrowBook(){
    int id;
    string student;
    cout<<"enter id:";
    cin>>id;
    cout<<"enter book title:";
    getline(cin,student);
    bool found=false;
    for ( auto b : book)
    {
        
    }
    
}
};