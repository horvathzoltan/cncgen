(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_usb_tavtarto.txt)
(output file: uniturn_usb_tavtarto_plot.gcode)
(created on: K júl. 11 21:25:31 2023)
(total time: 00:05:44.000)
(total cut: 1431.53mm)
(total length: 2877.77mm)
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
(cmd line: -i uniturn_usb_tavtarto.txt -t)
(plot cmd: -i uniturn_usb_tavtarto.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d1.500 h19.000)
(set mode to YXZ)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z5.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=1.500)
m0 (machine stop)
g0 z5.000
s50.000 (set spindle speed)
f300.000 (set feed)

(bigyó_1)
(box)
(time: 0.00133333)
(line)
(time: 0.00133333)
(linear cut)
G0 x0.700y5.950 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x5.300y5.950z-0.020
G04 P100
G1 x0.700y5.950z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.0415575)

(line)
(time: 0.0415575)
(linear cut)
G0 x5.300y6.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.700y6.550z-0.020
G04 P100
G1 x5.300y6.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.0809388)

(time: 0.0809388)
(box)
(time: 0.0809388)
(line)
(time: 0.0809388)
(linear cut)
G0 x8.700y5.950 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x13.300y5.950z-0.020
G04 P100
G1 x8.700y5.950z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.119612)

(line)
(time: 0.119612)
(linear cut)
G0 x13.300y6.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x8.700y6.550z-0.020
G04 P100
G1 x13.300y6.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.158994)

(time: 0.158994)
(box)
(time: 0.158994)
(line)
(time: 0.158994)
(linear cut)
G0 x0.700y18.450 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x5.300y18.450z-0.020
G04 P100
G1 x0.700y18.450z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.206638)

(line)
(time: 0.206638)
(linear cut)
G0 x5.300y19.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.700y19.050z-0.020
G04 P100
G1 x5.300y19.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.246019)

(time: 0.246019)
(box)
(time: 0.246019)
(line)
(time: 0.246019)
(linear cut)
G0 x8.700y18.450 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x13.300y18.450z-0.020
G04 P100
G1 x8.700y18.450z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.284693)

(line)
(time: 0.284693)
(linear cut)
G0 x13.300y19.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x8.700y19.050z-0.020
G04 P100
G1 x13.300y19.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.324074)

(time: 0.324074)
(box)
(time: 0.324074)

(line)
(time: 0.324074)
(linear cut)
G0 x7.050y8.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x7.050y16.800z-0.020
G04 P100
G1 x7.050y8.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.395207)

(line)
(time: 0.395207)
(linear cut)
G0 x6.450y16.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x6.450y8.200z-0.020
G04 P100
G1 x6.450y16.800z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.463787)
(time: 0.463787)
(horony)
(line)
(time: 0.463787)
(linear cut)
G0 x13.750y0.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x13.750y25.000z-0.020
G1 x13.750y0.000z-0.020
G0 z2.000 (lift up)
(time: 0.648085)
(line)
(time: 0.648085)
(linear cut)
G0 x14.050y0.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x14.050y25.000z-0.020
G1 x14.050y0.000z-0.020
G0 z2.000 (lift up)
(time: 0.821447)
(körvonal)
(box)
(time: 0.821447)

(line)
(time: 0.821447)
(linear cut)
G0 x0.000y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x10.250y-0.750z-0.020
G1 x0.000y-0.750z-0.020
G0 z2.000 (lift up)
(time: 0.904609)
(line)
(time: 0.904609)
(linear cut)
G0 x13.750y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.000y-0.750z-0.020
G1 x13.750y-0.750z-0.020
G0 z2.000 (lift up)
(time: 0.987559)

(line)
(time: 0.987559)
(linear cut)
G0 x24.750y0.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.750y10.750z-0.020
G1 x24.750y0.000z-0.020
G0 z2.000 (lift up)
(time: 1.07205)
(line)
(time: 1.07205)
(linear cut)
G0 x24.750y14.250 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.750y25.000z-0.020
G1 x24.750y14.250z-0.020
G0 z2.000 (lift up)
(time: 1.15866)

(line)
(time: 1.15866)
(linear cut)
G0 x-0.750y25.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-0.750y14.250z-0.020
G1 x-0.750y25.000z-0.020
G0 z2.000 (lift up)
(time: 1.25418)
(line)
(time: 1.25418)
(linear cut)
G0 x-0.750y10.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-0.750y0.000z-0.020
G1 x-0.750y10.750z-0.020
G0 z2.000 (lift up)
(time: 1.3408)
(time: 1.3408)
(bigyó_2)
(box)
(time: 1.3408)
(line)
(time: 1.3408)
(linear cut)
G0 x0.700y32.450 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x5.300y32.450z-0.020
G04 P100
G1 x0.700y32.450z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.39137)

