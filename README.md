# Manas_task_3
arduino coding

ref material: https://www.tinkercad.com/embed/exKE2556vpj?editbtn=1

circuit ref: refer the "ultrasonic.png" file

code: 
* Ultrasonic sensor gives duration in microseconds via pulseIn() set to detect when HIGH.
* Distace=(duration/2)*speed of sound in air in cm/microsecond.
* Six leds, each glows when distance is within their range determined by the distance variable.
* 0-n/6, n/6-2n/6........5n/6-n. (where n is Max_dist=400)
