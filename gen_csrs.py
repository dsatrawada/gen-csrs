#!/usr/bin/env python3

import argparse
import xmltodict
import string
import sys

#-----------------------------------------------------------------------------
# syntax
#-----------------------------------------------------------------------------
def syntax():
    print("\n    gen_csrs Rev " + version + ". Generation of Control/Status "
          "verilog register file")
    print("    and documentation based on XML description")
    print("\n    Usage: gen_csrs.py [options] xml_filename")
    print("\n    Where options is any combination of the following (can be "
          "abbreviated to unique)")
    print("\n       --out f               filename of the output register "
          "module")
    print("                              (default " + file_out + ")")
    print("       --mod s               define module name as <s>")
    print("                              (default is base of -out file)")
    print("       --mmio_defines f      filename of the defines and macros for "
          "mmio usage")
    print("                              (default <mod>_mmios.h)")
    print("       --host_defines f      filename of the defines and macros for "
          "host usage")
    print("                              (default <mod>_host_defines.h)")
    print("       --host_vdefines f     filename of the defines and macros for "
          "host usage in verilog")
    print("                              (default <mod>_host_defines.vh)")
    print("       --pe_defines f        filename of the defines and macros for "
          "PE usage")
    print("                              (default <mod>_pe_defines.h)")
    print("       --pkt_defines f       filename of the defines and macros for "
          "pkt processing")
    print("                              (default " + mod + "_pkt_defines.h)")
    print("       --csr_params f        filename of the csr parameters file")
    print("                              (not generated unless provided)")
    print("       --ralf f              filename of the output RALF file "
          "generated")
    print("                              (not generated unless provided)")
    print("       --ipxact f            filename of the output IP-XACT file "
          "generated")
    print("                              (not generated unless provided)")
    print("       --g2p f               Output file to interface with g2p")
    print("                              (not generated unless provided)")
    print("       --html f              filename for the output HTML "
          "documentation")
    print("                              (default <mod>.html)")
    print("       --[no_]parallel_mode  in Parallel_mode PREADY/PRDATA's from "
          "several gen_csr")
    print("                             modules can be OR'ed together and "
          "PSLVERR is never asserted.")
    print("                              (default " + str(parallel_mode) + ")")
    print("       --[no_]gen_regs       generate register portion of the "
          "output")
    print("                              (default " + str(gen_regs) + ")")
    print("       --[no_]gen_pkts       generate Command portion of the output")
    print("                              (default " + str(gen_pkts) + ")")
    print("       --[no_]hyperlinks     Create hyperlinks from summary to each "
          "register on html out")
    print("                              (default " + str(hyperlinks) + ")")
    print("       --[no_]warn_aw        Warn if constants specified are larger "
          "than expected size")
    print("                              (default " + str(warn_aw) + ")")
    print("       --vlogsep s           Separator for register name and field "
          "in verilog ports")
    print("                              (default " + vlogsep + ")")
    print("       --sep s               Separator for register name and field "
          "for everything else")
    print("                              (default " + sep + ")")
    print("       --cq n                Include this clock-to-q delay on "
          "non-blocking assignments")
    print("                              to help waveform debugging. None if 0 "
          "(default " + str(cq_delay) + ")")
    print("       --[no_]pstrb          Include PSTRB input control")
    print("                              (default " + str(allow_pstrobe) + ")")
    print("       --rdata_on_decerr vn  Value returned on read if reading a "
          "non-existing/non-readable")
    print("                              register (default " + rdata_on_decerr
          + ")")
    print("       --help                Display this message")
    print("\n    Where: f is a valid filename (E.g /path/to/file.txt)")
    print("           s is a string then conforms to C identifier rules (E.g. "
          "value_max)")
    print("           n is a natural number (E.g 2)")
    print("           vn is a verilog formated number/constant (E.g. "
          "32'hdeadbeef)")
    print("\n           <mod> is extracted as the basename of the xml_filename "
          "if no provided")
    print("           (e.g. /path/timer_csrs.xml yields timer_csrs)\n")
    sys.exit()

#-----------------------------------------------------------------------------
# store argument from command line
#-----------------------------------------------------------------------------
def store_arg(arg, var):
    if arg != None:
        return arg
    else:
        return var

#-----------------------------------------------------------------------------
#-----------------------------------------------------------------------------
def given (dict, key):
    if key in dict:
        return key != ""
    return False

#-----------------------------------------------------------------------------
# convert to decimal allowing for AB, 15, AA_BB type of inputs
#-----------------------------------------------------------------------------
def dec (value):
    input = value.split("_")
    x = ""
    for item in input:
        x += item
    x = x.strip()
    if('0x' in value):
        return int(x[2:], 8)
    if (all(c in set("ABCDEFabcdef") for c in x)):
        sys.exit("ERROR: expected number, got " + value + " which appears hex "
                 "but has no 0x prefix")
    return int(x)

