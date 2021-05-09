#include <stdio.h>

#include "../mhz1xx.h"

/*
static char cmd_read_ppm[9] = {
    0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79 };
static char cmd_calib_zero[8] = {
    0xFF, 0x01, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78 };
static char cmd_calib_span[8] = {
    0xFF, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78 };
*/
/*
TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
   FAIL("Fail me!");
}
*/

#include "CppUTest/CommandLineTestRunner.h"

int main (int argc, char **argv)
{
    char buf[9];
    mhz1xx_packet_read_ppm(buf);
    for (int i = 0; i < sizeof(buf); i++)
        printf("%#04x, ", (uint8_t)buf[i]);
    printf("\n");

  return RUN_ALL_TESTS(argc, argv);
}