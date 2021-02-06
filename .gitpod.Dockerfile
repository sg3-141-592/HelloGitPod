FROM gitpod/workspace-full

USER gitpod

RUN sudo apt-get update -q && \
    sudo apt-get install -yq valgrind

# RUN git clone https://github.com/aws/aws-sdk-cpp.git

# RUN mkdir aws-build

# RUN cd aws-build && cmake ../aws-sdk-cpp/ -DCMAKE_BUILD_TYPE=Debug -DBUILD_ONLY="sqs;s3" && \
#     make && sudo make install
