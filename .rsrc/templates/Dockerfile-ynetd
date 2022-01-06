# sudo docker build -t challenge_tcp5555 .
# sudo docker run -d -p 5555:5555 --rm --name FBC_tcp5555 challenge_tcp5555

FROM ubuntu:20.04

RUN apt-get update

RUN useradd -d /home/telegram/ -m -p telegram -s /bin/bash telegram
RUN echo "telegram:telegram" | chpasswd

WORKDIR /home/telegram

COPY ynetd /usr/bin
COPY telegram .
COPY flag.txt .

RUN chown -R telegram:telegram /home/telegram

USER telegram
EXPOSE 5555
CMD chmod +x ynetd
CMD chmod +x telegram
CMD /usr/bin/ynetd -p 5555 ./telegram