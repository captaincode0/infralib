#include <stdlib.h>

#define null NULL

using namespace std;

/**
 * Sensor structure
 */
typedef Node{
	Node *next_node;
	Node *last_node;
	uint8_t pin;
};

//current node
Node *header_node = null;
//pass node
Node *record_node = null;

/**
 * [add description]
 * @param  pin [description]
 * @return     [description]
 */
bool add(uint8_t pin){
	Node *beforenode = null;

	if(header_node != null
		& record_node != null)
		beforenode = header_node->last_node;
	
	record_node = (Node *) malloc(sizeof(Node));
	record_node->next_node = (Node *) malloc(sizeof(Node));
	record_node->last_node = beforenode;
	record_node->pin = pin;
	header_node = record_node;
}

/**
 * [print print the values of the list]
 */
void print(){
	Node* hnode = header_node;

	while(hnode!=null){
		cout<<hnode->pin<<endl;
		node = header_node->next_node;
	}
}

/**
 * [get_last_node get the last node of the current node]
 * @return [the last node]
 */
Node* get_last_node(){
	return header_node->last_node;
}

/**
 * [get_next_node get the next node of the current node]
 * @return [the next node]
 */
Node* get_next_node(){
	return header_node->next_node;
}

/**
 * [get_active_sensors get one pointer of active sensors]
 * @return [an array of active sensors]
 */
uint8_t* get_active_sensors(){

}