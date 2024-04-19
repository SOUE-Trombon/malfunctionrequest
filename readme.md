# Malfunction requester for Trombon IP
[![alt text](https://trombon.org/images/trombon_logo.webp)](https://trombon.org/)

Request malfunctions from Trombon emf (MO8) prints output to console and return 0 if no errors and 1 if errors persist. Suitable for some monitoring software. Written on pure C++.

## How to build
    mkdir build && cd build
    cmake -G "Unix Makefiles" -DBUILD_SHARED_LIBS=OFF ..
    cmake --build .

## How to use
Obtain public and private keys with "Malfunctions" access from emf (MO8) using web interface
Create file just near the executable and call it `params.json` with following content

    {
        "publicKey" : "yourPubKey",
        "privateKey" : "yourPrivKey",
        "address" : "serverAddress"
    }

Run the executable, and read the exit code.

## Remarks
OpenSSL installation is requred. Windows prebuilt binaries can be obtained from [here](https://kb.firedaemon.com/support/solutions/articles/4000121705).
To see JSON output on Windows in CMD you may need to switch UTF-8. How to do this explained [here](https://stackoverflow.com/a/57134096/15175873).
To see exit code on Windows run script in PowerShell and after execution print `$LASTEXITCODE`
