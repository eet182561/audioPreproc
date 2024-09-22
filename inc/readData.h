/* Only 16bit 16KHz supported for now*/
/* Basically streaming audio data from file to chunk wise API's*/
#include <stdio.h>
#include <types.h>

class PCMReader{
    PCM16 *data = nullptr;
    size_t dataSize = 0;
    public:
    PCMReader();
    void ReadFile(const char *);
    ~PCMReader() {
        delete [] data;
    }
};

class PCMWriter{
    PCM16 *data;
    public:
    PCMWriter();
    void writeFile(const char *filename);
};
