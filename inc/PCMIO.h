/* Only 16bit 16KHz supported for now*/
/* Basically streaming audio data from file to chunk wise API's*/
#include <stdio.h>
#include <types.h>

class PCMIO{
    PCM16 *data = nullptr;
    size_t dataSize = 0;
    public:
    PCMIO();
    void ReadFile(const char *);
    void writeFile(const char *) const;
    ~PCMIO() {
        delete [] data;
    }
};
