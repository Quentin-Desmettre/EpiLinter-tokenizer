FROM ubuntu:latest

USER root
WORKDIR /root

# Install dependencies
RUN apt-get update -y && apt-get install -y \
    g++ \
    make \
    libboost-wave-dev

# Install EpiLinter-tokenizer
RUN mkdir EpiLinter-tokenizer
COPY . .
RUN make re

EXPOSE 8081
CMD ./epi-tokenizer
