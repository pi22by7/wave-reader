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

int main(void)
{
    wav_head wavHeader;
    std::ofstream fio;
    std::ifstream fii;
    std::string line, path, select;
    int i = 1;
    
    fii.open(".path", ios::in);
    getline(fii, path);
    fii.clear();
    fii.close();

    freopen(".log", "w", stdout);
    cout<<"works"<<endl;
    cout<<"path is: "<<path<<endl;
    
    fio.open(path+"out", ios::trunc | ios::out);
    fio<<"testfio\n"<<endl;
    fio.clear();

    cin>>select;
    fii.open(path+select, ios::in);
    if(!getline(fii, line))
        cout<<"Unable to open file.";
    else
    {
        fii.seekg(0, ios::beg);
        while(fii) 
        {
            cout<<"line "<<i++<<endl;
            getline(fii, line);
            fio<<line<<endl;
        }
        fii.clear();
    }

    fio.close();
    fii.close();

    return 0;
}