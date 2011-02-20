#ifndef __BMA020_I2C_HEADER__
#define __BMA020_I2C_HEADER__

char  i2c_acc_bma020_read (u8, u8 *, unsigned int);
char  i2c_acc_bma020_write(u8 reg, u8 *val);

int  i2c_acc_bma020_init(void);
void i2c_acc_bma020_exit(void);

/*********** for debug **********************************************************/
#if 0
#define gprintk(fmt, x... ) printk( "[kr3dm-emu] %s(%d): " fmt, __FUNCTION__ ,__LINE__, ## x)
#else
#define gprintk(x...) do { } while (0)
#endif
/*******************************************************************************/

#endif
