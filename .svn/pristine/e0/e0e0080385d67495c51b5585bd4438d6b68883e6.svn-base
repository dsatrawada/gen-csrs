#!/usr/bin/env perl
#------------------------------------------------------------------------------
# Copyright (c) 2009-Present, Esencia Technologies Inc
# All rights reserved.
#
# This is free software released under GNU Lesser GPL license version 3.0 (LGPL 3.0)
#
# See http://www.gnu.org/licenses/lgpl-3.0.txt for a full text
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
# IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
# OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Author: Miguel Guerrero
# Please send bugs and suggestions to: tools@esenciatech.com
#------------------------------------------------------------------------------
use Getopt::Long;
use Env;
use XML::Simple;
use Data::Dumper;
use strict;

push @INC, ".";

my $version="2.00";

my $html_width=800;
my $file_out="regs.v";
my $file_mmio_defines_h=undef;
my $file_host_defines_h=undef;
my $file_host_defines_vh=undef;
my $file_pkt_defines_h=undef;
my $file_pe_defines_h=undef;
my $file_html=undef;
my $file_csr_params_pl=undef;
my $file_ralf=undef;
my $file_ipxact=undef;
my $file_g2p=undef;

my $gen_regs = 1;
my $gen_pkts = 1;
my $help=0;
my $sep="__";
my $vlogsep="__";
my $has_hidden=0;
my $hyperlinks=0;
my $warn_aw=1;
my $cq_delay=0;
my $rdata_on_decerr="32'hbad00add";
my $mod="";
my $allow_pstrobe=0;
my $parallel_mode=0;

