#ifndef MYCSRS_HOST_DEFINES_H_INCLUDED
#define MYCSRS_HOST_DEFINES_H_INCLUDED

#ifndef MYCSRS_BASE
 #define MYCSRS_BASE 0x21000
#endif


// reg Int
#define MYCSRS_ADDR_int	(MYCSRS_BASE+0x00000008)
#define MYCSRS_FLD_RNG_int__respq_notempty	0:0
#define MYCSRS_FLD_RST_int__respq_notempty	0x1
#define MYCSRS_FLD_LSB_int__respq_notempty	0
#define MYCSRS_FLD_MSB_int__respq_notempty	0
#define MYCSRS_FLD_WTH_int__respq_notempty	1
#define MYCSRS_FLD_MSK_int__respq_notempty	0x1
#define MYCSRS_FLD_MSKLO_int__respq_notempty	0x1
#define MYCSRS_FLD_RNG_int__respq_full	1:1
#define MYCSRS_FLD_RST_int__respq_full	0x0
#define MYCSRS_FLD_LSB_int__respq_full	1
#define MYCSRS_FLD_MSB_int__respq_full	1
#define MYCSRS_FLD_WTH_int__respq_full	1
#define MYCSRS_FLD_MSK_int__respq_full	0x2
#define MYCSRS_FLD_MSKLO_int__respq_full	0x1
#define MYCSRS_FLD_RNG_int__cmdq_empty	2:2
#define MYCSRS_FLD_RST_int__cmdq_empty	0x0
#define MYCSRS_FLD_LSB_int__cmdq_empty	2
#define MYCSRS_FLD_MSB_int__cmdq_empty	2
#define MYCSRS_FLD_WTH_int__cmdq_empty	1
#define MYCSRS_FLD_MSK_int__cmdq_empty	0x4
#define MYCSRS_FLD_MSKLO_int__cmdq_empty	0x1
#define MYCSRS_FLD_RNG_int__res	31:3
#define MYCSRS_FLD_RST_int__res	0x0
#define MYCSRS_FLD_LSB_int__res	3
#define MYCSRS_FLD_MSB_int__res	31
#define MYCSRS_FLD_WTH_int__res	29
#define MYCSRS_FLD_MSK_int__res	0xFFFFFFF8
#define MYCSRS_FLD_MSKLO_int__res	0x1FFFFFFF
#define MYCSRS_RST_int	0x1
#define MYCSRS_MSK_RST_int	0xFFFFFFFF
#define MYCSRS_MSK_RW_int	0x0
#define MYCSRS_MSK_RW1C_int	0x7
#define MYCSRS_MSK_R_int	0x0
#define MYCSRS_MSK_RC_int	0xFFFFFFF8

// reg IntEnable
#define MYCSRS_ADDR_intenable	(MYCSRS_BASE+0x0000000C)
#define MYCSRS_FLD_RNG_intenable__respq_notempty	0:0
#define MYCSRS_FLD_RST_intenable__respq_notempty	0x0
#define MYCSRS_FLD_LSB_intenable__respq_notempty	0
#define MYCSRS_FLD_MSB_intenable__respq_notempty	0
#define MYCSRS_FLD_WTH_intenable__respq_notempty	1
#define MYCSRS_FLD_MSK_intenable__respq_notempty	0x1
#define MYCSRS_FLD_MSKLO_intenable__respq_notempty	0x1
#define MYCSRS_FLD_RNG_intenable__respq_full	1:1
#define MYCSRS_FLD_RST_intenable__respq_full	0x0
#define MYCSRS_FLD_LSB_intenable__respq_full	1
#define MYCSRS_FLD_MSB_intenable__respq_full	1
#define MYCSRS_FLD_WTH_intenable__respq_full	1
#define MYCSRS_FLD_MSK_intenable__respq_full	0x2
#define MYCSRS_FLD_MSKLO_intenable__respq_full	0x1
#define MYCSRS_FLD_RNG_intenable__cmdq_empty	2:2
#define MYCSRS_FLD_RST_intenable__cmdq_empty	0x0
#define MYCSRS_FLD_LSB_intenable__cmdq_empty	2
#define MYCSRS_FLD_MSB_intenable__cmdq_empty	2
#define MYCSRS_FLD_WTH_intenable__cmdq_empty	1
#define MYCSRS_FLD_MSK_intenable__cmdq_empty	0x4
#define MYCSRS_FLD_MSKLO_intenable__cmdq_empty	0x1
#define MYCSRS_FLD_RNG_intenable__res	31:3
#define MYCSRS_FLD_RST_intenable__res	0x0
#define MYCSRS_FLD_LSB_intenable__res	3
#define MYCSRS_FLD_MSB_intenable__res	31
#define MYCSRS_FLD_WTH_intenable__res	29
#define MYCSRS_FLD_MSK_intenable__res	0xFFFFFFF8
#define MYCSRS_FLD_MSKLO_intenable__res	0x1FFFFFFF
#define MYCSRS_RST_intenable	0x0
#define MYCSRS_MSK_RST_intenable	0xFFFFFFFF
#define MYCSRS_MSK_RW_intenable	0x7
#define MYCSRS_MSK_RW1C_intenable	0x0
#define MYCSRS_MSK_R_intenable	0x0
#define MYCSRS_MSK_RC_intenable	0xFFFFFFF8

