/*
 *  linux/include/asm-arm/arch-s3c2410/infobowlq.h
 *
 *  Author:		Samsung Electronics
 *  Created:	05, Jul, 2007
 *  Copyright:	Samsung Electronics Co.Ltd.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#ifndef ASM_MACH_INFOBOWLQ_H

#define ASM_MACH_INFOBOWLQ_H

#include <mach/gpio.h>

/* 
 * Board Configuration
 */
#if defined (CONFIG_MACH_VINSQ) || defined(CONFIG_MACH_MAX) || defined(CONFIG_MACH_VITAL)
#if defined(CONFIG_MACH_VITAL)
#define CONFIG_VITAL_REV00			0x0000	/* REV00 */
#define CONFIG_VITAL_REV01			0x0010	/* REV01 */
#define CONFIG_VITAL_REV02			0x0020	/* REV02 */
#else
#define CONFIG_INFOBOWLQ_REV00			0x00	/* REV00 */
#define CONFIG_INFOBOWLQ_REV01			0x01	/* REV01 */

#define CONFIG_INFOBOWLQ_REV01A			0x001A	/* REV01A */
#define CONFIG_INFOBOWLQ_REV02			0x0020	/* REV02 */
#define CONFIG_INFOBOWLQ_REV03			0x0030	/* REV03 */
#define CONFIG_INFOBOWLQ_REV04			0x0040	/* REV04 */
#define CONFIG_INFOBOWLQ_REV05			0x0050	/* REV05 */
#define CONFIG_INFOBOWLQ_REV07			0x0070	/* REV07 */
#define CONFIG_INFOBOWLQ_REV14			0x0080	/* REV14 */
#define CONFIG_INFOBOWLQ_REV15			0x0090	/* REV14 */
#endif
// rev01: 4096(12bit) * 15/(100+15) = 534 
#define REVISION_ADC_REV01_MIN		1440
#define REVISION_ADC_REV01_MAX		1550

// rev01a: 4096(12bit) * 15/(68+15) = 740 
#define REVISION_ADC_REV01A_MIN		1440
#define REVISION_ADC_REV01A_MAX		1550

// rev02: 4096(12bit) * 22/(68+22) = 1001 
#define REVISION_ADC_REV02_MIN		1400
#define REVISION_ADC_REV02_MAX		1550

// rev03: 4096(12bit) * 22/(47+22) = 1305 
#define REVISION_ADC_REV03_MIN		180
#define REVISION_ADC_REV03_MAX		200

// rev04: 4096(12bit) * 27/(47+27) = 1494 

#define REVISION_ADC_REV04_MIN		220	
#define REVISION_ADC_REV04_MAX		240

#define REVISION_ADC_REV05_MIN		1200
#define REVISION_ADC_REV05_MAX		1350

#elif CONFIG_MACH_INFOBOWLQ

#define CONFIG_INFOBOWLQ_REV00			0x00	/* REV00 */
#define CONFIG_INFOBOWLQ_REV01			0x01	/* REV01 */

// added by Pineone by kimjh
#define CONFIG_INFOBOWLQ_REV01A			0x001A	/* REV01A */
#define CONFIG_INFOBOWLQ_REV02			0x0020	/* REV02 */
#define CONFIG_INFOBOWLQ_REV03			0x0030	/* REV03 */
#define CONFIG_INFOBOWLQ_REV04			0x0040	/* REV04 */

// rev01: 4096(12bit) * 15/(100+15) = 534 
#define REVISION_ADC_REV01_MIN		525
#define REVISION_ADC_REV01_MAX		545

// rev01a: 4096(12bit) * 15/(68+15) = 740 
#define REVISION_ADC_REV01A_MIN		705
#define REVISION_ADC_REV01A_MAX		775

// rev02: 4096(12bit) * 22/(68+22) = 1001 
#define REVISION_ADC_REV02_MIN		950
#define REVISION_ADC_REV02_MAX		1050

// rev03: 4096(12bit) * 22/(47+22) = 1305 
#define REVISION_ADC_REV03_MIN		1250
#define REVISION_ADC_REV03_MAX		1350

// rev04: 4096(12bit) * 27/(47+27) = 1494 

