# sudo docker build -t challenge_tcp1234 .
# sudo docker run -d -p 1234:1234 --rm --name FBC_tcp1234 challenge_tcp1234

FROM ubuntu:20.04

RUN apt-get update
RUN apt-get install python3 -y

RUN useradd -d /home/fast_and_furious/ -m -p fast_and_furious -s /bin/bash fast_and_furious
RUN echo "fast_and_furious:fast_and_furious" | chpasswd

WORKDIR /home/fast_and_furious

COPY ynetd /usr/bin
COPY fast_and_furious.py .
COPY timeout_stager.sh .
COPY flag.txt .

RUN chown -R fast_and_furious:fast_and_furious /home/fast_and_furious

USER fast_and_furious
EXPOSE 1234
CMD chmod +x timeout_stager.sh
CMD /usr/bin/ynetd -p 1234 ./timeout_stager.sh