// reg Status
#define MYCSRS_ADDR_status	(MYCSRS_BASE+0x00000010)
#define MYCSRS_FLD_RNG_status__respq_notempty	0:0
#define MYCSRS_FLD_RST_status__respq_notempty	0x0
#define MYCSRS_FLD_LSB_status__respq_notempty	0
#define MYCSRS_FLD_MSB_status__respq_notempty	0
#define MYCSRS_FLD_WTH_status__respq_notempty	1
#define MYCSRS_FLD_MSK_status__respq_notempty	0x1
#define MYCSRS_FLD_MSKLO_status__respq_notempty	0x1
#define MYCSRS_FLD_RNG_status__respq_full	1:1
#define MYCSRS_FLD_RST_status__respq_full	0x0
#define MYCSRS_FLD_LSB_status__respq_full	1
#define MYCSRS_FLD_MSB_status__respq_full	1
#define MYCSRS_FLD_WTH_status__respq_full	1
#define MYCSRS_FLD_MSK_status__respq_full	0x2
#define MYCSRS_FLD_MSKLO_status__respq_full	0x1
#define MYCSRS_FLD_RNG_status__cmdq_notempty	2:2
#define MYCSRS_FLD_RST_status__cmdq_notempty	0x0
#define MYCSRS_FLD_LSB_status__cmdq_notempty	2
#define MYCSRS_FLD_MSB_status__cmdq_notempty	2
#define MYCSRS_FLD_WTH_status__cmdq_notempty	1
#define MYCSRS_FLD_MSK_status__cmdq_notempty	0x4
#define MYCSRS_FLD_MSKLO_status__cmdq_notempty	0x1
#define MYCSRS_FLD_RNG_status__cmdq_full	3:3
#define MYCSRS_FLD_RST_status__cmdq_full	0x0
#define MYCSRS_FLD_LSB_status__cmdq_full	3
#define MYCSRS_FLD_MSB_status__cmdq_full	3
#define MYCSRS_FLD_WTH_status__cmdq_full	1
#define MYCSRS_FLD_MSK_status__cmdq_full	0x8
#define MYCSRS_FLD_MSKLO_status__cmdq_full	0x1
#define MYCSRS_FLD_RNG_status__res	30:4
#define MYCSRS_FLD_RST_status__res	0x0
#define MYCSRS_FLD_LSB_status__res	4
#define MYCSRS_FLD_MSB_status__res	30
#define MYCSRS_FLD_WTH_status__res	27
#define MYCSRS_FLD_MSK_status__res	0x7FFFFFF0
#define MYCSRS_FLD_MSKLO_status__res	0x7FFFFFF
#define MYCSRS_FLD_RNG_status__errorflag	31:31
#define MYCSRS_FLD_RST_status__errorflag	0x0
#define MYCSRS_FLD_LSB_status__errorflag	31
#define MYCSRS_FLD_MSB_status__errorflag	31
#define MYCSRS_FLD_WTH_status__errorflag	1
#define MYCSRS_FLD_MSK_status__errorflag	0x80000000
#define MYCSRS_FLD_MSKLO_status__errorflag	0x1
#define MYCSRS_RST_status	0x0
#define MYCSRS_MSK_RST_status	0xFFFFFFFF
#define MYCSRS_MSK_RW_status	0x0
#define MYCSRS_MSK_RW1C_status	0x80000000
#define MYCSRS_MSK_R_status	0xF
#define MYCSRS_MSK_RC_status	0x7FFFFFF0

// reg Conf
#define MYCSRS_ADDR_conf	(MYCSRS_BASE+0x00000014)
#define MYCSRS_FLD_RNG_conf__numretriesbeforeerror	3:0
#define MYCSRS_FLD_RST_conf__numretriesbeforeerror	0x0
#define MYCSRS_FLD_LSB_conf__numretriesbeforeerror	0
#define MYCSRS_FLD_MSB_conf__numretriesbeforeerror	3
#define MYCSRS_FLD_WTH_conf__numretriesbeforeerror	4
#define MYCSRS_FLD_MSK_conf__numretriesbeforeerror	0xF
#define MYCSRS_FLD_MSKLO_conf__numretriesbeforeerror	0xF
#define MYCSRS_FLD_RNG_conf__cmdq_almostemptylevel	15:8
#define MYCSRS_FLD_RST_conf__cmdq_almostemptylevel	0x2
#define MYCSRS_FLD_LSB_conf__cmdq_almostemptylevel	8
#define MYCSRS_FLD_MSB_conf__cmdq_almostemptylevel	15
#define MYCSRS_FLD_WTH_conf__cmdq_almostemptylevel	8
#define MYCSRS_FLD_MSK_conf__cmdq_almostemptylevel	0xFF00
#define MYCSRS_FLD_MSKLO_conf__cmdq_almostemptylevel	0xFF
#define MYCSRS_FLD_RNG_conf__respq_almostfulllevel	23:16
#define MYCSRS_FLD_RST_conf__respq_almostfulllevel	0x2
#define MYCSRS_FLD_LSB_conf__respq_almostfulllevel	16
#define MYCSRS_FLD_MSB_conf__respq_almostfulllevel	23
#define MYCSRS_FLD_WTH_conf__respq_almostfulllevel	8
#define MYCSRS_FLD_MSK_conf__respq_almostfulllevel	0xFF0000
#define MYCSRS_FLD_MSKLO_conf__respq_almostfulllevel	0xFF
#define MYCSRS_FLD_RNG_conf__halfbitdelay	31:24
#define MYCSRS_FLD_RST_conf__halfbitdelay	0x64
#define MYCSRS_FLD_LSB_conf__halfbitdelay	24
#define MYCSRS_FLD_MSB_conf__halfbitdelay	31
#define MYCSRS_FLD_WTH_conf__halfbitdelay	8
#define MYCSRS_FLD_MSK_conf__halfbitdelay	0xFF000000
#define MYCSRS_FLD_MSKLO_conf__halfbitdelay	0xFF
#define MYCSRS_RST_conf	0x64020200
#define MYCSRS_MSK_RST_conf	0xFFFFFF0F
#define MYCSRS_MSK_RW_conf	0xFFFFFF0F
#define MYCSRS_MSK_RW1C_conf	0x0
#define MYCSRS_MSK_R_conf	0x0
#define MYCSRS_MSK_RC_conf	0x0