#define REVISION_ADC_REV04_MIN		1450
#define REVISION_ADC_REV04_MAX		1550

#endif

//
#ifdef CONFIG_BOARD_REVISION
#define CONFIG_INFOBOWLQ_REV			CONFIG_BOARD_REVISION
#else
#error	"Board revision is not defined!"
#endif


#include "infobowlq_gpio.h"

#define I2C_CAM_DIS do {	\
	s3c_gpio_cfgpin(GPIO_I2C1_SCL, S3C_GPIO_INPUT);			\
	s3c_gpio_cfgpin(GPIO_I2C1_SDA, S3C_GPIO_INPUT);			\
	s3c_gpio_setpull(GPIO_I2C1_SCL, S3C_GPIO_PULL_DOWN);		\
	s3c_gpio_setpull(GPIO_I2C1_SDA, S3C_GPIO_PULL_DOWN);		\
} while (0)

#define I2C_CAM_EN do {		\
	s3c_gpio_cfgpin(GPIO_I2C1_SCL, S3C_GPIO_SFN(GPIO_I2C1_SCL_AF));	\
	s3c_gpio_cfgpin(GPIO_I2C1_SDA, S3C_GPIO_SFN(GPIO_I2C1_SDA_AF));	\
	s3c_gpio_setpull(GPIO_I2C1_SCL, S3C_GPIO_PULL_NONE);		\
	s3c_gpio_setpull(GPIO_I2C1_SDA, S3C_GPIO_PULL_NONE);		\
} while (0)

#define AF_PWR_DIS do {} while (0)
#define AF_PWR_EN do {} while (0)

#define	MCAM_RST_DIS do {	\
	/* MCAM RST Low */	\
	if (gpio_is_valid(GPIO_MCAM_RST_N)) {	\
		if (gpio_request(GPIO_MCAM_RST_N, S3C_GPIO_LAVEL(GPIO_MCAM_RST_N))) \
			printk(KERN_ERR "Failed to request GPIO_MCAM_RST_N!\n"); \
		gpio_direction_output(GPIO_MCAM_RST_N, GPIO_LEVEL_LOW);	\
	}	\
	s3c_gpio_setpull(GPIO_MCAM_RST_N, S3C_GPIO_PULL_NONE);	\
	gpio_free(GPIO_MCAM_RST_N);	\
} while (0)

#define	MCAM_RST_EN do {	\
	gpio_direction_output(GPIO_MCAM_RST_N, GPIO_LEVEL_HIGH);	\
	gpio_free(GPIO_MCAM_RST_N);	\
} while (0)
#if defined(CONFIG_MACH_VITAL)
#define	VCAM_RST_DIS do {	\
	/* MCAM RST Low */	\
	if (gpio_is_valid(GPIO_SCAM_RST_N)) {	\
		if (gpio_request(GPIO_SCAM_RST_N, S3C_GPIO_LAVEL(GPIO_SCAM_RST_N))) \
			printk(KERN_ERR "Failed to request GPIO_SCAM_RST_N!\n"); \
		gpio_direction_output(GPIO_SCAM_RST_N, GPIO_LEVEL_LOW);	\
	}	\
	s3c_gpio_setpull(GPIO_SCAM_RST_N, S3C_GPIO_PULL_NONE);	\
	gpio_free(GPIO_SCAM_RST_N); \
} while (0)

#define	VCAM_RST_EN do {	\
	gpio_direction_output(GPIO_SCAM_RST_N, GPIO_LEVEL_HIGH);	\
	gpio_free(GPIO_SCAM_RST_N);	\
} while (0)
#else
#define	VCAM_RST_DIS do { } while (0)
#define	VCAM_RST_EN do { } while (0)
#endif

#define	CAM_PWR_DIS do {	\
	/* CAM PWR Low */	\
	if (gpio_is_valid(GPIO_CAM_EN)) {	\
		if (gpio_request(GPIO_CAM_EN, S3C_GPIO_LAVEL(GPIO_CAM_EN))) \
			printk(KERN_ERR "Failed to request GPIO_CAM_EN!\n"); \
		gpio_direction_output(GPIO_CAM_EN, GPIO_LEVEL_LOW);	\
	}	\
	s3c_gpio_setpull(GPIO_CAM_EN, S3C_GPIO_PULL_NONE);	\
	gpio_free(GPIO_CAM_EN);	\
} while (0)