(line)
(time: 1.39137)
(linear cut)
G0 x5.300y33.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.700y33.050z-0.020
G04 P100
G1 x5.300y33.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.43075)

(time: 1.43075)
(box)
(time: 1.43075)
(line)
(time: 1.43075)
(linear cut)
G0 x8.700y32.450 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x13.300y32.450z-0.020
G04 P100
G1 x8.700y32.450z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.46942)

(line)
(time: 1.46942)
(linear cut)
G0 x13.300y33.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x8.700y33.050z-0.020
G04 P100
G1 x13.300y33.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.50881)

(time: 1.50881)
(box)
(time: 1.50881)
(line)
(time: 1.50881)
(linear cut)
G0 x0.700y44.950 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x5.300y44.950z-0.020
G04 P100
G1 x0.700y44.950z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.55645)

(line)
(time: 1.55645)
(linear cut)
G0 x5.300y45.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.700y45.550z-0.020
G04 P100
G1 x5.300y45.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.59583)

(time: 1.59583)
(box)
(time: 1.59583)
(line)
(time: 1.59583)
(linear cut)
G0 x8.700y44.950 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x13.300y44.950z-0.020
G04 P100
G1 x8.700y44.950z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.63451)

(line)
(time: 1.63451)
(linear cut)
G0 x13.300y45.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x8.700y45.550z-0.020
G04 P100
G1 x13.300y45.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.67389)

(time: 1.67389)
(box)
(time: 1.67389)

(line)
(time: 1.67389)
(linear cut)
G0 x7.050y34.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x7.050y43.300z-0.020
G04 P100
G1 x7.050y34.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.74502)

(line)
(time: 1.74502)
(linear cut)
G0 x6.450y43.300 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x6.450y34.700z-0.020
G04 P100
G1 x6.450y43.300z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.8136)
(time: 1.8136)
(horony)
(line)
(time: 1.8136)
(linear cut)
G0 x21.200y26.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x21.200y51.500z-0.020
G1 x21.200y26.500z-0.020
G0 z2.000 (lift up)
(time: 2.00058)
(line)
(time: 2.00058)
(linear cut)
G0 x21.500y26.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x21.500y51.500z-0.020
G1 x21.500y26.500z-0.020
G0 z2.000 (lift up)
(time: 2.17394)
(körvonal2)
(box)
(time: 2.17394)

(line)
(time: 2.17394)
(linear cut)
G0 x0.000y25.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x10.250y25.750z-0.020
G1 x0.000y25.750z-0.020
G0 z2.000 (lift up)
(time: 2.26203)
(line)
(time: 2.26203)
(linear cut)
G0 x13.750y25.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.000y25.750z-0.020
G1 x13.750y25.750z-0.020
G0 z2.000 (lift up)
(time: 2.34498)

(line)
(time: 2.34498)
(linear cut)
G0 x24.750y26.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.750y37.250z-0.020
G1 x24.750y26.500z-0.020
G0 z2.000 (lift up)
(time: 2.42947)
(line)
(time: 2.42947)
(linear cut)
G0 x24.750y40.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x24.750y51.500z-0.020
G1 x24.750y40.750z-0.020
G0 z2.000 (lift up)
(time: 2.51609)

(line)
(time: 2.51609)
(linear cut)
G0 x24.000y52.250 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x13.750y52.250z-0.020
G1 x24.000y52.250z-0.020
G0 z2.000 (lift up)
(time: 2.59757)
(line)
(time: 2.59757)
(linear cut)
G0 x10.250y52.250 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x0.000y52.250z-0.020
G1 x10.250y52.250z-0.020
G0 z2.000 (lift up)
(time: 2.68052)

(line)
(time: 2.68052)
(linear cut)
G0 x-0.750y51.500 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-0.750y40.750z-0.020
G1 x-0.750y51.500z-0.020
G0 z2.000 (lift up)
(time: 2.76501)
(line)
(time: 2.76501)
(linear cut)
G0 x-0.750y37.250 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x-0.750y26.500z-0.020
G1 x-0.750y37.250z-0.020
G0 z2.000 (lift up)
(time: 2.85163)
(time: 2.85163)
(merevito_1)
(box)
(time: 2.85163)

