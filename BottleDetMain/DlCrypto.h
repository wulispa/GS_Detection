//#pragma once
#ifndef DLCRYPTO_H
#define DLCRYPTO_H

#include <iostream>
#include <memory>
#include <fstream>
#include <aes.h>
#include <iostream>
#include <ostream>
#include <filters.h>
#include <modes.h>
#include <files.h>
#include <string>
#include <sstream> 


using namespace std;
using namespace CryptoPP;


extern "C" __declspec(dllexport) void initKV();

string decrypt(string cipherTextHex);

string encrypt(string plainText);

void writeCipher(string output);

string readCipher(string de_model_path);

extern "C" __declspec(dllexport) void decry_onnx(string encry_onnx_path);

extern "C" __declspec(dllexport) void encrypt_file(const std::string & filename_in, const std::string & filename_out, const std::string & other);
extern "C" __declspec(dllexport) void decrypt_file(const std::string& filename_in, const std::string& filename_out);

#endif 