#define	CAM_PWR_EN do {	\
	gpio_direction_output(GPIO_CAM_EN, GPIO_LEVEL_HIGH);	\
	gpio_free(GPIO_CAM_EN);	\
} while (0)

#define	MCAM_STB_EN do {	\
	/* MCAM STB High */	\
	gpio_set_value(GPIO_CAM_STANDBY, GPIO_LEVEL_HIGH);	\
	gpio_free(GPIO_CAM_STANDBY);	\
} while (0)

#define	MCAM_STB_DIS do {	\
	/* MCAM STB Low */	\
	if (gpio_is_valid(GPIO_CAM_STANDBY)) {	\
		if (gpio_request(GPIO_CAM_STANDBY, S3C_GPIO_LAVEL(GPIO_CAM_STANDBY))) \
			printk(KERN_ERR "Failed to request GPIO_CAM_STANDBY!\n"); \
		gpio_direction_output(GPIO_CAM_STANDBY, GPIO_LEVEL_LOW);	\
	}	\
	s3c_gpio_setpull(GPIO_CAM_STANDBY, S3C_GPIO_PULL_NONE);	\
	gpio_free(GPIO_CAM_STANDBY);	\
} while (0)

#if defined(CONFIG_MACH_VITAL)
#define	VCAM_STB_EN do {	\
	/* MCAM STB High */	\
	gpio_direction_output(GPIO_SCAM_STANDBY, GPIO_LEVEL_HIGH);	\
	gpio_free(GPIO_SCAM_STANDBY);	\
} while (0)

#define	VCAM_STB_DIS do {	\
	/* MCAM STB Low */	\
	if (gpio_is_valid(GPIO_SCAM_STANDBY)) {	\
		if (gpio_request(GPIO_SCAM_STANDBY, S3C_GPIO_LAVEL(GPIO_SCAM_STANDBY))) \
			printk(KERN_ERR "Failed to request GPIO_SCAM_STANDBY!\n"); \
		gpio_direction_output(GPIO_SCAM_STANDBY, GPIO_LEVEL_LOW);	\
	}	\
	s3c_gpio_setpull(GPIO_SCAM_STANDBY, S3C_GPIO_PULL_NONE);	\
	gpio_free(GPIO_SCAM_STANDBY); \
} while (0)
#else
#define	VCAM_STB_DIS do { } while (0)
#endif

#define CAM_MEM_SIZE	0x0D000000

#if defined(CONFIG_MACH_VITAL)
#define S5K5CA_ID	0x78
#define S5KA3D_ID	0xC4
#else
#define S5K4CA_ID	0x78 
#endif

#define	LCD_18V_OFF do {  \
		if (Get_MAX8698_PM_REG(ELDO6, &onoff_lcd_18)) {  \
			pr_info("%s: LCD 1.8V off(%d)\n", __func__, onoff_lcd_18);  \
			if (onoff_lcd_18) \
				Set_MAX8698_PM_REG(ELDO6, 0);  \
		}  \
}	while (0)
#define	LCD_28V_OFF do {  \
		if (Get_MAX8698_PM_REG(ELDO7, &onoff_lcd_28)) {  \
			pr_info("%s: LCD 2.8V off(%d)\n", __func__, onoff_lcd_28);  \
			if (onoff_lcd_28) \
				Set_MAX8698_PM_REG(ELDO7, 0);  \
		}  \
}	while (0)
#define	LCD_30V_OFF do {}	while (0)

#define	LCD_18V_ON do {  \
		if (onoff_lcd_18) {  \
			pr_info("%s: LCD 1.8V On\n", __func__);  \
			Set_MAX8698_PM_REG(ELDO6, 1);  \
		}  \
}	while (0)
#define	LCD_28V_ON do {  \
		if (onoff_lcd_28) {  \
		pr_info("%s: LCD 2.8V On\n", __func__);  \
		Set_MAX8698_PM_REG(ELDO7, 1);  \
	}  \
}while (0)

#define	LCD_30V_ON do {}	while (0)

#endif	/* ASM_MACH_INFOBOWLQ_H */