if (!&GetOptions(
      "mod=s" => \$mod, 
      "out=s" => \$file_out, 
      "mmio_defines=s" => \$file_mmio_defines_h, 
      "host_defines=s" => \$file_host_defines_h, 
      "host_vdefines=s" => \$file_host_defines_vh, 
      "pkt_defines=s" => \$file_pkt_defines_h, 
      "pe_defines=s" => \$file_pe_defines_h, 
      "parallel_mode!" => \$parallel_mode, 
      "csr_params=s" => \$file_csr_params_pl, 
      "ralf=s" => \$file_ralf, 
      "ipxact=s" => \$file_ipxact,
      "g2p=s" => \$file_g2p,
      "html=s" => \$file_html, 
      "rdata_on_decerr=s" => \$rdata_on_decerr, 
      "cq=n" => \$cq_delay, 
      "hyperlinks!" => \$hyperlinks,
      "warn_aw!" => \$warn_aw,
      "gen_regs!" => \$gen_regs,
      "gen_pkts!" => \$gen_pkts,
      "sep=s" => \$sep, 
      "vlogsep=s" => \$vlogsep, 
      "pstrb!" => \$allow_pstrobe, 
      "help!" => \$help
   ) || $help || ($#ARGV == -1)) 
{
   &syntax;
}

if ($mod eq "") {
    $mod = $file_out;
    $mod =~ s|^.*/||;
    $mod =~ s|\..*$||;
}

my $MOD = $mod;
$MOD =~ tr/a-z/A-Z/;

if (!defined $file_mmio_defines_h)  { $file_mmio_defines_h="${mod}_mmios.h"; }
if (!defined $file_host_defines_h)  { $file_host_defines_h="${mod}_host_defines.h"; }
if (!defined $file_host_defines_vh) { $file_host_defines_vh="${mod}_host_defines.vh"; }
if (!defined $file_pkt_defines_h)   { $file_pkt_defines_h="${mod}_pkt_defines.h"; }
if (!defined $file_pe_defines_h)    { $file_pe_defines_h="${mod}_pe_defines.h"; }
if (!defined $file_html)            { $file_html="${mod}.html"; }

my $NBASG = "<=";
if ($cq_delay > 0) {
   $NBASG = "<= #$cq_delay";
}

my $file_in=$ARGV[0];
our $data_in;

parseXml($file_in, "${mod}_regs.pm");
require "${mod}_regs.pm";

if (!given( $data_in->{DEFAULTS}->{CLOCK} ))           { $data_in->{DEFAULTS}->{CLOCK} = "PCLK"; }
if (!given( $data_in->{DEFAULTS}->{CLOCK_EDGE} ))      { $data_in->{DEFAULTS}->{CLOCK_EDGE} = "posedge"; }
if (!given( $data_in->{DEFAULTS}->{RESET} ))           { $data_in->{DEFAULTS}->{RESET} = "PRESETN"; }
if (!given( $data_in->{DEFAULTS}->{RESET_VAL} ))       { $data_in->{DEFAULTS}->{RESET_VAL} = "0"; }
if (!given( $data_in->{DEFAULTS}->{BASE} ))            { $data_in->{DEFAULTS}->{BASE} = "0"; }
if (!given( $data_in->{DEFAULTS}->{OFFS_INCR} ))       { $data_in->{DEFAULTS}->{OFFS_INCR} = "4"; }
if (!given( $data_in->{DEFAULTS}->{APB_ADDR_W} ))      { $data_in->{DEFAULTS}->{APB_ADDR_W} = "32"; }
if (!given( $data_in->{DEFAULTS}->{APB_ADDR_LSB} ))    { $data_in->{DEFAULTS}->{APB_ADDR_LSB} = "0"; }
if (!given( $data_in->{DEFAULTS}->{PREFIX_CSRS} ))     { $data_in->{DEFAULTS}->{PREFIX_CSRS} = ""; }
if (!given( $data_in->{DEFAULTS}->{PREFIX_PKTS} ))     { $data_in->{DEFAULTS}->{PREFIX_PKTS} = ""; }
if (!given( $data_in->{DEFAULTS}->{GEN_MMIO} ))        { $data_in->{DEFAULTS}->{GEN_MMIO} = "0"; }
if (!given( $data_in->{DEFAULTS}->{MMIO_STYLE_EXT} ))  { $data_in->{DEFAULTS}->{MMIO_STYLE_EXT} = "1"; }
if (!given( $data_in->{DEFAULTS}->{PREFIX_PORTS} ))    { $data_in->{DEFAULTS}->{PREFIX_PORTS} = "1"; }
if (!given( $data_in->{DEFAULTS}->{APB_V3} ))          { $data_in->{DEFAULTS}->{APB_V3} = "0"; }
if (!given( $data_in->{DEFAULTS}->{MMIO_EXT_ADDR_W} )) { $data_in->{DEFAULTS}->{MMIO_EXT_ADDR_W} = "16"; }
if (!given( $data_in->{DEFAULTS}->{REG_FLD_SEP} ))     { $data_in->{DEFAULTS}->{REG_FLD_SEP} = $sep; }
if (!given( $data_in->{DEFAULTS}->{REG_FLD_VLOGSEP} )) { $data_in->{DEFAULTS}->{REG_FLD_VLOGSEP} = $vlogsep; }

my $clock             = $data_in->{DEFAULTS}->{CLOCK};
my $clock_edge        = $data_in->{DEFAULTS}->{CLOCK_EDGE};
my $reset             = $data_in->{DEFAULTS}->{RESET};
my $reset_val         = $data_in->{DEFAULTS}->{RESET_VAL};
my $base              = dec($data_in->{DEFAULTS}->{BASE});
my $offs_incr         = dec($data_in->{DEFAULTS}->{OFFS_INCR});
my $prefix_csrs       = $data_in->{DEFAULTS}->{PREFIX_CSRS};
my $prefix_pkts       = $data_in->{DEFAULTS}->{PREFIX_PKTS};
my $gen_mmio          = $data_in->{DEFAULTS}->{GEN_MMIO} + 0;
my $mmio_style_ext    = $data_in->{DEFAULTS}->{MMIO_STYLE_EXT} + 0;
my $prefix_ports      = $data_in->{DEFAULTS}->{PREFIX_PORTS} + 0;
my $apb_v3            = $data_in->{DEFAULTS}->{APB_V3} + 0;
my $mmio_ext_addr_msb = $data_in->{DEFAULTS}->{MMIO_EXT_ADDR_W} - 1;
my $mmio_ext_addr_sz  = $mmio_ext_addr_msb + 1;
my $mmio_offs_incr    = &given($data_in->{DEFAULTS}->{MMIO_OFFS_INCR}) ? $data_in->{DEFAULTS}->{MMIO_OFFS_INCR} :
                                                       $mmio_style_ext ? 0x4 : 1;
$sep     = $data_in->{DEFAULTS}->{REG_FLD_SEP};
$vlogsep = $data_in->{DEFAULTS}->{REG_FLD_VLOGSEP};

my %tick;
$tick{c}="#";
$tick{v}="`";
my $hw;
my $hr;
my $rst;
my $ff;
my $mmi; 
my $mmi_decl;
my $mmi_ports;
my $mmo; 
my $mmo_decl;
my $mmo_ports;
my $mmio_defines;
my %host_defines;
my $pe_defines;
my $reg_list_macro;
my $field_list_macro;
my $ff_cnt=32; #for PRDATA
my $apb_addr_msb = dec($data_in->{DEFAULTS}->{APB_ADDR_W}) - 1;
my $apb_addr_size = $apb_addr_msb + 1;
my @g_input_list;
my @g_input_g2p_list;
my @g_output_list;
my @g_output_g2p_list;

#-----------------------------------------------------------------------------
# PART 1 : build up information based on XML contents
#-----------------------------------------------------------------------------
my $ports = "";
$ports .= input($clock);
$ports .= input($reset);
$ports .= input("PSEL");
$ports .= input("PENABLE");
$ports .= input("PWRITE");
$ports .= input("PADDR", $apb_addr_size);
$ports .= input("PWDATA", 32);
$ports .= output("PRDATA", 32);

if ($apb_v3) {
   $ports .= output("PREADY");
   $ports .= output("PSLVERR");
}
if ($allow_pstrobe) {
   $ports .= input("PSTRB", 4);
}

if ($gen_mmio && $mmio_style_ext) {
    $mmi_ports .= input("mmio_ext_en");
    $mmi_ports .= input("mmio_ext_write");
    $mmi_ports .= input("mmio_ext_address", $mmio_ext_addr_sz);
    $mmi_ports .= input("mmio_ext_wdata", 32);
    # output mmio_ext_stall;\n" .
    $mmi_ports .= output("mmio_ext_rdata_vld");
    $mmi_ports .= output("mmio_ext_rdata", 32);
    $mmi_decl = 
    "//reg mmio_ext_stall;\n" .
    "reg mmio_ext_rdata_vld_D;\n" .
    "reg mmio_ext_rdata_vld;\n" .
    "reg [ 31:0 ] mmio_ext_rdata_D;\n".
    "reg [ 31:0 ] mmio_ext_rdata;\n";
}

my $rini = "PRDATA_D = 32'h0 ;\n";
$rini   .= "rd_decerr = 1'b0 ;\n";

my $wini = "wr_decerr = 1'b0 ;\n";



my $decl = 
"reg [ 31:0 ] PRDATA ;\n".
"reg [ 31:0 ] PRDATA_D ;\n".
"reg PSEL_Q ;\n".
"reg rd_decerr ;\n".
"reg wr_decerr ;\n";

if ($allow_pstrobe) {
   $decl .= "wire [ 31:0 ] wr_en_mask ;\n";
   $decl .= "assign wr_en_mask = { {8{PSTRB[3]}}, {8{PSTRB[2]}}, {8{PSTRB[1]}}, {8{PSTRB[0]}} } ;\n";
} 

my $min_ch = 0xFFFF;
my $max_ch = 0;
my $ch = -$mmio_offs_incr;
my $offs = -$offs_incr;
my $overall_mmio_any_r = 0;
my $overall_mmio_any_w = 0;
my %addr_map;
my %addr_by_name;
my %field_exists;

my $arr_ref = $data_in->{REG_ARRAY};
if (ref($arr_ref) ne "ARRAY") { $gen_regs=0; }

if ($gen_regs) {
   foreach my $reg (@{$arr_ref}) {

      #some checks on register name
      if (!defined ($reg->{NAME})) { die "ERROR: no NAME defined for register"; }
      if ($reg->{NAME} eq "") { die "ERROR: invalid empty NAME for register"; }

      #figure out register offset and absolute address
      if (defined ($reg->{OFFS})) {
         $offs = dec($reg->{OFFS});
      } else {
         my $a=-1;
         do {
             $offs += $offs_incr;
             $a = $base + $offs;
         }
         while (defined $addr_map{$a});
      }
      my $addr = $base + $offs;

      my $offs0 = $offs;
      my $addr0 = $addr;

      my $reg_count     = given($reg->{COUNT}) ? $reg->{COUNT} + 0 : 1;
      my $reg_list_incr = given($reg->{INCR})  ? $reg->{INCR} + 0  : 4; 
      my $reg_list_idx0 = given($reg->{IDX0})  ? $reg->{IDX0} + 0  : 0; 


      my $curr_offs = $offs;
      my $curr_addr = $addr;

      for my $reg_num (0..$reg_count-1) {

          my $REG_NAME  = $reg->{NAME};
          my $reg_name  = sanitize_name($REG_NAME);
          my $reg_name0 = list_reg_name($reg_name, 0);

          #update list of register defines for verilog and for c
          if ($reg_count > 1) {
             $REG_NAME = list_reg_name($REG_NAME, $reg_num + $reg_list_idx0);
             $reg_name = list_reg_name($reg_name, $reg_num + $reg_list_idx0);
             $curr_offs = $offs0 + $reg_num*$reg_list_incr;
             $curr_addr = $addr0 + $reg_num*$reg_list_incr;
          }

          #make sure the register name is not repeated
          die "Register $REG_NAME is duplicated"  if defined $addr_by_name{$REG_NAME};
          $addr_by_name{$REG_NAME}=$curr_addr;
          #make sure the register address is not repeated
          die "Register $REG_NAME has address $curr_addr already used by $addr_map{$curr_addr}"  if defined $addr_map{$curr_addr};
          $addr_map{$curr_addr} = $REG_NAME;
          #make sure the register address is word aligned
          die "Register $REG_NAME address is not word aligned"  if $curr_addr % 4 != 0;

      
          #compute mmio channel number for PE
          $ch = $reg->{MMIO} || ($ch + $mmio_offs_incr);
          $min_ch = $ch < $min_ch ? $ch : $min_ch;
          $max_ch = $ch > $max_ch ? $ch : $max_ch;

          for my $format ("v","c") {
             my $use_define = ($format eq "v") ? "`" : "";
             $host_defines{$format} .= "\n// reg $REG_NAME\n";
             if ($reg_count > 1 && $reg_num == 0) {
                 if ($reg_list_idx0 != 0) {
                     my $chex_addr = chex($curr_offs-$reg_list_incr*$reg_list_idx0, $format, 8);
                     $host_defines{$format} .= "$tick{$format}define ${MOD}_ADDR_$reg_name0\t(${use_define}${MOD}_BASE+$chex_addr)\n";
                 }
                 $host_defines{$format} .= "$tick{$format}define ${MOD}_INCR_$reg_name0\t$reg_list_incr\n";
             }
             my $chex_addr = chex($curr_offs, $format, 8);
             $host_defines{$format} .= "$tick{$format}define ${MOD}_ADDR_$reg_name\t(${use_define}${MOD}_BASE+$chex_addr)\n";
          }

          #update list of defines for PE code (contains channel number)
          $pe_defines .= "\n// reg $REG_NAME\n";
          $pe_defines .= "#define ${MOD}_MMIO_$reg_name\t$ch\n";
          $reg_list_macro .= " op($reg_name) \\\n";

          # build up csr verilog file read and write code from host
          my $vhex_addr = vhex($curr_addr, $apb_addr_size, $warn_aw, "PADDR, -nowarn_aw to skip");
          $hw .= "$vhex_addr : begin // $REG_NAME\n";
          $hr .= "$vhex_addr : begin // $REG_NAME\n";
          # and from PE side
          my $vhex_ch = vhex($ch, $mmio_ext_addr_sz, $warn_aw, "mmio_ext_address, -nowarn_aw to skip");
          my $mmi_this_reg = "${vhex_ch} : begin // $REG_NAME\n";
          my $mmo_this_reg;
          #we have 2 styles of MMIO access
          if ($gen_mmio) {
              if ($mmio_style_ext) {
                 $mmo_this_reg = "${vhex_ch}: begin // $REG_NAME\n";
              }
              else {
                 $mmo_this_reg = "if (mmo_en_$ch) begin // $REG_NAME\n";
              }
          }

          #Now loop over all register fields
          my $reg_reset = 0;
          my $reg_reset_msk = 0;
          my $reg_rw_msk = 0;
          my $reg_rw1c_msk = 0;
          my $reg_r_msk = 0;
          my $reg_rc_msk = 0;
          my $mmio_any_r = 0;
          my $mmio_any_w = 0;
          my @bit_type=();
          my $field_arr_ref = $reg->{FIELD};
          foreach my $field (@{$field_arr_ref}) {

             #basic checks on field definition
             if (!given( $field->{NAME} ))      { die "ERROR: in reg $REG_NAME found field w/o name"; }
             if (!given( $field->{BIT_RANGE} )) { die "ERROR: $REG_NAME.$field->{NAME} has no BIT_RANGE"; }
             if (!given( $field->{HOST_ATTR} )) { $field->{HOST_ATTR} = "RW"; }
             if (!given( $field->{PE_ATTR} ))   { $field->{PE_ATTR}   = "RW"; }
             if (!given( $field->{IO_ATTR} ))   { $field->{IO_ATTR}   = "internal"; }
             if (!given( $field->{RESET} ))     { $field->{RESET}     = "0"; }
             if (!given( $field->{TRIGGER_ATTR})){ $field->{TRIGGER_ATTR} = "NONE"; }

             my $field_name;
             if ($prefix_ports) {
                $field_name = "$REG_NAME${vlogsep}$field->{NAME}";
             } 
             else {
                $field_name = "$field->{NAME}";
             }
             $field_name = sanitize_name($field_name);

             #make the bit range to be n:n if only n was given
             unless ($field->{BIT_RANGE} =~ /:/) {
                $field->{BIT_RANGE} .= ":" . $field->{BIT_RANGE};
             }

             $field->{RESET} = dec($field->{RESET});

             #check host attribute is valid
             my @vld_host_attr=qw(RW RW1C RC H R);
             if (!in_list_str($field->{HOST_ATTR}, @vld_host_attr)) {
                die "ERROR: invalid HOST_ATTR='$field->{HOST_ATTR}' for $REG_NAME.$field->{NAME}. Must be one of @vld_host_attr";
             }

             #check PE attribute is valid
             my @vld_pe_attr=qw(RW W NONE R);
             if (!in_list_str($field->{PE_ATTR}, @vld_pe_attr)) {
                die "ERROR: invalid PE_ATTR='$field->{PE_ATTR}' for $REG_NAME.$field->{NAME}. Must be one of @vld_pe_attr";
             }

             #check trigger attribute is valid
             my @vld_trigger_attr=qw(RW R W NONE);
             if (!in_list_str($field->{TRIGGER_ATTR}, @vld_trigger_attr)) {
                die "ERROR: invalid TRIGGER_ATTR='$field->{TRIGGER_ATTR}' for $REG_NAME.$field->{NAME}. Must be one of @vld_trigger_attr";
             }

             #check IO attribute is valid
             my @vld_io_attr=qw(internal out in lintr);
             if (!in_list_str($field->{IO_ATTR}, @vld_io_attr)) {
                die "ERROR: invalid IO_ATTR='$field->{IO_ATTR}' for $REG_NAME.$field->{NAME}. Must be one of @vld_io_attr";
             }

             #check IO attribute is valid. If pure read-only then must be "in". "lintr" requires W/RW to clear interrupt
             if ($field->{HOST_ATTR} eq "R" and $field->{PE_ATTR} eq "R" and $field->{IO_ATTR} ne "in") {
                die "ERROR: $REG_NAME.$field->{NAME} is R from HOST and PE. Must have IO_ATTR=in";
             }

             $field_list_macro .= " op($reg_name,$field_name) \\\n";

             my $msb = get_range_msb0($field->{BIT_RANGE});
             my $range;
             if ($msb eq "0") {
                $range = "";
             } else {
                $range = "[ $msb:0 ]";
             }
             my $size = $msb + 1;

             #decode bit range and make sure is not overlapping with any other on same register
             my ($m, $l) = split(/:/, $field->{BIT_RANGE});
             $m=eval($m);
             $l=eval($l);
             if ($m eq "" or $l eq "" or $m < $l) {
                die "ERROR: invalid BIT_RANGE=$field->{BIT_RANGE} for $REG_NAME.$field->{NAME}";
             }
             for my $i ($l..$m) {
                if ($bit_type[$i] ne "") {
                   die "ERROR: overlapping BIT_RANGE=$field->{BIT_RANGE} for $REG_NAME.$field->{NAME}";
                }
                $bit_type[$i]="$field->{HOST_ATTR}";
             }

             die("Register field $field_name is duplicated\n") if defined $field_exists{$field_name};
             $field_exists{$field_name}=1;

             if (implements_register($field)) {
                my $vhex_rst = vhex($field->{RESET}, $size, 2, "reset value for field $field_name");
                $rst        .= "$field_name $NBASG $vhex_rst ;\n";
                $ff         .= "$field_name $NBASG ${field_name}_D ;\n";
                $decl       .= "reg $range $field_name ;\n";
                $reg_reset     |= $field->{RESET} << $l;
                $reg_reset_msk |= mask2($m, $l);
                $ff_cnt     += $msb + 1;
             }
             elsif (implements_constant($field)) {
                my $const = vhex(get_const($field), $size, 2, "constant value for field $field_name");
                $decl       .= "wire $range $field_name ;\n";
                $decl       .= "assign $field_name = $const ;\n";
                $reg_reset     |= get_const($field)  << $l;
                $reg_reset_msk |= mask2($m, $l);
             }
             if ($field->{HOST_ATTR} ne "RC") {
                 $wini .= "${field_name}_D = $field_name ;\n";
             }

             $reg_rw_msk   |= $field->{HOST_ATTR} eq "RW"   ? mask2($m, $l) : 0;
             $reg_rw1c_msk |= $field->{HOST_ATTR} eq "RW1C" ? mask2($m, $l) : 0;
             $reg_r_msk    |= $field->{HOST_ATTR} eq "R"    ? mask2($m, $l) : 0;
             $reg_rc_msk   |= $field->{HOST_ATTR} eq "RC"   ? mask2($m, $l) : 0;

             my $lintr = $field->{IO_ATTR} eq "lintr";
             my $br = $field->{BIT_RANGE};
             my $extra_hw;

             if ($allow_pstrobe) {
                 my $field_spcs = " " x length(${field_name});

                 if ($field->{HOST_ATTR} eq "RW1C") {
                    $extra_hw  = "   ${field_name}_D =  wr_en_mask[ $br ] & ${field_name} & ~PWDATA[ $br ] \n".
                                 "   ${field_spcs}   | ~wr_en_mask[ $br ] & ${field_name} ;\n";
                 }
                 elsif ($field->{HOST_ATTR} eq "RW") {
                    $extra_hw  = "   ${field_name}_D =  wr_en_mask[ $br ] & PWDATA[ $br ] \n".
                                 "   ${field_spcs}   | ~wr_en_mask[ $br ] & ${field_name} ;\n";
                 }
             }
             else {
                 if ($field->{HOST_ATTR} eq "RW1C") {
                    $extra_hw  = "   ${field_name}_D =  ${field_name} & ~PWDATA[ $br ] ;\n";
                 }
                 elsif ($field->{HOST_ATTR} eq "RW") {
                    $extra_hw  = "   ${field_name}_D =  PWDATA[ $br ] ;\n";
                 }
             }

             if ($field->{IO_ATTR} eq "lintr") {
                $extra_hw =~ s/ =  / = (/m;
                $extra_hw =~ s/ ;/) | ${field_name}_intr ;/m;
             }
             $hw .= $extra_hw;

             if ($field->{HOST_ATTR} ne "RC") {
                 $decl .= "reg $range ${field_name}_D ;\n";
             }
             if ($field->{HOST_ATTR} ne "H") {
                $hr  .= "   PRDATA_D[ $br ] = $field_name ;\n";
             }
             else {
                $has_hidden=1;
             }

             if ($field->{PE_ATTR} eq "RW" || $field->{PE_ATTR} eq "R") {
                if ($mmio_style_ext) {
                   $mmi_this_reg .= "   mmio_ext_rdata_D [ $br ] = $field_name ;\n";
                }
                else {
                   $mmi_this_reg .= "mmi_${ch} [ $br ] = $field_name ;\n";
                }
                $mmio_any_r = 1;
             }
             if ($field->{PE_ATTR} eq "RW" || $field->{PE_ATTR} eq "W") {
                if ($mmio_style_ext) {
                   $mmo_this_reg .= "   ${field_name}_D = mmio_ext_wdata [ $br ] ;\n";
                }
                else {
                   $mmo_this_reg .= "   ${field_name}_D = mmo_$ch [ $br ] ;\n";
                }
                $mmio_any_w = 1;
             }

             my $in = $field->{IO_ATTR} eq "in";
             my $out = $field->{IO_ATTR} eq "out";

             my $trigger_wr = $field->{TRIGGER_ATTR} eq "W" || $field->{TRIGGER_ATTR} eq "RW";
             my $trigger_rd = $field->{TRIGGER_ATTR} eq "R" || $field->{TRIGGER_ATTR} eq "RW";
             my $trigger = $trigger_rd || $trigger_wr;

             if ($in) {
                $ports .= input($field_name, $msb+1);
             }
             elsif ($lintr) {
                $ports .= input($field_name."_intr", $msb+1);
             }

             if ($out || $lintr) {
                $ports .= output($field_name, $msb+1);
             }

             if ($trigger) {
                #if host can read
                if ($trigger_rd) {
                    $decl .= "reg ${field_name}_rd_trigger_D ;\n";
                    $ports .= output("${field_name}_rd_trigger_D");
                    $rini .= "${field_name}_rd_trigger_D = 0 ;\n";
                    $hr  .= "   ${field_name}_rd_trigger_D = 1'b1 ;\n";
                }

                #if host can write
                if ($trigger_wr) {
                    if ($field->{HOST_ATTR} eq "RW" || $field->{HOST_ATTR} eq "RW1C") {
                       $decl .= "reg ${field_name}_wr_trigger_D ;\n";
                       $ports .= output("${field_name}_D", $msb+1);
                       $ports .= output("${field_name}_wr_trigger_D");

                       $wini .= "${field_name}_wr_trigger_D = 1'b0 ;\n";
                       $hw  .= "   ${field_name}_wr_trigger_D = 1'b1 ;\n";
                    }

                    if ($field->{PE_ATTR} eq "RW" || $field->{PE_ATTR} eq "W") {
                       $mmo_this_reg .= "   ${field_name}_wr_trigger_D = 1'b1 ;\n";  #FIXME most likely incomplete
                    }
                }
             }

             for my $format ("c", "v") {
                my $define = "define ${MOD}_FLD_RNG_${field_name}\t$field->{BIT_RANGE}\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");

                my $chex_reset = chex($field->{RESET}, $format);
                my $define = "define ${MOD}_FLD_RST_${field_name}\t$chex_reset\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");

                my ($msb,$lsb)=get_msb_lsb($field->{BIT_RANGE});
                my $define = "define ${MOD}_FLD_LSB_${field_name}\t$lsb\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");

                my $define = "define ${MOD}_FLD_MSB_${field_name}\t$msb\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");

                my $w = $msb-$lsb+1;
                my $define = "define ${MOD}_FLD_WTH_${field_name}\t$w\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");

                my $mask=mask2($msb, $lsb);
                my $chex_mask = chex($mask, $format);
                my $define = "define ${MOD}_FLD_MSK_${field_name}\t$chex_mask\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");

                my $mask_lo = mask($w);
                my $chex_mask_lo = chex($mask_lo, $format);
                my $define = "define ${MOD}_FLD_MSKLO_${field_name}\t$chex_mask_lo\n";
                $host_defines{$format} .= "$tick{$format}$define";
                $pe_defines .= "#$define" if ($format eq "c");
             }

             my $enums = gen_enum($field, "${MOD}_REG", $field_name);
             $host_defines{c} .= $enums;
             $pe_defines .= $enums;

          } #end field loop

          for my $format ("c", "v") {
             {
                 my $chex_reset = chex($reg_reset, $format);
                 my $define = "define ${MOD}_RST_${reg_name}\t$chex_reset\n";
                 $host_defines{$format} .= "$tick{$format}$define";
                 $pe_defines .= "#$define" if ($format eq "c");
             }
             {
                 my $chex_rst_msk = chex($reg_reset_msk, $format);
                 $host_defines{$format} .= "$tick{$format}define ${MOD}_MSK_RST_${reg_name}\t$chex_rst_msk\n";
             }
             {
                 my $chex_rw_msk = chex($reg_rw_msk, $format);
                 $host_defines{$format} .= "$tick{$format}define ${MOD}_MSK_RW_${reg_name}\t$chex_rw_msk\n";
             }
             {
                 my $chex_rw1c_msk = chex($reg_rw1c_msk, $format);
                 $host_defines{$format} .= "$tick{$format}define ${MOD}_MSK_RW1C_${reg_name}\t$chex_rw1c_msk\n";
             }
             {
                 my $chex_r_msk = chex($reg_r_msk, $format);
                 $host_defines{$format} .= "$tick{$format}define ${MOD}_MSK_R_${reg_name}\t$chex_r_msk\n";
             }
             {
                 my $chex_rc_msk = chex($reg_rc_msk, $format);
                 $host_defines{$format} .= "$tick{$format}define ${MOD}_MSK_RC_${reg_name}\t$chex_rc_msk\n";
             }
          }

          if ($mmio_any_r && !$mmio_any_w) {
             $mmio_defines .= "static CR<$ch> $reg_name ;\n";
          }
          elsif (!$mmio_any_r && $mmio_any_w) {
             $mmio_defines .= "SR<$ch> $reg_name ;\n";
          }
          else {
             $mmio_defines .= "static CSR<$ch> $reg_name ;\n";
          }
          if ($mmio_any_r) {
             if ($mmio_style_ext) {
                 $mmi_this_reg .= "end\n";
             }
             $mmi .= $mmi_this_reg;
             if (!$mmio_style_ext) {
                $mmi_decl .= "reg [ 31:0 ] mmi_${ch} ;\n";
                $mmi_ports .= output("mmi_${ch}", 32) if $gen_mmio;
             }
             $overall_mmio_any_r = 1;
          }
          if ($mmio_any_w) {
             $mmo_this_reg .= "end\n";
             $mmo .= $mmo_this_reg;
             if ($gen_mmio && !$mmio_style_ext) {
                 $mmo_ports .= input("mmo_en_$ch");
                 $mmo_ports .= input("mmo_$ch", 32);
             }
             $overall_mmio_any_w = 1;
          }

          $hw .= "end\n";
          $hr .= "end\n";

      }
   }
   $hw .= "default: begin\n";
   if ($parallel_mode) {
       $hw .= "   wr_decerr = 1'b0 ; // no error provided, because of -parallel_mode\n";
   }
   else {
       $hw .= "   wr_decerr = 1'b1 ;\n";
   }
   $hw .= "end\n";
   $hr .= "default: begin\n";
   if ($parallel_mode) {
       $hr .= "   PRDATA_D = 32'h0 ;  // beause of -parallel_mode \n";
       $hr .= "   rd_decerr = 1'b0 ;  // no error provided, because of -parallel_mode\n";
   }
   else {
       $hr .= "   PRDATA_D = $rdata_on_decerr ;\n";
       $hr .= "   rd_decerr = 1'b1 ;\n";
   }
   $hr .= "end\n";
}



