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

send "3\n2 4\n10 5\n3 12\n7 7 7\n3 8\n4 2 1\n"
expect "Case #1: 1" {foreground green; puts "CASE #1 PASSED";reset} default {foreground red;puts "CASE #1 FAILED";reset}
expect "Case #2: 3" {foreground green; puts "CASE #2 PASSED";reset} default {foreground red;puts "CASE #2 FAILED";reset}
expect "Case #3: 1" {foreground green; puts "CASE #3 PASSED";reset} default {foreground red;puts "CASE #3 FAILED";reset}
