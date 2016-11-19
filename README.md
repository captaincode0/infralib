# infralib
`ìnfralib` es una librería para controlar sensores infrarojos hecho con la finalidad de obtener los sensores que están activos y obtener su valor.

## ¿Cómo usar infralib?
La librería hace usos de estructuras dinámicas, listas doblemente enlazadas, en las cuales almacena el pin del sensor y su estado [activo o no activo].

```c++
    /*
        Implementación del procedimiento para determinar si el sensor 
        está o no activo, este método se utilizará al recorrer todos 
        los sensores en la matriz de sensores infra rojos.
     */
    bool check_sensor(short pin){
        if(Sensor.isActive(pin))
            return true;
        else
            return false;
    }
```

La implementación de la librería en un proyecto de Arduino es la siguiente:

```c++
    #include "infralib.h";
    
    struct Node* sensors = null;
    
    void setup(){
        /*
            Añadir los sensores con su pin correspondiente
         */
        add_sensor(9);
        add_sensor(10);
        add_sensor(8);
    }

    void loop(){
        /*
            Obtener los sensores activos
         */
        sensors = get_active_sensors();

        while(sensor != null){
            //si el sensor está activado entonces hacer algo con el mismo
            if(sensors->isactive){
                //implementación del algoritmo para el sensor activos
            }
            sensors = sensors->next_node;
        }
    }
```