my $pkt_defines;
my $pkt_list_macro;
my $pkt_field_list_macro;

my $arr_ref = $data_in->{PKT_ARRAY};
if (ref($arr_ref) ne "ARRAY") { $gen_pkts=0; }

if ($gen_pkts) {
   foreach my $pkt (@{$arr_ref}) {
      if (!defined ($pkt->{NAME})) { die "ERROR: no NAME defined for register"; }
      if ($pkt->{NAME} eq "") { die "ERROR: invalid empty NAME for register"; }

      my $pkt_name = sanitize_name($pkt->{NAME});

      $pkt_defines .= "\n// pkt $pkt->{NAME}\n";
      $pkt_list_macro .= " op($pkt_name}) \\\n";


      my $field_arr_ref = $pkt->{FIELD};
      foreach my $field (@{$field_arr_ref}) {
         my $field_name = sanitize_name($field->{NAME});

         if (!defined( $field->{NAME} )) { die "ERROR: in reg $pkt->{NAME} found field w/o name"; }
         if ($field->{NAME} eq "") { die "ERROR: invalid empty field NAME in reg $pkt->{NAME}"; }

         if (!defined( $field->{BIT_RANGE} )) { die "ERROR: $pkt->{NAME}.$field_name has no BIT_RANGE"; }
         unless ($field->{BIT_RANGE} =~ /:/) {
            $field->{BIT_RANGE} .= ":" . $field->{BIT_RANGE};
         }

         $pkt_field_list_macro .= " op($pkt_name,$field_name) \\\n";

         my $full_name = "$pkt_name${sep}$field_name";
         my $define .= "#define ${MOD}_PKT_FLD_RNG_${full_name}\t$field->{BIT_RANGE}\n";
         $pkt_defines .= $define;
         my $enums = gen_enum($field, "${MOD}_PKT", $full_name);
         $pkt_defines .= $enums;
      }
   }
}

