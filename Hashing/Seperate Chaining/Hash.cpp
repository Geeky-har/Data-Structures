// In this program we will be implementing Hashing with Chaining method for collision

#include<bits/stdc++.h>
using namespace std;

class Hash{
    private:
        int bucket_size;    // Size if the hash table
        list<int> *table;   // Pointer to an array contaning buckets

    public:
        void CreateHash(int size);     // Contructor will set the size of the bucket(no. of entries)

        void insertItem(int);
        void search(int);
        int HashFunction(int);
        void deleteItem(int);
        void showHash();
};

void Hash:: CreateHash(int size){
    this->bucket_size = size;
    table = new list<int>[bucket_size];

    cout<<"Hash Table created successfully"<<endl;
}

int Hash::HashFunction(int value){
    return (value % bucket_size);
}

void Hash::insertItem(int value){
    int key = HashFunction(value);  // Using Hash function we will determine the key for the value
    table[key].push_back(value);    // Will append the value in the key identified above

    cout<<"Value "<<value<<" inserted successfully"<<endl;
}

void Hash::search(int value){
    int key = HashFunction(value);
    bool exists = false;

    list <int> :: iterator i;

    for(auto i = table[key].begin(); i != table[key].end(); ++i){
        if(*i == value)
            exists = true;

    }

    if(exists)
        cout<<"The value "<<value<<" is present in the Hash Table"<<endl;

    else
        cout<<"The value "<<value<<" is not present in the Hash Table"<<endl;        
    
}

void Hash::deleteItem(int value){
    int key = HashFunction(value);
    bool exists = false;

    list<int> :: iterator i;

    for( i = table[key].begin(); i != table[key].end(); i++){
        if(*i == value){
            exists = true;
            break;
        }
    }

    if(i != table[key].end()){
        table[key].erase(i);
    }

    if(exists)
        cout<<"Item deleted successfully"<<endl;

    else
        cout<<"Item not found in the Hash Table"<<endl;
    
}

void Hash::showHash(){
    cout<<"Here is your Hash Table"<<endl;

    for(int i = 0; i < bucket_size; ++i){

        cout<<i;
        for(auto x: table[i])
            cout<<" --> "<<x;

        cout<<endl;
    }
}

int main(){

    int option;
    Hash ht;

    do{

        cout<<"**********************MAIN MENU*************************"<<endl<<endl;

        cout<<"Select the option from below"<<endl;

        cout<<"1. To Create the Hash Table"<<endl;
        cout<<"2. To Insert the value in the Hash Table"<<endl;
        cout<<"3. To Search for a value in the Hash Table"<<endl;
        cout<<"4. To delete a value in the Hash Table"<<endl;
        cout<<"5. To show the Hash Table"<<endl;
        cout<<"6. Exit"<<endl;

        cin>>option;

        switch (option)
        {
        case 1:
            int n;
            cout<<"Enter the size of the Hash Table"<<endl;
            cin>>n;

            ht.CreateHash(n);

            break;
        
        case 2:
            int value_insert;

            cout<<"Enter the value that you want to insert in the table"<<endl;
            cin>>value_insert;

            ht.insertItem(value_insert);

            break;

        case 3:
            int value_search;

            cout<<"Enter the value that you want to search"<<endl;
            cin>>value_search;

            ht.search(value_search);

            break;

        case 4:
            int value_delete;

            cout<<"Enter the value to be deleted"<<endl;
            cin>>value_delete;

            ht.deleteItem(value_delete);

            break;

        case 5:
            ht.showHash();

            break;
        }

    }while(option != 6);

    return 0;

}