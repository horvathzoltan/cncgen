(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: kocsma_doboz_oldala.txt)
(output file: kocsma_doboz_oldala.gcode)
(created on: V júl. 16 15:39:55 2023)
(total time: 00:10:32.000)
(total cut: 7193.1mm)
(total length: 7603.88mm)
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
(kocsma doboz oldala)
(cmd line: -i kocsma_doboz_oldala.txt -t)
(plot cmd: -i kocsma_doboz_oldala.txt -t -p)
(szerszám beállítás)
(set tool 1 to t1 m  d2.000 h19.000)
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
f700.000 (set feed)

(vágás fogásmélység egy menetben)
(3.26+4.39+2+2+1.4-0.34)
(hdmi0)
(box)
(time: 0.00133333)
(line)
(time: 0.00133333)
(linear cut)
G0 x12.750y46.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x19.350y46.000z-0.100
G04 P100
G1 x12.750y46.000z-0.200
G04 P100
G1 x19.350y46.000z-0.300
G04 P100
G1 x12.750y46.000z-0.400
G04 P100
G1 x19.350y46.000z-0.500
G04 P100
G1 x12.750y46.000z-0.600
G04 P100
G1 x19.350y46.000z-0.700
G04 P100
G1 x12.750y46.000z-0.800
G04 P100
G1 x19.350y46.000z-0.900
G04 P100
G1 x12.750y46.000z-1.000
G04 P100
G1 x19.350y46.000z-1.100
G04 P100
G1 x12.750y46.000z-1.200
G04 P100
G1 x19.350y46.000z-1.300
G04 P100
G1 x12.750y46.000z-1.400
G04 P100
G1 x19.350y46.000z-1.500
G04 P100
G1 x12.750y46.000z-1.600
G04 P100
G1 x19.350y46.000z-1.700
G04 P100
G1 x12.750y46.000z-1.800
G04 P100
G1 x19.350y46.000z-1.900
G04 P100
G1 x12.750y46.000z-2.000
G04 P100
G1 x19.350y46.000z-2.100
G04 P100
G1 x12.750y46.000z-2.200
G04 P100
G1 x19.350y46.000z-2.300
G04 P100
G1 x12.750y46.000z-2.400
G04 P100
G1 x19.350y46.000z-2.500
G04 P100
G1 x12.750y46.000z-2.600
G04 P100
G1 x19.350y46.000z-2.700
G04 P100
G1 x12.750y46.000z-2.800
G04 P100
G1 x19.350y46.000z-2.900
G04 P100
G1 x12.750y46.000z-3.000
G04 P100
G1 x19.350y46.000z-3.100
G04 P100
G1 x12.750y46.000z-3.200
G04 P100
G1 x19.350y46.000z-3.300
G04 P100
G1 x12.750y46.000z-3.400
G04 P100
G1 x19.350y46.000z-3.500
G04 P100
G1 x12.750y46.000z-3.500
G04 P100
G0 z2.000 (lift up)
(time: 0.378412)
(line)
(time: 0.378412)
(linear cut)
G0 x19.350y46.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x19.350y56.800z-0.100
G1 x19.350y46.000z-0.200
G1 x19.350y56.800z-0.300
G1 x19.350y46.000z-0.400
G1 x19.350y56.800z-0.500
G1 x19.350y46.000z-0.600
G1 x19.350y56.800z-0.700
G1 x19.350y46.000z-0.800
G1 x19.350y56.800z-0.900
G1 x19.350y46.000z-1.000
G1 x19.350y56.800z-1.100
G1 x19.350y46.000z-1.200
G1 x19.350y56.800z-1.300
G1 x19.350y46.000z-1.400
G1 x19.350y56.800z-1.500
G1 x19.350y46.000z-1.600
G1 x19.350y56.800z-1.700
G1 x19.350y46.000z-1.800
G1 x19.350y56.800z-1.900
G1 x19.350y46.000z-2.000
G1 x19.350y56.800z-2.100
G1 x19.350y46.000z-2.200
G1 x19.350y56.800z-2.300
G1 x19.350y46.000z-2.400
G1 x19.350y56.800z-2.500
G1 x19.350y46.000z-2.600
G1 x19.350y56.800z-2.700
G1 x19.350y46.000z-2.800
G1 x19.350y56.800z-2.900
G1 x19.350y46.000z-3.000
G1 x19.350y56.800z-3.100
G1 x19.350y46.000z-3.200
G1 x19.350y56.800z-3.300
G1 x19.350y46.000z-3.400
G1 x19.350y56.800z-3.500
G1 x19.350y46.000z-3.500
G0 z2.000 (lift up)
(time: 0.944224)
(line)
(time: 0.944224)
(linear cut)
G0 x19.350y56.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x12.750y56.800z-0.100
G04 P100
G1 x19.350y56.800z-0.200
G04 P100
G1 x12.750y56.800z-0.300
G04 P100
G1 x19.350y56.800z-0.400
G04 P100
G1 x12.750y56.800z-0.500
G04 P100
G1 x19.350y56.800z-0.600
G04 P100
G1 x12.750y56.800z-0.700
G04 P100
G1 x19.350y56.800z-0.800
G04 P100
G1 x12.750y56.800z-0.900
G04 P100
G1 x19.350y56.800z-1.000
G04 P100
G1 x12.750y56.800z-1.100
G04 P100
G1 x19.350y56.800z-1.200
G04 P100
G1 x12.750y56.800z-1.300
G04 P100
G1 x19.350y56.800z-1.400
G04 P100
G1 x12.750y56.800z-1.500
G04 P100
G1 x19.350y56.800z-1.600
G04 P100
G1 x12.750y56.800z-1.700
G04 P100
G1 x19.350y56.800z-1.800
G04 P100
G1 x12.750y56.800z-1.900
G04 P100
G1 x19.350y56.800z-2.000
G04 P100
G1 x12.750y56.800z-2.100
G04 P100
G1 x19.350y56.800z-2.200
G04 P100
G1 x12.750y56.800z-2.300
G04 P100
G1 x19.350y56.800z-2.400
G04 P100
G1 x12.750y56.800z-2.500
G04 P100
G1 x19.350y56.800z-2.600
G04 P100
G1 x12.750y56.800z-2.700
G04 P100
G1 x19.350y56.800z-2.800
G04 P100
G1 x12.750y56.800z-2.900
G04 P100
G1 x19.350y56.800z-3.000
G04 P100
G1 x12.750y56.800z-3.100
G04 P100
G1 x19.350y56.800z-3.200
G04 P100
G1 x12.750y56.800z-3.300
G04 P100
G1 x19.350y56.800z-3.400
G04 P100
G1 x12.750y56.800z-3.500
G04 P100
G1 x19.350y56.800z-3.500
G04 P100
G0 z2.000 (lift up)
(time: 1.29677)
(line)
(time: 1.29677)
(linear cut)
G0 x12.750y56.800 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x12.750y46.000z-0.100
G1 x12.750y56.800z-0.200
G1 x12.750y46.000z-0.300
G1 x12.750y56.800z-0.400
G1 x12.750y46.000z-0.500
G1 x12.750y56.800z-0.600
G1 x12.750y46.000z-0.700
G1 x12.750y56.800z-0.800
G1 x12.750y46.000z-0.900
G1 x12.750y56.800z-1.000
G1 x12.750y46.000z-1.100
G1 x12.750y56.800z-1.200
G1 x12.750y46.000z-1.300
G1 x12.750y56.800z-1.400
G1 x12.750y46.000z-1.500
G1 x12.750y56.800z-1.600
G1 x12.750y46.000z-1.700
G1 x12.750y56.800z-1.800
G1 x12.750y46.000z-1.900
G1 x12.750y56.800z-2.000
G1 x12.750y46.000z-2.100
G1 x12.750y56.800z-2.200
G1 x12.750y46.000z-2.300
G1 x12.750y56.800z-2.400
G1 x12.750y46.000z-2.500
G1 x12.750y56.800z-2.600
G1 x12.750y46.000z-2.700
G1 x12.750y56.800z-2.800
G1 x12.750y46.000z-2.900
G1 x12.750y56.800z-3.000
G1 x12.750y46.000z-3.100
G1 x12.750y56.800z-3.200
G1 x12.750y46.000z-3.300
G1 x12.750y56.800z-3.400
G1 x12.750y46.000z-3.500
G1 x12.750y56.800z-3.500
G0 z2.000 (lift up)
(time: 1.86259)
(time: 1.86259)
(hdmi1)
(box)
(time: 1.86259)
(line)
(time: 1.86259)
(linear cut)
G0 x12.750y59.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x19.350y59.500z-0.100
G04 P100
G1 x12.750y59.500z-0.200
G04 P100
G1 x19.350y59.500z-0.300
G04 P100
G1 x12.750y59.500z-0.400
G04 P100
G1 x19.350y59.500z-0.500
G04 P100
G1 x12.750y59.500z-0.600
G04 P100
G1 x19.350y59.500z-0.700
G04 P100
G1 x12.750y59.500z-0.800
G04 P100
G1 x19.350y59.500z-0.900
G04 P100
G1 x12.750y59.500z-1.000
G04 P100
G1 x19.350y59.500z-1.100
G04 P100
G1 x12.750y59.500z-1.200
G04 P100
G1 x19.350y59.500z-1.300
G04 P100
G1 x12.750y59.500z-1.400
G04 P100
G1 x19.350y59.500z-1.500
G04 P100
G1 x12.750y59.500z-1.600
G04 P100
G1 x19.350y59.500z-1.700
G04 P100
G1 x12.750y59.500z-1.800
G04 P100
G1 x19.350y59.500z-1.900
G04 P100
G1 x12.750y59.500z-2.000
G04 P100
G1 x19.350y59.500z-2.100
G04 P100
G1 x12.750y59.500z-2.200
G04 P100
G1 x19.350y59.500z-2.300
G04 P100
G1 x12.750y59.500z-2.400
G04 P100
G1 x19.350y59.500z-2.500
G04 P100
G1 x12.750y59.500z-2.600
G04 P100
G1 x19.350y59.500z-2.700
G04 P100
G1 x12.750y59.500z-2.800
G04 P100
G1 x19.350y59.500z-2.900
G04 P100
G1 x12.750y59.500z-3.000
G04 P100
G1 x19.350y59.500z-3.100
G04 P100
G1 x12.750y59.500z-3.200
G04 P100
G1 x19.350y59.500z-3.300
G04 P100
G1 x12.750y59.500z-3.400
G04 P100
G1 x19.350y59.500z-3.500
G04 P100
G1 x12.750y59.500z-3.500
G04 P100
G0 z2.000 (lift up)
(time: 2.21005)
(line)
(time: 2.21005)
(linear cut)
G0 x19.350y59.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x19.350y70.300z-0.100
G1 x19.350y59.500z-0.200
G1 x19.350y70.300z-0.300
G1 x19.350y59.500z-0.400
G1 x19.350y70.300z-0.500
G1 x19.350y59.500z-0.600
G1 x19.350y70.300z-0.700
G1 x19.350y59.500z-0.800
G1 x19.350y70.300z-0.900
G1 x19.350y59.500z-1.000
G1 x19.350y70.300z-1.100
G1 x19.350y59.500z-1.200
G1 x19.350y70.300z-1.300
G1 x19.350y59.500z-1.400
G1 x19.350y70.300z-1.500
G1 x19.350y59.500z-1.600
G1 x19.350y70.300z-1.700
G1 x19.350y59.500z-1.800
G1 x19.350y70.300z-1.900
G1 x19.350y59.500z-2.000
G1 x19.350y70.300z-2.100
G1 x19.350y59.500z-2.200
G1 x19.350y70.300z-2.300
G1 x19.350y59.500z-2.400
G1 x19.350y70.300z-2.500
G1 x19.350y59.500z-2.600
G1 x19.350y70.300z-2.700
G1 x19.350y59.500z-2.800
G1 x19.350y70.300z-2.900
G1 x19.350y59.500z-3.000
G1 x19.350y70.300z-3.100
G1 x19.350y59.500z-3.200
G1 x19.350y70.300z-3.300
G1 x19.350y59.500z-3.400
G1 x19.350y70.300z-3.500
G1 x19.350y59.500z-3.500
G0 z2.000 (lift up)
(time: 2.77587)
(line)
(time: 2.77587)
(linear cut)
G0 x19.350y70.300 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x12.750y70.300z-0.100
G04 P100
G1 x19.350y70.300z-0.200
G04 P100
G1 x12.750y70.300z-0.300
G04 P100
G1 x19.350y70.300z-0.400
G04 P100
G1 x12.750y70.300z-0.500
G04 P100
G1 x19.350y70.300z-0.600
G04 P100
G1 x12.750y70.300z-0.700
G04 P100
G1 x19.350y70.300z-0.800
G04 P100
G1 x12.750y70.300z-0.900
G04 P100
G1 x19.350y70.300z-1.000
G04 P100
G1 x12.750y70.300z-1.100
G04 P100
G1 x19.350y70.300z-1.200
G04 P100
G1 x12.750y70.300z-1.300
G04 P100
G1 x19.350y70.300z-1.400
G04 P100
G1 x12.750y70.300z-1.500
G04 P100
G1 x19.350y70.300z-1.600
G04 P100
G1 x12.750y70.300z-1.700
G04 P100
G1 x19.350y70.300z-1.800
G04 P100
G1 x12.750y70.300z-1.900
G04 P100
G1 x19.350y70.300z-2.000
G04 P100
G1 x12.750y70.300z-2.100
G04 P100
G1 x19.350y70.300z-2.200
G04 P100
G1 x12.750y70.300z-2.300
G04 P100
G1 x19.350y70.300z-2.400
G04 P100
G1 x12.750y70.300z-2.500
G04 P100
G1 x19.350y70.300z-2.600
G04 P100
G1 x12.750y70.300z-2.700
G04 P100
G1 x19.350y70.300z-2.800
G04 P100
G1 x12.750y70.300z-2.900
G04 P100
G1 x19.350y70.300z-3.000
G04 P100
G1 x12.750y70.300z-3.100
G04 P100
G1 x19.350y70.300z-3.200
G04 P100
G1 x12.750y70.300z-3.300
G04 P100
G1 x19.350y70.300z-3.400
G04 P100
G1 x12.750y70.300z-3.500
G04 P100
G1 x19.350y70.300z-3.500
G04 P100
G0 z2.000 (lift up)
(time: 3.12842)
(line)
(time: 3.12842)
(linear cut)
G0 x12.750y70.300 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x12.750y59.500z-0.100
G1 x12.750y70.300z-0.200
G1 x12.750y59.500z-0.300
G1 x12.750y70.300z-0.400
G1 x12.750y59.500z-0.500
G1 x12.750y70.300z-0.600
G1 x12.750y59.500z-0.700
G1 x12.750y70.300z-0.800
G1 x12.750y59.500z-0.900
G1 x12.750y70.300z-1.000
G1 x12.750y59.500z-1.100
G1 x12.750y70.300z-1.200
G1 x12.750y59.500z-1.300
G1 x12.750y70.300z-1.400
G1 x12.750y59.500z-1.500
G1 x12.750y70.300z-1.600
G1 x12.750y59.500z-1.700
G1 x12.750y70.300z-1.800
G1 x12.750y59.500z-1.900
G1 x12.750y70.300z-2.000
G1 x12.750y59.500z-2.100
G1 x12.750y70.300z-2.200
G1 x12.750y59.500z-2.300
G1 x12.750y70.300z-2.400
G1 x12.750y59.500z-2.500
G1 x12.750y70.300z-2.600
G1 x12.750y59.500z-2.700
G1 x12.750y70.300z-2.800
G1 x12.750y59.500z-2.900
G1 x12.750y70.300z-3.000
G1 x12.750y59.500z-3.100
G1 x12.750y70.300z-3.200
G1 x12.750y59.500z-3.300
G1 x12.750y70.300z-3.400
G1 x12.750y59.500z-3.500
G1 x12.750y70.300z-3.500
G0 z2.000 (lift up)
(time: 3.69423)
(time: 3.69423)
(12.71+6.6+6)
(ethernet)
(box)
(time: 3.69423)
(line)
(time: 3.69423)
(linear cut)
G0 x25.500y46.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x38.550y46.000z-0.100
G1 x25.500y46.000z-0.200
G1 x38.550y46.000z-0.300
G1 x25.500y46.000z-0.400
G1 x38.550y46.000z-0.500
G1 x25.500y46.000z-0.600
G1 x38.550y46.000z-0.700
G1 x25.500y46.000z-0.800
G1 x38.550y46.000z-0.900
G1 x25.500y46.000z-1.000
G1 x38.550y46.000z-1.100
G1 x25.500y46.000z-1.200
G1 x38.550y46.000z-1.300
G1 x25.500y46.000z-1.400
G1 x38.550y46.000z-1.500
G1 x25.500y46.000z-1.600
G1 x38.550y46.000z-1.700
G1 x25.500y46.000z-1.800
G1 x38.550y46.000z-1.900
G1 x25.500y46.000z-2.000
G1 x38.550y46.000z-2.100
G1 x25.500y46.000z-2.200
G1 x38.550y46.000z-2.300
G1 x25.500y46.000z-2.400
G1 x38.550y46.000z-2.500
G1 x25.500y46.000z-2.600
G1 x38.550y46.000z-2.700
G1 x25.500y46.000z-2.800
G1 x38.550y46.000z-2.900
G1 x25.500y46.000z-3.000
G1 x38.550y46.000z-3.100
G1 x25.500y46.000z-3.200
G1 x38.550y46.000z-3.300
G1 x25.500y46.000z-3.400
G1 x38.550y46.000z-3.500
G1 x25.500y46.000z-3.500
G0 z2.000 (lift up)
(time: 4.38949)
(line)
(time: 4.38949)
(linear cut)
G0 x38.550y46.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x38.550y61.700z-0.100
G1 x38.550y46.000z-0.200
G1 x38.550y61.700z-0.300
G1 x38.550y46.000z-0.400
G1 x38.550y61.700z-0.500
G1 x38.550y46.000z-0.600
G1 x38.550y61.700z-0.700
G1 x38.550y46.000z-0.800
G1 x38.550y61.700z-0.900
G1 x38.550y46.000z-1.000
G1 x38.550y61.700z-1.100
G1 x38.550y46.000z-1.200
G1 x38.550y61.700z-1.300
G1 x38.550y46.000z-1.400
G1 x38.550y61.700z-1.500
G1 x38.550y46.000z-1.600
G1 x38.550y61.700z-1.700
G1 x38.550y46.000z-1.800
G1 x38.550y61.700z-1.900
G1 x38.550y46.000z-2.000
G1 x38.550y61.700z-2.100
G1 x38.550y46.000z-2.200
G1 x38.550y61.700z-2.300
G1 x38.550y46.000z-2.400
G1 x38.550y61.700z-2.500
G1 x38.550y46.000z-2.600
G1 x38.550y61.700z-2.700
G1 x38.550y46.000z-2.800
G1 x38.550y61.700z-2.900
G1 x38.550y46.000z-3.000
G1 x38.550y61.700z-3.100
G1 x38.550y46.000z-3.200
G1 x38.550y61.700z-3.300
G1 x38.550y46.000z-3.400
G1 x38.550y61.700z-3.500
G1 x38.550y46.000z-3.500
G0 z2.000 (lift up)
(time: 5.2115)
(line)
(time: 5.2115)
(linear cut)
G0 x38.550y61.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x25.500y61.700z-0.100
G1 x38.550y61.700z-0.200
G1 x25.500y61.700z-0.300
G1 x38.550y61.700z-0.400
G1 x25.500y61.700z-0.500
G1 x38.550y61.700z-0.600
G1 x25.500y61.700z-0.700
G1 x38.550y61.700z-0.800
G1 x25.500y61.700z-0.900
G1 x38.550y61.700z-1.000
G1 x25.500y61.700z-1.100
G1 x38.550y61.700z-1.200
G1 x25.500y61.700z-1.300
G1 x38.550y61.700z-1.400
G1 x25.500y61.700z-1.500
G1 x38.550y61.700z-1.600
G1 x25.500y61.700z-1.700
G1 x38.550y61.700z-1.800
G1 x25.500y61.700z-1.900
G1 x38.550y61.700z-2.000
G1 x25.500y61.700z-2.100
G1 x38.550y61.700z-2.200
G1 x25.500y61.700z-2.300
G1 x38.550y61.700z-2.400
G1 x25.500y61.700z-2.500
G1 x38.550y61.700z-2.600
G1 x25.500y61.700z-2.700
G1 x38.550y61.700z-2.800
G1 x25.500y61.700z-2.900
G1 x38.550y61.700z-3.000
G1 x25.500y61.700z-3.100
G1 x38.550y61.700z-3.200
G1 x25.500y61.700z-3.300
G1 x38.550y61.700z-3.400
G1 x25.500y61.700z-3.500
G1 x38.550y61.700z-3.500
G0 z2.000 (lift up)
(time: 5.89898)
(line)
(time: 5.89898)
(linear cut)
G0 x25.500y61.700 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x25.500y46.000z-0.100
G1 x25.500y61.700z-0.200
G1 x25.500y46.000z-0.300
G1 x25.500y61.700z-0.400
G1 x25.500y46.000z-0.500
G1 x25.500y61.700z-0.600
G1 x25.500y46.000z-0.700
G1 x25.500y61.700z-0.800
G1 x25.500y46.000z-0.900
G1 x25.500y61.700z-1.000
G1 x25.500y46.000z-1.100
G1 x25.500y61.700z-1.200
G1 x25.500y46.000z-1.300
G1 x25.500y61.700z-1.400
G1 x25.500y46.000z-1.500
G1 x25.500y61.700z-1.600
G1 x25.500y46.000z-1.700
G1 x25.500y61.700z-1.800
G1 x25.500y46.000z-1.900
G1 x25.500y61.700z-2.000
G1 x25.500y46.000z-2.100
G1 x25.500y61.700z-2.200
G1 x25.500y46.000z-2.300
G1 x25.500y61.700z-2.400
G1 x25.500y46.000z-2.500
G1 x25.500y61.700z-2.600
G1 x25.500y46.000z-2.700
G1 x25.500y61.700z-2.800
G1 x25.500y46.000z-2.900
G1 x25.500y61.700z-3.000
G1 x25.500y46.000z-3.100
G1 x25.500y61.700z-3.200
G1 x25.500y46.000z-3.300
G1 x25.500y61.700z-3.400
G1 x25.500y46.000z-3.500
G1 x25.500y61.700z-3.500
G0 z2.000 (lift up)
(time: 6.72099)
(time: 6.72099)
(hole - helical interpolation)
(time: 6.72099)
(helical cut)
G0 x29.950y40.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.050 i0.550
G2 z-0.100 i0.550
G2 z-0.150 i0.550
G2 z-0.200 i0.550
G2 z-0.250 i0.550
G2 z-0.300 i0.550
G2 z-0.350 i0.550
G2 z-0.400 i0.550
G2 z-0.450 i0.550
G2 z-0.500 i0.550
G2 z-0.550 i0.550
G2 z-0.600 i0.550
G2 z-0.650 i0.550
G2 z-0.700 i0.550
G2 z-0.750 i0.550
G2 z-0.800 i0.550
G2 z-0.850 i0.550
G2 z-0.900 i0.550
G2 z-0.950 i0.550
G2 z-1.000 i0.550
G2 z-1.050 i0.550
G2 z-1.100 i0.550
G2 z-1.150 i0.550
G2 z-1.200 i0.550
G2 z-1.250 i0.550
G2 z-1.300 i0.550
G2 z-1.350 i0.550
G2 z-1.400 i0.550
G2 z-1.450 i0.550
G2 z-1.500 i0.550
G2 z-1.550 i0.550
G2 z-1.600 i0.550
G2 z-1.650 i0.550
G2 z-1.700 i0.550
G2 z-1.750 i0.550
G2 z-1.800 i0.550
G2 z-1.850 i0.550
G2 z-1.900 i0.550
G2 z-1.950 i0.550
G2 z-2.000 i0.550
G2 z-2.050 i0.550
G2 z-2.100 i0.550
G2 z-2.150 i0.550
G2 z-2.200 i0.550
G2 z-2.250 i0.550
G2 z-2.300 i0.550
G2 z-2.350 i0.550
G2 z-2.400 i0.550
G2 z-2.450 i0.550
G2 z-2.500 i0.550
G2 z-2.550 i0.550
G2 z-2.600 i0.550
G2 z-2.650 i0.550
G2 z-2.700 i0.550
G2 z-2.750 i0.550
G2 z-2.800 i0.550
G2 z-2.850 i0.550
G2 z-2.900 i0.550
G2 z-2.950 i0.550
G2 z-3.000 i0.550
G2 z-3.050 i0.550
G2 z-3.100 i0.550
G2 z-3.150 i0.550
G2 z-3.200 i0.550
G2 z-3.250 i0.550
G2 z-3.300 i0.550
G2 z-3.350 i0.550
G2 z-3.400 i0.550
G2 z-3.450 i0.550
G2 z-3.500 i0.550
G2 z-3.500 i0.550
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.09446)
(hole - helical interpolation)
(time: 7.09446)
(helical cut)
G0 x29.950y67.200 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.050 i0.550
G2 z-0.100 i0.550
G2 z-0.150 i0.550
G2 z-0.200 i0.550
G2 z-0.250 i0.550
G2 z-0.300 i0.550
G2 z-0.350 i0.550
G2 z-0.400 i0.550
G2 z-0.450 i0.550
G2 z-0.500 i0.550
G2 z-0.550 i0.550
G2 z-0.600 i0.550
G2 z-0.650 i0.550
G2 z-0.700 i0.550
G2 z-0.750 i0.550
G2 z-0.800 i0.550
G2 z-0.850 i0.550
G2 z-0.900 i0.550
G2 z-0.950 i0.550
G2 z-1.000 i0.550
G2 z-1.050 i0.550
G2 z-1.100 i0.550
G2 z-1.150 i0.550
G2 z-1.200 i0.550
G2 z-1.250 i0.550
G2 z-1.300 i0.550
G2 z-1.350 i0.550
G2 z-1.400 i0.550
G2 z-1.450 i0.550
G2 z-1.500 i0.550
G2 z-1.550 i0.550
G2 z-1.600 i0.550
G2 z-1.650 i0.550
G2 z-1.700 i0.550
G2 z-1.750 i0.550
G2 z-1.800 i0.550
G2 z-1.850 i0.550
G2 z-1.900 i0.550
G2 z-1.950 i0.550
G2 z-2.000 i0.550
G2 z-2.050 i0.550
G2 z-2.100 i0.550
G2 z-2.150 i0.550
G2 z-2.200 i0.550
G2 z-2.250 i0.550
G2 z-2.300 i0.550
G2 z-2.350 i0.550
G2 z-2.400 i0.550
G2 z-2.450 i0.550
G2 z-2.500 i0.550
G2 z-2.550 i0.550
G2 z-2.600 i0.550
G2 z-2.650 i0.550
G2 z-2.700 i0.550
G2 z-2.750 i0.550
G2 z-2.800 i0.550
G2 z-2.850 i0.550
G2 z-2.900 i0.550
G2 z-2.950 i0.550
G2 z-3.000 i0.550
G2 z-3.050 i0.550
G2 z-3.100 i0.550
G2 z-3.150 i0.550
G2 z-3.200 i0.550
G2 z-3.250 i0.550
G2 z-3.300 i0.550
G2 z-3.350 i0.550
G2 z-3.400 i0.550
G2 z-3.450 i0.550
G2 z-3.500 i0.550
G2 z-3.500 i0.550
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.47129)
(táp)
(hole - helical interpolation)
(time: 7.47129)
(helical cut)
G0 x15.450y26.600 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.050 i4.550
G2 z-0.100 i4.550
G2 z-0.150 i4.550
G2 z-0.200 i4.550
G2 z-0.250 i4.550
G2 z-0.300 i4.550
G2 z-0.350 i4.550
G2 z-0.400 i4.550
G2 z-0.450 i4.550
G2 z-0.500 i4.550
G2 z-0.550 i4.550
G2 z-0.600 i4.550
G2 z-0.650 i4.550
G2 z-0.700 i4.550
G2 z-0.750 i4.550
G2 z-0.800 i4.550
G2 z-0.850 i4.550
G2 z-0.900 i4.550
G2 z-0.950 i4.550
G2 z-1.000 i4.550
G2 z-1.050 i4.550
G2 z-1.100 i4.550
G2 z-1.150 i4.550
G2 z-1.200 i4.550
G2 z-1.250 i4.550
G2 z-1.300 i4.550
G2 z-1.350 i4.550
G2 z-1.400 i4.550
G2 z-1.450 i4.550
G2 z-1.500 i4.550
G2 z-1.550 i4.550
G2 z-1.600 i4.550
G2 z-1.650 i4.550
G2 z-1.700 i4.550
G2 z-1.750 i4.550
G2 z-1.800 i4.550
G2 z-1.850 i4.550
G2 z-1.900 i4.550
G2 z-1.950 i4.550
G2 z-2.000 i4.550
G2 z-2.050 i4.550
G2 z-2.100 i4.550
G2 z-2.150 i4.550
G2 z-2.200 i4.550
G2 z-2.250 i4.550
G2 z-2.300 i4.550
G2 z-2.350 i4.550
G2 z-2.400 i4.550
G2 z-2.450 i4.550
G2 z-2.500 i4.550
G2 z-2.550 i4.550
G2 z-2.600 i4.550
G2 z-2.650 i4.550
G2 z-2.700 i4.550
G2 z-2.750 i4.550
G2 z-2.800 i4.550
G2 z-2.850 i4.550
G2 z-2.900 i4.550
G2 z-2.950 i4.550
G2 z-3.000 i4.550
G2 z-3.000 i4.550
G1 z0.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x15.769y24.927 (travel)
m3(spindle start)
G0 z-2.000 (lift down)
G1 z-3.000 (push)
G2 x22.734y30.237z-3.050 i4.231 j1.673
G3 x15.769y24.927z-3.100 i-2.734 j-3.637
G2 x22.734y30.237z-3.150 i4.231 j1.673
G3 x15.769y24.927z-3.200 i-2.734 j-3.637
G2 x22.734y30.237z-3.250 i4.231 j1.673
G3 x15.769y24.927z-3.300 i-2.734 j-3.637
G2 x22.734y30.237z-3.350 i4.231 j1.673
G3 x15.769y24.927z-3.400 i-2.734 j-3.637
G2 x22.734y30.237z-3.450 i4.231 j1.673
G3 x15.769y24.927z-3.500 i-2.734 j-3.637
G2 x22.734y30.237z-3.500 i4.231 j1.673
G1 z-3.000 (pull)
G0 z2.000 (lift up)
(circular_arc cut)
G0 x24.231y28.273 (travel)
m3(spindle start)
G0 z-2.000 (lift down)
G1 z-3.000 (push)
G2 x17.266y22.963z-3.050 i-4.231 j-1.673
G3 x24.231y28.273z-3.100 i2.734 j3.637
G2 x17.266y22.963z-3.150 i-4.231 j-1.673
G3 x24.231y28.273z-3.200 i2.734 j3.637
G2 x17.266y22.963z-3.250 i-4.231 j-1.673
G3 x24.231y28.273z-3.300 i2.734 j3.637
G2 x17.266y22.963z-3.350 i-4.231 j-1.673
G3 x24.231y28.273z-3.400 i2.734 j3.637
G2 x17.266y22.963z-3.450 i-4.231 j-1.673
G3 x24.231y28.273z-3.500 i2.734 j3.637
G2 x17.266y22.963z-3.500 i-4.231 j-1.673
G1 z-3.000 (pull)
G0 z2.000 (lift up)
(time: 10.5292)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
