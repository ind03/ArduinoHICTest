#ifndef HEIKO_H
#define HEIKO_H 1

#define INLINE __attribute__((always_inline));

#define NOP()	asm volatile ("nop")
#define NOP2()	asm volatile ("rjmp 1f\n 1:")


#define CLIPUSH()	byte sreg = SREG; cli();
#define SEIPOP()	SREG = sreg;

#define MILLIS_OFF()	TIMSK0 = 0x00;
#define MILLIS_ON()		TIMSK0 = 0x01;

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef union
{
  struct
    {
        byte low;
        byte high;
    };
    uint word;
} WORD;


// Highbyte / Lowbyte of variables
#define LOW_BYTE(var)		(((unsigned char *)&(var))[0])
#define HIGH_BYTE(var)		(((unsigned char *)&(var))[1])
#define MK_WORD(low,high)	(low | (high<<8))

//______________________________________________________
#define	S(bit)			(1<<bit)
#define	R(bit)			(~(1<<bit))
#define	C(bit)			(~(1<<bit))

//____ Bit functions __________________________________
#define	BM(bit)				(1<<bit)
#define	BS(bit)				(1<<bit)
#define	BC(bit)				(0<<bit)
#define IsSET(port,bit)		((port & BM(bit)) != 0)
#define IsCLEAR(port,bit)	((port & BM(bit)) == 0)
#define SetBit(port,bit)	port |= BM(bit)
#define ClearBit(port,bit)	port &= ~BM(bit)


// Obsolete
//#define ON(port,bit)	port |= BM(bit)
//#define OFF(port,bit)	port &= ~BM(bit)
//#define IsON(port,bit)	((port & BM(bit)) != 0)
//#define IsOFF(port,bit)	((port & BM(bit)) == 0)

//____ Port functions __________________________________

#define DIRIN(port,bit)		__CONCAT(DDR, port) &= (byte) ~BM(bit)
#define DIROUT(port,bit)	__CONCAT(DDR, port) |= (byte) BM(bit)
#define SETHIGH(port,bit)	__CONCAT(PORT, port) |= (byte) BM(bit)
#define SETLOW(port,bit)	__CONCAT(PORT, port) &= (byte) ~BM(bit)
#define TOGGLE(port,bit)	__CONCAT(PIN, port) |= (byte) BM(bit)
#define ISHIGH(port,bit)	((__CONCAT(PIN, port) & BM(bit)) != 0)
#define ISLOW(port,bit)		((__CONCAT(PIN, port) & BM(bit)) == 0)
#define PULLUPON(port,bit)	__CONCAT(PORT, port) |= (byte) BM(bit)
#define PULLUPOFF(port,bit)	__CONCAT(PORT, port) &= (byte) ~BM(bit)

//____ Open Collector assumes a 0 at the pins_________
#define OCHIGH(port,bit)	__CONCAT(DDR, port) &= ~BM(bit)
#define OCLOW(port,bit)		__CONCAT(DDR, port) |= BM(bit)

/*
#define SENSOR_DDR __CONCAT(DDR, SENSOR_PORT_LETTER)
#define SENSOR_PORT __CONCAT(PORT, SENSOR_PORT_LETTER)
#define SENSOR_PIN __CONCAT(PIN, SENSOR_PORT_LETTER)
*/
#endif
