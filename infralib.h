#include <stdlib.h>
#include <iostream>

#define null NULL

using namespace std;

/**
 * NODE STRUCTURE
 * 		-stores all sensors.
 */
struct Node{
	struct Node *next_node;
	struct Node *last_node;
	short pin;
	bool isactive;
};

/**
 * Current node.
 */
struct Node *header_node = null;

/**
 * Temporary node
 */
struct Node *record_node = null;

/**
 * [add_sensor saves one sensor to the sensor list]
 * @param sensor_pin [sensor board pin]
 */
void add_sensor(short sensor_pin){
	struct Node *tmpnode = null;

	if((header_node != null) & (record_node != null))
		tmpnode = header_node->last_node;

	record_node = (struct Node *) malloc(sizeof(struct Node));
	record_node->next_node = header_node;
	record_node->last_node = tmpnode;
	record_node->pin = sensor_pin;
	record_node->isactive = false;
	header_node = record_node;
}

void print_sensors(){
	struct Node* hnode = header_node;

	while(hnode!=null){
		cout<<"sensor number: "<<hnode->pin<<endl;
		cout<<"sensor active: "<<hnode->isactive<<endl;
		hnode = hnode->next_node;
	}

	free(hnode);
}

/**
 * [check_sensor verify if one sensor is active with the current pin]
 * @param  pin [pin on the board]
 * @return     [true: if the sensor is on, false: if the sensor is off]
 */
inline bool check_sensor(short pin){
	return (pin%2 == 0)?true:false;
}

/**
 * [get_active_sensors iterate the sensor list]
 * @return [the list altered by sensors reading]
 */
struct Node* get_active_sensors(){
	struct Node *sensors = header_node;

	while(sensors != null){
		//check if the sensor is active
		sensors->isactive = check_sensor(sensors->pin);

		//iterate the node
		sensors = sensors->next_node;
	}

	free(sensors);

	return header_node;
}


//overlod the operator ++ to pass to the next reference
/*
Node* operator ++(Node* currentnode){
	return currentnode->next_node;
}*/