(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_also.txt)
(output file: uniturn_also_plot.gcode)
(created on: K júl. 11 19:46:32 2023)
(total time: 00:23:20.000)
(total cut: 6275.59mm)
(total length: 9916.47mm)
G21 (metric units)
G90 (absolute mode)
G17 (select XY plane)
G94 (feedrate per minute)
G80 (cancel active cycles)
G54 (set work coordinate system offset)
M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)

G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)
(uniturn mérőállomás alsó szerelőlap)
(cmd line: -i uniturn_also.txt -t)
(plot cmd: -i uniturn_also.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d2.000 h19.000)
(set tool 2 to t2 m  d3.000 h19.000)
(set tool 3 to t3 m  d4.000 h19.000)
(set mode to YXZ)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z5.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=2.000)
m0 (machine stop)
g0 z5.000
s50.000 (set spindle speed)
f300.000 (set feed)

(pi3b furatok)
(box)
(time: 0.00133333)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x74.750y7.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.0672749)
(hole - helical interpolation)
(time: 0.0672749)
(helical cut)
G0 x132.750y7.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.121837)
(hole - helical interpolation)
(time: 0.121837)
(helical cut)
G0 x132.750y56.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.170403)
(hole - helical interpolation)
(time: 0.170403)
(helical cut)
G0 x74.750y56.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.224965)
(time: 0.224965)
(relé furatok)
(box)
(time: 0.224965)
(hole - helical interpolation)
(time: 0.224965)
(helical cut)
G0 x63.500y80.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.26903)
(hole - helical interpolation)
(time: 0.26903)
(helical cut)
G0 x96.600y80.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.317481)
(hole - helical interpolation)
(time: 0.317481)
(helical cut)
G0 x96.600y124.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.373722)
(hole - helical interpolation)
(time: 0.373722)
(helical cut)
G0 x63.500y124.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.422173)
(time: 0.422173)
(pizero furatok)
(box)
(time: 0.422173)
(hole - helical interpolation)
(time: 0.422173)
(helical cut)
G0 x122.750y65.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.494182)
(hole - helical interpolation)
(time: 0.494182)
(helical cut)
G0 x145.750y65.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.525446)
(hole - helical interpolation)
(time: 0.525446)
(helical cut)
G0 x145.750y123.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.580008)
(hole - helical interpolation)
(time: 0.580008)
(helical cut)
G0 x122.750y123.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.250
G2 z-0.020 i0.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.611272)
(time: 0.611272)
(alátámasztás)
(hole - helical interpolation)
(time: 0.611272)
(helical cut)
G0 x83.500y71.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.68107)
(hole - helical interpolation)
(time: 0.68107)
(helical cut)
G0 x105.500y131.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.750039)
(b3218101 - net-box 220, vers. i)
(rögzítő furatok)
(hole - helical interpolation)
(time: 0.750039)
(helical cut)
G0 x3.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.884465)
(hole - helical interpolation)
(time: 0.884465)
(helical cut)
G0 x123.500y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.990821)
(hole - helical interpolation)
(time: 0.990821)
(helical cut)
G0 x145.500y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.03703)
(hole - helical interpolation)
(time: 1.03703)
(helical cut)
G0 x145.500y169.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.15938)
(hole - helical interpolation)
(time: 1.15938)
(helical cut)
G0 x123.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.20559)
(hole - helical interpolation)
(time: 1.20559)
(helical cut)
G0 x3.500y189.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.500
G2 z-0.020 i0.500
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.31195)
(dugó kivágások)
(box)
(time: 1.31195)

(line)
(time: 1.31195)
(linear cut)
G0 x3.000y47.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x25.000y47.000z-0.020
G1 x3.000y47.000z-0.020
G0 z2.000 (lift up)
(time: 1.55865)
(line)
(time: 1.55865)
(linear cut)
G0 x29.000y47.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x51.000y47.000z-0.020
G1 x29.000y47.000z-0.020
G0 z2.000 (lift up)
(time: 1.72805)

(line)
(time: 1.72805)
(linear cut)
G0 x55.000y51.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x55.000y82.333z-0.020
G1 x55.000y51.000z-0.020
G0 z2.000 (lift up)
(time: 1.95988)
(line)
(time: 1.95988)
(linear cut)
G0 x55.000y86.333 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x55.000y115.667z-0.020
G1 x55.000y86.333z-0.020
G0 z2.000 (lift up)
(time: 2.18439)
(line)
(time: 2.18439)
(linear cut)
G0 x55.000y119.667 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x55.000y151.000z-0.020
G1 x55.000y119.667z-0.020
G0 z2.000 (lift up)
(time: 2.42089)

(line)
(time: 2.42089)
(linear cut)
G0 x51.000y155.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x29.000y155.000z-0.020
G1 x51.000y155.000z-0.020
G0 z2.000 (lift up)
(time: 2.59665)
(line)
(time: 2.59665)
(linear cut)
G0 x25.000y155.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x3.000y155.000z-0.020
G1 x25.000y155.000z-0.020
G0 z2.000 (lift up)
(time: 2.76606)
(arc)
(time: 2.76606)
(circular_arc cut)
G0 x55.000y51.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x51.000y47.000z-0.020 i-4.000 j0.000
G3 x55.000y51.000z-0.020 i0.000 j4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.0227)
(arc)
(time: 3.0227)
(circular_arc cut)
G0 x51.000y155.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x55.000y151.000z-0.020 i0.000 j-4.000
G3 x51.000y155.000z-0.020 i-4.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.50107)
(arc)
(time: 4.50107)
(circular_arc cut)
G0 x3.000y155.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x-1.000y159.000z-0.020 i0.000 j4.000
G3 x3.000y155.000z-0.020 i4.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 8.30757)
(arc)
(time: 8.30757)
(circular_arc cut)
G0 x-1.000y43.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x3.000y47.000z-0.020 i4.000 j0.000
G3 x-1.000y43.000z-0.020 i0.000 j-4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 9.12783)
(time: 9.12783)
(box)
(time: 9.12783)