// reg InFifo0
#define MYCSRS_ADDR_infifo0	(MYCSRS_BASE+0x00000018)
#define MYCSRS_FLD_RNG_infifo0__notempty	0:0
#define MYCSRS_FLD_RST_infifo0__notempty	0x0
#define MYCSRS_FLD_LSB_infifo0__notempty	0
#define MYCSRS_FLD_MSB_infifo0__notempty	0
#define MYCSRS_FLD_WTH_infifo0__notempty	1
#define MYCSRS_FLD_MSK_infifo0__notempty	0x1
#define MYCSRS_FLD_MSKLO_infifo0__notempty	0x1
#define MYCSRS_FLD_RNG_infifo0__full	1:1
#define MYCSRS_FLD_RST_infifo0__full	0x0
#define MYCSRS_FLD_LSB_infifo0__full	1
#define MYCSRS_FLD_MSB_infifo0__full	1
#define MYCSRS_FLD_WTH_infifo0__full	1
#define MYCSRS_FLD_MSK_infifo0__full	0x2
#define MYCSRS_FLD_MSKLO_infifo0__full	0x1
#define MYCSRS_RST_infifo0	0x0
#define MYCSRS_MSK_RST_infifo0	0x2
#define MYCSRS_MSK_RW_infifo0	0x0
#define MYCSRS_MSK_RW1C_infifo0	0x2
#define MYCSRS_MSK_R_infifo0	0x1
#define MYCSRS_MSK_RC_infifo0	0x0

// reg OutFifo0
#define MYCSRS_ADDR_outfifo0	(MYCSRS_BASE+0x0000001C)
#define MYCSRS_FLD_RNG_outfifo0__notempty	0:0
#define MYCSRS_FLD_RST_outfifo0__notempty	0x0
#define MYCSRS_FLD_LSB_outfifo0__notempty	0
#define MYCSRS_FLD_MSB_outfifo0__notempty	0
#define MYCSRS_FLD_WTH_outfifo0__notempty	1
#define MYCSRS_FLD_MSK_outfifo0__notempty	0x1
#define MYCSRS_FLD_MSKLO_outfifo0__notempty	0x1
#define MYCSRS_FLD_RNG_outfifo0__full	1:1
#define MYCSRS_FLD_RST_outfifo0__full	0x0
#define MYCSRS_FLD_LSB_outfifo0__full	1
#define MYCSRS_FLD_MSB_outfifo0__full	1
#define MYCSRS_FLD_WTH_outfifo0__full	1
#define MYCSRS_FLD_MSK_outfifo0__full	0x2
#define MYCSRS_FLD_MSKLO_outfifo0__full	0x1
#define MYCSRS_RST_outfifo0	0x0
#define MYCSRS_MSK_RST_outfifo0	0x0
#define MYCSRS_MSK_RW_outfifo0	0x0
#define MYCSRS_MSK_RW1C_outfifo0	0x0
#define MYCSRS_MSK_R_outfifo0	0x3
#define MYCSRS_MSK_RC_outfifo0	0x0

// reg SdaOeN
#define MYCSRS_ADDR_sdaoen	(MYCSRS_BASE+0x00000020)
#define MYCSRS_FLD_RNG_sdaoen__val	0:0
#define MYCSRS_FLD_RST_sdaoen__val	0x0
#define MYCSRS_FLD_LSB_sdaoen__val	0
#define MYCSRS_FLD_MSB_sdaoen__val	0
#define MYCSRS_FLD_WTH_sdaoen__val	1
#define MYCSRS_FLD_MSK_sdaoen__val	0x1
#define MYCSRS_FLD_MSKLO_sdaoen__val	0x1
#define MYCSRS_FLD_RNG_sdaoen__res	31:1
#define MYCSRS_FLD_RST_sdaoen__res	0x0
#define MYCSRS_FLD_LSB_sdaoen__res	1
#define MYCSRS_FLD_MSB_sdaoen__res	31
#define MYCSRS_FLD_WTH_sdaoen__res	31
#define MYCSRS_FLD_MSK_sdaoen__res	0xFFFFFFFE
#define MYCSRS_FLD_MSKLO_sdaoen__res	0x7FFFFFFF
#define MYCSRS_RST_sdaoen	0x0
#define MYCSRS_MSK_RST_sdaoen	0xFFFFFFFF
#define MYCSRS_MSK_RW_sdaoen	0x0
#define MYCSRS_MSK_RW1C_sdaoen	0x0
#define MYCSRS_MSK_R_sdaoen	0x0
#define MYCSRS_MSK_RC_sdaoen	0x0

// reg SclOeN
#define MYCSRS_ADDR_scloen	(MYCSRS_BASE+0x00000024)
#define MYCSRS_FLD_RNG_scloen__val	0:0
#define MYCSRS_FLD_RST_scloen__val	0x0
#define MYCSRS_FLD_LSB_scloen__val	0
#define MYCSRS_FLD_MSB_scloen__val	0
#define MYCSRS_FLD_WTH_scloen__val	1
#define MYCSRS_FLD_MSK_scloen__val	0x1
#define MYCSRS_FLD_MSKLO_scloen__val	0x1
#define MYCSRS_FLD_RNG_scloen__res	31:1
#define MYCSRS_FLD_RST_scloen__res	0x0
#define MYCSRS_FLD_LSB_scloen__res	1
#define MYCSRS_FLD_MSB_scloen__res	31
#define MYCSRS_FLD_WTH_scloen__res	31
#define MYCSRS_FLD_MSK_scloen__res	0xFFFFFFFE
#define MYCSRS_FLD_MSKLO_scloen__res	0x7FFFFFFF
#define MYCSRS_RST_scloen	0x0
#define MYCSRS_MSK_RST_scloen	0xFFFFFFFF
#define MYCSRS_MSK_RW_scloen	0x0
#define MYCSRS_MSK_RW1C_scloen	0x0
#define MYCSRS_MSK_R_scloen	0x0
#define MYCSRS_MSK_RC_scloen	0x0

