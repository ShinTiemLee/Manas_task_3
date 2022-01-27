# Manas_task_3
arduino coding

ref:https://www.tinkercad.com/embed/exKE2556vpj?editbtn=1

circuit: refer file "ultrasonic.png"

code:
* Ultrasonic sensor gives duration in microseconds(us) via pulseIn().
* disance=(duration/2)*speed of sound in air in cm/us.
* Six leds, each glow when the distance value is within their intervals respectively.
* 0-n/6,n/6-2n/6.....5n/6-n.  (Here n is Max_dist=400)