#-----------------------------------------------------------------------------
# Build up HTML documentation for this register
#-----------------------------------------------------------------------------

my $html_body="$data_in->{DEFAULTS}->{DOC}<BR>";
my $html_summ="";
if ($gen_regs) {
    $html_summ= "<table border='1' width='$html_width' cellspacing='0'>\n";
    $html_summ .= "<tr bgcolor='blue'>\n";
    $html_summ .= "<td align='center' width='110'><font color='yellow'><i>Address</i></font></td>\n";
    $html_summ .= "<td align='center' width='50' ><font color='yellow'><i>Name</i></font></td>\n";
    $html_summ .= "<td align='center'><i><font color='yellow'>Description</i></font></td>\n";
    $html_summ .= "</tr>\n";
    my $arr_ref = $data_in->{REG_ARRAY};
    foreach my $reg (@{$arr_ref}) {
       #see if the register is flagged as private
       my $private_doc=0;
       if (defined ($reg->{DOC_ATTR})) {
          $private_doc = $reg->{DOC_ATTR} eq "private";
       }
       if (!$private_doc) {

           my $reg_count     = given($reg->{COUNT}) ? $reg->{COUNT} + 0 : 1;
           my $reg_list_incr = given($reg->{INCR})  ? $reg->{INCR} + 0  : 4; 
           my $reg_list_idx0 = given($reg->{IDX0})  ? $reg->{IDX0} + 0  : 0; 

           my $RN = $reg->{NAME};

           my $chex_addr = chex($addr_by_name{$RN}, "c", 8);
           if ($reg_count > 1) {
              $chex_addr = chex($addr_by_name{list_reg_name($RN, 0 + $reg_list_idx0)}, "c", 8);
              $chex_addr .= ", " . chex($addr_by_name{list_reg_name($RN, 1 + $reg_list_idx0)}, "c", 8);
              if ($reg_count > 2) {
                  $chex_addr .= ", .. , " . chex($addr_by_name{list_reg_name($RN, $reg_count-1 + $reg_list_idx0)}, "c", 8);
              }
           }

           my $REG_NAME = $RN;
           if ($reg_count > 1) {
               if (0) {
                  $REG_NAME = list_reg_name($RN, 0 + $reg_list_idx0);;
                  $REG_NAME .= ", " . list_reg_name($RN, 1 + $reg_list_idx0);
                  if ($reg_count > 2) {
                      $REG_NAME .= ", .. , " . list_reg_name($RN, $reg_count-1 + $reg_list_idx0);
                  }
               }
               else {
                  $REG_NAME .= sprintf("_<%d-%d>", 0 + $reg_list_idx0, $reg_count - 1 + $reg_list_idx0);
               }
           }


           $html_body .= "<H3>Register $REG_NAME</H3>\n";
           $html_body .= "<table id=\"$REG_NAME\" border='0' width='$html_width'>\n";
           #$html_body .= "  <tr>\n";
           #$html_body .= "    <td><i>Register Name: <b>$REG_NAME</b></i></td>\n";
           #$html_body .= "  </tr>\n";
           $html_body .= "  <tr>\n";
           $html_body .= "    <td><b>APB address:</b> $chex_addr</td>\n";
           $html_body .= "  </tr>\n";
           $html_body .= "  <tr>\n";
           $html_body .= "    <td><b>Description:</b> $reg->{DOC}</td>\n";
           $html_body .= "  </tr>\n";
           if ($reg->{DOCEXT}) {
              $html_body .= "  <tr>\n";
              $html_body .= "    <td><i>$reg->{DOCEXT}</i></td>\n";
              $html_body .= "  </tr>\n";
           }
           $html_body .= "</table>\n";
           $html_body .= "<BR>\n";
           $html_body .= "<table border='1' width='$html_width' cellspacing='0'>\n";
           $html_body .= "  <tr bgcolor='blue'>\n";
           $html_body .= "    <td align='center' width='40'><font color='yellow'><i>Bits</i></font></td>\n";
           $html_body .= "    <td align='center' width='60'><font color='yellow'><i>Reset</i></font></td>\n";
           $html_body .= "    <td align='center' width='60'><font color='yellow'><i>Access</i></font></td>\n";
           $html_body .= "    <td align='center' width='100' cellpadding='5'><font color='yellow'><i>Field</i></font></td>\n";
           $html_body .= "    <td align='center'><i><font color='yellow'>Description</i></font></td>\n";
           $html_body .= "  </tr>\n";

           $html_summ .= "  <tr>\n";
           $html_summ .= "    <td align='center'>$chex_addr</td>\n";
           if ($hyperlinks) {
              $html_summ .= "    <td><a href=\"#$REG_NAME\">$REG_NAME</a></td>\n";
           }
           else {
              $html_summ .= "    <td>$REG_NAME</td>\n";
           }
           $html_summ .= "    <td>$reg->{DOC}</td>\n";
           $html_summ .= "  </tr>\n";

           my $field_arr_ref = $reg->{FIELD};
           foreach my $field (@{$field_arr_ref}) {
               my $br = bitrange_repr($field->{BIT_RANGE});
               my $chex_reset = "NA";
               if (implements_register($field)) {
                  $chex_reset = chex($field->{RESET});
               }
               elsif (implements_constant($field)) {
                  $chex_reset = chex(get_const($field));
               }
        
               $html_body .= "  <tr>\n";
               $html_body .= "    <td align='center'>$br</td>\n";
               $html_body .= "    <td align='center'>$chex_reset</td>\n";
               $html_body .= "    <td align='center'>$field->{HOST_ATTR}</td>\n";
               $html_body .= "    <td cellpadding='5'> $field->{NAME} </td>\n";
               $html_body .= "    <td>$field->{DOC}</td>\n";
               $html_body .= "  </tr>\n";
           }
           $html_body .= "</table><BR>\n";
       }
    }
    $html_body .= "<BR>\n";
    $html_summ .= "</table>\n";
}
if ($gen_pkts) {
   $html_body .= "<H2>COMMAND DEFINITION</H2>\n";
   my $arr_ref = $data_in->{PKT_ARRAY};
   foreach my $pkt (@{$arr_ref}) {
      $html_body .= "<BR>\n";
      $html_body .= "<table border='0' width='$html_width'>\n";
      $html_body .= "  <tr>\n";
      $html_body .= "    <td><i>Command Name: $pkt->{NAME}</i></td>\n";
      $html_body .= "  </tr>\n";
      $html_body .= "  <tr>\n";
      $html_body .= "    <td><i>Description: $pkt->{DOC}</i></td>\n";
      $html_body .= "  </tr>\n";
      $html_body .= "</table>\n";
      $html_body .= "<table border='1' width='$html_width' cellspacing='0'>\n";
      $html_body .= "  <tr bgcolor='blue'>\n";
      $html_body .= "    <td width='60'><font color='yellow'><i>Bits</i></font></td>\n";
      $html_body .= "    <td width='100'><font color='yellow'><i>Field</i></font></td>\n";
      $html_body .= "    <td><i><font color='yellow'>Description</i></font></td>\n";
      $html_body .= "  </tr>\n";
      my $field_arr_ref = $pkt->{FIELD};
      foreach my $field (@{$field_arr_ref}) {
         $html_body .= "  <tr>\n";
         my $br = bitrange_repr($field->{BIT_RANGE});
         $html_body .= "    <td >$br</td>\n";
         $html_body .= "    <td >$field->{NAME}</td>\n";
         $html_body .= "    <td>$field->{DOC}</td>\n";
         $html_body .= "  </tr>\n";
      }
      $html_body .= "</table><BR>\n";
   }
}

