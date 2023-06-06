namespace tinyxml2 {
    class XMLElement;
}

class Metadata {
public:
    Metadata();
    const char* GetOutPath() { return this->outPath_; };
    const char* GetVideoPath() { return this->videoFile_; };
    const char* GetBboxPath() { return this->bboxFile_; };
    const char* GetTrackerType() { return this->trackerType_; };
    bool ShouldSaveVideo() { return this->saveVideo_; };
    bool ShouldSaveBbox() { return this->saveBbox_; };
    void Run_();

private:
    const char* outPath_;
    const char* videoFile_;
    const char* bboxFile_;
    const char* trackerType_;
    bool saveVideo_;
    bool saveBbox_;
    void VerifyElement_(tinyxml2::XMLElement* el);
    void Parse_();
};