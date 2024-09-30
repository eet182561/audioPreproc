#include <PCMIO.h>
#include <iostream>




void PCMIO::ReadFile(const char *filename){
    FILE* F1 = fopen(filename, "rb");
    
    if (!F1) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Seek to the end of the file to get the file size
    fseek(F1, 0, SEEK_END);
    long fileSize = ftell(F1);
    rewind(F1); // Reset file pointer to the beginning

    // Calculate the number of PCM samples (each sample is 2 bytes for PCM16)
    dataSize = fileSize / sizeof(PCM16);
    
    // Allocate memory for the PCM data
    data = new PCM16[dataSize];
    
    if (data == nullptr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        fclose(F1);
        return;
    }

    // Read the PCM data from the file into the data buffer
    size_t bytesRead = fread(data, sizeof(PCM16), dataSize, F1);

    if (bytesRead != dataSize) {
        std::cerr << "Error reading file: " << filename << std::endl;
        delete[] data;
        data = nullptr;
        fclose(F1);
        return;
    }

    // Close the file
    fclose(F1);

    std::cout << "Successfully read " << bytesRead << " samples from " << filename << std::endl;
}

void PCMIO::writeFile(const char* filename) const {
    if (!data || dataSize == 0) {
        std::cerr << "No data to write to file." << std::endl;
        return;
    }

    // Open the file in binary mode for writing
    FILE* F1 = fopen(filename, "wb");
    if (!F1) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // Write the PCM data to the file
    size_t itemsWritten = fwrite(data, sizeof(PCM16), dataSize, F1);

    if (itemsWritten != dataSize) {
        std::cerr << "Error writing to file: " << filename << std::endl;
    } else {
        std::cout << "Successfully wrote " << itemsWritten << " samples to " << filename << std::endl;
    }

    // Close the file
    fclose(F1);
}