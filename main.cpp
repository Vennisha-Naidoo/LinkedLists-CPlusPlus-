#include <iostream>

using namespace std;

int Options(){

    int Choice;
    cout<<"Select ONE Option (Numbers only): "<<endl;
    cout<<" "<<endl;
    cout<<"1: Add Data"<<endl;
    cout<<"2: Delete Data"<<endl;
    cout<<"3: Display Data List"<<endl;
    cout<<"4: Exit"<<endl;

    cout<<"Your Choice: ";
    cin>>Choice;

    return Choice;
}

int AddOptions(){
    int AddDataOption;
    cout<<"Select ONE Add Option (Numbers only): "<<endl;
    cout<<" "<<endl;
    cout<<"1: First Node"<<endl;
    cout<<"2: At a Position"<<endl;
    cout<<"3: Last Node"<<endl;
    cout<<"4: Exit"<<endl;

    cout<<"Your Choice: ";
    cin>>AddDataOption;

    return AddDataOption;
}//end of AddOptions function

int DeleteOptions(){
    int DeleteDataOption;
    cout<<"Select ONE Delete Option (Numbers only): "<<endl;
    cout<<" "<<endl;
    cout<<"1: First Node"<<endl;
    cout<<"2: At a Position"<<endl;
    cout<<"3: Last Node"<<endl;
    cout<<"4: Exit"<<endl;

    cout<<"Your Choice: ";
    cin>>DeleteDataOption;

    return DeleteDataOption;
}//end of AddOptions function


struct Node{
    string Data;
    Node *next;
};//Node strcuture

class LinkedList{
    public:
        Node *head, *tail;

    public:
        LinkedList(){
            head=NULL;
            tail=NULL;
        }

        //declartion of AddFirstNode function
        void AddFirstNode(string Value){
            Node *temp=new Node;
            temp->Data=Value;
            temp->next=head;
            head=temp;
        }//end of AddFirstNode function

        //declartion of AddAtPosition function
        void AddAtPosition(int Pos, string Value){
            Node *Previous=new Node;
            Node *Current=new Node;
            Node *temp=new Node;

            Current=head;

            for(int i=1;i<Pos;i++){
                Previous=Current;
                Current=Current->next;
            }//for i loop

            temp->Data=Value;
            Previous->next=temp;
            temp->next=Current;

        }//end of AddAtPosition function

        //declaration of void AddLastNode function
        void AddLastNode(string Value){
            Node *temp= new Node;
            temp->Data=Value;
            temp->next=NULL;

            if(head==NULL){
                head=temp;
                tail=temp;
                //temp=NULL;
            }else{

                Node *tail=head;
                Node *temp=new Node;
                temp->Data=Value;
                temp->next=NULL;

                while(tail->next!=NULL){
                    tail=tail->next;
                }//while loop
                tail->next=temp;

            }//If...else condition statement

        }//end of void AddLastNode function




        //declaration of DeleteFirstNode function
        void DeleteFirstNode(){

            Node *temp=new Node;
            temp=head;
            head=head->next;
            delete temp;

        }//end of DeleteFirstNode function

        //declaration of DeleteAtPosition function
        void DeleteAtPosition(int Pos){

                Node *Current=new Node;
                Node *Previous=new Node;
                Current=head;

                for(int i=1;i<Pos;i++){
                    Previous=Current;
                    Current=Current->next;
                }//for i loop

                Previous->next=Current->next;

                delete Current;
        }//end of DeleteAtPosition function

        //declaration of DeleteLastNode function
        void DeleteLastNode(){

            Node *Current=new Node;
            Node *Previous=new Node;
            Current=head;

            while(Current->next!=NULL){
                Previous=Current;
                Current=Current->next;
            }//while loop

            tail=Previous;
            Previous->next=NULL;

            delete Current;

        }//end of DeleteLastNode function




        //Declaration of Void Diplay function
        void Display(){
            Node *temp=new Node;
            temp=head;

            int i=1;
            cout<<"List of Elements:"<<endl;
            while(temp!=NULL){
                cout<<i <<". "<<temp->Data<<endl;
                temp=temp->next;
                i++;
            }
        }//end of void declaration function

};//Class declaration



int main()
{
//creating an Object in the main function
LinkedList LL;

int Option;
do{
    system("cls");

    Option = Options();

    system("cls");

if(Option==1){

//declaration of variable for user input
string Input;

    int AddOpt;
    AddOpt = AddOptions();
    system("cls");

        switch (AddOpt){
        case 1:
            //Aking for user input
            cout<<"Enter Data: ";
            //Taking input -  storing in variable
            cin>>Input;

            LL.AddFirstNode(Input);
        break;
        case 2:
            int pos;
            cout<<"Enter Position: ";
            cin>>pos;

            //Aking for user input
            cout<<"Enter Data: ";
            //Taking input -  storing in variable
            cin>>Input;

            LL.AddAtPosition(pos, Input);
        break;
        case 3:
            //Aking for user input
            cout<<"Enter Data: ";
            //Taking input -  storing in variable
            cin>>Input;

            LL.AddLastNode(Input);
        break;
        case 4:
            cout<<"Exited program."<<endl;
            return 0;
        break;
        default:
            cout<<"Invalid."<<endl;
        }//switch AddOpt
}//end of if option one

//Start of if option two
else if(Option==2){
    int DeleteOpt;
    DeleteOpt=DeleteOptions();
    system("cls");

    switch (DeleteOpt){
        case 1:
            LL.DeleteFirstNode();
        break;
        case 2:
            int pos;
            cout<<"Enter Position: ";
            cin>>pos;
            LL.DeleteAtPosition(pos);
        break;
        case 3:
            LL.DeleteLastNode();
        break;
        case 4:
            cout<<"Exited Program";
            return 0;
        break;
        default:
            cout<<"Invalid."<<endl;
        }//switch DeleteOpt

}//end of if option two

//start of if option three
else if(Option==3){
    LL.Display();
    cout<<" "<<endl;
    system("pause");
}//end of if option three


else if(Option==4){
    cout<<"Exited Program";
    return 0;
}//if option four

else{
  cout<<"Invalid."<<endl;
  system("pause");
}//for errors

}while(Option!=4);

    return 0;
}
