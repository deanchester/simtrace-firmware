#ifndef _OPENPCD_PROTO_H
#define _OPENPCD_PROTO_H

/* This header file describes the USB protocol of the OpenPCD RFID reader */

#include <sys/types.h>

struct openpcd_hdr {
	u_int8_t cmd;		/* command. high nibble: class, low nibble: cmd */
	u_int8_t flags;
	u_int8_t reg;		/* register */
	u_int8_t val;		/* value (in case of write *) */
	u_int8_t data[0];
} __attribute__ ((packed));

enum openpcd_cmd_class {
	OPENPCD_CMD_CLS_RC632		= 0x1,
	OPENPCD_CMD_CLS_LED		= 0x2,
	OPENPCD_CMD_CLS_SSC		= 0x3,
	OPENPCD_CMD_CLS_PWM		= 0x4,
};

#define OPENPCD_CMD_CLS(x)	(x >> 4)
#define OPENPCD_CMD(x)		(x & 0xf)

#define OPENPCD_CLS2CMD(x)	(x << 4)

/* CMD_CLS_RC632 */
#define OPENPCD_CMD_WRITE_REG		(0x1|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_WRITE_FIFO		(0x2|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_WRITE_VFIFO		(0x3|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_REG_BITS_CLEAR	(0x4|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_REG_BITS_SET	(0x5|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_READ_REG		(0x6|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_READ_FIFO		(0x7|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_READ_VFIFO		(0x8|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_DUMP_REGS		(0x9|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))
#define OPENPCD_CMD_IRQ			(0xa|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_RC632))

/* CMD_CLS_LED */
#define OPENPCD_CMD_SET_LED		(0x1|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_LED))

/* CMD_CLS_SSC */
#define OPENPCD_CMD_SSC_READ		(0x1|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_SSC))
#define OPENPCD_CMD_SSC_WRITE		(0x2|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_SSC))

/* CMD_CLS_PWM */
#define OPENPCD_CMD_PWM_ENABLE		(0x1|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_PWM))
#define OPENPCD_CMD_PWM_DUTY_SET	(0x2|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_PWM))
#define OPENPCD_CMD_PWM_DUTY_GET	(0x3|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_PWM))
#define OPENPCD_CMD_PWM_FREQ_SET	(0x4|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_PWM))
#define OPENPCD_CMD_PWM_FREQ_GET	(0x5|OPENPCD_CLS2CMD(OPENPCD_CMD_CLS_PWM))

#define OPENPCD_VENDOR_ID	0x2342
#define OPENPCD_PRODUCT_ID	0x0001
#define OPENPCD_OUT_EP		0x01
#define OPENPCD_IN_EP		0x82
#define OPENPCD_IRQ_EP		0x83

#endif
