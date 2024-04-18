# Malfunction requester for Trombon IP
Request malfunctions from Trombon emf (MO8) and return 0 if no errors and 1 if errors persist. Suitable for some monitoring software. Written on pure C++.

## How to build
    mkdir build && cd build
    cmake -G "Unix Makefiles" -DBUILD_SHARED_LIBS=OFF ..
    cmake --build .

## How to use
Create file just near the executable and call it `params.json` with following content

    {
        "publicKey" : "yourPubKey",
        "privateKey" : "yourPrivKey",
        "address" : "serverAddress"
    }

Run the executable, and read the exit code.

### Remark
openSSL installation is requred