// reg SdaIn
#define MYCSRS_ADDR_sdain	(MYCSRS_BASE+0x00000028)
#define MYCSRS_FLD_RNG_sdain__val	0:0
#define MYCSRS_FLD_RST_sdain__val	0x0
#define MYCSRS_FLD_LSB_sdain__val	0
#define MYCSRS_FLD_MSB_sdain__val	0
#define MYCSRS_FLD_WTH_sdain__val	1
#define MYCSRS_FLD_MSK_sdain__val	0x1
#define MYCSRS_FLD_MSKLO_sdain__val	0x1
#define MYCSRS_FLD_RNG_sdain__res	31:1
#define MYCSRS_FLD_RST_sdain__res	0x0
#define MYCSRS_FLD_LSB_sdain__res	1
#define MYCSRS_FLD_MSB_sdain__res	31
#define MYCSRS_FLD_WTH_sdain__res	31
#define MYCSRS_FLD_MSK_sdain__res	0xFFFFFFFE
#define MYCSRS_FLD_MSKLO_sdain__res	0x7FFFFFFF
#define MYCSRS_RST_sdain	0x0
#define MYCSRS_MSK_RST_sdain	0xFFFFFFFE
#define MYCSRS_MSK_RW_sdain	0x0
#define MYCSRS_MSK_RW1C_sdain	0x0
#define MYCSRS_MSK_R_sdain	0x0
#define MYCSRS_MSK_RC_sdain	0x0

// reg SclIn
#define MYCSRS_ADDR_sclin	(MYCSRS_BASE+0x0000002C)
#define MYCSRS_FLD_RNG_sclin__val	0:0
#define MYCSRS_FLD_RST_sclin__val	0x0
#define MYCSRS_FLD_LSB_sclin__val	0
#define MYCSRS_FLD_MSB_sclin__val	0
#define MYCSRS_FLD_WTH_sclin__val	1
#define MYCSRS_FLD_MSK_sclin__val	0x1
#define MYCSRS_FLD_MSKLO_sclin__val	0x1
#define MYCSRS_FLD_RNG_sclin__res	31:1
#define MYCSRS_FLD_RST_sclin__res	0x0
#define MYCSRS_FLD_LSB_sclin__res	1
#define MYCSRS_FLD_MSB_sclin__res	31
#define MYCSRS_FLD_WTH_sclin__res	31
#define MYCSRS_FLD_MSK_sclin__res	0xFFFFFFFE
#define MYCSRS_FLD_MSKLO_sclin__res	0x7FFFFFFF
#define MYCSRS_RST_sclin	0x0
#define MYCSRS_MSK_RST_sclin	0xFFFFFFFE
#define MYCSRS_MSK_RW_sclin	0x0
#define MYCSRS_MSK_RW1C_sclin	0x0
#define MYCSRS_MSK_R_sclin	0x0
#define MYCSRS_MSK_RC_sclin	0x0

// reg scratch_pad_a_0
#define MYCSRS_INCR_scratch_pad_a_0	8
#define MYCSRS_ADDR_scratch_pad_a_0	(MYCSRS_BASE+0x00000030)
#define MYCSRS_FLD_RNG_scratch_pad_a_0__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_0__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_0__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_0__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_0__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_0__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_0__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_0	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_0	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_0	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_0	0x0
#define MYCSRS_MSK_R_scratch_pad_a_0	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_0	0x0

// reg scratch_pad_a_1
#define MYCSRS_ADDR_scratch_pad_a_1	(MYCSRS_BASE+0x00000038)
#define MYCSRS_FLD_RNG_scratch_pad_a_1__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_1__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_1__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_1__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_1__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_1__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_1__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_1	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_1	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_1	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_1	0x0
#define MYCSRS_MSK_R_scratch_pad_a_1	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_1	0x0

// reg scratch_pad_a_2
#define MYCSRS_ADDR_scratch_pad_a_2	(MYCSRS_BASE+0x00000040)
#define MYCSRS_FLD_RNG_scratch_pad_a_2__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_2__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_2__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_2__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_2__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_2__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_2__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_2	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_2	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_2	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_2	0x0
#define MYCSRS_MSK_R_scratch_pad_a_2	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_2	0x0

// reg scratch_pad_a_3
#define MYCSRS_ADDR_scratch_pad_a_3	(MYCSRS_BASE+0x00000048)
#define MYCSRS_FLD_RNG_scratch_pad_a_3__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_3__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_3__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_3__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_3__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_3__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_3__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_3	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_3	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_3	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_3	0x0
#define MYCSRS_MSK_R_scratch_pad_a_3	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_3	0x0

// reg scratch_pad_a_4
#define MYCSRS_ADDR_scratch_pad_a_4	(MYCSRS_BASE+0x00000050)
#define MYCSRS_FLD_RNG_scratch_pad_a_4__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_4__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_4__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_4__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_4__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_4__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_4__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_4	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_4	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_4	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_4	0x0
#define MYCSRS_MSK_R_scratch_pad_a_4	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_4	0x0

// reg scratch_pad_a_5
#define MYCSRS_ADDR_scratch_pad_a_5	(MYCSRS_BASE+0x00000058)
#define MYCSRS_FLD_RNG_scratch_pad_a_5__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_5__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_5__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_5__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_5__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_5__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_5__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_5	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_5	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_5	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_5	0x0
#define MYCSRS_MSK_R_scratch_pad_a_5	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_5	0x0

// reg scratch_pad_a_6
#define MYCSRS_ADDR_scratch_pad_a_6	(MYCSRS_BASE+0x00000060)
#define MYCSRS_FLD_RNG_scratch_pad_a_6__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_6__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_6__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_6__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_6__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_6__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_6__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_6	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_6	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_6	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_6	0x0
#define MYCSRS_MSK_R_scratch_pad_a_6	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_6	0x0

