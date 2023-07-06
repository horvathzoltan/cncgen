(GCode generated by cncgen - https://github.com/horvathzoltan/cncgen)
(type: GCode from geometry)
(input file: uniturn_relay_relays.txt)
(output file: uniturn_relay_relays.gcode)
(created on: Cs febr. 16 16:28:22 2023)
(total time: 00:50:04.000)
(total cut: 9613.29mm)
(total length: 12332.3mm)
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
(uniturn mérőállomás relé 3x4 szerelőlap)
(2mm polikarbonát lemez)
(xy0 a ja saroknál)
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
f200.000 (set feed)

(csavar a szélétől)
(relé panel w,h)
(teljes lap w,h)
(w: 236.14999999999995)
(h: 65.1)
(relé furatok)
(box)
(time: 0.00133333)
(hole - helical interpolation)
(time: 0.00133333)
(predrill)
G0 x10.000y10.000 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x9.200y10.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.347236)
(hole - helical interpolation)
(time: 0.347236)
(predrill)
G0 x55.100y10.000 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x54.300y10.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 0.714246)
(hole - helical interpolation)
(time: 0.714246)
(predrill)
G0 x55.100y75.850 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x54.300y75.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.09455)
(hole - helical interpolation)
(time: 1.09455)
(predrill)
G0 x10.000y75.850 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x9.200y75.850 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.4605)
(time: 1.4605)
(box)
(time: 1.4605)
(hole - helical interpolation)
(time: 1.4605)
(predrill)
G0 x10.000y82.250 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x9.200y82.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 1.80138)
(hole - helical interpolation)
(time: 1.80138)
(predrill)
G0 x55.100y82.250 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x54.300y82.250 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.16839)
(hole - helical interpolation)
(time: 2.16839)
(predrill)
G0 x55.100y148.100 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x54.300y148.100 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.54869)
(hole - helical interpolation)
(time: 2.54869)
(predrill)
G0 x10.000y148.100 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x9.200y148.100 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 2.91464)
(time: 2.91464)
(box)
(time: 2.91464)
(hole - helical interpolation)
(time: 2.91464)
(predrill)
G0 x10.000y154.500 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x9.200y154.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.25552)
(hole - helical interpolation)
(time: 3.25552)
(predrill)
G0 x55.100y154.500 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x54.300y154.500 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 3.62253)
(hole - helical interpolation)
(time: 3.62253)
(predrill)
G0 x55.100y220.350 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x54.300y220.350 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.00283)
(hole - helical interpolation)
(time: 4.00283)
(predrill)
G0 x10.000y220.350 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x9.200y220.350 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.36878)
(time: 4.36878)
(rögzítő furatok)
(hole - helical interpolation)
(time: 4.36878)
(predrill)
G0 x5.000y46.125 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x4.200y46.125 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 4.82135)
(hole - helical interpolation)
(time: 4.82135)
(predrill)
G0 x60.100y46.125 (travel)
m3(spindle start)
G98 G83 z-2.200 r1.000 q0.200
(helical cut)
G0 z2.000 (lift up)
G0 x59.300y46.125 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.800
G2 z-0.400 i0.800
G2 z-0.600 i0.800
G2 z-0.800 i0.800
G2 z-1.000 i0.800
G2 z-1.200 i0.800
G2 z-1.400 i0.800
G2 z-1.600 i0.800
G2 z-1.800 i0.800
G2 z-2.000 i0.800
G2 z-2.200 i0.800
G2 z-2.200 i0.800
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.19502)
(hole - helical interpolation)
(time: 5.19502)
(helical cut)
G0 x4.250y118.375 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.55657)
(hole - helical interpolation)
(time: 5.55657)
(helical cut)
G0 x59.350y118.375 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 5.8943)
(hole - helical interpolation)
(time: 5.8943)
(helical cut)
G0 x4.250y190.625 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 6.25587)
(hole - helical interpolation)
(time: 6.25587)
(helical cut)
G0 x59.350y190.625 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 6.5936)
(hole - helical interpolation)
(time: 6.5936)
(helical cut)
G0 x4.250y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.02367)
(hole - helical interpolation)
(time: 7.02367)
(helical cut)
G0 x59.350y5.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.36141)
(hole - helical interpolation)
(time: 7.36141)
(helical cut)
G0 x4.250y231.150 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 7.81757)
(hole - helical interpolation)
(time: 7.81757)
(helical cut)
G0 x59.350y231.150 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G2 z-0.200 i0.750
G2 z-0.400 i0.750
G2 z-0.600 i0.750
G2 z-0.800 i0.750
G2 z-1.000 i0.750
G2 z-1.200 i0.750
G2 z-1.400 i0.750
G2 z-1.600 i0.750
G2 z-1.800 i0.750
G2 z-2.000 i0.750
G2 z-2.200 i0.750
G2 z-2.200 i0.750
G1 z0.000 (pull)
G0 z2.000 (lift up)
(time: 8.1553)
(körvonal)
(box)
(time: 8.1553)
(line)
(time: 8.1553)
(linear cut)
G0 x0.000y-0.750 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x65.100y-0.750z-0.200
G1 x0.000y-0.750z-0.400
G1 x65.100y-0.750z-0.600
G1 x0.000y-0.750z-0.800
G1 x65.100y-0.750z-1.000
G1 x0.000y-0.750z-1.200
G1 x65.100y-0.750z-1.400
G1 x0.000y-0.750z-1.500
G1 x65.100y-0.750z-1.500
G0 z2.000 (lift up)
(time: 11.2524)
(line)
(time: 11.2524)
(linear cut)
G0 x0.000y-0.750 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x14.525y-0.750z-1.700
G1 x0.000y-0.750z-1.900
G1 x14.525y-0.750z-2.100
G1 x0.000y-0.750z-2.200
G1 x14.525y-0.750z-2.200
G0 z2.000 (lift up)
(time: 11.6685)
(line)
(time: 11.6685)
(linear cut)
G0 x18.025y-0.750 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x30.800y-0.750z-1.700
G1 x18.025y-0.750z-1.900
G1 x30.800y-0.750z-2.100
G1 x18.025y-0.750z-2.200
G1 x30.800y-0.750z-2.200
G0 z2.000 (lift up)
(time: 12.0006)
(line)
(time: 12.0006)
(linear cut)
G0 x34.300y-0.750 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x47.075y-0.750z-1.700
G1 x34.300y-0.750z-1.900
G1 x47.075y-0.750z-2.100
G1 x34.300y-0.750z-2.200
G1 x47.075y-0.750z-2.200
G0 z2.000 (lift up)
(time: 12.3328)
(line)
(time: 12.3328)
(linear cut)
G0 x50.575y-0.750 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x65.100y-0.750z-1.700
G1 x50.575y-0.750z-1.900
G1 x65.100y-0.750z-2.100
G1 x50.575y-0.750z-2.200
G1 x65.100y-0.750z-2.200
G0 z2.000 (lift up)
(time: 12.7087)
(line)
(time: 12.7087)
(linear cut)
G0 x65.850y0.000 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x65.850y236.150z-0.200
G1 x65.850y0.000z-0.400
G1 x65.850y236.150z-0.600
G1 x65.850y0.000z-0.800
G1 x65.850y236.150z-1.000
G1 x65.850y0.000z-1.200
G1 x65.850y236.150z-1.400
G1 x65.850y0.000z-1.500
G1 x65.850y236.150z-1.500
G0 z2.000 (lift up)
(time: 23.345)
(line)
(time: 23.345)
(linear cut)
G0 x65.850y0.000 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x65.850y57.287z-1.700
G1 x65.850y0.000z-1.900
G1 x65.850y57.287z-2.100
G1 x65.850y0.000z-2.200
G1 x65.850y57.287z-2.200
G0 z2.000 (lift up)
(time: 24.9441)
(line)
(time: 24.9441)
(linear cut)
G0 x65.850y60.787 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x65.850y116.325z-1.700
G1 x65.850y60.787z-1.900
G1 x65.850y116.325z-2.100
G1 x65.850y60.787z-2.200
G1 x65.850y116.325z-2.200
G0 z2.000 (lift up)
(time: 26.3453)
(line)
(time: 26.3453)
(linear cut)
G0 x65.850y119.825 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x65.850y175.362z-1.700
G1 x65.850y119.825z-1.900
G1 x65.850y175.362z-2.100
G1 x65.850y119.825z-2.200
G1 x65.850y175.362z-2.200
G0 z2.000 (lift up)
(time: 27.7465)
(line)
(time: 27.7465)
(linear cut)
G0 x65.850y178.862 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x65.850y236.150z-1.700
G1 x65.850y178.862z-1.900
G1 x65.850y236.150z-2.100
G1 x65.850y178.862z-2.200
G1 x65.850y236.150z-2.200
G0 z2.000 (lift up)
(time: 29.1915)
(line)
(time: 29.1915)
(linear cut)
G0 x65.100y236.900 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x0.000y236.900z-0.200
G1 x65.100y236.900z-0.400
G1 x0.000y236.900z-0.600
G1 x65.100y236.900z-0.800
G1 x0.000y236.900z-1.000
G1 x65.100y236.900z-1.200
G1 x0.000y236.900z-1.400
G1 x65.100y236.900z-1.500
G1 x0.000y236.900z-1.500
G0 z2.000 (lift up)
(time: 32.1305)
(line)
(time: 32.1305)
(linear cut)
G0 x65.100y236.900 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x50.575y236.900z-1.700
G1 x65.100y236.900z-1.900
G1 x50.575y236.900z-2.100
G1 x65.100y236.900z-2.200
G1 x50.575y236.900z-2.200
G0 z2.000 (lift up)
(time: 32.5466)
(line)
(time: 32.5466)
(linear cut)
G0 x47.075y236.900 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x34.300y236.900z-1.700
G1 x47.075y236.900z-1.900
G1 x34.300y236.900z-2.100
G1 x47.075y236.900z-2.200
G1 x34.300y236.900z-2.200
G0 z2.000 (lift up)
(time: 32.8787)
(line)
(time: 32.8787)
(linear cut)
G0 x30.800y236.900 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x18.025y236.900z-1.700
G1 x30.800y236.900z-1.900
G1 x18.025y236.900z-2.100
G1 x30.800y236.900z-2.200
G1 x18.025y236.900z-2.200
G0 z2.000 (lift up)
(time: 33.2109)
(line)
(time: 33.2109)
(linear cut)
G0 x14.525y236.900 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x0.000y236.900z-1.700
G1 x14.525y236.900z-1.900
G1 x0.000y236.900z-2.100
G1 x14.525y236.900z-2.200
G1 x0.000y236.900z-2.200
G0 z2.000 (lift up)
(time: 33.5868)
(line)
(time: 33.5868)
(linear cut)
G0 x-0.750y236.150 (travel)
m3(spindle start)
G0 z1.000 (lift down)
G1 z0.000 (push)
G1 x-0.750y0.000z-0.200
G1 x-0.750y236.150z-0.400
G1 x-0.750y0.000z-0.600
G1 x-0.750y236.150z-0.800
G1 x-0.750y0.000z-1.000
G1 x-0.750y236.150z-1.200
G1 x-0.750y0.000z-1.400
G1 x-0.750y236.150z-1.500
G1 x-0.750y0.000z-1.500
G0 z2.000 (lift up)
(time: 44.2231)
(line)
(time: 44.2231)
(linear cut)
G0 x-0.750y236.150 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-0.750y178.862z-1.700
G1 x-0.750y236.150z-1.900
G1 x-0.750y178.862z-2.100
G1 x-0.750y236.150z-2.200
G1 x-0.750y178.862z-2.200
G0 z2.000 (lift up)
(time: 45.8222)
(line)
(time: 45.8222)
(linear cut)
G0 x-0.750y175.362 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-0.750y119.825z-1.700
G1 x-0.750y175.362z-1.900
G1 x-0.750y119.825z-2.100
G1 x-0.750y175.362z-2.200
G1 x-0.750y119.825z-2.200
G0 z2.000 (lift up)
(time: 47.2234)
(line)
(time: 47.2234)
(linear cut)
G0 x-0.750y116.325 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-0.750y60.787z-1.700
G1 x-0.750y116.325z-1.900
G1 x-0.750y60.787z-2.100
G1 x-0.750y116.325z-2.200
G1 x-0.750y60.787z-2.200
G0 z2.000 (lift up)
(time: 48.6246)
(line)
(time: 48.6246)
(linear cut)
G0 x-0.750y57.288 (travel)
m3(spindle start)
G0 z-0.500 (lift down)
G1 z-1.500 (push)
G1 x-0.750y0.000z-1.700
G1 x-0.750y57.288z-1.900
G1 x-0.750y0.000z-2.100
G1 x-0.750y57.288z-2.200
G1 x-0.750y0.000z-2.200
G0 z2.000 (lift up)
(time: 50.0696)
(time: 50.0696)
G0 z2.000 (lift up)
G0 x0.000y0.000 (travel)
(travel to safe place)

M05 (Spindle stop)
(G00 Z15.0000) (lift up)
(G00 X0.0000 Y0.0000) (travel to home XY)
M30
(end)
