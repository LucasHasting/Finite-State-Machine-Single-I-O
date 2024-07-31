#include <cstring>
#include <iostream>
#include <fstream>
#include "node.h"
#include "FSM.h"
using namespace std;

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