(line)
(time: 2.85163)
(linear cut)
G0 x25.500y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x29.250y-0.750z-0.020
G04 P100
G1 x25.500y-0.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.9128)
(line)
(time: 2.9128)
(linear cut)
G0 x32.750y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x36.500y-0.750z-0.020
G04 P100
G1 x32.750y-0.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.94817)

(line)
(time: 2.94817)
(linear cut)
G0 x36.500y44.550 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x32.750y44.550z-0.020
G04 P100
G1 x36.500y44.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.00886)
(line)
(time: 3.00886)
(linear cut)
G0 x29.250y44.550 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x25.500y44.550z-0.020
G04 P100
G1 x29.250y44.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.04422)
(time: 3.04422)
(box)
(time: 3.04422)
(line)
(time: 3.04422)
(linear cut)
G0 x32.750y0.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x32.750y2.750z-0.020
G04 P100
G1 x32.750y0.250z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.09589)
(line)
(time: 3.09589)
(linear cut)
G0 x32.750y2.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x29.250y2.750z-0.020
G04 P100
G1 x32.750y2.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.12671)
(line)
(time: 3.12671)
(linear cut)
G0 x29.250y2.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x29.250y0.250z-0.020
G04 P100
G1 x29.250y2.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.15141)
(time: 3.15141)
(box)
(time: 3.15141)
(line)
(time: 3.15141)
(linear cut)
G0 x29.250y41.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x32.750y41.050z-0.020
G04 P100
G1 x29.250y41.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.20566)
(line)
(time: 3.20566)
(linear cut)
G0 x32.750y41.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x32.750y43.550z-0.020
G04 P100
G1 x32.750y41.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.23036)
(line)
(time: 3.23036)
(linear cut)
G0 x29.250y43.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x29.250y41.050z-0.020
G04 P100
G1 x29.250y43.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.25553)
(time: 3.25553)
(box)
(time: 3.25553)

(line)
(time: 3.25553)
(linear cut)
G0 x30.800y17.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x30.800y26.200z-0.020
G04 P100
G1 x30.800y17.600z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.3356)

(line)
(time: 3.3356)
(linear cut)
G0 x30.200y26.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x30.200y17.600z-0.020
G04 P100
G1 x30.200y26.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.40418)
(time: 3.40418)
(merevito_2)
(box)
(time: 3.40418)

(line)
(time: 3.40418)
(linear cut)
G0 x38.000y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x41.750y-0.750z-0.020
G04 P100
G1 x38.000y-0.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.45328)
(line)
(time: 3.45328)
(linear cut)
G0 x45.250y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x49.000y-0.750z-0.020
G04 P100
G1 x45.250y-0.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.48865)

(line)
(time: 3.48865)
(linear cut)
G0 x49.750y0.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x49.750y20.150z-0.020
G1 x49.750y0.000z-0.020
G0 z2.000 (lift up)
(time: 3.63166)
(line)
(time: 3.63166)
(linear cut)
G0 x49.750y23.650 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x49.750y43.800z-0.020
G1 x49.750y23.650z-0.020
G0 z2.000 (lift up)
(time: 3.78717)

(line)
(time: 3.78717)
(linear cut)
G0 x49.000y44.550 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x45.250y44.550z-0.020
G04 P100
G1 x49.000y44.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.83153)
(line)
(time: 3.83153)
(linear cut)
G0 x41.750y44.550 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x38.000y44.550z-0.020
G04 P100
G1 x41.750y44.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.8669)

(line)
(time: 3.8669)
(linear cut)
G0 x37.250y43.800 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x37.250y23.650z-0.020
G1 x37.250y43.800z-0.020
G0 z2.000 (lift up)
(time: 4.00991)
(line)
(time: 4.00991)
(linear cut)
G0 x37.250y20.150 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x37.250y0.000z-0.020
G1 x37.250y20.150z-0.020
G0 z2.000 (lift up)
(time: 4.16542)
(time: 4.16542)
(box)
(time: 4.16542)
(line)
(time: 4.16542)
(linear cut)
G0 x45.250y0.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x45.250y2.750z-0.020
G04 P100
G1 x45.250y0.250z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.2018)
(line)
(time: 4.2018)
(linear cut)
G0 x45.250y2.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x41.750y2.750z-0.020
G04 P100
G1 x45.250y2.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.23261)
(line)
(time: 4.23261)
(linear cut)
G0 x41.750y2.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x41.750y0.250z-0.020
G04 P100
G1 x41.750y2.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.25731)
(time: 4.25731)
(box)
(time: 4.25731)
(line)
(time: 4.25731)
(linear cut)
G0 x41.750y41.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x45.250y41.050z-0.020
G04 P100
G1 x41.750y41.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.31156)
(line)
(time: 4.31156)
(linear cut)
G0 x45.250y41.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x45.250y43.550z-0.020
G04 P100
G1 x45.250y41.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.33626)
(line)
(time: 4.33626)
(linear cut)
G0 x41.750y43.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x41.750y41.050z-0.020
G04 P100
G1 x41.750y43.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.36144)
(time: 4.36144)
(box)
(time: 4.36144)

