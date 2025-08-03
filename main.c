#include <stdint.h>
#include <stdbool.h>
#include "clock.h"
#include "wait.h"
#include "tm4c123gh6pm.h"

////Configuration of I2C module 0 = Uses PortB: PB2=SCL and PB3=SDA

#define Pins_of_portB 0x0C
#define I2C0SDA 0x08

void initI2C_Config()
{
    initSystemClockTo40Mhz();
    SYSCLK_RCGCI2C_R |= SYSCLK_RCGCI2C_R0;
    SYSCLK_RCGCGPIO_R |= SYSCLK_RCGCGPIO_R1;

    GPIO_PORTB_AFSEL_R |= Pins_of_portB;
    GPIO_PORTB_ODR_R |= I2C0SDA;
    GPIO_PORTB_PCTL_R &= ~(0x0000FF00);
    GPIO_PORTB_PCTL_R |= 0x00003300;

    GPIO_PORTB_DEN_R |= Pins_of_portB;

    I2C0_MCR_R = 0x00000010;
    I2C0_MTPR_R = 0x00000090;
    I2C0_MSA_R = (0x3B << 1);
    I2C0_MDR_R = 0x5A;
    I2C0_MCS_R =  0x00000007;
    while (I2C0_MCS_R & 0x01);  // Wait until controller is no longer busy
    while (I2C0_MCS_R & (1 << 0)); // Wait while busy

    if (I2C0_MCS_R & (1 << 1)) {
        // Handle error: arbitration lost, no ACK, etc.
    }

}

int main(void)
{
    initI2C_Config();
	return 0;
}
