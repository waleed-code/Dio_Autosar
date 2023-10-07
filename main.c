



#include "DIO/DIO.h"
#include "Port/Port.h"




int main(void)
{

    Dio_Init();
    Dio_WriteChannel(43, HIGH);


    while(1)
    {


    }
}