(line)
(time: 9.12783)
(linear cut)
G0 x3.000y21.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x8.000y21.000z-0.020
G04 P100
G1 x3.000y21.000z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 9.18149)
(line)
(time: 9.18149)
(linear cut)
G0 x12.000y21.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x17.000y21.000z-0.020
G04 P100
G1 x12.000y21.000z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 9.22632)

(line)
(time: 9.22632)
(linear cut)
G0 x21.000y25.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x21.000y32.000z-0.020
G04 P100
G1 x21.000y25.000z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 9.28504)
(line)
(time: 9.28504)
(linear cut)
G0 x21.000y36.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x21.000y43.000z-0.020
G04 P100
G1 x21.000y36.000z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 9.34452)
(arc)
(time: 9.34452)
(circular_arc cut)
G0 x21.000y25.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x17.000y21.000z-0.020 i-4.000 j0.000
G3 x21.000y25.000z-0.020 i0.000 j4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 9.46803)
(arc)
(time: 9.46803)
(circular_arc cut)
G0 x21.000y43.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x25.000y47.000z-0.020 i4.000 j0.000
G3 x21.000y43.000z-0.020 i0.000 j-4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 9.90051)

(arc)
(time: 9.90051)
(circular_arc cut)
G0 x-1.000y17.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x3.000y21.000z-0.020 i4.000 j0.000
G3 x-1.000y17.000z-0.020 i0.000 j-4.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 10.1941)
(time: 10.1941)
(usb hub furatai)
(körvonal)
(box)
(time: 10.1941)

(line)
(time: 10.1941)
(linear cut)
G0 x4.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x38.000y-1.000z-0.020
G1 x4.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 10.4387)
(line)
(time: 10.4387)
(linear cut)
G0 x42.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x74.000y-1.000z-0.020
G1 x42.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 10.6827)
(line)
(time: 10.6827)
(linear cut)
G0 x78.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x110.000y-1.000z-0.020
G1 x78.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 10.9255)
(line)
(time: 10.9255)
(linear cut)
G0 x114.000y-1.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x148.000y-1.000z-0.020
G1 x114.000y-1.000z-0.020
G0 z2.000 (lift up)
(time: 11.1815)

(line)
(time: 11.1815)
(linear cut)
G0 x153.000y4.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y48.500z-0.020
G1 x153.000y4.000z-0.020
G0 z2.000 (lift up)
(time: 11.5098)
(line)
(time: 11.5098)
(linear cut)
G0 x153.000y52.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y95.000z-0.020
G1 x153.000y52.500z-0.020
G0 z2.000 (lift up)
(time: 11.8308)
(line)
(time: 11.8308)
(linear cut)
G0 x153.000y99.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y141.500z-0.020
G1 x153.000y99.000z-0.020
G0 z2.000 (lift up)
(time: 12.1506)
(line)
(time: 12.1506)
(linear cut)
G0 x153.000y145.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x153.000y190.000z-0.020
G1 x153.000y145.500z-0.020
G0 z2.000 (lift up)
(time: 12.4836)

(line)
(time: 12.4836)
(linear cut)
G0 x148.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x114.000y195.000z-0.020
G1 x148.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 12.7488)
(line)
(time: 12.7488)
(linear cut)
G0 x110.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x78.000y195.000z-0.020
G1 x110.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 12.9929)
(line)
(time: 12.9929)
(linear cut)
G0 x74.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x42.000y195.000z-0.020
G1 x74.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 13.2356)
(line)
(time: 13.2356)
(linear cut)
G0 x38.000y195.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x4.000y195.000z-0.020
G1 x38.000y195.000z-0.020
G0 z2.000 (lift up)
(time: 13.4917)

(line)
(time: 13.4917)
(linear cut)
G0 x-1.000y190.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y145.500z-0.020
G1 x-1.000y190.000z-0.020
G0 z2.000 (lift up)
(time: 13.8199)
(line)
(time: 13.8199)
(linear cut)
G0 x-1.000y141.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y99.000z-0.020
G1 x-1.000y141.500z-0.020
G0 z2.000 (lift up)
(time: 14.141)
(line)
(time: 14.141)
(linear cut)
G0 x-1.000y95.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y52.500z-0.020
G1 x-1.000y95.000z-0.020
G0 z2.000 (lift up)
(time: 14.4607)
(line)
(time: 14.4607)
(linear cut)
G0 x-1.000y48.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-1.000y4.000z-0.020
G1 x-1.000y48.500z-0.020
G0 z2.000 (lift up)
(time: 14.7937)
(arc)
(time: 14.7937)
(circular_arc cut)
G0 x153.000y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x148.000y-1.000z-0.020 i-5.000 j0.000
G3 x153.000y4.000z-0.020 i0.000 j5.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 18.3805)
(arc)
(time: 18.3805)
(circular_arc cut)
G0 x148.000y195.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x153.000y190.000z-0.020 i0.000 j-5.000
G3 x148.000y195.000z-0.020 i-5.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 19.5233)
(arc)
(time: 19.5233)
(circular_arc cut)
G0 x-1.000y190.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x4.000y195.000z-0.020 i5.000 j0.000
G3 x-1.000y190.000z-0.020 i0.000 j-5.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 23.0449)
(arc)
(time: 23.0449)
(circular_arc cut)
G0 x4.000y-1.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 x-1.000y4.000z-0.020 i0.000 j5.000
G3 x4.000y-1.000z-0.020 i5.000 j0.000
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 23.3415)
(time: 23.3415)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
