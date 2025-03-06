#include"pch.h"
#include"crypto.h"
#include <fstream>
#include <openssl/evp.h>
#include <windows.h>

// 全局参数
std::string folderPath = "C:\\DSDsoftware\\";
const std::string key = "IDONTHAVEMONEY";
const std::string iv = "0919VAL";
std::string outputFileName = "config.cfg";
std::string fullPath = folderPath + outputFileName;

void handleErrors() {
	std::cerr << "Error occurred." << std::endl;
	abort();
}

void encryptAndSaveToFile(const std::string& plaintext) {
	// 初始化OpenSSL库
	OpenSSL_add_all_algorithms();

	// 创建EVP加密上下文
	EVP_CIPHER_CTX* encryptCtx = EVP_CIPHER_CTX_new();

	// 初始化加密上下文
	if (!EVP_EncryptInit_ex(encryptCtx, EVP_aes_256_cbc(), nullptr, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str())) {
		handleErrors();
	}

	// 执行加密
	int ciphertext_len = 0;
	unsigned char ciphertext[1024];
	if (!EVP_EncryptUpdate(encryptCtx, ciphertext, &ciphertext_len, (const unsigned char*)plaintext.c_str(), plaintext.length())) {
		handleErrors();
	}

	// 结束加密
	int final_ciphertext_len = 0;
	if (!EVP_EncryptFinal_ex(encryptCtx, ciphertext + ciphertext_len, &final_ciphertext_len)) {
		handleErrors();
	}
	ciphertext_len += final_ciphertext_len;

	outputFileName = folderPath + outputFileName;

	// 检查文件夹是否存在，如果不存在，则创建它
	CreateDirectoryA(folderPath.c_str(), nullptr);

	// 打开文件以写入加密数据
	std::ofstream outputFile(outputFileName, std::ios::binary);
	if (!outputFile) {
		std::cerr << "Failed to open output file." << std::endl;
		EVP_CIPHER_CTX_free(encryptCtx);
		return;
	}

	// 将加密后的数据写入文件
	outputFile.write(reinterpret_cast<const char*>(ciphertext), ciphertext_len);

	// 关闭文件
	outputFile.close();

	// 清理加密上下文
	EVP_CIPHER_CTX_free(encryptCtx);
}

// 从文件读取并解密字符串
std::string readAndDecryptFromFile() {
	// 打开加密文件以读取内容
	OpenSSL_add_all_algorithms();
	std::ifstream inputFile(fullPath, std::ios::binary);
	if (!inputFile) {
		std::cerr << "Failed to open input file." << std::endl;
		return "";
	}

	// 获取文件大小
	inputFile.seekg(0, inputFile.end);
	int file_size = inputFile.tellg();
	inputFile.seekg(0, inputFile.beg);

	// 读取加密数据
	unsigned char* ciphertext = new unsigned char[file_size];
	inputFile.read(reinterpret_cast<char*>(ciphertext), file_size);

	// 创建EVP解密上下文
	EVP_CIPHER_CTX* decryptCtx = EVP_CIPHER_CTX_new();

	// 初始化解密上下文
	if (!EVP_DecryptInit_ex(decryptCtx, EVP_aes_256_cbc(), nullptr, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str())) {
		handleErrors();
		delete[] ciphertext;
		inputFile.close();
		EVP_CIPHER_CTX_free(decryptCtx);
		return "";
	}

	// 执行解密
	unsigned char decryptedtext[1024];
	int decryptedtext_len = 0;
	if (!EVP_DecryptUpdate(decryptCtx, decryptedtext, &decryptedtext_len, ciphertext, file_size)) {
		handleErrors();
		delete[] ciphertext;
		inputFile.close();
		EVP_CIPHER_CTX_free(decryptCtx);
		return "";
	}

	// 结束解密
	int final_decryptedtext_len = 0;
	if (!EVP_DecryptFinal_ex(decryptCtx, decryptedtext + decryptedtext_len, &final_decryptedtext_len)) {
		handleErrors();
		delete[] ciphertext;
		inputFile.close();
		EVP_CIPHER_CTX_free(decryptCtx);
		return "";
	}
	decryptedtext_len += final_decryptedtext_len;

	// 关闭文件
	inputFile.close();

	// 清理解密上下文和内存
	EVP_CIPHER_CTX_free(decryptCtx);
	delete[] ciphertext;

	// 返回解密后的明文字符串
	return std::string((char*)decryptedtext, decryptedtext_len);
}