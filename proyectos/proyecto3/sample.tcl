#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]
#Put your test case here

send "3\n2 3 5 2 15\n3 2 3 5 10\n4 6 6 2 18\n"
expect "5 7 0 1" {foreground green; puts "CASE #1 PASSED";reset} default {foreground red;puts "CASE #1 FAILED";reset}
expect "6 5 0 3" {foreground green; puts "CASE #2 PASSED";reset} default {foreground red;puts "CASE #2 FAILED";reset}
expect "7 12 0 1" {foreground green; puts "CASE #3 PASSED";reset} default {foreground red;puts "CASE #3 FAILED";reset}
