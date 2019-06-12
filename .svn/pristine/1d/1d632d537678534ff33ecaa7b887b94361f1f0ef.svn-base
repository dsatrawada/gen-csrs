#!/usr/bin/env bash
if [ "$1" == "" ]; then
    echo ""
    echo "Usage: $0 <csr_def.xlsx> [csr_def.xml]"
    echo ""
    echo "Converts from spreadsheet format to XML accepted by gen_csrs"
    echo ""
    exit 1
fi
xlsx_file=$1

dir=`dirname $1`
base=`basename $1 .xlsx`
if [ "$2" == "" ]; then
    xml_file="${dir}/${base}.xml"
else
    xml_file="$2"
fi

csv_file=${dir}/${base}.csv

echo "xlsx_file $xlsx_file"
echo "csv_file $csv_file"
echo "xml_file $xml_file"

ssconvert $xlsx_file $csv_file && \
$(dirname $0)/csv_to_toolxml.pl -c $csv_file > $xml_file
