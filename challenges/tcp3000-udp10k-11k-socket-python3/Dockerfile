# sudo docker build -t challenge_tcp5555 .
# sudo docker run -d -p 3000:3000/tcp -p50000-55000:50000-55000/udp --rm --name FBC_tcp5555 challenge_tcp5555

FROM ubuntu:20.04

RUN apt-get update

RUN useradd -d /home/mailman/ -m -p mailman -s /bin/bash mailman
RUN echo "mailman:mailman" | chpasswd

WORKDIR /home/mailman

COPY mailman.py .
COPY flag.txt .

RUN chown -R mailman:mailman /home/mailman

USER telegram
EXPOSE 5555
CMD chmod +x mailman.py
CMD python3 mailman.py