// reg scratch_pad_a_7
#define MYCSRS_ADDR_scratch_pad_a_7	(MYCSRS_BASE+0x00000068)
#define MYCSRS_FLD_RNG_scratch_pad_a_7__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_7__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_7__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_7__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_7__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_7__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_7__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_7	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_7	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_7	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_7	0x0
#define MYCSRS_MSK_R_scratch_pad_a_7	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_7	0x0

// reg scratch_pad_a_8
#define MYCSRS_ADDR_scratch_pad_a_8	(MYCSRS_BASE+0x00000070)
#define MYCSRS_FLD_RNG_scratch_pad_a_8__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_8__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_8__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_8__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_8__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_8__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_8__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_8	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_8	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_8	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_8	0x0
#define MYCSRS_MSK_R_scratch_pad_a_8	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_8	0x0

// reg scratch_pad_a_9
#define MYCSRS_ADDR_scratch_pad_a_9	(MYCSRS_BASE+0x00000078)
#define MYCSRS_FLD_RNG_scratch_pad_a_9__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_a_9__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_a_9__val	0
#define MYCSRS_FLD_MSB_scratch_pad_a_9__val	31
#define MYCSRS_FLD_WTH_scratch_pad_a_9__val	32
#define MYCSRS_FLD_MSK_scratch_pad_a_9__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_a_9__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_a_9	0x0
#define MYCSRS_MSK_RST_scratch_pad_a_9	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_a_9	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_a_9	0x0
#define MYCSRS_MSK_R_scratch_pad_a_9	0x0
#define MYCSRS_MSK_RC_scratch_pad_a_9	0x0

// reg scratch_pad_b_0
#define MYCSRS_INCR_scratch_pad_b_0	8
#define MYCSRS_ADDR_scratch_pad_b_0	(MYCSRS_BASE+0x00000034)
#define MYCSRS_FLD_RNG_scratch_pad_b_0__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_0__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_0__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_0__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_0__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_0__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_0__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_0	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_0	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_0	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_0	0x0
#define MYCSRS_MSK_R_scratch_pad_b_0	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_0	0x0

// reg scratch_pad_b_1
#define MYCSRS_ADDR_scratch_pad_b_1	(MYCSRS_BASE+0x0000003C)
#define MYCSRS_FLD_RNG_scratch_pad_b_1__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_1__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_1__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_1__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_1__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_1__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_1__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_1	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_1	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_1	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_1	0x0
#define MYCSRS_MSK_R_scratch_pad_b_1	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_1	0x0

// reg scratch_pad_b_2
#define MYCSRS_ADDR_scratch_pad_b_2	(MYCSRS_BASE+0x00000044)
#define MYCSRS_FLD_RNG_scratch_pad_b_2__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_2__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_2__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_2__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_2__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_2__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_2__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_2	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_2	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_2	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_2	0x0
#define MYCSRS_MSK_R_scratch_pad_b_2	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_2	0x0

// reg scratch_pad_b_3
#define MYCSRS_ADDR_scratch_pad_b_3	(MYCSRS_BASE+0x0000004C)
#define MYCSRS_FLD_RNG_scratch_pad_b_3__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_3__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_3__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_3__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_3__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_3__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_3__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_3	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_3	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_3	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_3	0x0
#define MYCSRS_MSK_R_scratch_pad_b_3	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_3	0x0

// reg scratch_pad_b_4
#define MYCSRS_ADDR_scratch_pad_b_4	(MYCSRS_BASE+0x00000054)
#define MYCSRS_FLD_RNG_scratch_pad_b_4__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_4__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_4__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_4__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_4__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_4__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_4__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_4	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_4	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_4	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_4	0x0
#define MYCSRS_MSK_R_scratch_pad_b_4	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_4	0x0

// reg scratch_pad_b_5
#define MYCSRS_ADDR_scratch_pad_b_5	(MYCSRS_BASE+0x0000005C)
#define MYCSRS_FLD_RNG_scratch_pad_b_5__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_5__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_5__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_5__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_5__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_5__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_5__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_5	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_5	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_5	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_5	0x0
#define MYCSRS_MSK_R_scratch_pad_b_5	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_5	0x0

// reg scratch_pad_b_6
#define MYCSRS_ADDR_scratch_pad_b_6	(MYCSRS_BASE+0x00000064)
#define MYCSRS_FLD_RNG_scratch_pad_b_6__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_6__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_6__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_6__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_6__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_6__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_6__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_6	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_6	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_6	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_6	0x0
#define MYCSRS_MSK_R_scratch_pad_b_6	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_6	0x0

// reg scratch_pad_b_7
#define MYCSRS_ADDR_scratch_pad_b_7	(MYCSRS_BASE+0x0000006C)
#define MYCSRS_FLD_RNG_scratch_pad_b_7__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_7__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_7__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_7__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_7__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_7__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_7__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_7	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_7	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_7	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_7	0x0
#define MYCSRS_MSK_R_scratch_pad_b_7	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_7	0x0

// reg scratch_pad_b_8
#define MYCSRS_ADDR_scratch_pad_b_8	(MYCSRS_BASE+0x00000074)
#define MYCSRS_FLD_RNG_scratch_pad_b_8__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_8__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_8__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_8__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_8__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_8__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_8__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_8	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_8	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_8	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_8	0x0
#define MYCSRS_MSK_R_scratch_pad_b_8	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_8	0x0

// reg scratch_pad_b_9
#define MYCSRS_ADDR_scratch_pad_b_9	(MYCSRS_BASE+0x0000007C)
#define MYCSRS_FLD_RNG_scratch_pad_b_9__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_b_9__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_b_9__val	0
#define MYCSRS_FLD_MSB_scratch_pad_b_9__val	31
#define MYCSRS_FLD_WTH_scratch_pad_b_9__val	32
#define MYCSRS_FLD_MSK_scratch_pad_b_9__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_b_9__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_b_9	0x0
#define MYCSRS_MSK_RST_scratch_pad_b_9	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_b_9	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_b_9	0x0
#define MYCSRS_MSK_R_scratch_pad_b_9	0x0
#define MYCSRS_MSK_RC_scratch_pad_b_9	0x0

