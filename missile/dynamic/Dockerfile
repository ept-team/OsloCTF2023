# sudo docker build -t missile .
# sudo docker run -d -p 8887:8887 --rm -it missile

FROM ubuntu:22.04

RUN apt-get update

RUN useradd -d /home/edc/ -m -p edc -s /bin/bash edc
RUN echo "edc:edc" | chpasswd

WORKDIR /home/edc

COPY ynetd .
COPY flag.txt /opt/flag
COPY missile .

RUN chown -R root:root /home/edc
RUN chmod  -R a+rx /home/edc
USER edc
CMD ./ynetd -p 8887 ./missile
