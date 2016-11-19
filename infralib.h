#include <stdlib.h>
#include <iostream>

#define null NULL

using namespace std;

/**
 * Sensor structure
 */
struct Node{
	struct Node *next_node;
	struct Node *last_node;
	short pin;
	bool isactive;
};

//current node
struct Node *header_node = null;
//before node
struct Node *record_node = null;

void add_sensor(short sensor_pin){
	struct Node *tmpnode = null;

	if(header_node != null
		& record_node != null)
		tmpnode = header_node->last_node;

	record_node = (struct Node *) malloc(sizeof(struct Node));
	record_node->next_node = header_node;
	record_node->last_node = tmpnode;
	record_node->pin = sensor_pin;
	record_node->isactive = true;
	header_node = record_node;
}

/**
 * [prshort prshort the values of the list]
 */
void print_sensors(){
	struct Node* hnode = header_node;

	while(hnode!=null){
		cout<<"sensor number: "<<hnode->pin<<endl;
		cout<<"sensor active: "<<hnode->isactive<<endl;
		hnode = hnode->next_node;
	}
}

//FUNCTION FOR UNIT TEST
bool check_sensor(short pin){
	return (pin%2 == 0)?true:false;
}

struct Node* get_active_sensors(){
	struct Node *sensors = header_node;

	while(sensors != null){
		//check if the sensor is active
		sensors->isactive = (check_sensor(sensors->pin))?true:false;

		//iterate the node
		sensors = sensors->next_node;
	}

	return header_node;
}


//overlod the operator ++ to pass to the next reference
/*
Node* operator ++(Node* currentnode){
	return currentnode->next_node;
}*/