(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_doboz_fedlap.txt)
(output file: uniturn_doboz_fedlap_plot.gcode)
(created on: K júl. 11 14:31:05 2023)
(total time: 00:05:18.000)
(total cut: 1088mm)
(total length: 2592.2mm)
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
(uniturn mérőállomás doboz fedlap)
(cmd line: -i uniturn_doboz_fedlap.txt -t)
(plot cmd: -i uniturn_doboz_fedlap.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d1.500 h19.000)
(set tool 2 to t2 m  d3.000 h19.000)
(set mode to YXZ)
(nagyolás)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
g0 z5.000
t2 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=3.000)
m0 (machine stop)
g0 z5.000
s50.000 (set spindle speed)
f200.000 (set feed)

(mx: 35.7)
(my: 26.3)
(ma: 12.05)
(c2=0.2)
(z2=5)
(box)
(time: 0.00133333)

(line)
(time: 0.00133333)
(linear cut)
G0 x29.900y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x29.900y46.700z-0.020
G04 P100
G1 x29.900y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.135193)

(line)
(time: 0.135193)
(linear cut)
G0 x27.800y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x27.800y37.200z-0.020
G04 P100
G1 x27.800y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.243828)
(time: 0.243828)
(hole - helical interpolation)
(time: 0.243828)
(predrill)
G0 x30.000y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 0.256321)
(box)
(time: 0.256321)

(line)
(time: 0.256321)
(linear cut)
G0 z2.000 (lift up)
G0 x41.950y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x41.950y46.700z-0.020
G04 P100
G1 x41.950y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.37867)

(line)
(time: 0.37867)
(linear cut)
G0 x39.850y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x39.850y37.200z-0.020
G04 P100
G1 x39.850y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.487305)
(time: 0.487305)
(hole - helical interpolation)
(time: 0.487305)
(predrill)
G0 x42.050y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 0.499797)
(box)
(time: 0.499797)

(line)
(time: 0.499797)
(linear cut)
G0 z2.000 (lift up)
G0 x54.000y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x54.000y46.700z-0.020
G04 P100
G1 x54.000y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.622146)

(line)
(time: 0.622146)
(linear cut)
G0 x51.900y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x51.900y37.200z-0.020
G04 P100
G1 x51.900y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.730782)
(time: 0.730782)
(hole - helical interpolation)
(time: 0.730782)
(predrill)
G0 x54.100y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 0.743274)
(box)
(time: 0.743274)

(line)
(time: 0.743274)
(linear cut)
G0 z2.000 (lift up)
G0 x66.050y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x66.050y46.700z-0.020
G04 P100
G1 x66.050y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.865623)

(line)
(time: 0.865623)
(linear cut)
G0 x63.950y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x63.950y37.200z-0.020
G04 P100
G1 x63.950y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 0.974259)
(time: 0.974259)
(hole - helical interpolation)
(time: 0.974259)
(predrill)
G0 x66.150y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 0.986751)
(box)
(time: 0.986751)

(line)
(time: 0.986751)
(linear cut)
G0 z2.000 (lift up)
G0 x78.100y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x78.100y46.700z-0.020
G04 P100
G1 x78.100y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.1091)

(line)
(time: 1.1091)
(linear cut)
G0 x76.000y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x76.000y37.200z-0.020
G04 P100
G1 x76.000y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.21774)
(time: 1.21774)
(hole - helical interpolation)
(time: 1.21774)
(predrill)
G0 x78.200y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 1.23023)
(box)
(time: 1.23023)

(line)
(time: 1.23023)
(linear cut)
G0 z2.000 (lift up)
G0 x90.150y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x90.150y46.700z-0.020
G04 P100
G1 x90.150y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.35258)

(line)
(time: 1.35258)
(linear cut)
G0 x88.050y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x88.050y37.200z-0.020
G04 P100
G1 x88.050y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.46121)
(time: 1.46121)
(hole - helical interpolation)
(time: 1.46121)
(predrill)
G0 x90.250y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 1.47371)
(box)
(time: 1.47371)

(line)
(time: 1.47371)
(linear cut)
G0 z2.000 (lift up)
G0 x102.200y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x102.200y46.700z-0.020
G04 P100
G1 x102.200y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.59605)

(line)
(time: 1.59605)
(linear cut)
G0 x100.100y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x100.100y37.200z-0.020
G04 P100
G1 x100.100y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.70469)
(time: 1.70469)
(hole - helical interpolation)
(time: 1.70469)
(predrill)
G0 x102.300y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 1.71718)
(box)
(time: 1.71718)

(line)
(time: 1.71718)
(linear cut)
G0 z2.000 (lift up)
G0 x114.250y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x114.250y46.700z-0.020
G04 P100
G1 x114.250y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.83953)

(line)
(time: 1.83953)
(linear cut)
G0 x112.150y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x112.150y37.200z-0.020
G04 P100
G1 x112.150y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 1.94817)
(time: 1.94817)
(hole - helical interpolation)
(time: 1.94817)
(predrill)
G0 x114.350y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 1.96066)
(box)
(time: 1.96066)

