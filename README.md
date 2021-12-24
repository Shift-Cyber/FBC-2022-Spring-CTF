# FBC-2022-Spring-CTF
Capture The Flag (CTF) competition prepared for Fallbrook Cyber, Spring 2022

![SCYCA Logo](.rsrc/Logo-Full-black-JPG.jpg)

## Welcome!!
This CTF is compromised of 30 challenges, with 6 problems per each of the 5 sections. For the newer players out there this is referring to the standard 5 CTF sections: web exploitation (webex), binary exploitation (binex), forensics, networking, and cryptography (crypto). The problems increase in difficulty as you progress through the point ratings with harder or more intricate problems awarding more points. Each problem has a series of hints that will get you 90% of the way to the answer if you choose to use them. The competition organizers have decided to leave these hints free for your use as the root purpose is of course to teach the skills and techniques to you. Each challenge will still, however, require a fair bit of effort from the participant to solve.

Competition opens at 1500, at the start of the first practice of the year, 7 January 2022 and runs until the start of our last practice of the season on 20 May 2022. The goal is for you as the participant to take as much as possible away from this, aside from just the cool prizes ;)

## Prize Pool
These prizes are set for each position, however, prizes are actually picked in the order of the winner. For example, if the first place winner wants to take the second place prize and give up the first place prize to the would be winner, that is perfectly acceptable.

**1st Place** - Nintendo Switch<br>
**2nd Place** - Raspberry Pi 4B<br>
**3rd Place** - Arduino w/BB Kit<br>

**Tie breaks:** If there is a tie for a position on the scoreboard based on total points the tie will be broken by who achieved that amount of points first.
<br>

