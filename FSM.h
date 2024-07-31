#ifndef FSM_H
#define FSM_H

void delete_nodes(Node** data, int size);
void display_menu();
void connect_graph(Node* add, Node* zero, Node* one);
void find_solution(Node* start, string input_stream);
void make_file(string data_file);
Node** load_from_file(string data_file, int &size);

#endif