(line)
(time: 1.96066)
(linear cut)
G0 z2.000 (lift up)
G0 x126.300y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x126.300y46.700z-0.020
G04 P100
G1 x126.300y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.08301)

(line)
(time: 2.08301)
(linear cut)
G0 x124.200y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x124.200y37.200z-0.020
G04 P100
G1 x124.200y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.19164)
(time: 2.19164)
(hole - helical interpolation)
(time: 2.19164)
(predrill)
G0 x126.400y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 2.20414)
(box)
(time: 2.20414)

(line)
(time: 2.20414)
(linear cut)
G0 z2.000 (lift up)
G0 x138.350y37.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x138.350y46.700z-0.020
G04 P100
G1 x138.350y37.200z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.32649)

(line)
(time: 2.32649)
(linear cut)
G0 x136.250y46.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x136.250y37.200z-0.020
G04 P100
G1 x136.250y46.700z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.43512)
(time: 2.43512)
(hole - helical interpolation)
(time: 2.43512)
(predrill)
G0 x138.450y63.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 2.44761)
(hole - helical interpolation)
(time: 2.44761)
(predrill)
G0 z2.000 (lift up)
G0 x18.000y45.000 (travel)
m3(spindle start)
G98 G83 z-0.020 r1.000 q0.020
(time: 2.5316)
(simítás)
(change tool)
m5 (spindle stop)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
g0 z5.000
t1 (tool select)
m6 (tool change)
(msg, change tool to Milling, diameter=1.500)
m0 (machine stop)
g0 z5.000
f300.000 (set feed)

