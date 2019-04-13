#!/bin/sh

# 
# PlanAhead(TM)
# runme.sh: a PlanAhead-generated Runs Script for UNIX
# Copyright 1986-1999, 2001-2012 Xilinx, Inc. All Rights Reserved.
# 

echo "This script was generated under a different operating system."
echo "Please update the PATH and LD_LIBRARY_PATH variables below, before executing this script"
exit

if [ -z "$PATH" ]; then
  PATH=C:/Xilinx/14.2/ISE_DS/EDK/bin/nt;C:/Xilinx/14.2/ISE_DS/EDK/lib/nt;C:/Xilinx/14.2/ISE_DS/ISE/bin/nt;C:/Xilinx/14.2/ISE_DS/ISE/lib/nt;C:/Xilinx/14.2/ISE_DS/common/bin/nt;C:/Xilinx/14.2/ISE_DS/common/lib/nt:C:/Xilinx/14.2/ISE_DS/PlanAhead/bin
else
  PATH=C:/Xilinx/14.2/ISE_DS/EDK/bin/nt;C:/Xilinx/14.2/ISE_DS/EDK/lib/nt;C:/Xilinx/14.2/ISE_DS/ISE/bin/nt;C:/Xilinx/14.2/ISE_DS/ISE/lib/nt;C:/Xilinx/14.2/ISE_DS/common/bin/nt;C:/Xilinx/14.2/ISE_DS/common/lib/nt:C:/Xilinx/14.2/ISE_DS/PlanAhead/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD=`dirname "$0"`
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep ngdbuild -intstyle ise -p xc6slx45csg324-3 -uc "counterdisplay.ucf" "counterdisplay.edf"
EAStep map -intstyle pa -w -r 4 -ol high "counterdisplay.ngd"
EAStep par -intstyle pa "counterdisplay.ncd" -w "counterdisplay_routed.ncd" -ol high
EAStep trce -intstyle ise -o "counterdisplay.twr" -v 3 -l 30 -nodatasheet -fastpaths "counterdisplay_routed.ncd" "counterdisplay.pcf"
EAStep xdl -secure -ncd2xdl -nopips "counterdisplay_routed.ncd" "counterdisplay_routed.xdl"
