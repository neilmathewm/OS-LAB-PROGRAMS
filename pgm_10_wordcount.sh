#!/bin/bash
echo "Enter FileName : "
read file_name
echo ""
echo -n "Word Count :"
wc -w $file_name
echo ""
echo -n "Line Count :"
wc -l $file_name
echo ""
echo -n "Character Count :"
wc -m $file_name
echo ""
