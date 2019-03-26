EESchema Schematic File Version 4
LIBS:south-chonk-cache
EELAYER 26 0
EELAYER END
$Descr User 5195 4000
encoding utf-8
Sheet 2 3
Title "Reset Circuit"
Date "2019-03-26"
Rev "1"
Comp "Peioris Boards"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L keyboard_parts:SW_PUSH SW?
U 1 1 5C99A5ED
P 2425 1750
AR Path="/5C99A5ED" Ref="SW?"  Part="1" 
AR Path="/5C992EF8/5C99A5ED" Ref="SW-RST1"  Part="1" 
F 0 "SW-RST1" H 2425 1906 25  0000 C CNN
F 1 "SW" H 2425 1854 25  0000 C CNN
F 2 "Keebio-Parts:SW_Tactile_SPST_Angled_MJTP1117" H 2425 1750 50  0001 C CNN
F 3 "" H 2425 1750 50  0001 C CNN
	1    2425 1750
	1    0    0    -1  
$EndComp
Text HLabel 2725 1750 2    50   Input ~ 0
RST
$Comp
L keyboard_parts:GND #PWR0104
U 1 1 5EB62DDB
P 2125 1750
F 0 "#PWR0104" H 2125 1800 20  0001 C CNN
F 1 "GND" H 2125 1809 30  0000 C CNN
F 2 "" H 2125 1750 60  0000 C CNN
F 3 "" H 2125 1750 60  0000 C CNN
	1    2125 1750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