#-----------------------------------------------------------------------------
# PART 2 : generate output files
#-----------------------------------------------------------------------------

$hw =
$wini .
"if (PSEL & PWRITE) begin\n" .
"   case (PADDR)\n" .
       indent($hw,2) .
"   endcase\n" .
"end\n";

if ($gen_regs && $gen_mmio && $overall_mmio_any_w) {
   if ($mmio_style_ext) {
       $hw .=
       "else if (mmio_ext_en && mmio_ext_write) begin // mmo writes\n" .
       "   case (mmio_ext_address)\n" .
             indent($mmo,2) .
       "   endcase\n" .
       "end\n";
   }
   else {
       $hw .=
       "else begin // mmo writes\n" .
          indent($mmo) .
       "end\n";
   }
}

$hr =
$rini .
"if (PSEL & ~PWRITE) begin\n" .
"   case (PADDR)\n" .
       indent($hr,2) .
"   endcase\n" .
"end\n";

my $reset_edge = $reset_val == "1" ? "posedge" : "negedge";
my $ff = 
#"assign PRDATA = (PSEL & ~PWRITE & PENABLE) ? PRDATA_D : 0;\n" .
"always @($clock_edge $clock or $reset_edge $reset) begin\n" .
"   if ($reset == $reset_val) begin\n" .
       indent($rst,2) .
"   end\n" .
"   else if (PSEL_Q & PENABLE) begin\n".
       indent($ff,2) .
"   end\n" .
"end\n";

$hw=indent($hw);
$hr=indent($hr);

# final output

if (!$gen_mmio) {
   $mmo_ports="";
   $mmo_decl="";
   $mmi_ports="";
   $mmi_decl="";
}

if (!$overall_mmio_any_r) {
   $mmi_ports="";
   $mmi_decl="";
}

if (!$overall_mmio_any_w) {
   $mmo_ports="";
   $mmo_decl="";
}

#-----------------------------------------------------------------------------
# generation of Verilog file 
#-----------------------------------------------------------------------------
my $mod_io_list="\n";
$mod_io_list.="   // outputs\n   ";
$mod_io_list.= join(",\n   ", @g_output_list) . ",\n";
$mod_io_list.="   // inputs\n   ";
$mod_io_list.= join(",\n   ", @g_input_list) . "\n";

open(FOUT, "> $file_out") || die "ERROR: can't write into $file_out: $!";
print FOUT <<EOM 

// File autogenerated by gen_csr $version

module $mod($mod_io_list);

//--- PORTS ---
$ports
$mmo_ports
$mmi_ports
//--- DECL ---
$decl
$mmo_decl
$mmi_decl

always @(posedge PCLK or negedge PRESETN) begin
   if (PRESETN == 0)
      PSEL_Q $NBASG 1'b0;
   else
      PSEL_Q $NBASG PSEL;
end

always @(posedge PCLK or negedge PRESETN) begin
   if (PRESETN == 0)
      PRDATA $NBASG 'h0;
   else if (PSEL & ~PWRITE)
      PRDATA $NBASG PRDATA_D;
   else
      PRDATA $NBASG PRDATA;
end

always @(*) begin
   // --- read ---
$hr
end

always @(*) begin
   // --- write ---
$hw
end

//--- FF ---
$ff
EOM
;

if ($apb_v3) {
   print FOUT <<EOM 
//--- APB 3.0
assign PREADY = PSEL_Q & PENABLE ;
assign PSLVERR = rd_decerr | wr_decerr;

EOM
;
}

if ($gen_regs && $gen_mmio && $overall_mmio_any_r) {
   if ($mmio_style_ext) {
     $mmi = indent($mmi,3);
   print FOUT <<EOM 
always @(posedge PCLK or negedge PRESETN) begin
   if (PRESETN == 0) begin
       mmio_ext_rdata $NBASG 'h0;
       mmio_ext_rdata_vld $NBASG 'h0;
   end
   else begin
       mmio_ext_rdata $NBASG mmio_ext_rdata_D;
       mmio_ext_rdata_vld $NBASG mmio_ext_rdata_vld;
   end
end

always @(*) begin
   // --- mmi ---
   mmio_ext_rdata_D = 0;
   mmio_ext_rdata_vld_D = 0;
   if (mmio_ext_en && ~mmio_ext_write) begin
      mmio_ext_rdata_vld_D = 1;
      case (mmio_ext_address)
$mmi
      endcase
   end
end
EOM
;
   }
   else {
     $mmi=indent($mmi);
     print FOUT <<EOM 
always @(*) begin
   // --- mmi ---
$mmi
end
EOM
;
   }
}
print FOUT <<EOM 

endmodule

// FF count = $ff_cnt 

EOM
;

print FOUT "// vi" . "m:syntax=verilog:\n";
close (FOUT);

#-----------------------------------------------------------------------------
# common for subsequent files
#-----------------------------------------------------------------------------
my $csr_macros= <<EOM
// reg access macros
#define ${MOD}_ADDRI(r,i)                       (${MOD}_ADDR_ ## r ## _0 + (i) * ${MOD}_INCR_ ## r ## _0)
#define ${MOD}_ADDR(r)                          ${MOD}_ADDR_  ## r

#define ${MOD}_REGF_RST(f)                      ${MOD}_FLD_RST_  ## f
#define ${MOD}_REGF_ENUM(f,e)                   ${MOD}_FLD_ENUM_ ## f ## ${sep} ## e
#define ${MOD}_REGF_MSB(f)                      ${MOD}_FLD_MSB_  ## f
#define ${MOD}_REGF_LSB(f)                      ${MOD}_FLD_LSB_  ## f
#define ${MOD}_REGF_WIDTH(f)                    ${MOD}_FLD_WTH_  ## f
#define ${MOD}_REGF_MASK(f)                     ${MOD}_FLD_MSK_  ## f
#define ${MOD}_REGF_MASK_LOW(f)                 ${MOD}_FLD_MSKLO_ ## f

#define ${MOD}_RST_VALUE(f)                     ${MOD}_RST_   ## f
#define ${MOD}_RST_VLD(f)                       ${MOD}_MSK_RST_ ## f
#define ${MOD}_CLRF(fullRegVal,f)               ((fullRegVal) & ~${MOD}_REGF_MASK(f))
#define ${MOD}_GETF(fullRegVal,f)               (((fullRegVal) >> ${MOD}_REGF_LSB(f)) & ${MOD}_REGF_MASK_LOW(f))
#define ${MOD}_SETF(f,newFldVal)                ((newFldVal) << ${MOD}_REGF_LSB(f))
#define ${MOD}_CHGF(fullRegVal,f,newFldVal)     (${MOD}_CLRF(fullRegVal,f) | ${MOD}_SETF(f,newFldVal))

// Examples:
//
// reg = RegisterRead( ${MOD}_ADDR(PE0_register1) );
// reg = ${MOD}_CHGF( reg, PE0_register1${sep}field0, 3 );
// RegisterWrite( ${MOD}_ADDR(PE0_register1), reg );
//
// reg = RegisterRead( ${MOD}_ADDR(PE2_status) );
// if ( ${MOD}_GETF( reg, PE2_status${sep}busy ) == 1 ) { ... } 
EOM
;

