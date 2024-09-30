#include <types.h>

enum StreamStatus {
    SUCCESS = 0,
    ERR_STREAM_END,  // Represents the end of the stream
    ERR_STREAM_CORRUPT,
    ERR_STREAM_TIMEOUT,
    ERR_UNKNOWN,
    ERR_DATA_EMPTY,
    ERR_STREAM_NOTINIT
};

class PCMStreamer{
    private:
    PCM16 *data = nullptr;
    size_t dataSize = 0;
    int currentWin = 0;
    int winSize = 0;
    public:
    PCMStreamer() = default;
    void init(PCM16* pcmData, size_t size, int windowSize);
    StreamStatus getWindow(PCM16 *); //Returns the currentWin and increments it. If it winSize*  
};