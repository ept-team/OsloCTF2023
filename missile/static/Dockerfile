# sudo docker build -t missile-static .
# sudo docker run -d -p 8888:8888 --rm -it missile-static

FROM ubuntu:22.04

RUN apt-get update

RUN useradd -d /home/edc/ -m -p edc -s /bin/bash edc
RUN echo "edc:edc" | chpasswd

WORKDIR /home/edc

COPY ynetd .
COPY flag.txt /opt/flag
COPY missile-static .

RUN chown -R root:root /home/edc
RUN chmod  -R a+rx /home/edc
USER edc
CMD ./ynetd -p 8887 ./missile-static
