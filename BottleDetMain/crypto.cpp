#include"pch.h"
#include"crypto.h"
#include <fstream>
#include <openssl/evp.h>
#include <windows.h>

// ȫ�ֲ���
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
	// ��ʼ��OpenSSL��
	OpenSSL_add_all_algorithms();

	// ����EVP����������
	EVP_CIPHER_CTX* encryptCtx = EVP_CIPHER_CTX_new();

	// ��ʼ������������
	if (!EVP_EncryptInit_ex(encryptCtx, EVP_aes_256_cbc(), nullptr, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str())) {
		handleErrors();
	}

	// ִ�м���
	int ciphertext_len = 0;
	unsigned char ciphertext[1024];
	if (!EVP_EncryptUpdate(encryptCtx, ciphertext, &ciphertext_len, (const unsigned char*)plaintext.c_str(), plaintext.length())) {
		handleErrors();
	}

	// ��������
	int final_ciphertext_len = 0;
	if (!EVP_EncryptFinal_ex(encryptCtx, ciphertext + ciphertext_len, &final_ciphertext_len)) {
		handleErrors();
	}
	ciphertext_len += final_ciphertext_len;

	outputFileName = folderPath + outputFileName;

	// ����ļ����Ƿ���ڣ���������ڣ��򴴽���
	CreateDirectoryA(folderPath.c_str(), nullptr);

	// ���ļ���д���������
	std::ofstream outputFile(outputFileName, std::ios::binary);
	if (!outputFile) {
		std::cerr << "Failed to open output file." << std::endl;
		EVP_CIPHER_CTX_free(encryptCtx);
		return;
	}

	// �����ܺ������д���ļ�
	outputFile.write(reinterpret_cast<const char*>(ciphertext), ciphertext_len);

	// �ر��ļ�
	outputFile.close();

	// �������������
	EVP_CIPHER_CTX_free(encryptCtx);
}

// ���ļ���ȡ�������ַ���
std::string readAndDecryptFromFile() {
	// �򿪼����ļ��Զ�ȡ����
	OpenSSL_add_all_algorithms();
	std::ifstream inputFile(fullPath, std::ios::binary);
	if (!inputFile) {
		std::cerr << "Failed to open input file." << std::endl;
		return "";
	}

	// ��ȡ�ļ���С
	inputFile.seekg(0, inputFile.end);
	int file_size = inputFile.tellg();
	inputFile.seekg(0, inputFile.beg);

	// ��ȡ��������
	unsigned char* ciphertext = new unsigned char[file_size];
	inputFile.read(reinterpret_cast<char*>(ciphertext), file_size);

	// ����EVP����������
	EVP_CIPHER_CTX* decryptCtx = EVP_CIPHER_CTX_new();

	// ��ʼ������������
	if (!EVP_DecryptInit_ex(decryptCtx, EVP_aes_256_cbc(), nullptr, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str())) {
		handleErrors();
		delete[] ciphertext;
		inputFile.close();
		EVP_CIPHER_CTX_free(decryptCtx);
		return "";
	}

	// ִ�н���
	unsigned char decryptedtext[1024];
	int decryptedtext_len = 0;
	if (!EVP_DecryptUpdate(decryptCtx, decryptedtext, &decryptedtext_len, ciphertext, file_size)) {
		handleErrors();
		delete[] ciphertext;
		inputFile.close();
		EVP_CIPHER_CTX_free(decryptCtx);
		return "";
	}

	// ��������
	int final_decryptedtext_len = 0;
	if (!EVP_DecryptFinal_ex(decryptCtx, decryptedtext + decryptedtext_len, &final_decryptedtext_len)) {
		handleErrors();
		delete[] ciphertext;
		inputFile.close();
		EVP_CIPHER_CTX_free(decryptCtx);
		return "";
	}
	decryptedtext_len += final_decryptedtext_len;

	// �ر��ļ�
	inputFile.close();

	// ������������ĺ��ڴ�
	EVP_CIPHER_CTX_free(decryptCtx);
	delete[] ciphertext;

	// ���ؽ��ܺ�������ַ���
	return std::string((char*)decryptedtext, decryptedtext_len);
}