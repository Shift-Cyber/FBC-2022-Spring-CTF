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

**Tie breaks:** If there is a tie for a position on the scoreboard based on total points the tie will be decided by who achieved that amount of points first.

<br>

# Challenges
| Pts | [Web Exploitation](#web-exploitation-webex) | [Binary Exploitation](#binary-exploitation-binex) | [Cryptography](#cryptography-crypto) | [Networking](#networking) | [Forensics](#forensics) |
|:----:|:----------------:|:----------------:|:----------------:|:----------------:|:----------------:|
|  10  | Challenge | Challenge | Challenge | Challenge | Challenge |
|  25  | Challenge | Challenge | Challenge | Challenge | Challenge |
|  50  | Challenge | Challenge | Challenge | Challenge | Challenge |
|  50  | Challenge | Challenge | Challenge | Challenge | Challenge |
|  50  | Challenge | Challenge | Challenge | Challenge | Challenge |
|  90  | Challenge | Challenge | Challenge | Challenge | Challenge |

<br>

## Introduction
### WELCOME [1pt] For the Flag
[**Solution:**](solutions/welcome/for_the_flag) ```solutions/welcome/for_the_flag```

**Intended Solution:** Simply read the instructions and after creating an account get on the board with a single point. This gets the engine to recognize their account and gets them familiar.

**Teaching Points:** This is how all Jeapordy CTFs work and its going to get them used to our flag format so that they have a crib in some cases or just so they know what they're looking for.

<br>

## Web Exploitation (WEBEX)
### WEBEX [10pts] Inspector Gadget
[**Challenge:**](challenges/tcp1337-webapp-nodejs) ```challenges/tcp1337-webapp-nodejs```<br>
[**Solution:**](solutions/web/inspector_gadget) ```solutions/web/inspector_gadget```

**Intended Solution:** The competitor navigates to the web page (with off-nominal port) and uses "inspect element" or "view source" to observe the HTML and code comments, where the flag is embedded.

**Teaching Points:** Web servers dont have to run on the standard port 80 and we can access them by specify the port explicitly. Additionally, the HTML that the browser is displaying might have notable secrets.

---

### WEBEX [25pts] The Middleman
[**Challenge:**](challenges/tcp1337-webapp-nodejs) ```challenges/tcp1337-webapp-nodejs```<br>
[**Solution:**](solutions/web/the_middleman) ```solutions/web/the_middleman```

**Intended Solution:** The competitor sets up a web proxy, ideally BurpSuite Community and using that web proxy intercepts web requests between the client browser and web server. The flag is in a XFLAG header.

**Teaching Points** Here we introudce the idea of a web proxy and the concept that browers and servers are simply operating in a client-server relationship.

---

### WEBEX [50pts] GET Out
[**Challenge:**](challenges/tcp7777-webapp-nodejs) ```challenges/tcp7777-webapp-nodejs```<br>
[**Solution:**](solutions/web/get_out) ```solutions/web/get_out```

**Intended Solution:** After navigating around the page and inspecting that the hyperlinks simply change a GET parameter, the user finds a code comment TODO saying that the "flag" button hasnt been implemented yet. They forecfully submit "flag" as the GET param to display the flag image.

**Teaching Points:** GET requests power the internet; the primary teaching point is what a GET request is and how parameter data is passed from the client to server. Additionally, how it can be manipulated.

---

### WEBEX [50pts] Mr. Robot
[**Challenge:**](challenges/tcp7777-webapp-nodejs) ```challenges/tcp7777-webapp-nodejs```<br>
[**Solution**](solutions/web/mr_robot) ```solutions/web/mr_robot```

**Intended Solution:** User performs standard webapp reconisance and identifies an active robots.txt page. This page has an admin page that should be behind auth but is accessible. The user forecfully browses to the page for the flag.

**Teaching Points:** First and foremost we teach what the robots RFC is and why its implemented for spiders. Then there is the idea that sometimes its used to hiden sensitive pages and can therefore expose them. Lastly, foreful browsing.

---

### WEBEX [50pts] Cookie Monster
[**Challenge:**](challenges/tcp9001-webapp-nodejs) ```challenges/tcp9001-webapp-nodejs```<br>
[**Solution**](solutions/web/cookie_monster) ```solutions/web/cookie_monster```

**Intended Solution:** Either via an established web-proxy or through store inspection in the brower, or via a cookie editor, the user identifies a cookie with the flag in it and extracts the string.

**Teaching Points:** Cookies are simply another header in the web request and they are used for a variety of things but simply put are a way for a client to track information and send it to and from a web server.

---

### WEBEX [90pts] The Postman
[**Challenge**](challenges/tcp9001-webapp-nodejs) ```challenges/tcp9001-webapp-nodejs```<br>
[**Solution**](solutions/web/the_postman) ```solutions/web/the_postman```

**Intended Solution:** User is given the login credentails but is told the page is submitting the wrong credentials due to a client-side bug. They manually set the POST parameters to login with the provided credentials successfully.

**Teaching Points:** Sometimes there are things clientside that prevent us from logging in. Just because there is a bug client-side, doesn't mean we can't send data to the server. You have complete control over what is being sent via the proxy.

<br>

## Binary Exploitation (BINEX)
#### 10pts Challenge Name
Challenge Description
Run a linux binary to get the flag (requires setting executable)

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 25pts
Challenge Description
Connect to a remote socket with netcat

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Requires that the user count to 100 over netcat within 10 seconds recieving responses in the process

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Overflow a stack variable to get the flag locally then remotely

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Overwrite the target variable with specific bytes

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 90pts
Challenge Description
Ret2Win with a provided function address on the remote, let ASLR and PIE stay on so they have to read it. Provide a buffer cap here and write in restrictions so they cant actually get legit RCE

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### Cryptography (CRYPTO)
#### 10pts Challenge Name
Challenge Description
Morse code

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 25pts
Challenge Description
Caesar cipher non13

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
XOR with a provided key

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Something thats run x3, base64, then morse, then rot

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
XOR brute force for a single byte

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 90pts
Challenge Description
XOR byte force with a 4 byte key repeated, with a crib

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### Networking
#### 10pts Challenge Name
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

### Forensics
#### 10pts Challenge Name
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