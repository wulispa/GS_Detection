#include "pch.h"
#include "dlCrypto.h"
#include <assert.h>




byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];

void initKV()
{
	/*memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
	memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);*/
	// 或者也可以
	//char tmpK[] = "gngLxg8eZZG080WVnU2-6FWwn8HF8Mr21-4vgnJshR8=";
	char tmpK[] = "lxg502shjkbjio^2";
	//char tmpIV[] = "\xcaq\xab\xf2|Nd\xa4\x16\x8av\x94\xa4.m\x80";
	char tmpIV[] = "zcmr4sg32g3fg32f";
	/*char tmpK[] = "tqsktqsktqsktqsk";
	char tmpIV[] = "qqqqqqqqqqqqqqqq";*/
	for (int j = 0; j < CryptoPP::AES::DEFAULT_KEYLENGTH; ++j)
	{
		key[j] = tmpK[j];
	}

	for (int i = 0; i < CryptoPP::AES::BLOCKSIZE; ++i)
	{
		iv[i] = tmpIV[i];
	}
}

string encrypt(string plainText)
{
	string cipherText;

	//
	CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
	CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plainText.c_str()), plainText.length() + 1);
	stfEncryptor.MessageEnd();

	string cipherTextHex;
	for (int i = 0; i < cipherText.size(); i++)
	{
		char ch[3] = { 0 };
		sprintf_s(ch, "%02x", static_cast<byte>(cipherText[i]));
		cipherTextHex += ch;
	}

	return cipherTextHex;
}

void writeCipher(string output)
{
	ofstream out("E:/zby/DLvisionDi/Cpro/AEStest/tmp/cipher.data");
	out.write(output.c_str(), output.length());
	out.close();

	cout << "writeCipher finish " << endl << endl;
}

string decrypt(string cipherTextHex)
{
	string cipherText;
	string decryptedText;

	int i = 0;
	char c;
	int x;
	while (true)
	{
		/*stringstream ss;
		ss << hex << cipherTextHex.substr(i, 2).c_str();
		ss >> x;*/
		x = stoi(cipherTextHex.substr(i, 2), 0, 16);
		c = (char)x;
		cipherText += c;
		if (i >= cipherTextHex.length() - 2)break;
		i += 2;
	}
	//
	CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
	CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
	stfDecryptor.Put(reinterpret_cast<const unsigned char*>(cipherText.c_str()), cipherText.size());

	stfDecryptor.MessageEnd();

	return decryptedText;
}

string readCipher(string de_model_path)
{
	/*解密，输入模型路径*/
	//ifstream in("E:/zby/DLvisionDi/Cpro/AEStest/tmp/cipher.data");
	ifstream in(de_model_path, ios::binary);
	string line;
	string decryptedText;
	while (getline(in, line))
	{
		if (line.length() > 1)
		{
			decryptedText += decrypt(line) + "";
		}
		line.clear();
	}
	cout << "readCipher finish " << endl;
	in.close();

	return decryptedText;
}

void decry_onnx(string encry_onnx_path) {
	string tmp_onnx_path = "tmp_onnx.onnx";
	initKV();
	string text = readCipher(encry_onnx_path);
	/*text.erase(std::unique(text.begin(), text.end(),
		[](char a, char b) {return a == '\n' && b == '\n'; }),
		text.end());*/
	ofstream os;     //创建一个文件输出流对象
	os.open(tmp_onnx_path, ios::binary);//将对象与文件关联
	os << text;   //将输入的内容放入txt文件中
	os.close();
	//std::istringstream iss(text);
}

void encrypt_file(const std::string& filename_in, const std::string& filename_out, const std::string& other) {
	CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption cipher{};
	cipher.SetKeyWithIV(key, 16, iv);

	std::ifstream in{ filename_in, std::ios::binary };
	std::ofstream out{ filename_out, std::ios::binary };

	CryptoPP::FileSource{ in, /*pumpAll=*/true,
						 new CryptoPP::StreamTransformationFilter{
							 cipher, new CryptoPP::FileSink{out}} };
	if (other != "") {
		_CSTD remove(other.c_str());
	}
}

void decrypt_file(const std::string& filename_in, const std::string& filename_out) {
	CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption cipher{};
	cipher.SetKeyWithIV(key, 16, iv);

	std::ifstream in{ filename_in, std::ios::binary };
	std::ofstream out{ filename_out, std::ios::binary };

	CryptoPP::FileSource{ in, /*pumpAll=*/true,
						 new CryptoPP::StreamTransformationFilter{
							 cipher, new CryptoPP::FileSink{out}} };

}

