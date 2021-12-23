# FBC-2022-Spring-CTF
Capture The Flag (CTF) competition prepared for Fallbrook Cyber, Spring 2022

![SCYCA Logo](.resources/Logo-Full-black-JPG.jpg)

## Welcome!!
This CTF is compromised of 30 challenges, with 6 problems per each of the 5 sections. For the newer players out there this is referring to the standard 5 CTF sections: web exploitation (webex), binary exploitation (binex), forensics, networking, and cryptography (crypto). The problems increase in difficulty as you progress through the point ratings with harder or more intricate problems awarding more points. Each problem has a series of hints that will get you 90% of the way to the answer if you choose to use them. The competition organizers have decided to leave these hints free for your use as the root purpose is of course to teach the skills and techniques to you. Each challenge will still, however, require a fair bit of effort from the participant to solve.

Competition opens at 1500, at the start of the first practice of the year, 7 January 2022 and runs until the start of our last practice of the season on 20 May 2022. The goal is for you as the participant to take as much as possible away from this, aside from just the cool prizes ;)

## Prizes
1st Place - TBD<br>
2nd Place - TBD<br>
3rd Place - TBD<br>

**Tie breaks: **If there is a tie for a position on the scoreboard based on total points the tie will be decided by who achieved that amount of points first.

## Challenge Breakout
### WEBEX [10pts] Inspector Gadget
Challenge files: ```web/inspector_gadget```

Intended Solution: the competitor navigates to the web page (with off-nominal port) and uses "inspect element" or "view source" to observe the HTML and code comments, where the flag is embedded.

Teaching Points: Web servers dont have to run on the standard port 80 and we can access them by specify the port explicitly. Additionally, the HTML that the browser is displaying might have notable secrets.

---

### WEBEX [25pts] The Middleman
Challenge files: ```web/the_middleman```

Here the competitor is provided a URL and is told that there is hidden data in the stream. The goal of the challenge is to setup Burp or Zap and catch the hidden traffic in the communication. This will be implemented either at the TCP layer or hideen in the page some other way.

Hint1: When we navigate to www.google.com our browser sends a request to Google's webserver for the data that it needs in order to display the user the web page, kind of like instructions for drawing something. This data is HTML code and other stuff. Can we get in the middle of this connection to see everything that is being sent?
Hint2: we need better hints for this

---

Solution POC: ```relative/path/here```

#### [50pts] GET Out
Challenge Description
With this one there is a page with three links and when they click the links it submits a GET with a parameter on the home page to choose one of three cat images. If they change the paraemeter to "flag" it will show a picture with the flag in it.

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
Here we're teaching what spidering/crawling and hidden things with robots are. Once they idenitfy robots.txt they will find a long url that they can forcefully browse to in order to get the flag.

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 50pts
Challenge Description
In this we are going to present a cookie in a flag and force them to idenitfy the flag via inspecting cookies

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

#### 90pts
Challenge Description
Posting arbitrary data like a username that is being prevented clientside

Intended Solution Writeup

Teaching points

Solution POC: ```relative/path/here```

### Binary Exploitation (BINEX)
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