#ifndef MHZ1XX
#define MHZ1XX
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define MHZ1XX_PACKETLEN 9

void mhz1xx_packet_read_ppm (char buf[9]);
void mhz1xx_packet_calib_zero (char buf[9]);
void mhz1xx_packet_calib_span (char buf[9], uint16_t ppm);
void mhz1xx_packet_autocal_en (char buf[9], bool en);
void mhz1xx_packet_detect_range (char buf[9], uint16_t ppm);

bool mhz1xx_parse_read_ppm (char buf[9], uint16_t *ppm);

// Error numbers
#define MHZ1XX_INVALID_STARTBYTE 1
#define MHZ1XX_INVALID_SENSOR_NO 2
#define MHZ1XX_INVALID_CMDBYTE   3
#define MHZ1XX_INVALID_CHECKSUM  4

/**
 * mhz1xx_get_err - Get error number
 * @return Error number
 */
uint_fast8_t mhz1xx_get_err (void);

#ifdef __cplusplus
}
#endif
#endif