#------------------------------------------------------------------------------
# Copyright (c) 2006-Present, Esencia Technologies Inc
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
# Please send bugs and suggestions to: tools@esenciatech.com
#------------------------------------------------------------------------------

TOOL_DIR=.
MOD=mycsrs

all: $(MOD).v

$(MOD).v: $(MOD).xml $(TOOL_DIR)/gen_csrs.pl
	$(TOOL_DIR)/gen_csrs.pl -pstrb $(MOD).xml -nowarn_aw -out $(MOD).v \
        -g2p $(MOD).ios -ralf $(MOD).ralf -ipxact $(MOD)_ipxact.xml
	./ralf2rdl/ralf2rdl.sh $(MOD).ralf 

validate: $(MOD).xml
	xmllint --schema $(TOOL_DIR)/csr_schema.xsd --noout $(MOD).xml 

compare:
	diff GEN_REF/$(MOD).html .
	diff GEN_REF/$(MOD).ralf .
	diff GEN_REF/$(MOD).rdl .
	diff GEN_REF/$(MOD).v .
	diff GEN_REF/$(MOD)_host_defines.h .
	diff GEN_REF/$(MOD)_host_defines.vh .
	diff GEN_REF/$(MOD)_mmios.h .
	diff GEN_REF/$(MOD)_pe_defines.h .
	diff GEN_REF/$(MOD)_pkt_defines.h .

clean:
	-rm -f $(MOD).v $(MOD)_host_defines.h $(MOD)_host_defines.vh $(MOD).html $(MOD)_mmios.h $(MOD)_pe_defines.h $(MOD)_pkt_defines.h ${MOD}_regs.pm ${MOD}.ralf ${MOD}_ipxact.xml $(MOD).rdl $(MOD).ios