(line)
(time: 4.36144)
(linear cut)
G0 x43.550y17.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x43.550y26.200z-0.020
G04 P100
G1 x43.550y17.600z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.44151)

(line)
(time: 4.44151)
(linear cut)
G0 x42.950y26.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x42.950y17.600z-0.020
G04 P100
G1 x42.950y26.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.51009)
(time: 4.51009)
(merevito_3)
(box)
(time: 4.51009)

(line)
(time: 4.51009)
(linear cut)
G0 x50.500y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x56.250y-0.750z-0.020
G04 P100
G1 x50.500y-0.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.57248)
(line)
(time: 4.57248)
(linear cut)
G0 x59.750y-0.750 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x65.500y-0.750z-0.020
G04 P100
G1 x59.750y-0.750z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.62248)

(line)
(time: 4.62248)
(linear cut)
G0 x66.250y0.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x66.250y20.150z-0.020
G1 x66.250y0.000z-0.020
G0 z2.000 (lift up)
(time: 4.76673)
(line)
(time: 4.76673)
(linear cut)
G0 x66.250y23.650 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x66.250y43.800z-0.020
G1 x66.250y23.650z-0.020
G0 z2.000 (lift up)
(time: 4.92224)

(line)
(time: 4.92224)
(linear cut)
G0 x65.500y44.550 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x59.750y44.550z-0.020
G04 P100
G1 x65.500y44.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.97993)
(line)
(time: 4.97993)
(linear cut)
G0 x56.250y44.550 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G1 x50.500y44.550z-0.020
G04 P100
G1 x56.250y44.550z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 5.02993)
(time: 5.02993)
(box)
(time: 5.02993)
(line)
(time: 5.02993)
(linear cut)
G0 x52.250y0.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x52.250y16.150z-0.020
G1 x52.250y0.250z-0.020
G0 z2.000 (lift up)
(time: 5.17096)
(line)
(time: 5.17096)
(linear cut)
G0 x52.250y16.150 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x50.750y16.150z-0.020
G04 P100
G1 x52.250y16.150z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 5.19699)
(time: 5.19699)
(box)
(time: 5.19699)
(line)
(time: 5.19699)
(linear cut)
G0 x50.750y27.650 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x52.250y27.650z-0.020
G04 P100
G1 x50.750y27.650z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 5.22018)
(line)
(time: 5.22018)
(linear cut)
G0 x52.250y27.650 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x52.250y43.550z-0.020
G1 x52.250y27.650z-0.020
G0 z2.000 (lift up)
(time: 5.3332)
(time: 5.3332)
(box)
(time: 5.3332)
(line)
(time: 5.3332)
(linear cut)
G0 x65.250y16.150 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x63.750y16.150z-0.020
G04 P100
G1 x65.250y16.150z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 5.36019)
(line)
(time: 5.36019)
(linear cut)
G0 x63.750y16.150 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x63.750y0.250z-0.020
G1 x63.750y16.150z-0.020
G0 z2.000 (lift up)
(time: 5.4732)
(time: 5.4732)
(box)
(time: 5.4732)
(line)
(time: 5.4732)
(linear cut)
G0 x63.750y27.650 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x65.250y27.650z-0.020
G04 P100
G1 x63.750y27.650z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 5.49633)
(line)
(time: 5.49633)
(linear cut)
G0 x63.750y43.550 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x63.750y27.650z-0.020
G1 x63.750y43.550z-0.020
G0 z2.000 (lift up)
(time: 5.61836)
(time: 5.61836)
(hole - helical interpolation)
(time: 5.61836)
(predrill)
G0 x58.000y21.900 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(helical cut)
G0 z2.000 (lift up)
G0 x56.750y21.900 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i1.250
G2 z-0.020 i1.250
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.69544)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