// reg scratch_pad_c_4
#define MYCSRS_ADDR_scratch_pad_c_0	(MYCSRS_BASE+0x00000070)
#define MYCSRS_INCR_scratch_pad_c_0	4
#define MYCSRS_ADDR_scratch_pad_c_4	(MYCSRS_BASE+0x00000080)
#define MYCSRS_FLD_RNG_scratch_pad_c_4__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_c_4__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_c_4__val	0
#define MYCSRS_FLD_MSB_scratch_pad_c_4__val	31
#define MYCSRS_FLD_WTH_scratch_pad_c_4__val	32
#define MYCSRS_FLD_MSK_scratch_pad_c_4__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_c_4__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_c_4	0x0
#define MYCSRS_MSK_RST_scratch_pad_c_4	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_c_4	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_c_4	0x0
#define MYCSRS_MSK_R_scratch_pad_c_4	0x0
#define MYCSRS_MSK_RC_scratch_pad_c_4	0x0

// reg scratch_pad_c_5
#define MYCSRS_ADDR_scratch_pad_c_5	(MYCSRS_BASE+0x00000084)
#define MYCSRS_FLD_RNG_scratch_pad_c_5__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_c_5__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_c_5__val	0
#define MYCSRS_FLD_MSB_scratch_pad_c_5__val	31
#define MYCSRS_FLD_WTH_scratch_pad_c_5__val	32
#define MYCSRS_FLD_MSK_scratch_pad_c_5__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_c_5__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_c_5	0x0
#define MYCSRS_MSK_RST_scratch_pad_c_5	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_c_5	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_c_5	0x0
#define MYCSRS_MSK_R_scratch_pad_c_5	0x0
#define MYCSRS_MSK_RC_scratch_pad_c_5	0x0

// reg scratch_pad_d_0
#define MYCSRS_INCR_scratch_pad_d_0	4
#define MYCSRS_ADDR_scratch_pad_d_0	(MYCSRS_BASE+0x00000088)
#define MYCSRS_FLD_RNG_scratch_pad_d_0__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_0__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_0__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_0__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_0__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_0__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_0__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_0	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_0	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_0	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_0	0x0
#define MYCSRS_MSK_R_scratch_pad_d_0	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_0	0x0

// reg scratch_pad_d_1
#define MYCSRS_ADDR_scratch_pad_d_1	(MYCSRS_BASE+0x0000008C)
#define MYCSRS_FLD_RNG_scratch_pad_d_1__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_1__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_1__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_1__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_1__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_1__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_1__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_1	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_1	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_1	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_1	0x0
#define MYCSRS_MSK_R_scratch_pad_d_1	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_1	0x0

// reg scratch_pad_d_2
#define MYCSRS_ADDR_scratch_pad_d_2	(MYCSRS_BASE+0x00000090)
#define MYCSRS_FLD_RNG_scratch_pad_d_2__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_2__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_2__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_2__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_2__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_2__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_2__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_2	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_2	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_2	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_2	0x0
#define MYCSRS_MSK_R_scratch_pad_d_2	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_2	0x0

// reg scratch_pad_d_3
#define MYCSRS_ADDR_scratch_pad_d_3	(MYCSRS_BASE+0x00000094)
#define MYCSRS_FLD_RNG_scratch_pad_d_3__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_3__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_3__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_3__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_3__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_3__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_3__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_3	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_3	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_3	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_3	0x0
#define MYCSRS_MSK_R_scratch_pad_d_3	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_3	0x0

// reg scratch_pad_d_4
#define MYCSRS_ADDR_scratch_pad_d_4	(MYCSRS_BASE+0x00000098)
#define MYCSRS_FLD_RNG_scratch_pad_d_4__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_4__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_4__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_4__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_4__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_4__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_4__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_4	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_4	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_4	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_4	0x0
#define MYCSRS_MSK_R_scratch_pad_d_4	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_4	0x0

// reg scratch_pad_d_5
#define MYCSRS_ADDR_scratch_pad_d_5	(MYCSRS_BASE+0x0000009C)
#define MYCSRS_FLD_RNG_scratch_pad_d_5__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_5__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_5__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_5__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_5__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_5__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_5__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_5	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_5	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_5	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_5	0x0
#define MYCSRS_MSK_R_scratch_pad_d_5	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_5	0x0

// reg scratch_pad_d_6
#define MYCSRS_ADDR_scratch_pad_d_6	(MYCSRS_BASE+0x000000A0)
#define MYCSRS_FLD_RNG_scratch_pad_d_6__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_6__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_6__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_6__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_6__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_6__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_6__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_6	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_6	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_6	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_6	0x0
#define MYCSRS_MSK_R_scratch_pad_d_6	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_6	0x0

// reg scratch_pad_d_7
#define MYCSRS_ADDR_scratch_pad_d_7	(MYCSRS_BASE+0x000000A4)
#define MYCSRS_FLD_RNG_scratch_pad_d_7__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_7__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_7__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_7__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_7__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_7__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_7__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_7	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_7	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_7	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_7	0x0
#define MYCSRS_MSK_R_scratch_pad_d_7	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_7	0x0

// reg scratch_pad_d_8
#define MYCSRS_ADDR_scratch_pad_d_8	(MYCSRS_BASE+0x000000A8)
#define MYCSRS_FLD_RNG_scratch_pad_d_8__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_8__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_8__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_8__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_8__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_8__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_8__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_8	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_8	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_8	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_8	0x0
#define MYCSRS_MSK_R_scratch_pad_d_8	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_8	0x0

