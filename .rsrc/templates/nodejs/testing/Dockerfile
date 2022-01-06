# sudo docker build -t nodejs-test .
# sudo docker run -d -p 3000:3000/tcp --rm --name nodejs-test nodejs-test

FROM node:9-slim

RUN useradd -d /home/nodetest/ -m -p nodetest -s /bin/bash nodetest
RUN echo "nodetest:nodetest" | chpasswd

WORKDIR /home/nodetest

COPY package.json /home/nodetest

RUN npm install

COPY . /home/nodetest
CMD npm start