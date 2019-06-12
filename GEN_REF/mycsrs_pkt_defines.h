#ifndef MYCSRS_PKT_DEFINES_H_INCLUDED
#define MYCSRS_PKT_DEFINES_H_INCLUDED

// pkt Write
#define MYCSRS_PKT_FLD_RNG_write__n	7:0
#define MYCSRS_PKT_FLD_RNG_write__waddr	15:8
#define MYCSRS_PKT_FLD_RNG_write__slave_addr	25:16
#define MYCSRS_PKT_FLD_RNG_write__use_10b_addressing	26:26
#define MYCSRS_PKT_FLD_RNG_write__rr	27:27
#define MYCSRS_PKT_FLD_RNG_write__cmd	31:28

// pkt Read
#define MYCSRS_PKT_FLD_RNG_read__n	7:0
#define MYCSRS_PKT_FLD_RNG_read__raddr	15:8
#define MYCSRS_PKT_FLD_RNG_read__slave_addr	25:16
#define MYCSRS_PKT_FLD_RNG_read__use_10b_addressing	26:26
#define MYCSRS_PKT_FLD_RNG_read__res	27:27
#define MYCSRS_PKT_FLD_RNG_read__cmd	31:28

// pkt WriteOne
#define MYCSRS_PKT_FLD_RNG_writeone__wdata	7:0
#define MYCSRS_PKT_FLD_RNG_writeone__waddr	15:8
#define MYCSRS_PKT_FLD_RNG_writeone__slave_addr	25:16
#define MYCSRS_PKT_FLD_RNG_writeone__use_10b_addressing	26:26
#define MYCSRS_PKT_FLD_RNG_writeone__rr	27:27
#define MYCSRS_PKT_FLD_RNG_writeone__cmd	31:28

// pkt ReadCurrent
#define MYCSRS_PKT_FLD_RNG_readcurrent__n	7:0
#define MYCSRS_PKT_FLD_RNG_readcurrent__res1	15:8
#define MYCSRS_PKT_FLD_RNG_readcurrent__slave_addr	25:16
#define MYCSRS_PKT_FLD_RNG_readcurrent__use_10b_addressing	26:26
#define MYCSRS_PKT_FLD_RNG_readcurrent__res2	27:27
#define MYCSRS_PKT_FLD_RNG_readcurrent__cmd	31:28

// pkt WritePayload
#define MYCSRS_PKT_FLD_RNG_writepayload__wdata	7:0
#define MYCSRS_PKT_FLD_RNG_writepayload__res	31:8

// pkt WriteResp
#define MYCSRS_PKT_FLD_RNG_writeresp__res	7:0
#define MYCSRS_PKT_FLD_RNG_writeresp__error	8:8
#define MYCSRS_PKT_FLD_RNG_writeresp__cmd	31:28

// pkt ReadResp
#define MYCSRS_PKT_FLD_RNG_readresp__rdata	7:0
#define MYCSRS_PKT_FLD_RNG_readresp__error	8:8
#define MYCSRS_PKT_FLD_RNG_readresp__cmd	31:28

// pkt LLWrite
#define MYCSRS_PKT_FLD_RNG_llwrite__wdata	7:0
#define MYCSRS_PKT_FLD_RNG_llwrite__stop	8:8
#define MYCSRS_PKT_FLD_RNG_llwrite__start	9:9
#define MYCSRS_PKT_FLD_RNG_llwrite__rr	12:12
#define MYCSRS_PKT_FLD_RNG_llwrite__cmd	31:28

// pkt LLRead
#define MYCSRS_PKT_FLD_RNG_llread__stop	8:8
#define MYCSRS_PKT_FLD_RNG_llread__nack	9:9
#define MYCSRS_PKT_FLD_RNG_llread__cmd	31:28

#define MYCSRS_PKT_LIST(op) \
 op(write}) \
 op(read}) \
 op(writeone}) \
 op(readcurrent}) \
 op(writepayload}) \
 op(writeresp}) \
 op(readresp}) \
 op(llwrite}) \
 op(llread}) \

#define MYCSRS_PKT_FIELD_LIST(op) \
 op(write,n) \
 op(write,waddr) \
 op(write,slave_addr) \
 op(write,use_10b_addressing) \
 op(write,rr) \
 op(write,cmd) \
 op(read,n) \
 op(read,raddr) \
 op(read,slave_addr) \
 op(read,use_10b_addressing) \
 op(read,res) \
 op(read,cmd) \
 op(writeone,wdata) \
 op(writeone,waddr) \
 op(writeone,slave_addr) \
 op(writeone,use_10b_addressing) \
 op(writeone,rr) \
 op(writeone,cmd) \
 op(readcurrent,n) \
 op(readcurrent,res1) \
 op(readcurrent,slave_addr) \
 op(readcurrent,use_10b_addressing) \
 op(readcurrent,res2) \
 op(readcurrent,cmd) \
 op(writepayload,wdata) \
 op(writepayload,res) \
 op(writeresp,res) \
 op(writeresp,error) \
 op(writeresp,cmd) \
 op(readresp,rdata) \
 op(readresp,error) \
 op(readresp,cmd) \
 op(llwrite,wdata) \
 op(llwrite,stop) \
 op(llwrite,start) \
 op(llwrite,rr) \
 op(llwrite,cmd) \
 op(llread,stop) \
 op(llread,nack) \
 op(llread,cmd) \

// pkt access macros
#define MYCSRS_PKTF_ENUM(f,e)                   MYCSRS_PKT_FLD_ENUM_ ## f ## __ ## e
#define _MYCSRS_PKTF_MSB(f)                     1 ? MYCSRS_PKT_FLD_RNG_ ## f
#define _MYCSRS_PKTF_LSB(f)                     0 ? MYCSRS_PKT_FLD_RNG_ ## f
#define MYCSRS_PKTF_MSB(f)                      (_MYCSRS_PKTF_MSB(f))
#define MYCSRS_PKTF_LSB(f)                      (_MYCSRS_PKTF_LSB(f))

#define MYCSRS_PKTF_WIDTH(f)                    (MYCSRS_PKTF_MSB(f) - MYCSRS_PKTF_LSB(f) + 1)
#define MYCSRS_PKTF_MASK_LOW(f)                 ((1 << MYCSRS_PKTF_WIDTH(f)) - 1)
#define MYCSRS_PKTF_MASK(f)                     (MYCSRS_PKTF_MASK(f) << MYCSRS_PKTF_LSB(f))

#define MYCSRS_CLRPF(fullPktVal,f)              ((fullPktVal) & ~MYCSRS_PKTF_MASK(f))
#define MYCSRS_GETPF(fullPktVal,f)              (((fullPktVal) >> MYCSRS_PKTF_LSB(f)) & MYCSRS_PKTF_MASK_LOW(f))
#define MYCSRS_SETPF(f,newFldVal)               ((newFldVal) << MYCSRS_PKTF_LSB(f))
#define MYCSRS_CHGPF(fullPktVal,f,newFldVal)    (MYCSRS_CLRPF(fullPktVal,f) | MYCSRS_SETPF(f,newFldVal))

#endif
