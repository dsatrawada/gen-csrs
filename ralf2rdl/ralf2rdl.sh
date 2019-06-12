#!/usr/bin/env bash 
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
if [ "$1" == "" ]; then
    echo ""
    echo "Usage: $0 <ralf_file_path> [rdl_file_path]"
    echo ""
    echo "Converts from ralf to rdl. If the destination file is not provided"
    echo "it is generated with the source file path removing .ralf extension"
    echo "if present and appending .rdl"
    echo ""
    exit 1
fi
if [ "$2" == "" ]; then
    dir=`dirname $1`
    base=`basename $1 .ralf`
    dst="${dir}/${base}.rdl"
else
    dst="$2"
fi
script_dir=`dirname $0`
    
cat $script_dir/ralf2rdl.tcl $1 | tclsh > $dst
