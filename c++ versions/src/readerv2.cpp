#include<iostream>
#include<fstream>
#include<string>

#define byte uint8_t
#define tint uint32_t
#define hint uint16_t

using std::cout;
using std::cin;
using std::endl;
using std::ios;

class read
{
protected:
                                // RIFF
    byte RIFF[4];
    tint file_size;
    byte WAVE[4];
                                // fmt
    byte fmt[4];
    tint fmt_subChunk_size;
    hint format;
    hint channels;
    tint sample_rate;
    tint bytes_rate;
    hint block_align;
    hint bps;
                                //data
    byte data_id[4];
    tint data_size;
public:
    read::read(byte RIFF[], tint file_size, byte WAVE[], byte fmt[], 
            tint fmt_subChunk_size, hint format, hint channels, 
            tint sample_rate, tint bytes_rate, hint block_align, 
            hint bps, byte data_id[], tint data_size)
    {
        for(int i=0; i<=4; i++)
        {
            this->RIFF[i] = RIFF[i];
            this->WAVE[i] = WAVE[i];
            this->fmt[i] = fmt[i];
            this->data_id[i] = data_id[i];
        }
        this->file_size = file_size;
        this->fmt_subChunk_size = fmt_subChunk_size;
        this->format = format;
        this->channels = channels;
        this->sample_rate = sample_rate;
        this->bytes_rate = bytes_rate;
        this->block_align = block_align;
        this->bps = bps;
        this->data_size = data_size;
    }
};

int main(void)
{
    std::ofstream fio;
    std::ifstream fii;
    

    
    read wave();
}
