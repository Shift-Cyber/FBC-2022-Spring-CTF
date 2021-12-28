# sudo docker build -t challenge_tcp6000 .
# sudo docker run -d -p 6000:6000 --rm --name FBC_tcp6000 challenge_tcp6000

FROM ubuntu:20.04

# support for x86
RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386 zlib1g:i386

RUN useradd -d /home/return-of-the-king/ -m -p return-of-the-king -s /bin/bash return-of-the-king
RUN echo "return-of-the-king:return-of-the-king" | chpasswd

WORKDIR /home/return-of-the-king

COPY ynetd /usr/bin
COPY vuln .
COPY flag.txt .

RUN chown -R return-of-the-king:return-of-the-king /home/return-of-the-king

USER return-of-the-king
EXPOSE 6000
CMD /usr/bin/ynetd -p 6000 ./vuln