my $pkt_macros= <<EOM
// pkt access macros
#define ${MOD}_PKTF_ENUM(f,e)                   ${MOD}_PKT_FLD_ENUM_ ## f ## ${sep} ## e
#define _${MOD}_PKTF_MSB(f)                     1 ? ${MOD}_PKT_FLD_RNG_ ## f
#define _${MOD}_PKTF_LSB(f)                     0 ? ${MOD}_PKT_FLD_RNG_ ## f
#define ${MOD}_PKTF_MSB(f)                      (_${MOD}_PKTF_MSB(f))
#define ${MOD}_PKTF_LSB(f)                      (_${MOD}_PKTF_LSB(f))

#define ${MOD}_PKTF_WIDTH(f)                    (${MOD}_PKTF_MSB(f) - ${MOD}_PKTF_LSB(f) + 1)
#define ${MOD}_PKTF_MASK_LOW(f)                 ((1 << ${MOD}_PKTF_WIDTH(f)) - 1)
#define ${MOD}_PKTF_MASK(f)                     (${MOD}_PKTF_MASK(f) << ${MOD}_PKTF_LSB(f))

#define ${MOD}_CLRPF(fullPktVal,f)              ((fullPktVal) & ~${MOD}_PKTF_MASK(f))
#define ${MOD}_GETPF(fullPktVal,f)              (((fullPktVal) >> ${MOD}_PKTF_LSB(f)) & ${MOD}_PKTF_MASK_LOW(f))
#define ${MOD}_SETPF(f,newFldVal)               ((newFldVal) << ${MOD}_PKTF_LSB(f))
#define ${MOD}_CHGPF(fullPktVal,f,newFldVal)    (${MOD}_CLRPF(fullPktVal,f) | ${MOD}_SETPF(f,newFldVal))
EOM
;

#-----------------------------------------------------------------------------
# Generate defines intended for the HOST (c format)
#-----------------------------------------------------------------------------
my $base_hex=chex($base);
open(FOUT, "> $file_host_defines_h") || die "ERROR: can't write into $file_host_defines_h: $!";
print FOUT <<EOM
#ifndef ${MOD}_HOST_DEFINES_H_INCLUDED
#define ${MOD}_HOST_DEFINES_H_INCLUDED

#ifndef ${MOD}_BASE
 #define ${MOD}_BASE $base_hex
#endif

$host_defines{c}
#define ${MOD}_REG_LIST(op) \\
$reg_list_macro
#define ${MOD}_REG_FIELD_LIST(op) \\
$field_list_macro
$csr_macros
#endif
EOM
;
close (FOUT);

#-----------------------------------------------------------------------------
# Generate defines intended for the HOST (verilog format)
#-----------------------------------------------------------------------------
$base_hex=chex($base, "v");
open(FOUT, "> $file_host_defines_vh") || die "ERROR: can't write into $file_host_defines_vh: $!";
print FOUT <<EOM

`ifdef ${MOD}_BASE
`else
 `define ${MOD}_BASE $base_hex
`endif

$host_defines{v}

EOM
;
close (FOUT);

#-----------------------------------------------------------------------------
# Generate PKT defines and access macro file
#-----------------------------------------------------------------------------
open(FOUT, "> $file_pkt_defines_h") || die "ERROR: can't write into $file_pkt_defines_h: $!";
print FOUT <<EOM
#ifndef ${MOD}_PKT_DEFINES_H_INCLUDED
#define ${MOD}_PKT_DEFINES_H_INCLUDED
$pkt_defines
#define ${MOD}_PKT_LIST(op) \\
$pkt_list_macro
#define ${MOD}_PKT_FIELD_LIST(op) \\
$pkt_field_list_macro
$pkt_macros
#endif
EOM
;
close (FOUT);

#-----------------------------------------------------------------------------
# print csr_params.pl
#-----------------------------------------------------------------------------
if (defined $file_csr_params_pl) {
    my $num_mmio_ch = $max_ch - $min_ch + 1;
    open(FOUT, "> $file_csr_params_pl") || die "ERROR: can't write into $file_csr_params_pl: $!";
    print FOUT <<EOM
\$MMIO_CSR_FIRST=$min_ch;
\$MMIO_CSR_LAST=$max_ch;
\$NUM_MMIO_CSR=$num_mmio_ch;
EOM
;
    close (FOUT);
}

#-----------------------------------------------------------------------------
# Generate HTML documentation
#-----------------------------------------------------------------------------
open(FOUT, "> $file_html") || die "ERROR: can't write into $file_html: $!";

my $hidden_doc=$has_hidden ?
"<tr> 
  <td>H</td>
  <td>Hidden (not accesible to host, only to PE)</td>
</tr>" : "";

print FOUT <<EOM

<html lang="en-US" xml:lang="en-US" xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>CSR documentation</title>
</head>
<body>

<H2>REGISTER DEFINITION SUMMARY</H2>

$html_summ

<H2>REGISTER DEFINITION</H2>

<table>
<tr> 
  <td width='100'><B>Symbol</B></td>
  <td width='400'><B>Access Type</B></td>
</tr> 
<tr> 
  <td>R</td>
  <td>Read Only</td>
</tr> 
<tr> 
  <td>RW</td>
  <td>Read/Write</td>
</tr> 
<tr> 
  <td>RW1C</td>
  <td>Read. Write 1 to clear a bit</td>
</tr> 
<tr> 
  <td>RC</td>
  <td>Read constant</td>
</tr> 
$hidden_doc
</table>

$html_body

<p>Automatically generated by gen_csr $version</p>

</body>
</html>

EOM
;
close (FOUT);

#-----------------------------------------------------------------------------
# Generate CSR/SR/CR class instantiations for PE accessing CSRS thorugh MMIO
#-----------------------------------------------------------------------------
if ($gen_mmio) {
    open(FOUT, "> $file_mmio_defines_h") || die "ERROR: can't write into $file_mmio_defines_h: $!";
    print FOUT <<EOM
#ifndef ${MOD}_MMIOS_H_INCLUDED
#define ${MOD}_MMIOS_H_INCLUDED

#include "csr.h"
#include "$file_pe_defines_h"

$mmio_defines
#endif
EOM
;
    close (FOUT);
}

#-----------------------------------------------------------------------------
# Generate defines intended for the PE
#-----------------------------------------------------------------------------
if ($gen_mmio) {
    open(FOUT, "> $file_pe_defines_h") || die "ERROR: can't write into $file_pe_defines_h: $!";
    print FOUT <<EOM
#ifndef ${MOD}_PE_DEFINES_H_INCLUDED
#define ${MOD}_PE_DEFINES_H_INCLUDED
$pe_defines
#define ${MOD}_REG_LIST(op) \\
$reg_list_macro
#define ${MOD}_REG_FIELD_LIST(op) \\
$field_list_macro
$csr_macros
#endif
EOM
;
    close (FOUT);
}

#-----------------------------------------------------------------------------
# Generate RALF
#-----------------------------------------------------------------------------
if ($file_ralf) {
    my $ralf_body ="block $mod {\n";
    $ralf_body   .="  bytes 4;\n";
    my $arr_ref = $data_in->{REG_ARRAY};
    foreach my $reg (@{$arr_ref}) {

       my $reg_count     = given($reg->{COUNT}) ? $reg->{COUNT} + 0 : 1;
       my $reg_list_incr = given($reg->{INCR})  ? $reg->{INCR} + 0  : 4; 
       my $reg_list_idx0 = given($reg->{IDX0})  ? $reg->{IDX0} + 0  : 0; 

       my $reg_range="";
       if (0) { #disable until ralf2rdl supports arrayed registers
          if ($reg_count > 1 && $reg_list_incr==4 && $reg_list_idx0==0) {
             $reg_range="[$reg_count]";
             $reg_count=1;
          }
       }

       for my $reg_num (0..$reg_count-1) {

          my $REG_NAME  = $reg->{NAME};
          my $reg_name  = sanitize_name($REG_NAME);

          if ($reg_count > 1 || $reg_range ne "") {
             $REG_NAME = list_reg_name($REG_NAME, $reg_num + $reg_list_idx0);
             $reg_name = list_reg_name($reg_name, $reg_num + $reg_list_idx0) if $reg_range eq "";
          }

           my $chex_addr = chex($addr_by_name{$REG_NAME}, "c", 8);

           $chex_addr = sprintf("%x", oct($chex_addr)/4);

           $ralf_body .= "  register $reg_name$reg_range \@'h$chex_addr {\n";

           my $field_arr_ref = $reg->{FIELD};
           my @reserved_keywords=("type"); #add here comma separated list of SV keyworkds to avoid
           foreach my $field (@{$field_arr_ref}) {
               if ($field->{HOST_ATTR} ne "H") {
                   my $br = bitrange_repr($field->{BIT_RANGE});
                   my $chex_reset = chex($field->{RESET});
                   if ($field->{HOST_ATTR} eq "RC") {
                      $chex_reset = chex(get_const($field));
                   }
                   $chex_reset =~ s/^0x//;
                   my $field_name = $field->{NAME};
                   $field_name = sanitize_name($field_name);
                   if (in_list_str($field_name, @reserved_keywords)) {
                      $field_name.= "_";
                   }
                   my ($m, $l) = split(/:/, $field->{BIT_RANGE});
                   $m=eval($m); $l=eval($l);
                   my $bits = $m - $l + 1;
                   my $access = $field->{HOST_ATTR} eq "RW"   ? "rw" :
                                $field->{HOST_ATTR} eq "R"    ? "ro" :
                                $field->{HOST_ATTR} eq "RW1C" ? "w1c" :
                                $field->{HOST_ATTR} eq "RC"   ? "ro" : "ERROR";

                   die "ERROR: unsupported field type for RALF generation ".
                       "$reg_name.$field_name $field->{HOST_ATTR}" if $access eq "ERROR";

                   my $field_pos_hex = sprintf("%x", $l);

                   $ralf_body .= "    field $field_name \@'h$field_pos_hex {\n";
                   $ralf_body .= "      bits $bits;\n";
                   if ($field_name ne "reserved" && $field_name ne "unused") {
                       $ralf_body .= "      access $access;\n";
                       $ralf_body .= "      reset 'h$chex_reset;\n";
                   }
                   $ralf_body .= "    }\n";
               }
           }
           $ralf_body .= "  }\n";
       }
   }
   $ralf_body.="}\n";
   open(FOUT, "> $file_ralf") || die "ERROR: can't write into $file_ralf: $!";
   print FOUT $ralf_body;
   close (FOUT);
}