version = "2.00"

html_width = 800
file_out = "regs.v"
file_mmio_defines_h = None
file_host_defines_h = None
file_host_defines_vh = None
file_pkt_defines_h = None
file_pe_defines_h = None
file_html = None
file_csr_params_py = None
file_ralf = None
file_ipxact = None
file_g2p = None

gen_regs = True
gen_pkts = True
help = False
sep = "__"
vlogsep = "__"
has_hidden = False
hyperlinks = False
warn_aw = True
cq_delay = 0
rdata_on_decerr = "32'hbad00add"
mod = ""
allow_pstrobe = False
parallel_mode = False

parser = argparse.ArgumentParser(add_help = False)

arguments = [
    "--mod", "--out", "--mmio_defines", "--host_defines", "--host_vdefines",
    "--pkt_defines", "--pe_defines", "--csr_params", "--ralf", "--ipxact",
    "--g2p", "--html", "--rdata_on_decerr", "--cq", "--sep", "--vlogsep"
]
types = [
    str, str, str, str, str, str, str, str, str, str, str, str, str, float, str,
    str
]
for index in range(0, len(arguments)):
    parser.add_argument(arguments[index], type = types[index])
arguments = [
    "--parallel_mode", "--hyperlinks", "--warn_aw", "--gen_regs", "--gen_pkts",
    "--pstrb", "--help"
]
[parser.add_argument(argument, action = "store_true") for argument in arguments]
arguments = [
    "--no_parallel_mode", "--no_hyperlinks", "--no_warn_aw", "--no_gen_regs",
    "--no_gen_pkts", "--no_pstrb", "--no_help"
]
[parser.add_argument(argument, action = "store_false") for argument in arguments]

try:
    args = parser.parse_args()
except SystemExit:
    syntax()

mod = store_arg(args.mod, mod)
file_out = store_arg(args.out, file_out)
file_mmio_defines_h = store_arg(args.mmio_defines, file_mmio_defines_h)
file_host_defines_h = store_arg(args.host_defines, file_host_defines_h)
file_host_defines_vh = store_arg(args.host_vdefines, file_host_defines_vh)
file_pkt_defines_h = store_arg(args.pkt_defines, file_pkt_defines_h)
file_pe_defines_h = store_arg(args.pe_defines, file_pe_defines_h)
parallel_mode = store_arg(args.parallel_mode, parallel_mode)
file_csr_params_py = store_arg(args.csr_params, file_csr_params_py)
file_ralf = store_arg(args.ralf, file_ralf)
file_ipxact = store_arg(args.ipxact, file_ipxact)
file_g2p = store_arg(args.g2p, file_g2p)
file_html = store_arg(args.html, file_html)
rdata_on_decerr = store_arg(args.rdata_on_decerr, rdata_on_decerr)
cq_delay = store_arg(args.cq, cq_delay)
hyperlinks = store_arg(args.hyperlinks, hyperlinks)
warn_aw = store_arg(args.warn_aw, warn_aw)
gen_regs = store_arg(args.gen_regs, gen_regs)
gen_pkts = store_arg(args.gen_pkts, gen_pkts)
sep = store_arg(args.sep, sep)
vlogsep = store_arg(args.vlogsep, vlogsep)
allow_pstrobe = store_arg(args.pstrb, allow_pstrobe)
help = store_arg(args.help, help)

if (not len(sys.argv) > 1) or help:
    syntax()

if mod == "":
    mod = file_out.split(".")
    mod = mod[0]

MOD = mod.upper()

if file_mmio_defines_h == None:
    file_mmio_defines_h = mod + "_mmios.h"
if file_host_defines_h == None:
    file_host_defines_h = mod + "_host_defines.h"
if file_host_defines_vh == None:
    file_host_defines_vh = mod + "_host_defines.vh"
if file_pkt_defines_h == None:
    file_pkt_defines_h = mod + "_pkt_defines.h"
if file_pe_defines_h == None:
    file_pe_defines_h = mod + "_pe_defines.h"
if file_html == None:
    file_html = mod + ".html"

NBASG = "<="
if cq_delay > 0:
    NBASG = "<= #" + cq_delay

file_in = mod + ".xml"
with open(file_in) as fd:
    data_in = xmltodict.parse(fd.read())['REGISTERS']

if not given(data_in['DEFAULTS'], '@CLOCK'):
    data_in['DEFAULTS']['@CLOCK'] = "PCLK"
if not given(data_in['DEFAULTS'], '@CLOCK_EDGE'):
    data_in['DEFAULTS']['@CLOCK_EDGE'] = "posedge"
