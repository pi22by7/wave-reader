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

typedef struct WAV_FHEAD
{
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
} wav_head;

std::ofstream fio;
std::ifstream fii;

int getFileSize();

void init(std::string path)
{
    cout<<"works"<<endl;
    cout<<"path is: "<<path<<endl;
    
    fio.open(path+"out", ios::trunc | ios::out);
    fio<<"testfio\n"<<endl;
    fio.clear();
}

int main(void)
{
    freopen(".log", "w", stdout);
    wav_head wavHeader;
    int headerSize = sizeof(wav_head), filelength = 0;
    std::string line, path, select, cho;
    int i = 1;
    
    fii.open(".path", ios::in);
    getline(fii, path);
    fii.clear();
    fii.close();

    init(path);
    
    cout<<"do you want to use custom sound or the one from test directory? y/n"<<endl;
    cin>>cho;
    if(cho=="y")
        select = path+"test.wav";
    else
        getline(cin, select);
    cout<<"you chose "<<select<<endl;
    fii.open(select, ios::in);
    if(!getline(fii, line))
        cout<<"Unable to open file.";
    else
    {
        size_t bytesRead = (fii.read((char*)&wavHeader, sizeof(WAV_FHEAD))).get();

        cout<<"Header Read. Contains "<<bytesRead<<" bytes.\n"<<endl;
        fii.seekg(0, ios::beg);
        if(bytesRead>0)
        {
            uint16_t bps = wavHeader.bytes_rate/8;
            uint64_t numSamples = wavHeader.fmt_subChunk_size/bps;
            static const uint16_t BUFFER_SIZE = 4096;
            int8_t* buffer = new int8_t[BUFFER_SIZE];

            delete [] buffer;
            buffer = nullptr;
            filelength = getFileSize();

            cout<<"File is                    :"<<filelength<<" bytes."<<endl;
            cout<<"RIFF header                :"<<wavHeader.RIFF[0]<<wavHeader.RIFF[1]<<wavHeader.RIFF[2]<<wavHeader.RIFF[3]<<endl;
            cout<<"WAVE header                :"<<wavHeader.WAVE[0]<<wavHeader.WAVE[1]<<wavHeader.WAVE[2]<<wavHeader.WAVE[3]<<endl;
            cout<<"FMT                        :"<<wavHeader.fmt[0]<<wavHeader.fmt[1]<<wavHeader.fmt[2]<<wavHeader.fmt[3]<<endl;
            cout<<"Format SubChunk Size       :"<<wavHeader.fmt_subChunk_size<<endl;

            cout<<"Sampling Rate              :"<<wavHeader.sample_rate<<endl;
            cout<<"Number of bits used        :"<<wavHeader.bytes_rate<<endl;
            cout<<"Number of channels         :"<<wavHeader.channels<<endl;
            cout<<"Bit Per Second             :"<<wavHeader.bps<<endl;
            cout<<"Data length                :"<<wavHeader.data_size<<endl;
            cout<<"Audio Format               :"<<wavHeader.format<<endl;

            cout<<"Block align                :"<<wavHeader.block_align<< endl;
            cout<<"Data ID                    :"<<wavHeader.data_id[0]<<wavHeader.data_id[1]<<wavHeader.data_id[2]<<wavHeader.data_id[3]<<endl;
        }
        cout<<endl;
        while(fii) 
        {
            cout<<"line "<<i++<<endl;
            getline(fii, line);
            cout<<line<<endl;
        }
        fii.clear();
    }

    fio.close();
    fii.close();

    return 0;
}

int getFileSize()
{
    int fileSize = 0;
    fii.seekg(0, ios::end);
    fileSize = fii.tellg();
    fii.seekg(0, ios::beg);
    return fileSize;
}