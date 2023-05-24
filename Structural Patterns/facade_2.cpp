#include <iostream>
using namespace std;

// Subsystem classes    ----------------------------------------------------------------
class VideoFile {
public:
    void createVideo() {
        cout << "VideoFile::createVideo()\n";
    }
};

class OggCompressionCodec {
public:
    void compression() {
        cout << "OggCompressionCodec::compression()\n";
    }
};

class MPEG4CompressionCodec {
public:
    void mp4() {
        cout << "MPEG4CompressionCodec::mp4()\n";
    }
};

class CodecFactory {
public:
    void factory() {
        cout << "CodecFactory::factory()\n";
    }
};

class BitrateReader {
public:
    void reader() {
        cout << "BitrateReader::reader()\n";
    }
};

class AudioMixer {
public:
    void createAudio() {
        cout << "AudioMixer::createAudio()\n";
    }
};
// -------------------------------------------------------------------------------------

// facade
class VideoConverter {
public:
    VideoConverter(VideoFile* file = nullptr, AudioMixer* audio = nullptr)
        : file_(file ?: new VideoFile)
        , audio_(audio_ ?: new AudioMixer)
    {
    }
    void convert(const string& filename, const string& format = "mp4") {
        file_ = new VideoFile();
        file_->createVideo();
        if (format == "mp4") {
            codec = new MPEG4CompressionCodec();
            codec->mp4();
        } else {
            cout << "audio format is " << format << endl;
        }
        audio_->createAudio();
    }
    //menq dzerov chen kancum convert() metodi meji gracy amen angam, uxaki kanchum enq convert()
private:
    VideoFile *file_;
    AudioMixer* audio_;
    MPEG4CompressionCodec* codec;
};

int main()
{
    VideoConverter video;
    video.convert("file.mp4");

    return 0;
}
