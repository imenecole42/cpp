#include <iostream>
#include "Serializer.hpp"
#include <stdint.h>
int main( void )
{
	std::cout<<"********tes1*************"<<std::endl;
	 // Create a Data object
    Data dataObj(42);

    // Serialize the pointer to the Data object
    uintptr_t serializedPtr = Serializer::serialize(&dataObj);

    // Deserialize the serialized pointer
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedPtr == &dataObj) {
        std::cout << "Serialization and deserialization worked correctly!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

	std::cout<<"********tes2*************"<<std::endl;

	Data	*data = new Data;
	Data	*data_res;

	data_res = Serializer ::deserialize( Serializer ::serialize( data ) );
	if ( data_res != data )
		std::cout << "Error: cast 'Data *' to 'uintptr_t' and reverse failed" << std::endl;
	else
		std::cout << "Cast 'Data *' to 'uintptr_t'and reverse successed" << std::endl;
	delete data;
	return ( 0);
}