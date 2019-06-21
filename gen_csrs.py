import argparse





import sys

version = "2.00"

html_width = 800
file_out = "regs.v"
file_mmio_defines_h = None
file_host_defines_h = None
file_host_defines_vh = None
file_pkt_defines_h = None
file_pe_defines_h = None
file_html = None
file_csr_params_pl = None
file_ralf = None
file_ipxact = None
file_g2p = None

gen_regs = 1
gen_pkts = 1
help = 0
sep = "__"
vlogsep = "__"
has_hidden = 0
hyperlinks = 0
warn_aw = 1
cq_delay = 0
rdata_on_decerr = "32'hbad00add"
mod = ""
allow_pstrobe = 0
parallel_mode = 0

parser = argparse.ArgumentParser(add_help = False)
arguments = [
 "--mod",
 "--out",
 "--mmio_defines",
 "--host_defines",
 "--host_vdefines",
 "--pkt_defines",
 "--pe_defines",
 "--parallel_mode",
 "--csr_params",
 "--ralf",
 "--ipxact",
 "--g2p",
 "--html",
 "--rdata_on_decerr",
 "--cq",
 "--hyperlinks",
 "--warn_aw",
 "--gen_regs",
 "--gen_pkts",
 "--sep",
 "--vlogsep",
 "--pstrb",
 "--help"
]
[parser.add_argument(argument) for argument in arguments]
args = parser.parse_args()

mod = args.mod
file_out = args.out
file_mmio_defines_h = args.mmio_defines
file_host_defines_h = args.host_defines
file_host_defines_vh = args.host_vdefines
file_pkt_defines_h = args.pkt_defines
file_pe_defines_h = args.pe_defines
parallel_mode = args.parallel_mode
file_csr_params_pl = args.csr_params
file_ralf = args.ralf
file_ipxact = args.ipxact
file_g2p = args.g2p
file_html = args.html
rdata_on_decerr = args.rdata_on_decerr
cq_delay = args.cq
hyperlinks = args.hyperlinks
warn_aw = args.warn_aw
gen_regs = args.gen_regs
gen_pkts = args.gen_pkts
sep = args.sep
vlogsep = args.vlogsep
allow_pstrobe = args.pstrb
help = args.help

if (not len(sys.argv) > 1) or help:
    print("call syntax")
