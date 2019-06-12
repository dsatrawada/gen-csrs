#ifndef MYCSRS_MMIOS_H_INCLUDED
#define MYCSRS_MMIOS_H_INCLUDED

#include "csr.h"
#include "mycsrs_pe_defines.h"

static CSR<0> int ;
static CR<4> intenable ;
static CSR<8> status ;
static CR<12> conf ;
static CR<16> infifo0 ;
static CR<20> outfifo0 ;
static CSR<24> sdaoen ;
static CSR<28> scloen ;
static CR<32> sdain ;
static CR<36> sclin ;
static CSR<40> scratch_pad_a_0 ;
static CSR<44> scratch_pad_a_1 ;
static CSR<48> scratch_pad_a_2 ;
static CSR<52> scratch_pad_a_3 ;
static CSR<56> scratch_pad_a_4 ;
static CSR<60> scratch_pad_a_5 ;
static CSR<64> scratch_pad_a_6 ;
static CSR<68> scratch_pad_a_7 ;
static CSR<72> scratch_pad_a_8 ;
static CSR<76> scratch_pad_a_9 ;
static CSR<80> scratch_pad_b_0 ;
static CSR<84> scratch_pad_b_1 ;
static CSR<88> scratch_pad_b_2 ;
static CSR<92> scratch_pad_b_3 ;
static CSR<96> scratch_pad_b_4 ;
static CSR<100> scratch_pad_b_5 ;
static CSR<104> scratch_pad_b_6 ;
static CSR<108> scratch_pad_b_7 ;
static CSR<112> scratch_pad_b_8 ;
static CSR<116> scratch_pad_b_9 ;
static CSR<120> scratch_pad_c_4 ;
static CSR<124> scratch_pad_c_5 ;
static CSR<128> scratch_pad_d_0 ;
static CSR<132> scratch_pad_d_1 ;
static CSR<136> scratch_pad_d_2 ;
static CSR<140> scratch_pad_d_3 ;
static CSR<144> scratch_pad_d_4 ;
static CSR<148> scratch_pad_d_5 ;
static CSR<152> scratch_pad_d_6 ;
static CSR<156> scratch_pad_d_7 ;
static CSR<160> scratch_pad_d_8 ;
static CSR<164> scratch_pad_d_9 ;
static CSR<168> scratch_pad_d_10 ;
static CSR<172> scratch_pad_d_11 ;
static CSR<176> scratch_pad_d_12 ;
static CSR<180> scratch_pad_d_13 ;
static CSR<184> scratch_pad_d_14 ;
static CSR<188> scratch_pad_d_15 ;

#endif
