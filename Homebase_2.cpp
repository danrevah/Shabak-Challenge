//
//  main.cpp
//  Shabak_Challenge_2
//
//  Created by Dan Revah on 30/04/2017.
//  Copyright © 2017 Dan Revah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

enum Direction { Left, Right };

struct EncryptionStepDescriptor
{
    int operationCode;
    int operationParameter;
    int lengthToOperateOn;
};

std::vector<EncryptionStepDescriptor> extractOperations(std::string key) {
    std::vector<EncryptionStepDescriptor> descriptors = {};
    
    for (int i = 0; i < key.length(); i+=6) {
        std::string step = key.substr(i, i + 6);
        descriptors.push_back({ (int8_t)step[0], (int8_t)step[1], (int32_t)step[2] });
    }
    
    return descriptors;
}

char doOperationByCode(EncryptionStepDescriptor operation, char ch) {
    switch (operation.operationCode) {
        default: std::cout << "No such operation code!" << std::endl; return 0;
        case 0: return ch ^ operation.operationParameter;
        case 1: return ch + operation.operationParameter;
        case 2: return ch - operation.operationParameter;
    }
    
}

std::string doOperations(std::vector<EncryptionStepDescriptor> operations, std::string encryptedMessage) {
    
    std::string result = encryptedMessage;
    long i = 0, l = encryptedMessage.length();
    
    Direction direction = Right;
    
    for(auto& operation : operations) {
	// @TODO: Main flow is hidden in order not to ruin Shabak challenge.
    }
    
    return result;
}

void printDescriptors(std::vector<EncryptionStepDescriptor> descriptors) {
    for(EncryptionStepDescriptor d : descriptors) {
        std::cout << "Operation Code: " << d.operationCode << ", Parameter: " << d.operationParameter << ", length: " << d.lengthToOperateOn << std::endl;
    }
}

std::string getFileContent(const std::string& path)
{
    std::ifstream file(path);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    
    return content;
}

int main(int argc, const char * argv[]) {
    std::string key = getFileContent("Key.bin"),
                encrypedMessage = getFileContent("EncryptedMessage.bin");
    
//    printDescriptors(extractOperations(key));
    
//    std::vector<EncryptionStepDescriptor> descriptors = {};
//    descriptors.push_back({1, 1, 4});
//    descriptors.push_back({2, 2, 3});
//    std::cout << "First test pass? " << (doOperations(descriptors, "ccccccc") == "ddddaaa" ? "true" : "false");
    
//    std::vector<EncryptionStepDescriptor> descriptors = {};
//    descriptors.push_back({1, 5, 10});
//    descriptors.push_back({1, 1, 5});
//    descriptors.push_back({2, 2, 9});
//    descriptors.push_back({2, 1, 8});
//    std::cout << "Second test pass? " << (doOperations(descriptors, "aaaaaaaaaaeeeeehhhhhhhhhgggghh") == "ffffffffffffffffffffffffffffff" ? "true" : "false");
    
    std::cout << doOperations(extractOperations(key), encrypedMessage) << std::endl;
    
    return 0;
}

