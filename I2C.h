#include "MKL25Z4.h"
#include "TP_I2C.h"
void I2C_Init(){
    SIM->SCGC4 |= SIM_SCGC4_I2C1_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
    I2C0->C1 = I2C_C1_IICEN_MASK;
    I2C0->C1 |= I2C_C1_TX_MASK;
    I2C0->C1 |= I2C_C1_MST_MASK;
    PORTC->PCR[10] = PORT_PCR_MUX(2);
    PORTC->PCR[11] = PORT_PCR_MUX(2);
    I2C1->F=0x14;

}
void I2C_bStart(){
while (!(I2C1->S & I2C_S_IICIF_MASK));
I2C1->D = data;
}
void I2C_bStop(){
while (I2C1->S & I2C_S_IICIF_MASK);
I2C1->D = data;
}
void I2C_Write(uint8_t data){
I2C1->S |= I2C_S_IICIF_MASK;
return I2C1->D;
}