if not given(data_in['DEFAULTS'], '@RESET'):
    data_in['DEFAULTS']['@RESET'] = "PRESETN"
if not given(data_in['DEFAULTS'], '@RESET_VAL'):
    data_in['DEFAULTS']['@RESET_VAL'] = "0"
if not given(data_in['DEFAULTS'], '@BASE'):
    data_in['DEFAULTS']['@BASE'] = "0"
if not given(data_in['DEFAULTS'], '@OFFS_INCR'):
    data_in['DEFAULTS']['@OFFS_INCR'] = "4"
if not given(data_in['DEFAULTS'], '@APB_ADDR_W'):
    data_in['DEFAULTS']['@APB_ADDR_W'] = "32"
if not given(data_in['DEFAULTS'], '@APB_ADDR_LSB'):
    data_in['DEFAULTS']['@APB_ADDR_LSB'] = "0"
if not given(data_in['DEFAULTS'], '@PREFIX_CSRS'):
    data_in['DEFAULTS']['@PREFIX_CSRS'] = ""
if not given(data_in['DEFAULTS'], '@PREFIX_PKTS'):
    data_in['DEFAULTS']['@PREFIX_PKTS'] = ""
if not given(data_in['DEFAULTS'], '@GEN_MMIO'):
    data_in['DEFAULTS']['@GEN_MMIO'] = "0"
if not given(data_in['DEFAULTS'], '@MMIO_STYLE_EXT'):
    data_in['DEFAULTS']['@MMIO_STYLE_EXT'] = "1"
if not given(data_in['DEFAULTS'], '@PREFIX_PORTS'):
    data_in['DEFAULTS']['@PREFIX_PORTS'] = "1"
if not given(data_in['DEFAULTS'], '@APB_V3'):
    data_in['DEFAULTS']['@APB_V3'] = "0"
if not given(data_in['DEFAULTS'], '@MMIO_EXT_ADDR_W'):
    data_in['DEFAULTS']['@MMIO_EXT_ADDR_W'] = "16"
if not given(data_in['DEFAULTS'], '@REG_FLD_SEP'):
    data_in['DEFAULTS']['@REG_FLD_SEP'] = sep
if not given(data_in['DEFAULTS'], '@REG_FLD_VLOGSEP'):
    data_in['DEFAULTS']['@REG_FLD_VLOGSEP'] = vlogsep

clock             = data_in['DEFAULTS']['@CLOCK']
clock_edge        = data_in['DEFAULTS']['@CLOCK_EDGE']
reset             = data_in['DEFAULTS']['@RESET']
reset_val         = data_in['DEFAULTS']['@RESET_VAL']
base              = dec(data_in['DEFAULTS']['@BASE'])
offs_incr         = dec(data_in['DEFAULTS']['@OFFS_INCR'])
prefix_csrs       = data_in['DEFAULTS']['@PREFIX_CSRS']
prefix_pkts       = data_in['DEFAULTS']['@PREFIX_PKTS']
gen_mmio          = int(data_in['DEFAULTS']['@GEN_MMIO']) + 0
mmio_style_ext    = int(data_in['DEFAULTS']['@MMIO_STYLE_EXT']) + 0
prefix_ports      = int(data_in['DEFAULTS']['@PREFIX_PORTS']) + 0
apb_v3            = int(data_in['DEFAULTS']['@APB_V3']) + 0
mmio_ext_addr_msb = int(data_in['DEFAULTS']['@MMIO_EXT_ADDR_W']) - 1
mmio_ext_addr_sz  = int(mmio_ext_addr_msb) + 1
mmio_offs_incr    = (data_in['DEFAULTS']['@MMIO_OFFS_INCR']
                    if given(data_in['DEFAULTS'], '@MMIO_OFFS_INCR')
                    else 0x4 if mmio_style_ext else 1)
sep     = data_in['DEFAULTS']['@REG_FLD_SEP']
vlogsep = data_in['DEFAULTS']['@REG_FLD_VLOGSEP']

tick = {}
tick['c'] = "#"
tick['v'] = "`"
hw = None
hr = None
rst = None
ff = None
mmi = None
mmi_decl = None
mmi_ports = None
mmo = None
mmo_decl = None
mmo_ports = None
mmio_defines = None
host_defines = None
pe_defines = None
reg_list_macro = None
field_list_macro = None
ff_cnt = 32 #for PRDATA
apb_addr_msb = dec(data_in['DEFAULTS']['@APB_ADDR_W']) - 1
apb_addr_size = apb_addr_msb + 1
g_input_list = None
g_input_g2p_list = None
g_output_list = None
g_output_g2p_list = None