(mx: 35.7)
(my: 26.3)
(ma: 12.05)
(c2=0.1)
(z2=4)
(box)
(time: 2.56525)
(line)
(time: 2.56525)
(linear cut)
G0 x26.650y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x31.050y36.050z-0.020
G04 P100
G1 x26.650y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.62984)
(line)
(time: 2.62984)
(linear cut)
G0 x31.050y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x31.050y47.850z-0.020
G1 x31.050y36.050z-0.020
G0 z2.000 (lift up)
(time: 2.71708)
(line)
(time: 2.71708)
(linear cut)
G0 x31.050y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x26.650y47.850z-0.020
G04 P100
G1 x31.050y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.75974)
(line)
(time: 2.75974)
(linear cut)
G0 x26.650y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x26.650y36.050z-0.020
G1 x26.650y47.850z-0.020
G0 z2.000 (lift up)
(time: 2.84697)
(time: 2.84697)
(box)
(time: 2.84697)
(line)
(time: 2.84697)
(linear cut)
G0 x38.700y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x43.100y36.050z-0.020
G04 P100
G1 x38.700y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 2.89298)
(line)
(time: 2.89298)
(linear cut)
G0 x43.100y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x43.100y47.850z-0.020
G1 x43.100y36.050z-0.020
G0 z2.000 (lift up)
(time: 2.98021)
(line)
(time: 2.98021)
(linear cut)
G0 x43.100y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x38.700y47.850z-0.020
G04 P100
G1 x43.100y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.02287)
(line)
(time: 3.02287)
(linear cut)
G0 x38.700y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x38.700y36.050z-0.020
G1 x38.700y47.850z-0.020
G0 z2.000 (lift up)
(time: 3.11011)
(time: 3.11011)
(box)
(time: 3.11011)
(line)
(time: 3.11011)
(linear cut)
G0 x50.750y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x55.150y36.050z-0.020
G04 P100
G1 x50.750y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.15611)
(line)
(time: 3.15611)
(linear cut)
G0 x55.150y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x55.150y47.850z-0.020
G1 x55.150y36.050z-0.020
G0 z2.000 (lift up)
(time: 3.24334)
(line)
(time: 3.24334)
(linear cut)
G0 x55.150y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x50.750y47.850z-0.020
G04 P100
G1 x55.150y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.286)
(line)
(time: 3.286)
(linear cut)
G0 x50.750y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x50.750y36.050z-0.020
G1 x50.750y47.850z-0.020
G0 z2.000 (lift up)
(time: 3.37324)
(time: 3.37324)
(box)
(time: 3.37324)
(line)
(time: 3.37324)
(linear cut)
G0 x62.800y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x67.200y36.050z-0.020
G04 P100
G1 x62.800y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.41924)
(line)
(time: 3.41924)
(linear cut)
G0 x67.200y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x67.200y47.850z-0.020
G1 x67.200y36.050z-0.020
G0 z2.000 (lift up)
(time: 3.50648)
(line)
(time: 3.50648)
(linear cut)
G0 x67.200y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x62.800y47.850z-0.020
G04 P100
G1 x67.200y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.54914)
(line)
(time: 3.54914)
(linear cut)
G0 x62.800y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x62.800y36.050z-0.020
G1 x62.800y47.850z-0.020
G0 z2.000 (lift up)
(time: 3.63637)
(time: 3.63637)
(box)
(time: 3.63637)
(line)
(time: 3.63637)
(linear cut)
G0 x74.850y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x79.250y36.050z-0.020
G04 P100
G1 x74.850y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.68237)
(line)
(time: 3.68237)
(linear cut)
G0 x79.250y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x79.250y47.850z-0.020
G1 x79.250y36.050z-0.020
G0 z2.000 (lift up)
(time: 3.76961)
(line)
(time: 3.76961)
(linear cut)
G0 x79.250y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x74.850y47.850z-0.020
G04 P100
G1 x79.250y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.81227)
(line)
(time: 3.81227)
(linear cut)
G0 x74.850y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x74.850y36.050z-0.020
G1 x74.850y47.850z-0.020
G0 z2.000 (lift up)
(time: 3.8995)
(time: 3.8995)
(box)
(time: 3.8995)
(line)
(time: 3.8995)
(linear cut)
G0 x86.900y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x91.300y36.050z-0.020
G04 P100
G1 x86.900y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 3.94551)
(line)
(time: 3.94551)
(linear cut)
G0 x91.300y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x91.300y47.850z-0.020
G1 x91.300y36.050z-0.020
G0 z2.000 (lift up)
(time: 4.03274)
(line)
(time: 4.03274)
(linear cut)
G0 x91.300y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x86.900y47.850z-0.020
G04 P100
G1 x91.300y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.0754)
(line)
(time: 4.0754)
(linear cut)
G0 x86.900y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x86.900y36.050z-0.020
G1 x86.900y47.850z-0.020
G0 z2.000 (lift up)
(time: 4.16264)
(time: 4.16264)
(box)
(time: 4.16264)
(line)
(time: 4.16264)
(linear cut)
G0 x98.950y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x103.350y36.050z-0.020
G04 P100
G1 x98.950y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.20864)
(line)
(time: 4.20864)
(linear cut)
G0 x103.350y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x103.350y47.850z-0.020
G1 x103.350y36.050z-0.020
G0 z2.000 (lift up)
(time: 4.29588)
(line)
(time: 4.29588)
(linear cut)
G0 x103.350y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x98.950y47.850z-0.020
G04 P100
G1 x103.350y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.33853)
(line)
(time: 4.33853)
(linear cut)
G0 x98.950y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x98.950y36.050z-0.020
G1 x98.950y47.850z-0.020
G0 z2.000 (lift up)
(time: 4.42577)
(time: 4.42577)
(box)
(time: 4.42577)
(line)
(time: 4.42577)
(linear cut)
G0 x111.000y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x115.400y36.050z-0.020
G04 P100
G1 x111.000y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.47177)
(line)
(time: 4.47177)
(linear cut)
G0 x115.400y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x115.400y47.850z-0.020
G1 x115.400y36.050z-0.020
G0 z2.000 (lift up)
(time: 4.55901)
(line)
(time: 4.55901)
(linear cut)
G0 x115.400y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x111.000y47.850z-0.020
G04 P100
G1 x115.400y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.60167)
(line)
(time: 4.60167)
(linear cut)
G0 x111.000y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x111.000y36.050z-0.020
G1 x111.000y47.850z-0.020
G0 z2.000 (lift up)
(time: 4.6889)
(time: 4.6889)
(box)
(time: 4.6889)
(line)
(time: 4.6889)
(linear cut)
G0 x123.050y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x127.450y36.050z-0.020
G04 P100
G1 x123.050y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.73491)
(line)
(time: 4.73491)
(linear cut)
G0 x127.450y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x127.450y47.850z-0.020
G1 x127.450y36.050z-0.020
G0 z2.000 (lift up)
(time: 4.82214)
(line)
(time: 4.82214)
(linear cut)
G0 x127.450y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x123.050y47.850z-0.020
G04 P100
G1 x127.450y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.8648)
(line)
(time: 4.8648)
(linear cut)
G0 x123.050y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x123.050y36.050z-0.020
G1 x123.050y47.850z-0.020
G0 z2.000 (lift up)
(time: 4.95204)
(time: 4.95204)
(box)
(time: 4.95204)
(line)
(time: 4.95204)
(linear cut)
G0 x135.100y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x139.500y36.050z-0.020
G04 P100
G1 x135.100y36.050z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 4.99804)
(line)
(time: 4.99804)
(linear cut)
G0 x139.500y36.050 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x139.500y47.850z-0.020
G1 x139.500y36.050z-0.020
G0 z2.000 (lift up)
(time: 5.08527)
(line)
(time: 5.08527)
(linear cut)
G0 x139.500y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x135.100y47.850z-0.020
G04 P100
G1 x139.500y47.850z-0.020
G04 P100
G0 z2.000 (lift up)
(time: 5.12793)
(line)
(time: 5.12793)
(linear cut)
G0 x135.100y47.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x135.100y36.050z-0.020
G1 x135.100y47.850z-0.020
G0 z2.000 (lift up)
(time: 5.21517)
(time: 5.21517)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)