// reg scratch_pad_d_9
#define MYCSRS_ADDR_scratch_pad_d_9	(MYCSRS_BASE+0x000000AC)
#define MYCSRS_FLD_RNG_scratch_pad_d_9__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_9__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_9__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_9__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_9__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_9__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_9__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_9	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_9	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_9	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_9	0x0
#define MYCSRS_MSK_R_scratch_pad_d_9	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_9	0x0

// reg scratch_pad_d_10
#define MYCSRS_ADDR_scratch_pad_d_10	(MYCSRS_BASE+0x000000B0)
#define MYCSRS_FLD_RNG_scratch_pad_d_10__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_10__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_10__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_10__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_10__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_10__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_10__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_10	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_10	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_10	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_10	0x0
#define MYCSRS_MSK_R_scratch_pad_d_10	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_10	0x0

// reg scratch_pad_d_11
#define MYCSRS_ADDR_scratch_pad_d_11	(MYCSRS_BASE+0x000000B4)
#define MYCSRS_FLD_RNG_scratch_pad_d_11__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_11__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_11__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_11__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_11__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_11__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_11__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_11	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_11	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_11	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_11	0x0
#define MYCSRS_MSK_R_scratch_pad_d_11	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_11	0x0

// reg scratch_pad_d_12
#define MYCSRS_ADDR_scratch_pad_d_12	(MYCSRS_BASE+0x000000B8)
#define MYCSRS_FLD_RNG_scratch_pad_d_12__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_12__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_12__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_12__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_12__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_12__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_12__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_12	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_12	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_12	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_12	0x0
#define MYCSRS_MSK_R_scratch_pad_d_12	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_12	0x0

// reg scratch_pad_d_13
#define MYCSRS_ADDR_scratch_pad_d_13	(MYCSRS_BASE+0x000000BC)
#define MYCSRS_FLD_RNG_scratch_pad_d_13__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_13__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_13__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_13__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_13__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_13__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_13__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_13	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_13	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_13	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_13	0x0
#define MYCSRS_MSK_R_scratch_pad_d_13	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_13	0x0

// reg scratch_pad_d_14
#define MYCSRS_ADDR_scratch_pad_d_14	(MYCSRS_BASE+0x000000C0)
#define MYCSRS_FLD_RNG_scratch_pad_d_14__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_14__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_14__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_14__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_14__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_14__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_14__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_14	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_14	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_14	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_14	0x0
#define MYCSRS_MSK_R_scratch_pad_d_14	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_14	0x0

// reg scratch_pad_d_15
#define MYCSRS_ADDR_scratch_pad_d_15	(MYCSRS_BASE+0x000000C4)
#define MYCSRS_FLD_RNG_scratch_pad_d_15__val	31:0
#define MYCSRS_FLD_RST_scratch_pad_d_15__val	0x0
#define MYCSRS_FLD_LSB_scratch_pad_d_15__val	0
#define MYCSRS_FLD_MSB_scratch_pad_d_15__val	31
#define MYCSRS_FLD_WTH_scratch_pad_d_15__val	32
#define MYCSRS_FLD_MSK_scratch_pad_d_15__val	0xFFFFFFFF
#define MYCSRS_FLD_MSKLO_scratch_pad_d_15__val	0xFFFFFFFF
#define MYCSRS_RST_scratch_pad_d_15	0x0
#define MYCSRS_MSK_RST_scratch_pad_d_15	0xFFFFFFFF
#define MYCSRS_MSK_RW_scratch_pad_d_15	0xFFFFFFFF
#define MYCSRS_MSK_RW1C_scratch_pad_d_15	0x0
#define MYCSRS_MSK_R_scratch_pad_d_15	0x0
#define MYCSRS_MSK_RC_scratch_pad_d_15	0x0

#define MYCSRS_REG_LIST(op) \
 op(int) \
 op(intenable) \
 op(status) \
 op(conf) \
 op(infifo0) \
 op(outfifo0) \
 op(sdaoen) \
 op(scloen) \
 op(sdain) \
 op(sclin) \
 op(scratch_pad_a_0) \
 op(scratch_pad_a_1) \
 op(scratch_pad_a_2) \
 op(scratch_pad_a_3) \
 op(scratch_pad_a_4) \
 op(scratch_pad_a_5) \
 op(scratch_pad_a_6) \
 op(scratch_pad_a_7) \
 op(scratch_pad_a_8) \
 op(scratch_pad_a_9) \
 op(scratch_pad_b_0) \
 op(scratch_pad_b_1) \
 op(scratch_pad_b_2) \
 op(scratch_pad_b_3) \
 op(scratch_pad_b_4) \
 op(scratch_pad_b_5) \
 op(scratch_pad_b_6) \
 op(scratch_pad_b_7) \
 op(scratch_pad_b_8) \
 op(scratch_pad_b_9) \
 op(scratch_pad_c_4) \
 op(scratch_pad_c_5) \
 op(scratch_pad_d_0) \
 op(scratch_pad_d_1) \
 op(scratch_pad_d_2) \
 op(scratch_pad_d_3) \
 op(scratch_pad_d_4) \
 op(scratch_pad_d_5) \
 op(scratch_pad_d_6) \
 op(scratch_pad_d_7) \
 op(scratch_pad_d_8) \
 op(scratch_pad_d_9) \
 op(scratch_pad_d_10) \
 op(scratch_pad_d_11) \
 op(scratch_pad_d_12) \
 op(scratch_pad_d_13) \
 op(scratch_pad_d_14) \
 op(scratch_pad_d_15) \

