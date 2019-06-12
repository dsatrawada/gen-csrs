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
# Author: Ricky Bhangal
# Please send bugs and suggestions to: tools@esenciatech.com
#------------------------------------------------------------------------------

use strict;
use warnings;

use Getopt::Long;
use File::Basename;
use File::Path;
use File::Copy;
use Data::Dumper;
use XML::Writer;

sub usage {
    my $msg = "Usage: $0";
    $msg .= " -h {help message}";
    $msg .= " [-c registers.csv]";
    $msg .= "\n";
    printf STDERR $msg;
    exit -1;
}

my $help = 0;
my $CsvFile = "";
my $RegDesc;

GetOptions ("h"  => \$help,
            "c=s" => \$CsvFile) or usage();

usage() if $help;

parse_csv($CsvFile);
write_xml();
#print Dumper ($RegDesc);

sub write_xml {
    my $writer = XML::Writer->new(DATA_MODE => 1, DATA_INDENT => 2, );
    $writer->startTag('REGISTERS');
    $writer->emptyTag('DEFAULTS');
    $writer->startTag('REG_ARRAY');
    my @regs = sort keys %{$RegDesc->{Regs}};
    #print Dumper (@regs);
    foreach my $reg (sort @regs) {
        $writer->startTag('REG', NAME => $reg, OFFS => $RegDesc->{Regs}->{$reg}->{Addr});
        foreach (sort keys %{$RegDesc->{Regs}->{$reg}->{Fields}}) {
            my $accType = $RegDesc->{Regs}->{$reg}->{Fields}->{$_}->{Access};
            next if ($accType eq "RV"); 
            if ($accType eq "RO") {
                $accType = "R";
            }
            if ($accType eq "WO") {
                $accType = "RW";
            }
            my $ioAttr = "";
            if ($accType eq "R") {
                $ioAttr = "in";
            } elsif ($accType eq "RW") {
                $ioAttr = "out";
            }
            $writer->emptyTag('FIELD',
                               NAME => $_, 
                               BIT_RANGE => $RegDesc->{Regs}->{$reg}->{Fields}->{$_}->{Bits}, 
                               HOST_ATTR => $accType, 
                               IO_ATTR => $ioAttr, 
                               RESET => $RegDesc->{Regs}->{$reg}->{Fields}->{$_}->{Default}); 
            #FIXME IO_ATTR ??? Should it be in or out at Reg block boundary?);    
        }
        $writer->endTag('REG'); 
    }
    $writer->endTag('REG_ARRAY');
    $writer->endTag('REGISTERS');
}


sub parse_csv {
    my $fn = shift || "";

    open(my $cfh, '<', $fn) or die "Unable to open $fn\n";

    my $fndReg = 0;
    my $sttReg = 0;
    my $hdrVld = 0;
    my $RegName = "";
    while (my $line = <$cfh>) {
        my @lineArr = split (/,/,$line);
        foreach my $tf (@lineArr) {
           $tf =~ s/\s*\"\s*//g; 
        }
        next if (($#lineArr) < 1); 
        if ($lineArr[0] =~ /Name/) {
            $fndReg = 1;
            $sttReg = 1;
            next;
        }

        if ($sttReg == 1) {
            $hdrVld = 1;
            $RegDesc->{Regs}->{$lineArr[0]}->{Addr} =  ($lineArr[5]);
            $RegDesc->{Regs}->{$lineArr[0]}->{Desc} =  ($lineArr[6]);
            $RegName = $lineArr[0];
            $sttReg = 0;
            next;
        }
        if ( ($fndReg == 1) and ($sttReg == 0) and ($hdrVld == 0) ) {
            next if (
                     ($lineArr[0] eq "") ||
                     ($lineArr[2] eq "") ||
                     ($lineArr[5] eq "") ||
                     ($lineArr[6] eq "")
                    );
            $RegDesc->{Regs}->{$RegName}->{Fields}->{$lineArr[1]}->{Bits} =  ($lineArr[0]);
            $RegDesc->{Regs}->{$RegName}->{Fields}->{$lineArr[1]}->{Access} =  ($lineArr[2]);
            $RegDesc->{Regs}->{$RegName}->{Fields}->{$lineArr[1]}->{Default} =  ($lineArr[5]);
            next;
        }
        if ($hdrVld == 1) {
            $hdrVld = 0;
            next;
        }
        
        if ($lineArr[0] =~ /:/) {
            my ($msb,$lsb) = split (/:/,$lineArr[0]);
            if ($lsb eq "0") {
                $fndReg = 0;
            }
            next;
        }
    }
}
