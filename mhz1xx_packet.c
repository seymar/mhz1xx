/**
 * MH-Z14A CO2 sensor protocol
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "./mhz1xx.h"

#define STARTBYTE 0xff

static uint_fast8_t err = 0;

// Prototypes
void mhz1xx_packet_create (char buf[9], uint8_t no, uint8_t cmd, char *data);
bool mhz1xx_packet_parse (char buf[9], uint8_t no, uint8_t cmd, char *data);

// The checksum = (invert (byte 1 +... + 7)) + 1
static char checksum (char *packet)
{
    char i, checksum;
    for (i = 1; i < 8; i++) {
        checksum += packet[i];
    }
    checksum = 0xff - checksum;
    checksum += 1;
    return checksum;
}

void mhz1xx_packet_create (char buf[9], uint8_t no, uint8_t cmd, char *data)
{
    buf[0] = 0xFF;
    buf[1] = no;
    buf[2] = cmd;
    memmove(&buf[3], data, 5);
    buf[8] = checksum(buf);
}

bool mhz1xx_packet_parse (char buf[9], uint8_t no, uint8_t cmd, char *data)
{
    if ((uint8_t)buf[0] != 0xFF) {
        err = MHZ1XX_INVALID_STARTBYTE;
        return false;
    }
    if (buf[1] != no) {
        err = MHZ1XX_INVALID_SENSOR_NO;
        return false;
    }
    if (buf[2] != cmd) {
        err = MHZ1XX_INVALID_CMDBYTE;
        return false;
    }
    if (buf[8] != checksum(buf)) {
        err = MHZ1XX_INVALID_CHECKSUM;
        return false;
    }
    data = &buf[3];
    err = 0;
    return true;
}

uint_fast8_t mhz1xx_get_err (void)
{
    return err;
}
