#include "infralib.h"

int main(){
		cout<<"Adding eleven sensors"<<endl;
		
		//add the first sensor
		for(short sensor=1; sensor<=60000; sensor++)
			add_sensor(sensor);

		
		struct Node *sensor_list = get_active_sensors();

		while(sensor_list != null){
			//if is active print the current value
			if(sensor_list->isactive)
				cout<<sensor_list->pin<<endl;
			sensor_list = sensor_list->next_node;
		}

	return 0x0;
}