# Challenges
| Pts | [Web Exploitation](#web-exploitation-webex) | [Binary Exploitation](#binary-exploitation-binex) | [Cryptography](#cryptography-crypto) | [Networking](#networking) | [Forensics](#forensics) |
|:----:|:----------------:|:------------------:|:--------------:|:----------------:|:----------------:|
|  10  | Inspector Gadget | Execution          | Titanic        | Challenge | Challenge |
|  25  | The Middleman    | Telegram           | Cleopatra      | Challenge | Challenge |
|  50  | Get Out          | Fast and Furious   | Da Vinci Code  | Challenge | Challenge |
|  50  | Mr. Robot        | Stacked            | Imitation Game | Challenge | Challenge |
|  50  | Cookie Monster   | Ready, Aim, Fire   | Codebreaker    | Challenge | Challenge |
|  90  | The Postman      | Return of the King | Enigma         | Challenge | Challenge |

<br>

## Getting Started
### WELCOME [1pt] For the Flag
[**Solution:**](solutions/welcome/for_the_flag) ```solutions/welcome/for_the_flag```<br>
> FBC{some_long_flag_like_this}

**Intended Solution:** Simply read the instructions and after creating an account get on the board with a single point. This gets the engine to recognize their account and gets them familiar.

**Teaching Points:** This is how all Jeapordy CTFs work and its going to get them used to our flag format so that they have a crib in some cases or just so they know what they're looking for.


<br>

## Web Exploitation (WEBEX)
### WEBEX [10pts] Inspector Gadget
[**Challenge:**](challenges/tcp1337-webapp-nodejs) ```challenges/tcp1337-webapp-nodejs```<br>
[**Solution:**](solutions/web/inspector_gadget) ```solutions/web/inspector_gadget```

**Intended Solution:** The competitor navigates to the web page (with off-nominal port) and uses "inspect element" or "view source" to observe the HTML and code comments, where the flag is embedded.

**Teaching Points:** Web servers dont have to run on the standard port 80 and we can access them by specify the port explicitly. Additionally, the HTML that the browser is displaying might have notable secrets.

### WEBEX [25pts] The Middleman
[**Challenge:**](challenges/tcp1337-webapp-nodejs) ```challenges/tcp1337-webapp-nodejs```<br>
[**Solution:**](solutions/web/the_middleman) ```solutions/web/the_middleman```

**Intended Solution:** The competitor sets up a web proxy, ideally BurpSuite Community and using that web proxy intercepts web requests between the client browser and web server. The flag is in a XFLAG header.

**Teaching Points** Here we introudce the idea of a web proxy and the concept that browers and servers are simply operating in a client-server relationship.

### WEBEX [50pts] Get Out
[**Challenge:**](challenges/tcp7777-webapp-nodejs) ```challenges/tcp7777-webapp-nodejs```<br>
[**Solution:**](solutions/web/get_out) ```solutions/web/get_out```

**Intended Solution:** After navigating around the page and inspecting that the hyperlinks simply change a GET parameter, the user finds a code comment TODO saying that the "flag" button hasnt been implemented yet. They forecfully submit "flag" as the GET param to display the flag image.

**Teaching Points:** GET requests power the internet; the primary teaching point is what a GET request is and how parameter data is passed from the client to server. Additionally, how it can be manipulated.

### WEBEX [50pts] Mr. Robot
[**Challenge:**](challenges/tcp7777-webapp-nodejs) ```challenges/tcp7777-webapp-nodejs```<br>
[**Solution:**](solutions/web/mr_robot) ```solutions/web/mr_robot```

**Intended Solution:** User performs standard webapp reconisance and identifies an active robots.txt page. This page has an admin page that should be behind auth but is accessible. The user forecfully browses to the page for the flag.

**Teaching Points:** First and foremost we teach what the robots RFC is and why its implemented for spiders. Then there is the idea that sometimes its used to hiden sensitive pages and can therefore expose them. Lastly, foreful browsing.

### WEBEX [50pts] Cookie Monster
[**Challenge:**](challenges/tcp9001-webapp-nodejs) ```challenges/tcp9001-webapp-nodejs```<br>
[**Solution:**](solutions/web/cookie_monster) ```solutions/web/cookie_monster```

**Intended Solution:** Either via an established web-proxy or through store inspection in the brower, or via a cookie editor, the user identifies a cookie with the flag in it and extracts the string.

**Teaching Points:** Cookies are simply another header in the web request and they are used for a variety of things but simply put are a way for a client to track information and send it to and from a web server.

### WEBEX [90pts] The Postman
[**Challenge:**](challenges/tcp9001-webapp-nodejs) ```challenges/tcp9001-webapp-nodejs```<br>
[**Solution:**](solutions/web/the_postman) ```solutions/web/the_postman```

**Intended Solution:** User is given the login credentails but is told the page is submitting the wrong credentials due to a client-side bug. They manually set the POST parameters to login with the provided credentials successfully.

**Teaching Points:** Sometimes there are things clientside that prevent us from logging in. Just because there is a bug client-side, doesn't mean we can't send data to the server. You have complete control over what is being sent via the proxy.

<br>

## Binary Exploitation (BINEX)
### BINEX [10pts] Execution
[**Challenge:**](challenges/01-ELFx86) ```challenges/x86-elf-binary-1```<br>
[**Solution:**](solutions/binex/execution) ```solutions/binex/execution```

**Intended Solution:** The competitor will recieve the binary and must run it in order to recieve the flag, this means downloading it to an approperiate directory and setting executable, then running it.

**Teaching Points:** Here we are teaching that a binary will always be downloaded as 600 perms and needs to get executable perms in order to execute. Also loosely that anything can be set executable. Basically just how to run executables on a linux machine.

### BINEX [25pts] Telegram
[**Challenge:**](challenges/tcp5555-socket-python3) ```challenges/tcp5555-socket-python3```<br>
[**Solution:**](solutions/binex/telegram) ```solutions/binex/telegram```

**Intended Solution:** Here the competitor connects to a socket and must recieve a message. This is intended to be done with netcat but could teheoritically be done with pwntools or raw socket programming in any language.

**Teaching Points:** This is designed to be a ramp up to sending and recieving an actual exploit across a socket remotely. The idea being that we first teach basic socket programming, then stack on top of it with pwntools.

### BINEX [50pts] Fast and Furious
[**Challenge:**](challenges/tcp1234-socket-python3) ```challenges/tcp1234-socket-python3```<br>
[**Solution:**](solutions/binex/fast_and_furious) ```solutions/binex/fast_and_furious```

**Intended Solution:** The competitor starts from a similar place with generic socket programming, but now must script in order to both send AND recieve from the socket 100 times within 10 seconds. This has to be scripted due to the time requirement.

**Teaching Points:** Here we continue to staack on top of the socket programming concepts. The goal is to get a student to be able to recieve a program prompt or arbitrary data and handle that before sending a payload.

### BINEX [50pts] Stacked
[**Challenge:**](challenges/tcp6000-socket-python3) ```challenges/tcp5678-socket-python3```<br>
[**Solution:**](solutions/binex/stacked) ```solutions/binex/stacked```

**Intended Solution:** Now the competitor has a variable loaded onto the stack and must overwrite the contents via overflow. When that happens on the remote machine logic checks determine the variable was overflowed and print a value to the screen.

**Teaching Points:** We continue to build towards a stack overflow exploit for the purpose of RCE, here introducing the overwriting of variables on the stack. The user will get the source code here so they can undrstand whats going on behind the scenes a bit.

### BINEX [50pts] Ready, Aim, Fire
[**Challenge:**](challenges/tcp6000-socket-python3) ```challenges/tcp6789-socket-python3```<br>
[**Solution:**](solutions/binex/ready_aim_fire) ```solutions/binex/ready_aim_fire```

**Intended Solution:** Now the competitor must calculate at exactly what offset the overflow is happening and replace those specific bytes with a non-printable byte pattern. This means pattern creation and matching.

**Teaching Points:** Continuing to build on the overflow logic, here we are introducing the idea of calculating where you have control. Offset calculation is critical to obtaining eventual code execution and this is the final step prior to overwriting with real addresses.

### BINEX [90pts] Return of the King
[**Challenge:**](challenges/tcp6000-socket-python3) ```challenges/tcp8888-socket-python3```<br>
[**Solution:**](solutions/binex/return_of_the_king) ```solutions/binex/return_of_the_king```

**Intended Solution:** In the final binex challenge, we are overwriting with an actual address for simluated code execution. Here the user now must use the obtained shell to cat the flag file.

**Teaching Points:** Finally we get to an actual logical overwrite where the user must take their point of control and derive a shell. They do not need to write shellcode however, as this will be a ret2win style POC.

<br>

## Cryptography (CRYPTO)
### CRYPTO [10pts] Titanic
[**Challenge:**](challenges/cipher1-ascii) ```challenges/cipher1-ascii```<br>
[**Solution:**](solutions/crypto/titanic) ```solutions/crypto/titanic```

**Intended Solution:** The student starts off with a repeating pattern of dots and dashes. They google for what that pattern could be and quickly identify that it is morse code. They then use a morse decoder to retrieve the plaintext.

**Teaching Points:** Most importantly, the student learns that there is ciphertext and plaintext and that we can often convert between them using an algorithm. We start to introduce the idea that ciphers can be recognized based on patterns of characters.

### CRYPTO [25pts] Cleopatra
[**Challenge:**](challenges/cipher2-ascii) ```challenges/cipher2-ascii```<br>
[**Solution:**](solutions/crypto/cleopatra) ```solutions/crypto/cleopatra```

Challenge Description
Caesar cipher non13

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### CRYPTO [50pts] Da Vinci Code
[**Challenge:**](challenges/cipher3-ascii) ```challenges/cipher3-ascii```<br>
[**Solution:**](solutions/crypto/da_vinci) ```solutions/crypto/da_vinci```

Challenge Description
XOR with a provided key

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### CRYPTO [50pts] Imitation Game
[**Challenge:**](challenges/cipher4-ascii) ```challenges/cipher4-ascii```<br>
[**Solution:**](solutions/crypto/imitation_game) ```solutions/crypto/imitation_game```

Challenge Description
Something thats run x3, base64, then morse, then rot

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### CRYPTO [50pts] Codebreaker
[**Challenge:**](challenges/cipher5-ascii) ```challenges/cipher5-ascii```<br>
[**Solution:**](solutions/crypto/codebreaker) ```solutions/crypto/codebreaker```

Challenge Description
XOR brute force for a single byte

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### CRYPTO [90pts] Enigma
[**Challenge:**](challenges/cipher6-ascii) ```challenges/cipher6-ascii```<br>
[**Solution:**](solutions/crypto/enigma) ```solutions/crypto/enigma```

Challenge Description
XOR byte force with a 4 byte key repeated, with a crib

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

<br>

## Networking
[**Challenge:**]() ``````<br>
[**Solution:**]() ``````

### 10pts Challenge Name
Challenge Description
Open a capture in wireshark and get some statistic like the start date

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 25pts
Challenge Description
How many hosts are available in a /12 network?

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
hide flags in the hostnames, have user retrieve hostnames

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Dump images from a http connection, lets say stream X, and the flag is one of those images

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Kinda secure shell, literally the same problem with better hints

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 90pts
Challenge Description
Interaction with a web server and read the data that is sent to a different port when the server responds. Just tell the user that data is being sent to them but the port has been messed up. Idea being that they montior with wireshark for the packet, will have to be UDP cause handshakes

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

<br>

## Forensics
### 10pts Challenge Name
Challenge Description
Strings

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 25pts
Challenge Description
Identify the entry point of a binary

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Steghide extract without a password

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
log investigation for an event or credentials

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
mount a disk image and read the flag file out

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 90pts
Challenge Description
Bypass a login check, impossible password style, using gdb to get the flag

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```