#define MYCSRS_REG_FIELD_LIST(op) \
 op(int,int__respq_notempty) \
 op(int,int__respq_full) \
 op(int,int__cmdq_empty) \
 op(int,int__res) \
 op(intenable,intenable__respq_notempty) \
 op(intenable,intenable__respq_full) \
 op(intenable,intenable__cmdq_empty) \
 op(intenable,intenable__res) \
 op(status,status__respq_notempty) \
 op(status,status__respq_full) \
 op(status,status__cmdq_notempty) \
 op(status,status__cmdq_full) \
 op(status,status__res) \
 op(status,status__errorflag) \
 op(conf,conf__numretriesbeforeerror) \
 op(conf,conf__cmdq_almostemptylevel) \
 op(conf,conf__respq_almostfulllevel) \
 op(conf,conf__halfbitdelay) \
 op(infifo0,infifo0__notempty) \
 op(infifo0,infifo0__full) \
 op(outfifo0,outfifo0__notempty) \
 op(outfifo0,outfifo0__full) \
 op(sdaoen,sdaoen__val) \
 op(sdaoen,sdaoen__res) \
 op(scloen,scloen__val) \
 op(scloen,scloen__res) \
 op(sdain,sdain__val) \
 op(sdain,sdain__res) \
 op(sclin,sclin__val) \
 op(sclin,sclin__res) \
 op(scratch_pad_a_0,scratch_pad_a_0__val) \
 op(scratch_pad_a_1,scratch_pad_a_1__val) \
 op(scratch_pad_a_2,scratch_pad_a_2__val) \
 op(scratch_pad_a_3,scratch_pad_a_3__val) \
 op(scratch_pad_a_4,scratch_pad_a_4__val) \
 op(scratch_pad_a_5,scratch_pad_a_5__val) \
 op(scratch_pad_a_6,scratch_pad_a_6__val) \
 op(scratch_pad_a_7,scratch_pad_a_7__val) \
 op(scratch_pad_a_8,scratch_pad_a_8__val) \
 op(scratch_pad_a_9,scratch_pad_a_9__val) \
 op(scratch_pad_b_0,scratch_pad_b_0__val) \
 op(scratch_pad_b_1,scratch_pad_b_1__val) \
 op(scratch_pad_b_2,scratch_pad_b_2__val) \
 op(scratch_pad_b_3,scratch_pad_b_3__val) \
 op(scratch_pad_b_4,scratch_pad_b_4__val) \
 op(scratch_pad_b_5,scratch_pad_b_5__val) \
 op(scratch_pad_b_6,scratch_pad_b_6__val) \
 op(scratch_pad_b_7,scratch_pad_b_7__val) \
 op(scratch_pad_b_8,scratch_pad_b_8__val) \
 op(scratch_pad_b_9,scratch_pad_b_9__val) \
 op(scratch_pad_c_4,scratch_pad_c_4__val) \
 op(scratch_pad_c_5,scratch_pad_c_5__val) \
 op(scratch_pad_d_0,scratch_pad_d_0__val) \
 op(scratch_pad_d_1,scratch_pad_d_1__val) \
 op(scratch_pad_d_2,scratch_pad_d_2__val) \
 op(scratch_pad_d_3,scratch_pad_d_3__val) \
 op(scratch_pad_d_4,scratch_pad_d_4__val) \
 op(scratch_pad_d_5,scratch_pad_d_5__val) \
 op(scratch_pad_d_6,scratch_pad_d_6__val) \
 op(scratch_pad_d_7,scratch_pad_d_7__val) \
 op(scratch_pad_d_8,scratch_pad_d_8__val) \
 op(scratch_pad_d_9,scratch_pad_d_9__val) \
 op(scratch_pad_d_10,scratch_pad_d_10__val) \
 op(scratch_pad_d_11,scratch_pad_d_11__val) \
 op(scratch_pad_d_12,scratch_pad_d_12__val) \
 op(scratch_pad_d_13,scratch_pad_d_13__val) \
 op(scratch_pad_d_14,scratch_pad_d_14__val) \
 op(scratch_pad_d_15,scratch_pad_d_15__val) \

// reg access macros
#define MYCSRS_ADDRI(r,i)                       (MYCSRS_ADDR_ ## r ## _0 + (i) * MYCSRS_INCR_ ## r ## _0)
#define MYCSRS_ADDR(r)                          MYCSRS_ADDR_  ## r

#define MYCSRS_REGF_RST(f)                      MYCSRS_FLD_RST_  ## f
#define MYCSRS_REGF_ENUM(f,e)                   MYCSRS_FLD_ENUM_ ## f ## __ ## e
#define MYCSRS_REGF_MSB(f)                      MYCSRS_FLD_MSB_  ## f
#define MYCSRS_REGF_LSB(f)                      MYCSRS_FLD_LSB_  ## f
#define MYCSRS_REGF_WIDTH(f)                    MYCSRS_FLD_WTH_  ## f
#define MYCSRS_REGF_MASK(f)                     MYCSRS_FLD_MSK_  ## f
#define MYCSRS_REGF_MASK_LOW(f)                 MYCSRS_FLD_MSKLO_ ## f

#define MYCSRS_RST_VALUE(f)                     MYCSRS_RST_   ## f
#define MYCSRS_RST_VLD(f)                       MYCSRS_MSK_RST_ ## f
#define MYCSRS_CLRF(fullRegVal,f)               ((fullRegVal) & ~MYCSRS_REGF_MASK(f))
#define MYCSRS_GETF(fullRegVal,f)               (((fullRegVal) >> MYCSRS_REGF_LSB(f)) & MYCSRS_REGF_MASK_LOW(f))
#define MYCSRS_SETF(f,newFldVal)                ((newFldVal) << MYCSRS_REGF_LSB(f))
#define MYCSRS_CHGF(fullRegVal,f,newFldVal)     (MYCSRS_CLRF(fullRegVal,f) | MYCSRS_SETF(f,newFldVal))

// Examples:
//
// reg = RegisterRead( MYCSRS_ADDR(PE0_register1) );
// reg = MYCSRS_CHGF( reg, PE0_register1__field0, 3 );
// RegisterWrite( MYCSRS_ADDR(PE0_register1), reg );
//
// reg = RegisterRead( MYCSRS_ADDR(PE2_status) );
// if ( MYCSRS_GETF( reg, PE2_status__busy ) == 1 ) { ... } 

#endif
