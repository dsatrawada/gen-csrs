$data_in = {
             'PKT_ARRAY' => [
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'N',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Number of bytes to write (0 is interpreted as 256)'
                                         },
                                         {
                                           'NAME' => 'waddr',
                                           'BIT_RANGE' => '15:8',
                                           'DOC' => 'Starting address to write'
                                         },
                                         {
                                           'NAME' => 'slave_addr',
                                           'BIT_RANGE' => '25:16',
                                           'DOC' => 'Slave device Address. If 7-bit addressing, LSB aligned'
                                         },
                                         {
                                           'NAME' => 'use_10b_addressing',
                                           'BIT_RANGE' => '26',
                                           'DOC' => '1:Use 10-bit I2C addressing, 0:Use 7-bit I2C addressing'
                                         },
                                         {
                                           'NAME' => 'rr',
                                           'BIT_RANGE' => '27',
                                           'DOC' => 'Response Request. If set the I2C master will send a response after this command is complete. See WriteResp packet'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => 'Set to 0 for this command'
                                         }
                                       ],
                              'NAME' => 'Write',
                              'DOC' => 'Write N-bytes from a specific address COMMAND format'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'N',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Number of bytes to read (0 is interpreted as 256)'
                                         },
                                         {
                                           'NAME' => 'raddr',
                                           'BIT_RANGE' => '15:8',
                                           'DOC' => 'Starting address to read'
                                         },
                                         {
                                           'NAME' => 'slave_addr',
                                           'BIT_RANGE' => '25:16',
                                           'DOC' => 'Slave device Address. If 7-bit addressing, LSB aligned'
                                         },
                                         {
                                           'NAME' => 'use_10b_addressing',
                                           'BIT_RANGE' => '26',
                                           'DOC' => '1:Use 10-bit I2C addressing, 0:Use 7-bit I2C addressing'
                                         },
                                         {
                                           'NAME' => 'res',
                                           'BIT_RANGE' => '27',
                                           'DOC' => 'reserved'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => 'Set to 1 for this command'
                                         }
                                       ],
                              'NAME' => 'Read',
                              'DOC' => 'Read N-bytes from a specific address COMMAND format'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'wdata',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Data Byte to write'
                                         },
                                         {
                                           'NAME' => 'waddr',
                                           'BIT_RANGE' => '15:8',
                                           'DOC' => 'Address to write'
                                         },
                                         {
                                           'NAME' => 'slave_addr',
                                           'BIT_RANGE' => '25:16',
                                           'DOC' => 'Slave device Address. If 7-bit addressing, LSB aligned'
                                         },
                                         {
                                           'NAME' => 'use_10b_addressing',
                                           'BIT_RANGE' => '26',
                                           'DOC' => '1:Use 10-bit I2C addressing, 0:Use 7-bit I2C addressing'
                                         },
                                         {
                                           'NAME' => 'rr',
                                           'BIT_RANGE' => '27',
                                           'DOC' => 'Response Request. If set the I2C master will send a response after this command is complete. See WriteResp'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => 'Set to 2 for this command'
                                         }
                                       ],
                              'NAME' => 'WriteOne',
                              'DOC' => 'Compact Write One byte COMMAND format'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'N',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Number of bytes to read (0 is interpreted as 256)'
                                         },
                                         {
                                           'NAME' => 'res1',
                                           'BIT_RANGE' => '15:8',
                                           'DOC' => 'reserved'
                                         },
                                         {
                                           'NAME' => 'slave_addr',
                                           'BIT_RANGE' => '25:16',
                                           'DOC' => 'Slave device Address. If 7-bit addressing, LSB aligned'
                                         },
                                         {
                                           'NAME' => 'use_10b_addressing',
                                           'BIT_RANGE' => '26',
                                           'DOC' => '1:Use 10-bit I2C addressing, 0:Use 7-bit I2C addressing'
                                         },
                                         {
                                           'NAME' => 'res2',
                                           'BIT_RANGE' => '27',
                                           'DOC' => 'reserved'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => 'Set to 3 for this command'
                                         }
                                       ],
                              'NAME' => 'ReadCurrent',
                              'DOC' => 'Read N-bytes from a current address COMMAND format'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'wdata',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Data to write'
                                         },
                                         {
                                           'NAME' => 'res',
                                           'BIT_RANGE' => '31:8',
                                           'DOC' => 'Reserved'
                                         }
                                       ],
                              'NAME' => 'WritePayload',
                              'DOC' => 'Write command. Format for subsequent words'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'res',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Reserved'
                                         },
                                         {
                                           'NAME' => 'Error',
                                           'BIT_RANGE' => '8',
                                           'DOC' => 'Copy of Status.ErrorFlag'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => '0/2 for Write/WriteOne responses'
                                         }
                                       ],
                              'NAME' => 'WriteResp',
                              'DOC' => 'Response to Write/WriteOne commands format'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'rdata',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Read data byte from I2C bus'
                                         },
                                         {
                                           'NAME' => 'Error',
                                           'BIT_RANGE' => '8',
                                           'DOC' => 'If set indicates read transaction was aborted due to an error'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => '1/3 for Read/ReadCurrent responses'
                                         }
                                       ],
                              'NAME' => 'ReadResp',
                              'DOC' => 'Response to Read/ReadCurrent command format'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'wdata',
                                           'BIT_RANGE' => '7:0',
                                           'DOC' => 'Data Byte to write'
                                         },
                                         {
                                           'NAME' => 'stop',
                                           'BIT_RANGE' => '8',
                                           'DOC' => 'Set to 1 if the write should be followed by a stop condition'
                                         },
                                         {
                                           'NAME' => 'start',
                                           'BIT_RANGE' => '9',
                                           'DOC' => 'Set to 1 if the write should be preceded by a start condition'
                                         },
                                         {
                                           'NAME' => 'rr',
                                           'BIT_RANGE' => '12',
                                           'DOC' => 'Response Request. If set the I2C master will send a response after this command is complete. See WriteResp packet'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => 'Set to 4 for this command'
                                         }
                                       ],
                              'NAME' => 'LLWrite',
                              'DOC' => 'Low level Write command COMMAND format. For internal use only'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'NAME' => 'stop',
                                           'BIT_RANGE' => '8',
                                           'DOC' => 'Set to 1 if the read should be followed by a stop condition'
                                         },
                                         {
                                           'NAME' => 'nack',
                                           'BIT_RANGE' => '9',
                                           'DOC' => 'Set to 1 if the read should be nacked by the master'
                                         },
                                         {
                                           'NAME' => 'cmd',
                                           'BIT_RANGE' => '31:28',
                                           'DOC' => 'Set to 5 for this command'
                                         }
                                       ],
                              'NAME' => 'LLRead',
                              'DOC' => 'Low level Read COMMAND format. For internal use only'
                            }
                          ],
             'REG_ARRAY' => [
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'RW1C',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'RespQ_NotEmpty',
                                           'RESET' => '1',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'Interrupt due to Response Queue not empty condition'
                                         },
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'RW1C',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'RespQ_Full',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '1',
                                           'DOC' => 'Interrupt due to Response Queue full condition'
                                         },
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'RW1C',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'CmdQ_Empty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '2',
                                           'DOC' => 'Interrupt due to Command Queue empty condition'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RC',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:3',
                                           'DOC' => 'reserved'
                                         }
                                       ],
                              'NAME' => 'Int',
                              'OFFS' => '0x08',
                              'DOC' => 'Interrupt Register',
                              'MMIO' => '0'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'RespQ_NotEmpty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'Interrupt Enable due to Response Queue not empty condition'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'RespQ_Full',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '1',
                                           'DOC' => 'Interrupt Enable due to Response Queue full condition'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'CmdQ_Empty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '2',
                                           'DOC' => 'Interrupt Enable for Command Queue empty condition'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RC',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:3',
                                           'DOC' => 'reserved'
                                         }
                                       ],
                              'NAME' => 'IntEnable',
                              'DOC' => 'Interrupt Enable Register'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'RespQ_NotEmpty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'If set, Indicates the Response Queue is not empty'
                                         },
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'RespQ_Full',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '1',
                                           'DOC' => 'If set, Indicates the Response Queue is full'
                                         },
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'CmdQ_NotEmpty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '2',
                                           'DOC' => 'If set, Indicates the Command Queue is not empty'
                                         },
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'CmdQ_Full',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '3',
                                           'DOC' => 'If set, Indicates the Command Queue is full'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RC',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'CONST' => '0',
                                           'BIT_RANGE' => '30:4',
                                           'DOC' => 'reserved'
                                         },
                                         {
                                           'PE_ATTR' => 'RW',
                                           'HOST_ATTR' => 'RW1C',
                                           'IO_ATTR' => 'internal',
                                           'NAME' => 'ErrorFlag',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31',
                                           'DOC' => 'Indicates any prior operation contained an error. The bit remains high until cleared. Write 1 to clear'
                                         }
                                       ],
                              'NAME' => 'Status',
                              'DOC' => 'Status Register'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'NAME' => 'NumRetriesBeforeError',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '3:0',
                                           'DOC' => 'Sets the number of silent retries the I2C master will do on a nack\'ed command before reporting error'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'NAME' => 'CmdQ_AlmostEmptyLevel',
                                           'RESET' => '2',
                                           'BIT_RANGE' => '15:8',
                                           'DOC' => 'Sets the threshold for command queue level at which almost empty condition will trigger'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'NAME' => 'RespQ_AlmostFullLevel',
                                           'RESET' => '2',
                                           'BIT_RANGE' => '23:16',
                                           'DOC' => 'Number of remaining entries in Response queue at which almost full condition will trigger'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW',
                                           'NAME' => 'HalfBitDelay',
                                           'RESET' => '100',
                                           'BIT_RANGE' => '31:24',
                                           'DOC' => 'I2C speed. Control bit time duration in core clock cycles (details TBD)'
                                         }
                                       ],
                              'NAME' => 'Conf',
                              'DOC' => 'Configuration Register'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'in',
                                           'NAME' => 'NotEmpty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'If set, Indicates the Response Queue is Not empty'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'RW1C',
                                           'IO_ATTR' => 'lintr',
                                           'NAME' => 'Full',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '1',
                                           'DOC' => 'If set, Indicates the Response Queue is Full'
                                         }
                                       ],
                              'NAME' => 'InFifo0',
                              'DOC_ATTR' => 'private',
                              'DOC' => 'InFifo0 Status Register'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'in',
                                           'NAME' => 'NotEmpty',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'If set, Indicates the Response Queue is not empty'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'R',
                                           'IO_ATTR' => 'in',
                                           'NAME' => 'Full',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '1',
                                           'DOC' => 'If set, Indicates the Response Queue is Full'
                                         }
                                       ],
                              'NAME' => 'OutFifo0',
                              'DOC' => 'OutFifo0 Status Register'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'W',
                                           'HOST_ATTR' => 'H',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'Set to 0 to drive a 0 to the I2C bust. Set to 1 to disable ouput and leave it as pulled-up input'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'H',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:1',
                                           'DOC' => 'reserved'
                                         }
                                       ],
                              'NAME' => 'SdaOeN',
                              'DOC_ATTR' => 'private',
                              'DOC' => 'Sda OE_N control. For PE local access'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'W',
                                           'HOST_ATTR' => 'H',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'Set to 0 to drive a 0 to the I2C bust. Set to 1 to disable ouput and leave it as pulled-up input'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'H',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:1',
                                           'DOC' => 'reserved'
                                         }
                                       ],
                              'NAME' => 'SclOeN',
                              'DOC_ATTR' => 'private',
                              'DOC' => 'Scl OE_N control. For PE local access'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'H',
                                           'IO_ATTR' => 'in',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'Read value of the I2C SDA line'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'H',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:1',
                                           'DOC' => 'reserved'
                                         }
                                       ],
                              'NAME' => 'SdaIn',
                              'DOC_ATTR' => 'private',
                              'DOC' => 'SclIn input. For PE local access'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'H',
                                           'IO_ATTR' => 'in',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '0',
                                           'DOC' => 'Read value of the I2C SCL line'
                                         },
                                         {
                                           'PE_ATTR' => 'R',
                                           'HOST_ATTR' => 'H',
                                           'NAME' => 'res',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:1',
                                           'DOC' => 'reserved'
                                         }
                                       ],
                              'NAME' => 'SclIn',
                              'DOC_ATTR' => 'private',
                              'DOC' => 'SclIn input. For PE local access'
                            },
                            {
                              'INCR' => '8',
                              'FIELD' => [
                                         {
                                           'HOST_ATTR' => 'RW',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:0',
                                           'DOC' => 'value'
                                         }
                                       ],
                              'NAME' => 'scratch_pad_a',
                              'COUNT' => '10',
                              'DOC' => 'scratch pad a register n'
                            },
                            {
                              'INCR' => '8',
                              'FIELD' => [
                                         {
                                           'HOST_ATTR' => 'RW',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'BIT_RANGE' => '31:0',
                                           'DOC' => 'value'
                                         }
                                       ],
                              'NAME' => 'scratch_pad_b',
                              'COUNT' => '10',
                              'DOC' => 'scratch pad b register n'
                            },
                            {
                              'INCR' => '4',
                              'IDX0' => '4',
                              'FIELD' => [
                                         {
                                           'HOST_ATTR' => 'RW',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'TRIGGER_ATTR' => 'W',
                                           'BIT_RANGE' => '31:0',
                                           'DOC' => 'value'
                                         }
                                       ],
                              'NAME' => 'scratch_pad_c',
                              'COUNT' => '2',
                              'DOC' => 'scratch pad c register n'
                            },
                            {
                              'FIELD' => [
                                         {
                                           'HOST_ATTR' => 'RW',
                                           'IO_ATTR' => 'out',
                                           'NAME' => 'val',
                                           'RESET' => '0',
                                           'TRIGGER_ATTR' => 'W',
                                           'BIT_RANGE' => '31:0',
                                           'DOC' => 'value'
                                         }
                                       ],
                              'NAME' => 'scratch_pad_d',
                              'COUNT' => '16',
                              'DOC' => 'scratch pad d register n'
                            }
                          ],
             'DEFAULTS' => {
                           'PREFIX_PKTS' => 'I2C_',
                           'BASE' => '0x21000',
                           'CLOCK' => 'PCLK',
                           'PREFIX_CSRS' => '',
                           'MMIO_EXT_ADDR_W' => '8',
                           'MODULE' => 'csrs',
                           'APB_V3' => '1',
                           'APB_ADDR_W' => '16',
                           'PRI' => 'HOST',
                           'GEN_MMIO' => '1'
                         }
           };

1;
