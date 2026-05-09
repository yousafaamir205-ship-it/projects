#include<iostream>
using namespace std;
class Book{
    int BookID;
    string title;
    public:
    Book (int id,string h){
        BookID=id;
        title=h;
    }
};
class ReturnedBook{
Book returnedBook[100];
int top;
public:
ReturnedBook(){
    top=-1;
}
void addReturnedBook(Book b){
    if(top==99){
        cout<<"reurned book record is full";
        return;
    }
    returnedBook[++top]=b;
}
void showReturnedBook(){
    if(top=-1){
        cout<<"returned book is empty";
        return;
    }
    cout<<"recently returned book are: ";
    for(int i=top;i>=0;i++){
        cout<<returnedBook[i].title<<endl;
    }
}
};
class WaitingList{
string student[100];
int front,rear;
public:
WaitingList(){
    front=rear=-1;
}
void addStudentsTowaitinglist (string name){
    if (rear==99){
        cout<<"no space left"<<endl;
        return;
    }
    student[++rear]=name;
}
void showWaitinglist(){
    if (front=-1 || front>rear){
        cout<<"waiting list is empty"<<endl;
    }
    for (int i=front;i<=rear;i++){
        cout<<student[i]<<endl;
    }
}

};