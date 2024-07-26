#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    Node* one = nullptr;
    Node* zero = nullptr;
    bool data = 0;

    Node(){
        data = 0;
    }

    Node(bool output){
        data = output;
    }
};

void find_solution(Node* start, string input_stream){
    Node* current = start;
    int length = strlen(input_stream.c_str());
    for (int i = 0; i < length; i++){
        if(input_stream[i]=='1'){
            if (start->one == nullptr){
                cout << "ERROR, NULL" << "\n";
            }
            current = current->one;
        }
        else {
            if (start->zero == nullptr){
                cout << "ERROR, NULL" << "\n";
            }
            current = current->zero;
        }
    }
    cout << "The output is: " << current->data << "\n";

}

void connect_graph(Node* add, Node* zero, Node* one){
    add->one = one;
    add->zero = zero;
}

Node** load_from_file(string data_file, int &size){
    ifstream in_file(data_file);
    in_file >> size;
    Node** data = new Node*[size];
    for (int i = 0; i < size; i++){
        data[i] = new Node();
        in_file >> data[i]->data;
    }

    for (int i = 0; i < size; i++){
        int zero;
        int one;
        in_file >> zero >> one;
        data[i]->zero = data[zero];
        data[i]->one = data[one];
    }
    in_file.close();

    return data;

}

void make_file(string data_file){
    /*
    Structure of file:
    amount_of_states state_1_output ... state_n_output
    state_0_connection_0 state_0_connection_1
    ...
    */

    /*
    state connections are indexs to the array, first state is 0, all states are represented with numbers
    example file:
    3 0 1 1
    0 1
    0 0
    1 1
    */

    int size;
    ofstream out_file;
    out_file.open(data_file);
    cout << "How many states: ";
    cin >> size;
    out_file << size << " ";

    for(int i = 0; i < size; i++){
        int write;
        cout << "Enter State " << i << " Output: ";
        cin >> write;
        if (i != size-1)
            out_file << write << " ";
        else
            out_file << write << "\n";
    }

    for(int i = 0; i < size; i++){
        int write;
        cout << "Enter State " << i << " Connection 0: ";
        cin >> write;
        out_file << write << " ";

        cout << "Enter State " << i << " Connection 1: ";
        cin >> write;
        out_file << write << "\n";
    }
    out_file.close();
}

void display_menu(){
    cout << "make state machine file \t Enter 1 \n"
    << "load state machine from file \t Enter 2 \n"
    << "test state machine \t\t Enter 3 \n"
    << "Exit \t\t\t\t Enter 0 \nEnter: ";
}

void delete_nodes(Node** data, int size){
    if (data == nullptr){
        return;
    }

    for(int i = size-1; i >= 0; i--){
        delete data[i];
    }
    delete []data;
    data = nullptr;
}

int main(){
    int size = 0;
    int choice = -1;
    string data_name = " ";
    string input = " ";
    Node** data = nullptr;

    while (choice != 0){
        display_menu();
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter Data File: ";
            cin >> data_name;
            make_file(data_name);
            break;
        case 2:
            delete_nodes(data, size);
            cout << "Enter Data File: ";
            cin >> data_name;
            data = load_from_file(data_name, size);
            break;
        case 3:
            if (data == nullptr){
                cout << "NO MACHINE SELECTED\n";
                break;
            }
            cout << "input: ";
            cin >> input;

            find_solution(data[0], input);
        }
    }

    delete_nodes(data, size);
    return 0;
}
