#include <iostream>
#include <chrono>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <openssl/hmac.h>

using json = nlohmann::json;

const char *apiPath = "api/v1/malfunctions";

std::string makeSignature(const std::string &key, const std::string &nonce)
{
    std::string data(apiPath + nonce);

    const char *k = key.data();
    const unsigned char *d = reinterpret_cast<const unsigned char *>(data.data());
    unsigned char *result = nullptr;
    unsigned int resultlen = 0;

    result = HMAC(EVP_sha1(), (const void *)k, key.length(), d, data.length(), result, &resultlen);

    std::stringstream ss;
    for (unsigned int i = 0; i < resultlen; i++)
        ss << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(result[i]);

    return std::string(ss.str());
}

int main()
{
    const auto p1 = std::chrono::system_clock::now();
    std::string nonce = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count());

    std::ifstream f("params.json");
    json params = json::parse(f);

    std::string publicKey = params.value("publicKey", std::string());
    std::string privateKey = params.value("privateKey", std::string());
    std::string address = params.value("address", std::string());

    cpr::Header hdr{
        {"trombon-apikey", publicKey},
        {"trombon-nonce", nonce},
        {"trombon-signature", makeSignature(privateKey, nonce)},
        {"Content-Type", "application/json"}
    };

    cpr::Response r = cpr::Get(cpr::Url{address + ":" + std::to_string(8080) + "/" + apiPath}, hdr);
    json data = json::parse(r.text);

    std::cout << data << std::endl;

    if (data.empty())
        return 0;

    return 1;
}