#-----------------------------------------------------------------------------
# Generate IP-XACT
#-----------------------------------------------------------------------------
if ($file_ipxact) {

    my $name = "$mod";
    my $display_name = "$mod CSR block";

    my $ab_name = "$mod";
    my $ab_display_name = "$mod address block";
    my $ab_description = "$mod description";
    my $ab_base_addr = chex($base);
    my $ab_range = 0;
    my $ab_volatile = "true";
    my $I="\t";

    
    my $ipxact_body = "";

    my $arr_ref = $data_in->{REG_ARRAY};
    foreach my $reg (@{$arr_ref}) {

       my $reg_count     = given($reg->{COUNT}) ? $reg->{COUNT} + 0 : 1;
       my $reg_list_incr = given($reg->{INCR})  ? $reg->{INCR} + 0  : 4; 
       my $reg_list_idx0 = given($reg->{IDX0})  ? $reg->{IDX0} + 0  : 0; 

       my $reg_range="";
       if ($reg_count > 1 && $reg_list_incr==4 && $reg_list_idx0==0) {
           $reg_range="[$reg_count]";
           $reg_count=1;
       }

       for my $reg_num (0..$reg_count-1) {

           my $REG_NAME  = $reg->{NAME};
           my $reg_name  = sanitize_name($REG_NAME);

           if ($reg_count > 1 || $reg_range ne "") {
               $REG_NAME = list_reg_name($REG_NAME, $reg_num + $reg_list_idx0);
               $reg_name = list_reg_name($reg_name, $reg_num + $reg_list_idx0) if $reg_range eq "";
           }

           my $offset = $addr_by_name{$REG_NAME} - $base;
           my $chex_addr = chex($offset, "c", 8);
           $ab_range = $offset > $ab_range ? $offset : $ab_range;

           my $reg_access = "read-write";
           my $volatile = "true";
           my $reg_reset = 0;
           my $reg_reset_msk = 0;


           my $field_arr_ref = $reg->{FIELD};
           foreach my $field (@{$field_arr_ref}) {
               my ($m, $l) = split(/:/, $field->{BIT_RANGE});
               $m=eval($m);
               $l=eval($l);
  
               if (implements_register($field)) {
                  $reg_reset     |= $field->{RESET} << $l;
                  $reg_reset_msk |= mask2($m, $l);
               }
               elsif (implements_constant($field)) {
                  $reg_reset     |= get_const($field)  << $l;
                  $reg_reset_msk |= mask2($m, $l);
               }
           }
           $reg_reset = chex($reg_reset, "c");
           $reg_reset_msk = chex($reg_reset_msk, "c");

           $ipxact_body .= "$I$I$I<spirit:register>\n";
           $ipxact_body .= "$I$I$I$I<spirit:name>$REG_NAME</spirit:name>\n";
           $ipxact_body .= "$I$I$I$I<spirit:addressOffset>$chex_addr</spirit:addressOffset>\n";
           $ipxact_body .= "$I$I$I$I<spirit:size>32</spirit:size>\n";
           $ipxact_body .= "$I$I$I$I<spirit:volatile>$volatile</spirit:volatile>\n";
           $ipxact_body .= "$I$I$I$I<spirit:access>$reg_access</spirit:access>\n";
           $ipxact_body .= "$I$I$I$I<spirit:reset>\n";
           $ipxact_body .= "$I$I$I$I$I<spirit:value>$reg_reset</spirit:value>\n";
           $ipxact_body .= "$I$I$I$I$I<spirit:mask>$reg_reset_msk</spirit:mask>\n";
           $ipxact_body .= "$I$I$I$I</spirit:reset>\n";

           my $field_arr_ref = $reg->{FIELD};
           my @reserved_keywords=("type"); #add here comma separated list of SV keyworkds to avoid
           foreach my $field (@{$field_arr_ref}) {
               if ($field->{HOST_ATTR} ne "H") {
                   my $br = bitrange_repr($field->{BIT_RANGE});
                   my $chex_reset = chex($field->{RESET});
                   if ($field->{HOST_ATTR} eq "RC") {
                      $chex_reset = chex(get_const($field));
                   }
                   $chex_reset =~ s/^0x//;
                   my $field_name = $field->{NAME};
                   $field_name = sanitize_name($field_name);
                   if (in_list_str($field_name, @reserved_keywords)) {
                      $field_name.= "_";
                   }
                   my ($m, $l) = split(/:/, $field->{BIT_RANGE});
                   $m=eval($m); $l=eval($l);
                   my $bits = $m - $l + 1;
                   my $access = $field->{HOST_ATTR} eq "RW"   ? "read-write" :
                                $field->{HOST_ATTR} eq "R"    ? "read-only" :
                                $field->{HOST_ATTR} eq "RW1C" ? "read-write" :
                                $field->{HOST_ATTR} eq "RC"   ? "read-only" : "ERROR";

                   die "ERROR: unsupported field type for xact generation ".
                       "$reg_name.$field_name $field->{HOST_ATTR}" if $access eq "ERROR";

                   my $field_pos_hex = sprintf("%x", $l);

                   $ipxact_body .= "$I$I$I$I<spirit:field>\n";
                   $ipxact_body .= "$I$I$I$I$I<spirit:name>$field_name</spirit:name>\n";
                   $ipxact_body .= "$I$I$I$I$I<spirit:bitOffset>$l</spirit:bitOffset>\n";
                   $ipxact_body .= "$I$I$I$I$I<spirit:bitWidth>$bits</spirit:bitWidth>\n";
                   if ($field_name ne "reserved" && $field_name ne "unused") {
                       $ipxact_body .= "$I$I$I$I$I<spirit:access>$access</spirit:access>\n";
                   }
                   $ipxact_body .= "$I$I$I$I</spirit:field>\n";
               }
           }

           $ipxact_body .= "$I$I$I</spirit:register>\n";
       }
   }

   $ab_range = chex($ab_range+4);

   my $ipxact_head ='<?xml version="1.0" encoding="UTF-8" ?>' ."\n".
                    '<spirit:memoryMaps' ."\n".
                    $I.'xmlns:spirit="http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.4"' ."\n".
                    $I.'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"'."\n".
                    $I.'xsi:schemaLocation="http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.4 ' ."\n".
                    $I.$I.'http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.4/index.xsd">' ."\n".
                    "$I<spirit:memoryMap>\n".
                    "$I$I<spirit:name>$name</spirit:name>\n".
                    "$I$I<spirit:displayName>$display_name</spirit:displayName>\n".
                    "$I$I<spirit:addressBlock>\n".
                    "$I$I$I<spirit:name>$ab_name</spirit:name>\n".
                    "$I$I$I<spirit:displayName>$ab_display_name</spirit:displayName>\n".
                    "$I$I$I<spirit:description>$ab_description</spirit:description>\n".
                    "$I$I$I<spirit:baseAddress>$ab_base_addr</spirit:baseAddress>\n".
                    "$I$I$I<spirit:range>$ab_range</spirit:range>\n".
                    "$I$I$I<spirit:width>32</spirit:width>\n".
                    "$I$I$I<spirit:usage>register</spirit:usage>\n".
                    "$I$I$I<spirit:volatile>$ab_volatile</spirit:volatile>\n". 
                    "";

   my $ipxact_tail.="$I$I</spirit:addressBlock>\n".
                    "$I</spirit:memoryMap>\n".
                    "</spirit:memoryMaps>\n".
                    "";

   open(FOUT, "> $file_ipxact") || die "ERROR: can't write into $file_ipxact: $!";
   print FOUT $ipxact_head . $ipxact_body . $ipxact_tail;
   close (FOUT);
}

#-----------------------------------------------------------------------------
# Generate interface file with g2p
#-----------------------------------------------------------------------------
if ($file_g2p) {
   my $g2p_body = join(", \\\n", (@g_input_g2p_list, @g_output_g2p_list));
   open(FOUT, "> $file_g2p") || die "ERROR: can't write into $file_g2p: $!";
   print FOUT $g2p_body;
   close (FOUT);
}

