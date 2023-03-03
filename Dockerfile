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
COPY . /root/EpiLinter-tokenizer
RUN \
    cd EpiLinter-tokenizer \
    && make re && make clean \
    && apt-get remove -y \
        g++ \
        make \
    && apt-get autoremove -y \
    && apt-get clean -y \
    && apt-get autoclean -y \
    && apt-get purge -y \
    && cp epi-tokenizer .. \
    && cd .. \
    && rm -rf EpiLinter-tokenizer

EXPOSE 8081
CMD ./epi-tokenizer
