#include "i2c.h"
#include <avr/io.h>
#include <util/delay.h>

// Inicijalizacija I2C modula
void i2c_init(uint32_t scl_freq) {
    // Postavi prescaler na 1
    TWSR = 0x00;
    
    // Izračunaj TWBR: F_SCL = F_CPU / (16 + 2 * TWBR * Prescaler)
    TWBR = ((F_CPU / scl_freq) - 16) / 2;
    
    // Omogući TWI modul
    TWCR = (1 << TWEN);
}

// Slanje START uvjeta
uint8_t i2c_start(uint8_t address) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x08) return 1; // Greška
    
    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != ((address & 0x01) ? 0x40 : 0x18)) return 1; // Greška
    
    return 0; // Uspjeh
}

// Slanje REPEATED START uvjeta
uint8_t i2c_rep_start(uint8_t address) {
    return i2c_start(address);
}

// Slanje STOP uvjeta
void i2c_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
    while (TWCR & (1 << TWSTO));
}

// Slanje bajta
uint8_t i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x28) return 1; // Greška
    
    return 0; // Uspjeh
}

// Čitanje bajta s ACK-om
uint8_t i2c_read_ack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

// Čitanje bajta s NACK-om
uint8_t i2c_read_nack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}