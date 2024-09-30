#include <PCMStreamer.h>

void PCMStreamer::init(PCM16* pcmData, size_t size, int windowSize) {
    dataSize = size;
    winSize = windowSize;
    data = new PCM16[dataSize];        // Allocate memory for the PCM data
    std::memcpy(data, pcmData, size * sizeof(PCM16));  // Copy data into the internal buffer
}

StreamStatus PCMStreamer::getWindow(PCM16* buffer) {
    // Check if we've reached or exceeded the end of the data
    if (currentWin * winSize >= dataSize) {
        return ERR_STREAM_END;   // No more data to return
    }

    // Calculate the number of samples to copy in this window
    int remainingSamples = dataSize - (currentWin * winSize);
    int samplesToCopy = (remainingSamples < winSize) ? remainingSamples : winSize;

    // Copy the window of data into the provided buffer
    std::memcpy(buffer, data + currentWin * winSize, samplesToCopy * sizeof(PCM16));

    // Increment the current window index for the next call
    currentWin++;

    // Return success if we have successfully returned the window
    return SUCCESS;
}