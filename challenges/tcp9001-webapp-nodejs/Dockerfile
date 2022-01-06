# sudo docker build -t challenge_tcp9001 .
# sudo docker run -d -p 9001:9001/tcp --rm --name challenge_tcp9001 challenge_tcp9001

FROM node:9-slim

RUN useradd -d /home/fbc-webex/ -m -p fbc-webex -s /bin/bash fbc-webex
RUN echo "fbc-webex:fbc-webex" | chpasswd
USER fbc-webex

WORKDIR /home/fbc-webex

COPY package.json* /home/fbc-webex

RUN npm install

COPY . /home/fbc-webex
CMD npm start
