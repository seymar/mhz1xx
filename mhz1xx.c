/**
 * MH-Z14A CO2 sensor protocol
 */
#include <stdint.h>
#include <stdbool.h>

#include "./mhz1xx.h"

#define SENSOR_NO 0x01

#define CMD_READ_PPM     0x86
#define CMD_CALIB_ZERO   0x87
#define CMD_CALIB_SPAN   0x88
#define CMD_AUTOCAL_EN   0x79
#define CMD_DETECT_RANGE 0x99

// Prototypes
void mhz1xx_packet_create (char buf[9], uint8_t no, uint8_t cmd, char *data);
bool mhz1xx_packet_parse (char buf[9], uint8_t no, uint8_t cmd, char *data);

// Public functions
void mhz1xx_packet_read_ppm (char buf[9])
{
    mhz1xx_packet_create(buf, SENSOR_NO, CMD_READ_PPM, &buf[3]);
}

void mhz1xx_packet_calib_zero (char buf[9])
{
    mhz1xx_packet_create(buf, SENSOR_NO, CMD_CALIB_ZERO, &buf[3]);
}

void mhz1xx_packet_calib_span (char buf[9], uint16_t ppm)
{
    buf[3] = ppm / 256;
    buf[4] = ppm % 256;
    mhz1xx_packet_create(buf, SENSOR_NO, CMD_CALIB_SPAN, &buf[3]);
}

void mhz1xx_packet_autocal_en (char buf[9], bool en)
{
    buf[3] = en ? 0xA0 : 0;
    mhz1xx_packet_create(buf, SENSOR_NO, CMD_AUTOCAL_EN, &buf[3]);
}

void mhz1xx_packet_detect_range (char buf[9], uint16_t ppm)
{
    buf[3] = ppm / 256;
    buf[4] = ppm % 256;
    mhz1xx_packet_create(buf, SENSOR_NO, CMD_DETECT_RANGE, &buf[3]);
}

bool mhz1xx_parse_read_ppm (char buf[9], uint16_t *ppm)
{
    char *data;
    if (!mhz1xx_packet_parse(buf, SENSOR_NO, CMD_READ_PPM, data)) return false;
    *ppm = data[0] * 256 + data[1];
    return true;
}
