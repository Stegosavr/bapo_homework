FROM ubuntu:latest AS builder

RUN apt-get update
RUN apt-get -y install libcurl4-gnutls-dev gcc

RUN mkdir /app
WORKDIR /app
COPY . /app

RUN ./build.sh



FROM ubuntu:latest

WORKDIR /app
COPY --from=builder /app/ip .

RUN apt-get update
RUN apt-get -y install libcurl4-gnutls-dev

CMD ["./ip"]
