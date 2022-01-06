# sudo docker build -t challenge_tcp7777 .
# sudo docker run -d -p 7777:7777/tcp --rm --name challenge_tcp7777 challenge_tcp7777

FROM node:9-slim

RUN useradd -d /home/fbc-webex/ -m -p fbc-webex -s /bin/bash fbc-webex
RUN echo "fbc-webex:fbc-webex" | chpasswd
USER fbc-webex

WORKDIR /home/fbc-webex

COPY package.json* /home/fbc-webex

RUN npm install

COPY . /home/fbc-webex
CMD npm start
