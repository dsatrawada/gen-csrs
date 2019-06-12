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
#-----------------------------------------------------------------------------
# TBD: Needs testing with more inputs
#-----------------------------------------------------------------------------
set g_in_register 0
set g_regw 32
set g_baseaddr "TBD"

proc instantiate_regs {} {
    global g_registers
    global g_registers_list
    foreach n $g_registers_list {
        set v $g_registers($n)
        puts "  reg_${n}_type ${n}@$v;"
    }
}

#-----------------------------------------------------------------------------
# block entry point
#-----------------------------------------------------------------------------
proc block {name blk} {
    global g_baseaddr 
    puts "// file automatically generated - do not edit"
    puts ""
    puts "`include \"lib_udp.rdl\""
    puts ""
    puts "addrmap map_$name {"
    puts ""
    puts "  desc = \"$name\";"
    puts "  Space = \"$name\";"
    puts ""
    uplevel $blk
    instantiate_regs
    puts "};"
}

#used on block and register context
proc bytes {n} {
    global g_in_register
    global g_regw
    if {$g_in_register == 0} {
        #puts "  // bytes $n"
    } else {
        #puts "    // bytes $n"
    }
    set g_regw [expr 8 * $n]
}

#-----------------------------------------------------------------------------
# register and sub items
#-----------------------------------------------------------------------------
proc register {name offs blk} {
    global g_registers
    global g_registers_list
    global g_reserved_cnt
    global g_in_register
    set g_in_register 1
    set g_reserved_cnt 0
    puts "  reg reg_${name}_type {"
    uplevel $blk
    puts "  }; // end register $name"
    puts ""
    set offs [string replace $offs 0 0 ""]
    set offs [string map {'h 0x} $offs]
    set g_registers($name) $offs
    lappend g_registers_list $name
    set g_in_register 0
}

proc doc {x} {
    global g_regw
    puts "    desc = \"$x\";"
    puts "    regwidth  = $g_regw;"
#   puts "    accesswidth  = 8;"
#   puts "    shared;"
    puts ""
}

#-----------------------------------------------------------------------------
# field and sub items
#-----------------------------------------------------------------------------
proc field {name offs blk} {
    global g_bits
    global g_access
    global g_reset
    global g_reserved_cnt
    uplevel $blk
    if {$name == "Reserved"} {
        append name "$g_reserved_cnt"
        incr g_reserved_cnt
    }

    set lsb [string replace $offs 0 0 ""]
    set lsb [string map {'h 0x} $lsb]
    set msb  [expr $g_bits + $lsb - 1]
    puts "    field {"
    puts "        desc = \"\";"
    puts "        AccessType = \"$g_access\";"
    puts "    } $name \[$msb:$lsb\] = $g_bits$g_reset;"
    set g_bits "<>"
    set g_access "<>"
    set g_reset "<>"
}

proc bits {n} {
    global g_bits
    set g_bits $n
}

proc access {n} {
    global g_access
    set g_access $n
}

proc reset {n} {
    global g_reset
    set g_reset $n
}
