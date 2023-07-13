(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: pi_alatet_15.txt)
(output file: pi_alatet_15_plot.gcode)
(created on: K júl. 11 21:10:52 2023)
(total time: 00:25:16.000)
(total cut: 7372.77mm)
(total length: 8430.71mm)
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
(raspberry pi alátét 16 db)
(cmd line: -i pi_alatet_15.txt -t)
(plot cmd: -i pi_alatet_15.txt -t -p)
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

(mélység)
(belső átmérő)
(külső átmérő)
(dk: 8.8)
(h 4,4 d7.5 z1.2 c0.175 g0,0,0 np)
(h 4,4 d5 z1.2 c0.175 g0,0,0 np)
(1.sor)
(hole - helical interpolation)
(time: 0.00133333)
(helical cut)
G0 x3.975y4.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.0287078)
(hole - helical interpolation)
(time: 0.0287078)
(helical cut)
G0 x0.750y4.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x0.852y3.541 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x6.981y6.981z-0.020 i3.548 j0.859
G3 x0.852y3.541z-0.020 i-2.581 j-2.581
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.948y5.259 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x1.819y1.819z-0.020 i-3.548 j-0.859
G3 x7.948y5.259z-0.020 i2.581 j2.581
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 0.290011)
(hole - helical interpolation)
(time: 0.290011)
(helical cut)
G0 x3.975y14.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.319871)
(hole - helical interpolation)
(time: 0.319871)
(helical cut)
G0 x0.750y14.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x1.662y11.787 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.480y17.686z-0.020 i2.738 j2.413
G3 x1.662y11.787z-0.020 i-1.080 j-3.486
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x7.138y16.613 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.320y10.714z-0.020 i-2.738 j-2.413
G3 x7.138y16.613z-0.020 i1.080 j3.486
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 0.782049)
(hole - helical interpolation)
(time: 0.782049)
(helical cut)
G0 x3.975y24.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.810772)
(hole - helical interpolation)
(time: 0.810772)
(helical cut)
G0 x0.750y24.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x1.968y21.278 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x5.058y27.590z-0.020 i2.432 j2.722
G3 x1.968y21.278z-0.020 i-0.658 j-3.590
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.832y26.722 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.742y20.410z-0.020 i-2.432 j-2.722
G3 x6.832y26.722z-0.020 i0.658 j3.590
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 1.56011)
(hole - helical interpolation)
(time: 1.56011)
(helical cut)
G0 x3.975y33.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.58857)
(hole - helical interpolation)
(time: 1.58857)
(helical cut)
G0 x0.750y33.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.112y30.956 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.871y37.419z-0.020 i2.288 j2.844
G3 x2.112y30.956z-0.020 i-0.471 j-3.619
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.688y36.644 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x3.929y30.181z-0.020 i-2.288 j-2.844
G3 x6.688y36.644z-0.020 i0.471 j3.619
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 2.627)
(hole - helical interpolation)
(time: 2.627)
(helical cut)
G0 x3.975y43.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.65535)
(hole - helical interpolation)
(time: 2.65535)
(helical cut)
G0 x0.750y43.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.195y40.691 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.766y47.232z-0.020 i2.205 j2.909
G3 x2.195y40.691z-0.020 i-0.366 j-3.632
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.605y46.509 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.034y39.968z-0.020 i-2.205 j-2.909
G3 x6.605y46.509z-0.020 i0.366 j3.632
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 3.98332)
(hole - helical interpolation)
(time: 3.98332)
(helical cut)
G0 x3.975y53.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.01162)
(hole - helical interpolation)
(time: 4.01162)
(helical cut)
G0 x0.750y53.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.249y50.451 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.700y57.038z-0.020 i2.151 j2.949
G3 x2.249y50.451z-0.020 i-0.300 j-3.638
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.551y56.349 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.100y49.762z-0.020 i-2.151 j-2.949
G3 x6.551y56.349z-0.020 i0.300 j3.638
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 5.62931)
(hole - helical interpolation)
(time: 5.62931)
(helical cut)
G0 x3.975y63.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.65757)
(hole - helical interpolation)
(time: 5.65757)
(helical cut)
G0 x0.750y63.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.287y60.224 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.654y66.841z-0.020 i2.113 j2.976
G3 x2.287y60.224z-0.020 i-0.254 j-3.641
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.513y66.176 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.146y59.559z-0.020 i-2.113 j-2.976
G3 x6.513y66.176z-0.020 i0.254 j3.641
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 7.56506)
(hole - helical interpolation)
(time: 7.56506)
(helical cut)
G0 x3.975y73.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.59329)
(hole - helical interpolation)
(time: 7.59329)
(helical cut)
G0 x0.750y73.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x2.315y70.004 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.620y76.643z-0.020 i2.085 j2.996
G3 x2.315y70.004z-0.020 i-0.220 j-3.643
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x6.485y75.996 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x4.180y69.357z-0.020 i-2.085 j-2.996
G3 x6.485y75.996z-0.020 i0.220 j3.643
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 9.79063)
(2.sor)
(hole - helical interpolation)
(time: 9.79063)
(helical cut)
G0 x13.775y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 9.8621)
(hole - helical interpolation)
(time: 9.8621)
(helical cut)
G0 x10.550y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x10.686y4.985 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x17.713y4.990z-0.020 i3.514 j-0.985
G3 x10.686y4.985z-0.020 i-3.513 j-0.990
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x17.714y3.015 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x10.687y3.010z-0.020 i-3.514 j0.985
G3 x17.714y3.015z-0.020 i3.513 j0.990
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 10.2155)
(hole - helical interpolation)
(time: 10.2155)
(helical cut)
G0 x13.775y13.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 10.2465)
(hole - helical interpolation)
(time: 10.2465)
(helical cut)
G0 x10.550y13.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x10.641y12.992 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x16.818y16.344z-0.020 i3.559 j0.808
G3 x10.641y12.992z-0.020 i-2.618 j-2.544
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x17.759y14.608 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x11.582y11.256z-0.020 i-3.559 j-0.808
G3 x17.759y14.608z-0.020 i2.618 j2.544
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 10.5804)
(hole - helical interpolation)
(time: 10.5804)
(helical cut)
G0 x13.775y23.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 10.6103)
(hole - helical interpolation)
(time: 10.6103)
(helical cut)
G0 x10.550y23.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x10.964y21.911 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x16.082y26.728z-0.020 i3.236 j1.689
G3 x10.964y21.911z-0.020 i-1.882 j-3.128
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x17.436y25.289 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x12.318y20.472z-0.020 i-3.236 j-1.689
G3 x17.436y25.289z-0.020 i1.882 j3.128
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 11.1071)
(hole - helical interpolation)
(time: 11.1071)
(helical cut)
G0 x13.775y33.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 11.1364)
(hole - helical interpolation)
(time: 11.1364)
(helical cut)
G0 x10.550y33.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x11.231y31.277 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x15.628y36.759z-0.020 i2.969 j2.123
G3 x11.231y31.277z-0.020 i-1.428 j-3.359
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x17.169y35.523 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x12.772y30.041z-0.020 i-2.969 j-2.123
G3 x17.169y35.523z-0.020 i1.428 j3.359
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 11.8993)
(hole - helical interpolation)
(time: 11.8993)
(helical cut)
G0 x13.775y43.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 11.9283)
(hole - helical interpolation)
(time: 11.9283)
(helical cut)
G0 x10.550y43.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x11.421y40.834 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x15.340y46.667z-0.020 i2.779 j2.366
G3 x11.421y40.834z-0.020 i-1.140 j-3.467
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x16.979y45.566 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x13.060y39.733z-0.020 i-2.779 j-2.366
G3 x16.979y45.566z-0.020 i1.140 j3.467
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 12.9684)
(hole - helical interpolation)
(time: 12.9684)
(helical cut)
G0 x13.775y53.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 12.9972)
(hole - helical interpolation)
(time: 12.9972)
(helical cut)
G0 x10.550y53.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x11.557y50.483 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x15.145y56.526z-0.020 i2.643 j2.517
G3 x11.557y50.483z-0.020 i-0.945 j-3.526
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x16.843y55.517 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x13.255y49.474z-0.020 i-2.643 j-2.517
G3 x16.843y55.517z-0.020 i0.945 j3.526
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 14.3192)
(hole - helical interpolation)
(time: 14.3192)
(helical cut)
G0 x13.775y62.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 14.3479)
(hole - helical interpolation)
(time: 14.3479)
(helical cut)
G0 x10.550y62.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x11.658y60.180 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x15.005y66.360z-0.020 i2.542 j2.620
G3 x11.658y60.180z-0.020 i-0.805 j-3.560
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x16.742y65.420 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x13.395y59.240z-0.020 i-2.542 j-2.620
G3 x16.742y65.420z-0.020 i0.805 j3.560
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 15.9543)
(hole - helical interpolation)
(time: 15.9543)
(helical cut)
G0 x13.775y72.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 15.9829)
(hole - helical interpolation)
(time: 15.9829)
(helical cut)
G0 x10.550y72.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x11.736y69.907 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x14.901y76.182z-0.020 i2.464 j2.693
G3 x11.736y69.907z-0.020 i-0.701 j-3.582
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x16.664y75.293 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x13.499y69.018z-0.020 i-2.464 j-2.693
G3 x16.664y75.293z-0.020 i0.701 j3.582
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 17.8753)
(3.sor)
(hole - helical interpolation)
(time: 17.8753)
(helical cut)
G0 x23.575y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 17.9462)
(hole - helical interpolation)
(time: 17.9462)
(helical cut)
G0 x20.350y4.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.614y5.363 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x27.600y4.600z-0.020 i3.386 j-1.363
G3 x20.614y5.363z-0.020 i-3.600 j-0.600
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.386y2.637 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x20.400y3.400z-0.020 i-3.386 j1.363
G3 x27.386y2.637z-0.020 i3.600 j0.600
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 18.7381)
(hole - helical interpolation)
(time: 18.7381)
(helical cut)
G0 x23.575y13.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 18.7693)
(hole - helical interpolation)
(time: 18.7693)
(helical cut)
G0 x20.350y13.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.351y13.895 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x27.164y15.619z-0.020 i3.649 j-0.095
G3 x20.351y13.895z-0.020 i-3.164 j-1.819
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.649y13.705 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x20.836y11.981z-0.020 i-3.649 j0.095
G3 x27.649y13.705z-0.020 i3.164 j1.819
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 19.2051)
(hole - helical interpolation)
(time: 19.2051)
(helical cut)
G0 x23.575y23.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 19.2356)
(hole - helical interpolation)
(time: 19.2356)
(helical cut)
G0 x20.350y23.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.445y22.771 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x26.603y26.159z-0.020 i3.555 j0.829
G3 x20.445y22.771z-0.020 i-2.603 j-2.559
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.555y24.429 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x21.397y21.041z-0.020 i-3.555 j-0.829
G3 x27.555y24.429z-0.020 i2.603 j2.559
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 19.642)
(hole - helical interpolation)
(time: 19.642)
(helical cut)
G0 x23.575y33.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 19.6718)
(hole - helical interpolation)
(time: 19.6718)
(helical cut)
G0 x20.350y33.400 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.638y31.979 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x26.130y36.364z-0.020 i3.362 j1.421
G3 x20.638y31.979z-0.020 i-2.130 j-2.964
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.362y34.821 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x21.870y30.436z-0.020 i-3.362 j-1.421
G3 x27.362y34.821z-0.020 i2.130 j2.964
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 20.2326)
(hole - helical interpolation)
(time: 20.2326)
(helical cut)
G0 x23.575y43.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 20.2621)
(hole - helical interpolation)
(time: 20.2621)
(helical cut)
G0 x20.350y43.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.825y41.400 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x25.773y46.391z-0.020 i3.175 j1.800
G3 x20.825y41.400z-0.020 i-1.773 j-3.191
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.175y45.000 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x22.227y40.009z-0.020 i-3.175 j-1.800
G3 x27.175y45.000z-0.020 i1.773 j3.191
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 21.0759)
(hole - helical interpolation)
(time: 21.0759)
(helical cut)
G0 x23.575y53.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 21.1051)
(hole - helical interpolation)
(time: 21.1051)
(helical cut)
G0 x20.350y53.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x20.983y50.946 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x25.506y56.325z-0.020 i3.017 j2.054
G3 x20.983y50.946z-0.020 i-1.506 j-3.325
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x27.017y55.054 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x22.494y49.675z-0.020 i-3.017 j-2.054
G3 x27.017y55.054z-0.020 i1.506 j3.325
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 22.1851)
(hole - helical interpolation)
(time: 22.1851)
(helical cut)
G0 x23.575y62.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 22.2141)
(hole - helical interpolation)
(time: 22.2141)
(helical cut)
G0 x20.350y62.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x21.112y60.568 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x25.303y66.210z-0.020 i2.888 j2.232
G3 x21.112y60.568z-0.020 i-1.303 j-3.410
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x26.888y65.032 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x22.697y59.390z-0.020 i-2.888 j-2.232
G3 x26.888y65.032z-0.020 i1.303 j3.410
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 23.5673)
(hole - helical interpolation)
(time: 23.5673)
(helical cut)
G0 x23.575y72.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.020 i0.425
G2 z-0.020 i0.425
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 23.5961)
(hole - helical interpolation)
(time: 23.5961)
(helical cut)
G0 x20.350y72.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.010 i3.650
G2 z-0.010 i3.650
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x21.217y70.239 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x25.146y76.066z-0.020 i2.783 j2.361
G3 x21.217y70.239z-0.020 i-1.146 j-3.466
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x26.783y74.961 (travel)
m3(spindle start)
G0 z0.990 (lift down)
G1 z-0.010 (push)
G2 x22.854y69.134z-0.020 i-2.783 j-2.361
G3 x26.783y74.961z-0.020 i1.146 j3.466
G1 z-0.010 (pull)
G0 z2.000 (lift up)
(time: 25.2268)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)