#-----------------------------------------------------------------------------
# syntax
#-----------------------------------------------------------------------------
sub syntax {

   print<<EOF

    gen_csrs Rev $version. Generation of Control/Status verilog register file 
    and documentation based on XML description

    Usage: $0 [options] xml_filename

    Where options is any combination of the following (can be abbreviated to unique)

       -out f              filename of the output register module 
                            (default $file_out)
       -mod s              define module name as <s>
                            (default is base of -out file)
       -mmio_defines f     filename of the defines and macros for mmio usage 
                            (default <mod>_mmios.h)
       -host_defines f     filename of the defines and macros for host usage 
                            (default <mod>_host_defines.h)
       -host_vdefines f    filename of the defines and macros for host usage in verilog 
                            (default <mod>_host_defines.vh)
       -pe_defines f       filename of the defines and macros for PE usage 
                            (default <mod>_pe_defines.h)
       -pkt_defines f      filename of the defines and macros for pkt processing 
                            (default ${mod}_pkt_defines.h)
       -csr_params f       filename of the csr parameters file 
                            (not generated unless provided)
       -ralf f             filename of the output RALF file generated 
                            (not generated unless provided)
       -ipxact f           filename of the output IP-XACT file generated 
                            (not generated unless provided)
       -g2p f              Output file to interface with g2p
                            (not generated unless provided)
       -html f             filename for the output HTML documentation 
                            (default <mod>.html)
       -[no]parallel_mode  in Parallel_mode PREADY/PRDATA's from several gen_csr 
                           modules can be OR'ed together and PSLVERR is never asserted. 
                            (default $parallel_mode)
       -[no]gen_regs       generate register portion of the output 
                            (default $gen_regs)
       -[no]gen_pkts       generate Command portion of the output 
                            (default $gen_pkts)
       -[no]hyperlinks     Create hyperlinks from summary to each register on html out
                            (default $hyperlinks)
       -[no]warn_aw        Warn if constants specified are larger than expected size 
                            (default $warn_aw)
       -vlogsep s          Separator for register name and field in verilog ports 
                            (default $vlogsep)
       -sep s              Separator for register name and field for everything else 
                            (default $sep)
       -cq n               Include this clock-to-q delay on non-blocking assignments 
                            to help waveform debugging. None if 0 (default $cq_delay)
       -[no]pstrb          Include PSTRB input control 
                            (default $allow_pstrobe)
       -rdata_on_decerr vn Value returned on read if reading a non-existing/non-readable 
                            register (default $rdata_on_decerr)
       -help               Display this message

   Where: f is a valid filename (E.g /path/to/file.txt)
          s is a string then conforms to C identifier rules (E.g. value_max)
          n is a natural number (E.g 2)
          vn is a verilog formated number/constant (E.g. 32'hdeadbeef)

          <mod> is extracted as the basename of the xml_filename if no provided 
          (e.g. /path/timer_csrs.xml yields timer_csrs)

EOF
;
   exit(1);
}

#-----------------------------------------------------------------------------
# indent 3 spaces input multiline string
#-----------------------------------------------------------------------------
sub indent {
   my $out = $_[0];
   my $times = $_[1] || 1;
   my $spc = "   " x $times;
   $out =~ s/^/$spc/gm;
   return $out;
}

#-----------------------------------------------------------------------------
# get MSB of a a:b type of bit-range
#-----------------------------------------------------------------------------
sub get_range_msb0 ($) {
   my ($bit_range) = @_;
   if ($bit_range =~ /:/) {
      my ($msb, $lsb) = split(/\s*:\s*/, $bit_range);
      my $val = $msb - $lsb;
      return "$val";
   }
   else {
      return "0";
   }
}

#-----------------------------------------------------------------------------
# get LSB of a a:b type of bit-range
#-----------------------------------------------------------------------------
sub get_msb_lsb ($) {
   my ($bit_range) = @_;
   if ($bit_range =~ /:/) {
      my ($msb, $lsb) = split(/\s*:\s*/, $bit_range);
      return ($msb,$lsb);
   }
   else {
      return ($bit_range,$bit_range);
   }
}

#-----------------------------------------------------------------------------
# return constant if define or 0 as default if not
#-----------------------------------------------------------------------------
sub get_const($) {
   my ($field) = @_;
   return $field->{CONST} if $field->{CONST};
   return "0";
}

#-----------------------------------------------------------------------------
# return 1 if the attributes indicate a register must be implemented inside 
# CSR, 0 if it is a direct external input
#-----------------------------------------------------------------------------
sub implements_register ($) {
   my ($field) = @_;
   if (implements_constant($field)) { return 0; }
   if ($field->{IO_ATTR} eq "in") { return 0; }
   return 1;
}

#-----------------------------------------------------------------------------
# return 1 if the attributes indicate a constant is internally generated for
# this field
#-----------------------------------------------------------------------------
sub implements_constant ($) {
   my ($field) = @_;
   if ($field->{HOST_ATTR} eq "RC") { return 1; }
   return 0;
}

#-----------------------------------------------------------------------------
# convert to decimal allowing for 0xAB, 15, 0xAA_BB type of inputs
#-----------------------------------------------------------------------------
sub dec ($) {
   my ($in) = @_;
   my $x = $in; 
   $x =~ s/_//g; # allow under-scores for readability
   $x =~ s/^\s+//; #trim leading
   $x =~ s/\s+$//; #trim trailing
   if ($x =~ /^0x/) { return oct($x); }
   if ($x =~ /[a-fA-F]/) {
      die("ERROR: expected number, got $in wich appears hex but has no 0x prefix");
   }
   return $x;
}

#-----------------------------------------------------------------------------
#-----------------------------------------------------------------------------
sub mask2 ($$) {
   my ($msb, $lsb) = @_;
   return mask($msb-$lsb+1) << $lsb;
}

sub mask ($) {
   my ($bits) = @_;
   return (1 << $bits)-1;
}

#-----------------------------------------------------------------------------
# format number as verilog 'hXX
#-----------------------------------------------------------------------------
sub vhex ($$$$) {
   my ($val, $siz, $warn, $msg) = @_;
   if (($val & mask($siz)) != $val) {
      if ($warn == 1) {
          printf "WARNING: Constant 0x%x wider than expected size %d-bits [$msg]\n", $val, $siz;
      }
      if ($warn == 2) {
          printf "ERROR: Constant 0x%x wider than expected size %d-bits [$msg]\n", $val, $siz;
          exit 1;
      }
   }
   my $s=sprintf("${siz}'h%X",$val & mask($siz));
   return $s;
}

#-----------------------------------------------------------------------------
#-----------------------------------------------------------------------------
sub chex {
   my ($dec, $format, $dig)=@_;
   my $s;
   my $prefix = defined($format) && ($format eq "v") ? "'h" : "0x";
   if (defined ($dig)) {
      $s=sprintf("%s%0${dig}X", $prefix, $dec);
   }
   else {
      $s=sprintf("%s%X", $prefix, $dec);
   }
   return $s;
}

#-----------------------------------------------------------------------------
#-----------------------------------------------------------------------------
sub gen_enum ($$$) {
   my ($field, $prefix, $full_name) = @_;
   my $defines;
   my $enum_arr_ref = $field->{ENUM_LIST};
   if (ref($enum_arr_ref) eq "ARRAY") { 
      my $val=0;
      foreach my $enum (@{$enum_arr_ref}) {
         my $full_name_enum = "${full_name}${sep}$enum->{NAME}";
         if (defined $enum->{VALUE}) { $val = dec($enum->{VALUE}); }
         else { $val++; }
         my $define .= "#define ${prefix}_FLD_ENUM_${full_name_enum}\t$val\n";
         $defines .= $define;
      } 
   }
   return $defines;
}


#-----------------------------------------------------------------------------
#-----------------------------------------------------------------------------
sub given {
   return defined($_[0]) && ($_[0] ne "");
}

#-----------------------------------------------------------------------------
# given a bit range return how it should be represented in documentation
#-----------------------------------------------------------------------------
sub bitrange_repr($) {
   my ($br) = @_;
   my ($msb, $lsb) = split(/\s*:\s*/, $br);
   if ($msb eq $lsb) {
      $br = $msb;
   }
   return $br;
}

#-----------------------------------------------------------------------------
# return 1 if a string is in a give list of strings, 0 otherwise
#-----------------------------------------------------------------------------
sub in_list_str {
   my ($val, @list) = @_;
   foreach my $x (@list) {
      if ($val eq $x) { return 1 }
   }
   return 0;
}

#-----------------------------------------------------------------------------
# convert spaces to _ and mixed case to lower case to unify identifier names
#-----------------------------------------------------------------------------
sub sanitize_name {
   my ($x) = @_;
   $x =~ s/\s+/_/g;
   $x =~ tr/A-Z/a-z/;
   return $x;
}

#-----------------------------------------------------------------------------
# generate verilog code for an input and add port name to a global list
#-----------------------------------------------------------------------------
sub input {
   my ($port, $size) = @_;
   $size = 1 if !defined $size;
   my $bit_range = "";
   if ($size > 1) {
       my $msb = $size-1;
       $bit_range = "[ $msb:0 ]";
   }
   push @g_input_list, $port;
   push @g_input_g2p_list, "Input($size, name='$port')";
   return "input $bit_range $port ;\n";
}

#-----------------------------------------------------------------------------
# generate verilog code for an output and add port name to a global list
#-----------------------------------------------------------------------------
sub output {
   my ($port, $size) = @_;
   $size = 1 if !defined $size;
   my $bit_range = "";
   if ($size > 1) {
       my $msb = $size-1;
       $bit_range = "[ $msb:0 ]";
   }
   push @g_output_list, $port;
   push @g_output_g2p_list, "Output($size, name='$port')";
   return "output $bit_range $port ;\n";
}

#-----------------------------------------------------------------------------
#-----------------------------------------------------------------------------
sub list_reg_name {
   my ($name, $i) = @_;
   return sprintf("%s_%d", $name, $i);
}

#-----------------------------------------------------------------------------
# Convert an XML file into a perl package that has the same contents
#-----------------------------------------------------------------------------
sub parseXml {
   my ($file, $file_out) = @_;

   open(FOUT, "> $file_out") || die "ERROR: can't write into $file_out: $!";

      my $xml_in=new XML::Simple;
      my $data_in=$xml_in->XMLin($file, 
          grouptags  => {REG_ARRAY=>'REG','PKT_ARRAY'=>'PKT', 'ENUM_LIST'=>'ENUM'}
         ,forcearray => ['FIELD','REG']
      );

      print FOUT new Data::Dumper([$data_in], ["data_in"])->Dump();
      print FOUT  "\n";
      print FOUT "1;";
      print FOUT  "\n";

   close(FOUT);
}
